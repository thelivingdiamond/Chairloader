#include "DebuggerConsoleOutput.h"

void DebuggerConsoleOutput::Init()
{
	gEnv->pConsole->AddOutputPrintSink(this);
	PrintExistingMessages();
}

void DebuggerConsoleOutput::Print(const char* inszText)
{
	OutputDebugStringA(inszText);
	OutputDebugStringA("\n");
}

void DebuggerConsoleOutput::PrintExistingMessages()
{
	int count = gEnv->pConsole->GetLineCount();

	for (int i = count - 1; i >= 0; i--) {
		char buf[1024];
		gEnv->pConsole->GetLineNo(i, buf, sizeof(buf));
		OutputDebugStringA(buf);
		OutputDebugStringA("\n");
	}
}
