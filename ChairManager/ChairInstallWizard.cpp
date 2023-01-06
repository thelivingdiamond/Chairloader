#include <Manager/PathUtils.h>
#include "ChairInstallWizard.h"
#include "GameVersion.h"
#include "ChairManager.h"
#include "BinaryVersionCheck.h"
#include "../Common/Chairloader/SemanticVersion.h"

static const ImVec2 DEFAULT_WINDOW_SIZE = { 600, 400 };
static ImVec2 WINDOW_SIZE = DEFAULT_WINDOW_SIZE;
static bool bDPIUpdated = false;

bool ChairInstallWizard::Show(const char* name, bool* pbIsOpen)
{
	if (m_State == State::Progress)
		pbIsOpen = nullptr;
	m_Cancel = false;

	ImGuiWindowFlags windowFlags =
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoResize;
//    if(!bDPIUpdated) {
//        WINDOW_SIZE = {WINDOW_SIZE.x * ImGui::GetWindowDpiScale(), WINDOW_SIZE.y * ImGui::GetWindowDpiScale()};
//        bDPIUpdated = true;
//    }
    WINDOW_SIZE = {DEFAULT_WINDOW_SIZE.x * ChairManager::Get().GetDPIScale(), DEFAULT_WINDOW_SIZE.y * ChairManager::Get().GetDPIScale()};
    ImGui::SetNextWindowSize(WINDOW_SIZE);
	if (ImGui::Begin(name, pbIsOpen, windowFlags))
	{
        if(ImGui::GetWindowViewport()->DpiScale != ChairManager::Get().GetDPIScale()){
            ChairManager::Get().updateDPI(ImGui::GetWindowViewport()->DpiScale);
        }
		switch (m_State)
		{
		case State::Error:
			ShowErrorPage();
			break;
		case State::Welcome:
			ShowWelcomePage();
			break;
		case State::VersionCheck:
			ShowVersionCheckPage();
			break;
		case State::Confirm:
			ShowConfirmPage();
			break;
		case State::Progress:
			ShowProgressPage();
			break;
		case State::Finish:
			ShowFinishPage();
			break;
		default:
			assert(false);
			std::abort();
		}
	}
	ImGui::End();

	if (pbIsOpen)
	{
		if (m_State == State::Progress)
		{
			// May be closed just before starting the install
			*pbIsOpen = true;
		}
		else
		{
			*pbIsOpen = !m_Cancel;
		}
	}

	assert(!m_SuccessFinish || m_State == State::Finish);
	return m_SuccessFinish;
}

void ChairInstallWizard::ShowErrorPage()
{
	ImGui::TextWrapped("An error has occured during the setup process:");
	ImGui::TextWrapped("%s", m_ErrorText.c_str());

	std::unique_lock lock(m_InstallLogMutex);
	if (!m_InstallLog.empty())
	{
		ImGui::NewLine();
		ImGui::Text("Installation log:");
		const float footer_height_to_reserve = GetButtonRowHeight();
		ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_AlwaysVerticalScrollbar);

		ImGui::PushTextWrapPos(0.0f);
		for (const std::string& line : m_InstallLog)
		{
			ImGui::TextUnformatted(line.c_str());
		}
		ImGui::PopTextWrapPos();

		if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
			ImGui::SetScrollHereY(1.0f);
		ImGui::EndChild();
	}

	ShowBottomBtns(BtnCallback(), BtnCallback(), [&]() { m_Cancel = true; });
}

void ChairInstallWizard::ShowWelcomePage()
{
    if(VersionCheck::getInstalledChairloaderVersion().valid() && VersionCheck::getPackagedChairloaderVersion() > VersionCheck::getInstalledChairloaderVersion())
    {
        ImGui::TextWrapped("Current Installed Version: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
        ImGui::TextWrapped("Available Version: %s", VersionCheck::getPackagedChairloaderVersion().String().c_str());
        ImGui::NewLine();
        ImGui::TextWrapped("Chairloader has been updated to a new version. The latest version will now be installed.");
        ImGui::NewLine();
    } else {
        ImGui::TextWrapped("Before using the Mod Manager, the game needs to be modified to add support "
                           "for code mods. It will be done in the following steps.");
        ImGui::NewLine();
        ImGui::Text("\t1) Check if your version of the game is supported");
        ImGui::Text("\t2) Patch the game DLL file for Chairloader");
        ImGui::Text("\t3) Install Chairloader files");
        ImGui::NewLine();

        ShowPatchWarning(false);
    }

	ShowBottomBtns(BtnCallback(), [&]() { ToVersionCheck(); }, [&]() { m_Cancel = true; });
}

void ChairInstallWizard::ShowVersionCheckPage()
{
	ImGui::TextWrapped("Currently Chairloader only works with one specific version of Prey.");
	ImGui::TextWrapped("Other versions must be converted into that version.");
	ImGui::NewLine();

	m_pGameVersion->Update();
	GameVersion::Result result = m_pGameVersion->ShowInstalledVersion(false);

	auto fnBack = [&]() { m_State = State::Welcome; };
	auto fnNext = [&]() { m_State = State::Confirm; };
	auto fnCancel = [&]() { m_Cancel = true; };

	switch (result)
	{
	case GameVersion::Result::Error:
		ShowBottomBtns(BtnCallback(), BtnCallback(), BtnCallback());
		SetError(m_pGameVersion->GetErrorText());
		break;
	case GameVersion::Result::Loading:
		ShowBottomBtns(fnBack, BtnCallback(), fnCancel);
		break;
	case GameVersion::Result::Supported:
		m_bNeedDllPatch = false;
		ShowBottomBtns(fnBack, fnNext, fnCancel);
		break;
	case GameVersion::Result::Patchable:
		m_bNeedDllPatch = true;
		ShowBottomBtns(fnBack, fnNext, fnCancel);
		break;
	case GameVersion::Result::NotSupported:
		ShowBottomBtns(fnBack, BtnCallback(), fnCancel);
		break;
	}
}

void ChairInstallWizard::ShowConfirmPage()
{
	ImGui::TextWrapped("Chairloader is ready to be installed.");
	ImGui::NewLine();

	if (m_bNeedDllPatch)
	{
		ShowPatchWarning(true);
		ImGui::NewLine();
	}

	ImGui::TextWrapped("This is your last chance to cancel the installation.\nDo you wish to proceed?");
	ShowBottomBtns([&]() { m_State = State::VersionCheck; }, [&]() { StartInstall(); }, [&]() { m_Cancel = true; });
}

void ChairInstallWizard::ShowProgressPage()
{
	ImGui::TextWrapped("Installation is in progress...");
	const float footer_height_to_reserve = GetButtonRowHeight();
	ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_AlwaysVerticalScrollbar);
	ImGui::PushTextWrapPos(0.0f);

	{
		std::unique_lock lock(m_InstallLogMutex);
		for (const std::string& line : m_InstallLog)
		{
			ImGui::TextUnformatted(line.c_str());
		}
	}

	ImGui::PopTextWrapPos();
	if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
		ImGui::SetScrollHereY(1.0f);
	ImGui::EndChild();

	if (m_bIsInstallFinished)
		ShowBottomBtns(BtnCallback(), [&]() { m_State = State::Finish; }, BtnCallback());
	else
		ShowBottomBtns(BtnCallback(), BtnCallback(), BtnCallback());
	

	if (IsFutureReady(m_InstallFuture))
	{
		try
		{
			m_InstallFuture.get();
			m_bIsInstallFinished = true;
		}
		catch (const std::exception& e)
		{
			SetError(e.what());
		}
	}
}

