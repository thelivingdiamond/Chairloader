#pragma once
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace ReferenceCatalog
{

//! Inputs to KindRegistry::Resolve, packaged so callers don't have to
//! depend on FlowgraphEditor types. Pass empty string_views for fields you
//! don't have.
struct PortQuery
{
    std::string_view nodeClass;  //!< e.g. "Mission:GameTokenCheck"
    std::string_view portName;   //!< e.g. "gametokenid_Token"
    std::string_view uiConfig;   //!< Cry's sUIConfig string, e.g. "enum_global:Token". May be empty.
};

//! Maps a flowgraph port to a Catalog kind (or none). The first matching
//! rule wins. Rules are evaluated in registration order, so register the
//! most specific rules first.
//!
//! Thread-safe. Singleton per process.
class KindRegistry
{
public:
    struct Rule
    {
        //! Matches if uiConfig starts with this prefix. Empty = any.
        std::string uiConfigPrefix;

        //! Matches if portName ends with this suffix. Empty = any.
        std::string portSuffix;

        //! Matches if nodeClass starts with this prefix. Empty = any.
        std::string nodeClassPrefix;

        //! Resulting kind. Required.
        std::string kind;
    };

    static KindRegistry& Get();

    //! Append a rule. First-match-wins, so order matters: register specific
    //! rules before generic ones.
    void AddRule(Rule rule);

    //! Replace the entire rule set. Useful for tests and for re-bootstrapping
    //! after a hot-reload.
    void SetRules(std::vector<Rule> rules);

    //! Drop all rules.
    void Clear();

    //! Returns the matching kind, or nullopt if no rule applies.
    std::optional<std::string> Resolve(const PortQuery& q) const;

private:
    KindRegistry() = default;
    KindRegistry(const KindRegistry&) = delete;
    KindRegistry& operator=(const KindRegistry&) = delete;

    mutable std::mutex m_Mutex;
    std::vector<Rule> m_Rules;
};

} // namespace ReferenceCatalog
