#pragma once
#include <Chairloader/IChairSceneEditor.h>
#include <Preditor/Main/IPreditor.h>

struct IChairloaderToolsPreditor;
struct IPreditorInput;
struct IAssetSystem;

namespace Main
{

class PreditorUI;
class Project;
class UserProjectSettings;
class SceneEditorManager;

class Preditor : public IPreditor, public IChairSceneEditor
{
public:
    Preditor();
    ~Preditor();

    //! Adds a level to recent level list.
    void AddLevelToRecent(const std::string& path);
    
    // IPreditor
    virtual void InitSystem() override;
    virtual void InitGame() override;
    virtual void ShutdownGame() override;
    virtual void ShutdownSystem() override;
    virtual void Update() override;
    virtual void ShowUI() override;

    // IChairSceneEditor
    virtual EChairSceneEditor GetEditorType() const { return EChairSceneEditor::Preditor; }
    virtual bool IsInSceneView() const;

private:
    PreditorTime m_Time;
    std::unique_ptr<Project> m_pProject;
    std::unique_ptr<UserProjectSettings> m_pUserSettings;
    std::unique_ptr<IAssetSystem> m_pAssetSystem;
    std::unique_ptr<IPreditorInput> m_pInput;
    std::unique_ptr<SceneEditorManager> m_pSceneEditorManager;
    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::unique_ptr<PreditorUI> m_pUI;

    void UpdateTime();
};

} // namespace
