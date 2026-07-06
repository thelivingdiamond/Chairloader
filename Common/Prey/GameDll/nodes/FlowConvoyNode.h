// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <_unknown/CConvoyPathIterator.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct EventPhys;
class ICrySizer;
struct IEntity;
struct IEntityAudioProxy;
struct IFlowNode;
struct SFlowNodeConfig;

// CConvoyPath
// Header:  Prey/GameDll/nodes/FlowConvoyNode.h
class CConvoyPath
{ // Size=32 (0x20)
public:
	// CConvoyPath::SConvoyPathNode
	// Header:  Prey/GameDll/nodes/FlowConvoyNode.h
	struct SConvoyPathNode
	{ // Size=20 (0x14)
		Vec3 Position;
		float Length;
		float TotalLength;
	};

	std::vector<CConvoyPath::SConvoyPathNode> m_path;
	float m_totalLength;

	Vec3 GetPointAlongPath(float dist, CConvoyPathIterator& iterator) { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPointAlongPath(this, reinterpret_cast<Vec3*>(_return_buf_), dist, iterator); }

#if 0
	CConvoyPath();
	void SetPath(const std::vector<Vec3>& _arg0_);
	float GetTotalLength() const;
#endif

	static inline auto FGetPointAlongPath = PreyFunction<Vec3*(CConvoyPath* const _this, Vec3* _return_value_, float dist, CConvoyPathIterator& iterator)>(0x18A3480);
};

// CFlowConvoyNode
// Header:  Prey/GameDll/nodes/FlowConvoyNode.h
class CFlowConvoyNode : public CFlowBaseNode<1>
{ // Size=144 (0x90)
public:
	enum class EInputs
	{
		IN_PATH = 0,
		IN_LOOPCOUNT = 1,
		IN_SPEED = 2,
		IN_DESIREDSPEED = 3,
		IN_SHIFT = 4,
		IN_SHIFTTIME = 5,
		IN_START_DISTANCE = 6,
		IN_SPLIT_COACH = 7,
		IN_XAXIS_FWD = 8,
		IN_HORN_SOUND = 9,
		IN_BREAK_SOUND = 10,
		IN_START = 11,
		IN_STOP = 12,
	};

	enum class EOutputs
	{
		OUT_ONPATHEND = 0,
		OUT_COACHINDEX = 1,
	};

	// CFlowConvoyNode::SConvoyCoach
	// Header:  Prey/GameDll/nodes/FlowConvoyNode.h
	struct SConvoyCoach
	{ // Size=72 (0x48)
		IEntity* m_pEntity;
		int m_frontWheelBase;
		int m_backWheelBase;
		float m_wheelDistance;
		float m_coachOffset;
		float m_distanceOnPath;
		IEntityAudioProxy* m_pEntitySoundsProxy;
		CConvoyPathIterator m_frontWheelIterator[2];
		CConvoyPathIterator m_backWheelIterator[2];

	#if 0
		SConvoyCoach();
	#endif
	};

	static inline auto gFlowConvoyNodes = PreyGlobal<std::vector<CFlowConvoyNode*>>(0x2D8F458);
	CConvoyPath m_path;
	float m_speed;
	float m_desiredSpeed;
	float m_ShiftTime;
	float m_MaxShiftTime;
	float m_distanceOnPath;
	int m_splitCoachIndex;
	int m_loopCount;
	int m_loopTotal;
	bool m_bFirstUpdate;
	bool m_bXAxisFwd;
	CTimeValue m_offConvoyStartTime;
	int m_coachIndex;
	float m_splitDistanceOnPath;
	float m_splitSpeed;
	bool m_processNode;
	bool m_atEndOfPath;
	std::vector<CFlowConvoyNode::SConvoyCoach> m_coaches;
	static inline auto m_playerMaxVelGround = PreyGlobal<float>(0x2D8F450);
	int m_startBreakSoundShifted;

	static int OnPhysicsPostStep_static(const EventPhys* pEvent) { return FOnPhysicsPostStep_static(pEvent); }
	CFlowConvoyNode(IFlowNode::SActivationInfo* pActInfo);
	virtual ~CFlowConvoyNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	int OnPhysicsPostStep(const EventPhys* pEvent) { return FOnPhysicsPostStep(this, pEvent); }
	void DiscoverConvoyCoaches(IEntity* pEntity) { FDiscoverConvoyCoaches(this, pEntity); }
	void InitConvoyCoaches() { FInitConvoyCoaches(this); }
	void AwakeCoaches() { FAwakeCoaches(this); }
	int GetCoachIndexPlayerIsOn2() { return FGetCoachIndexPlayerIsOn2(this); }
	void SetPlayerMaxVelGround(float vel) { FSetPlayerMaxVelGround(this, vel); }
	void Update(IFlowNode::SActivationInfo* pActInfo) { FUpdate(this, pActInfo); }

#if 0
	static bool PlayerIsOnaConvoy();
	int GetCoachIndexPlayerIsOn();
	float GetPlayerMaxVelGround();
	void UpdateLineSounds();
	void StartSounds();
	void SplitLineSound();
	void ConvoyStopSounds();
	void StopAllSounds();
	float GetSpeedSoundParam(int _arg0_);
	void SetSoundParams();
	void StartBreakSoundShifted();
#endif

	static inline auto FOnPhysicsPostStep_static = PreyFunction<int(const EventPhys* pEvent)>(0x18A4060);
	static inline auto FCFlowConvoyNodeOv1 = PreyFunction<void(CFlowConvoyNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18A1DF0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowConvoyNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A2150);
	static inline auto FSerialize = PreyFunction<void(CFlowConvoyNode* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x18A4730);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowConvoyNode* const _this, SFlowNodeConfig& config)>(0x18A2810);
	static inline auto FProcessEvent = PreyFunction<void(CFlowConvoyNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18A40B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowConvoyNode* const _this, ICrySizer* s)>(0x18A3460);
	static inline auto FOnPhysicsPostStep = PreyFunction<int(CFlowConvoyNode* const _this, const EventPhys* pEvent)>(0x18A37E0);
	static inline auto FDiscoverConvoyCoaches = PreyFunction<void(CFlowConvoyNode* const _this, IEntity* pEntity)>(0x18A21A0);
	static inline auto FInitConvoyCoaches = PreyFunction<void(CFlowConvoyNode* const _this)>(0x18A35F0);
	static inline auto FAwakeCoaches = PreyFunction<void(CFlowConvoyNode* const _this)>(0x18A2090);
	static inline auto FGetCoachIndexPlayerIsOn2 = PreyFunction<int(CFlowConvoyNode* const _this)>(0x18A2430);
	static inline auto FSetPlayerMaxVelGround = PreyFunction<void(CFlowConvoyNode* const _this, float vel)>(0x18A48D0);
	static inline auto FUpdate = PreyFunction<void(CFlowConvoyNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18A49E0);
};
#endif // MOONCRASH
