#pragma once
#include <Preditor/Main/IPreditor.h>

struct IChairloaderToolsPreditor;
struct IPreditorInput;

namespace Main
{

class PreditorUI;
class Project;
class UserProjectSettings;
class SceneEditorManager;

class Preditor : public IPreditor
{
public:
    Preditor();
    ~Preditor();
    
    // IPreditor
    virtual void InitSystem() override;
    virtual void InitGame() override;
    virtual void ShutdownGame() override;
    virtual void ShutdownSystem() override;
    virtual void Update() override;
    virtual void ShowUI() override;

private:
    std::unique_ptr<Project> m_pProject;
    std::unique_ptr<UserProjectSettings> m_pUserSettings;
    std::unique_ptr<IPreditorInput> m_pInput;
    std::unique_ptr<SceneEditorManager> m_pSceneEditorManager;
    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::unique_ptr<PreditorUI> m_pUI;
};

} // namespace
