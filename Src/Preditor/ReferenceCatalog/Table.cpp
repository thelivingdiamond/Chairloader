#include <algorithm>
#include <charconv>
#include <cstdint>
#include <system_error>
#include <Preditor/ReferenceCatalog/Table.h>

namespace ReferenceCatalog
{

std::string CanonicalizeId(std::string_view id)
{
    if (id.empty())
        return std::string(id);

    // Try int64 first — handles signed values including negatives.
    int64_t s = 0;
    {
        const auto* first = id.data();
        const auto* last = first + id.size();
        auto [p, ec] = std::from_chars(first, last, s);
        if (ec == std::errc{} && p == last)
            return std::to_string(static_cast<uint64_t>(s));
    }

    // Try uint64 in case the value is too large for signed (high-bit set).
    uint64_t u = 0;
    {
        const auto* first = id.data();
        const auto* last = first + id.size();
        auto [p, ec] = std::from_chars(first, last, u);
        if (ec == std::errc{} && p == last)
            return std::to_string(u);
    }

    // Non-numeric (e.g. "WorldState.ApexIsHere", "Phantoms.BasePhantom") —
    // pass through.
    return std::string(id);
}

Table::Table(std::vector<Entry> entries)
    : m_Entries(std::move(entries))
{
    std::sort(m_Entries.begin(), m_Entries.end(),
              [](const Entry& a, const Entry& b) { return a.name < b.name; });

    m_ById.reserve(m_Entries.size());
    m_ByName.reserve(m_Entries.size());
    for (size_t i = 0; i < m_Entries.size(); ++i)
    {
        const Entry& e = m_Entries[i];
        if (!e.id.empty())
            m_ById.emplace(CanonicalizeId(e.id), i);
        if (!e.name.empty())
            m_ByName.emplace(e.name, i);
    }
}

const Entry* Table::ById(std::string_view id) const
{
    auto it = m_ById.find(CanonicalizeId(id));
    return it != m_ById.end() ? &m_Entries[it->second] : nullptr;
}

std::vector<const Entry*> Table::ByName(std::string_view name) const
{
    auto range = m_ByName.equal_range(std::string(name));
    std::vector<const Entry*> out;
    for (auto it = range.first; it != range.second; ++it)
        out.push_back(&m_Entries[it->second]);
    return out;
}

} // namespace ReferenceCatalog
