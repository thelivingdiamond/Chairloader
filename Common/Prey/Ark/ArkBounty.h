// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <_unknown/ArkBountyWeapon.h>

class ArkClass;
class IArkValueBase;

// ArkBounty
// Header:  Prey/Ark/ArkBounty.h
class ArkBounty : public ArkReflectedObject
{ // Size=112 (0x70)
public:
	// ArkBounty::ArkIDProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkBounty::ArkNameProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkBounty::ArkWeaponProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkWeaponProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkWeaponProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkWeaponProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
	};

	// ArkBounty::ArkAlternateWeaponsProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkAlternateWeaponsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkAlternateWeaponsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkAlternateWeaponsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10794F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkAlternateWeaponsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1079550);
		static inline auto FIsArray = PreyFunction<bool(const ArkBounty::ArkAlternateWeaponsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkBounty::ArkAlternateWeaponsProperty* const _this, ArkReflectedObject* _pObject)>(0x1079570);
	};

	// ArkBounty::ArkVerbProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkVerbProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVerbProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkVerbProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkVerbProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkBounty::ArkLethalProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkLethalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLethalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkLethalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10795E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkLethalProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkBounty::ArkTargetWhiteListProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkTargetWhiteListProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkTargetWhiteListProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkTargetWhiteListProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10795F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkTargetWhiteListProperty* const _this, ArkReflectedObject* const _pObject)>(0x1079610);
		static inline auto FIsArray = PreyFunction<bool(const ArkBounty::ArkTargetWhiteListProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkBounty::ArkTargetWhiteListProperty* const _this, ArkReflectedObject* _pObject)>(0x1079630);
	};

	// ArkBounty::ArkTargetBlackListProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkTargetBlackListProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkTargetBlackListProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBounty::ArkTargetBlackListProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1079640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBounty::ArkTargetBlackListProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C440);
		static inline auto FIsArray = PreyFunction<bool(const ArkBounty::ArkTargetBlackListProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkBounty::ArkTargetBlackListProperty* const _this, ArkReflectedObject* _pObject)>(0x1079660);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkBounty::ArkIDProperty>(0x2D21840);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkBounty::ArkNameProperty>(0x2D21860);
	string m_Name;
	static inline auto s_ArkWeaponProperty = PreyGlobal<ArkBounty::ArkWeaponProperty>(0x2D21880);
	string m_Weapon;
	static inline auto s_ArkAlternateWeaponsProperty = PreyGlobal<ArkBounty::ArkAlternateWeaponsProperty>(0x2D218A0);
	std::vector<ArkBountyWeapon> m_AlternateWeapons;
	static inline auto s_ArkVerbProperty = PreyGlobal<ArkBounty::ArkVerbProperty>(0x2D218C0);
	string m_Verb;
	static inline auto s_ArkLethalProperty = PreyGlobal<ArkBounty::ArkLethalProperty>(0x2D218E0);
	bool m_Lethal;
	static inline auto s_ArkTargetWhiteListProperty = PreyGlobal<ArkBounty::ArkTargetWhiteListProperty>(0x2D21900);
	std::vector<uint64_t> m_TargetWhiteList;
	static inline auto s_ArkTargetBlackListProperty = PreyGlobal<ArkBounty::ArkTargetBlackListProperty>(0x2D21920);
	std::vector<uint64_t> m_TargetBlackList;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	bool IsValidWeaponForBounty(uint64_t _archetypeId) const { return FIsValidWeaponForBounty(this, _archetypeId); }

#if 0
	ArkBounty();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetWeapon(string _arg0_);
	uint64_t GetWeapon() const;
	const string& GetWeaponString() const;
	std::vector<ArkBountyWeapon>& GetAlternateWeapons();
	const std::vector<ArkBountyWeapon>& GetAlternateWeapons() const;
	void SetVerb(string _arg0_);
	const string& GetVerb() const;
	void SetLethal(bool _arg0_);
	const bool& GetLethal() const;
	std::vector<uint64_t>& GetTargetWhiteList();
	const std::vector<uint64_t>& GetTargetWhiteList() const;
	std::vector<uint64_t>& GetTargetBlackList();
	const std::vector<uint64_t>& GetTargetBlackList() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107AAF0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107ACD0);
	static inline auto FIsValidWeaponForBounty = PreyFunction<bool(const ArkBounty* const _this, uint64_t _archetypeId)>(0x107B0D0);
};

