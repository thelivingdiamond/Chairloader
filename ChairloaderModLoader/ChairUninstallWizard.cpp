//
// Created by theli on 8/30/2022.
//

#include "ChairUninstallWizard.h"
#include "PathUtils.h"
#include "ModLoader.h"

static const ImVec2 WINDOW_SIZE = { 600, 400 };

bool ChairUninstallWizard::Show(const char *name, bool *pbIsOpen) {
    m_Cancel = false;

    ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoResize;

    ImGui::SetNextWindowSize(WINDOW_SIZE);
    if (ImGui::Begin(name, pbIsOpen, windowFlags))
    {
        switch (m_State)
        {
            case State::Error:
                ShowErrorPage();
                break;
            case State::Welcome:
                ShowWelcomePage();
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

    assert(!m_SuccessFinish || m_State == State::Finish);
    return m_SuccessFinish;
}

void ChairUninstallWizard::ShowErrorPage() {
    ImGui::TextWrapped("An error has occured during the uninstall process:");
    ImGui::TextWrapped("%s", m_ErrorText.c_str());
    ShowBottomBtns(BtnCallback(), BtnCallback(), [&]() { m_Cancel = true; });
}

void ChairUninstallWizard::ShowWelcomePage() {
    ImGui::TextWrapped("Welcome to the uninstall wizard. This will uninstall the Chairloader DLL's from the game. You will also have the option to delete the mods folder.");
//    ImGui::Text("\t1) Check if your version of the game is supported");
//    ImGui::Text("\t2) Patch the game DLL file for Chairloader");
//    ImGui::Text("\t3) Install Chairloader files");
    ImGui::NewLine();


    ShowBottomBtns(BtnCallback(), [&]() { m_State = State::Confirm; }, [&]() { m_Cancel = true; });

}

void ChairUninstallWizard::ShowConfirmPage() {
    ImGui::TextWrapped("Chairloader is ready to be uninstalled.");
    ImGui::NewLine();

    ImGui::Text("This will remove the config files, mod files, and any other files stored in the Mods/ folder in the game directory."
                "\nOnly choose if you are certain you will never use Chairloader again.");
    ImGui::Checkbox("Delete mods folder", &m_bDeleteModFolder);
    ImGui::NewLine();

    ImGui::TextWrapped("Do you wish to proceed?");
    ShowBottomBtns([&]() { m_State = State::Welcome; }, [&]() { StartUninstall(); }, [&]() { m_Cancel = true; });

}

void ChairUninstallWizard::ShowFinishPage() {
    ImGui::TextWrapped("Chairloader has been successfully uninstalled.");
    ShowBottomBtns(BtnCallback(), [&]() { m_SuccessFinish = true; }, BtnCallback(), true);
}

void ChairUninstallWizard::StartUninstall() {
    fs::path dstBinPath = ModLoader::Get().GetGamePath() / PathUtils::GAME_BIN_DIR;
    try{
        // Removing binaries
        for(auto & requiredFile : PathUtils::REQUIRED_CHAIRLOADER_BINARIES){
            remove(dstBinPath / requiredFile);
        }

        // Remove patch file
        fs::remove(ModLoader::Get().GetGamePath() / PathUtils::CHAIRLOADER_PATCH_PATH);

        // remove mods folder
        if(m_bDeleteModFolder){
            fs::remove_all(ModLoader::Get().GetGamePath() / "Mods");
        }
    } catch (const std::exception& e) {
        SetError(e.what());
        return;
    }

    m_State = State::Finish;

}

void ChairUninstallWizard::SetError(const std::string &text) {
    m_State = State::Error;
    m_ErrorText = text;
}

float ChairUninstallWizard::GetButtonRowHeight() {
    return ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 4;
}

void ChairUninstallWizard::ShowBottomBtns(ChairUninstallWizard::BtnCallback &&back, ChairUninstallWizard::BtnCallback &&next, ChairUninstallWizard::BtnCallback &&cancel, bool isFinish) {
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
