#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryThreading/IJobManager.h>
#include <Prey/CrySystem/Profiling.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Chairloader/IChairloaderDll.h>
#include "imgui_widget_flamegraph.h"
#include "Profiler.h"

Profiler *g_pProfiler = nullptr;

namespace {

//! One profiling marker
struct Node {
	char name[Profiler::MAX_MARKER_NAME];
	int64_t startTime = 0;
	int64_t endTime = 0;
	int16_t parent = -1;
	int16_t children[Profiler::MAX_DIRECT_CHILDREN];
	int8_t childCount = 0;
};

//! Tree of markers
struct ProfileData {
	std::vector<Node> nodes;
	mutable std::mutex mutex;
	int16_t currentNode = -1;

	void Clear() {
		nodes.clear();
		currentNode = -1;
	}

	bool IsReady() const {
		return !nodes.empty() && nodes[0].endTime != 0;
	}
};

// Thread-specific data
struct ThreadProfile {
	ProfileData datas[Profiler::DATA_COUNT];
	int currentData = 0;
};

ThreadProfile g_Profiles[2];
thread_local int g_ProfileIdx = -1;

int64_t g_TicksPerSecond;
int64_t g_TickOffset;
double g_SecsPerTick;

int64_t GetCPUTickCount() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return li.QuadPart;
}

void UpdateTicksPerSecond() {
	LARGE_INTEGER li;
	if (QueryPerformanceFrequency(&li)) {
		g_TicksPerSecond = li.QuadPart;
	} else {
		assert(false && "QueryPerformanceFrequency failed");
		g_TicksPerSecond = 1000000;
	}

	g_SecsPerTick = 1.0 / g_TicksPerSecond;
}

//! @returns profile datas for calling thread.
ThreadProfile *GetProfileForThisThread() {
	int idx = g_ProfileIdx;

	if (idx == -1) {
		static threadID mainThreadId = 0, renderThreadId = 0;
		if (mainThreadId == 0)
			gEnv->pRenderer->GetThreadIDs(mainThreadId, renderThreadId);
		
		threadID threadId = GetCurrentThreadId();
		if (threadId == mainThreadId) {
			idx = Profiler::MAIN_THREAD;
		} else if (threadId == renderThreadId) {
			idx = Profiler::RENDER_THREAD;
		} else {
			// Thread is not profiled
			g_ProfileIdx = -2;
			return nullptr;
		}

		g_ProfileIdx = idx;
	} else if (idx == -2) {
		return nullptr;
	}

	return &g_Profiles[idx];
}

void PushProfilingMarker(JobManager::IJobManager *_this, char *name) {
	int64_t startTime = GetCPUTickCount();
	ThreadProfile *pProfile = GetProfileForThisThread();

	if (!pProfile) {
		return;
	}

	ProfileData &data = pProfile->datas[pProfile->currentData];
	std::unique_lock lock(data.mutex);

	if (data.nodes.size() >= Profiler::MAX_NODES_CHILDREN) {
		CryWarning("PushProfilingMarker: too many nodes");
		return;
	}

	if (data.currentNode == -1) {
		// Now adding the root node
		data.Clear();
	}

	// Add new node
	int16_t newNodeIdx = (int16_t)data.nodes.size();
	Node &newNode = data.nodes.emplace_back();

	// Add the node to the parent
	if (data.currentNode != -1) {
		Node &parent = data.nodes[data.currentNode];
		
		if (parent.childCount == Profiler::MAX_DIRECT_CHILDREN) {
			CryWarning("PushProfilingMarker: too many children");
			return;
		}

		parent.children[parent.childCount] = newNodeIdx;
		parent.childCount++;
	}

	// Fill node data
	memcpy(newNode.name, name, Profiler::MAX_MARKER_NAME);
	newNode.startTime = startTime;
	newNode.parent = data.currentNode;

	// Update current node
	data.currentNode = newNodeIdx;
}

