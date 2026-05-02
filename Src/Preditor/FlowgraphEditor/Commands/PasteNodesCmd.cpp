#include <algorithm>
#include <set>
#include "PasteNodesCmd.h"

FlowgraphEditor::PasteNodesCmd::PasteNodesCmd(std::vector<Node> nodes,
                                              std::vector<Edge> edges,
                                              const char* name)
    : m_Nodes(std::move(nodes))
    , m_Edges(std::move(edges))
    , m_Name(name)
{
}

void FlowgraphEditor::PasteNodesCmd::Redo(Flowgraph& graph)
{
    for (const Node& n : m_Nodes)
        graph.nodes.push_back(n);
    for (const Edge& e : m_Edges)
        graph.edges.push_back(e);
}

void FlowgraphEditor::PasteNodesCmd::Undo(Flowgraph& graph)
{
    std::set<int64_t> nodeIds;
    for (const Node& n : m_Nodes) nodeIds.insert(n.id);
    std::set<int64_t> edgeIds;
    for (const Edge& e : m_Edges) edgeIds.insert(e.id);

    graph.nodes.erase(
        std::remove_if(graph.nodes.begin(), graph.nodes.end(),
            [&](const Node& n) { return nodeIds.count(n.id) != 0; }),
        graph.nodes.end());
    graph.edges.erase(
        std::remove_if(graph.edges.begin(), graph.edges.end(),
            [&](const Edge& e) { return edgeIds.count(e.id) != 0; }),
        graph.edges.end());
}
