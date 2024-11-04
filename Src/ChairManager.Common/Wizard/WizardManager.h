#pragma once
#include <Manager/ILogger.h>

class WizardStage;

//! Manages a wizard dialog. Shows Prev/Next buttons, calls into specific wizard stages.
class WizardManager : NoCopy
{
public:
    WizardManager(ILogger* logger);
    ~WizardManager();

    //! Restarts the initial check and switches to the first stage.
    void Reset();

    //! Adds a stage into the wizard.
    //! Can only be called before first update or show.
    void AddStage(WizardStage* pStage);

    bool IsDone() const { return m_State == EState::Done; }
    bool IsCancelled() const { return m_Cancelled; }
    bool IsStageDone(WizardStage* pStage) const;

    //! Sets the text that is shown during initial check.
    void SetInitialCheckText(std::string_view value) { m_InitialCheckText = value; }

    //! Updates the internal process without showing a dialog.
    //! @returns Whether still running.
    bool UpdateNoDialog();

    //! Updates and shows dialog content.
    //! @returns Whether still running.
    bool ShowContent();

private:
    enum class EState
    {
        None, //!< Not yet running
        InitialCheck, //!< Initial check for steps
        Wizard, //!< Show the wizard dialog
        CheckingCurrentResult, //!< Checking whether current stage has succeded
        Done, //!< All steps are finished
    };

    struct Stage
    {
        //! Stage instance.
        WizardStage* pStage = nullptr;

        //! Indices of stages that this one depends on.
        std::vector<size_t> dependsOn;

        //! Whether the stage was done from the start.
        bool initialStatus = false;

        //! Whether the stage was completed successfully.
        bool isDone = false;
    };

    ILogger* m_pLogger = nullptr;
    EState m_State = EState::None;
    bool m_Cancelled = false;
    std::vector<Stage> m_Stages;
    std::vector<int> m_VisibleStages;
    
    // InitialCheck
    std::string m_InitialCheckText = "Initializing...";
    std::future<void> m_InitialCheckFuture;

    // Wizard
    int m_CurrentVisibleIdx = -1;

    // CheckingCurrentResult
    std::future<bool> m_CurrentCheckFuture;

    int GetCurrentStageIdx() const { return m_VisibleStages[m_CurrentVisibleIdx]; }
    void Update();
    void GoToNext();
    void GoToPrev();
    void Finish();
    void Cancel();

    void OnCurrentCheckFinished();

    std::future<void> InitialCheckAsync();
    std::future<bool> CurrentCheckAsync();
};
