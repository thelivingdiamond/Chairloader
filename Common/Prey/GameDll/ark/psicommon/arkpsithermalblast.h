// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

struct IEntity;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h
class ArkPsiThermalBlastProperties : public ArkReflectedObject // Id=801C16A Size=144
{
public:
	class ArkBlastPropertiesProperty : public ArkProperty // Id=801C16B Size=32
	{
	public:
		ArkBlastPropertiesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkPsiThermalBlastProperties::ArkBlastPropertiesProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1580AE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkPsiThermalBlastProperties::ArkBlastPropertiesProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static ArkPsiThermalBlastProperties::ArkBlastPropertiesProperty s_ArkBlastPropertiesProperty;
	ArkPsiBlastProperties m_BlastProperties;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetBlastProperties(ArkPsiBlastProperties arg0);
	ArkPsiBlastProperties const& GetBlastProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15811D0);
};

// Header: FromCpp
// Prey/GameDll/ark/psicommon/arkpsithermalblast.h
class CArkPsiThermalBlast : public CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> > // Id=801C18E Size=112
{
public:
	using BaseType = CArkPsiBlast<CArkPsiThermalBlast,CArkPsiBlastProperties<ArkPsiThermalBlastProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiThermalBlastProperties>;
	
	std::vector<unsigned int> m_obstructedTargets;
	int m_checkObstructedTargetIndex;
	bool m_bExplode;
	
	CArkPsiThermalBlast();
	CArkPsiThermalBlast(CArkPsiThermalBlast *_blast);
	CArkPsiThermalBlast(Vec3 const &_pos, CArkPsiBlastProperties<ArkPsiThermalBlastProperties> const *_pProperties);
	CArkPsiThermalBlast &operator=(CArkPsiThermalBlast *_blast) { return FoperatorEq(this,_blast); }
	float GetDelaySec() const { return FGetDelaySec(this); }
	EArkPsiPowers GetPower() const { return FGetPower(this); }
	void UpdateEffect(std::vector<IEntity *> _entities) const { FUpdateEffect(this,_entities); }
	void UpdateFrame(const float _frameTime) { FUpdateFrame(this,_frameTime); }
	void OnEnterAreaDerived(IEntity const &_entity) { FOnEnterAreaDerived(this,_entity); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void InitializeArea() { FInitializeArea(this); }
	bool TriggerExplosion(IEntity const &_entity) { return FTriggerExplosion(this,_entity); }
	
#if 0
	void ResetDerived();
#endif
	
	static inline auto FoperatorEq = PreyFunction<CArkPsiThermalBlast &(CArkPsiThermalBlast *const _this, CArkPsiThermalBlast *_blast)>(0x146F460);
	static inline auto FGetDelaySec = PreyFunction<float(CArkPsiThermalBlast const *const _this)>(0x146F480);
	static inline auto FGetPower = PreyFunction<EArkPsiPowers(CArkPsiThermalBlast const *const _this)>(0x1B1DEA0);
	static inline auto FUpdateEffect = PreyFunction<void(CArkPsiThermalBlast const *const _this, std::vector<IEntity *> _entities)>(0x146FC70);
	static inline auto FUpdateFrame = PreyFunction<void(CArkPsiThermalBlast *const _this, const float _frameTime)>(0x146FFB0);
	static inline auto FOnEnterAreaDerived = PreyFunction<void(CArkPsiThermalBlast *const _this, IEntity const &_entity)>(0x146F8A0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiThermalBlast *const _this, TSerialize _ser)>(0x146F940);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiThermalBlast *const _this)>(0x146F8B0);
	static inline auto FInitializeArea = PreyFunction<void(CArkPsiThermalBlast *const _this)>(0x146F4A0);
	static inline auto FTriggerExplosion = PreyFunction<bool(CArkPsiThermalBlast *const _this, IEntity const &_entity)>(0x146FA70);
};
