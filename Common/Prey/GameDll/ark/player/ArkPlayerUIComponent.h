// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct IEntity;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;
class XmlNodeRef;

// ArkPlayerUIComponent
// Header:  Prey/GameDll/ark/player/ArkPlayerUIComponent.h
class ArkPlayerUIComponent : public ArkUIMenuBase<ArkPlayerUIComponent>
{ // Size=136 (0x88)
public:
	enum class EArkAwarenessUpdateType
	{
		none = 0,
		visible = 1,
		fadeOut = 2,
		fullAwareness = 3,
	};

	// ArkPlayerUIComponent::MarkerEntry
	// Header:  Prey/GameDll/ark/player/ArkPlayerUIComponent.h
	class MarkerEntry
	{ // Size=20 (0x14)
	public:
		unsigned m_entity;
		EArkAttentionLevel m_awarenessLevel;
		ArkPlayerUIComponent::EArkAwarenessUpdateType m_awarenessUpdateType;
		bool m_bAwarenessAnimating;
		bool m_bShowingMarkerEntry;
		bool m_bIsNewlyMarked;
		bool m_bIsMarked;
		bool m_bMarkedHostile;

	#if 0
		MarkerEntry();
		MarkerEntry(const unsigned _arg0_, const EArkAttentionLevel _arg1_);
		MarkerEntry(const unsigned _arg0_, const bool _arg1_, const bool _arg2_);
		bool operator==(const unsigned _arg0_) const;
		bool IsValid() const;
	#endif
	};

	// ArkPlayerUIComponent::DamageIndicator
	// Header:  Prey/GameDll/ark/player/ArkPlayerUIComponent.h
	class DamageIndicator
	{ // Size=12 (0xC)
	public:
		int m_id;
		unsigned m_sourceEntity;
		float m_time;

	#if 0
		DamageIndicator();
		bool operator==(int _arg0_) const;
	#endif
	};

	std::vector<ArkPlayerUIComponent::MarkerEntry> m_markerEntries;
	string m_attachmentName;
	float m_markedFullAlphaDistance;
	float m_markedZeroAlphaDistance;
	float m_markedMaxAngleCosForLabel;
	float m_awarenessFullAlphaDistance;
	float m_awarenessZeroAlphaDistance;
	float m_awarenessFullScaleDistance;
	float m_awarenessMinScaleDistance;
	float m_awarenessMinScale;
	std::vector<ArkPlayerUIComponent::DamageIndicator> m_damageIndicators;
	int m_maxNumDamageIndicators;
	unsigned m_currentEnemyTarget;
	ArkSimpleTimer m_enemyHealthTimeout;
	bool m_bEnemyHealthEnabled;

