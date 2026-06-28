// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <_unknown/STagState.h>
#include <_unknown/TMannequinAutoInit.h>

struct AnimEventInstance;
class CItem;
class CTagDefinition;
enum class EPriorityComparison;
class IAction;
struct ICharacterInstance;
struct SControllerDef;

// CItemAction
// Header:  Prey/GameDll/itemanimation.h
class CItemAction : public TAction<SAnimationContext>
{ // Size=128 (0x80)
public:
	using BaseClass = TAction<SAnimationContext>;

	virtual const char* GetName() const;
	virtual void DoDelete();
	virtual EPriorityComparison ComparePriority(const IAction& actionCurrent) const;

#if 0
	CItemAction(int _arg0_, int _arg1_, const STagState<12>& _arg2_, const int _arg3_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CItemAction* const _this)>(0x1883610);
	static inline auto FDoDelete = PreyFunction<void(CItemAction* const _this)>(0x3E3960);
	static inline auto FComparePriority = PreyFunction<EPriorityComparison(const CItemAction* const _this, const IAction& actionCurrent)>(0x4FD7F0);
};

// CItemSelectAction
// Header:  Prey/GameDll/itemanimation.h
class CItemSelectAction : public CItemAction
{ // Size=136 (0x88)
public:
	using BaseClass = CItemAction;

	unsigned m_ItemID;
	bool m_bSelected;

	virtual const char* GetName() const;
	virtual void DoDelete();
	CItemSelectAction(int priority, int fragmentID, const STagState<12>& fragTags, CItem& _item);
	virtual void Enter();
	virtual void Exit();
	virtual void OnAnimationEvent(ICharacterInstance* pCharacter, const AnimEventInstance& event);
	void ItemSelectCancelled() { FItemSelectCancelled(this); }
	void SelectWeapon() { FSelectWeapon(this); }
	void UnhideWeapon(CItem* pItem) { FUnhideWeapon(this, pItem); }

	static inline auto FGetName = PreyFunction<const char* (const CItemSelectAction* const _this)>(0x1883620);
	static inline auto FDoDelete = PreyFunction<void(CItemSelectAction* const _this)>(0x3E3960);
	static inline auto FCItemSelectAction = PreyFunction<void(CItemSelectAction* const _this, int priority, int fragmentID, const STagState<12>& fragTags, CItem& _item)>(0x18834F0);
	static inline auto FEnter = PreyFunction<void(CItemSelectAction* const _this)>(0x1883590);
	static inline auto FExit = PreyFunction<void(CItemSelectAction* const _this)>(0x18835F0);
	static inline auto FOnAnimationEvent = PreyFunction<void(CItemSelectAction* const _this, ICharacterInstance* pCharacter, const AnimEventInstance& event)>(0x1883650);
	static inline auto FItemSelectCancelled = PreyFunction<void(CItemSelectAction* const _this)>(0x1883630);
	static inline auto FSelectWeapon = PreyFunction<void(CItemSelectAction* const _this)>(0x1883670);
	static inline auto FUnhideWeapon = PreyFunction<void(CItemSelectAction* const _this, CItem* pItem)>(0x1883780);
};

