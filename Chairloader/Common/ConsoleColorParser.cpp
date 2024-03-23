#include "ConsoleColorParser.h"

static constexpr char TAB_STRING[] = "    ";

static bool IsAsciiDigit(char c)
{
	// Used instead of isdigit because isdigit may reference the locale
	return c >= '0' && c <= '9';
}

ConsoleColorParser::ConsoleColorParser()
{
	m_Str.reserve(RESERVE_SIZE);
}

void ConsoleColorParser::ProcessLine(const char* line)
{
	const char* strIn = line;
	bool isEscape = false;
	bool isColor = false;
	int color = 0;

	m_Str.clear();

	for (; *strIn != '\0'; strIn++)
	{
		// Handle control characters
		switch (*strIn)
		{
		case '\n':
			Commit(color);
			color = 0;
			[[fallthrough]];
		case '\r':
			// Not supported
			// ClearLine(position);
			[[fallthrough]];
		case '\0':
			// Don't print null-terminators. They will mess something up.
			// But it must still eat the escape.
			if (isEscape)
				m_Str.push_back('\\');
			isEscape = false;
			continue;
		}

		// Handle escaped characters
		if (isEscape)
		{
			// Disable escape
			isEscape = false;

			// Only some characters can be escaped
			// Others will be printed as-is with backslash
			switch (*strIn)
			{
			case '$':
				m_Str.push_back('$');
				continue;
			default:
				m_Str.push_back('\\');
				m_Str.push_back(*strIn);
				continue;
			}
			continue;
		}

		// Handle special characters
		switch (*strIn)
		{
		case '$':
			isColor = true;
			continue;
		case '\\':
			isEscape = true;
			continue;
		}

		// Handle color-codes
		if (isColor)
		{
			if (IsAsciiDigit(*strIn))
			{
				// Commit with the old color
				Commit(color);

				// Next text will use the new color
				color = *strIn - '0';
			}
			else
			{
				// Not a color code. Print as-is
				m_Str.push_back('$');
				m_Str.push_back(*strIn);
			}

			isColor = false;
			continue;
		}

		// Print non-special characters
		m_Str.push_back(*strIn);
	}

	Commit(color);
}

void ConsoleColorParser::Commit(int color)
{
	if (m_Str.empty())
		return;

	PrintText(m_Str.data(), m_Str.size(), color);
	m_Str.clear();
}
