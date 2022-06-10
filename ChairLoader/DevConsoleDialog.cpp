#include "pch.h"
#include <boost/algorithm/string/find.hpp>
#include "DevConsoleDialog.h"
#include "ChairLoader.h"

class ICVarsWhitelist {
public:
	virtual ~ICVarsWhitelist() {};
	virtual bool IsWhiteListed(const CryStringT<char> *, bool) = 0;
};

namespace {

class CBetterCVarsWhitelist : public ICVarsWhitelist {
public:
	~CBetterCVarsWhitelist() {}

	bool IsWhiteListed(const CryStringT<char> *, bool)  override {
		return true;
	}
};

struct ParseBuffer {
	char buf[1024];
	char *ptr;

	ParseBuffer() {
		ptr = buf;
		*ptr = '\0';
	}

	void ShowText(ImVec4 color) {
		if (ptr == buf) {
			return;
		}

		assert(ptr - buf < sizeof(buf));
		*ptr = '\0';

		if (color.w != 0) {
			ImGui::PushStyleColor(ImGuiCol_Text, color);
		}

		ImGui::TextUnformatted(buf);
		ImGui::SameLine();

		if (color.w != 0) {
			ImGui::PopStyleColor();
		}

		ptr = buf;
	}
};

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

CBetterCVarsWhitelist g_CVarsWhitelist;

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
		CryLog("$3%s = $6%s", cvar->GetName(), cvar->GetString());

		const char *help = cvar->GetHelp();
		if (help) {
			std::string line;
			line.reserve(256);

			for (const char *str = help; *str; str++) {
				if (*str == '\n') {
					CryLog("    %s", line.c_str());
					line.clear();
				} else {
					line += *str;
				}
			}

			if (!line.empty()) {
				CryLog("    %s", line.c_str());
			}
		}
	}
}

} // namespace

DevConsoleDialog::DevConsoleDialog() {
	m_pConsole = gEnv->pConsole;

	auto pSystem = static_cast<CSystem *>(gEnv->pSystem);
	pSystem->m_pCVarsWhitelist = &g_CVarsWhitelist;

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
	ImGui::Separator();

	// Reserve enough left-over height for 1 separator + 1 input text
	const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
	ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);

	// Display every line as a separate entry so we can change their color or add custom widgets.
	// If you only want raw text you can use ImGui::TextUnformatted(log.begin(), log.end());
	// NB- if you have thousands of entries this approach may be too inefficient and may require user-side clipping
	// to only process visible items. The clipper will automatically measure the height of your first item and then
	// "seek" to display only items in the visible area.
	// To use the clipper we can replace your standard loop:
	//      for (int i = 0; i < Items.Size; i++)
	//   With:
	//      ImGuiListClipper clipper;
	//      clipper.Begin(Items.Size);
	//      while (clipper.Step())
	//         for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
	// - That your items are evenly spaced (same height)
	// - That you have cheap random access to your elements (you can access them given their index,
	//   without processing all the ones before)
	// You cannot this code as-is if a filter is active because it breaks the 'cheap random-access' property.
	// We would need random-access on the post-filtered list.
	// A typical application wanting coarse clipping and filtering may want to pre-compute an array of indices
	// or offsets of items that passed the filtering test, recomputing this array when user changes the filter,
	// and appending newly elements as they are inserted. This is left as a task to the user until we can manage
	// to improve this example code!
	// If your items are of variable height:
	// - Split them into same height items would be simpler and facilitate random-seeking into your list.
	// - Consider using manual call to IsRectVisible() and skipping extraneous decoration from your items.

	// I'd love to use ImGuiListClipper but text may contain line breaks
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
	int itemCount = m_pConsole->GetLineCount();
	for (int i = itemCount - 1; i >= 0; i--) {
		char item[1024];
		m_pConsole->GetLineNo(i, item, sizeof(item));

		const char *strIn = item;
		ParseBuffer buf;
		bool isEscape = 0;
		bool isColor = false;
		ImVec4 color = g_ConColors[0];

		// Based on CryEngine WindowsConsole
		while (*strIn) {
			switch (*strIn) {
			case '$':
				if (!isEscape) {
					isColor = true;
					break;
				}
				[[fallthrough]];
			case '\\':
				if (isEscape = !isEscape) {
					break;
				}
			case 'n':
				if (isEscape) {
				[[fallthrough]];
			case '\n':
				buf.ShowText(color);
				color = g_ConColors[0];
				isEscape = false;
				break;
				}
				[[fallthrough]];
			case 'r':
				if (isEscape) {
				[[fallthrough]];
			case '\r':
				// Not supported
				//ClearLine(position);
				isEscape = false;
				break;
				}
				[[fallthrough]];
			case 't':
				if (isEscape) {
				[[fallthrough]];
			case '\t':
				*buf.ptr = '\t';
				buf.ptr++;
				isEscape = false;
				break;
				}
				[[fallthrough]];
			default:
				if (isColor) {
					if (isdigit(*strIn)) {
						buf.ShowText(color);
						color = g_ConColors[*strIn - '0'];
					}

					isColor = false;
				} else {
					if (isEscape && (*strIn != '\\')) {
						*buf.ptr = '\\';
						buf.ptr++;
					}
					if (*strIn) {
						*buf.ptr = *strIn;
						buf.ptr++;
					}
				}
				isEscape = false;
				break;
			}
			strIn++;
		}
		buf.ShowText(color);
		ImGui::NewLine();
	}

	if (m_bScrollToBottom || (m_bAutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
		ImGui::SetScrollHereY(1.0f);
	m_bScrollToBottom = false;

	ImGui::PopStyleVar();
	ImGui::EndChild();
	ImGui::Separator();

	// Command-line
	bool reclaim_focus = false;
	ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue |
		ImGuiInputTextFlags_CallbackAlways | ImGuiInputTextFlags_CallbackCompletion |
		ImGuiInputTextFlags_CallbackHistory;
	if (ImGui::InputText("Input", m_InputBuf, IM_ARRAYSIZE(m_InputBuf), input_text_flags, [](ImGuiInputTextCallbackData *data) {
			auto console = (DevConsoleDialog *)data->UserData;
			return console->TextEditCallback(data);
		}, (void *)this)) {
		char *s = m_InputBuf;
		Strtrim(s);
		if (s[0])
			ExecCommand(s);
		s[0] = 0;
		reclaim_focus = true;
	}

	// Auto-focus on window apparition
	ImGui::SetItemDefaultFocus();
	if (reclaim_focus || ImGui::IsWindowAppearing())
		ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

	ImGui::End();
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