// ArkBountyTarget
// Header:  Prey/Ark/ArkBounty.h
class ArkBountyTarget : public ArkReflectedObject
{ // Size=48 (0x30)
public:
	// ArkBountyTarget::ArkIDProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyTarget::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBountyTarget::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkBountyTarget::ArkNameProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyTarget::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBountyTarget::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkBountyTarget::ArkMetaTagsProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyTarget::ArkMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1079260);
	};

	// ArkBountyTarget::ArkLabelProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyTarget::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBountyTarget::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkBountyTarget::ArkIDProperty>(0x2D217A0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkBountyTarget::ArkNameProperty>(0x2D217C0);
	string m_Name;
	static inline auto s_ArkMetaTagsProperty = PreyGlobal<ArkBountyTarget::ArkMetaTagsProperty>(0x2D217E0);
	std::vector<uint64_t> m_MetaTags;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkBountyTarget::ArkLabelProperty>(0x2D21800);
	string m_Label;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkBountyTarget();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetMetaTags(string _arg0_);
	const std::vector<uint64_t>& GetMetaTags() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107ABB0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107AE60);
};

// ArkBountyBoard
// Header:  Prey/Ark/ArkBounty.h
class ArkBountyBoard : public ArkReflectedLibrary
{ // Size=56 (0x38)
public:
	// ArkBountyBoard::ArkBountiesProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkBountiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkBountiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyBoard::ArkBountiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1079100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBountyBoard::ArkBountiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10791B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkBountyBoard::ArkBountiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkBountyBoard::ArkBountiesProperty* const _this, ArkReflectedObject* _pObject)>(0x10791F0);
	};

	// ArkBountyBoard::ArkTargetsProperty
	// Header:  Prey/Ark/ArkBounty.h
	class ArkTargetsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkTargetsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkBountyBoard::ArkTargetsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1079390);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkBountyBoard::ArkTargetsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1079470);
		static inline auto FIsArray = PreyFunction<bool(const ArkBountyBoard::ArkTargetsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkBountyBoard::ArkTargetsProperty* const _this, ArkReflectedObject* _pObject)>(0x10794B0);
	};

	static inline auto s_ArkBountiesProperty = PreyGlobal<ArkBountyBoard::ArkBountiesProperty>(0x2D21940);
	std::vector<ArkBounty> m_Bounties;
	static inline auto s_ArkTargetsProperty = PreyGlobal<ArkBountyBoard::ArkTargetsProperty>(0x2D21960);
	std::vector<ArkBountyTarget> m_Targets;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkBounty* Find(const uint64_t _id) const { return FFindOv1(this, _id); }
	const ArkBounty* Find(const char* _name) const { return FFindOv0(this, _name); }
	const ArkBountyTarget* FindTarget(const uint64_t _id) const { return FFindTarget(this, _id); }
	virtual bool Init();

#if 0
	std::vector<ArkBounty>& GetBounties();
	const std::vector<ArkBounty>& GetBounties() const;
	std::vector<ArkBountyTarget>& GetTargets();
	const std::vector<ArkBountyTarget>& GetTargets() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107AB50);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107AD70);
	static inline auto FFindOv1 = PreyFunction<const ArkBounty* (const ArkBountyBoard* const _this, const uint64_t _id)>(0x107AC70);
	static inline auto FFindOv0 = PreyFunction<const ArkBounty* (const ArkBountyBoard* const _this, const char* _name)>(0x107AC20);
	static inline auto FFindTarget = PreyFunction<const ArkBountyTarget* (const ArkBountyBoard* const _this, const uint64_t _id)>(0x107ACA0);
	static inline auto FInit = PreyFunction<bool(ArkBountyBoard* const _this)>(0x107AF00);
};
#endif // MOONCRASH
