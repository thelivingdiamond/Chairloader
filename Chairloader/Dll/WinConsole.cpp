#include <Prey/CryCore/Platform/CryWindows.h>
#include "WinConsole.h"

#define R FOREGROUND_RED
#define G FOREGROUND_GREEN
#define B FOREGROUND_BLUE
#define I FOREGROUND_INTENSITY
static WORD g_ConColors[] = {
	R | G | B,		// 0 Default
	I | R | G | B,	// 1 White
	I | B,			// 2 Blue
	I | G,			// 3 Green
	I | R,			// 4 Red
	I | G | B,		// 5 Cyan
	I | R | G,		// 6 Yellow
	I | R | B,		// 7 Magenta
	R | G,			// 8 Brown
	R | G | B,		// 9 Grey
};
#undef R
#undef G
#undef B
#undef I

void WinConsole::InitConsole()
{
	m_Parser.pCon = this;
	AllocConsole();
	freopen_s(&m_pConsoleFile, "CONOUT$", "w", stdout);
	m_hStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("Welcome to funland sonic\n");
}

void WinConsole::InitSystem()
{
	gEnv->pConsole->AddOutputPrintSink(this);
	PrintExistingMessages();
}

void WinConsole::ShutdownConsole()
{
	if (m_pConsoleFile) {
		fclose(m_pConsoleFile);
		m_pConsoleFile = nullptr;
	}
}

void WinConsole::Print(const char* inszText)
{
	m_Parser.ProcessLine(inszText);
	printf("\n");
}

void WinConsole::PrintExistingMessages()
{
	Print("$5>>>>>>>> Printing console log");
	int count = gEnv->pConsole->GetLineCount();

	for (int i = count - 1; i >= 0; i--) {
		char buf[1024];
		gEnv->pConsole->GetLineNo(i, buf, sizeof(buf));
		Print(buf);
	}

	Print("$5>>>>>>>> Finished printing console log");
}

void WinConsole::ConsoleParser::PrintText(const char* text, size_t size, int colorIdx)
{
	SetConsoleTextAttribute((HANDLE)pCon->m_hStdHandle, g_ConColors[colorIdx]);
	fwrite(text, 1, size, stdout);
}

void WinConsole::ConsoleParser::NewLine()
{
	printf("\n");
}
