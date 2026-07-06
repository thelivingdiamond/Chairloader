// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/itemstring.h>
#include <_unknown/CryFixedArray.h>
#include <_unknown/IGameSharedParameters.h>
#include <_unknown/SAccessoryParams.h>
#include <_unknown/SAimLookParameters.h>
#include <_unknown/SAnimationPreCache.h>
#include <_unknown/SAttachmentHelper.h>
#include <_unknown/SDamageLevel.h>
#include <_unknown/SGeometryDef.h>

class CItem;
class CItemGeometryCache;
class CItemResourceCache;
class ICrySizer;
struct IEntityClass;
struct SFlashLightParams;
struct SLaserParams;
struct SMountParams;
class XmlNodeRef;
enum eGeometrySlot;

// SAimAnimsBlock
// Header:  Prey/GameDll/ItemSharedParams.h
struct SAimAnimsBlock
{ // Size=128 (0x80)
	SharedString::CSharedString anim[16];

	void Reset() { FReset(this); }

#if 0
	void Read(const XmlNodeRef& _arg0_);
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FReset = PreyFunction<void(SAimAnimsBlock* const _this)>(0x1890360);
};

// SParams
// Header:  Prey/GameDll/ItemSharedParams.h
// Include: Prey/CryAction/Animation/PoseModifier/IKTorsoAim.h
struct SParams
{ // Size=632 (0x278)
	bool heavy_weapon;
	bool selectable;
	bool droppable;
	bool pickable;
	bool mountable;
	bool usable;
	bool giveable;
	bool unique;
	bool auto_droppable;
	bool auto_pickable;
	bool attachment_gives_ammo;
	bool has_first_select;
	bool fast_select;
	bool select_delayed_grab_3P;
	bool can_ledge_grab;
	bool can_rip_off;
	bool usable_under_water;
	bool can_overcharge;
	bool check_clip_size_after_drop;
	bool check_bonus_ammo_after_drop;
	bool remove_on_drop;
	float sprintToFireDelay;
	float sprintToZoomDelay;
	float sprintToMeleeDelay;
	float autoReloadDelay;
	float runToSprintBlendTime;
	float sprintToRunBlendTime;
	int scopeAttachment;
	int hud_style;
	float mass;
	float drop_impulse;
	float select_override;
	float zoomTimeMultiplier;
	float selectTimeMultiplier;
	Vec3 fp_offset;
	Quat fp_rot_offset;
	SharedString::CSharedString tag;
	SharedString::CSharedString itemClass;
	SharedString::CSharedString aiAttachment[2];
	SharedString::CSharedString attachment[2];
	SharedString::CSharedString display_name;
	SharedString::CSharedString icon;
	int width;
	int height;
	SharedString::CSharedString description;
	SharedString::CSharedString pickupSFX;
	SharedString::CSharedString usedFromInventorySFX;
	SharedString::CSharedString adbFile;
	SharedString::CSharedString soundAdbFile;
	SharedString::CSharedString actionControllerFile;
	SharedString::CSharedString bone_attachment_01;
	SharedString::CSharedString bone_attachment_02;
	bool attach_to_back;
	bool hasAimAnims;
	float ironsightAimAnimFactor;
	SAimAnimsBlock aimAnims;
	SAimAnimsBlock mountedAimAnims;
	SAimLookParameters aimLookParams;
	SharedString::CSharedString mountedTPAimAnims[2];
	SharedString::CSharedString crosshairTexture;

	void Reset() { FReset(this); }

#if 0
	SParams();
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FReset = PreyFunction<void(SParams* const _this)>(0x18903E0);
};

// CItemSharedParams
// Header:  Prey/GameDll/ItemSharedParams.h
class CItemSharedParams : public IGameSharedParameters
{ // Size=960 (0x3C0)
public:
	using TDamageLevelVector = std::vector<SDamageLevel>;
	using TGeometryDefVector = std::vector<SGeometryDef>;
	using TAnimationPrecacheVector = std::vector<SAnimationPreCache>;

