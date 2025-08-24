#include <imgui_internal.h>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <atlbase.h>
#include <shlobj_core.h>
#include <shlobj.h>
#include <WinShell/WinShell.h>

namespace WinShell
{

std::mutex g_AllFileWindowsMutex;
std::set<HWND> g_AllFileWindows;

std::map<ImGuiID, std::future<DialogResult>> g_ImWindows;

struct CComRaii : NoCopy
{
	CComRaii()
	{
		if (!SUCCEEDED(CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE)))
            throw std::runtime_error("CoInitializeEx failed");
	}

	~CComRaii()
	{
		CoUninitialize();
	}
};

// I hate COM so fucking much...
class FileDialogEvents : public IFileDialogEvents
{
public:
	HWND m_hWnd = nullptr;

	FileDialogEvents() {}
	~FileDialogEvents() {}

	// IUnknown
	STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject) override
	{
		if (!ppvObject)
			return E_POINTER;

		if (IsEqualIID(riid, __uuidof(IUnknown)))
		{
			*ppvObject = (IUnknown*)this;
			return S_OK;
		}

		if (IsEqualIID(riid, __uuidof(IFileDialogEvents)))
		{
			*ppvObject = (IFileDialogEvents*)this;
			return S_OK;
		}

		return E_NOINTERFACE;
	}
	STDMETHODIMP_(ULONG) AddRef() override { return 1; };
	STDMETHODIMP_(ULONG) Release() override { return 1; }

	// IFileDialogEvents
	STDMETHODIMP OnFileOk(IFileDialog* pfd) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}
	STDMETHODIMP OnFolderChanging(IFileDialog* pfd, IShellItem* psiFolder) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}
	STDMETHODIMP OnFolderChange(IFileDialog* pfd) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}
	STDMETHODIMP OnSelectionChange(IFileDialog* pfd) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}
	STDMETHODIMP OnShareViolation(IFileDialog* pfd, IShellItem* psi, FDE_SHAREVIOLATION_RESPONSE* pResponse) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}
	STDMETHODIMP OnTypeChange(IFileDialog* pfd) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}
	STDMETHODIMP OnOverwrite(IFileDialog* pfd, IShellItem* psi, FDE_OVERWRITE_RESPONSE* pResponse) override
	{
		UpdateHwnd(pfd);
		return S_OK;
	}

private:
	void UpdateHwnd(IFileDialog* pfd)
	{
		if (m_hWnd)
			return;

		CComPtr<IOleWindow> pWindow;

		if (SUCCEEDED(pfd->QueryInterface(&pWindow)))
		{
			if (SUCCEEDED(pWindow->GetWindow(&m_hWnd)) && m_hWnd)
			{
				// Add to the global list
				std::scoped_lock lock(g_AllFileWindowsMutex);
				g_AllFileWindows.insert(m_hWnd);
			}
		}
	}
};

std::wstring ConvertUTF8ToWide(std::string_view s)
{
	// This is just cursed...
	return fs::u8path(s).wstring();
}

} // namespace Shell

