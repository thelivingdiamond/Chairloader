#pragma once
#include <Prey/CrySystem/IConsole.h>

namespace Engine
{

class DebuggerConsoleOutput : public IOutputPrintSink
{
public:
	void Init();
	void Print(const char* inszText) override;

private:
	void PrintExistingMessages();
};

} // namespace Engine
