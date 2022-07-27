// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h>

class ArkClass;
class ArkReflectedObject;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerfear.h
class FearPowerProperties : public ArkReflectedLibrary // Id=801C88C Size=248
{
public:
	using LevelProperties = ArkPsiPowerFearProperties;
	using UniqueProperties = bool;
	
	class ArkCommonProperty : public ArkProperty // Id=801C88D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(FearPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(FearPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static FearPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801C88E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(FearPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(FearPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static FearPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	bool m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C88F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(FearPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15840B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(FearPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15841B0);
		static inline auto FIsArray = PreyFunction<bool(FearPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(FearPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1466DB0);
	};

	static FearPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerFearProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~FearPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(bool arg0);
	const bool &GetUnique() const;
	std::vector<ArkPsiPowerFearProperties> &GetLevels();
	std::vector<ArkPsiPowerFearProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1584890);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15849B0);
	static inline auto FInit = PreyFunction<bool(FearPowerProperties *const _this)>(0x1584AA0);
};

