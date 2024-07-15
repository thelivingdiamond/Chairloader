#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryAction/flowsystem/flowsystem.h>

struct PrototypeNode;

using PrototypeNodeClass = std::string;
using PrototypeNodeMap = std::map<PrototypeNodeClass, std::shared_ptr<PrototypeNode>>;
