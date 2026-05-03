#pragma once
#include <string>
#include <vector>
#include "Entry.h"

namespace ReferenceCatalog
{

//! A pluggable source for a kind's entries. Implementations might scan XML
//! files (XmlFileProvider), iterate engine registries, or pull from a baked
//! database. Load() runs synchronously inside Catalog::TryGet/Refresh — for
//! v1 we don't background-load, so providers should keep loads cheap (well
//! under 100 ms) or be invoked rarely.
class IProvider
{
public:
    virtual ~IProvider() = default;

    //! Produce the full set of entries. Called the first time the kind is
    //! requested, and again on Refresh. Order doesn't matter — the Table
    //! sorts by name.
    virtual std::vector<Entry> Load() = 0;

    //! Free-form description shown in the catalog browser ("Game tokens from
    //! Libs/GameTokens/*.xml"). Optional.
    virtual std::string Description() const { return {}; }
};

} // namespace ReferenceCatalog
