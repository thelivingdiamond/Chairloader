#pragma once

namespace WinShell
{

struct FileFilter
{
	std::string displayName;
	std::string filter; //!< Like "*.exe" or "*.exe;*.dll"
};

enum DialogFlags
{
	FL_PICK_FOLDERS = 1 << 0,
};

struct DialogOptions
{
	//! Dialog title. If empty, default one is used.
	std::string title;

	//! List of extensions.
	std::vector<FileFilter> fileTypes;

	//! Default extension index
	int defaultFileType = -1;

	//! Default extension (e.g. "exe").
	//std::string defaultExtension;

	//! Default location if there is no recent one.
	fs::path defaultFolder;

	//! If not empty, overrides folder to the specified one.
	fs::path forceFolder;

	//! Bitmask of DialogFlags.
	unsigned flags = 0;
};

struct DialogResult
{
	bool isOk = false;
	fs::path filePath;
};

//! Shows a file open dialog.
std::future<DialogResult> ShowOpenDialog(const DialogOptions& opts);

//! Sends a request to close all open dialogs.
void CloseAllDialogs();

//! Shows a file open dialog in ImGui API-style.
//! If the dialog is already visible, it's options are not updated.
//! Use ImUpdateFileOpenDialog to poll for events.
//! @param	strId	Dialog ID. Independent from the current ID stack.
//! @param	opt		Dialog open options.
//! @returns whether the dialog was opened. If false, the dialog was already opened.
bool ImShowFileOpenDialog(const char* strId, const DialogOptions& opts);

//! Updates a file open dialog.
//! @returns true when the dialog finishes.
bool ImUpdateFileOpenDialog(const char* strId, DialogResult* pDlgResult);

}
