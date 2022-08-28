#pragma once

class GamePathDialog
{
public:
	enum class Result
	{
		None,
		Ok,
		Cancel,
	};

	Result ShowDialog(const char* name, bool* pbIsOpen);
	Result ShowModal(const char* name);
	Result ShowContents();
	const fs::path& GetGamePath() { return m_Path; }
	void SetGamePath(const fs::path& path);

private:
	bool m_IsValid = false;
	char m_PathInput[260] = {};
	std::string m_ValidationError;
	fs::path m_Path;

	void ValidatePath();
};
