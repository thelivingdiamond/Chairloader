#pragma once
#include <functional>
#include <string>
#include <utility>
#include <vector>
#include "../Entry.h"
#include "../IProvider.h"

namespace ReferenceCatalog
{

//! Provider whose Load() implementation is a user-supplied callable. Use for
//! anything that doesn't fit XmlFileProvider's flat-XML pattern: querying
//! `gEnv->p*` registries (entity classes, audio triggers, factions, etc.),
//! walking compound data structures, derived/computed catalogs, test fixtures.
//!
//! The callable runs synchronously inside `Catalog::TryGet` on first access
//! (or on `Refresh`). Capture any state you need by value. `gEnv` lookups
//! inside the callable are safe — Load() doesn't fire until the catalog is
//! queried, by which time engine subsystems are up.
//!
//! Threading: the callable runs while Catalog's mutex is held, so do NOT call
//! back into the same Catalog (would deadlock). Plain reads of `gEnv->p*` are
//! fine.
//!
//! Example:
//! @code
//! Catalog::Get().RegisterProvider("EntityClass",
//!     std::make_unique<FunctionProvider>(
//!         [] {
//!             std::vector<Entry> out;
//!             auto* reg = gEnv->pEntitySystem->GetClassRegistry();
//!             reg->IteratorMoveFirst();
//!             while (IEntityClass* c = reg->IteratorNext())
//!                 out.push_back({c->GetName(), c->GetName(), "EntitySystem"});
//!             return out;
//!         },
//!         "Entity classes (gEnv->pEntitySystem)"));
//! @endcode
class FunctionProvider : public IProvider
{
public:
    using LoadFn = std::function<std::vector<Entry>()>;

    explicit FunctionProvider(LoadFn loader, std::string description = {})
        : m_Loader(std::move(loader))
        , m_Description(std::move(description))
    {
    }

    std::vector<Entry> Load() override
    {
        return m_Loader ? m_Loader() : std::vector<Entry>{};
    }

    std::string Description() const override { return m_Description; }

private:
    LoadFn m_Loader;
    std::string m_Description;
};

} // namespace ReferenceCatalog
