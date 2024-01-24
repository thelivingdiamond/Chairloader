#pragma once
#include "Components/EntityComponent.h"

namespace LevelEditor
{

class ScriptTableEditor;

//! Component for an entity object's Lua script and properties.
class EntityScriptComponent : public EntityComponent
{
public:
    EntityScriptComponent();
    ~EntityScriptComponent();

    //! Sets a new entity class.
    void SetEntityClass(IEntityClass* pClass);

    //! Loads properties from the entity.
    void LoadEntityProperties();

    //! Applies all proeprties to the entity.
    //! @param  notifyEntity    Send entity event that properties have changed.
    void ApplyEntityProperties(bool notifyEntity);

    // EntityComponent
    virtual void ShowInspector() override;

private:
    static constexpr char PROPERTIES_TABLE[] = "Properties";
    static constexpr char PROPERTIES2_TABLE[] = "PropertiesInstance";

    //! The entity class.
    IEntityClass* m_pClass = nullptr;

    //! Whether the component was initialized correctly.
    bool m_bInitialized = false;

    //! Lua function to call on the entity when a property is changed.
    HSCRIPTFUNCTION m_hOnPropertyChangedFunc;

    //! Entity properties and edit UI
    //! @{
    std::unique_ptr<ScriptTableEditor> m_pProperties;
    std::unique_ptr<ScriptTableEditor> m_pProperties2;
    //! @}
    
    //! Called when an entity property is changed in the GUI.
    void OnPropertyChanged();
};

} // namespace LevelEditor
