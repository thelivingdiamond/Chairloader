//
// Created by theli on 9/25/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPHEDITOR_H
#define CHAIRLOADER_FLOWGRAPHEDITOR_H

struct Node;
#include <pugixml.hpp>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <filesystem>
#include "ImGui/imgui.h"
#include "ImNodes/imnodes.h"

using NodeClass = std::string;

class IFlowNode;

static uint64_t uniqueID = 0;
static uint64_t GetUniqueID() {
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
struct Node;

struct Pin: public PrototypePin
{
    uint64_t   ID = 0;
    Node*     Parent_Node = nullptr;


    // constructor from prototypePin
    Pin() = default;
    Pin(PrototypePin pin, Node* node)
    {
        Name = pin.Name;
        HumanName = pin.HumanName;
        Description = pin.Description;
        Kind = pin.Kind;
        sUIConfig = pin.sUIConfig;
        Type = pin.Type;
        ID = GetUniqueID();
        Parent_Node = node;
    }
    // an operator that returns true if the id is not zero
    operator bool() const { return ID != 0; }
};

struct PrototypeNode{
    std::string Description;
    std::vector<PrototypePin> ProtoInputs;
    std::vector<PrototypePin> ProtoOutputs;
    NodeClass Class;
    // == operator based on Class
    bool operator==(const PrototypeNode& other) const
    {
        return Class == other.Class;
    }
    // == operator based on std::string
    bool operator==(const std::string& other) const
    {
        return Class == other;
    }
};

struct Node : public PrototypeNode
{
    uint64_t ID;
    std::string Name;
    // white
    ImU32 Color = 0xFFFFFFFF;
    ImVec2 Pos;
    std::vector<Pin> Inputs;
    std::vector<Pin> Outputs;
    std::string State;
    std::string SavedState;
    bool PosSet = false;
    float outputWidestText = 0.0f;
    float inputWidestText = 0.0f;

    Node() = default;
    // add a constructor to intialize from a PrototypeNode
    Node( std::string name, PrototypeNode &proto, ImVec2 pos)
            : Name(name), Pos(pos) {
        ID = GetUniqueID();
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        ProtoInputs = proto.ProtoInputs;
        ProtoOutputs = proto.ProtoOutputs;
        //TODO: initialize inputs and outputs from proto
        Class = proto.Class;
        Description = proto.Description;
    }

    Node( std::string name, PrototypeNode &proto, ImVec2 pos, uint64_t id)
            : Name(name), Pos(pos) {
        ID = id;
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        ProtoInputs = proto.ProtoInputs;
        ProtoOutputs = proto.ProtoOutputs;
        //TODO: initialize inputs and outputs from proto
        Class = proto.Class;
        Description = proto.Description;
    }
    //! OPERATORS
    // == operator
    bool operator==(const Node& other) const
    {
        return ID == other.ID;
    }
    // != operator
    bool operator!=(const Node& other) const
    {
        return ID != other.ID;
    }
    // < operator
    bool operator<(const Node& other) const
    {
        return  ID < other.ID;
    }
    // > operator
    bool operator>(const Node& other) const
    {
        return ID > other.ID;
    }
    // <= operator
    bool operator<=(const Node& other) const
    {
        return ID <= other.ID;
    }
    // >= operator
    bool operator>=(const Node& other) const
    {
        return ID >= other.ID;
    }
    // operator that returns true if the id is not zero
    operator bool() const { return ID != 0; }

    void initializePins(){
        Inputs.clear();
        Outputs.clear();
        for(auto &pin : ProtoInputs) {
            Pin newPin(pin, this);
            auto textSize = ImGui::CalcTextSize((newPin.Name + " ->").c_str());
            if(textSize.x > inputWidestText)
                inputWidestText = textSize.x;
            Inputs.emplace_back(newPin);
        }
        for(auto &pin : ProtoOutputs) {
            Pin newPin(pin, this);
            auto textSize = ImGui::CalcTextSize((newPin.Name + " ->").c_str());
            if(textSize.x > outputWidestText)
                outputWidestText = textSize.x;
            Outputs.emplace_back(newPin);
        }
    }
    Pin& getPin(uint64_t id){
        static Pin nullPin;
        for(auto &pin : Inputs){
            if(pin.ID == id)
                return pin;
        }
        for(auto &pin : Outputs) {
            if (pin.ID == id)
                return pin;
        }
        return nullPin;
    }
    Pin& getPin(std::string name){
        static Pin nullPin;
        for(auto &pin : Inputs){
            if(pin.Name == name)
                return pin;
        }
        for(auto &pin : Outputs){
            if(pin.Name == name)
                return pin;
        }
        return nullPin;
    }
};

struct Edge
{
    uint64_t ID = 0;
    uint64_t nodeOut = 0,
            nodeIn = 0;
    uint64_t pinOut = 0,
            pinIn = 0;
    ImU32 Color = 0xFFFFFFFF;
    Edge() = default;
    Edge( uint64_t id,  uint64_t outPin, uint64_t inPin)
            : ID(id), pinOut(outPin), pinIn(inPin) {}
};

struct FlowGraph {
    //TODO: add gametokens
    fs::path path;
    std::string name;
    std::vector<Node> m_Nodes;
    std::vector<Edge> m_Edges;
    Node& getNode(uint64_t id);
    Pin& getPin(uint64_t id);
    Edge& getEdge(uint64_t id);
    void drawFlowGraph();
    void drawFlowGraphTab();

    void drawNode(Node& node);
    void drawEdge(Edge& edge);

    void addNodeFromPrototype(PrototypeNode& proto, ImVec2 pos = {0,0});
    void addNodeFromPrototype(PrototypeNode& proto, uint64_t id, ImVec2 pos = {0,0});

    void loadXML(fs::path path);

};

class FlowgraphEditor {
public:
    FlowgraphEditor();
    ~FlowgraphEditor();
    void Draw(bool *bDraw);
    void Update();
private:
//    std::vector<_smart_ptr<IFlowNode>> m_FlowNodes;
    std::vector<PrototypeNode> m_PrototypeNodes;
    std::vector<FlowGraph> m_FlowGraphs;
    FlowGraph* p_CurrentFlowGraph = nullptr;
    void drawNode(Node& node);
    void drawEdge(Edge& edge);
    void handleEdges();


    // XML Load and save
    void loadXMLFlowgraph(fs::path path);
};


#endif //CHAIRLOADER_FLOWGRAPHEDITOR_H
