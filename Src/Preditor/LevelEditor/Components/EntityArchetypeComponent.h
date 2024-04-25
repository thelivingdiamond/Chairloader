#pragma once
#include "Components/Component.h"

namespace LevelEditor
{

//! Component for entities with an archetype.
class EntityArchetypeComponent : public Component
{
public:
    EntityArchetypeComponent();
    ~EntityArchetypeComponent();

    //! @returns the archetype name.
    const std::string& GetArchetypeName() const { return m_ArchetypeName; }

    //! @returns the archetype instance. Mey be null.
    IEntityArchetype* GetArchetype() const { return m_pArchetype; }

    //! Sets the archetype by name.
    //! @returns whether the archetype was found.
    bool SetArchetype(const char* name);

    //! Sets the archetype directly.
    void SetArchetype(IEntityArchetype* pArchetype);

protected:
    // Component
    virtual void ShowInspector();

private:
    std::string m_ArchetypeName;
    IEntityArchetype* m_pArchetype = nullptr;
};

} // namespace LevelEditor
