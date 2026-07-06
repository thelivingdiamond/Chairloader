// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkOverlappingGooHandler.h>
#include <Prey/GameDll/ark/weapons/IArkOverlappingGooListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CMoveEntityTo
// Header:  Prey/GameDll/nodes/ownerlinearinterpolatornode.h
class CMoveEntityTo : public CFlowBaseNode<1>
{ // Size=128 (0x80)
public:
	enum class EInPorts
	{
		IN_DEST = 0,
		IN_DYN_DEST = 1,
		IN_VALUETYPE = 2,
		IN_VALUE = 3,
		IN_EASEIN = 4,
		IN_EASEOUT = 5,
		IN_COORDSYS = 6,
		IN_START = 7,
		IN_STOP = 8,
	};

	enum class EValueType
	{
		VT_SPEED = 0,
		VT_TIME = 1,
	};

	enum class ECoordSys
	{
		CS_PARENT = 0,
		CS_WORLD = 1,
		CS_LOCAL = 2,
	};

	enum class EOutPorts
	{
		OUT_CURRENT = 0,
		OUT_START = 1,
		OUT_STOP = 2,
		OUT_FINISH = 3,
		OUT_DONE = 4,
	};

	// CMoveEntityTo::CArkOverlappingGooListener
	// Header:  Prey/GameDll/nodes/ownerlinearinterpolatornode.h
	class CArkOverlappingGooListener : public IArkOverlappingGooListener
	{ // Size=8 (0x8)
	public:
		virtual void OnGooStatusChanged(bool _bHasGoo);

	#if 0
		CArkOverlappingGooListener();
	#endif

		static inline auto FOnGooStatusChanged = PreyFunction<void(CMoveEntityTo::CArkOverlappingGooListener* const _this, bool _bHasGoo)>(0x1333E90);
	};

	Vec3 m_position;
	Vec3 m_destination;
	Vec3 m_startPos;
	float m_lastFrameTime;
	float m_topSpeed;
	float m_easeOutDistance;
	float m_easeInDistance;
	float m_startTime;
	CMoveEntityTo::ECoordSys m_coorSys;
	CMoveEntityTo::EValueType m_valueType;
	bool m_bActive;
	bool m_stopping;
	bool m_bForceFinishAsTooNear;
	static inline auto EASE_MARGIN_FACTOR = PreyGlobal<const float>(0x1FE4DDC);
	ArkOverlappingGooHandler m_gooHandler;
	CMoveEntityTo::CArkOverlappingGooListener m_gooListener;

	CMoveEntityTo(IFlowNode::SActivationInfo* pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void SetPos(IFlowNode::SActivationInfo* pActInfo, const Vec3& vPos) { FSetPos(this, pActInfo, vPos); }
	void ReadDestinationPosFromInput(IFlowNode::SActivationInfo* pActInfo) { FReadDestinationPosFromInput(this, pActInfo); }
	void ReadSpeedFromInput(IFlowNode::SActivationInfo* pActInfo) { FReadSpeedFromInput(this, pActInfo); }
	void CalcSpeedFromTimeInput(IFlowNode::SActivationInfo* pActInfo) { FCalcSpeedFromTimeInput(this, pActInfo); }
	void Start(IFlowNode::SActivationInfo* pActInfo) { FStart(this, pActInfo); }
	virtual void GetMemoryUsage(ICrySizer* s) const;

	static inline auto FCMoveEntityToOv2 = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B6C30);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CMoveEntityTo* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B5740);
	static inline auto FSerialize = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B5790);
	static inline auto FGetConfiguration = PreyFunction<void(CMoveEntityTo* const _this, SFlowNodeConfig& config)>(0x18B5A20);
	static inline auto FProcessEvent = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B63F0);
	static inline auto FSetPos = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo, const Vec3& vPos)>(0x18B7010);
	static inline auto FReadDestinationPosFromInput = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B6E10);
	static inline auto FReadSpeedFromInput = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B6F80);
	static inline auto FCalcSpeedFromTimeInput = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B6CA0);
	static inline auto FStart = PreyFunction<void(CMoveEntityTo* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B7140);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CMoveEntityTo* const _this, ICrySizer* s)>(0x4A5BF0);
};
#endif // MOONCRASH