void PopProfilingMarker(JobManager::IJobManager *_this, char *name) {
	ThreadProfile *pProfile = GetProfileForThisThread();

	if (!pProfile) {
		return;
	}

	ProfileData &data = pProfile->datas[pProfile->currentData];
	std::unique_lock lock(data.mutex);

	if (data.currentNode == -1) {
		return;
	}

	Node &nodeToPop = data.nodes[data.currentNode];
	data.currentNode = nodeToPop.parent;
	nodeToPop.endTime = GetCPUTickCount();

	if (nodeToPop.parent == -1) {
		// Next time use other data
		pProfile->currentData = (pProfile->currentData + 1) % Profiler::DATA_COUNT;
	}
}

void PushProfilingMarker_Disabled(JobManager::IJobManager *_this, char *name) {}
void PopProfilingMarker_Disabled(JobManager::IJobManager *_this) {}

void RecursiveProcessNode(const ProfileData &data, Profiler::ProcessedProfileData &procData,
						  const Node &node, Profiler::ProcessedNode *pParent, int depth) {
	int16_t procNodeIdx = (int16_t)data.nodes.size();
	Profiler::ProcessedNode &procNode = procData.nodes.emplace_back();

	if (pParent) {
		pParent->children[pParent->childCount] = procNodeIdx;
		pParent->childCount++;
	}

	memcpy(procNode.name, node.name, sizeof(node.name));
	procNode.startTime = (float)((node.startTime - g_TickOffset) * g_SecsPerTick * 1000.0);
	procNode.endTime = (float)((node.endTime - g_TickOffset) * g_SecsPerTick * 1000.0);
	procNode.depth = depth;
	procNode.childCount = node.childCount;
	procData.minTime = std::min(procData.minTime, procNode.startTime);
	procData.maxTime = std::max(procData.maxTime, procNode.endTime);

	for (int i = 0; i < node.childCount; i++) {
		RecursiveProcessNode(data, procData, data.nodes[node.children[i]], &procNode, depth + 1);
	}
}

void ProfilerValueGetter(float *startTimestamp, float *endTimestamp, ImU8 *level, const char **caption, const void *pUser, int idx) {
	auto data = reinterpret_cast<const Profiler::ProcessedProfileData *>(pUser);
	auto &node = data->nodes[idx];
	if (startTimestamp) {
		*startTimestamp = node.startTime;
	}
	if (endTimestamp) {
		*endTimestamp = node.endTime;
	}
	if (level) {
		*level = node.depth;
	}
	if (caption) {
		*caption = node.name;
	}
}

} // namespace

Profiler::Profiler() {
	UpdateTicksPerSecond();
	m_JobManagerHook.HookObject(gEnv->pJobManager);
	g_TickOffset = GetCPUTickCount();
}

void Profiler::SetEnabled(bool state) {
	if (state) {
		Enable();
	} else {
		Disable();
	}
}

void Profiler::Enable() {
	if (m_bEnabled) {
		return;
	}

	threadID mainThreadId = 0, renderThreadId = 0;
	gEnv->pRenderer->GetThreadIDs(mainThreadId, renderThreadId);
	if (mainThreadId == 0 || renderThreadId == 0) {
		CryError("gEnv->pRenderer->GetThreadIDs returned zeroes");
		return;
	}

	m_JobManagerHook.HookMethod(JobManager::IJobManager::VTBL_PushProfilingMarker, &PushProfilingMarker);
	m_JobManagerHook.HookMethod(JobManager::IJobManager::VTBL_PopProfilingMarker, &PopProfilingMarker);
	m_bEnabled = true;
}

void Profiler::Disable() {
	if (!m_bEnabled) {
		return;
	}

	m_JobManagerHook.HookMethod(JobManager::IJobManager::VTBL_PushProfilingMarker, &PushProfilingMarker_Disabled);
	m_JobManagerHook.HookMethod(JobManager::IJobManager::VTBL_PopProfilingMarker, &PopProfilingMarker_Disabled);
	m_bEnabled = false;
}

