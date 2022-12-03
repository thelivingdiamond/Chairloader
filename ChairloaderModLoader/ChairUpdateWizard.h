//
// Created by theli on 11/12/2022.
//

#ifndef CHAIRLOADER_UPDATEWIZARD_H
#define CHAIRLOADER_UPDATEWIZARD_H

#pragma once


class ChairUpdateWizard {
public:
    //! Shows the update wizard dialog.
    //! @returns true if update has succeded.
    bool Show(const char* name, bool* pbIsOpen);

private:
    enum class State
    {
        Error,
        Welcome,
        Confirm,
        Download,
        Install,
        Finish,
    };

    using BtnCallback = std::function<void()>;

    State m_State = State::Welcome;
    bool m_Cancel = false;
    bool m_SuccessFinish = false;

    // State::Error
    std::string m_ErrorText;

    // State::Confirm
    bool m_bDeleteModFolder = false;

    // State::Finish
    bool m_patched;
    std::string m_patchMessage;


    void ShowErrorPage();
    void ShowWelcomePage();
    void ShowConfirmPage();
    void ShowDownloadPage();
    void ShowInstallPage();
    void ShowFinishPage();

    void StartUpdate();
    void SetError(const std::string& text);

    float GetButtonRowHeight();
    void ShowBottomBtns(BtnCallback&& back, BtnCallback&& next, BtnCallback&& cancel, bool isFinish = false);

};


#endif //CHAIRLOADER_UPDATEWIZARD_H