void ChairInstallWizard::ShowFinishPage()
{
	ImGui::TextWrapped("Installation has been successfully completed.");
	ImGui::TextWrapped("You can now use ChairManager.");
	ShowBottomBtns(BtnCallback(), [&]() { m_SuccessFinish = true; }, BtnCallback(), true);
}

void ChairInstallWizard::ToVersionCheck()
{
	if (!m_pGameVersion)
	{
		try
		{
			m_pGameVersion = std::make_unique<GameVersion>();
		}
		catch (const std::exception& e)
		{
			SetError(e.what());
			return;
		}
	}

	m_State = State::VersionCheck;
}

void ChairInstallWizard::StartInstall()
{
	m_State = State::Progress;
	m_InstallFuture = std::async(std::launch::async, [&]() { InstallAsyncTask(); });
}

void ChairInstallWizard::SetError(const std::string& text)
{
	m_State = State::Error;
	m_ErrorText = text;
}

float ChairInstallWizard::GetButtonRowHeight()
{
	return ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 4;
}

void ChairInstallWizard::ShowBottomBtns(BtnCallback&& back, BtnCallback&& next, BtnCallback&& cancel, bool isFinish)
{
	ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), WINDOW_SIZE.y - GetButtonRowHeight()));
	ImGui::BeginDisabled(!back);
	if (ImGui::Button("< Back"))
		back();
	ImGui::EndDisabled();
	ImGui::SameLine();

	ImGui::BeginDisabled(!next);
	if (ImGui::Button(isFinish ? "Finish" : "Next >"))
		next();
	ImGui::EndDisabled();
	ImGui::SameLine();

	ImGui::BeginDisabled(!cancel);
	if (ImGui::Button("Cancel"))
		cancel();
	ImGui::EndDisabled();
}

void ChairInstallWizard::ShowPatchWarning(bool isFinal)
{
	ImGui::TextColored(ImColor(255, 255, 0), isFinal ? "Final Warning: " : "Warning: ");
	ImGui::TextWrapped("Patching the game will turn your version of the game into an Epic Games Store version. "
		"This will disable Steam/GOG integration, including achievements.");
}

void ChairInstallWizard::InstallAsyncTask() const
{
	auto printlog = [&](std::string&& msg)
	{
		std::unique_lock lock(m_InstallLogMutex);
		m_InstallLog.push_back(std::move(msg));
	};

	fs::path srcBinPath = fs::current_path() / PathUtils::CHAIRLOADER_BIN_SRC_PATH;
	fs::path dstBinPath = ChairManager::Get().GetGamePath() / PathUtils::GAME_BIN_DIR;

	printlog("Verifying files...");
	{
		bool allFilesExist = true;

		for (const char* name : PathUtils::REQUIRED_CHAIRLOADER_BINARIES)
		{
			if (!fs::exists(srcBinPath / name))
			{
				printlog(name + std::string(" NOT found"));
				allFilesExist = false;
			}
		}

		if (!allFilesExist)
			throw std::runtime_error("Installation files are missing");
	}

	if (m_bNeedDllPatch)
	{
		printlog("Patching the game DLL...");
		m_pGameVersion->PatchTheGame();
	}
	else
	{
		printlog("DLL patch skipped");
	}

	printlog("Copying binaries...");
	fs::copy(srcBinPath / ".", dstBinPath, fs::copy_options::overwrite_existing | fs::copy_options::recursive);

	printlog("Deploying Chairloader files...");
	ChairManager::Get().DeployForInstallWizard();

    if(fs::exists("ChairManager.old.exe"))
    {
        printlog("Removing old ChairManager.exe...");
        fs::remove("ChairManager.old.exe");
    }

	printlog("Finished!");
}
