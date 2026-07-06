// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequinUserParams.h>
#include <_unknown/TMannequinAutoInit.h>

class CTagDefinition;
struct SControllerDef;

// SMannequinPlayerParams
// Header:  Prey/GameDll/playeranimation.h
struct SMannequinPlayerParams : public IMannequinUserParams
{ // Size=432 (0x1B0)
	// SMannequinPlayerParams::FragmentIDs
	// Header:  Prey/GameDll/playeranimation.h
	struct FragmentIDs
	{ // Size=120 (0x78)
		TMannequinAutoInit<int,-1> Motion_Idle;
		TMannequinAutoInit<int,-1> Motion_Turn;
		TMannequinAutoInit<int,-1> Motion_Movement;
		TMannequinAutoInit<int,-1> Motion_Jump;
		TMannequinAutoInit<int,-1> Motion_InAir;
		TMannequinAutoInit<int,-1> Motion_Mounted;
		TMannequinAutoInit<int,-1> Fp_None;
		TMannequinAutoInit<int,-1> Fp_Sway;
		TMannequinAutoInit<int,-1> Fp_Idle;
		TMannequinAutoInit<int,-1> Fp_Movement;
		TMannequinAutoInit<int,-1> Fp_Land;
		TMannequinAutoInit<int,-1> Pose_AimPoses;
		TMannequinAutoInit<int,-1> Pose_IdlePose;
		TMannequinAutoInit<int,-1> Ledge_Grab;
		TMannequinAutoInit<int,-1> Ladder_Climb;
		TMannequinAutoInit<int,-1> Ladder_In;
		TMannequinAutoInit<int,-1> Ladder_Out;
		TMannequinAutoInit<int,-1> idle;
		TMannequinAutoInit<int,-1> idle_break;
		TMannequinAutoInit<int,-1> Motion_Slide;
		TMannequinAutoInit<int,-1> slidingKick;
		TMannequinAutoInit<int,-1> Fp_Bump;
		TMannequinAutoInit<int,-1> interact;
		TMannequinAutoInit<int,-1> Wpn_Melee;
		TMannequinAutoInit<int,-1> melee_multipart;
		TMannequinAutoInit<int,-1> melee_weapon;
		TMannequinAutoInit<int,-1> melee_interact;
		TMannequinAutoInit<int,-1> Reaction_Death;
		TMannequinAutoInit<int,-1> Anim_FullBodyControlled;
		TMannequinAutoInit<int,-1> weaponPose;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::FragmentIDs* const _this, const CTagDefinition& tagDefs)>(0x18D1030);
	};

	// SMannequinPlayerParams::TagIDs
	// Header:  Prey/GameDll/playeranimation.h
	struct TagIDs
	{ // Size=88 (0x58)
		TMannequinAutoInit<int,-1> zerog;
		TMannequinAutoInit<int,-1> sneak;
		TMannequinAutoInit<int,-1> swim;
		TMannequinAutoInit<int,-1> underwater;
		TMannequinAutoInit<int,-1> jump;
		TMannequinAutoInit<int,-1> move;
		TMannequinAutoInit<int,-1> sprint;
		TMannequinAutoInit<int,-1> outOfAmmo;
		TMannequinAutoInit<int,-1> aiming;
		TMannequinAutoInit<int,-1> forward;
		TMannequinAutoInit<int,-1> backward;
		TMannequinAutoInit<int,-1> left;
		TMannequinAutoInit<int,-1> right;
		TMannequinAutoInit<int,-1> nw;
		TMannequinAutoInit<int,-1> MP;
		TMannequinAutoInit<int,-1> SP;
		TMannequinAutoInit<int,-1> FP;
		TMannequinAutoInit<int,-1> localClient;
		TMannequinAutoInit<int,-1> throwing;
		TMannequinAutoInit<int,-1> slaveHuman;
		TMannequinAutoInit<int,-1> BowPrime;
		TMannequinAutoInit<int,-1> slide;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::TagIDs* const _this, const CTagDefinition& tagDefs)>(0x18D22C0);
	};

	// SMannequinPlayerParams::TagGroupIDs
	// Header:  Prey/GameDll/playeranimation.h
	struct TagGroupIDs
	{ // Size=52 (0x34)
		TMannequinAutoInit<int,-1> stance;
		TMannequinAutoInit<int,-1> weaponType;
		TMannequinAutoInit<int,-1> item;
		TMannequinAutoInit<int,-1> zoom;
		TMannequinAutoInit<int,-1> firemode;
		TMannequinAutoInit<int,-1> moveDir;
		TMannequinAutoInit<int,-1> moveSpeed;
		TMannequinAutoInit<int,-1> scope_attachment;
		TMannequinAutoInit<int,-1> barrel_attachment;
		TMannequinAutoInit<int,-1> underbarrel_attachment;
		TMannequinAutoInit<int,-1> melee_type;
		TMannequinAutoInit<int,-1> playMode;
		TMannequinAutoInit<int,-1> mp_enviro;

	#if 0
		void Init(const CTagDefinition& _arg0_);
	#endif
	};

	// SMannequinPlayerParams::ScopeIDs
	// Header:  Prey/GameDll/playeranimation.h
	struct ScopeIDs
	{ // Size=40 (0x28)
		TMannequinAutoInit<int,-1> FullBody1P;
		TMannequinAutoInit<int,-1> FullBody3P;
		TMannequinAutoInit<int,-1> Motion1P;
		TMannequinAutoInit<int,-1> AimPose;
		TMannequinAutoInit<int,-1> Torso1P;
		TMannequinAutoInit<int,-1> Torso3P;
		TMannequinAutoInit<int,-1> Weapon;
		TMannequinAutoInit<int,-1> AttachmentBottom;
		TMannequinAutoInit<int,-1> SlaveChar;
		TMannequinAutoInit<int,-1> SlaveObject;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::ScopeIDs* const _this, const CTagDefinition& tagDefs)>(0x18D1BC0);
	};

	// SMannequinPlayerParams::ContextIDs
	// Header:  Prey/GameDll/playeranimation.h
	struct ContextIDs
	{ // Size=28 (0x1C)
		TMannequinAutoInit<int,-1> Char1P;
		TMannequinAutoInit<int,-1> Char3P;
		TMannequinAutoInit<int,-1> Weapon;
		TMannequinAutoInit<int,-1> attachment_top;
		TMannequinAutoInit<int,-1> attachment_bottom;
		TMannequinAutoInit<int,-1> SlaveChar;
		TMannequinAutoInit<int,-1> SlaveObject;

		void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

		static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::ContextIDs* const _this, const CTagDefinition& tagDefs)>(0x18D0E10);
	};

	// SMannequinPlayerParams::Fragments
	// Header:  Prey/GameDll/playeranimation.h
	struct Fragments
	{ // Size=96 (0x60)
		// SMannequinPlayerParams::Fragments::Smelee
		// Header:  Prey/GameDll/playeranimation.h
		struct Smelee
		{ // Size=16 (0x10)
			// SMannequinPlayerParams::Fragments::Smelee::FragmentTagIDs
			// Header:  Prey/GameDll/playeranimation.h
			struct FragmentTagIDs
			{ // Size=4 (0x4)
				TMannequinAutoInit<int,-1> secondSwing;

			#if 0
				void Init(const CTagDefinition& _arg0_);
			#endif
			};

			TMannequinAutoInit<int,-1> fragmentID;
			SMannequinPlayerParams::Fragments::Smelee::FragmentTagIDs fragmentTagIDs;
			const CTagDefinition* pTagDefinition;

			void Init(const SControllerDef& controllerDef) { FInit(this, controllerDef); }

		#if 0
			Smelee();
		#endif

			static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::Fragments::Smelee* const _this, const SControllerDef& controllerDef)>(0x18D1EB0);
		};

		// SMannequinPlayerParams::Fragments::Smelee_multipart
		// Header:  Prey/GameDll/playeranimation.h
		struct Smelee_multipart
		{ // Size=24 (0x18)
			// SMannequinPlayerParams::Fragments::Smelee_multipart::FragmentTagIDs
			// Header:  Prey/GameDll/playeranimation.h
			struct FragmentTagIDs
			{ // Size=12 (0xC)
				TMannequinAutoInit<int,-1> into;
				TMannequinAutoInit<int,-1> Sfx_Hit;
				TMannequinAutoInit<int,-1> miss;

			#if 0
				void Init(const CTagDefinition& _arg0_);
			#endif
			};

			TMannequinAutoInit<int,-1> fragmentID;
			SMannequinPlayerParams::Fragments::Smelee_multipart::FragmentTagIDs fragmentTagIDs;
			const CTagDefinition* pTagDefinition;

			void Init(const SControllerDef& controllerDef) { FInit(this, controllerDef); }

		#if 0
			Smelee_multipart();
		#endif

			static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::Fragments::Smelee_multipart* const _this, const SControllerDef& controllerDef)>(0x18D2070);
		};

		// SMannequinPlayerParams::Fragments::SLedge_Grab
		// Header:  Prey/GameDll/playeranimation.h
		struct SLedge_Grab
		{ // Size=56 (0x38)
			// SMannequinPlayerParams::Fragments::SLedge_Grab::FragmentTagIDs
			// Header:  Prey/GameDll/playeranimation.h
			struct FragmentTagIDs
			{ // Size=44 (0x2C)
				TMannequinAutoInit<int,-1> floor;
				TMannequinAutoInit<int,-1> fall;
				TMannequinAutoInit<int,-1> ledge;
				TMannequinAutoInit<int,-1> vault;
				TMannequinAutoInit<int,-1> quick;
				TMannequinAutoInit<int,-1> up;
				TMannequinAutoInit<int,-1> over;
				TMannequinAutoInit<int,-1> drop;
				TMannequinAutoInit<int,-1> endCrouched;
				TMannequinAutoInit<int,-1> floorSprint;
				TMannequinAutoInit<int,-1> high;

				void Init(const CTagDefinition& tagDefs) { FInit(this, tagDefs); }

				static inline auto FInit = PreyFunction<void(SMannequinPlayerParams::Fragments::SLedge_Grab::FragmentTagIDs* const _this, const CTagDefinition& tagDefs)>(0x18D1890);
			};

			TMannequinAutoInit<int,-1> fragmentID;
			SMannequinPlayerParams::Fragments::SLedge_Grab::FragmentTagIDs fragmentTagIDs;
			const CTagDefinition* pTagDefinition;

		#if 0
			SLedge_Grab();
			void Init(const SControllerDef& _arg0_);
		#endif
		};

		SMannequinPlayerParams::Fragments::Smelee melee;
		SMannequinPlayerParams::Fragments::Smelee_multipart melee_multipart;
		SMannequinPlayerParams::Fragments::SLedge_Grab Ledge_Grab;

	#if 0
		void Init(const SControllerDef& _arg0_);
	#endif
	};

	SMannequinPlayerParams::FragmentIDs fragmentIDs;
	SMannequinPlayerParams::TagIDs tagIDs;
	SMannequinPlayerParams::TagGroupIDs tagGroupIDs;
	SMannequinPlayerParams::ScopeIDs scopeIDs;
	SMannequinPlayerParams::ContextIDs contextIDs;
	SMannequinPlayerParams::Fragments fragments;

	virtual void Init(const SControllerDef& controllerDef);

	static inline auto FInit = PreyFunction<void(SMannequinPlayerParams* const _this, const SControllerDef& controllerDef)>(0x18D0700);
};
#endif // MOONCRASH
