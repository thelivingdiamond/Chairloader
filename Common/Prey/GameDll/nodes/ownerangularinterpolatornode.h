// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ark/ArkOverlappingGooHandler.h>
#include <Prey/GameDll/ark/weapons/IArkOverlappingGooListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowNode_RotateSpeed
// Header:  Prey/GameDll/nodes/ownerangularinterpolatornode.h
class CFlowNode_RotateSpeed : public CFlowBaseNode<1>
{ // Size=80 (0x50)
public:
	enum EInputPorts
	{
		EIP_Destination = 0,
		EIP_Speed = 1,
		EIP_Start = 2,
		EIP_Stop = 3,
		EIP_Reset = 4,
	};

	enum EOutputPorts
	{
		EOP_Start = 0,
		EOP_Stop = 1,
		EOP_Finish = 2,
		EOP_SpeedChanged = 3,
	};

	enum EFlags
	{
		EF_FIRSTSTART = 1,
		EF_RUNNING = 2,
	};

	uint8_t m_flags;
	float m_speed;
	float m_interpolate;
	Quat m_iniRot;
	Quat m_rot;
	Quat m_dest;

	virtual ~CFlowNode_RotateSpeed();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void GetNewDestination(IFlowNode::SActivationInfo* pActInfo) { FGetNewDestination(this, pActInfo); }
	void GetNewSpeed(IFlowNode::SActivationInfo* pActInfo) { FGetNewSpeed(this, pActInfo); }

#if 0
	CFlowNode_RotateSpeed(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_RotateSpeed* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B3A90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_RotateSpeed* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FSerialize = PreyFunction<void(CFlowNode_RotateSpeed* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B1AA0);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_RotateSpeed* const _this, SFlowNodeConfig& config)>(0x18B1BE0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_RotateSpeed* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B21E0);
	static inline auto FGetNewDestination = PreyFunction<void(CFlowNode_RotateSpeed* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B4100);
	static inline auto FGetNewSpeed = PreyFunction<void(CFlowNode_RotateSpeed* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B4290);
};

// CRotateEntityToExNode
// Header:  Prey/GameDll/nodes/ownerangularinterpolatornode.h
class CRotateEntityToExNode : public CFlowBaseNode<1>
{ // Size=128 (0x80)
public:
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

	enum class EInPorts
	{
		IN_DEST = 0,
		IN_DYN_DEST = 1,
		IN_VALUETYPE = 2,
		IN_VALUE = 3,
		IN_COORDSYS = 4,
		IN_START = 5,
		IN_STOP = 6,
	};

	enum class EOutPorts
	{
		OUT_CURRENT = 0,
		OUT_CURRENT_RAD = 1,
		OUT_START = 2,
		OUT_STOP = 3,
		OUT_FINISH = 4,
		OUT_DONE = 5,
	};

	// CRotateEntityToExNode::CArkOverlappingGooListener
	// Header:  Prey/GameDll/nodes/ownerangularinterpolatornode.h
	class CArkOverlappingGooListener : public IArkOverlappingGooListener
	{ // Size=8 (0x8)
	public:
		virtual void OnGooStatusChanged(bool _bHasGoo);

	#if 0
		CArkOverlappingGooListener();
	#endif

		static inline auto FOnGooStatusChanged = PreyFunction<void(CRotateEntityToExNode::CArkOverlappingGooListener* const _this, bool _bHasGoo)>(0x1333E90);
	};

	CTimeValue m_startTime;
	CTimeValue m_endTime;
	CTimeValue m_localStartTime;
	Quat m_targetQuat;
	Quat m_sourceQuat;
	CRotateEntityToExNode::ECoordSys m_coorSys;
	CRotateEntityToExNode::EValueType m_valueType;
	bool m_bIsMoving;
	ArkOverlappingGooHandler m_gooHandler;
	CRotateEntityToExNode::CArkOverlappingGooListener m_gooListener;

