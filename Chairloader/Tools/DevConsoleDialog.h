#pragma once
#include <imgui.h>
#include <ConsoleColorParser.h>

struct IConsole;

namespace Internal
{
struct ILogManager;
}

class DevConsoleDialog {
public:
	enum class TabRequest
	{
		None,
		Console,
		ModLog,
		Toggle, //!< Toggle to the other tab
	};

	DevConsoleDialog();
	void Show(bool *p_open);
	void SetTabRequest(TabRequest req) { m_TabRequest = req; }

private:
	class ConsoleParser : public ConsoleColorParser
	{
	protected:
		void PrintText(const char* text, size_t size, int color) override;
		void NewLine() override;
	};

	const std::string modName = "DevConsole";
	IConsole *m_pConsole = nullptr;
	Internal::ILogManager* m_pLogManager = nullptr;
	bool m_bAutoScroll = true;
	bool m_bScrollToBottom = false;
	char m_InputBuf[1024] = {};
	int m_LastInputPos = 0;
	bool m_IsCompletionReset = true;
	bool m_bFocusTextInput = false;
	ConsoleParser m_Parser;
	TabRequest m_TabRequest = TabRequest::None;

	void ShowConsole();
	void ShowModLog();
	int TextEditCallback(ImGuiInputTextCallbackData *data);
	void ExecCommand(const char *cmd);

	static void Strtrim(char *s);
};
