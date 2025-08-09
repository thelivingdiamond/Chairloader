#pragma once
#include <WindowManager/ManagedWindow.h>

namespace GameEditor
{

class GameEditMode;

class EntitySpawner : public ManagedWindow
{
public:
    EntitySpawner();

protected:
    void ShowContents() override;

private:
    std::string m_FilterText;
    std::vector<std::string> m_Achetypes;

    void RefreshList();
    void SpawnArchetype(const std::string& archetypeName);
};

} // namespace GameEditor
