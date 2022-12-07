#pragma once
#include <Prey/CrySystem/IConsole.h>

class DebuggerConsoleOutput : public IOutputPrintSink
{
public:
	void Init();
	void Print(const char* inszText) override;

private:
	void PrintExistingMessages();
};