// SMannequinItemParams
// Header:  Prey/GameDll/itemanimation.h
struct SMannequinItemParams : public IMannequinUserParams
{ // Size=528 (0x210)
	// SMannequinItemParams::FragmentIDs
	// Header:  Prey/GameDll/itemanimation.h
	struct FragmentIDs
	{ // Size=444 (0x1BC)
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_A;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_B;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_C;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_D;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_E;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_F;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Attack_G;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_A;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_B;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_C;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_D;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_E;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_F;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_G;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_A;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_B;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_C;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_D;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_E;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_F;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_G;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_A2B;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_B2C;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_C2D;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_D2E;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_E2F;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_F2G;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_G2A;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_A2B;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_B2C;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_C2D;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_D2E;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_E2F;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_F2G;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_BigHit_Enemy_G2A;
		TMannequinAutoInit<int,-1> Wpn_DualWrench_Fatality_Generic;
		TMannequinAutoInit<int,-1> Wpn_Melee_BigHit_LeftRight;
		TMannequinAutoInit<int,-1> Wpn_Melee_BigHit_RightLeft;
		TMannequinAutoInit<int,-1> Wpn_Melee_BigHit_Enemy_RightLeft;
		TMannequinAutoInit<int,-1> Wpn_Melee_BigHit_Enemy_LeftRight;
		TMannequinAutoInit<int,-1> Wpn_Melee_In_LeftRight;
		TMannequinAutoInit<int,-1> Wpn_Melee_In_RightLeft;
		TMannequinAutoInit<int,-1> Wpn_Melee_LeftRight;
		TMannequinAutoInit<int,-1> Wpn_Melee_RightLeft;
		TMannequinAutoInit<int,-1> Wpn_Melee_Out_LeftRight;
		TMannequinAutoInit<int,-1> Wpn_Melee_Out_RightLeft;
		TMannequinAutoInit<int,-1> Wpn_Melee_Fatality_Generic;
		TMannequinAutoInit<int,-1> Wpn_FireMode;
		TMannequinAutoInit<int,-1> unholster_select;
		TMannequinAutoInit<int,-1> Wpn_Select;
		TMannequinAutoInit<int,-1> Wpn_Unselect;
		TMannequinAutoInit<int,-1> Wpn_Pickup;
		TMannequinAutoInit<int,-1> unprime;
		TMannequinAutoInit<int,-1> cock;
		TMannequinAutoInit<int,-1> Wpn_OutOfAmmo;
		TMannequinAutoInit<int,-1> Wpn_Fire_In;
		TMannequinAutoInit<int,-1> fire_cock;
		TMannequinAutoInit<int,-1> Sfx_Fire_LastBullet;
		TMannequinAutoInit<int,-1> Wpn_Fire_Out;
		TMannequinAutoInit<int,-1> spin_up;
		TMannequinAutoInit<int,-1> spin_down;
		TMannequinAutoInit<int,-1> spin_down_tail;
		TMannequinAutoInit<int,-1> charge;
		TMannequinAutoInit<int,-1> uncharge;
		TMannequinAutoInit<int,-1> Wpn_ChargeUp;
		TMannequinAutoInit<int,-1> Wpn_Fire;
		TMannequinAutoInit<int,-1> Wpn_Malfunction;
		TMannequinAutoInit<int,-1> Wpn_Emp;
		TMannequinAutoInit<int,-1> Wpn_ChargeDown;
		TMannequinAutoInit<int,-1> hold;
		TMannequinAutoInit<int,-1> prime;
		TMannequinAutoInit<int,-1> primed_loop;
		TMannequinAutoInit<int,-1> Throw;
		TMannequinAutoInit<int,-1> Wpn_Idle;
		TMannequinAutoInit<int,-1> Wpn_Throw;
		TMannequinAutoInit<int,-1> Wpn_Throw_Cancel;
		TMannequinAutoInit<int,-1> Wpn_Throw_Idle;
		TMannequinAutoInit<int,-1> Wpn_Throw_In;
		TMannequinAutoInit<int,-1> Wpn_Throw_Out;
		TMannequinAutoInit<int,-1> Wpn_Deploy;
		TMannequinAutoInit<int,-1> Wpn_Deploy_Ready_Idle;
		TMannequinAutoInit<int,-1> Wpn_Deploy_Ready_In;
		TMannequinAutoInit<int,-1> Wpn_Deploy_Ready_Out;
		TMannequinAutoInit<int,-1> fromPlant;
		TMannequinAutoInit<int,-1> plant;
		TMannequinAutoInit<int,-1> intoPlant;
		TMannequinAutoInit<int,-1> rip_off;
		TMannequinAutoInit<int,-1> Wpn_Modify;
		TMannequinAutoInit<int,-1> Wpn_Modify_Out;
		TMannequinAutoInit<int,-1> destroy;
		TMannequinAutoInit<int,-1> Sfx_Pick;
		TMannequinAutoInit<int,-1> Sfx_Pick_Ammo;
		TMannequinAutoInit<int,-1> friendly_enter;
		TMannequinAutoInit<int,-1> friendly_leave;
		TMannequinAutoInit<int,-1> weapon_lower_enter;
		TMannequinAutoInit<int,-1> weapon_lower_leave;
		TMannequinAutoInit<int,-1> meleeReaction;
		TMannequinAutoInit<int,-1> Wpn_Reload_In;
		TMannequinAutoInit<int,-1> Wpn_Reload;
		TMannequinAutoInit<int,-1> idle_lastGrenade;
		TMannequinAutoInit<int,-1> use_light;
		TMannequinAutoInit<int,-1> turret;
		TMannequinAutoInit<int,-1> cannon;
		TMannequinAutoInit<int,-1> lock;
		TMannequinAutoInit<int,-1> activate;
		TMannequinAutoInit<int,-1> deactivate;
		TMannequinAutoInit<int,-1> drop;
		TMannequinAutoInit<int,-1> Sfx_Zoom_In;
		TMannequinAutoInit<int,-1> Sfx_Zoom_Out;
		TMannequinAutoInit<int,-1> Wpn_Fire_Cancel;
		TMannequinAutoInit<int,-1> barrel_spin;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinItemParams::FragmentIDs* const _this, const CTagDefinition& tagDefs)>(0x172BCF0);
	};

	// SMannequinItemParams::TagIDs
	// Header:  Prey/GameDll/itemanimation.h
	struct TagIDs
	{ // Size=12 (0xC)
		TMannequinAutoInit<int,-1> shoulder;
		TMannequinAutoInit<int,-1> weaponMounted;
		TMannequinAutoInit<int,-1> weaponDetached;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	// SMannequinItemParams::TagGroupIDs
	// Header:  Prey/GameDll/itemanimation.h
	struct TagGroupIDs
	{ // Size=16 (0x10)
		TMannequinAutoInit<int,-1> scope_attachment;
		TMannequinAutoInit<int,-1> barrel_attachment;
		TMannequinAutoInit<int,-1> underbarrel_attachment;
		TMannequinAutoInit<int,-1> mountedWeapons;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	// SMannequinItemParams::ContextIDs
	// Header:  Prey/GameDll/itemanimation.h
	struct ContextIDs
	{ // Size=12 (0xC)
		TMannequinAutoInit<int,-1> Weapon;
		TMannequinAutoInit<int,-1> attachment_top;
		TMannequinAutoInit<int,-1> attachment_bottom;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	// SMannequinItemParams::Fragments
	// Header:  Prey/GameDll/itemanimation.h
	struct Fragments
	{ // Size=32 (0x20)
		// SMannequinItemParams::Fragments::SSelect
		// Header:  Prey/GameDll/itemanimation.h
		struct SSelect
		{ // Size=32 (0x20)
			// SMannequinItemParams::Fragments::SSelect::FragmentTagIDs
			// Header:  Prey/GameDll/itemanimation.h
			struct FragmentTagIDs
			{ // Size=20 (0x14)
				TMannequinAutoInit<int,-1> special_first;
				TMannequinAutoInit<int,-1> first;
				TMannequinAutoInit<int,-1> fast_select;
				TMannequinAutoInit<int,-1> primary;
				TMannequinAutoInit<int,-1> secondary;

				void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

				static inline auto FInit = PreyFunction<void(SMannequinItemParams::Fragments::SSelect::FragmentTagIDs* const _this, const CTagDefinition& tagDefs)>(0x172DC10);
			};

			TMannequinAutoInit<int,-1> fragmentID;
			SMannequinItemParams::Fragments::SSelect::FragmentTagIDs fragmentTagIDs;
			const CTagDefinition* pTagDefinition;

		#if 0
			SSelect();
			void Init(const SControllerDef& _arg0_);
		#endif
		};

		SMannequinItemParams::Fragments::SSelect Select;

	#if 0
		void Init(const SControllerDef& _arg0_);
	#endif
	};

	SMannequinItemParams::FragmentIDs fragmentIDs;
	SMannequinItemParams::TagIDs tagIDs;
	SMannequinItemParams::TagGroupIDs tagGroupIDs;
	SMannequinItemParams::ContextIDs contextIDs;
	SMannequinItemParams::Fragments fragments;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinItemParams* const _this, const SControllerDef& controllerDef)>(0x172DDA0);
};
#endif // MOONCRASH
