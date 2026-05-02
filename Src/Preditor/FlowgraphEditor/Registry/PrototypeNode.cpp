#include <algorithm>
#include <array>
#include <cctype>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include "PrototypeNode.h"

namespace FlowgraphEditor
{

namespace
{

const std::array<const char*, (size_t)FlowDataType::Count> kFlowDataTypeNames = {
    "Void", "Int", "Float", "EntityId", "Vec3", "String", "Bool",
};

} // anonymous namespace

const char* ToString(FlowDataType type)
{
    auto idx = (size_t)type;
    return idx < kFlowDataTypeNames.size() ? kFlowDataTypeNames[idx] : "?";
}

FlowDataType FlowDataTypeFromEngine(int engineType)
{
    if (engineType < 0 || engineType >= (int)FlowDataType::Count)
        return FlowDataType::Void;
    return (FlowDataType)engineType;
}

std::string CategoryKeyFromClassName(std::string_view className)
{
    auto colon = className.find(':');
    if (colon == std::string_view::npos)
        return {};

    std::string key(className.substr(0, colon));
    std::transform(key.begin(), key.end(), key.begin(),
                   [](unsigned char c) { return (char)std::tolower(c); });
    return key;
}

std::string FormatCategoryDisplay(std::string_view categoryKey)
{
    if (categoryKey.empty())
        return "Misc";

    std::string out(categoryKey);
    out[0] = (char)std::toupper((unsigned char)out[0]);
    return out;
}

bool PrototypeNode::IsEntityNode() const
{
    return (engineFlags & EHYPER_NODE_ENTITY) != 0;
}

bool PrototypeNode::IsHidden() const
{
    return (engineFlags & EHYPER_NODE_HIDE_UI) != 0;
}

bool PrototypeNode::IsTargetingGraphEntity() const
{
    return (engineFlags & EHYPER_NODE_GRAPH_ENTITY) != 0;
}

const PrototypePort* PrototypeNode::FindInput(std::string_view name) const
{
    for (const auto& port : inputs)
        if (port.name == name)
            return &port;
    return nullptr;
}

const PrototypePort* PrototypeNode::FindOutput(std::string_view name) const
{
    for (const auto& port : outputs)
        if (port.name == name)
            return &port;
    return nullptr;
}

} // namespace FlowgraphEditor
