#include <Preditor/ReferenceCatalog/KindRegistry.h>

namespace ReferenceCatalog
{

namespace
{

bool StartsWith(std::string_view s, std::string_view prefix)
{
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

bool EndsWith(std::string_view s, std::string_view suffix)
{
    return s.size() >= suffix.size() &&
           s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
}

} // namespace

KindRegistry& KindRegistry::Get()
{
    static KindRegistry s_instance;
    return s_instance;
}

void KindRegistry::AddRule(Rule rule)
{
    std::lock_guard lock(m_Mutex);
    m_Rules.push_back(std::move(rule));
}

void KindRegistry::SetRules(std::vector<Rule> rules)
{
    std::lock_guard lock(m_Mutex);
    m_Rules = std::move(rules);
}

void KindRegistry::Clear()
{
    std::lock_guard lock(m_Mutex);
    m_Rules.clear();
}

std::optional<std::string> KindRegistry::Resolve(const PortQuery& q) const
{
    std::lock_guard lock(m_Mutex);
    for (const Rule& r : m_Rules)
    {
        if (!r.uiConfigPrefix.empty() && !StartsWith(q.uiConfig, r.uiConfigPrefix))
            continue;
        if (!r.portSuffix.empty() && !EndsWith(q.portName, r.portSuffix))
            continue;
        if (!r.nodeClassPrefix.empty() && !StartsWith(q.nodeClass, r.nodeClassPrefix))
            continue;
        return r.kind;
    }
    return std::nullopt;
}

} // namespace ReferenceCatalog