	std::vector<SAccessoryParams> accessoryparams;
	std::vector<SAttachmentHelper> helpers;
	SParams params;
	std::vector<SDamageLevel> damageLevels;
	CryFixedArray<IEntityClass *,8> defaultAccessories;
	CryFixedArray<IEntityClass *,4> initialSetup;
	std::map<IEntityClass*, int> bonusAccessoryAmmo;
	std::map<IEntityClass*, int> accessoryAmmoCapacity;
	SLaserParams* pLaserParams;
	SFlashLightParams* pFlashLightParams;
	SMountParams* pMountParams;
	SharedString::CSharedString animationGroup;
	std::vector<SAnimationPreCache> animationPrecache;
	std::vector<SGeometryDef> geometry;

	CItemSharedParams();
	virtual ~CItemSharedParams();
	virtual void GetMemoryUsage(ICrySizer* pSizer) const;
	virtual const char* GetDataType() const;
	virtual void ReleaseLevelResources();
	void CacheResources(CItemResourceCache& itemResourceCache, const IEntityClass* pItemClass) { FCacheResources(this, itemResourceCache, pItemClass); }
	const SGeometryDef* GetGeometryForSlot(eGeometrySlot geomSlot) const { return FGetGeometryForSlot(this, geomSlot); }
	void LoadGeometryForItem(CItem* pItem, eGeometrySlot skipSlot) const { FLoadGeometryForItem(this, pItem, skipSlot); }

#if 0
	static const SLaserParams& GetDefaultLaserParameters();
	bool ReadItemParams(const XmlNodeRef& _arg0_);
	void ReadOverrideItemParams(const XmlNodeRef& _arg0_);
	void CacheResourcesForLevelStartMP(CItemResourceCache& _arg0_, const IEntityClass* _arg1_);
	bool ReadParams(const XmlNodeRef& _arg0_);
	bool ReadGeometry(const XmlNodeRef& _arg0_);
	bool ReadDamageLevels(const XmlNodeRef& _arg0_);
	bool ReadAccessories(const XmlNodeRef& _arg0_);
	bool ReadAccessoryParams(const XmlNodeRef& _arg0_, SAccessoryParams* _arg1_);
	bool ReadAccessoryAmmo(const XmlNodeRef& _arg0_);
	bool ReadLaserParams(const XmlNodeRef& _arg0_);
	bool ReadFlashLightParams(const XmlNodeRef& _arg0_);
	int TargetToSlot(const char* _arg0_);
	void PrefixPathIfFilename(const char* _arg0_, SharedString::CSharedString& _arg1_);
	bool ItemClassUsesDefaultLaser(const IEntityClass* _arg0_) const;
#endif

	static inline auto FCItemSharedParamsOv1 = PreyFunction<void(CItemSharedParams* const _this)>(0x188E6C0);
	static inline auto FBitNotCItemSharedParams = PreyFunction<void(CItemSharedParams* const _this)>(0x188ECB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CItemSharedParams* const _this, ICrySizer* pSizer)>(0x188FE90);
	static inline auto FGetDataType = PreyFunction<const char* (const CItemSharedParams* const _this)>(0x188FBF0);
	static inline auto FReleaseLevelResources = PreyFunction<void(CItemSharedParams* const _this)>(0x1333E90);
	static inline auto FCacheResources = PreyFunction<void(CItemSharedParams* const _this, CItemResourceCache& itemResourceCache, const IEntityClass* pItemClass)>(0x188F8B0);
	static inline auto FGetGeometryForSlot = PreyFunction<const SGeometryDef* (const CItemSharedParams* const _this, eGeometrySlot geomSlot)>(0x188FC00);
	static inline auto FLoadGeometryForItem = PreyFunction<void(const CItemSharedParams* const _this, CItem* pItem, eGeometrySlot skipSlot)>(0x1890040);
};

// SLaserParams
// Header:  Prey/GameDll/ItemSharedParams.h
struct SLaserParams
{ // Size=48 (0x30)
	string laser_geometry_tp;
	string laser_dot[2];
	float laser_range[2];
	float laser_thickness[2];
	bool show_dot;

	SLaserParams();

#if 0
	void CacheResources(CItemGeometryCache& _arg0_) const;
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FSLaserParamsOv2 = PreyFunction<void(SLaserParams* const _this)>(0x188E920);
};
#endif // MOONCRASH
