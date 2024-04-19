#pragma once

class ConsoleColorParser
{
public:
	ConsoleColorParser();
	virtual ~ConsoleColorParser() = default;

	//! Parses the CryEngine console line. Calls protected methods.
	//! Doesn't call NewLine.
	void ProcessLine(const char* line);

protected:
	//! Prints the text with specified color.
	virtual void PrintText(const char* text, size_t size, int color) = 0;

	//! Called for \n. Goes to the next line.
	virtual void NewLine() = 0;

private:
	static constexpr size_t RESERVE_SIZE = 2048;
	std::vector<char> m_Str;

	void Commit(int color);
};