bool Profiler::GetDataForThread(int threadIdx, ProcessedProfileData &outData) {
	const ThreadProfile &profile = g_Profiles[threadIdx];
	int curData = profile.currentData + 1;

	// Try to find a data that is not locked and is ready
	for (int i = 0; i < DATA_COUNT; i++) {
		int idx = (curData + i + 1) % DATA_COUNT;
		const ProfileData &profData = profile.datas[idx];
		std::unique_lock lock(profData.mutex, std::defer_lock);

		if (!lock.try_lock() || !profData.IsReady()) {
			continue;
		}

		outData.Clear();
		RecursiveProcessNode(profData, outData, profData.nodes[0], nullptr, 0);
		return true;
	}

	return false;
}

void ProfilerDialog::Show(bool *pIsOpen) {
	CRY_PROFILE_MARKER("Profiler Dialog");
	if (!*pIsOpen) {
		return;
	}

	if (ImGui::Begin("Profiler", pIsOpen)) {
		bool isEnabled = g_pProfiler->IsEnabled();
		if (ImGui::Checkbox("Enable", &isEnabled)) {
			g_pProfiler->SetEnabled(isEnabled);
		}
		
		if (g_pProfiler->IsEnabled()) {
			ImGui::SameLine();
			ImGui::TextColored(ImColor(255, 0, 0), "Profiler is running");

			if (m_bFreeze) {
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 255, 0), "Graph frozen");
			}
		}

		if (ImGui::BeginTabBar("Tab Bar")) {
			if (ImGui::BeginTabItem("Flame Graph")) {
				ShowFlameGraph();
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("ReadMe")) {
				ShowReadMe();
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
	}

	ImGui::End();
}

void ProfilerDialog::ShowFlameGraph() {
	bool update = m_FramesLeft == 0 && !m_bFreeze;

	ImGui::Checkbox("Freeze", &m_bFreeze);
	ImGui::SameLine();

	update = ImGui::Button("Refresh") || update;
	ImGui::SameLine();

	ImGui::PushItemWidth(200);
	if (ImGui::SliderInt("Throttle", &m_ThrottleFrames, 0, 60)) {
		m_ThrottleFrames = std::max(m_ThrottleFrames, 0);
		m_FramesLeft = 0;
	}
	ImGui::PopItemWidth();

	if (g_pProfiler->IsEnabled() && update) {
		g_pProfiler->GetDataForThread(Profiler::MAIN_THREAD, m_MainThreadData);
		g_pProfiler->GetDataForThread(Profiler::RENDER_THREAD, m_RenderThreadData);
		m_GraphMinTime = std::min(m_MainThreadData.minTime, m_RenderThreadData.minTime);
		m_GraphMaxTime = std::max(m_MainThreadData.maxTime, m_RenderThreadData.maxTime);
	}

	ShowFlameGraphForThread(m_MainThreadData, "Main Thread");
	ShowFlameGraphForThread(m_RenderThreadData, "Render Thread");

	m_FramesLeft--;
	if (m_FramesLeft == -1) {
		m_FramesLeft = m_ThrottleFrames;
	}
}

void ProfilerDialog::ShowFlameGraphForThread(Profiler::ProcessedProfileData &data, const char *threadName) {

	char label[128];
	snprintf(label, sizeof(label), "##%s", threadName);
	ImVec2 vMin = ImGui::GetWindowContentRegionMin();
	ImVec2 vMax = ImGui::GetWindowContentRegionMax();

	ImGuiWidgetFlameGraph::PlotFlame(label, &ProfilerValueGetter, &data,
		(int)data.nodes.size(), 0, threadName, m_GraphMinTime, m_GraphMaxTime, ImVec2(vMax.x - vMin.x, 0));
}

void ProfilerDialog::ShowReadMe() {
	ImGui::Text("1) Flame graph times are in ms.");
	ImGui::Text("2) Profiler uses markers left in the game as well as custom ones\n   added to ChairLoader functions.");
	ImGui::Text("3) Enabling profiler will have some additional overhead but\n   it should be negligible compared to functions that need markers.");
	ImGui::Text("4) Timings will jump around every frame. Use \"freeze\" or \"throttle\"\n   to make the graph readable.");
}

void Profiler::ProcessedProfileData::Clear() {
	nodes.clear();
	minTime = FLT_MAX;
	maxTime = FLT_MIN;
}