std::future<WinShell::DialogResult> WinShell::ShowOpenDialog(const DialogOptions& opts)
{
	return std::async(std::launch::async, [opts]()
		{
			CComRaii comInit;

			// Create dialog
			CComPtr<IFileOpenDialog> pFileDialog;
			if (FAILED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pFileDialog))))
				throw std::runtime_error("CoCreateInstance failed");

			// Register the event handler
			DWORD eventHandlerCookie = 0;
			FileDialogEvents eventHandler;
			pFileDialog->Advise(&eventHandler, &eventHandlerCookie);

			// Set title
			pFileDialog->SetTitle(ConvertUTF8ToWide(opts.title).c_str());

			// Set flags
			{
				DWORD dwOptions = 0;
				pFileDialog->GetOptions(&dwOptions);

				if (opts.flags & FL_PICK_FOLDERS)
					dwOptions |= FOS_PICKFOLDERS;

				if (pFileDialog->SetOptions(dwOptions) != S_OK)
					throw std::runtime_error("pFileDialog->SetOptions failed");
			}
			
			// Set extensions
			if (!opts.fileTypes.empty())
			{
				std::vector<COMDLG_FILTERSPEC> filters(opts.fileTypes.size());
				std::vector<std::wstring> strBuf(2 * filters.size());

				for (int i = 0; i < filters.size(); i++)
				{
					strBuf[2 * i + 0] = ConvertUTF8ToWide(opts.fileTypes[i].displayName);
					strBuf[2 * i + 1] = ConvertUTF8ToWide(opts.fileTypes[i].filter);
					filters[i].pszName = strBuf[2 * i + 0].c_str();
					filters[i].pszSpec = strBuf[2 * i + 1].c_str();
				}

				if (FAILED(pFileDialog->SetFileTypes(filters.size(), filters.data())))
					throw std::runtime_error("pFileDialog->SetFileTypes failed");

				// Set default extension
				if (opts.defaultFileType != -1)
				{
					assert(opts.defaultFileType >= 0 && opts.defaultFileType < opts.fileTypes.size());
					if (FAILED(pFileDialog->SetFileTypeIndex(opts.defaultFileType + 1)))
						throw std::runtime_error("pFileDialog->SetFileTypeIndex failed");
				}
			}

			// Set default folder
			if (!opts.defaultFolder.empty())
			{
				CComPtr<IShellItem> pDefFolder;
				if (SHCreateItemFromParsingName(opts.defaultFolder.c_str(), nullptr, IID_IShellItem, (void**)&pDefFolder) != S_OK)
					throw std::runtime_error("SHCreateItemFromParsingName failed");
				if (pFileDialog->SetDefaultFolder(pDefFolder) != S_OK)
					throw std::runtime_error("pFileDialog->SetDefaultFolder failed");
			}

			// Set forced folder
			if (!opts.forceFolder.empty())
			{
				CComPtr<IShellItem> pDefFolder;
				if (SHCreateItemFromParsingName(opts.forceFolder.c_str(), nullptr, IID_IShellItem, (void**)&pDefFolder) != S_OK)
					throw std::runtime_error("SHCreateItemFromParsingName failed");
				if (pFileDialog->SetFolder(pDefFolder) != S_OK)
					throw std::runtime_error("pFileDialog->SetDefaultFolder failed");
			}

			// Show the dialog
			HRESULT hr = pFileDialog->Show(nullptr);

			if (eventHandler.m_hWnd)
			{
				// Remove from the global list
				std::scoped_lock lock(g_AllFileWindowsMutex);
				g_AllFileWindows.erase(eventHandler.m_hWnd);
			}

			pFileDialog->Unadvise(eventHandlerCookie);

			if (hr == S_OK)
			{
				CComPtr<IShellItem> pSelectedItem;
				if (FAILED(pFileDialog->GetResult(&pSelectedItem)))
					throw std::runtime_error("pFileDialog->GetResult failed");
				
				CComHeapPtr<WCHAR> pszPath;
				if (FAILED(pSelectedItem->GetDisplayName(SIGDN_FILESYSPATH, &pszPath)))
					throw std::runtime_error("pSelectedItem->GetDisplayName failed");

				DialogResult result;
				result.isOk = true;
				result.filePath = fs::path(pszPath.m_pData);
				return result;
			}
			else if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED))
			{
				return DialogResult();
			}
			else
			{
				throw std::runtime_error("pFileDialog->Show failed");
			}
		});
}

void WinShell::CloseAllDialogs()
{
	std::scoped_lock lock(g_AllFileWindowsMutex);

	for (HWND hWnd : g_AllFileWindows)
	{
		SendNotifyMessageW(hWnd, WM_CLOSE, 0, 0);
	}
}

bool WinShell::ImShowFileOpenDialog(const char* strId, const DialogOptions& opts)
{
	ImGuiID id = ImHashStr(strId);
	auto it = g_ImWindows.find(id);

	if (it != g_ImWindows.end())
		return false;

	std::future<DialogResult> futureResult = ShowOpenDialog(opts);
	g_ImWindows.emplace(id, std::move(futureResult));
	return true;
}

bool WinShell::ImUpdateFileOpenDialog(const char* strId, DialogResult* pDlgResult)
{
	ImGuiID id = ImHashStr(strId);
	auto it = g_ImWindows.find(id);

	if (it == g_ImWindows.end())
		return false;

	if (!IsFutureReady(it->second))
		return false;

	*pDlgResult = it->second.get();
	g_ImWindows.erase(it);
	return true;
}
