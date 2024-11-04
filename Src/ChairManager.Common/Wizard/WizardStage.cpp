#include <Wizard/WizardStage.h>

WizardStage::WizardStage()
{
}

WizardStage::WizardStage(std::string_view displayName)
    : WizardStage()
{
    SetDisplayName(displayName);
}

WizardStage::~WizardStage()
{
}

void WizardStage::ShowContent()
{
    ImGui::Text("Empty content. Override WizardStage::ShowContent");
}

std::future<bool> WizardStage::CheckFinishedConditionAsync(bool isInitial)
{
    // For debugging
    /*return std::async(std::launch::async, [&]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return true;
    });*/

    // Fail on initial, but always done after
    // This will show the wizard in sidebar but will let always go back/next.
    std::promise<bool> promise;
    promise.set_value(!isInitial);
    return promise.get_future();
}
