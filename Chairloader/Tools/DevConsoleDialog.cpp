#include <boost/algorithm/string/find.hpp>
#include <Prey/CrySystem/System.h>
#include <Chairloader/ILogManager.h>
#include <Chairloader/IChairloaderCore.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/IChairloaderImGui.h>
#include "DevConsoleDialog.h"

namespace {

struct FindDumpSink : ICVarDumpSink {
	std::vector<ICVar *> cvars;
	const char *str = nullptr;

	void OnElementFound(ICVar *pCVar) {
		const char *name = pCVar->GetName();
		const char *help = pCVar->GetHelp();

		bool isFound = boost::ifind_first(name, str);
		isFound = isFound || (help && boost::ifind_first(help, str));

		if (isFound) {
			cvars.push_back(pCVar);
		}
	}
};

ImVec4 g_ConColors[] = {
	ImColor(0, 0, 0, 0),		// 0 Default
	ImColor(255, 255, 255, 255),// 1 White
	ImColor(64, 64, 255, 255),	// 2 Blue
	ImColor(64, 255, 64, 255),	// 3 Green
	ImColor(255, 64, 64, 255),	// 4 Red
	ImColor(0, 255, 255, 255),	// 5 Cyan
	ImColor(255, 255, 0, 255),	// 6 Yellow
	ImColor(255, 0, 255, 255),	// 7 Magenta
	ImColor(192, 64, 0, 255),	// 8 Brown
	ImColor(64, 64, 64, 255),	// 9 Grey
};

void Command_Find(IConsoleCmdArgs *args) {
	if (args->GetArgCount() != 2) {
		CryLog("Prints all variables matching input text.");
		CryLog("Usage: find <text>");
		return;
	}

	FindDumpSink sink;
	sink.cvars.reserve(gEnv->pConsole->GetNumVars());
	sink.str = args->GetArg(1);

	gEnv->pConsole->DumpCVars(&sink);

	for (ICVar *cvar : sink.cvars) {
		CryLog("$3{} = $6{}", cvar->GetName(), cvar->GetString());

		const char *help = cvar->GetHelp();
		if (help) {
			std::string line;
			line.reserve(256);

			for (const char *str = help; *str; str++) {
				if (*str == '\n') {
					CryLog("    {}", line);
					line.clear();
				} else {
					line += *str;
				}
			}

			if (!line.empty()) {
				CryLog("    {}", line);
			}
		}
	}
}

} // namespace

DevConsoleDialog::DevConsoleDialog() {
	m_pConsole = gEnv->pConsole;
	m_pLogManager = gChair->GetCore()->GetLogManager();
	REGISTER_COMMAND("find", Command_Find, 0, "Prints all variables matching input text");
}

