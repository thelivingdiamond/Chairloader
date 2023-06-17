#pragma once
#include <imgui.h>
#include <WindowManager/IManagedWindow.h>

//! A window managed by the Window Manager.
//! It can work in two modes:
//! Unique mode:
//!   - Each instance is assigned as unique ID.
//!   - This ID is used in the title.
//!   - You can have multiple windows with identical display titles (e.g. for a file editor).
//!   - Such windows cannot be saved to the config because the ID won't persist across restarts.
//!   - Must have ImGuiWindowFlags_NoSavedSettings flag set.
//! Persistent mode:
//!   - Call SetPersistentID with non-empty string.
//!   - The string will be used as the ImGui window ID.
//!   - Such windows can be saved to the config.
//!   - They can still have any title (as long as peristent ID matches).
class ManagedWindow : public IManagedWindow
{
public:
	ManagedWindow();

	//! @param	title	Title of the window
	ManagedWindow(std::string_view title);

	//! @returns the unique ID of the window.
	unsigned GetUniqueId() const { return m_UniqueId; }

	//! Sets the title of the window.
	void SetTitle(std::string_view title);
	const std::string& GetTitle() const { return m_Title; }

	//! Sets the title of the window.
	//! Sets persistent ID of the window. Such windows can be save to the .ini.
	void SetPersistentID(std::string_view id);
	const std::string& GetPersistentID() const { return m_PersistentID; }

	//! Sets the window flags.
	void SetFlags(ImGuiWindowFlags flags);
	ImGuiWindowFlags GetFlags() const { return m_Flags; }

	//! Sets whether the window can be closed by user.
	void SetCloseable(bool state);
	bool IsCloseable() const { return m_bCloseable; }

	//! Sets whether the window is being displayed.
	void SetVisible(bool state);
	bool IsVisible() const { return m_bVisible; }

	//! Sets whether the window will be destroyed when it's closed by the user.
	//! If not, it will become hidden.
	void SetDestroyOnClose(bool state);
	bool IsDestoryOnClose() const { return m_bDestroyOnClose; }

	//! Closes the window.
	void CloseWindow();
	bool IsWindowOpen() const { return m_bOpen; }

	//! Whether the window is focused.
	bool IsFocused() const { return m_bVisible && m_bFocused; }

	// IManagedWindow
	bool UpdateWindow() final override;

protected:
	//! Called before ImGui::Begin only when visible.
	virtual void PreUpdate();

	//! Called just after ImGui::Begin when visible.
	//! Called every WindowManager frame if not visible.
	virtual void Update(bool isVisible);

	//! Shows the contents of the window. This is only called if ImGui::Begin returned true.
	virtual void ShowContents() = 0;

private:
	//! The window's unique ID. Used to resolve conflicts of multiple windows with identical names.
	unsigned m_UniqueId = 0;

	//! Title of the window.
	std::string m_Title;

	//! Persistent ID of the window. See class doc for details.
	std::string m_PersistentID;

	//! Full title of the window (title + ID): e.g. "Example Window###123"
	std::string m_FullTitle;

	//! The window flags to use.
	ImGuiWindowFlags m_Flags = ImGuiWindowFlags_None;

	//! Whether the window is open.
	bool m_bOpen = true;

	//! Whether the window can be closed by user.
	bool m_bCloseable = true;

	//! Whether the window is being displayed.
	bool m_bVisible = true;

	//! Whether to destroy the window when it's closed.
	bool m_bDestroyOnClose = true;

	//! Whether the window is focused.
	bool m_bFocused = false;

	//! Updates m_FullTitle based on IDs.
	void UpdateFullTitle();
};
