#pragma once

struct IFlowgraphEditor;

//! Flowgraph Editor module.
struct IPreditorFlowgraph
{
    //! Creates the main flowgraph editor instance.
    static std::unique_ptr<IPreditorFlowgraph> CreateInstance();

    virtual ~IPreditorFlowgraph() {}

    //! Creates a flowgraph editor from an XML node.
    //! @param  xmlNode <FlowGraph> or <Graph> XML node.
    //! @returns the flowgraph editor.
    //! @{
    virtual std::shared_ptr<IFlowgraphEditor> CreateEditor(XmlNodeRef xmlNode) = 0;
    virtual std::shared_ptr<IFlowgraphEditor> CreateEditor(pugi::xml_node xmlNode) = 0;
    //! @}
};
