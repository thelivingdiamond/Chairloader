// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkInteractionInfo.h>

class ArkSafeScriptTable;
struct IConsoleCmdArgs;
struct IEntity;

// ArkPlayerTargetSelector
// Header:  Prey/GameDll/ark/player/ArkPlayerTargetSelector.h
class ArkPlayerTargetSelector
{ // Size=72 (0x48)
public:
	// ArkPlayerTargetSelector::ArkPlayerTarget
	// Header:  Prey/GameDll/ark/player/ArkPlayerTargetSelector.h
	class ArkPlayerTarget
	{ // Size=112 (0x70)
	public:
		float m_priority;
		float m_aimDistance;
		std::array<ArkInteractionInfo,4> m_interactionInfo;
		unsigned m_entityId;

		ArkPlayerTarget(const float _priority, const float _aimDistance, const unsigned& _entityId, const std::array<ArkInteractionInfo,4>& _interactionInfo);

	#if 0
		float GetPriority() const;
		float GetAimDistance() const;
		const unsigned& GetEntityId() const;
		const std::array<ArkInteractionInfo,4>& GetInteractionInfo() const;
		void SetPriority(const float _arg0_);
		bool operator==(const ArkPlayerTargetSelector::ArkPlayerTarget& _arg0_) const;
	#endif

		static inline auto FArkPlayerTargetOv2 = PreyFunction<void(ArkPlayerTargetSelector::ArkPlayerTarget* const _this, const float _priority, const float _aimDistance, const unsigned& _entityId, const std::array<ArkInteractionInfo,4>& _interactionInfo)>(0x156B7C0);
	};

	// ArkPlayerTargetSelector::IntersectResult
	// Header:  Prey/GameDll/ark/player/ArkPlayerTargetSelector.h
	struct IntersectResult
	{ // Size=8 (0x8)
		unsigned m_entityId;
		bool m_bHitAnything;

	#if 0
		IntersectResult();
	#endif
	};

	using PlayerTargets = std::vector<ArkPlayerTargetSelector::ArkPlayerTarget>;
	using TargetPriorityMap = std::map<uint64_t, float>;

	bool m_bDrawDebug;
	bool m_bIsHoovering;
	float m_innerAimDistance;
	float m_outerAimDistance;
	float m_interactDistance;
	float m_pickupTimerSec;
	float m_pickupMaxCooldownSec;
	float m_pickupInitialCooldownSec;
	unsigned m_forceSelectEntity;
	std::vector<ArkPlayerTargetSelector::ArkPlayerTarget> m_candidateTargets;
	std::map<uint64_t, float> m_itemTypePriorityMap;
	static inline auto s_MaxItemScore = PreyGlobal<const float>(0x1E48B30);
	static inline auto s_pDebugDrawCommandName = PreyGlobal<const char* const>(0x1E48B38);
	static inline auto s_pLoadConfigCommandName = PreyGlobal<const char* const>(0x0);

	ArkPlayerTargetSelector();
	~ArkPlayerTargetSelector();
	void StartHoovering() { FStartHoovering(this); }
	void LoadConfigFile() { FLoadConfigFile(this); }
	unsigned GetInteractionTarget() const { return FGetInteractionTarget(this); }
	const std::array<ArkInteractionInfo,4>& GetInteractionInfoForTarget() const { return FGetInteractionInfoForTarget(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void UpdateHoovering(const float _frameTime) { FUpdateHoovering(this, _frameTime); }
	static void SetDrawDebugCmd(IConsoleCmdArgs* _pCmdArgs) { FSetDrawDebugCmd(_pCmdArgs); }
	void UpdateCandidates() { FUpdateCandidates(this); }
	void DrawDebug() const { FDrawDebug(this); }
	Vec3 GetInteractionPosition(const IEntity& _entity, const ArkSafeScriptTable& _propertiesTable) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetInteractionPosition(this, reinterpret_cast<Vec3*>(_return_buf_), _entity, _propertiesTable); }
	float GetInteractionDistanceSq(const ArkSafeScriptTable& _propertiesTable) const { return FGetInteractionDistanceSq(this, _propertiesTable); }

#if 0
	void SetDrawDebug(const bool _arg0_);
	void SetIsHoovering(const bool _arg0_);
	bool IsHoovering() const;
	float GetInteractDistance() const;
	void SetForceSelectEntity(const unsigned _arg0_);
	void SetInteractDistance(const float _arg0_);
	bool HasLineOfSight(const IEntity& _arg0_, const Vec3& _arg1_, const Vec3& _arg2_, bool _arg3_, bool _arg4_, bool _arg5_) const;
	ArkPlayerTargetSelector::IntersectResult RayIntersectEntity(const Vec3& _arg0_, const Vec3& _arg1_, bool _arg2_, bool _arg3_) const;
#endif

	static inline auto FArkPlayerTargetSelectorOv1 = PreyFunction<void(ArkPlayerTargetSelector* const _this)>(0x156B840);
	static inline auto FBitNotArkPlayerTargetSelector = PreyFunction<void(ArkPlayerTargetSelector* const _this)>(0x156BB30);
	static inline auto FStartHoovering = PreyFunction<void(ArkPlayerTargetSelector* const _this)>(0x156D7A0);
	static inline auto FLoadConfigFile = PreyFunction<void(ArkPlayerTargetSelector* const _this)>(0x156D250);
	static inline auto FGetInteractionTarget = PreyFunction<unsigned(const ArkPlayerTargetSelector* const _this)>(0x156D230);
	static inline auto FGetInteractionInfoForTarget = PreyFunction<const std::array<ArkInteractionInfo,4>& (const ArkPlayerTargetSelector* const _this)>(0x156CFA0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerTargetSelector* const _this, const float _frameTime)>(0x156D7C0);
	static inline auto FUpdateHoovering = PreyFunction<void(ArkPlayerTargetSelector* const _this, const float _frameTime)>(0x156DC10);
	static inline auto FSetDrawDebugCmd = PreyFunction<void(IConsoleCmdArgs* _pCmdArgs)>(0x156D700);
	static inline auto FUpdateCandidates = PreyFunction<void(ArkPlayerTargetSelector* const _this)>(0x156D7F0);
	static inline auto FDrawDebug = PreyFunction<void(const ArkPlayerTargetSelector* const _this)>(0x156C600);
	static inline auto FGetInteractionPosition = PreyFunction<Vec3*(const ArkPlayerTargetSelector* const _this, Vec3* _return_value_, const IEntity& _entity, const ArkSafeScriptTable& _propertiesTable)>(0x156CFB0);
	static inline auto FGetInteractionDistanceSq = PreyFunction<float(const ArkPlayerTargetSelector* const _this, const ArkSafeScriptTable& _propertiesTable)>(0x156CEF0);
};

