//
// Created by theli on 9/25/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPHEDITOR_H
#define CHAIRLOADER_FLOWGRAPHEDITOR_H

struct Node;
#include "imgui_node_editor.h"
#include "imgui_canvas.h"
#include <pugixml.hpp>
#include <Prey/CryFlowGraph/IFlowSystem.h>
namespace ed = ax::NodeEditor;


using NodeClass = std::string;

class IFlowNode;

static int uniqueID = 0;
static int GetUniqueID() {
    return uniqueID++;
}

enum class PinKind
{
    Output,
    Input
};

struct PrototypePin{
    std::string Name,
                HumanName,
                Description;
    PinKind     Kind = PinKind::Input;
    // input pins only
    std::string sUIConfig;
    // inputData struct thing

    // output pins only
    int         Type = 0;
    PrototypePin() = default;
};

struct Pin: public PrototypePin
{
    ed::PinId   ID = 0;
    ::Node*     Node = nullptr;


    // constructor from prototypePin
    Pin() = default;
    Pin(PrototypePin pin, ::Node* node)
    {
        Name = pin.Name;
        HumanName = pin.HumanName;
        Description = pin.Description;
        Kind = pin.Kind;
        sUIConfig = pin.sUIConfig;
        Type = pin.Type;
        ID = GetUniqueID();
        Node = node;
    }

};

struct PrototypeNode{
    std::string Description;
    std::vector<PrototypePin> ProtoInputs;
    std::vector<PrototypePin> ProtoOutputs;
    NodeClass Class;
};

struct Node : public PrototypeNode
{
    ed::NodeId ID;
    std::string Name;
    // white
    ImU32 Color = 0xFFFFFFFF;
    ImVec2 Pos;
    std::vector<Pin> Inputs;
    std::vector<Pin> Outputs;
    std::string State;
    std::string SavedState;
    bool PosSet = false;

    // add a constructor to intialize from a PrototypeNode
    Node( std::string name, PrototypeNode &proto, ImVec2 pos)
            : Name(name), Pos(pos) {
        ID = GetUniqueID();
        for(auto &pin : proto.ProtoInputs) {
            Pin newPin(pin, this);
            Inputs.emplace_back(newPin);
        }
        for(auto &pin : proto.ProtoOutputs) {
            Pin newPin(pin, this);
            Outputs.emplace_back(newPin);
        }
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        //TODO: initialize inputs and outputs from proto
        Class = proto.Class;
        Description = proto.Description;
    }
};

struct Edge
{
    ed::LinkId ID = 0;
    ed::NodeId nodeOut = 0,
            nodeIn = 0;
    ed::PinId pinOut = 0,
            pinIn = 0;
    ImU32 Color = 0xFFFFFFFF;
    Edge() = default;
    Edge(ed::LinkId id, ed::PinId outPin, ed::PinId inPin)
            : ID(id), pinOut(outPin), pinIn(inPin) {}
};

class FlowgraphEditor {
public:
    FlowgraphEditor();
    ~FlowgraphEditor() = default;
    void Draw(bool *bDraw);
    void Update();
private:
//    std::vector<_smart_ptr<IFlowNode>> m_FlowNodes;
    std::vector<PrototypeNode> m_PrototypeNodes;
    std::vector<Node> m_Nodes;
    std::vector<Edge> m_Edges;
    void drawNode(Node& node);
    void drawEdge(Edge& edge);
    void handleEdges();
};


#endif //CHAIRLOADER_FLOWGRAPHEDITOR_H
