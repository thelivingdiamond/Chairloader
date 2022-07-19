#pragma once
#include "VTableHook.h"

class Profiler {
public:
	static constexpr int MAIN_THREAD = 0;
	static constexpr int RENDER_THREAD = 1;

	static constexpr int MAX_MARKER_NAME = 256;		//!< Maximum marker name length. Engine limit.
	static constexpr int MAX_DIRECT_CHILDREN = 24;	//!< Maximum immediate children of a node. Just a sane limit.
	static constexpr int MAX_NODES_CHILDREN = 32767;//!< Maximum number of nodes. int16_t limit.
	static constexpr int DATA_COUNT = 4;			//!< Number of profile data to keep at the same time.

	struct ProcessedNode {
		char name[Profiler::MAX_MARKER_NAME];
		float startTime = 0;
		float endTime = 0;
		int depth = 0;
		int16_t children[MAX_DIRECT_CHILDREN];
		int8_t childCount = 0;
	};

	struct ProcessedProfileData {
		std::vector<ProcessedNode> nodes;
		float minTime = FLT_MAX;
		float maxTime = FLT_MIN;

		void Clear();
	};

	Profiler();
	inline bool IsEnabled() { return m_bEnabled; }
	void SetEnabled(bool state);
	void Enable();
	void Disable();
	bool GetDataForThread(int threadIdx, ProcessedProfileData &data);

private:
	bool m_bEnabled = false;
	float m_NextTicksUpdate = 0;
	VTableHook m_JobManagerHook;
};

class ProfilerDialog {
public:
	void Show(bool *pIsOpen);

private:
	const std::string modName = "Profiler";
	Profiler::ProcessedProfileData m_MainThreadData;
	Profiler::ProcessedProfileData m_RenderThreadData;
	bool m_bFreeze = false;
	int m_ThrottleFrames = 0;;
	int m_FramesLeft = 0;
	float m_GraphMinTime = 0;
	float m_GraphMaxTime = 0;

	void ShowFlameGraph();
	void ShowFlameGraphForThread(Profiler::ProcessedProfileData &data, const char *threadName);
	void ShowReadMe();
};

extern Profiler *g_pProfiler;
