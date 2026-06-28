// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct SFlowNodeConfig;

// ArkFlowNodeIsEntityFriendlyToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsEntityFriendlyToEntity : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsEntityFriendlyToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsEntityFriendlyToEntity(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsEntityFriendlyToEntity* const _this, SFlowNodeConfig& config)>(0x15BC810);
};

// ArkFlowNodeIsEntityFriendlyToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsEntityFriendlyToFaction : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityFriendlyToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsEntityFriendlyToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsEntityFriendlyToFaction(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsEntityFriendlyToFaction* const _this, SFlowNodeConfig& config)>(0x15BBD90);
};

// ArkFlowNodeIsEntityHostileToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsEntityHostileToEntity : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsEntityHostileToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsEntityHostileToEntity(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsEntityHostileToEntity* const _this, SFlowNodeConfig& config)>(0x15BCF50);
};

// ArkFlowNodeIsEntityHostileToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsEntityHostileToFaction : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityHostileToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsEntityHostileToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsEntityHostileToFaction(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsEntityHostileToFaction* const _this, SFlowNodeConfig& config)>(0x15BC470);
};

// ArkFlowNodeIsEntityNeutralToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsEntityNeutralToEntity : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsEntityNeutralToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsEntityNeutralToEntity(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsEntityNeutralToEntity* const _this, SFlowNodeConfig& config)>(0x15BCBB0);
};

// ArkFlowNodeIsEntityNeutralToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsEntityNeutralToFaction : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsEntityNeutralToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsEntityNeutralToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsEntityNeutralToFaction(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsEntityNeutralToFaction* const _this, SFlowNodeConfig& config)>(0x15BC100);
};

// ArkFlowNodeIsFactionFriendlyToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsFactionFriendlyToEntity : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsFactionFriendlyToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsFactionFriendlyToEntity(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsFactionFriendlyToEntity* const _this, SFlowNodeConfig& config)>(0x15BDC40);
};

// ArkFlowNodeIsFactionFriendlyToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsFactionFriendlyToFaction : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionFriendlyToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsFactionFriendlyToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsFactionFriendlyToFaction(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsFactionFriendlyToFaction* const _this, SFlowNodeConfig& config)>(0x15BD280);
};

// ArkFlowNodeIsFactionHostileToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsFactionHostileToEntity : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsFactionHostileToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsFactionHostileToEntity(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsFactionHostileToEntity* const _this, SFlowNodeConfig& config)>(0x15BBA20);
};

// ArkFlowNodeIsFactionHostileToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsFactionHostileToFaction : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionHostileToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsFactionHostileToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsFactionHostileToFaction(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsFactionHostileToFaction* const _this, SFlowNodeConfig& config)>(0x15BD8E0);
};

// ArkFlowNodeIsFactionNeutralToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsFactionNeutralToEntity : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsFactionNeutralToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsFactionNeutralToEntity(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsFactionNeutralToEntity* const _this, SFlowNodeConfig& config)>(0x15BDFA0);
};

// ArkFlowNodeIsFactionNeutralToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeisdisposition.h
class ArkFlowNodeIsFactionNeutralToFaction : public ArkFlowNodeIsDispositionBase<ArkFlowNodeIsFactionNeutralToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeIsFactionNeutralToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeIsFactionNeutralToFaction(IFlowNode::SActivationInfo* _arg0_);
	bool OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeIsFactionNeutralToFaction* const _this, SFlowNodeConfig& config)>(0x15BD5B0);
};
#endif // MOONCRASH
