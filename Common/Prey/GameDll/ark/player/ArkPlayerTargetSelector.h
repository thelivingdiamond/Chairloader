// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkInteractionInfo.h>

class ArkSafeScriptTable;
struct IConsoleCmdArgs;
struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerTargetSelector.h
class ArkPlayerTargetSelector // Id=8017452 Size=72
{
public:
	class ArkPlayerTarget // Id=8017453 Size=112
	{
	public:
		float m_priority;
		float m_aimDistance;
		std::array<ArkInteractionInfo,4> m_interactionInfo;
		unsigned m_entityId;
		
		ArkPlayerTarget(const float _priority, const float _aimDistance, const unsigned &_entityId, std::array<ArkInteractionInfo,4> const &_interactionInfo);
		
#if 0
		float GetPriority() const;
		float GetAimDistance() const;
		const unsigned &GetEntityId() const;
		std::array<ArkInteractionInfo,4> const &GetInteractionInfo() const;
		void SetPriority(const float arg0);
		bool operator==(ArkPlayerTargetSelector::ArkPlayerTarget const &arg0) const;
#endif
	};

	using PlayerTargets = std::vector<ArkPlayerTargetSelector::ArkPlayerTarget>;
	using TargetPriorityMap = std::map<unsigned __int64,float,std::less<unsigned __int64>>;
	
	struct IntersectResult // Id=8017484 Size=8
	{
		unsigned m_entityId;
		bool m_bHitAnything;
	};

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
	std::map<unsigned __int64,float,std::less<unsigned __int64>> m_itemTypePriorityMap;
	static const float s_MaxItemScore;
	static const char *const s_pDebugDrawCommandName;
	static const char *const s_pLoadConfigCommandName;
	
	ArkPlayerTargetSelector();
	~ArkPlayerTargetSelector();
	void StartHoovering() { FStartHoovering(this); }
	void LoadConfigFile() { FLoadConfigFile(this); }
	unsigned GetInteractionTarget() const { return FGetInteractionTarget(this); }
	std::array<ArkInteractionInfo,4> const &GetInteractionInfoForTarget() const { return FGetInteractionInfoForTarget(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void UpdateHoovering(const float _frameTime) { FUpdateHoovering(this,_frameTime); }
	static void SetDrawDebugCmd(IConsoleCmdArgs *_pCmdArgs) { FSetDrawDebugCmd(_pCmdArgs); }
	void UpdateCandidates() { FUpdateCandidates(this); }
	void DrawDebug() const { FDrawDebug(this); }
	Vec3 GetInteractionPosition(IEntity const &_entity, ArkSafeScriptTable const &_propertiesTable) const { return FGetInteractionPosition(this,_entity,_propertiesTable); }
	float GetInteractionDistanceSq(ArkSafeScriptTable const &_propertiesTable) const { return FGetInteractionDistanceSq(this,_propertiesTable); }
	
#if 0
	void SetDrawDebug(const bool arg0);
	void SetIsHoovering(const bool arg0);
	bool IsHoovering() const;
	float GetInteractDistance() const;
	void SetForceSelectEntity(const unsigned arg0);
	void SetInteractDistance(const float arg0);
	bool HasLineOfSight(IEntity const &arg0, Vec3 const &arg1, Vec3 const &arg2, bool arg3, bool arg4, bool arg5) const;
	ArkPlayerTargetSelector::IntersectResult RayIntersectEntity(Vec3 const &arg0, Vec3 const &arg1, bool arg2, bool arg3) const;
#endif
	
	static inline auto FBitNotArkPlayerTargetSelector = PreyFunction<void(ArkPlayerTargetSelector *const _this)>(0x156BB30);
	static inline auto FStartHoovering = PreyFunction<void(ArkPlayerTargetSelector *const _this)>(0x156D7A0);
	static inline auto FLoadConfigFile = PreyFunction<void(ArkPlayerTargetSelector *const _this)>(0x156D250);
	static inline auto FGetInteractionTarget = PreyFunction<unsigned(ArkPlayerTargetSelector const *const _this)>(0x156D230);
	static inline auto FGetInteractionInfoForTarget = PreyFunction<std::array<ArkInteractionInfo,4> const &(ArkPlayerTargetSelector const *const _this)>(0x156CFA0);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerTargetSelector *const _this, const float _frameTime)>(0x156D7C0);
	static inline auto FUpdateHoovering = PreyFunction<void(ArkPlayerTargetSelector *const _this, const float _frameTime)>(0x156DC10);
	static inline auto FSetDrawDebugCmd = PreyFunction<void(IConsoleCmdArgs *_pCmdArgs)>(0x156D700);
	static inline auto FUpdateCandidates = PreyFunction<void(ArkPlayerTargetSelector *const _this)>(0x156D7F0);
	static inline auto FDrawDebug = PreyFunction<void(ArkPlayerTargetSelector const *const _this)>(0x156C600);
	static inline auto FGetInteractionPosition = PreyFunction<Vec3(ArkPlayerTargetSelector const *const _this, IEntity const &_entity, ArkSafeScriptTable const &_propertiesTable)>(0x156CFB0);
	static inline auto FGetInteractionDistanceSq = PreyFunction<float(ArkPlayerTargetSelector const *const _this, ArkSafeScriptTable const &_propertiesTable)>(0x156CEF0);
};

