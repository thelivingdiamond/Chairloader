#include <algorithm>
#include <Preditor/ReferenceCatalog/Catalog.h>

namespace ReferenceCatalog
{

Catalog& Catalog::Get()
{
    static Catalog s_instance;
    return s_instance;
}

void Catalog::RegisterProvider(std::string kind, std::unique_ptr<IProvider> provider)
{
    std::lock_guard lock(m_Mutex);
    auto& slot = m_Slots[std::move(kind)];
    if (!slot)
        slot = std::make_unique<Slot>();
    slot->provider = std::move(provider);
    slot->table.reset();
}

std::shared_ptr<const Table> Catalog::TryGet(std::string_view kind)
{
    std::lock_guard lock(m_Mutex);
    Slot* s = FindSlot(kind);
    if (!s || !s->provider)
        return nullptr;
    if (!s->table)
        s->table = std::make_shared<const Table>(s->provider->Load());
    return s->table;
}

void Catalog::Refresh(std::string_view kind)
{
    std::lock_guard lock(m_Mutex);
    Slot* s = FindSlot(kind);
    if (!s || !s->provider)
        return;
    s->table = std::make_shared<const Table>(s->provider->Load());
}

std::vector<std::string> Catalog::Kinds() const
{
    std::lock_guard lock(m_Mutex);
    std::vector<std::string> out;
    out.reserve(m_Slots.size());
    for (const auto& [k, _] : m_Slots)
        out.push_back(k);
    std::sort(out.begin(), out.end());
    return out;
}

std::string Catalog::DescriptionOf(std::string_view kind) const
{
    std::lock_guard lock(m_Mutex);
    const Slot* s = FindSlot(kind);
    return (s && s->provider) ? s->provider->Description() : std::string{};
}

Catalog::Slot* Catalog::FindSlot(std::string_view kind)
{
    auto it = m_Slots.find(std::string(kind));
    return it != m_Slots.end() ? it->second.get() : nullptr;
}

const Catalog::Slot* Catalog::FindSlot(std::string_view kind) const
{
    auto it = m_Slots.find(std::string(kind));
    return it != m_Slots.end() ? it->second.get() : nullptr;
}

} // namespace ReferenceCatalog
