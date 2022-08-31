//
// Created by theli on 8/30/2022.
//

#ifndef CHAIRLOADER_CHAIRUNINSTALLWIZARD_H
#define CHAIRLOADER_CHAIRUNINSTALLWIZARD_H


class ChairUninstallWizard {
public:
    //! Shows the wizard dialog.
    //! @returns true if installation has succeded.
    bool Show(const char* name, bool* pbIsOpen);

private:
    enum class State
    {
        Error,
        Welcome,
        Confirm,
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


    void ShowErrorPage();
    void ShowWelcomePage();
    void ShowConfirmPage();
    void ShowFinishPage();

    void StartUninstall();
    void SetError(const std::string& text);

    float GetButtonRowHeight();
    void ShowBottomBtns(BtnCallback&& back, BtnCallback&& next, BtnCallback&& cancel, bool isFinish = false);

};


#endif //CHAIRLOADER_CHAIRUNINSTALLWIZARD_H
