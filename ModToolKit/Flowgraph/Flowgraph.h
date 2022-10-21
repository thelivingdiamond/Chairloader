//
// Created by theli on 10/5/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPH_H
#define CHAIRLOADER_FLOWGRAPH_H

#pragma once

#include "Node.h"
#include "Pin.h"
#include "Edge.h"
#include <variant>
#include <pugixml.hpp>
#include "IChairFlowgraph.h"
#include <ImNodes/ImNodes.h>

struct FlowGraph : public IChairFlowgraph {
    FlowGraph();
    ~FlowGraph();
    ImNodesEditorContext* m_Context;
    //TODO: add gametokens
    fs::path m_Path;
    std::string m_Name;
    std::map<int64_t,Node> m_Nodes;
    std::map<int64_t,Edge> m_Edges;
    std::map<int64_t,Pin*> m_pPins;

    Node * getNode(int64_t id);
    Pin * getPin(int64_t id);
    Edge * getEdge(int64_t id);
    int64_t uniqueID;
    int64_t GetUniqueID() override{
        return uniqueID++;
    }

   /* node adding functions */

    //! add a node from a prototype node
    /// \returns true if the node was added successfully, false if the node already exists or other error
    bool addNode(std::string name, PrototypeNode &proto, ImVec2 pos = {0,0}, int64_t id = -1);

    //! add a node from a prototype class name
    /// \returns true if the node was added successfully, false if the node already exists or other error
    bool addNode(std::string name, PrototypeNode::NodeClass &protoClass, ImVec2 pos = {0,0}, int64_t id = -1);

    //! add a node from a prototype with default inputs (for XML loading)
    /// \returns true if the node was added successfully, false if the node already exists or other error
    bool addNode(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id, std::map<std::string, std::string> &defaultInputs);

    //! add a node from a prototype class name with default inputs (for XML loading)
    /// \returns true if the node was added successfully, false if the node already exists or other error
    bool addNode(std::string name, PrototypeNode::NodeClass &protoClass, ImVec2 pos, int64_t id, std::map<std::string, std::string> &defaultInputs);


    bool addCommentBox(std::string name, ImVec2 pos, std::string comment, int64_t id = -1);


    //! remove a node from the graph, will also remove all edges connected to the node
    /// \returns true if the node was removed successfully, false if the node does not exist or other error
    bool removeNode(int64_t id);

    /* edge adding and removing functions */

    //! add an edge from a pin id to a pin id
    /// \returns true if the edge was added, false if the edge already exists or the pins are invalid
    bool addEdge(int64_t startPin, int64_t endPin, int64_t id = -1);

    //! remove an edge
    /// \returns true if the edge was removed, false if the edge does not exist
    bool removeEdge(int64_t id);

    void draw();
    void drawTab();
    void update();
    bool m_bFirstDraw = true;

    void drawNode(Node& node);
    void drawEdge(Edge& edge);

    bool loadXML(fs::path path);

    bool m_bResetPan = false;
    ImVec2 m_ResetPos = {0, 0};
    void resetPanning(ImVec2 pos);

    void drawSelectedNodeProperties();
    void drawNodeProperties(Node& node);
    float m_nodePropertiesHeight = 0.2f;
};


#endif //CHAIRLOADER_FLOWGRAPH_H

enum class FilePlace {
    Ark,
    Level,
    Libs,
    Prefabs,
    Mod,
    Unknown,
    COUNT
};

class FlowGraphFromXML : public FlowGraph {
public:
    FlowGraphFromXML(pugi::xml_node &node, fs::path path, std::string name);
    FilePlace m_FilePlace;

    enum class FlowGraphType{
        Entity,
        FlowgraphModule,
        FlowgraphObjectList,
        GlobalAction,
        UIAction,
        PrefabObject,
        Unknown,
        COUNT
    };
    struct EntityFileInfo {
        std::string entityName;
        uint64_t entityID;
    };
    struct FlowgraphModuleFileInfo {
        std::string moduleName;
    };
    struct FlowgraphObjectListFileInfo {
        std::string objectListName;
    };
    struct GlobalActionFileInfo {
    };
    struct UIActionFileInfo {
    };
    struct PrefabObjectFileInfo {
        std::string prefabObjectName;
        uint64_t prefabObjectID;
    };
    struct UnknownFileInfo {
    };
    std::variant<EntityFileInfo, FlowgraphModuleFileInfo, FlowgraphObjectListFileInfo, GlobalActionFileInfo, UIActionFileInfo, PrefabObjectFileInfo, UnknownFileInfo> m_FileInfo;
    FlowGraphType m_FlowGraphType;
    pugi::xml_node m_RootNode;
    std::string m_FlowGraphName;

    bool loadXML(pugi::xml_node &node);

};


class FlowGraphXMLFile : public FlowGraph {
public:
    fs::path m_RelativePath;
    FilePlace m_FilePlace;

    // level files
    fs::path m_LevelName;
    fs::path m_RelativeLevelPath;

    std::vector<std::shared_ptr<FlowGraphFromXML>> m_FlowGraphs;
    pugi::xml_document m_Document; // super important document object that all the child flowgraph nodes will use
    FlowGraphXMLFile() = default;
    FlowGraphXMLFile(fs::path path);
    FilePlace parseFilePlace(fs::path path);
    bool loadFromXmlFile(fs::path path);
};