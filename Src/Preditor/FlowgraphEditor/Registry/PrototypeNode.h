#pragma once

namespace FlowgraphEditor
{

//! Engine flow data type. Order matches TFlowSystemDataTypes
//! (SFlowSystemVoid, int, float, EntityId, Vec3, string, bool).
enum class FlowDataType : uint8_t
{
    Void = 0,
    Int,
    Float,
    EntityId,
    Vec3,
    String,
    Bool,

    Count,
};

const char* ToString(FlowDataType type);
FlowDataType FlowDataTypeFromEngine(int engineType);

//! Lowercase prefix before ':' in a flow class name (e.g. "entity:SpawnPoint" -> "entity").
//! Empty if no ':'. Casing is normalized so "Entity:Foo" and "entity:Bar" share a key.
std::string CategoryKeyFromClassName(std::string_view className);

//! UI display form of a category key — empty -> "Misc", otherwise first letter capitalized.
std::string FormatCategoryDisplay(std::string_view categoryKey);

//! Schema for one port on a prototype. Pure data — no IDs, no per-graph state.
struct PrototypePort
{
    std::string name;             //!< identifier, e.g. "entityId"
    std::string humanName;        //!< display name, e.g. "Entity ID"
    std::string description;
    FlowDataType type = FlowDataType::Void;
    std::string uiConfig;         //!< sUIConfig (input only, e.g. "enum_int:On=0,Off=1")
    std::string defaultValueText; //!< serialized default for inputs (empty when none)
};

//! Immutable schema for one node class. Owned by NodeRegistry; callers hold raw pointers.
struct PrototypeNode
{
    std::string className;        //!< engine class, e.g. "entity:SpawnPoint"
    std::string description;
    std::string categoryKey;      //!< lowercase prefix derived from className; empty if no ':'
    uint32_t engineFlags = 0;     //!< raw EHyperNodeFlags
    std::vector<PrototypePort> inputs;
    std::vector<PrototypePort> outputs;

    bool IsEntityNode() const;            //!< EHYPER_NODE_ENTITY
    bool IsHidden() const;                //!< EHYPER_NODE_HIDE_UI
    bool IsTargetingGraphEntity() const;  //!< EHYPER_NODE_GRAPH_ENTITY

    const PrototypePort* FindInput(std::string_view name) const;
    const PrototypePort* FindOutput(std::string_view name) const;
};

} // namespace FlowgraphEditor
