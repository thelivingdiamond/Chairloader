// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/Ark/ArkAbility.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/arkstatscomponent.h>

class ArkClass;
class XmlNodeRef;

// Header: Exact
// Prey/GameDll/ark/arkstatscomponent.h
class ArkStatModifierPackage : public ArkReflectedObject // Id=8015F86 Size=40
{
public:
	class ArkIDProperty : public ArkProperty // Id=8015F87 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkStatModifierPackage::ArkIDProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkStatModifierPackage::ArkIDProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	static ArkStatModifierPackage::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;

	class ArkNameProperty : public ArkProperty // Id=8015F88 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkStatModifierPackage::ArkNameProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1067250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkStatModifierPackage::ArkNameProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static ArkStatModifierPackage::ArkNameProperty s_ArkNameProperty;
	CCryName m_Name;

	class ArkModifiersProperty : public ArkProperty // Id=8015F89 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkStatModifierPackage::ArkModifiersProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1480550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkStatModifierPackage::ArkModifiersProperty const* const _this, ArkReflectedObject* const _pObject)>(0x14805B0);
		static inline auto FIsArray = PreyFunction<bool(ArkStatModifierPackage::ArkModifiersProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkStatModifierPackage::ArkModifiersProperty const* const _this, ArkReflectedObject* _pObject)>(0x14805D0);
	};

	static ArkStatModifierPackage::ArkModifiersProperty s_ArkModifiersProperty;
	std::vector<ArkStatModifier> m_Modifiers;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t arg0);
	const uint64_t& GetID() const;
	void SetName(CCryName arg0);
	CCryName const& GetName() const;
	std::vector<ArkStatModifier>& GetModifiers();
	std::vector<ArkStatModifier> const& GetModifiers() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1481C20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1481CD0);
};

// Header: Exact
// Prey/GameDll/ark/arkstatscomponent.h
class ArkStatModifierPackages : public ArkReflectedObject // Id=8015F81 Size=24
{
public:
	class ArkPackagesProperty : public ArkProperty // Id=8015F82 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkStatModifierPackages::ArkPackagesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14805E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkStatModifierPackages::ArkPackagesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1480660);
		static inline auto FIsArray = PreyFunction<bool(ArkStatModifierPackages::ArkPackagesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkStatModifierPackages::ArkPackagesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1480680);
	};

	static ArkStatModifierPackages::ArkPackagesProperty s_ArkPackagesProperty;
	std::vector<ArkStatModifierPackage> m_Packages;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkStatModifierPackage> &GetPackages();
	std::vector<ArkStatModifierPackage> const &GetPackages() const;
	ArkStatModifierPackage const *Find(uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
};

// Header: Exact
// Prey/GameDll/ark/ArkStatsComponent.h
class ArkStatsComponent // Id=8015F15 Size=160
{
public:
	struct ArkModifier // Id=8015F3F Size=8
	{
		unsigned m_id;
		float m_value;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(unsigned arg0) const;
#endif
	};

	struct ArkStat // Id=8015F40 Size=32
	{
		float m_baseValue;
		float m_currentValue;
		std::vector<ArkStatsComponent::ArkModifier> m_modifiers;
		
#if 0
		void Serialize(TSerialize arg0);
		float GetValue() const;
		float ComputeValue();
#endif
	};

	unsigned m_ownerId;
	unsigned m_currentId;
	std::unordered_map<CCryName,ArkStatsComponent::ArkStat> m_stats;
	ArkStatModifierPackages m_packagesDesc;
	std::unordered_map<unsigned int,std::vector<unsigned int>> m_activePackages;
	
	void Reset(XmlNodeRef const &_config) { FReset(this,_config); }
	void AddStats(std::unordered_map<CCryName,float> &_statsMap) { FAddStats(this,_statsMap); }
	void Clear() { FClear(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	float GetStat(CCryName const &_stat64i32) const { return FGetStatOv1(this,_stat64i32); }
	float GetStat(string const &_stat64i32) const { return FGetStatOv0(this,_stat64i32); }
	float GetBaseStat(CCryName const &_stat64i32) const { return FGetBaseStat(this,_stat64i32); }
	unsigned AddModifier(CCryName const &_statName, float _modifier, string const &_modName) { return FAddModifierOv0(this,_statName,_modifier,_modName); }
	unsigned ApplyPackage(uint64_t _packageId) { return FApplyPackage(this,_packageId); }
	void RemoveModifier(unsigned _modifierId, bool _bSilent) { FRemoveModifier(this,_modifierId,_bSilent); }
	void RemovePackage(unsigned _packageId, bool _bSilent) { FRemovePackage(this,_packageId,_bSilent); }
	
#if 0
	void SetOwnerId(const unsigned arg0);
	int GetStatInt(CCryName const &arg0) const;
	bool GetStatBool(CCryName const &arg0) const;
	unsigned AddModifier(CCryName const &arg0, float arg1);
	unsigned UpdateCurrentId();
#endif
	
	static inline auto FReset = PreyFunction<void(ArkStatsComponent *const _this, XmlNodeRef const &_config)>(0x1482270);
	static inline auto FAddStats = PreyFunction<void(ArkStatsComponent *const _this, std::unordered_map<CCryName,float> &_statsMap)>(0x1481670);
	static inline auto FClear = PreyFunction<void(ArkStatsComponent *const _this)>(0x1481BF0);
	static inline auto FSerialize = PreyFunction<void(ArkStatsComponent *const _this, TSerialize _ser)>(0x14826A0);
	static inline auto FGetStatOv1 = PreyFunction<float(ArkStatsComponent const *const _this, CCryName const &_stat64i32)>(0x1481D70);
	static inline auto FGetStatOv0 = PreyFunction<float(ArkStatsComponent const *const _this, string const &_stat64i32)>(0x122EDC0);
	static inline auto FGetBaseStat = PreyFunction<float(ArkStatsComponent const *const _this, CCryName const &_stat64i32)>(0x1481C60);
	static inline auto FAddModifierOv0 = PreyFunction<unsigned(ArkStatsComponent *const _this, CCryName const &_statName, float _modifier, string const &_modName)>(0x14814C0);
	static inline auto FApplyPackage = PreyFunction<unsigned(ArkStatsComponent *const _this, uint64_t _packageId)>(0x1481910);
	static inline auto FRemoveModifier = PreyFunction<void(ArkStatsComponent *const _this, unsigned _modifierId, bool _bSilent)>(0x1481DE0);
	static inline auto FRemovePackage = PreyFunction<void(ArkStatsComponent *const _this, unsigned _packageId, bool _bSilent)>(0x1481F40);
};

