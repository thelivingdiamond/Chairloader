#pragma once
#include <Manager/SynchronizedData.h>
#include <Wizard/WizardStage.h>

class ProgressWizardStage : public WizardStage
{
public:
    enum class EState
    {
        //! Task has not started yet.
        NotStarted,

        //! Task is currently running
        InProgress,

        //! Task has finished successfully
        Success,

        //! Task has failed with an error.
        Error,
    };

    using WizardStage::WizardStage;
    ~ProgressWizardStage();

    //! @returns Current task state.
    EState GetState() const { return m_State; }

    // WizardStage
    virtual bool CanContinue() override { return m_State == EState::Success; }
    virtual bool CanReturn() override { return false; }
    virtual bool CanCancel() override { return m_State == EState::Success || m_State == EState::Error; }
    virtual void OnActive() override;

protected:
    //! Sets the task future to check. Future must exist as long as this ProgressWizardStage.
    //! This means that `future` must be class field!
    template <typename T>
    void SetTaskFutureRef(const std::future<T>& future)
    {
        CRY_ASSERT(m_State == EState::NotStarted);

        // Type-erasure using a lambda
        // T may be anything
        m_CheckFutureFunction = [&future]() { return IsFutureReady(future); };
        m_State = EState::InProgress;
    }

    //! Start the async task.
    virtual void StartTask() = 0;

    //! Called when the async task finishes (future is ready).
    //! Future must be set by a call to
    //! Any exception in this method will turn into an error message.
    virtual void OnTaskFinished() = 0;

    //! Updates the progress bar. Thread-safe.
    void Task_UpdateProgressBar(float progress);

    //! Updates the text under progress bar. Thread-safe.
    void Task_UpdateProgressSubtext(std::string_view text);

    //! Adds a message to the log. Thread-safe.
    void Task_LogMessage(std::string_view msg);

    // WizardStage
    virtual void Update() override;
    virtual void ShowContent() override;

private:
    EState m_State = EState::NotStarted;
    std::function<bool()> m_CheckFutureFunction;
    std::string m_ErrorText;

    SynchronizedData<float> m_ProgressBar = -1;
    SynchronizedData<std::string> m_ProgressSubtext;
    SynchronizedData<std::vector<std::string>> m_Log;
    size_t m_LastLogSize = 0;
};
