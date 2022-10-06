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
    std::vector<Node> m_Nodes;
    std::vector<Edge> m_Edges;
    Node * getNode(int64_t id);
    Pin * getPin(int64_t id);
    Edge * getEdge(int64_t id);
    void draw();
    void drawTab();
    void update();

    void drawNode(Node& node);
    void drawEdge(Edge& edge);

    void addNodeFromPrototype(PrototypeNode& proto, ImVec2 pos = {0,0});
    void addNodeFromPrototype(PrototypeNode& proto, int64_t id, ImVec2 pos = {0,0});

    bool isLinked(int64_t pinID);

    bool loadXML(fs::path path);

};


#endif //CHAIRLOADER_FLOWGRAPH_H
