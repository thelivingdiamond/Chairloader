#include <Manager/ConfigManager.h>
#include "UI/ModConfigTab.h"

Assets::ModConfigTab::ModConfigTab(IChairManager* pChair)
{
    m_pConfigManager = std::make_unique<ConfigManager>();
    m_pChair = pChair;
}

Assets::ModConfigTab::~ModConfigTab()
{
}

bool Assets::ModConfigTab::HasUnsavedChanges()
{
    return m_pConfigManager->IsDirty();
}

void Assets::ModConfigTab::Reset()
{
    m_pConfigManager->init(m_pChair);
}

void Assets::ModConfigTab::ApplyChanges()
{
    m_pConfigManager->saveDirtyConfigs();
}

void Assets::ModConfigTab::ShowContents()
{
    m_pConfigManager->draw();
}
