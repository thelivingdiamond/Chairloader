#pragma once
#include <imgui.h>

struct IConsole;

class DevConsoleDialog {
public:
	DevConsoleDialog();
	void Show(bool *p_open);

private:
	IConsole *m_pConsole = nullptr;
	bool m_bAutoScroll = true;
	bool m_bScrollToBottom = false;
	char m_InputBuf[1024];
	int m_LastInputPos = 0;
	bool m_IsCompletionReset = true;

	int TextEditCallback(ImGuiInputTextCallbackData *data);
	void ExecCommand(const char *cmd);

	static void Strtrim(char *s);
};
