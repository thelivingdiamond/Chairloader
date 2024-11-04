#pragma once

class WizardStage : NoCopy
{
public:
    WizardStage();
    WizardStage(std::string_view displayName);
    virtual ~WizardStage();

    //! @returns The display name of the stage.
    const std::string& GetDisplayName() const { return m_DisplayName; }

    //! Sets the display name.
    void SetDisplayName(std::string_view value) { m_DisplayName = value; }

    //! @returns The list of dependencies. They nust be successful for this stage to be processes.
    const std::vector<WizardStage*>& GetDependencies() const { return m_Deps; }

    //! Adds a dependency. CheckFinishedConditionAsync won't be called unless all deps are successful.
    void AddDependency(WizardStage* pStage) { m_Deps.push_back(pStage); }

    //! Resets internal processes.
    virtual void Reset() {}

    //! Updates internal processes. Called only when active.
    virtual void Update() {}

    //! Shows ImGui UI.
    virtual void ShowContent();

    //! @returns Whether this stage can continue to the next stage. Enables/disables the button.
    virtual bool CanContinue() { return true; }

    //! @returns Whether it's possible to go back to this stage. Enables/disables the button.
    virtual bool CanReturn() { return true; }

    //! @returns Whether it's possible to cancel this stage (e.g. total cancel or go back).
    virtual bool CanCancel() { return true; }

    //! Attempts to switch to the next stage. Only called if CanContinue() == true.
    //! Use this to start some operation on continue.
    //! @returns Whether to switch to the next stage.
    virtual bool TryContinue() { return true; }

    //! Attempts to cancel the operation.
    //! @returns Whether to allow cancel.
    virtual bool TryCancel() { return true; }

    //! Whether to automatically continue to the next stage if possible.
    virtual bool AutoContinue() { return false; }

    //! Called when stage becomes active
    virtual void OnActive() {}

    //! Called when stage becomes inactive (when switching to a different stage).
    virtual void OnInactive() {}

    //! @returns Whether this stage is finished.
    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial);

private:
    std::string m_DisplayName;
    std::vector<WizardStage*> m_Deps;
};
