#pragma once
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include "Entry.h"

namespace ReferenceCatalog
{

//! Returns a canonical decimal form for `id` so signed and unsigned 64-bit
//! representations of the same bit pattern compare equal. E.g.,
//! "-4589863060514743348" and "13856881013194808268" both canonicalize to
//! "13856881013194808268". Non-numeric ids pass through unchanged.
//!
//! This matters because flowgraphs sometimes serialize 64-bit ids as signed
//! int64 (negative when the high bit is set) while library XMLs store them
//! as unsigned uint64. Both representations must hash to the same bucket.
std::string CanonicalizeId(std::string_view id);

//! Immutable snapshot of all known entries for a kind. Built once per Load
//! by the Catalog and replaced wholesale on Refresh; consumers hold a
//! shared_ptr<const Table> so prior snapshots stay valid until released.
//!
//! Lookups are O(1) by id and O(1) amortized by name (multimap — collisions
//! are allowed since two libraries can share a name with different ids).
//! Id lookups are canonicalized so signed/unsigned 64-bit representations
//! resolve to the same entry (see CanonicalizeId).
class Table
{
public:
    //! Sorts by name and builds the lookup indices.
    explicit Table(std::vector<Entry> entries);

    Table(const Table&) = delete;
    Table& operator=(const Table&) = delete;

    //! Returns the entry whose id field matches exactly, or nullptr.
    const Entry* ById(std::string_view id) const;

    //! Returns all entries whose name matches exactly. Empty vector if none.
    std::vector<const Entry*> ByName(std::string_view name) const;

    //! All entries, sorted by name. Stable for the lifetime of this Table.
    const std::vector<Entry>& All() const { return m_Entries; }

    size_t Size() const { return m_Entries.size(); }
    bool Empty() const { return m_Entries.empty(); }

private:
    std::vector<Entry> m_Entries;
    std::unordered_map<std::string, size_t> m_ById;
    std::unordered_multimap<std::string, size_t> m_ByName;
};

} // namespace ReferenceCatalog
