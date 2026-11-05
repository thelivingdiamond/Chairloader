// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/ArkFlowNodeDissipateNightmare.h
class ArkFlowNodeDissipateNightmare : public CFlowBaseNode<eNCT_Singleton> // Id=80190D3 Size=16
{
public:
	enum class EInputPortIndex
	{
		dissipate = 0,
	};

	enum class EOutputPortIndex
#ifdef MOONCRASH
		out = 0,
#endif
	{
#ifndef MOONCRASH
		success = 0,
		failure = 1,
		out = 2,
#endif
	};

	virtual ~ArkFlowNodeDissipateNightmare();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *, XmlNodeRef const &, bool );
	virtual void Serialize(IFlowNode::SActivationInfo *, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *);
	
#ifndef MOONCRASH
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, SFlowNodeConfig &config)>(0x11689F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *_pActInfo)>(0x1168C50);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeDissipateNightmare const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::SActivationInfo *, XmlNodeRef const &, bool )>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::SActivationInfo *, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::SActivationInfo *)>(0xA13080);
#else
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDissipateNightmare* const _this, SFlowNodeConfig& config)>(0x11DE5C0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDissipateNightmare* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x11DE7D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeDissipateNightmare* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeDissipateNightmare* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeDissipateNightmare* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeDissipateNightmare* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
#endif
};
