#pragma once
#include <Preditor/Main/IUserProjectSettings.h>

namespace Main
{

//! UserProjectSettings
//! Keeps project settings that are unrelated to the project data
//! and that are adjusted per-user (e.g. main window size).
class UserProjectSettings : public IUserProjectSettings
{
public:
	UserProjectSettings(const fs::path& path);

	//! @returns whether there are unsaved changes.
	bool IsDirty() const { return m_bDirty; }

	//! Marks the file for saving.
	void MarkDirty();

	//! Creates or saves the config file
	void SaveFile();

	//! Per frame update.
	void Update();

	// IUserProjectSettings
	virtual const Vec2i& GetWindowRestoredPos() const override { return m_WindowRestPos; }
	virtual void SetWindowRestoredPos(const Vec2i& val) override;
	virtual const Vec2i& GetWindowRestoredSize() const override { return m_WindowRestSize; }
	virtual void SetWindowRestoredSize(const Vec2i& val) override;
	virtual bool IsWindowMaximized() const override { return m_bWindowMaximized; }
	virtual void SetWindowMaximized(bool val) override;

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

} // namespace Main