void DevConsoleDialog::Show(bool *p_open) {
	ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
	if (!ImGui::Begin("Developer Console", p_open)) {
		ImGui::End();
		return;
	}

	// As a specific feature guaranteed by the library, after calling Begin() the last Item represent the title bar.
	// So e.g. IsItemHovered() will return true when hovering the title bar.
	// Here we create a context menu only available from the title bar.
	if (ImGui::BeginPopupContextItem()) {
		if (ImGui::MenuItem("Close Console"))
			*p_open = false;
		ImGui::EndPopup();
	}

	// Options menu
	if (ImGui::BeginPopup("Options")) {
		ImGui::Checkbox("Auto-scroll", &m_bAutoScroll);
		ImGui::EndPopup();
	}

	// Options, Filter
	if (ImGui::Button("Options"))
		ImGui::OpenPopup("Options");
	ImGui::SameLine();
	if (ImGui::Button("Clear"))
		m_pConsole->Clear();
	
	TabRequest tabRequest = m_TabRequest;
	m_TabRequest = TabRequest::None;

	if (ImGui::BeginTabBar("MyTabBar", ImGuiTabBarFlags_None))
	{
		if (ImGui::BeginTabItem("Console", nullptr, tabRequest == TabRequest::Console ? ImGuiTabItemFlags_SetSelected : 0))
		{
			if (tabRequest == TabRequest::Toggle)
				SetTabRequest(TabRequest::ModLog);

			ShowConsole();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Mod Log", nullptr, tabRequest == TabRequest::ModLog ? ImGuiTabItemFlags_SetSelected : 0))
		{
			if (tabRequest == TabRequest::Toggle)
			{
				SetTabRequest(TabRequest::Console);
				m_bFocusTextInput = true;
			}

			ShowModLog();
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	ImGui::End();
}

void DevConsoleDialog::ShowConsole()
{
	ImGui::TextWrapped("'cvar_name ?' for help. '?string' for search. 'find string' for search (variables only) with help.");
	ImGui::Separator();
	ImGui::PushFont(gCL->pImGui->GetFont(IChairloaderImGui::EFont::Monospace));

	// Reserve enough left-over height for 1 separator + 1 input text
	const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
	ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);

	// I'd love to use ImGuiListClipper but text may contain line breaks
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
	int itemCount = m_pConsole->GetLineCount();
	for (int i = itemCount - 1; i >= 0; i--) {
		char item[1024];
		m_pConsole->GetLineNo(i, item, sizeof(item));
		m_Parser.ProcessLine(item);
		ImGui::NewLine();
	}

	if (m_bScrollToBottom || (m_bAutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
		ImGui::SetScrollHereY(1.0f);
	m_bScrollToBottom = false;

	ImGui::PopStyleVar();
	ImGui::EndChild();
	ImGui::Separator();

	// Command-line
	bool reclaim_focus = m_bFocusTextInput;
	ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue |
		ImGuiInputTextFlags_CallbackAlways | ImGuiInputTextFlags_CallbackCompletion |
		ImGuiInputTextFlags_CallbackHistory;
	ImGui::PushItemWidth(-0.01f);
	if (ImGui::InputText("##Input", m_InputBuf, IM_ARRAYSIZE(m_InputBuf), input_text_flags, [](ImGuiInputTextCallbackData* data) {
		auto console = (DevConsoleDialog*)data->UserData;
		return console->TextEditCallback(data);
		}, (void*)this)) {
		char* s = m_InputBuf;
		Strtrim(s);
		if (s[0])
			ExecCommand(s);
		s[0] = 0;
		reclaim_focus |= true;
	}
	ImGui::PopItemWidth();
	ImGui::PopFont();

	// Auto-focus on window apparition
	ImGui::SetItemDefaultFocus();
	if (reclaim_focus || ImGui::IsWindowAppearing())
		ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

	m_bFocusTextInput = false;
}

void DevConsoleDialog::ShowModLog()
{
	ImGui::TextWrapped("Tip: Press Alt+~ to open mod log directly or toggle between console and log.");
	ImGui::Separator();

	ImGui::PushFont(gCL->pImGui->GetFont(IChairloaderImGui::EFont::Monospace));
	ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

	// I'd love to use ImGuiListClipper but text may contain line breaks
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
	size_t itemCount = m_pLogManager->GetMessageCount();
	for (size_t i = 0; i < itemCount; i++) {
		char item[1024];
		m_pLogManager->GetMessage(i, item, sizeof(item));
		m_Parser.ProcessLine(item);
		ImGui::NewLine();
	}

	if (m_bScrollToBottom || (m_bAutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
		ImGui::SetScrollHereY(1.0f);
	m_bScrollToBottom = false;

	ImGui::PopStyleVar();
	ImGui::EndChild();
	ImGui::PopFont();
}

int DevConsoleDialog::TextEditCallback(ImGuiInputTextCallbackData *data) {
	switch (data->EventFlag) {
	case ImGuiInputTextFlags_CallbackCompletion: {
		if (m_IsCompletionReset) {
			m_pConsole->PrintLine("$7-------------------------------------");
			m_pConsole->PrintLine("$7--         Auto-completion         --");
			m_pConsole->PrintLine("$7-------------------------------------");
			m_IsCompletionReset = false;
		}

		const char *completed = m_pConsole->ProcessCompletion(data->Buf);

		if (completed && completed[0]) {
			m_LastInputPos = -1;
			data->DeleteChars(0, data->BufTextLen);
			data->InsertChars(0, completed);
			m_bScrollToBottom = true;
		}
		break;
	}
	case ImGuiInputTextFlags_CallbackHistory: {
		if (data->EventKey == ImGuiKey_UpArrow || data->EventKey == ImGuiKey_DownArrow) {
			const char *hist = m_pConsole->GetHistoryElement(data->EventKey == ImGuiKey_UpArrow);
			if (hist) {
				data->DeleteChars(0, data->BufTextLen);
				data->InsertChars(0, hist);
			}
		}
		break;
	}
	case ImGuiInputTextFlags_CallbackAlways: {
		if (m_LastInputPos != data->CursorPos) {
			if (m_LastInputPos != -1) {
				m_pConsole->ResetAutoCompletion();
				m_IsCompletionReset = true;
			}

			m_LastInputPos = data->CursorPos;
		}
		break;
	}
	}
	return 0;
}

void DevConsoleDialog::ExecCommand(const char *cmd) {
	CryLog("$7> {}", cmd);
	m_pConsole->AddCommandToHistory(cmd);
	m_pConsole->ExecuteString(cmd);
	m_bScrollToBottom = true;
}

void DevConsoleDialog::Strtrim(char *s) {
	char *str_end = s + strlen(s);
	while (str_end > s && str_end[-1] == ' ')
		str_end--;
	*str_end = 0;
}

void DevConsoleDialog::ConsoleParser::PrintText(const char* text, size_t size, int colorIdx)
{
	ImVec4 color = g_ConColors[colorIdx];
	if (color.w != 0) {
		ImGui::PushStyleColor(ImGuiCol_Text, color);
	}

	ImGui::TextUnformatted(text, text + size);
	ImGui::SameLine(0, 0);

	if (color.w != 0) {
		ImGui::PopStyleColor();
	}
}

void DevConsoleDialog::ConsoleParser::NewLine()
{
	ImGui::NewLine();
}
