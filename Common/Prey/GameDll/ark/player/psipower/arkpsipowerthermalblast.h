// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowermimic.h>

class ArkClass;
class ArkReflectedObject;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerthermalblast.h
class ThermalBlastPowerProperties : public ArkReflectedLibrary // Id=801C174 Size=248
{
public:
	using LevelProperties = ArkPsiPowerThermalBlastProperties;
	using UniqueProperties = bool;
	
	class ArkCommonProperty : public ArkProperty // Id=801C175 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ThermalBlastPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ThermalBlastPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ThermalBlastPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801C176 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ThermalBlastPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ThermalBlastPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static ThermalBlastPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	bool m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C177 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ThermalBlastPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x146C180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ThermalBlastPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x146C280);
		static inline auto FIsArray = PreyFunction<bool(ThermalBlastPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ThermalBlastPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1466DB0);
	};

	static ThermalBlastPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerThermalBlastProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ThermalBlastPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(bool arg0);
	const bool &GetUnique() const;
	std::vector<ArkPsiPowerThermalBlastProperties> &GetLevels();
	std::vector<ArkPsiPowerThermalBlastProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x146D740);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x146D860);
	static inline auto FInit = PreyFunction<bool(ThermalBlastPowerProperties *const _this)>(0x146DAF0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowerthermalblast.h
class CArkPsiPowerThermalBlast : public CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,1> // Id=801C186 Size=696
{
public:
	CArkPsiPowerThermalBlast();
	virtual ~CArkPsiPowerThermalBlast();
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity *>(CArkPsiPowerThermalBlast const *const _this)>(0x146DA30);
};

