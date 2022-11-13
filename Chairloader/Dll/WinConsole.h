#pragma once
#include <ConsoleColorParser.h>

class WinConsole : private IOutputPrintSink, private NoCopy
{
public:
	void InitConsole();
	void InitSystem();
	void ShutdownConsole();

	void Print(const char* inszText) override;

private:
	class ConsoleParser : public ConsoleColorParser
	{
	public:
		WinConsole* pCon = nullptr;

	protected:
		void PrintText(const char* text, size_t size, int color) override;
		void NewLine() override;
	};

	ConsoleParser m_Parser;
	FILE* m_pConsoleFile = nullptr;
	void* m_hStdHandle = nullptr;

	void PrintExistingMessages();
};
