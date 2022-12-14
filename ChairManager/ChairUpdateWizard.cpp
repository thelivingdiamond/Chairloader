//
// Created by theli on 11/12/2022.
//
#pragma once

#include "ChairUpdateWizard.h"
#include "ChairManager.h"
#include "UpdateHandler.h"

static const ImVec2 DEFAULT_WINDOW_SIZE = { 600, 400 };
static ImVec2 WINDOW_SIZE = DEFAULT_WINDOW_SIZE;

bool ChairUpdateWizard::Show(const char *name, bool *pbIsOpen) {
    m_Cancel = false;

    ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize;

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
            case State::Download:
                ShowDownloadPage();
                break;
            case State::Install:
                ShowInstallPage();
                break;
            case State::Confirm:
                ShowConfirmPage();
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
        *pbIsOpen = !m_Cancel;
    }

//    assert(!m_SuccessFinish || m_State == State::Finish);
    return m_SuccessFinish || m_Cancel;
}

void ChairUpdateWizard::ShowErrorPage() {
    ImGui::TextWrapped("An error has occured during the update process:");
    ImGui::TextWrapped("%s", m_ErrorText.c_str());
    ShowBottomBtns(BtnCallback(), BtnCallback(), [&]() { m_Cancel = true; });
}

void ChairUpdateWizard::ShowWelcomePage() {
    ImGui::TextWrapped("Welcome to the update wizard. This will update to the latest version of Chairloader. The following steps will happen:");
    ImGui::Text("\t1) Download the latest version from github, if a new version available");
    ImGui::Text("\t2) Install the update to Chair Manager and unpack the new Chairloader release");
    ImGui::Text("\t3) Chair Manager will restart and the new updates will be applied");
    ImGui::NewLine();


    ShowBottomBtns(BtnCallback(), [&]() {
        m_State = State::Confirm;
        }, [&]() { m_Cancel = true; });
}

void ChairUpdateWizard::ShowConfirmPage() {
    static bool m_bUpdateAvailable;
    static VersionCheck::DLLVersion m_LatestVersion, m_CurrentVersion;
    static bool m_bRefresh = true;
    if(m_bRefresh){
        m_bRefresh = false;
        m_LatestVersion = VersionCheck::getLatestChairloaderVersion();
        m_CurrentVersion = VersionCheck::getInstalledChairloaderVersion();
        m_bUpdateAvailable = m_LatestVersion > m_CurrentVersion;
    }
    if(m_bUpdateAvailable){
        ImGui::TextWrapped("A new version of Chairloader is available. Do you want to update?");
        ImGui::Text("\tCurrent Version: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
        ImGui::Text("\tNew Version: %s", VersionCheck::getLatestChairloaderVersion().String().c_str());
        ImGui::NewLine();
        if(ImGui::Selectable("Check for updates again")){
            m_bRefresh = true;
        }
        ShowBottomBtns([&]() { m_State = State::Welcome; }, [&]() { m_State = State::Download; UpdateHandler::asyncDownloadUpdate();}, [&]() { m_Cancel = true; });
    } else {
        ImGui::TextWrapped("You are already on the latest version of Chairloader, no update is required.");
        if(ImGui::Selectable("Check for updates again")){
            m_bRefresh = true;
        }
        ImGui::NewLine();
        ShowBottomBtns(BtnCallback(), [&]() { m_Cancel = true; m_SuccessFinish = true; m_bRefresh = true;}, BtnCallback(), true);
    }

}

void ChairUpdateWizard::ShowDownloadPage() {
    UpdateHandler::asyncDownloadCheck();
    ImGui::TextWrapped("Downloading update...");
    ImGui::ProgressBar(UpdateHandler::getProgress() / UpdateHandler::getProgressTotal(), ImVec2(0.0f, 0.0f));
    ImGui::SameLine();
    // check if the total is MB or KB
    if(UpdateHandler::getProgressTotal() > 1000000){
        ImGui::Text("%.2f MB / %.2f MB", UpdateHandler::getProgress() / 1000000.0f, UpdateHandler::getProgressTotal() / 1000000.0f);
    } else {
        ImGui::Text("%.2f KB / %.2f KB", UpdateHandler::getProgress() / 1000.0f, UpdateHandler::getProgressTotal() / 1000.0f);
    }
    if(!UpdateHandler::isDownloading()){
       if(UpdateHandler::isErrored()){
           m_State = State::Error;
           m_ErrorText = UpdateHandler::getError();
       } else {
           ShowBottomBtns(BtnCallback(), [&]() { m_State = State::Install; UpdateHandler::asyncInstallUpdate(); }, [&]() { m_Cancel = true; });
       }
    }
}

void ChairUpdateWizard::ShowInstallPage() {
    UpdateHandler::asyncInstallCheck();
    ImGui::TextWrapped("Installing update...");
    if(!UpdateHandler::isInstalling()){
        if(UpdateHandler::isErrored()){
            m_State = State::Error;
            m_ErrorText = UpdateHandler::getError();
        } else {
            ImGui::Text("Update installed successfully!");
            ImGui::NewLine();
            ShowBottomBtns(BtnCallback(), [&]() { m_State = State::Finish; }, BtnCallback());
        }
    }

}

void ChairUpdateWizard::ShowFinishPage() {
    ImGui::TextWrapped("The update has been installed successfully. Chair Manager will now restart.");
    ShowBottomBtns(BtnCallback(), [&]() { UpdateHandler::finishUpdate(); }, BtnCallback(), true);
}

void ChairUpdateWizard::StartUpdate() {

}

void ChairUpdateWizard::SetError(const std::string &text) {
    m_State = State::Error;
    m_ErrorText = text;

}



void ChairUpdateWizard::ShowBottomBtns(ChairUpdateWizard::BtnCallback &&back, ChairUpdateWizard::BtnCallback &&next,
                                       ChairUpdateWizard::BtnCallback &&cancel, bool isFinish) {
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

float ChairUpdateWizard::GetButtonRowHeight() {
    return ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 4;
}