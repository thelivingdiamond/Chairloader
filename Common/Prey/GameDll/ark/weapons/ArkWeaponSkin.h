// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <_unknown/ArkWeaponSkinArchetypes.h>

class ArkClass;
class IArkValueBase;

// ArkWeaponSkin
// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
class ArkWeaponSkin : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkWeaponSkin::ArkIDProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponSkin::ArkNameProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkWeaponSkin::ArkLabelProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkWeaponSkin::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkWeaponSkin::ArkIconProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkWeaponSkin::ArkMaterial1PProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkMaterial1PProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaterial1PProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkMaterial1PProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkMaterial1PProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkWeaponSkin::ArkGroupProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkGroupProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGroupProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkin::ArkGroupProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkin::ArkGroupProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkWeaponSkin::ArkIDProperty>(0x2D586F8);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkWeaponSkin::ArkNameProperty>(0x2D58718);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkWeaponSkin::ArkLabelProperty>(0x2D58738);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkWeaponSkin::ArkDescriptionProperty>(0x2D58758);
	string m_Description;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkWeaponSkin::ArkIconProperty>(0x2D58778);
	string m_Icon;
	static inline auto s_ArkMaterial1PProperty = PreyGlobal<ArkWeaponSkin::ArkMaterial1PProperty>(0x2D58798);
	string m_Material1P;
	static inline auto s_ArkGroupProperty = PreyGlobal<ArkWeaponSkin::ArkGroupProperty>(0x2D587B8);
	uint64_t m_Group;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkWeaponSkin();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetIcon(string _arg0_);
	const string& GetIcon() const;
	void SetMaterial1P(string _arg0_);
	const string& GetMaterial1P() const;
	void SetGroup(uint64_t _arg0_);
	const uint64_t& GetGroup() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1492290);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14924F0);
};

// ArkWeaponSkinGroup
// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
class ArkWeaponSkinGroup : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkWeaponSkinGroup::ArkIDProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkinGroup::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkinGroup::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkWeaponSkinGroup::ArkWeaponsProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkWeaponsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWeaponsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkinGroup::ArkWeaponsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14914D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkinGroup::ArkWeaponsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1491530);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponSkinGroup::ArkWeaponsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponSkinGroup::ArkWeaponsProperty* const _this, ArkReflectedObject* _pObject)>(0x1491550);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkWeaponSkinGroup::ArkIDProperty>(0x2D586B8);
	uint64_t m_ID;
	static inline auto s_ArkWeaponsProperty = PreyGlobal<ArkWeaponSkinGroup::ArkWeaponsProperty>(0x2D586D8);
	std::vector<ArkWeaponSkinArchetypes> m_Weapons;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkWeaponSkinGroup();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	std::vector<ArkWeaponSkinArchetypes>& GetWeapons();
	const std::vector<ArkWeaponSkinArchetypes>& GetWeapons() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14922D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1492590);
};

// ArkWeaponSkins
// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
class ArkWeaponSkins : public ArkReflectedLibrary
{ // Size=56 (0x38)
public:
	// ArkWeaponSkins::ArkWeaponSkinsProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkWeaponSkinsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkWeaponSkinsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkins::ArkWeaponSkinsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14911D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkins::ArkWeaponSkinsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1491320);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponSkins::ArkWeaponSkinsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponSkins::ArkWeaponSkinsProperty* const _this, ArkReflectedObject* _pObject)>(0x1491360);
	};

	// ArkWeaponSkins::ArkGroupsProperty
	// Header:  Prey/GameDll/ark/weapons/ArkWeaponSkin.h
	class ArkGroupsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkGroupsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkWeaponSkins::ArkGroupsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14913D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkWeaponSkins::ArkGroupsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1491420);
		static inline auto FIsArray = PreyFunction<bool(const ArkWeaponSkins::ArkGroupsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkWeaponSkins::ArkGroupsProperty* const _this, ArkReflectedObject* _pObject)>(0x1491460);
	};

	static inline auto s_ArkWeaponSkinsProperty = PreyGlobal<ArkWeaponSkins::ArkWeaponSkinsProperty>(0x2D587D8);
	std::vector<ArkWeaponSkin> m_WeaponSkins;
	static inline auto s_ArkGroupsProperty = PreyGlobal<ArkWeaponSkins::ArkGroupsProperty>(0x2D587F8);
	std::vector<ArkWeaponSkinGroup> m_Groups;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	bool DoesArchetypeHaveSkins(uint64_t _archetypeId) const { return FDoesArchetypeHaveSkins(this, _archetypeId); }
	const ArkWeaponSkin* FindWeaponSkin(uint64_t _id) const { return FFindWeaponSkinOv1(this, _id); }
	uint64_t FindWeaponSkinGroup(const uint64_t _archetypeId) const { return FFindWeaponSkinGroup(this, _archetypeId); }

#if 0
	std::vector<ArkWeaponSkin>& GetWeaponSkins();
	const std::vector<ArkWeaponSkin>& GetWeaponSkins() const;
	std::vector<ArkWeaponSkinGroup>& GetGroups();
	const std::vector<ArkWeaponSkinGroup>& GetGroups() const;
	const ArkWeaponSkin* FindWeaponSkin(const char* const _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1492310);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1492630);
	static inline auto FInit = PreyFunction<bool(ArkWeaponSkins* const _this)>(0x1492720);
	static inline auto FDoesArchetypeHaveSkins = PreyFunction<bool(const ArkWeaponSkins* const _this, uint64_t _archetypeId)>(0x1492370);
	static inline auto FFindWeaponSkinOv1 = PreyFunction<const ArkWeaponSkin* (const ArkWeaponSkins* const _this, uint64_t _id)>(0x1492420);
	static inline auto FFindWeaponSkinGroup = PreyFunction<uint64_t(const ArkWeaponSkins* const _this, const uint64_t _archetypeId)>(0x1492450);
};
#endif // MOONCRASH
