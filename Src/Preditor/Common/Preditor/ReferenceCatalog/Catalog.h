#pragma once
#include <memory>
#include <mutex>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include "IProvider.h"
#include "Table.h"

namespace ReferenceCatalog
{

//! Owns one Table per registered kind. Loads lazily on first TryGet, and
//! reloads on demand via Refresh. Tables are immutable snapshots wrapped in
//! shared_ptr<const Table>, so a stale pointer in a render frame never gets
//! invalidated by a concurrent Refresh.
//!
//! Single-process singleton. Thread-safe: a mutex serializes registration
//! and load; queries that hit an already-loaded kind acquire the same mutex
//! briefly to fetch the snapshot pointer (microseconds — adequate for the
//! handful of inspector queries per frame).
class Catalog
{
public:
    static Catalog& Get();

    //! Registers a provider for the given kind. If a provider is already
    //! registered, replaces it and clears any cached table. Kind is a free-
    //! form identifier (e.g. "GameToken", "RemoteEvent") used by callers.
    void RegisterProvider(std::string kind, std::unique_ptr<IProvider> provider);

    //! Returns the table for `kind`, loading it on first call. Returns
    //! nullptr if no provider is registered for that kind.
    std::shared_ptr<const Table> TryGet(std::string_view kind);

    //! Forces a re-load for the given kind. No-op if no provider is
    //! registered. The previous Table snapshot stays alive for any callers
    //! still holding a shared_ptr to it.
    void Refresh(std::string_view kind);

    //! All registered kind names, sorted alphabetically. For the browser UI.
    std::vector<std::string> Kinds() const;

    //! Provider description for a kind, or empty if unknown.
    std::string DescriptionOf(std::string_view kind) const;

private:
    Catalog() = default;
    Catalog(const Catalog&) = delete;
    Catalog& operator=(const Catalog&) = delete;

    struct Slot
    {
        std::unique_ptr<IProvider> provider;
        std::shared_ptr<const Table> table; //!< nullptr until first load.
    };

    Slot* FindSlot(std::string_view kind);
    const Slot* FindSlot(std::string_view kind) const;

    mutable std::mutex m_Mutex;
    std::unordered_map<std::string, std::unique_ptr<Slot>> m_Slots;
};

} // namespace ReferenceCatalog
