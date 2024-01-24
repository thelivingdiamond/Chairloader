#pragma once
#include "Components/Component.h"
#include "Objects/EntityObject.h"

namespace LevelEditor
{

class EntityComponent : public Component
{
public:
    EntityComponent() = default;
    ~EntityComponent() = default;

    // Component
    EntityObject* GetObject() const { return static_cast<EntityObject*>(Component::GetObject()); }
};

} // namespace LevelEditor
