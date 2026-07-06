// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkfactionflowgraphcommon.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B7EF0);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B9C00);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B67B0);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B8850);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B5510);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B4CD0);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BB3B0);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B90C0);
};

// ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		reciprocate = 3,
	};

	virtual ~ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeClearDispositionBase<ArkFlowNodeClearRelationshipFactionEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BA810);
};

// ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		makeFriendly = 3,
	};

	virtual ~ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B4140);
};

// ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		makeFriendly = 3,
	};

	virtual ~ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityEntityFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B3DE0);
};

// ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		makeFriendly = 3,
	};

	virtual ~ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B3A80);
};

// ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		makeFriendly = 3,
	};

	virtual ~ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeEndHostilityBase<ArkFlowNodeEndHostilityFactionFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B3750);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B7410);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B5CD0);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B6030);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B7BE0);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B9930);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BA540);
};

// ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BB110);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BC6E0);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BBC90);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BCE20);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BC370);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BCA80);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BC000);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BDB50);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BD1C0);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BB930);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BD820);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BDEB0);
};

// ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BD4F0);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B77B0);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B9510);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B6390);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B8430);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B5120);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B48E0);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntity>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BA110);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BAD20);
};

// ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities>
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h
class ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities> : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		disposition = 3,
		reciprocate = 4,
	};

	virtual ~ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities>();
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities>();
#endif

	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities>* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B8CD0);
};
#endif // MOONCRASH
