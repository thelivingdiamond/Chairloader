#pragma once
#include <Preditor/FGE/IPreditorFlowgraph.h>

struct PrototypePin;

namespace FGE
{

//! Main class for the Flowgraph Editor.
class PreditorFlowgraph : public IPreditorFlowgraph
{
public:
    PreditorFlowgraph();
    ~PreditorFlowgraph();

    //! @returns the map of prototype nodes.
    const PrototypeNodeMap& GetPrototypes() { return m_PrototypeNodes; }

    //! Adds a prototype node for an unknown node (that doesn't exist in the game code).
    std::shared_ptr<PrototypeNode> AddUnknownPrototype(const PrototypeNodeClass& nodeClass);

    //! Adds a pin to a prototype.
    void AddPinToPrototype(const PrototypeNodeClass& nodeClass, const PrototypePin& pin);

    //! Initializes the stuff shared between flowgraph editors.
    void InitForEditor();

private:
    bool m_IsInitialized = false;
    PrototypeNodeMap m_PrototypeNodes;

    //! Loads prototypes from the game.
    void LoadPrototypes();
};

} // namespace FGE
