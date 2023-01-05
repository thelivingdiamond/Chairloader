#pragma once
#include <pugixml.hpp>

//! UserProjectSettings
//! Keeps project settings that are unrelated to the project data
//! and that are adjusted per-user (e.g. main window size).
class UserProjectSettings
{
public:
	//! Name of the XML file.
	static constexpr char FILE_NAME[] = "UserSettings.xml";

	//! The invalid value for size and position.
	static constexpr int INVALID_SIZE = -65536;

	UserProjectSettings(const fs::path& path);

	//! @returns whether there are unsaved changes.
	bool IsDirty() const { return m_bDirty; }

	//! Marks the file for saving.
	void MarkDirty();

	//! Creates or saves the config file
	void SaveFile();

	//! Per frame update.
	void Update();

	//! Non-maximized window pos and size
	//! @{
	const Vec2i& GetWindowRestoredPos() const { return m_WindowRestPos; }
	void SetWindowRestoredPos(const Vec2i& val);

	const Vec2i& GetWindowRestoredSize() const { return m_WindowRestSize; }
	void SetWindowRestoredSize(const Vec2i& val);
	//! @}

	//! @returns whether the window was maximized.
	bool IsWindowMaximized() const { return m_bWindowMaximized; }
	void SetWindowMaximized(bool val);

private:
	static constexpr int SAVE_DELAY_MS = 3000;

	// Window size in "restored" state (non-maximized).
	Vec2i m_WindowRestPos = Vec2i(INVALID_SIZE, INVALID_SIZE);
	Vec2i m_WindowRestSize = Vec2i(INVALID_SIZE, INVALID_SIZE);

	bool m_bWindowMaximized = false;

	fs::path m_FilePath;
	bool m_bDirty = false;
	pugi::xml_document m_Xml;
	std::chrono::steady_clock::time_point m_NextSaveTime;

	void LoadFile();

	//! Creates the attribute if needs to.
	//! @returns the attribute.
	pugi::xml_attribute EnsureAttribute(pugi::xml_node& node, const char* name);

	template <typename T>
	bool UpdateValue(T& field, const T& val)
	{
		if (field != val)
		{
			field = val;
			MarkDirty();
			return true;
		}
		else
		{
			return false;
		}
	}
};
