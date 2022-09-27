//
// Created by theli on 9/25/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPHEDITOR_H
#define CHAIRLOADER_FLOWGRAPHEDITOR_H

struct Node;
#include "imgui_node_editor.h"
#include "imgui_canvas.h"
#include <pugixml.hpp>
namespace ed = ax::NodeEditor;

using NodeClass = std::string;

enum class PinKind
{
    Output,
    Input
};

struct Pin
{
    ed::PinId   ID;
    ::Node*     Node;
    std::string Name;
//    PinType     Type;
    PinKind     Kind;

//    Pin(int id, const char* name, PinKind kind):
//            ID(id), Node(nullptr), Name(name), Kind(kind)
//    {
//    }
};

struct Node
{
    ed::NodeId ID;
    std::string Name;
    std::vector<Pin> Inputs;
    std::vector<Pin> Outputs;
    ImU32 Color = 0;
    NodeClass Class;
    ImVec2 Size;
    ImVec2 Pos;

    std::string State;
    std::string SavedState;

    Node(int id, const char* name, ImColor color = ImColor(255, 255, 255)):
            ID(id), Name(name), Color(color), Class(""), Size(0, 0)
    {
    }
    Node(pugi::xml_node node){
        // TODO: parse xml node
    }
};

struct Edge
{
    ed::LinkId ID;
    ed::NodeId nodeOut,
            nodeIn;
    ed::PinId pinOut,
            pinIn;
    ImU32 Color;
};

class FlowgraphEditor {
public:
    FlowgraphEditor();
    ~FlowgraphEditor() = default;
    void Draw(bool *bDraw);
    void Update();
};


#endif //CHAIRLOADER_FLOWGRAPHEDITOR_H
