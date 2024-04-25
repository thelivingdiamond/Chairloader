#pragma once
#include "UniqueID.h"

enum class PinKind
{
    Output,
    Input
};
struct PrototypePin
{
    std::string Name, HumanName, Description;
    PinKind Kind = PinKind::Input;
    // input pins only
    std::string sUIConfig;
    // inputData struct thing
    // output pins only
    int Type = 0;
    PrototypePin() = default;
};
struct Node;
struct Pin : public PrototypePin
{
    int64_t ID = 0;
    Node* Parent_Node = nullptr;
    std::string value;
    int numberOfConnections = 0;
    // constructor from prototypePin
    Pin() = default;
    Pin(PrototypePin pin, Node* node, int64_t id)
    {
        Name = pin.Name;
        HumanName = pin.HumanName;
        Description = pin.Description;
        Kind = pin.Kind;
        sUIConfig = pin.sUIConfig;
        Type = pin.Type;
        ID = id;
        Parent_Node = node;
    }
    // an operator that returns true if the id is not zero
    operator bool() const { return ID != 0; }
    bool isLinked() const { return numberOfConnections > 0; }
    void addLink() { numberOfConnections++; }
    void removeLink() { numberOfConnections--; }
};