	ArkPlayerUIComponent();
	virtual ~ArkPlayerUIComponent();
	void LoadConfig(const XmlNodeRef& _node) { FLoadConfig(this, _node); }
	void Reset() { FReset(this); }
	void Update(const float _dt) { FUpdate(this, _dt); }
	void DrawDamageIndicator(const Vec3& _dir, bool _bIsDamage, const unsigned _sourceEntity) { FDrawDamageIndicatorOv0(this, _dir, _bIsDamage, _sourceEntity); }
	void SetEnemyHealthEnabled(bool _bEnabled) { FSetEnemyHealthEnabled(this, _bEnabled); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PreSerialize() { FPreSerialize(this); }
	void UpdateHUDMarkerElements() { FUpdateHUDMarkerElements(this); }
	void UpdateAwarenessLevel(unsigned _entity, EArkAttentionLevel _awarenessLevel) { FUpdateAwarenessLevel(this, _entity, _awarenessLevel); }
	void RemoveAwarenessIndicator(unsigned _entity, bool _bIsAware) { FRemoveAwarenessIndicator(this, _entity, _bIsAware); }
	void UpdateMarkedTarget(unsigned _entity, bool _bHostile, bool _bIsNew) { FUpdateMarkedTarget(this, _entity, _bHostile, _bIsNew); }
	void RemoveMarkedTarget(unsigned _entity) { FRemoveMarkedTarget(this, _entity); }
	void SetMarkedTargetConfigValues(float _fullAlphaDistance, float _zeroAlphaDistance, float _maxAngleForLabel) { FSetMarkedTargetConfigValues(this, _fullAlphaDistance, _zeroAlphaDistance, _maxAngleForLabel); }
	void SetAwarenessConfigValues(float _fullAlphaDistance, float _zeroAlphaDistance, float _fullScaleDistance, float _minScaleDistance, float _minScale) { FSetAwarenessConfigValues(this, _fullAlphaDistance, _zeroAlphaDistance, _fullScaleDistance, _minScaleDistance, _minScale); }
	void UpdateEnemyHealth(IUIElement* pHud, const float _frameTime) { FUpdateEnemyHealth(this, pHud, _frameTime); }
	void RemoveDamageIndicator(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FRemoveDamageIndicator(this, _pSender, _event, _args); }
	void OnAwarenessAnimComplete(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnAwarenessAnimComplete(this, _pSender, _event, _args); }

#if 0
	void DrawDamageIndicator(const Vec3& _arg0_, const unsigned _arg1_);
	void DrawShieldIndicator(const Vec3& _arg0_, const unsigned _arg1_);
	Vec3 GetTargetPosition(IEntity& _arg0_) const;
	void CloseEnemyHealth(bool _arg0_);
	int GetBestDamageIndicator(const unsigned _arg0_);
#endif

	static inline auto FArkPlayerUIComponentOv1 = PreyFunction<void(ArkPlayerUIComponent* const _this)>(0x1579A50);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerUIComponent* const _this, const XmlNodeRef& _node)>(0x157A230);
	static inline auto FReset = PreyFunction<void(ArkPlayerUIComponent* const _this)>(0x157A540);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerUIComponent* const _this, const float _dt)>(0x157A680);
	static inline auto FDrawDamageIndicatorOv0 = PreyFunction<void(ArkPlayerUIComponent* const _this, const Vec3& _dir, bool _bIsDamage, const unsigned _sourceEntity)>(0x1579DC0);
	static inline auto FSetEnemyHealthEnabled = PreyFunction<void(ArkPlayerUIComponent* const _this, bool _bEnabled)>(0x157A620);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerUIComponent* const _this, TSerialize _ser)>(0x157A550);
	static inline auto FPreSerialize = PreyFunction<void(ArkPlayerUIComponent* const _this)>(0x157A3D0);
	static inline auto FUpdateHUDMarkerElements = PreyFunction<void(ArkPlayerUIComponent* const _this)>(0x157AB70);
	static inline auto FUpdateAwarenessLevel = PreyFunction<void(ArkPlayerUIComponent* const _this, unsigned _entity, EArkAttentionLevel _awarenessLevel)>(0x157A880);
	static inline auto FRemoveAwarenessIndicator = PreyFunction<void(ArkPlayerUIComponent* const _this, unsigned _entity, bool _bIsAware)>(0x157A400);
	static inline auto FUpdateMarkedTarget = PreyFunction<void(ArkPlayerUIComponent* const _this, unsigned _entity, bool _bHostile, bool _bIsNew)>(0x157BEB0);
	static inline auto FRemoveMarkedTarget = PreyFunction<void(ArkPlayerUIComponent* const _this, unsigned _entity)>(0x157A510);
	static inline auto FSetMarkedTargetConfigValues = PreyFunction<void(ArkPlayerUIComponent* const _this, float _fullAlphaDistance, float _zeroAlphaDistance, float _maxAngleForLabel)>(0x157A670);
	static inline auto FSetAwarenessConfigValues = PreyFunction<void(ArkPlayerUIComponent* const _this, float _fullAlphaDistance, float _zeroAlphaDistance, float _fullScaleDistance, float _minScaleDistance, float _minScale)>(0x157A5F0);
	static inline auto FUpdateEnemyHealth = PreyFunction<void(ArkPlayerUIComponent* const _this, IUIElement* pHud, const float _frameTime)>(0x157A8E0);
	static inline auto FRemoveDamageIndicator = PreyFunction<void(ArkPlayerUIComponent* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x157A440);
	static inline auto FOnAwarenessAnimComplete = PreyFunction<void(ArkPlayerUIComponent* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x157A310);
};

