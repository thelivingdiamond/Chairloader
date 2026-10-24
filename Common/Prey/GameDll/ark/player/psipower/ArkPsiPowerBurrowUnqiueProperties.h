#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerBurrowUnqiueProperties
// Header:  _unknown/ArkPsiPowerBurrowUnqiueProperties.h
class ArkPsiPowerBurrowUnqiueProperties : public ArkReflectedObject
{ // Size=4 (0x4)
public:
	// ArkPsiPowerBurrowUnqiueProperties::ArkNavMeshHorizontalSearchRadiusProperty
	// Header:  _unknown/ArkPsiPowerBurrowUnqiueProperties.h
	class ArkNavMeshHorizontalSearchRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNavMeshHorizontalSearchRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBurrowUnqiueProperties::ArkNavMeshHorizontalSearchRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerBurrowUnqiueProperties::ArkNavMeshHorizontalSearchRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	static inline auto s_ArkNavMeshHorizontalSearchRadiusProperty = PreyGlobal<ArkPsiPowerBurrowUnqiueProperties::ArkNavMeshHorizontalSearchRadiusProperty>(0x2D50978);
	float m_NavMeshHorizontalSearchRadius;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	void SetNavMeshHorizontalSearchRadius(float _arg0_);
	const float& GetNavMeshHorizontalSearchRadius() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14E13B0);
};

#endif // MOONCRASH