	CRotateEntityToExNode(IFlowNode::SActivationInfo* pActInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	void DegToQuat(const Vec3& rotation, Quat& destQuat) { FDegToQuat(this, rotation, destQuat); }
	void SetRawEntityRot(IEntity* pEntity, const Quat& quat) { FSetRawEntityRot(this, pEntity, quat); }
	void UpdateCurrentRotOutputs(IFlowNode::SActivationInfo* pActInfo, const Quat& quat) { FUpdateCurrentRotOutputs(this, pActInfo, quat); }
	void PhysicStop(IEntity* pEntity, const Quat* forcedOrientation) { FPhysicStop(this, pEntity, forcedOrientation); }
	void PhysicSetApropiateSpeed(IEntity* pEntity) { FPhysicSetApropiateSpeed(this, pEntity); }
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	void Start(IFlowNode::SActivationInfo* pActInfo, bool triggerStartOutput) { FStart(this, pActInfo, triggerStartOutput); }
	void ReadSourceAndTargetQuats(IFlowNode::SActivationInfo* pActInfo) { FReadSourceAndTargetQuats(this, pActInfo); }
	void CalcEndTime(IFlowNode::SActivationInfo* pActInfo) { FCalcEndTime(this, pActInfo); }
	virtual void GetMemoryUsage(ICrySizer* s) const;

	static inline auto FCRotateEntityToExNodeOv2 = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B3B60);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CRotateEntityToExNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B3B10);
	static inline auto FSerialize = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B2860);
	static inline auto FGetConfiguration = PreyFunction<void(CRotateEntityToExNode* const _this, SFlowNodeConfig& config)>(0x18B2A60);
	static inline auto FDegToQuat = PreyFunction<void(CRotateEntityToExNode* const _this, const Vec3& rotation, Quat& destQuat)>(0x18B3F10);
	static inline auto FSetRawEntityRot = PreyFunction<void(CRotateEntityToExNode* const _this, IEntity* pEntity, const Quat& quat)>(0x18B5190);
	static inline auto FUpdateCurrentRotOutputs = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::SActivationInfo* pActInfo, const Quat& quat)>(0x18B5660);
	static inline auto FPhysicStop = PreyFunction<void(CRotateEntityToExNode* const _this, IEntity* pEntity, const Quat* forcedOrientation)>(0x18B4D60);
	static inline auto FPhysicSetApropiateSpeed = PreyFunction<void(CRotateEntityToExNode* const _this, IEntity* pEntity)>(0x18B49F0);
	static inline auto FProcessEvent = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B3290);
	static inline auto FStart = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::SActivationInfo* pActInfo, bool triggerStartOutput)>(0x18B55C0);
	static inline auto FReadSourceAndTargetQuats = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B4EA0);
	static inline auto FCalcEndTime = PreyFunction<void(CRotateEntityToExNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B3BE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CRotateEntityToExNode* const _this, ICrySizer* s)>(0x4A5BF0);
};

// CRotateEntityTo_Node
// Header:  Prey/GameDll/nodes/ownerangularinterpolatornode.h
class CRotateEntityTo_Node : public CFlowBaseNode<1>
{ // Size=80 (0x50)
public:
	enum class EInPorts
	{
		IN_DEST = 0,
		IN_DYN_DEST = 1,
		IN_DURATION = 2,
		IN_START = 3,
		IN_STOP = 4,
	};

	enum class EOutPorts
	{
		OUT_CURRENT = 0,
		OUT_CURRENT_RAD = 1,
		OUT_DONE = 2,
	};

	CTimeValue m_startTime;
	CTimeValue m_endTime;
	Quat m_targetQuat;
	Quat m_sourceQuat;
	Vec3 m_rotVel;

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	void DegToQuat(const Vec3& rotation, Quat& destQuat) { FDegToQuat(this, rotation, destQuat); }
	void Interpol(const float fTime, IFlowNode::SActivationInfo* pActInfo) { FInterpol(this, fTime, pActInfo); }
	void SnapToTarget(IFlowNode::SActivationInfo* pActInfo) { FSnapToTarget(this, pActInfo); }
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CRotateEntityTo_Node(IFlowNode::SActivationInfo* _arg0_);
	void StopInterpol(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CRotateEntityTo_Node* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B3A20);
	static inline auto FSerialize = PreyFunction<void(CRotateEntityTo_Node* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B0C80);
	static inline auto FGetConfiguration = PreyFunction<void(CRotateEntityTo_Node* const _this, SFlowNodeConfig& config)>(0x18B0D90);
	static inline auto FDegToQuat = PreyFunction<void(CRotateEntityTo_Node* const _this, const Vec3& rotation, Quat& destQuat)>(0x18B3F10);
	static inline auto FInterpol = PreyFunction<void(CRotateEntityTo_Node* const _this, const float fTime, IFlowNode::SActivationInfo* pActInfo)>(0x18B4560);
	static inline auto FSnapToTarget = PreyFunction<void(CRotateEntityTo_Node* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18B53D0);
	static inline auto FProcessEvent = PreyFunction<void(CRotateEntityTo_Node* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B1370);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CRotateEntityTo_Node* const _this, ICrySizer* s)>(0x4B5230);
};
#endif // MOONCRASH
