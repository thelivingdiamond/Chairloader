#pragma once
#include <map>
#include "PrototypeNode.h"

namespace FlowgraphEditor
{

//! Owns every PrototypeNode for the session. Process-lifetime singleton;
//! pointers from Find/InCategory/All stay valid for the whole session.
//!
//! Get() never touches the engine — call EnsureLoaded() per-frame until it
//! returns true (gEnv->pFlowSystem isn't ready when PreditorUI constructs).
class NodeRegistry
{
public:
    using CategoryMap = std::map<std::string,
                                 std::vector<const PrototypeNode*>,
                                 std::less<>>;

    static NodeRegistry& Get();

    NodeRegistry(const NodeRegistry&) = delete;
    NodeRegistry& operator=(const NodeRegistry&) = delete;

    //! Tries to scrape prototypes from gEnv->pFlowSystem.
    //! @returns true if loaded (now or previously); false if the engine isn't
    //!          ready yet — call again later.
    bool EnsureLoaded();
    bool IsLoaded() const { return m_bLoaded; }

    const std::vector<std::unique_ptr<PrototypeNode>>& All() const { return m_All; }
    size_t Size() const { return m_All.size(); }

    //! Look up by class name (e.g. "entity:SpawnPoint"). Returns nullptr if missing.
    const PrototypeNode* Find(std::string_view className) const;

    //! All categories, alphabetically by key (case-insensitive grouping).
    //! Each entry's vector is sorted by className.
    const CategoryMap& Categories() const { return m_ByCategory; }

    //! Sorted (by className) view of prototypes in a category.
    const std::vector<const PrototypeNode*>& InCategory(std::string_view categoryKey) const;

    //! Add a prototype the engine doesn't know about (comments, placeholders, etc.).
    void AddSynthetic(std::unique_ptr<PrototypeNode> proto);

private:
    NodeRegistry() = default;

    void LoadFromEngine();
    void RebuildIndices();

    bool m_bLoaded = false;
    std::vector<std::unique_ptr<PrototypeNode>> m_All;
    std::unordered_map<std::string, PrototypeNode*> m_ByClass;
    CategoryMap m_ByCategory;
};

} // namespace FlowgraphEditor
