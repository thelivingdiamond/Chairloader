//
// Created by theli on 10/5/2022.
//

#ifndef CHAIRLOADER_FLOWGRAPH_H
#define CHAIRLOADER_FLOWGRAPH_H

#include "Node.h"
#include "Pin.h"
#include "Edge.h"


struct FlowGraph {
    //TODO: add gametokens
    fs::path path;
    std::string name;
    std::map<int64_t,Node> m_Nodes;
    std::map<int64_t,Edge> m_Edges;
    std::map<int64_t,Pin*> m_pPins;

    Node * getNode(int64_t id);
    Pin * getPin(int64_t id);
    Edge * getEdge(int64_t id);


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

    //! remove a node from the graph, will also remove all edges connected to the node
    /// \returns true if the node was removed successfully, false if the node does not exist or other error
    bool removeNode(int64_t id);

    /* edge adding and removing functions */

    //! add an edge from a pin id to a pin id
    /// \returns true if the edge was added, false if the edge already exists or the pins are invalid
    bool addEdge(int64_t startPin, int64_t endPin, int64_t id = 0);

    //! remove an edge
    /// \returns true if the edge was removed, false if the edge does not exist
    bool removeEdge(int64_t id);

    void draw();
    void drawTab();
    void update();

    void drawNode(Node& node);
    void drawEdge(Edge& edge);

    bool loadXML(fs::path path);

};


#endif //CHAIRLOADER_FLOWGRAPH_H
