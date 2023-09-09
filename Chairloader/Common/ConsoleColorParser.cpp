#include "ConsoleColorParser.h"

static constexpr char TAB_STRING[] = "    ";

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

	while (*strIn) {
		switch (*strIn) {
		case '$':
			if (!isEscape) {
				isColor = true;
				break;
			}
			[[fallthrough]];
		case '\\':
			if ((isEscape = !isEscape)) {
				break;
			}
		case 'n':
			if (isEscape) {
				[[fallthrough]];
		case '\n':
			Commit(color);
			color = 0;
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
			m_Str.insert(m_Str.end(), std::begin(TAB_STRING), std::end(TAB_STRING) - 1);
			isEscape = false;
			break;
			}
			[[fallthrough]];
		default:
			if (isColor) {
				if (isdigit(*strIn)) {
					Commit(color);
					color = *strIn - '0';
				}

				isColor = false;
			}
			else {
				if (isEscape && (*strIn != '\\')) {
					m_Str.push_back('\\');
				}
				if (*strIn) {
					m_Str.push_back(*strIn);
				}
			}
			isEscape = false;
			break;
		}
		strIn++;
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
