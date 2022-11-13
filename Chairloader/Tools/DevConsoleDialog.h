#pragma once
#include <imgui.h>
#include <ConsoleColorParser.h>

struct IConsole;

class DevConsoleDialog {
public:
	DevConsoleDialog();
	void Show(bool *p_open);

private:
	class ConsoleParser : public ConsoleColorParser
	{
	protected:
		void PrintText(const char* text, size_t size, int color) override;
		void NewLine() override;
	};

	const std::string modName = "DevConsole";
	IConsole *m_pConsole = nullptr;
	bool m_bAutoScroll = true;
	bool m_bScrollToBottom = false;
	char m_InputBuf[1024] = {};
	int m_LastInputPos = 0;
	bool m_IsCompletionReset = true;
	ConsoleParser m_Parser;

	int TextEditCallback(ImGuiInputTextCallbackData *data);
	void ExecCommand(const char *cmd);

	static void Strtrim(char *s);
};
