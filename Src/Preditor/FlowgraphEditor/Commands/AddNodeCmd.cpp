#include <algorithm>
#include "AddNodeCmd.h"
#include "../Registry/NodeRegistry.h"

FlowgraphEditor::AddNodeCmd::AddNodeCmd(std::string className, ImVec2 pos)
    : m_ClassName(std::move(className))
    , m_Pos(pos)
{
}

void FlowgraphEditor::AddNodeCmd::Redo(Flowgraph& graph)
{
    if (!m_bAllocated)
    {
        m_Node.id = graph.AllocNodeId();
        m_Node.className = m_ClassName;
        m_Node.pos = m_Pos;
        m_Node.prototype = NodeRegistry::Get().Find(m_ClassName);

        if (m_Node.prototype)
        {
            for (const PrototypePort& portProto : m_Node.prototype->inputs)
            {
                Pin pin;
                pin.id = graph.AllocPinId();
                pin.name = portProto.name;
                pin.isInput = true;
                pin.prototype = &portProto;
                m_Node.inputs.push_back(std::move(pin));
            }
            for (const PrototypePort& portProto : m_Node.prototype->outputs)
            {
                Pin pin;
                pin.id = graph.AllocPinId();
                pin.name = portProto.name;
                pin.isInput = false;
                pin.prototype = &portProto;
                m_Node.outputs.push_back(std::move(pin));
            }
        }

        // Commentboxes need a non-zero starting size and styling defaults
        // so they render as usable rects and round-trip with valid <Inputs>.
        if (m_Node.IsCommentBox())
        {
            m_Node.commentWidth  = 240.0f;
            m_Node.commentHeight = 120.0f;
            m_Node.inputDefaults["TextSize"]      = "1";
            m_Node.inputDefaults["Color"]         = "0.4,0.6,0.9";
            m_Node.inputDefaults["DisplayFilled"] = "1";
            m_Node.inputDefaults["DisplayBox"]    = "1";
            m_Node.inputDefaults["SortPriority"]  = "0";
        }

        m_bAllocated = true;
    }

    graph.nodes.push_back(m_Node);
}

void FlowgraphEditor::AddNodeCmd::Undo(Flowgraph& graph)
{
    auto& nodes = graph.nodes;
    nodes.erase(
        std::remove_if(nodes.begin(), nodes.end(),
            [this](const Node& n) { return n.id == m_Node.id; }),
        nodes.end());
}
