#pragma once


#include <set>

#include "ArkBasicTypes.h"
#include "EArk.h"
// #include "Header.h"
	// Created with ReClass.NET 1.2 by KN4CK3R

class IEntityClass;
//ArkGame * getArkGame(void)
	// CGame* (18)0x2c09010
	// GEnv		  0x22418c0
class CGame;
class IEntitySystem;
class CEntitySystem;
class staticObjectPointers {
public:
	// typedef CGame* _g_pGame;
	 // _g_pGame g_pGame;
	class _gEnv {
	public:
		void* pDialogSystem		   ;
		void * p3DEngine	       ;
		void *pNetwork			   ;
		void* IOnline			   ;
		void *pLobby			   ;
		void *pArkRewardSystem	   ;
		void *pArkEntitlementSystem;
		void *pArkDlcSystem		   ;
		void *pScriptSystem		   ;
		void *pPhysicalWorld	   ;
		void *pFlowSystem		   ;
		void *pInput			   ;
		void *pStatoscope		   ;
		void *pCryPak			   ;
		void* pFileChangeMonitor   ;
		void* pProfileLogSystem	   ;
		void *pParticleManager	   ;
		void *pOpticsManager	   ;
		void *pFrameProfileSystem  ;
		void *pTimer			   ;
		void *pCryFont			   ;
		CGame*pGame				   ;
		void *pLocalMemoryUsage	   ;
		CEntitySystem*pEntitySystem;
		void *pConsole			   ;
		void *pAudioSystem		   ;
		void *pSystem			   ;
		void *pCharacterManager	   ;
		void *pAISystem			   ;
		void *pLog				   ;
		void *pMovieSystem		   ;
		void *pNameTable		   ;
		void *pRenderer			   ;
		void *pAuxGeomRenderer	   ;
		void *pHardwareMouse	   ;
	};
	 _gEnv * gEnvPtr;
	 _gEnv gEnv;
	staticObjectPointers(uintptr_t moduleBase);

};
 


namespace ArkNpc {
	class ArkRobotLight;
	class ArkNpc;
}

	enum class  CinematicMode : int32_t {
		 off = 0,
		 allowLook = 1,
		 complete = 2
	 } ;

	enum class  Mode : int32_t {
		 player = 0,
		 world_ui_examination = 1,
		 examination = 2,
		 menu = 3,
		 flycam = 4,
		 focusmode = 5,
		 ether_duplicate = 6,
		 hacking = 7,
		 psi_scanning_fanfare = 8,
		 mimic_grab = 9,
		 _count = 10
	 } ;



	enum class  ExamineMode : int32_t {
		 Normal = 0,
		 RemoteManipulation = 1,
		 Forced = 2
	 } ;
	

	
	enum class ArkMaterialAnimationChannel : int8_t
	{
		none = 0,
	};
	enum class EMaterialParamFloat : int32_t
	{
		none = 0,
		other = 3,
		telescope = 2,
		worldUI = 1
	};
	enum class EMaterialParamVec3 : int32_t
	{
		none = 0,
		other = 3,
		telescope = 2,
		worldUI = 1
	};
	enum class enumArkMaterialAnimationType : int32_t
	{
		none = 0,
	};
	

	enum class enumEPlayerSex : int32_t
	{
		none = 0
	};
	


	

	

	enum class EStance : int32_t{
		STANCE_UNLOCKED = -2,
		STANCE_NULL = -1,
		STANCE_STAND = 0,
		STANCE_SNEAK = 1,
		STANCE_CRAWL = 2,
		STANCE_SMOKE = 3,
		STANCE_PRONE = 4,
		STANCE_RELAXED = 5,
		STANCE_STEALTH = 6,
		STANCE_ALERTED = 7,
		STANCE_SWIM = 8,
		STANCE_ZEROG = 9,
		STANCE_HOVER = 10,
		STANCE_CORRUPTED = 11,
		STANCE_INVESTIGATE_ANOMALY = 12,
		STANCE_INVESTIGATE_DANGER = 13,
		STANCE_INVESTIGATE_VISION = 14,
		STANCE_HUNT = 15,
		STANCE_GUNUP = 16,
		STANCE_CHARGE = 17,
		STANCE_LAST = 18
	} ;

	
	

	

	enum class EQueuedDialog : int32_t
	{
		TODO = 0
	};

	enum class InventorySort : int32_t
	{
		TODO = 0
	};



	class StagingInfo
	{
	public:
		Vec3 m_rotation; //0x0000
		float m_yaw; //0x000C
		float m_pitch; //0x0010
	}; //Size: 0x0014
	class ClimbPosInfo
	{
	public:
		Vec3 m_point; //0x0000
		EStance m_stance; //0x000C
	}; //Size: 0x0010
	class IAnimatedCharacter
	{
	public:
		char pad_0000[64]; //0x0000
	}; //Size: 0x0040
	class ArkPlayerMovementFSM
	{
	public:
		char pad_0000[1472]; //0x0000
		ClimbPosInfo m_climbPosInfo; //0x05C0
		class StagingInfo m_stagingInfo; //0x05D4
		EArkFlyMode m_flyMode; //0x05E8
		float m_carrySpeedScale; //0x05EC
		float m_climbHorizontalFromEdgeProbeDistance; //0x05F0
		float m_climbVerticalReachDistance; //0x05F4
		float m_climbVerticalNormalMaxAngle; //0x05F8
		float m_cameraRoll; //0x05FC
		float m_cameraRollMaxAngle; //0x0600
		float m_cameraRollIncreaseSpeed; //0x0604
		float m_cameraRollRecoverySpeed; //0x0608
		float m_airControl; //0x060C
		bool m_bInputSneak; //0x0610
		bool m_bInputJumpPressed; //0x0611
		bool m_bInputJumpRequested; //0x0612
		bool m_bMovementRestricted; //0x0613
		float m_verticalSpeed; //0x0614
		float m_jumpRequestedTime; //0x0618
		char pad_061C[4]; //0x061C
	}; //Size: 0x0620

	class ArkPlayerComponent
	{
	public:
		void* m_pPsiComponent; //0x0000
		void* m_pAbilityComponent; //0x0008
		void* m_pAudioLogComponent; //0x0010
		void* m_pNoteComponent; //0x0018
		void* m_pKeyCodeComponent; //0x0020
		void* m_pLocationComponent; //0x0028
		void* m_pLoreComponent; //0x0030
		void* m_pKeyCardComponent; //0x0038
		void* m_pEmailComponent; //0x0040
		void* m_pQuickSelectComponent; //0x0048
		void* m_pRosterComponent; //0x0050
		void* m_pUtilityComponent; //0x0058
		void* m_pPharmaComponent; //0x0060
		void* m_pPDAComponent; //0x0068
		void* m_pAchievementComponent; //0x0070
		void* m_pAwarenessComponent; //0x0078
		void* m_pEntitlementComponent; //0x0080
		void* m_pFatigueComponent; //0x0088
		void* m_pHealthComponent; //0x0090
		void* m_pRadiationComponent; //0x0098
		void* m_pLightManager; //0x00A0
		void* m_pFXComponent; //0x00A8
		void* m_pUIComponent; //0x00B0
		void* m_pFabricationPlanComponent; //0x00B8
		void* m_pStatusComponent; //0x00C0
		void* m_pPropulsionComponent; //0x00C8
		void* m_pSignalReceiver; //0x00D0
		void* m_pAimAssistComponent; //0x00D8
		void* m_pMarkedEnemyComponent; //0x00E0
		void* m_pScopeComponent; //0x00E8
		void* m_pPlayerSpeaker; //0x00F0
		void* m_pSuitSpeaker; //0x00F8
		void* m_pDiscRifleSpeaker; //0x0100
		void* m_pTranscribeSpeaker; //0x0108
		void* m_pGameMetricsComponent; //0x0110
		void* m_pFocusModeComponent; //0x0118
		void* m_pLiveTranscribeComponent; //0x0120
		void* m_pStationAccessComponent; //0x0128
		void* m_pPOIComponent; //0x0130
		float m_fShadowDissolveBlend; //0x0138
		float m_fShadowDissolveTarget; //0x013C
		float m_fShadowDissolveTimeScale; //0x0140
		int8_t m_bItemsRestricted; //0x0144
		int8_t m_bMarkerTextDisplayed; //0x0145
		char pad_0146[2]; //0x0146
	}; //Size: 0x0148

		class ArkStatModifier {
		public:
			CCryName m_StatName;
			float m_Modifier;
		};

		class ArkStatModifierPackage {
		public:
			unsigned __int64 m_ID;
			CCryName m_name;
			std::vector<ArkStatModifier> m_Modifiers;
		};

		class ArkStatModifierPackages
		{
		public:
			std::vector<ArkStatModifierPackage> m_Packages;
		}; //Size: 0x0018

		class ArkModifier {
		public:
			uint32_t m_id;
			float m_value;
		};

		class ArkStat {
		public:
			float m_baseValue;
			float m_currentValue;
			std::vector<ArkModifier> m_modifiers;
		};
		class ArkStatsComponent
		{
		public:
			uint32_t m_ownerId; //0x0000
			uint32_t m_currentId; //0x0004
			char pad2[64];
			//std::unordered_map<CCryName, ArkStat, std::hash<CCryName>, std::equal_to<CCryName>> m_stats; //0x0008
			ArkStatModifierPackages m_packagesDesc; //0x0048
			char pad[64];
			//std::unordered_map<unsigned int, std::vector<unsigned int> m_activePackages; //0x0060
		}; //Size: 0x00A0


	

	class ArkEquipmentModComponent
	{
	public:
		bool m_bSuitMods; //0x0000
		char pad_0001[7]; //0x0001
		std::vector<uint32_t> m_ownedChipsets; //0x0008
		int32_t m_installedChipsets[8]; //0x0020
	}; //Size: 0x0040


	class TActionHandler
	{
	public:
		char pad_0000[16]; //0x0000
	}; //Size: 0x0010

	class MovementButtonPressInfo
	{
	public:
		bool bForward; //0x0000
		bool bBack; //0x0001
		bool bLeft; //0x0002
		bool bRight; //0x0003
	}; //Size: 0x0004

	class ModeAndHandle {
		Mode m_mode;
		uint32_t m_handle;
	};
	class ArkPlayerInput
	{
	public:
		char pad_0000[16]; //0x0000
		std::vector<ModeAndHandle> m_modeStack; //0x0010
		class TActionHandler m_actionHandler; //0x0028
		Vec3 m_deltaRotation; //0x0038
		Vec3 m_gamePadRotation; //0x0044
		Vec3 m_adjustedGamePadRotation; //0x0050
		Vec2 m_movement; //0x005C
		Vec2 m_reticleMovement; //0x0064
		class MovementButtonPressInfo m_movementButtonPressInfo; //0x006C
		void* m_player; //0x0070
		float m_debugTimeScale; //0x0078
		float m_lean; //0x007C
		float m_rawLean; //0x0080
		float m_lastRegisteredInputTime; //0x0084
		float m_currentGamePadRotationSpeed; //0x0088
		int32_t m_mashesRemaining; //0x008C
		int32_t m_mimicGrabMashesRequired; //0x0090
		CinematicMode m_cinematicMode; //0x0094
		float m_sprintCameraRotationRateScale; //0x0098
		float m_zoomCameraRotationRateScale; //0x009C
		float m_sprintCancelForwardThreshold; //0x00A0
		float m_sprintCancelBackwardThreshold; //0x00A4
		float m_sprintCancelStrafeThreshold; //0x00A8
		bool m_bSprint; //0x00AC
		bool m_bUseHeld; //0x00AD
		bool m_bTriggeredUse; //0x00AE
		bool m_bTriggeredHoldUse; //0x00AF
		bool m_bTriggeredSpecialUse; //0x00B0
		bool m_bZeroGBraking; //0x00B1
		bool m_bSprintInhibited; //0x00B2
		bool m_bJumpInhibited; //0x00B3
		bool m_bRotationInhibited; //0x00B4
		bool m_bLeftLean; //0x00B5
		bool m_bRightLean; //0x00B6
		char pad_00B7[1]; //0x00B7
		float m_deadzone; //0x00B8
		float m_curvePercentTurnSpeed; //0x00BC
		float m_accelerationThreshold; //0x00C0
		float m_accelerationRate; //0x00C4
		float m_accelerationMaxTurnSpeed; //0x00C8
		Mode m_disabledMode; //0x00CC
	}; //Size: 0x00D0


	class ArkInputAction {
	public:
		CCryName m_Action;
		CryStringT<char> m_ActionMap;
	};
	class ArkInputLegendItem {
	public:
		CCryName m_Action;
		CryStringT<char> m_ActionMap;
		CryStringT<char> m_Label;
		bool m_Hold;
		CryStringT<char> m_ComboString;
		std::vector<ArkInputAction> m_ActionList;
		EArkLegendControlScheme m_ControlScheme;
		bool m_enabled;
		CryStringT<wchar_t> m_localizedLabel;
		
	};
	

	class ArkInputLegend
	{
	public:
		CryStringT<char> m_actionMap;
		std::vector<ArkInputLegendItem> m_Items; //0x0008
	}; //Size: 0x0020

	class ArkInputLegendHandler
	{
	public:
		uint32_t m_handle; //0x0000
	}; //Size: 0x0004

	class ArkExaminationMode
	{
	public:
		char pad_0000[24]; //0x0000
		Vec4 m_initialRotation; //0x0018
		Vec3 m_playerCameraPosition; //0x0028
		Vec4 m_playerCameraRotation; //0x0034
		Vec3 m_localRotation; //0x0044
		Vec4 m_rotation; //0x0050
		Vec2 m_reticlePos; //0x0060
		Vec3 m_optimalCameraPos; //0x0068
		float m_cameraLerpStartTime; //0x0074
		float m_activeLerpDuration; //0x0078
		float m_viewingBuffer; //0x007C
		float m_maxCameraRotation; //0x0080
		float m_cameraSpeedMultiplier; //0x0084
		float m_cameraLerpDuration; //0x0088
		float m_telescopeLerpDuration; //0x008C
		float m_distFromNonWorldUI; //0x0090
		EArkExaminationType m_examinationType; //0x0094
		EArkExaminationState m_examinationState; //0x0098
		uint32_t m_targetEntity; //0x009C
		int32_t m_inputHandle; //0x00A0
		int32_t m_zoomHandle; //0x00A4
		ExamineMode m_mode; //0x00A8
		char pad_00AC[4]; //0x00AC
		class ArkInputLegend m_inputLegendWorldUI; //0x00B0
		class ArkInputLegend m_inputLegendDefault; //0x00D0
		class ArkInputLegend m_inputLegendTelescope; //0x00F0
		class ArkInputLegendHandler m_examinationLegendHandler; //0x0110
		char pad_0114[4]; //0x0114
	}; //Size: 0x0118

	class ArkEntityGrabber
	{
	public:
		float m_breakDistanceSq; //0x0000
		float m_lastDesiredLerpVelocity; //0x0004
		float m_timeUnderDesiredLerpVelocity; //0x0008
		float m_totalDistanceForLerp; //0x000C
		float m_lerpSpeed; //0x0010
		float m_lerpObstructedSpeed; //0x0014
		float m_lerpAcceleration; //0x0018
		float m_lerpObstructedAcceleration; //0x001C
		float m_maxTimeAllowedUnderDesiredLerpVelocity; //0x0020
		bool m_bConstrained; //0x0024
		char pad_0025[3]; //0x0025
	}; //Size: 0x0028

	class ArkSimpleTimer
	{
	public:
		char pad_0000[4]; //0x0000
		float N0000235D; //0x0004
	}; //Size: 0x0008

	class ArkAudioTrigger
	{
	public:
		char pad_0000[4]; //0x0000
	}; //Size: 0x0004


	class ArkPlayerCarry
	{
	public:
		char pad_0000[16]; //0x0000
		class ArkInputLegend m_carryLegend; //0x0010
		class ArkInputLegendHandler m_carryLegendHandler; //0x0030
		class ArkSimpleTimer m_collisionRestoreTimer; //0x0034
		class ArkEntityGrabber m_grabber; //0x003C
		class ArkAudioTrigger m_throwAudio; //0x0064
		class std::vector<CryStringT<char>> m_dragCorpseJointNames; //0x0068
		float m_throwKickBacks[4]; //0x0080
		float m_leverageHoldDurations[4]; //0x0090
		Vec4 m_pickupEntityOriginalRotation; //0x00A0
		uint32_t m_pickedUpEntityId; //0x00B0
		int32_t m_pickedUpEntityConstraintId; //0x00B4
		float m_carryMaxPullForce; //0x00B8
		float m_carryMaxPullForceZeroG; //0x00BC
		float m_carryHeightOffset; //0x00C0
		float m_carryCameraRotationToEntityMinThreshold; //0x00C4
		float m_carryCameraRotationToEntityMaxThreshold; //0x00C8
		float m_carryObjectLengthRotationLimitScaleMin; //0x00CC
		float m_carryObjectLengthRotationLimitScaleMax; //0x00D0
		float m_carrySneakPitchLimit; //0x00D4
		float m_dragCorpseHeight; //0x00D8
		float m_dragCorpseDistance; //0x00DC
		float m_dragCorpseBreakDistanceSq; //0x00E0
		float m_dragCorpseSyncSpeed; //0x00E4
		float m_dragCorpseRemoteSyncSpeed; //0x00E8
		float m_opacity; //0x00EC
		int32_t m_dragCorpsePartId; //0x00F0
		int32_t m_attachedEmitterSlot; //0x00F4
		EStance m_dragCorpsePreviousStance; //0x00F8
		bool m_bThrowCarriedEntity; //0x00FC
		bool m_bCastSunShadow; //0x00FD
		bool m_bRemoteManipulatedCorpse; //0x00FE
		bool m_bJustThrown; //0x00FF
	}; //Size: 0x0100

	class ArkInteractionInfo
	{
	public:
		EArkInteractionType m_interactionType; //0x0000
		char pad_0004[4]; //0x0004
		class CryStringT<char> m_displayText; //0x0008
		float m_holdDuration; //0x0010
		char pad_0014[4]; //0x0014
	}; //Size: 0x0018

	class Map
	{
	public:
		char pad_0000[16]; //0x0000
	}; //Size: 0x0010

	class ArkPlayerTargetSelector
	{
	public:
		bool m_bDrawDebug; //0x0000
		bool m_bIsHoovering; //0x0001
		char pad_0002[2]; //0x0002
		float m_innerAimDistance; //0x0004
		float m_outerAimDistance; //0x0008
		float m_interactDistance; //0x000C
		float m_pickupTimerSec; //0x0010
		float m_pickupMaxCooldownSec; //0x0014
		float m_pickupInitialCooldownSec; //0x0018
		uint32_t m_forceSelectEntity; //0x001C
		char m_candidateTargets[3][8]; //0x0020
		std::map<unsigned __int64, float, std::less<unsigned __int64>> m_itemTypePriorityMap; //0x0038
	}; //Size: 0x0048

	

	class ArkButtonPrompt : public CCryName
	{
	public:
		class CryStringT<char> m_actionMap; //0x0008
		class ArkSimpleTimer m_holdTimer; //0x0010
		float m_baseHoldDuration; //0x0018
		bool m_bUseHoldTriggerDelay; //0x001C
		char pad_001D[3]; //0x001D
		wchar_t* m_inputPromptString; //0x0020
		wchar_t* m_promptText; //0x0028
		bool m_bEnabled; //0x0030
		bool m_bDirty; //0x0031
		char pad_0032[6]; //0x0032
	}; //Size: 0x0038



	class ArkExclusiveActionFilter
	{
	public:
		char pad_0000[16]; //0x0000
		bool m_bIgnoreActionMapState; //0x0010
		char pad_0011[7]; //0x0011
		class CryStringT<char> m_filterName; //0x0018
		class CryStringT<char> m_actionMap; //0x0020
		class std::vector<CCryName> m_filteredActionIds; //0x0028
		class std::vector<CCryName> m_allowedActionIds; //0x0040
	}; //Size: 0x0058

	class ArkButtonPromptCollection
	{
	public:
		char pad_0000[16]; //0x0000
		ArkButtonPrompt m_buttonPrompts[8]; //0x0010
		wchar_t b_maxUsed[1]; //0x01D0
		char pad_01D2[6]; //0x01D2
		CryStringT<char> m_formatFunction; //0x01D8
		CryStringT<char> m_setFunctionOrArrayName; //0x01E0
		ArkExclusiveActionFilter m_filter; //0x01E8
		bool N00002370; //0x0240
		char pad_0241[7]; //0x0241
	}; //Size: 0x0248

	class ArkInventoryPreview
	{
	public:
		char pad_0000[16]; //0x0000
		void* m_pInventory; //0x0010
		uint32_t m_interactionEntityId; //0x0018
		int32_t m_x; //0x001C
		int32_t m_y; //0x0020
		int32_t m_startingRow; //0x0024
		class ArkAudioTrigger m_lootItemTrigger; //0x0028
		class ArkAudioTrigger m_lootFailedTrigger; //0x002C
		class ArkAudioTrigger m_inventoryFullTrigger; //0x0030
		char pad_0034[4]; //0x0034
		class ArkButtonPromptCollection m_inputPrompts; //0x0038
		class ArkSimpleTimer m_errorTimer; //0x0280
	}; //Size: 0x0288

	class ArkPlayerInteraction : public ArkEntityGrabber
	{
	public:
		class ArkPlayerCarry m_playerCarry; //0x0028
		class ArkInteractionInfo m_interactionInfo[4]; //0x0128
		bool m_interactionHidden[4]; //0x0188
		char pad_018C[4]; //0x018C
		class ArkPlayerTargetSelector m_targetSelector; //0x0190
		class ArkInventoryPreview m_inventoryPreview; //0x01D8
		class ArkSimpleTimer m_carryDelay; //0x0460
		int32_t m_disableInteractionPromptCount; //0x0468
		uint32_t m_usableEntityId; //0x046C
		bool m_bCanClimb; //0x0470
		bool m_bHideFailedAbilityInteractions; //0x0471
		char pad_0472[6]; //0x0472
		class ArkButtonPromptCollection m_buttonPrompts; //0x0478
		class ArkInputLegend m_alternativePrompts; //0x06C0
		class ArkInputLegendHandler m_alternativePromptHandler; //0x06E0
		char pad_06E4[4]; //0x06E4
	}; //Size: 0x06E8

	class ArkGroundColliderComponent
	{
	public:
		void* m_pOwner; //0x0000
		uint32_t m_groundEntity; //0x0008
		char pad_000C[4]; //0x000C
	}; //Size: 0x0010

	class ArkPlayerLightEntity
	{
	public:
		char pad_0000[32]; //0x0000
		uint32_t m_attachmentEntity; //0x0020
		uint32_t m_lightEntity; //0x0024
		class CryStringT<char> m_archetypeName; //0x0028
		class CryStringT<char> m_attachmentName; //0x0030
	}; //Size: 0x0038


	class DimRange {
		float m_distanceSq;
		float m_diffuseMultiplier;
	};
	class ArkPlayerFlashlight
	{
	public:
		char pad_0000[16]; //0x0000
		class ArkPlayerLightEntity m_playerLight; //0x0010
		class ArkAudioTrigger m_toggleAudio; //0x0048
		char pad_004C[4]; //0x004C
		std::vector<DimRange> m_dimRanges; //0x0050
		float m_dimRangeDeltaRate; //0x0068
		float m_currentDimRangeDiffuse; //0x006C
		float m_drainRate; //0x0070
		float m_chargeRate; //0x0074
		float m_maxCharge; //0x0078
		float m_currentCharge; //0x007C
		float m_dimStart; //0x0080
		float m_minDimAmount; //0x0084
		bool m_bEnabled; //0x0088
		bool m_bShowingUI; //0x0089
		bool m_bFlashlightOn; //0x008A
		char pad_008B[5]; //0x008B
	}; //Size: 0x0090


	
	template<typename T> class TArkAudioSwitch
	{
	public:
		char pad_0000[4]; //0x0000
		class ArkAudioSwitchState m_states[2]; //0x0004
	}; //Size: 0x000C

	class ArkAudioRtpc
	{
	public:
		char pad_0000[4]; //0x0000
	}; //Size: 0x0004

	class ArkAudioSwitch
	{
	public:
		char pad_0000[4]; //0x0000
	}; //Size: 0x0004

	class ArkAudioSwitchState
	{
	public:
		uint32_t m_id; //0x0000
	}; //Size: 0x0004

	class ArkPlayerAudio
	{
	public:
		char pad_0000[8]; //0x0000
		TArkAudioSwitch<enumEPlayerSex> m_genderAudioSwitch; //0x0008
		ArkAudioRtpc m_combatIntensityRtpc; //0x0014
		ArkAudioRtpc m_jumpHeightRtpc; //0x0018
		ArkAudioSwitch m_combatAudioSwitch; //0x001C
		ArkAudioSwitchState m_combatOnAudioState; //0x0020
		ArkAudioSwitchState m_combatOffAudioState; //0x0024
		ArkAudioTrigger m_combatEndAudio; //0x0028
		ArkAudioTrigger m_setHelmetOnAtmosphere; //0x002C
		ArkAudioTrigger m_setHelmetOnNoAtmosphere; //0x0030
		ArkAudioTrigger m_setHelmetOffAtmosphere; //0x0034
		ArkAudioTrigger m_setHelmetOffNoAtmosphere; //0x0038
		ArkAudioTrigger m_helmetOn; //0x003C
		ArkAudioTrigger m_helmetOff; //0x0040
		float m_combatIntensity; //0x0044
		float m_combatIntensityEventStartThreshold; //0x0048
		float m_combatIntensityEventStopThreshold; //0x004C
	}; //Size: 0x0050

	class SViewParams {
	public:
		Vec3 position;
		Vec4 rotation;
		Vec4 localRotationLast;
		float nearplane;
		float fov;
		float fovBase;
		unsigned char viewID;
		bool groundOnly;
		float shakingRatio;
		Vec4 currentShakeQuat;
		Vec3 currentShakeShift;
		uint32_t idTarget;
		Vec3 targetPos;
		float frameTime;
		float angleVel;
		float vel;
		float dist;
		bool blend;
		char pad_07c[3];
		float blendPosSpeed;
		float blendRotSpeed;
		float blendFOVSpeed;
		Vec3 blendPosOffset;
		Vec4 blendRotOffset;
		float blendFOVOffset;
		bool justActivated;
		unsigned char viewIDLast;
		char pad_0ad[2];
		Vec3 positionLast;
		Vec4 rotationLast;
		float FOVLast;
	};
	

	class ArkPlayerCamera
	{
	public:
		class CryStringT<char> m_boneNames[17]; //0x0008
		char m_customUpdateFunction[64];
		char m_customOffsetFunction[64];
		char m_customViewFunction[64];
		// float m_customUpdateFunction(Vec4);
		// float m_customOffsetFunction(Vec3);
		// SViewParams& m_customViewFunction();
		Vec4 m_rotation; //0x0150
		Vec2 m_recoilStep; //0x0160
		float m_recoilTimeRemaining; //0x0168
		float m_recoilDelayRemaining; //0x016C
		float m_leanAmount; //0x0170
		float m_leanAngle; //0x0174
		float m_leanOffset; //0x0178
		float m_eyeOffset; //0x017C
		float m_transitionTime; //0x0180
		float m_transitionTimeRemain; //0x0184
		Vec4 m_transitionStartRot; //0x0188
		Vec3 m_deathPos; //0x0198
		Mode N00002ED5; //0x01A4
		float m_bRecycleGrenadeDeathSpeed; //0x01A8
		Vec3 m_nonLeaningTargetPosition; //0x01AC
		float m_FPIKWeight; //0x01B8
		float m_FPIKWeightTarget; //0x01BC
		float m_stanceChangeInterSpeed; //0x01C0
		char pad_01C4[4]; //0x01C4

		virtual void Function0();
		virtual void Function1();
		virtual void Function2();
		virtual void Function3();
		virtual void Function4();
		virtual void Function5();
		virtual void Function6();
		virtual void Function7();
		virtual void Function8();
		virtual void Function9();
	}; //Size: 0x01C8

	class ArkPlayerHelmet
	{
	public:
		void* ptr;
		Vec4 m_target; //0x0008
		void* m_pOxygenComponent; //0x0018
		Vec2 m_tolerance; //0x0020
		ArkSimpleTimer m_reactTimer; //0x0028
		uint64_t m_signalModifier; //0x0030
		float m_catchUpSpeed; //0x0038
		EQueuedDialog m_queuedDialog; //0x003C
		int32_t m_crackSubMatId; //0x0040
		bool m_bActive; //0x0044
		bool m_bPaused; //0x0045
		bool m_bNonReactActivated; //0x0046
		bool m_bCatchUp; //0x0047
		bool m_bConsideredCaughtUp; //0x0048
		char pad_0049[7]; //0x0049

	}; //Size: 0x0050

	class ArkTimeRemaining {
	public:
		float m_timeRemaining;
	};

	class ArkRegularOutcome {
	public:
		uint32_t m_data;
	};
	class IEntity {
	public:
		void* ptr;
	};
	class IAttachment {
	public:
		void* ptr;
	};

	// template<int,typename T> class SCRCRef {
	// 	uint32_t crc;
	// 	T* stringValue;
	// };
	// class SControllerDef {
	// 	
	// };
	class SAnimationContext {
		//TODO: SAnimationContext
	public:
		char pad[2544];
		// SControllerDef* controllerDef;
		// CTagState state;
		// char pad[8];
		// CMTRand_int32 randGenerator;
	};

	class IScope {
	public:
		void* ptr;
	};
	namespace IActions {
		enum class EStatus {
			None = 0,
			Pending = 1,
			Installed = 2,
			Exiting = 3,
			Finished = 4
		};
	}
	template<int32_t s> class STagState {
		unsigned char state[s];
	};
	class CMannequinParams {
		//TODO: CMannequinParams
		char pad[24];
	};
	class IAction {
		void* undefined;
		SAnimationContext* m_context;
		float m_activeTime;
		float m_queueTime;
		uint32_t m_forcedScopeMask;
		uint32_t m_installedScopeMask;
		int32_t m_subContext;
		int32_t priority;
		IActions::EStatus m_eStatus;
		uint32_t m_flags;
		IScope* m_rootScope;
		int32_t m_fragmentID;
		STagState<12> m_fragTags;
		uint32_t m_optionIdx;
		uint32_t m_userToken;
		int32_t m_refCount;
		float m_speedBias;
		float m_animWeight;
		char pad1[4];
		CMannequinParams m_mannequinParams;
		char pad2[8];
		//DynArray<_smart_ptr<IAction>, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc>>> m_slaveActions;

	};

	namespace EntityEffects {
		class SEffectInfo {
		public:
			uint32_t id;
			int32_t entityEffectSlot;
			int32_t characterEffectSlot;
			CSharedString helperName;
		};
	}


	class ArkWeaponMods {
	public:
		std::unordered_map<unsigned __int64, int32_t, std::hash<unsigned __int64>, std::equal_to<unsigned __int64>> m_weaponModIds;
	};
	class CEffectsController {
	public:
		IEntity* m_pOwnerEntity;
		std::vector<EntityEffects::SEffectInfo> m_attachedEffects;
		uint32_t m_effectGeneratorId;
	};

	class ArkEntityAttachmentEffect {
	public:
		char pad[64];
		CEffectsController* m_controller;
		CryStringT<char> m_attachmentName;
		uint32_t m_attachemtnSlot;
		uint32_t m_effectId;
	};

	class ArkMaterialParamOverride {
	public:
		CryStringT<char> m_paramName;
		float m_paramValue;
	};
	class IParticleEffect {
	public:
		void* ptr1;
		void* ptr2;
	};
	class IArkWeaponEventListener {
	public:
		void* ptr;
	};
	template<typename T, T val> class TMannequinAutoInit {
	public:
		T val;
	};
	class FragmentIDs {
	public:
		TMannequinAutoInit<int32_t, -1> LookBlink;
	};
	class IUIElement {
	public:
		void* ptr;
	};
	class SmartScriptTable {
	public:
		void* ptr;
	};
	class XmlNodeRef {
	public:
		void* ptr;
	};
	class CEntityArchetype {
	public:
		char pad[24];
		CryStringT<char> m_name;
		uint64_t m_id;
		SmartScriptTable m_pProperties;
		XmlNodeRef m_ObjectVars;
		IEntityClass* m_pClass;
	};
	class IEntityArchetype {
	public:
		CEntityArchetype* ptr;
		
	};
	class CArkWeapon {
	public:
		char pad1[416];
		ArkRegularOutcome m_criticalOutcome;
		char pad2[4];
		ArkStatsComponent m_statsComponent;
		ArkWeaponMods m_weaponMods;
		CEffectsController m_effectController;
		IAttachment* m_pAttachment;
		ArkSimpleTimer m_attackTimer;
		ArkSimpleTimer m_hudDamageIconTimer;
		bool m_bAmmoIsPooled;
		bool m_bIsAttacking;
		bool m_bWantsToAttack;
		bool m_bWantsToReload;
		char pad3[4];
		IAction* m_pWeaponIdleAction;
		IAction* m_pWeaponFireAction;
		CryStringT<char> m_pWeaponClassName;
		CryStringT<char> m_ammoArchetypeName;
		CryStringT<char> m_ammoSpawnPointName;
		CryStringT<char> m_uiElementName;
		uint32_t m_wepaonUIType;
		Vec3 m_defaultLightColor;
		Vec3 m_damagedLightColor;
		Vec3 m_brokenLightColor;
		bool m_bAutoload;
		bool m_bAllowInterruptReloading;
		bool m_bAffectedByDisruption;
		bool m_bTakesHazardDamage;
		float m_idleBreakDelayTime;
		float m_ironsightsTargetDistance;
		float m_ironsightsTargetWidth;
		float m_ironsightsTargetSpeed;
		float m_ironsightsMaxAngularVelocity;
		float m_ironsightsSuccessDistance;
		float m_aimAssistRangeMax;
		float m_ammoLootImpulse;
		float m_condition;
		float m_malfunctionThreshold;
		float m_malfunctionRate;
		unsigned __int64 m_disrepairModifier;
		unsigned __int64 m_tutorialPrompt;
		unsigned __int64 m_tutorialCard;
		uint32_t m_minStartAmmo;
		uint32_t m_maxStartAmmo;
		uint32_t m_disruptionSubMatIndex;
		char pad4[4];
		ArkEntityAttachmentEffect m_disruptionVFX;
		std::vector<ArkMaterialParamOverride> m_originalInterenceValues;
		float m_spawnFromCameraTestDistance;
		float m_spawnBehindCameraDistance;
		CryStringT<char> m_upgradeInfoDesc;
		CryStringT<char> m_focusDescription;
		CCryName m_leverageBaseName;
		CryStringT<char> m_muzzleLightAttachName;
		IParticleEffect* m_pMuzzleLight;
		std::vector<IArkWeaponEventListener*> m_listeners;
		ArkPlayerLightEntity m_playerLight;
		FragmentIDs* m_pFragmentIDs;
		IUIElement* m_pUIElement;
		uint32_t m_zoomHandle;
		uint32_t m_numAmmoLoaded;
		bool m_bIdleBreakEnabled;
		bool m_bShouldFinishReloading;
		bool m_bCancelTutorialEnabled;
		bool m_bIsReadyToAttack;
		bool m_bIsReloading;
		bool m_bIsUnequipping;
		bool m_bRetainPhysicsOnEquip;
		char pad5[1];
		uint32_t m_ironsightsTargetId;
		char pad6[4];
		CryStringT<char> m_ironsightsBoneOrAttachName;
		bool m_bHasAmmoBeenLooted;
		char pad7[7];
		IEntityArchetype* m_pAmmoPickupArchetype;
		ArkAudioTrigger m_startMalfunctionTrigger;
		ArkAudioTrigger m_stopMalfunctionTrigger;
		ArkAudioTrigger m_brokeTrigger;
		ArkAudioTrigger m_ammoPickupTrigger;
	};







	
	class GameLogData {
	public:
		uint32_t m_target;
		ArkTimeRemaining m_timer;
		EArkZoomPriority m_priority;
	};
	class ArkPlayerWeaponComponent
	{
		
	public:
		char pad_0000[24]; //0x0000
		std::vector<uint32_t> m_weaponEntityIds; //0x0018
		std::vector<uint32_t> m_specialWeaponIds; //0x0030
		void* m_player; //0x0048
		ArkAudioTrigger m_triggerSneakAttack; //0x0050
		ArkAudioTrigger m_triggerCriticalHit; //0x0054
		uint32_t m_equippedWeaponId; //0x0058
		uint32_t m_lastEquippedWeaponId; //0x005C
		uint32_t m_backupWeaponId; //0x0060
		uint32_t m_toBeEquippedWeaponId; //0x0064
		float m_weaponCameraSpeedMultiplierAcceleration; //0x0068
		float m_weaponCameraSpeedMultiplier; //0x006C
		float m_aimAssistTargetRangeSq; //0x0070
		float m_gameLogReportWindow; //0x0074
		bool m_bIsUnequipping; //0x0078
		bool m_bCanEquip; //0x0079
		char pad_007A[6]; //0x007A
		std::vector<unsigned __int64> m_weaponTypesAcquired; //0x0080
		std::vector<GameLogData> m_sneakAttackData; //0x0098
		std::vector<GameLogData> m_criticalHitData; //0x00B0
		std::vector<GameLogData> m_mimicHitData; //0x00C8

	}; //Size: 0x00E0

	

	class StanceInfo
	{
	public:
		Vec3 m_colliderSize; //0x0000
		float m_colliderHeight; //0x000C
		float m_viewHeight; //0x0010
		float m_halfHeight; //0x0014
	}; //Size: 0x0018

	class ArkPlayerAttentionObject
	{
	public:
		char pad_0000[32]; //0x0000
		void* m_pPlayer; //0x0020
		uint32_t m_roomEntityId; //0x0028
		char pad_002C[4]; //0x002C
	}; //Size: 0x0030

	class ZoomData {
	public:
		int32_t m_handle;
		float m_desiredHFOV;

	};
	class ArkPlayerZoomManager
	{
		
	public:
		std::vector<ZoomData> m_zoomStack;
		float m_currentHFOV; //0x0018
		float m_prevDesiredHFOV; //0x001C
		float m_interpTime; //0x0020
		bool m_bUseUITime; //0x0024
		char pad_0025[3]; //0x0025
		int32_t m_nearFOVLockedCount; //0x0028
		int32_t m_handleGenerator; //0x002C
	}; //Size: 0x0030

	class IMaterial {
	public:
		char pad1[8];
		unsigned char m_ucDefaultMappingAxis;
		char pad2[3];
		float m_fDefaultMappingScale;
	};

	class SAttachmentMaterials {
	public:
		int32_t meshSlot;
		CryStringT<char> attachmentName;
		IMaterial* pMaterial;
		IMaterial* pOriginalMaterial;
	};
	class EnumClassHash {
	public:
		char a;
	};

	class ArkMaterialAnimationRgbKey {
		float m_Time;
		float m_Red;
		float m_Green;
		float m_Blue;
	};
	
	class ArkMaterialAnimationRgbKeysArray {
	public:
		std::vector<ArkMaterialAnimationRgbKey> m_RgbKeys;

	};
	class ArkMaterialAnimationKey {
	public:
		float m_Time;
		float m_Value;
	};
	class ArkMaterialAnimationKeysArray {
	public:
		std::vector<ArkMaterialAnimationKey> m_Keys;
	};
	class ArkMaterialAnimationSubMaterialData {
	public:
		uint32_t m_SubMaterialSlot;
		char pad1[4];
		ArkMaterialAnimationRgbKeysArray m_Diffuse;
		ArkMaterialAnimationRgbKeysArray m_Specular;
		ArkMaterialAnimationRgbKeysArray m_Emissive;
		ArkMaterialAnimationKeysArray m_Opacity;
		ArkMaterialAnimationKeysArray m_Smoothness;
		ArkMaterialAnimationKeysArray m_AlphaTest;
		ArkMaterialAnimationKeysArray m_Ambient;
		ArkMaterialAnimationKeysArray m_EmissiveIntensity;
	};
	class ArkMaterialAnimationKeyframe {
	public:
		uint32_t m_subMaterialSlot;
		ArkMaterialAnimationChannel m_channel;
		float m_keyTime;
		float m_timeToNextKey;
		float m_floatValue;
		Vec3 m_vectorValue;
		bool m_bIsFloat;
		char pad1[3];
	};
	class ArkMaterialAnimation {
	public:
		unsigned __int64 m_Id;
		CryStringT<char> m_Name;
		CryStringT<char> m_AttachmentName;
		uint32_t m_MeshSlot;
		CryStringT<char> m_MaterialReference;
		std::vector<ArkMaterialAnimationSubMaterialData> m_SubMaterials;
		std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
	};

	class MaterialParameterRamp {
	public:
		IMaterial* m_PMaterial;
		EMaterialParamFloat m_paramFloat;
		EMaterialParamVec3 m_paramVec3;
		char* m_paramName;
		float m_initialFloatValue;
		float m_finalFloatValue;
		Vec3 m_initialvectorValue;
		Vec3 m_finalvectorValue;
		float m_currentTime;
		float m_finalTime;
		bool m_bIsFloat;
	};

	class ActiveAnimationData {
	public:
		std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
	}; 
	class ArkMaterialAnimationManager
	{
	public:
		void* m_pEntity; //0x0000
		std::vector<SAttachmentMaterials> m_attachmentMaterials; //0x0008
		void* m_pOneOffMaterialAnimation; //0x0020
		ActiveAnimationData m_oneOffAnimationData; //0x0028
		std::unordered_map<enumArkMaterialAnimationType, const ArkMaterialAnimation*, EnumClassHash, std::equal_to<enumArkMaterialAnimationType>> m_animationsByType; //0x0040
		ActiveAnimationData m_activeAnimationsByType[18]; //0x0080
		std::vector<MaterialParameterRamp> m_materialParameterRamps; //0x0230
	}; //Size: 0x0248
	class IPlayerEventListener
	{
	public:
		uint64_t N0000349A; //0x0000
	}; //Size: 0x0008

	class ArkPlayer
	{
	public:
		char pad_0000[64]; //0x0000
		void* IArkPlayer; //0x0040
		void* IArkPlayerCombatListener; //0x0048
		void* ISystemEventListener; //0x0050
		ArkPlayerMovementFSM m_movementFSM; //0x0058
		ArkPlayerComponent m_playerComponent; //0x0678
		ArkStatsComponent m_statsComponent; //0x07C0
		ArkEquipmentModComponent m_suitChipsetComponent; //0x0860
		ArkEquipmentModComponent m_scopeChipsetComponent; //0x08A0
		ArkPlayerInput m_input; //0x08E0
		ArkExaminationMode m_examinationMode; //0x09B0
		ArkPlayerInteraction m_interaction; //0x0AC8
		ArkGroundColliderComponent m_groundColliderComponent; //0x11B0
		ArkPlayerFlashlight m_flashlight; //0x11C0
		ArkPlayerAudio m_audio; //0x1250
		ArkPlayerCamera m_camera; //0x12A0
		ArkPlayerHelmet m_helmet; //0x1468
		ArkPlayerWeaponComponent m_weaponComponent; //0x14B8
		std::vector<IPlayerEventListener*> m_playerEventListenersVector; //0x1598
		std::vector<std::pair<CryStringT<char>, uint32_t>> m_attachmentFlagsVector; //0x15B0
		std::vector<unsigned __int64> m_learnedNames; //0x15C8
		std::vector<unsigned __int64> m_criticalHitMetaTags; //0x15E0
		std::vector<CryStringT<char>> m_animationTagsSetFromFG; //0x15F8
		class StanceInfo m_stanceInfos[18]; //0x1610
		class CryStringT<char> m_modelName; //0x17C0
		Vec3 m_serializedVelocity; //0x17C8
		Vec3 m_cachedReticlePos; //0x17D4
		Vec3 m_cachedReticleDir; //0x17E0
		Vec2 m_reticlePos; //0x17EC
		char pad_17F4[4]; //0x17F4
		void* m_pHeadBobbingAction; //0x17F8
		void* m_pMovementController; //0x1800
		void* m_pAnimatedCharacter; //0x1808
		void* m_pInventory; //0x1810
		void* m_pFragmentCache; //0x1818
		uint64_t m_coralSignalPackageId; //0x1820
		ArkSimpleTimer m_coralInteractionTimer; //0x1828
		float m_knockdownLoopDuration; //0x1830
		float m_idleFragmentSpeedThreshold; //0x1834
		EStance m_stance; //0x1838
		char pad_183C[4]; //0x183C
		ArkPlayerAttentionObject m_attentionObject; //0x1840
		float m_fearNoiseAmplitude; //0x1870
		float m_autoSaveHealthThreshold; //0x1874
		float m_autoSaveOxygenThreshold; //0x1878
		float m_attackTargetPosHeightPercent; //0x187C
		float m_lookAtFarRange; //0x1880
		bool m_bInTrackview; //0x1884
		bool m_bInAir; //0x1885
		bool m_bShowArmor; //0x1886
		bool m_bShowHealth; //0x1887
		bool m_bAllowIdleBreak; //0x1888
		bool m_bJustPhysicalized; //0x1889
		bool m_bShowContinuePrompt; //0x188A
		bool m_bReceivedStartLevelEvent; //0x188B
		bool m_bRetcileViewPositionValid; //0x188C
		char pad_188D[3]; //0x188D
		ArkSimpleTimer m_autoSaveBlockedBySignalTimer; //0x1890
		ArkPlayerZoomManager m_zoomManager; //0x1898
		int32_t m_rotationModifierHandleGenerator; //0x18C8
		char pad_18CC[4]; //0x18CC
		std::vector<std::pair<uint32_t, Vec3&>> m_rotationModifiers; //0x18D0
		int32_t m_mimicGrabSequenceEntityId; //0x18E8
		char pad_18EC[4]; //0x18EC
		 ArkMaterialAnimationManager m_materialAnimationManager; //0x18F0
	}; //Size: 0x1B38



	

	


	class StorageCell {
	public:
		uint32_t m_entityId;
		int32_t m_x;
		int32_t m_y;
		int32_t m_width;
		int32_t m_height;
	};
	class ArkInventory
	{
	public:
		char pad_0000[88]; //0x0000
		bool m_bSortDirty; //0x0058
		bool m_bSerializeOpen; //0x0059
		bool m_bPreventStorage; //0x005A
		bool m_bTakesTrash; //0x005B
		EArkGridSizes m_size; //0x005C
		std::vector<StorageCell> m_storedItems; //0x0060
		class ArkSimpleTimer m_lookAtTimer; //0x0078
		InventorySort m_currentSort; //0x0080
		char pad_0084[4]; //0x0084
	}; //Size: 0x0088
	class ArkRandomizedTimer {
	public:
		char pad[8];
		float m_variation;
	};

	//todo:check enum sizes
	enum class ECryAiSystemActiveState {
		unknown = -1,
		inactive = 0,
		active = 1
	};
	enum class EReactionThrowAtType {
		rail = 0,
		glass = 1,
		ledge = 2,
		breakable = 3
	};
	enum class ELookStyle : int32_t{
		LOOKSTYLE_DEFAULT = 0,
		LOOKSTYLE_HARD = 1,
		LOOKSTYLE_HARD_NOLOWER = 2,
		LOOKSTYLE_SOFT = 3,
		LOOKSTYLE_SOFT_NOLOWER = 4,
		LOOKSTYLE_COUNT = 5
	};
	enum class EBodyOrientationMode : int32_t{
		FullyTowardsMovementDirection = 0,
		FullyTowardsAimOrLook = 1,
		HalfwayTowardsAimOrLook = 2
	};



	

	enum class TurnState : int32_t {
		None = 0,
		TurnLeft = 1,
		TurnRight = 2
	};


	enum class ShiftAnimation : int32_t {
		None = 0,
		ShiftInAndOut = 1,
		ShiftInOnly = 2,
		ShiftOutOnly = 3,
		Attack = 4
	};

	enum class ShiftType : int32_t {
		Normal = 0,
		Lurk = 1
	};

	enum class JumpStyle : int32_t {
		None = 0,
		ForwardJump = 1,
		WallJump = 2,
		AnyJump = 3
	};

	enum class JumpGoal : int32_t {
		FromStart = 0,
		FromStartImmediate = 1,
		ToEnd = 2,
		ToEndImmediate = 3
	};

	enum class HoverStyle : int32_t {
		MaintainFloorHeight = 0,
		MaintainCurrentHeight = 1,
		IgnoreHeight = 2
	};
	enum class EStatus : int32_t {
		None = 0,
		Pending = 1,
		Installed = 2,
		Exiting = 3,
		Finished = 4
	};
	enum class FailureReason : int32_t {
		NoReason = 0,
		CouldNotFindValidStart = 1,
		CouldNotFindValidDestination = 2,
		CouldNotFindPathToRequestedDestination = 3,
		CouldNotMoveAlongDesignerDesignedPath = 4,
		FailedToProduceSuccessfulPlanAfterMaximumNumberOfAttempts = 5,
		CouldNotFindPathAroundObstacles = 6,
		FailedShift = 7,
		PathingModeForced = 8,
		FacingRestricted = 9,
		StuckOnObstacle = 10,
		StuckOnNpc = 11,
		StuckOnGloo = 12
	};

	enum class LightMode : int32_t {
		friendly = 0,
		hostile = 1,
		hacked = 2
	};

	enum class EFallingState : int32_t {
		notFalling = 0,
		maybeFalling = 1,
		falling = 2,
		fallingOutOfGravShaft = 3
	};
	
	class ArkSpatiallySortedKey {
	public:
		uint64_t m_index;
	};
	
	template<typename t> class ArkSpatialManagerKey {
	public:
		ArkSpatiallySortedKey m_key;
	};

	class ArkSpatialManagerEntryImpl_Npc {
	public:
		unsigned char a;
	};

	template<typename t> class ArkSpatialManagerEntry {
	public:
		t m_impl;
		ArkSpatialManagerKey<t> m_key;
	};

	class LookPoseParam {
	public:
		float m_torso,
			m_head,
			m_eyes,
			m_aim;
	};
	class CTimeValue {
	public:
		uint64_t m_lValue;
	};
	
	namespace ArkNpc {

		class ArkCharacterEffectsManager {
		public:
			IEntity* m_pEntity;
			std::vector < CryStringT<char>> m_attachmentsByType[64];
		};
		class ArkNpcAttentiveSubject {
		public:
			char pad[32];
			ArkNpc* m_pNpc;
			float m_complexHearingGain,
				m_complexVisionGain;
			EArkNpcVisionDirection m_visionDirection;
			char pad2[4];
		};
		class ArkNpcAttentionObject {
		public:
			char pad[24];
			ArkNpc* m_pNpc;
		};
		class CArkNpcLookAroundControl {
		public:
			bool m_bSuspended,
				m_bStateChange,
				m_bEnabled[2];
			float m_idleTime;
			IAction* m_pLookAroundAction;
		};
		class ArkNpcCollisionObserver {
		public:
			char pad[32];
		};

		class Fatality {
			float m_vulnerabilityHealthThreshold;
		};


		class Corruption {
		public:
			bool m_bDeletedOnLevelLoadAndUncorrupted;
			bool m_bShouldGoUnconsciousOnUncorruption;
			bool m_bStartCorrupted;
			char* m_pMovementGlitchAttachmentName1;
			char* m_pMovementGlitchAttachmentName2;
			class ArkAudioTrigger m_becomeCorruptedAudioTrigger;
			uint64_t m_corruptedGameEffectId;
			uint64_t m_uncorruptedMetaTagId;
			IParticleEffect* m_pCorruptedMovementGlitchParticleEffect;
		};

		class Dodge {
		public:
			bool m_bEnabled;
			float m_chance;
			float m_cooldown;
			uint64_t m_damagePackageId;
		};

		class PoltergeistEffects {
		public:
			uint64_t m_invisibilityGameEffectId;
		};

		class RaiseFromCorpse {
		public:
			uint64_t m_raiseFromCorpseGameEffectId;
		};

		class Stunned {
		public:
			uint64_t m_stunnedGameEffectId;
		};

		class Dormant {
		public:
			float m_hearingGainModifier;
			uint64_t m_signalModifierId;
		};

		class Glooed {
		public:
			uint64_t m_glooGameEffectId;
			uint64_t m_onGlooedAbilityContextId;
		};

		class UnreachableTargeting {
		public:
			float m_defaultCombatReachabilityCheckUp;
			float m_defaultCombatReachabilityCheckDown;
			float m_defaultCombatReachabilityCheckHorizontal;
			float m_startingTraceRadius;
			float m_startingMinSearchRadius;
			float m_chanceToSearchInReverseOrder;
			float m_horizontalOffsetStanding;
			float m_standardCombatHeight;
		};

		class OperatorEffects {
		public:
			float m_airJetToggleOffTime;
			float m_maxAirJetToggleOnTime;
			float m_minAirJetToggleOnTime;
			uint64_t m_operatorArmRetractedGameEffectId;
			IParticleEffect* m_pAirJetParticleEffect;
		};

		class CorruptNpc {
		public:
			bool m_bReleaseCorruptionOnDeath;
		};

		class Mimicry {
		public:
			int m_morphInSlot;
			int m_morphOutSlot;
			float m_defaultMass;
			float m_impulseMultiplier;
			float m_impulsePointHorizontalRatio;
			float m_impulsePointVerticalRatio;
			float m_startCharacterMorphOutTime;
			float m_startGeometryMorphInTime;
			float m_stopCharacterMorphInTime;
			float m_stopGeometryMorphOutTime;
			class CryStringT<char> m_MorphOutBamfBoneName;
			uint64_t m_signalModifierId;
			IParticleEffect* m_pMorphInParticlefEffect;
			IParticleEffect* m_pMorphOutBamParticlefEffect;
			IParticleEffect* m_pMorphOutParticlefEffect;
			class ArkAudioTrigger m_startTickingAudioTrigger;
			class ArkAudioTrigger m_stopTickingAudioTrigger;
			class ArkAudioTrigger m_unmorphAudioTrigger;
		};

		class TurretWeapon {
		public:
			class IEntityArchetype* m_pLootAmmoLaserArchetype;
			class IEntityArchetype* m_pLootAmmoStunArchetype;
		};


		class RaisePhantom {
		public:
			bool m_bCanBeRaisedPhantom;
			int m_maxAllowedRaisedPhantoms;
		};

		class IParticleEffect {
		public:
			void* ptr1;
			void* ptr2;
		};

		class ControlTurrets {
		public:
			uint64_t m_controlTurretsGameEffectId;
		};

		class OnDeath {
		public:
			float m_aoeDeathRadius;
			float m_aoeDeathSignalScale;
			uint64_t m_aoeDeathSignal;
			IParticleEffect* m_pFearAoeParticleEffect;
		};

		class NoiseStates {
		public:
			ArkAudioTrigger m_combatStateAudioTrigger;
			ArkAudioTrigger m_idleStateAudioTrigger;
			ArkAudioTrigger m_noticeStateAudioTrigger;
			ArkAudioTrigger m_searchStateAudioTrigger;
			ArkAudioTrigger m_stareStateAudioTrigger;
		};

		class DamageStates {
		public:
			bool m_bHasDamageStates;
			float m_healthThresholdDamage;
			float m_healthThresholdDisabled;
			float m_destroyedExplosionRadius;
			float m_destroyedExplosionImpulse;
			float m_destroyedExplosionDelay;
			float m_destroyedHeightOffset;
			float m_disabledRepeatDialogCD;
			float m_disabledFlickerDuration;
			char* m_pUndamagedAttachmentName;
			char* m_pDamagedAttachmentName;
			char* m_pDisabledAttachmentName;
			char* m_pChassisModelName;
			char* m_pChassisUndamagedAttachmentName;
			char* m_pChassisDestroyedAttachmentName;
			ArkAudioTrigger m_becomeUndamagedAudioTrigger;
			ArkAudioTrigger m_becomeDamagedAudioTrigger;
			ArkAudioTrigger m_becomeDisabledAudioTrigger;
			uint64_t m_destroyedExplosionPackageId;
			uint64_t m_destroyedExplosionCameraShakeId;
		};

		class CallForHelp {
		public:
			uint64_t m_onAttackNoiseLoudness;
			uint64_t m_onAttackNoiseType;
			uint64_t m_onNewCombatAttentionNoiseLoudness;
			uint64_t m_onNewCombatAttentionNoiseType;
		};

		class Ability {
		public:
			uint64_t m_abilityContextProfileId;
		};

		class Shift {
		public:
			uint64_t m_shiftingSignalModifierId;
		};

		class Hack {
		public:
			bool m_bStartHacked;
			uint64_t m_hackedGameEffectId;
		};

		class Character {
		public:
			uint64_t m_characterId;
		};

		class HitReaction {
		public:
			uint64_t m_hitReactionMaterialAnimationGameEffectId;
		};

		class HumanArmed {
		public:
			bool m_bIsArmed;
			int m_magSize;
			char* m_pGunAttachmentName;
			class IEntityArchetype* m_pLootWeaponEntityArchetype;
		};

		class AttentionFacing {
		public:
			bool m_bUsesAttentionFacing;
			bool m_bUsesAttentionLook;
		};

		class Nullwave {
		public:
			uint64_t m_nullwavedSignalModifierId;
		};

		class Sound {
		public:
			NoiseStates m_noiseStates;
			ArkAudioTrigger m_deathAudioTrigger;
			ArkAudioTrigger m_startAmbientLivingAudioTrigger;
			ArkAudioTrigger m_stopAmbientLivingAudioTrigger;
		};

		class CombatRoleInfo {
		public:
			bool m_bCanGetStaleInMeleeRole;
			bool m_bUsesCombatRoles;
			float m_meleeRoleCost;
			float m_meleeRolePreference;
			float m_meleeRoleScoreBias;
			float m_minDistanceToAllowRangeRoleSwitchSq;
		};

		class OnFire {
		public:
			uint64_t m_onFireGameEffectId;
		};

		class Surprise {
		public:
			uint64_t m_noiseLoudnessId;
			uint64_t m_noiseTypeId;
		};

		class MimicJumpAttack {
		public:
			uint64_t m_mimicJumpAttackPackageId;
			IParticleEffect* m_pMimicAttackEffect;
		};

		class Hypnotize {
			float m_timeBetweenHypnotize;
		};

		class Energized {
		public:
			uint64_t m_energizedGameEffectId;
		};

		class MimicReorient {
		public:
			bool m_bSupportsReorientation;
			float m_mimicGlitchRandTimeMax;
			float m_mimicGlitchRandTimeMin;
		};

		class Fear {
		public:
			uint64_t m_fearedGameEffectId;
			uint64_t m_fearedSignalModifierId;
		};

		class EntityFactionModifier {
		public:
			uint64_t m_hositleToFactionId;
		};

		class Mannequin {
		public:
			char* m_pLifetimeTag;
		};

		class PlayerControlled {
		public:
			uint64_t m_playerControlledGameEffectId;
		};

		class Laser {
		public:
			int m_laserHitTypeId;
			float m_beamEndJumpDistanceSq;
			float m_materialEffectCooldown;
			float m_maxLaserLength;
			float m_maxThickness;
			float m_minThickness;
			uint64_t m_laserPackageId;
			int m_customSurfaceTypeId;
			char* m_pBeamEndEffectName;
			char* m_pLaserGeometryName;
			char* m_pLaserMaterialEffectName;
			char* m_pReflectionGeometryName;
			class IEntityArchetype* m_pLootAmmoLaserArchetype;
			class IEntityArchetype* m_pLootAmmoStunArchetype;
		};

		class MindControl {
		public:
			uint64_t m_mindControlGameEffectId;
		};

		class Audio {
		public:
			char* m_pDistanceToPlayerParam;
		};

		class ArkNpcProperties {
		public:
			Ability m_ability;
			AttentionFacing m_attentionFacing;
			Audio m_audio;
			CallForHelp m_callForHelp;
			Character m_character;
			CombatRoleInfo m_combatRoleInfo;
			ControlTurrets m_controlTurrets;
			CorruptNpc m_corruptNpc;
			Corruption m_corruption;
			DamageStates m_damageStates;
			Dodge m_dodge;
			Dormant m_dormant;
			Energized m_energized;
			EntityFactionModifier m_entityFactionModifier;
			Fatality m_fatality;
			Fear m_fear;
			Glooed m_glooed;
			Hack m_hack;
			HitReaction m_hitReaction;
			HumanArmed m_humanArmed;
			Hypnotize m_hypnotize;
			Laser m_laser;
			Mannequin m_mannequin;
			MimicJumpAttack m_mimicJumpAttack;
			MimicReorient m_mimicReorient;
			Mimicry m_mimicry;
			MindControl m_mindControl;
			Nullwave m_nullwave;
			OnDeath m_onDeath;
			OnFire m_onFire;
			OperatorEffects m_operatorEffects;
			PlayerControlled m_playerControlled;
			PoltergeistEffects m_poltergeistEffects;
			RaiseFromCorpse m_raiseFromCorpse;
			RaisePhantom m_raisePhantom;
			Shift m_shift;
			Sound m_sound;
			Stunned m_stunned;
			Surprise m_surprise;
			TurretWeapon m_turretWeapon;
			UnreachableTargeting m_unreachableTargeting;
			bool m_bCanFall;
			bool m_bCanRagdoll;
			bool m_bSupportsLookAt;
			int m_playerPowerTierTriggerThreshold;
			int m_npcManagerCombatPoints;
			float m_combatIntensityContribution;
			float m_combatIntensityRange;
			float m_fallDamagePerMeter;
			float m_fallDistanceForDamage;
			float m_fallDistanceForDialog;
			float m_fallDistanceForFallAnim;
			float m_fallDistanceForGlooBreak;
			float m_fallDistanceForLandAnim;
			float m_forceResistScrunchDistance;
			char* m_pAiTreeFilePath;
			char* m_pFaction;
			uint64_t m_fallDamagePackage;
			uint64_t m_ragdollSignalModifierId;
			EArkAttentionLevel m_abortTrackviewOnHostileAttention;
			EArkNpcVisionDirection m_visionDirection;
		};
		typedef unsigned char ArkNpcSpawnedState_Alert;
		typedef unsigned char ArkNpcSpawnedState_Broken;
		typedef unsigned char ArkNpcSpawnedState_Dead;
		typedef unsigned char ArkNpcSpawnedState_Dormant;
		template<typename a, typename b, typename c, typename d> class variant {
		public:
			int32_t which_;
			a A;
			b B;
			c C;
			d D;
			std::aligned_storage<32, 8> storage_;
		};
		class AkrNpcLifecycleFsm {
		public:
			char pad[712];
		};
		class ArkNpcLifecycle {
		public:
			ArkNpc* m_pNpc;
			AkrNpcLifecycleFsm m_fsm;
		};
		class ArkNpcBodyFsm {
		public:
			char pad[6072];
		};
		class ArkNpcBody {
		public:
			char pad[24];
			ArkNpc* m_pNpc;
			ArkNpcBodyFsm m_fsm;
			float m_jumpStartZ;
			bool m_bCanFallFromJump;
			char pad2[3];
			EFallingState m_FallingState;
			float m_fallingStartZ;
			uint64_t m_liftCount;
		};
		class ArkNpcDamageFsm {
		public:
			char pad[56];
			bool m_bCanBeDisabled;
			bool m_bShouldInstantlyDie;
			char pad2[2];
		};
		class ArkNpcDesireTarget {
		public:
			char pad[36];
			//variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<10>,ArkNpcNoDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<9>,ArkNpcPositionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<8>,ArkNpcEntityDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<7>,ArkNpcEntityBoneDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<6>,ArkNpcEntityOffsetTargetImpl,boost::mpl::l_item<boost::mpl::long_<5>,ArkNpcEntityBoundsCenterTargetImpl,boost::mpl::l_item<boost::mpl::long_<4>,ArkNpcAttentionProxyDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<3>,ArkNpcCameraDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<2>,ArkNpcDirectionDesireTargetImpl,boost::mpl::l_item<boost::mpl::long_<1>,ArkNpcAttackPositionDesireTargetImpl,boost::mpl::l_end>>>>>>>>>>>>
		};
		template<typename T> class ArkDelegate {
		public:
			T* m_pObject;
			void* m_pCaller;
		};
		class ArkNpcLookDesire {
		public:
			char pad[64];
			ArkNpcDesireTarget m_target;
			bool m_bUseAim,
				m_bAllowLowerBodyTurn;
			char pad2[2];
			ELookStyle m_style;
			EBodyOrientationMode m_orientMode;
			EArkNpcSpeedType m_minSpeed;
			LookPoseParam m_blendInTime,
				m_smoothTime,
				m_blendOutTime,
				m_maxAngleRadiansPitch,
				m_maxAngleRadiansYaw;
			float m_polarOffsetX,
				m_polarOffsetY;
			char pad3[4];
			ArkDelegate<void __cdecl(EArkNpcLookDesireCallbackEvent)> m_callback;
		};
		class ArkNpcNoiseStateDesire {
		public:
			char pad[64];
			EArkNpcNoiseState m_noiseState;
			char pad2[4];
		};
		class ArkNpcFacingDesire {
		public:
			char pad[64];
			TurnState m_turnState;
			ArkNpcDesireTarget m_target,
				m_turnAlignTarget;
			float m_resumeAngle;
			EArkNpcSpeedType m_minSpeed;
			char pad2[4];
			ArkDelegate<void __cdecl(EArkNpcFacingDesireCallbackEvent)> m_callback;
		};
		class ArkNpcMovementDesire {
		public:
			char pad[64];
			ArkNpcDesireTarget m_destination;
			bool m_bQueryNavSystem;
			char pad2[3];
			float m_navQueryHorizontalRadius,
				m_navQueryBelowThreshold,
				m_navQueryAboveThreshold;
			bool m_bForcePath,
				m_bForceGoToNavMesh;
			char pad3[2];
			int32_t m_stance;
			float m_speedLiteral,
				m_accelLiteral,
				m_decelLiteral,
				m_stopDistance,
				m_resumeDistance;
			bool m_bUseExactPosition;
			char pad4[3];
			float m_exacRotationStartDist;
			Vec3 m_exactDirection;
			bool m_bShift;
			char pad5[3];
			float m_shiftDistBefore,
				m_shiftDistAfter,
				m_shiftTelegraphTime;
			ShiftAnimation m_shiftAnims;
			ShiftType m_shiftType;
			JumpStyle m_jumpStyle;
			JumpGoal m_jumpGoal;
			float m_jumpDist,
				m_jumpGoalPathDist;
			HoverStyle m_hoverStyle;
			EArkObstacleAvoidanceUrgency m_obstacleAvoidUrgency;
			bool m_bContinueMoving,
				m_bScriptMove,
				m_bAllowTeleportToNavMesh;
			char pad6;
			FailureReason m_lastFailure;
			char pad7[4];
			ArkDelegate<void __cdecl(EArkNpcMovementDesireCallbackEvent)> m_callback;
		};

		class ArkNpcFacingDesireManager {
		public:
			char pad[48];
		};
		class ArkNpcLookDesireManager {
		public:
			char pad[48];
			EArkNpcSpeedType m_speed;
			LookPoseParam m_defaultBlendInTime,
				m_defaultSmoothTime,
				m_defaultBlendOutTime,
				m_defaultMaxYaw,
				m_defaultMaxPitch;
			float m_speedMultiplierFastHead,
				m_speedMultiplierFastestHead,
				m_speedMultiplierFastTorso,
				m_speedMultiplierFastestTorso,
				m_speedScale;
		};
		typedef uint32_t MovementRequestID;
		class ArkNpcMovementDesireManager {
		public:
			char pad[48];
			MovementRequestID m_movementRequestID,
				m_stopRequestId;
			ArkNpcFacingDesire m_facingDesire;
			bool m_bNeedsStop;
			bool m_bNeedsNavMeshReturn;
			char pad2[6];
		};
		class ArkNpcNoiseStateDesireManager {
		public:
			char pad[48];
			ArkAudioTrigger m_audioTriggers[5];
			OPTIONAL EArkNpcNoiseState m_currentNoiseState;
			char pad2[4];
		};

		class ArkNpcSpeedDesireManager {
		public:
			char pad[48];
			float m_deltaAngleRateNormal,
				m_deltaAngleRateFast,
				m_deltaAngleRateFastest;
			bool m_bSmoothedZTurning;
			char pad2[3];
		};

		class ArkAiKnowledge {
		public:
			ArkNpc* m_npc;
		};
		class ArkAiTree {
		public:
			char pad[8];
			ArkContiguousMemory m_nodes;
		};
		class ArkAiTreeNodeParent {
		public:
			char pad[8];
		};
		class ArkAiTreeNode {
		public:
			char pad[8];
			uint64_t m_traversalIndex;
			ArkAiTreeNodeParent* m_pParent;
			ArkAiTreeNode** m_ppChildrenBegin;
			ArkAiTreeNode** m_ppChildrenEnd;
		};
		class ArkAiTreeInstanceNodeParent {
		public:
			unsigned char a;
		};
		class ArkAiTreeStatus {
		public:
			EArkAiTreeStatusFlags m_statusFlags;
		};
		class ArkAiTreeInstanceNode {
		public:
			char pad[8];
			ArkAiTreeInstanceNodeParent* m_pParent;
			ArkAiTreeInstanceNode** m_ppChildrenBegin;
			ArkAiTreeInstanceNode** m_ppChildrenEnd;
			ArkAiTreeStatus m_status;
		};
		class ArkAiTreeStimulusDelegate {
		public:
			ArkAiTreeNode* m_pNode;
			ArkAiTreeInstanceNode* m_pInstanceNode;
			void* m_pCaller;
		};
		class ArkAiTreeInstance {
		public:
			ArkContiguousMemory m_nodes;
			std::unordered_map<const ArkAiTreeNode*, std::unordered_map<const char*, ArkAiTreeStimulusDelegate, std::hash<const char*>, std::equal_to<const char*>, std::allocator<std::pair<const char* const, ArkAiTreeStimulusDelegate>>>, std::hash<const ArkAiTreeNode*>, std::equal_to<const ArkAiTreeNode*>, std::allocator<std::pair<const ArkAiTreeNode* const, std::unordered_map<const char*, ArkAiTreeStimulusDelegate, std::hash<const char*>, std::equal_to<const char*>, std::allocator<std::pair<const char* const, ArkAiTreeStimulusDelegate>>>>>> m_nodeStimulusDelegates;
		};
		class HitInfo {
		public:
			uint32_t shooterId;
			uint32_t targetId;
			uint32_t weaponId;
			uint32_t projectileId;
			uint32_t uniqueId;
			uint32_t groupId;
			float damage;
			float impulseScale;
			float radius;
			float angle;
			int material;
			int type;
			int bulletType;
			float damageMin;
			int partId;
			Vec3_tpl<float> pos;
			Vec3_tpl<float> dir;
			Vec3_tpl<float> normal;
			unsigned short projectileClassId;
			unsigned short weaponClassId;
			bool remote;
			bool aimed;
			bool knocksDown;
			bool knocksDownLeg;
			bool hitViaProxy;
			bool explosion;
			bool forceLocalKill;
			bool critical;
			int penetrationCount;
		};
		class IAnimSequence {
		public:
			char pad[16];
		};
		class ArkPsiLift {
		public:
			Vec3 m_axis;
			Vec3 m_position;
			CryStringT<char> m_particleEffectName;
			uint32_t m_entityId,
				m_ownerid;
			int32_t m_particleEmitterSlot;
			float m_radius,
				m_height;
		};
		class ArkPlayerLiftEntity {
		public:
			ArkSimpleTimer m_destroyGooTimer;
			float m_inwardLiftForce,
				m_upwardLiftForce;
		};
		class ArkPsiPowerLiftUniqueProperties {
		public:
			float m_MinHeight,
				m_MaxRange,
				m_MaxRangeZeroG,
				m_Radius,
				m_Gravity,
				m_InwardLiftForce,
				m_UpwardLiftForce,
				m_LiftForceZeroG,
				m_HoverVelocityDamping,
				m_HoverVelocityFalloff,
				m_HoverFalloffDistance;
			CryStringT<char> m_ParticleEffect,
				m_TargetingParticleEffect,
				m_TargetingParticleEffectLight;
			uint64_t m_PlayerPostEffectId;
			CryStringT<char> m_PlayerEnterAudioTrigger,
				m_PlayerExitAudioTrigger;
			uint64_t m_EnterLiftSignalPackageId;
		};
		class LiftEntitySpawner {
			ArkPsiPowerLiftUniqueProperties* m_properties;
		};
		template<typename T> class ArkPsiLiftVolumeEntity {
		public:
			T m_derived;
			uint32_t m_entityId;
		};
		template<typename T> class ArkPsiLiftVolume {
		public:
			ArkPsiLift m_psLift;
			ArkSimpleTimer m_aliveTimer,
				m_queryTimer;
			T m_entitySpawner;
			std::vector<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>> m_containedEntities;
			float m_gravity;
		};
		template<typename T> class ArkPsiLiftVolumeManager {
		public:
			char pad[8];
			std::vector<ArkPsiLiftVolume<T>> m_liftVolumes;

		};
		class ArkAirJet {
		public:
			IAttachment* m_pAttachment;
			float m_toggleTimer;
		};
		class ArkAirJetManager {
		public:
			std::vector<ArkAirJet> m_airJets;
			Vec3 m_prevForward;
			ArkInterval<float> m_airJetActiveToggleTime;
			float m_airJetOffTime;
		};
		class ArkDialogPlayerRobotLightExtension {
		public:
			char pad[8];
			ArkRandomizedTimer m_brightnessTimer;
			char pad2[4];
			uint64_t m_lastDialogId;
			float m_minBrightness,
				m_maxBrightness;
			ArkRobotLight* m_light;
		};
		class ArkRobotLight {
		public:
			IEntity* m_pEntity;
			uint32_t m_arkLightEntityId;
			LightMode m_lightMode;
			ArkDialogPlayerRobotLightExtension m_dialogExtension;
			ArkSimpleTimer m_lightFlickerDurationTimer,
				m_lightFlickerToggleTimer;
			float m_flickerToggleMaxTime,
				m_onBrightness;
			bool m_bActive,
				m_bGlowHidden,
				m_bEntityHidden,
				m_bIsOn,
				m_bScriptEnabled,
				m_bIsFlickering,
				m_bFlickeringForceOff,
				m_bRemoved;
		};
		class ArkFireAndForgetEffect {
		public:
			char pad[64];
		};
		class ArkNpc {
		public:
			char pad[88];
			std::vector<Vec3> m_cachedDoppelgangerCandidatePositions;
			std::vector<uint32_t> m_cachedNearbyNpcsForAbility;
			Vec3 m_cachedThermogenesisLocation;
			Vec3 m_cachedEMPBlastLocation;
			Vec3 m_cachedHitReactShiftLocation;
			char pad2[4];
			ArkSpatialManagerEntry<ArkSpatialManagerEntryImpl_Npc> m_spatialManagerEntry;
			uint64_t m_characterId;
			CEffectsController m_effectController;
			ArkNpcFacingDesireManager m_facingDesireManager;
			ArkNpcLookDesireManager m_lookDesireManager; 
			ArkNpcMovementDesireManager m_movementDesireManager;
			ArkNpcNoiseStateDesireManager m_noiseStateDesireManager;
			ArkNpcSpeedDesireManager m_speedDesireManager;
			ArkCharacterEffectsManager m_characterEffectsManager;
			ArkMaterialAnimationManager m_materialAnimationManager;
			ArkNpcAttentiveSubject m_attentiveSubject;
			ArkNpcAttentionObject m_attentionObject;
			CArkNpcLookAroundControl m_lookAround;
			ArkIntrusiveList<ArkNpcCollisionObserver> m_collisionObservers;
			ArkNpcProperties m_properties;
			variant<ArkNpcSpawnedState_Alert, ArkNpcSpawnedState_Broken, ArkNpcSpawnedState_Dead, ArkNpcSpawnedState_Dormant> m_spawnedState;
			std::unique_ptr<ArkNpcLifecycle, std::default_delete<ArkNpcLifecycle>> m_pLifecycle;
			std::unique_ptr<ArkNpcBody, std::default_delete<ArkNpcBody>> m_pBody;
			std::unique_ptr<ArkNpcDamageFsm, std::default_delete<ArkNpcDamageFsm>> m_pDamageFsm;
			ArkNpcLookDesire m_attentionLookDesire;
			ArkNpcNoiseStateDesire m_attentionNoiseStateDesire;
			ArkNpcFacingDesire m_blendRagdollFacingDesire;
			ArkNpcLookDesire m_blendRagdollLookDesire;
			ArkNpcMovementDesire m_blendRagdollMovementDesire;
			ArkNpcFacingDesire m_conversationFaceDesire;
			ArkNpcLookDesire m_conversationLookDesire;
			ArkNpcMovementDesire m_conversationMovementDesire;
			ArkNpcFacingDesire m_trackViewFacingDesire;
			ArkNpcLookDesire m_trackViewLookingDesire;
			ECryAiSystemActiveState m_cryAISystemState;
			char pad3[4];
			ArkAiKnowledge m_aiKnowledge;
			CryStringT<char> m_aiTreeFilePath;
			std::shared_ptr<ArkAiTree> m_pAiTree;
			std::unique_ptr<ArkAiTreeInstance, std::default_delete<ArkAiTreeInstance>> m_pAiTreeInstance;
			bool m_bUpdatingForStimuli;
			bool m_bSerializedUpdatingForStimuli;
			char pad4[6];
			ArkUnanimous m_abilitiesEnabled;
			ArkUnanimous m_aiTreeEnabled;
			ArkUnanimous m_ambientSoundEnabled[2];
			ArkUnanimous m_attentionObjectEnabled;
			ArkUnanimous m_attentiveSubjectEnabled;
			ArkUnanimous m_audibleEnabled;
			ArkUnanimous m_combatIntensityEnabled;
			ArkUnanimous m_hearingEnabled;
			ArkUnanimous m_lifetimeEffectEnabled;
			ArkUnanimous m_operatorLevitatorsEffectEnabled;
			ArkUnanimous m_roomPerceiverEnabled;
			ArkUnanimous m_visibleEnabled;
			ArkUnanimous m_visionEnabled;
			uint64_t m_aiAlwaysUpdatePushCount;
			uint64_t m_aiTreeSuspendedCount;
			uint64_t m_disableDeathReactionsCount;
			uint64_t m_disableHitReactionsCount;
			uint64_t m_disableNpcHealthUiCount;
			uint64_t m_dumbedCount;
			uint64_t m_glassBreakingEnabledCount;
			uint64_t m_rigidOnGlooFrozenCount;
			bool m_bFlowGraphAiDisabled;
			bool m_bFlowGraphCanCorruptNpcs;
			bool m_bFlowGraphCombatIntensityDisabled;
			bool m_bFlowGraphDumbed;
			bool m_bFlowGraphIgnoreDistractions;
			bool m_bHasTimeToDeath;
			char pad5[2];
			float m_timeToDeath;
			Vec3_tpl<float> m_headPosition;
			Vec3_tpl<float> m_headDirection;
			ArkAudioRtpc m_distanceToPlayerRtpc;
			uint32_t m_wanderAreaContainerEntityId;
			bool m_bWanderDisabled;
			bool m_bCurrentlyWandering;
			bool m_bPushedAIAlwaysUpdateForPatrol;
			bool m_bCanBeDistracted;
			bool m_bIsDistracted;
			char pad6[3];
			float m_usedDistractionCooldown;
			ArkUnanimous m_breakable;
			float m_transitionStateTagTimer;
			bool m_bShouldSkipNextCombatReaction;
			bool m_bAnimatedMovement;
			bool m_bAnimatedJump;
			bool m_bIsFrozenInGloo;
			bool m_bDeflectsGloo;
			char pad7[3];
			ArkSimpleTimer m_playerBumpTimer;
			ArkSimpleTimer m_xRayVisionTimeOnPlayer;
			uint32_t m_topAttentionTargetEntityId;
			char pad8[4];
			 ArkDelegate<void __cdecl(void)> m_fleeStartFlowNodeCallback;
			 ArkDelegate<void __cdecl(void)> m_fleeEndFlowNodeCallback;
			 ArkDelegate<void __cdecl(void)> m_guardInPositionFlowNodeCallback;
			 ArkDelegate<void __cdecl(uint32_t, uint32_t, bool)> m_createPhantomFlowNodeCallback;
			bool m_bHasPerformedNotice;
			char padx[7];
			CTimeValue m_lastSearchAnimTime;
			bool m_bIsInCombat;
			bool m_bCombatIntensityIncreased;
			char pad9[2];
			enum EArkCombatRole m_currentCombatRole;
			float m_combatReactionCooldownTimer;
			HitInfo m_lastDamagingHitInfo;
			char pad10[4];
			uint64_t m_lastDamagingPackageId;
			int32_t m_lastOnHitFrameId;
			char pad11[4];
			CTimeValue m_damageAccumulationStartTime;
			float m_damageAccumulationFromPlayer;
			bool m_bIsIgnoringRangedAbilities;
			char pad12[3];
			uint64_t m_lastAbilityContextIdPerformed;
			CTimeValue m_dodgeTimeStamp;
			CTimeValue m_knockDownTimeStamp;
			CTimeValue m_staggerTimeStamp;
			CTimeValue m_hypnotizeStartTimeStamp;
			bool m_bPsiSuppressed;
			bool m_bIsPrereqHitReacting;
			bool m_bIsTakingPrereqDamage;
			bool m_bPrereqIsRegainingLoS;
			bool m_bCanMimicSideStepLeft;
			bool m_bCanMimicSideStepRight;
			char pad13[2];
			uint64_t m_animAttackPackageId;
			IAnimSequence* m_pTrackviewSequence;
			float m_mimicGlitchTimeNext;
			char pad15[4];
			ArkEntityAttachmentEffect m_mimicMorphInEffect;
			ArkEntityAttachmentEffect m_mimicMorphOutEffect;
			std::vector<uint32_t> m_raisedPhantomIds;
			uint32_t m_ethericDoppelgangerId;
			uint32_t m_ethericDoppelgangerOwnerId;
			bool m_bIsEthericDoppelganger;
			char pad16[7];
			std::unique_ptr<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<LiftEntitySpawner>>, std::default_delete<ArkPsiLiftVolumeManager<ArkPsiLiftVolume<LiftEntitySpawner>>>> m_pLiftVolumeManager;
			uint32_t m_npcThatCorruptedMe;
			char pad17[4];
			std::vector<uint32_t> m_npcsCorrupted;
			bool m_bCorruptedMovementDisabled;
			bool m_bWasUncorrupted;
			char pad18[6];
			ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect1;
			ArkEntityAttachmentEffect m_CorruptedMovementGlitchEffect2;
			ArkAirJetManager m_operatorAirJetManager;
			ArkRobotLight m_robotLight;
			ArkFireAndForgetEffect m_aoeDeathEffect;
			Vec3_tpl<float> m_cachedThrowAtLocation;
			EReactionThrowAtType m_cachedThrowAtType; //enum
			uint32_t m_leaderEntityId;
			uint32_t m_attachedPistolEntityId;
			int32_t m_numAmmo;
			bool m_bInitiallyUpdateAi;
			bool m_bIsSerializingRead;
			bool m_bHasFullSerializeReadBeenCalled;
			bool m_bShuttingDown_Hack;
		};
		};


		class AABB {
			Vec3 min;
			Vec3 max;
		};
		
		class CEntity {
			//TODO
		};
		class IEntitySystemSink {
		public:
			void* ptr;
		};
		class ISystem {
			void* ptr;
		};
		class OnEventSink {
		public:
			uint64_t subscriptions;
			IEntitySystemSink* pSink;
		};
		class IEntitySystem {
		public:
			CEntitySystem* ptr;
		};
		class IEntityClass {
		public:
			CEntity* ptr;
		};
		class SEntityTimerEvent {
		public:
			uint32_t entityId;
			int32_t nTimerId;
			int32_t nMilliSeconds;
		};

		class CScriptBind_Entity {
		public:
		};
		class CEntityClassRegistry {
		public:
		};
		class CPhysicsEventListener {
		public:
		};
		class CAreaManager {
		public:
		};
		class CEntityLoadManager {
		public:
		};

		class CEntityPoolManager {
		public:
		};

		class IBreakableManager {
		public:
			void* ptr;
		};

		class CEntityArchetypeManager {
		public:
			std::map<const char*, CEntityArchetype*> m_nameToArchetypeMap;
			std::unordered_map<unsigned __int64, CEntityArchetype*> m_idToArchetypeMap;
			char pad[8];
			char pad2[24];
		};
		class CGeomCacheAttachmentManager {
		public:
		};
		class CCharacterBoneAttachmentManager {
		public:
		};
		class IEntityEventListener {
		public:
			void* ptr;
		};
		class CPartitionGrid {
		public:
		};
		class CProximityTriggerSystem {
		public:
		};
		class CEntityLayer {
		public:
		};
		class SEntityLayerGarbage {
		public:
			void* pHeap;
			CryStringT<char> layerName;
			int32_t nAge;
			char pad[4];
		};
		class CEntitySystem {
		public:
			undefined field0_0x0;
			undefined field1_0x1;
			undefined field2_0x2;
			undefined field3_0x3;
			undefined field4_0x4;
			undefined field5_0x5;
			undefined field6_0x6;
			undefined field7_0x7;
			std::unordered_map<uint32_t, float, std::hash<uint32_t>, std::equal_to<uint32_t>> m_queuedEntityVisibilities;
			std::vector<IEntitySystemSink*> m_sinks[5];
			std::vector<OnEventSink> m_onEventSinks;
			ISystem* m_pISystem;
			std::vector<CEntity*> m_EntityArray;
			std::vector<CEntity*> m_deletedEntities;
			std::vector<CEntity*> m_deferredUsedEntities;
			std::map<uint32_t, CEntity*, std::less<uint32_t>, std::allocator<std::pair<const uint32_t, CEntity*>>> m_mapActiveEntities;
			bool m_tempActiveEntitiesValid;
			undefined field17_0x139;
			undefined field18_0x13a;
			undefined field19_0x13b;
			undefined field20_0x13c;
			undefined field21_0x13d;
			undefined field22_0x13e;
			undefined field23_0x13f;
			std::set<uint32_t, std::less<uint32_t>, std::allocator<uint32_t>> m_mapPrePhysicsEntities;
			char pad[16];
			//std::multimap<const char*, uint32_t, stl::less_stricmp<charconst*>, std::allocator<std::pair<const char* , uint32_t>>> m_mapEntityNames;
			char pad2[262136];
			//CSaltBufferArray<unsigned short, unsigned short, 65533> m_EntitySaltBuffer;
			std::vector<uint32_t, std::allocator<uint32_t>> m_tempActiveEntities;
			char pad3[8];
			//CComponentEventDistributer* m_pEventDistributer;
			char pad5[16];
			//std::multimap<CTimeValue, SEntityTimerEvent, std::less<CTimeValue>, stl::STLPoolAllocator<std::pair<CTimeValue, SEntityTimerEvent>, stl::PSyncNone, 0, 0>> m_timersMap;
			std::vector<SEntityTimerEvent, std::allocator<SEntityTimerEvent>> m_currentTimers;
			bool m_bTimersPause;
			undefined field32_0x401a1;
			undefined field33_0x401a2;
			undefined field34_0x401a3;
			undefined field35_0x401a4;
			undefined field36_0x401a5;
			undefined field37_0x401a6;
			undefined field38_0x401a7;
			CTimeValue m_nStartPause;
			CScriptBind_Entity* m_pEntityScriptBinding;
			CEntityClassRegistry* m_pClassRegistry;
			CPhysicsEventListener* m_pPhysicsEventListener;
			CAreaManager* m_pAreaManager;
			CEntityLoadManager* m_pEntityLoadManager;
			CEntityPoolManager* m_pEntityPoolManager;
			std::multimap<uint32_t, IEntityEventListener*, std::less<uint32_t>, std::allocator<std::pair<const uint32_t, IEntityEventListener*>>> m_eventListeners[60];
			int m_eventListenerBeingProcessedRefCount;
			undefined field48_0x405a4;
			undefined field49_0x405a5;
			undefined field50_0x405a6;
			undefined field51_0x405a7;
			std::map<unsigned __int64, uint32_t, std::less<unsigned __int64>, std::allocator<std::pair<const unsigned __int64, uint32_t>>> m_guidMap;
			std::map<unsigned __int64, uint32_t, std::less<unsigned __int64>, std::allocator<std::pair<const unsigned __int64, uint32_t>>> m_genIdMap;
			IBreakableManager* m_pBreakableManager;
			CEntityArchetypeManager* m_pEntityArchetypeManager;
			CGeomCacheAttachmentManager* m_pGeomCacheAttachmentManager;
			CCharacterBoneAttachmentManager* m_pCharacterBoneAttachmentManager;
			CPartitionGrid* m_pPartitionGrid;
			CProximityTriggerSystem* m_pProximityTriggerSystem;
			uint32_t m_idForced;
			bool m_bLocked;
			undefined field62_0x405fd;
			undefined field63_0x405fe;
			undefined field64_0x405ff;
			char pad4[16];
			//CEntityTimeoutList m_entityTimeoutList;
			std::map<CryStringT<char>, CEntityLayer*, std::less<CryStringT<char>>, std::allocator<std::pair<CryStringT<char>const, CEntityLayer*>>> m_layers;
			std::vector<SEntityLayerGarbage, std::allocator<SEntityLayerGarbage>> m_garbageLayerHeaps;
			std::set<const IEntity*, std::less<const IEntity*>, std::allocator<const IEntity*>> m_EntitiesUsingPlayerTime;
			std::vector<const IEntityClass*, std::allocator<const IEntityClass*>> m_areaTriggeringClasses;
			AABB m_safeBounds;
			bool m_bReseting;
			undefined field72_0x40679;
			undefined field73_0x4067a;
			undefined field74_0x4067b;
			undefined field75_0x4067c;
			undefined field76_0x4067d;
			undefined field77_0x4067e;
			undefined field78_0x4067f;
		};
		enum class EHostMigrationState {

			eHMS_NotMigrating = 0,
			eHMS_WaitingForPlayers = 1,
			eHMS_Resuming = 2
		};

		enum class ERichPresenceState {

			eRPS_none = 0,
			eRPS_idle = 1,
			eRPS_frontend = 2,
			eRPS_lobby = 3,
			eRPS_inGame = 4
		};

		enum class EInviteAcceptedState {

			eIAS_None = 0,
			eIAS_Init = 1,
			eIAS_StartAcceptInvite = 2,
			eIAS_InitProfile = 3,
			eIAS_WaitForInitProfile = 4,
			eIAS_WaitForLoadToFinish = 5,
			eIAS_DisconnectGame = 6,
			eIAS_DisconnectLobby = 7,
			eIAS_WaitForSessionDelete = 8,
			eIAS_ConfirmInvite = 9,
			eIAS_WaitForInviteConfirmation = 10,
			eIAS_InitSinglePlayer = 11,
			eIAS_WaitForInitSinglePlayer = 12,
			eIAS_WaitForSplashScreen = 13,
			eIAS_WaitForValidUser = 14,
			eIAS_InitMultiplayer = 15,
			eIAS_WaitForInitMultiplayer = 16,
			eIAS_InitOnline = 17,
			eIAS_WaitForInitOnline = 18,
			eIAS_WaitForSquadManagerEnabled = 19,
			eIAS_Accept = 20,
			eIAS_Error = 21
		};

		enum class ESaveIconMode {

			eSIM_Off = 0,
			eSIM_SaveStart = 1,
			eSIM_Saving = 2,
			eSIM_Finished = 3
		};

		enum class EPlatform {

			ePlatform_Unknown = 0,
			ePlatform_PC = 1,
			ePlatform_XBoxOne = 2,
			ePlatform_PS4 = 3,
			ePlatform_COUNT = 4
		};

		enum class State {

			Idle = 0,
			UpdatingModules = 1
		};

		enum class EControlScheme {

			eControlScheme_NotSpecified = 0,
			eControlScheme_Keyboard = 1,
			eControlScheme_KeyboardMouse = 2,
			eControlScheme_XBoxOneController = 3,
			eControlScheme_PS4Controller = 4,
			eControlScheme_SteamController = 5
		};

		enum class ECryLobbyService {

			eCLS_LAN = 0,
			eCLS_Online = 1,
			eCLS_NumServices = 2
		};

		enum class ECryLobbyError {

			eCLE_Success = 0,
			eCLE_SuccessContinue = 1,
			eCLE_ServiceNotSupported = 2,
			eCLE_AlreadyInitialised = 3,
			eCLE_NotInitialised = 4,
			eCLE_TooManyTasks = 5,
			eCLE_OutOfMemory = 6,
			eCLE_OutOfSessionUserData = 7,
			eCLE_UserDataNotRegistered = 8,
			eCLE_UserDataTypeMissMatch = 9,
			eCLE_TooManySessions = 10,
			eCLE_InvalidSession = 11,
			eCLE_InvalidRequest = 12,
			eCLE_SPAFileOutOfDate = 13,
			eCLE_ConnectionFailed = 14,
			eCLE_SessionFull = 15,
			eCLE_SessionWrongState = 16,
			eCLE_UserNotSignedIn = 17,
			eCLE_InvalidParam = 18,
			eCLE_TimeOut = 19,
			eCLE_InsufficientPrivileges = 20,
			eCLE_AlreadyInSession = 21,
			eCLE_LeaderBoardNotRegistered = 22,
			eCLE_UserNotInSession = 23,
			eCLE_OutOfUserData = 24,
			eCLE_NoUserDataRegistered = 25,
			eCLE_ReadDataNotWritten = 26,
			eCLE_UserDataMissMatch = 27,
			eCLE_InvalidUser = 28,
			eCLE_PSNContextError = 29,
			eCLE_PSNWrongSupportState = 30,
			eCLE_SuccessUnreachable = 31,
			eCLE_ServerNotDefined = 32,
			eCLE_WorldNotDefined = 33,
			eCLE_SystemIsBusy = 34,
			eCLE_TooManyParameters = 35,
			eCLE_NotEnoughParameters = 36,
			eCLE_DuplicateParameters = 37,
			eCLE_ExceededReadWriteLimits = 38,
			eCLE_InvalidTitleID = 39,
			eCLE_IllegalSessionJoin = 40,
			eCLE_InternetDisabled = 41,
			eCLE_NoOnlineAccount = 42,
			eCLE_NotConnected = 43,
			eCLE_CyclingForInvite = 44,
			eCLE_CableNotConnected = 45,
			eCLE_SessionNotMigratable = 46,
			eCLE_SuccessInvalidSession = 47,
			eCLE_RoomDoesNotExist = 48,
			eCLE_PSNUnavailable = 49,
			eCLE_TooManyOrders = 50,
			eCLE_InvalidOrder = 51,
			eCLE_OrderInUse = 52,
			eCLE_OnlineAccountBlocked = 53,
			eCLE_AgeRestricted = 54,
			eCLE_ReadDataCorrupt = 55,
			eCLE_PasswordIncorrect = 56,
			eCLE_InvalidInviteFriendData = 57,
			eCLE_InvalidJoinFriendData = 58,
			eCLE_InvalidPing = 60,
			eCLE_CDKeyMalformed = 61,
			eCLE_CDKeyUnknown = 62,
			eCLE_CDKeyAuthFailed = 63,
			eCLE_CDKeyDisabled = 64,
			eCLE_CDKeyInUse = 65,
			eCLE_MultipleSignIn = 66,
			eCLE_Banned = 67,
			eCLE_CDKeyTimeOut = 68,
			eCLE_IncompleteLoginCredentials = 69,
			eCLE_WrongVersion = 70,
			eCLE_NoServerAvailable = 71,
			eCLE_ArbitratorTimeOut = 72,
			eCLE_RequiresInvite = 73,
			eCLE_SteamInitFailed = 74,
			eCLE_SteamBlocked = 75,
			eCLE_NothingToEnumerate = 76,
			eCLE_ServiceNotConnected = 77,
			eCLE_GlobalBan = 78,
			eCLE_Cancelled = 79,
			eCLE_Kicked = 79,
			eCLE_UnhandledNickError = 80,
			eCLE_InternalError = 81,
			eCLE_NumErrors = 82
		};

		enum class ECryLobbyInviteType {

			eCLIT_InviteToSquad = 0,
			eCLIT_JoinSessionInProgress = 1,
			eCLIT_InviteToSession = 2
		};

		enum class AsyncState {

			AsyncFailed = 0,
			AsyncReady = 1,
			AsyncInProgress = 2,
			AsyncComplete = 3
		};


		

		
		
		class DeferredDeathReaction {
		public:
			std::multimap<float, uint32_t, std::less<float>> potentialWitnesses;
			Vec3 deathPos;
			uint32_t victimID,
				closestID,
				witnessID,
				killerID;
			int32_t groupID;
			float timestamp;
			unsigned char state;
			char pad[3];
		};
		class DeadBody {
		public:
			Vec3 position;
			int32_t groupID;
			uint32_t entityID,
				killerID;
		};
		class DeathManager {
		public:
			undefined field0_0x0;
			undefined field1_0x1;
			undefined field2_0x2;
			undefined field3_0x3;
			undefined field4_0x4;
			undefined field5_0x5;
			undefined field6_0x6;
			undefined field7_0x7;
			std::vector<DeferredDeathReaction> m_deferredDeathReactions;
			std::vector<DeadBody> m_unseenDeadBodies;
			enum AsyncState m_asyncState;
			uint32_t m_rayID;
		};
		class SPlatformInfo {
		public:
			EPlatform platformId;
			unsigned char devices;
			char pad[3];
		};
		class CGameCache{};
		class IGameFramework{};
		class IConsole{};
		class CGamePhysicsSettings{};
		class CScriptBind_Actor				 {};
		class CScriptBind_Item				 {};
		class CScriptBind_GameRules			 {};
		class CScriptBind_Game				 {};
		class CScriptBind_GameAI			 {};
		class CScriptBind_HitDeathReactions	 {};
		class CScriptBind_ProtectedBinds	 {};
		class CPlayerVisTable				 {};
		class CDataPatchDownloader			 {};
		class IAntiCheatManager				 {};
		class CGameLocalizationManager		 {};
		class ITelemetryCollector			 {};
		class CGameActions					 {};
		class IPlayerProfileManager			 {};

		class SCVars {};
		class SItemStrings {};
		class CGameSharedParametersStorage {};
		class CScreenEffects{};
		class CDownloadMgr{};
		class CDLCManager{};
		class CLightningGameEffect{};
		class CParameterGameEffect{};
		class CWorldBuilder{};
		class IInputEventListener{};
		class CColorGradientManager{};
		class CGameAISystem{};
		
		// class IntersectionTestQueue<43>{};
		class CUIManager{};
		class CHitDeathReactionsSystem{};
		class CBodyDamageManager{};
		class CMovementTransitionsSystem{};
		class CGameMechanismManager{};
		class CModInfoManager{};
		class SCrySessionID {};
		template<uint32_t i> class RayCastQueue {
			public:
				undefined field0_0x0;
				undefined field1_0x1;
				undefined field2_0x2;
				undefined field3_0x3;
				undefined field4_0x4;
				undefined field5_0x5;
				undefined field6_0x6;
				undefined field7_0x7;
				undefined field8_0x8;
				undefined field9_0x9;
				undefined field10_0xa;
				undefined field11_0xb;
				undefined field12_0xc;
				undefined field13_0xd;
				undefined field14_0xe;
				undefined field15_0xf;
				undefined field16_0x10;
				undefined field17_0x11;
				undefined field18_0x12;
				undefined field19_0x13;
				undefined field20_0x14;
				undefined field21_0x15;
				undefined field22_0x16;
				undefined field23_0x17;
				undefined field24_0x18;
				undefined field25_0x19;
				undefined field26_0x1a;
				undefined field27_0x1b;
				undefined field28_0x1c;
				undefined field29_0x1d;
				undefined field30_0x1e;
				undefined field31_0x1f;
				undefined field32_0x20;
				undefined field33_0x21;
				undefined field34_0x22;
				undefined field35_0x23;
				undefined field36_0x24;
				undefined field37_0x25;
				undefined field38_0x26;
				undefined field39_0x27;
				undefined field40_0x28;
				undefined field41_0x29;
				undefined field42_0x2a;
				undefined field43_0x2b;
				undefined field44_0x2c;
				undefined field45_0x2d;
				undefined field46_0x2e;
				undefined field47_0x2f;
				undefined field48_0x30;
				undefined field49_0x31;
				undefined field50_0x32;
				undefined field51_0x33;
				undefined field52_0x34;
				undefined field53_0x35;
				undefined field54_0x36;
				undefined field55_0x37;
				undefined field56_0x38;
				undefined field57_0x39;
				undefined field58_0x3a;
				undefined field59_0x3b;
				undefined field60_0x3c;
				undefined field61_0x3d;
				undefined field62_0x3e;
				undefined field63_0x3f;
				undefined field64_0x40;
				undefined field65_0x41;
				undefined field66_0x42;
				undefined field67_0x43;
				undefined field68_0x44;
				undefined field69_0x45;
				undefined field70_0x46;
				undefined field71_0x47;
				undefined field72_0x48;
				undefined field73_0x49;
				undefined field74_0x4a;
				undefined field75_0x4b;
				undefined field76_0x4c;
				undefined field77_0x4d;
				undefined field78_0x4e;
				undefined field79_0x4f;
				undefined field80_0x50;
				undefined field81_0x51;
				undefined field82_0x52;
				undefined field83_0x53;
				undefined field84_0x54;
				undefined field85_0x55;
				undefined field86_0x56;
				undefined field87_0x57;
				undefined field88_0x58;
				undefined field89_0x59;
				undefined field90_0x5a;
				undefined field91_0x5b;
				undefined field92_0x5c;
				undefined field93_0x5d;
				undefined field94_0x5e;
				undefined field95_0x5f;
				undefined field96_0x60;
				undefined field97_0x61;
				undefined field98_0x62;
				undefined field99_0x63;
				undefined field100_0x64;
				undefined field101_0x65;
				undefined field102_0x66;
				undefined field103_0x67;
				undefined field104_0x68;
				undefined field105_0x69;
				undefined field106_0x6a;
				undefined field107_0x6b;
				undefined field108_0x6c;
				undefined field109_0x6d;
				undefined field110_0x6e;
				undefined field111_0x6f;
				undefined field112_0x70;
				undefined field113_0x71;
				undefined field114_0x72;
				undefined field115_0x73;
				undefined field116_0x74;
				undefined field117_0x75;
				undefined field118_0x76;
				undefined field119_0x77;
				undefined field120_0x78;
				undefined field121_0x79;
				undefined field122_0x7a;
				undefined field123_0x7b;
				undefined field124_0x7c;
				undefined field125_0x7d;
				undefined field126_0x7e;
				undefined field127_0x7f;
				undefined field128_0x80;
				undefined field129_0x81;
				undefined field130_0x82;
				undefined field131_0x83;
				undefined field132_0x84;
				undefined field133_0x85;
				undefined field134_0x86;
				undefined field135_0x87;
				undefined field136_0x88;
				undefined field137_0x89;
				undefined field138_0x8a;
				undefined field139_0x8b;
				undefined field140_0x8c;
				undefined field141_0x8d;
				undefined field142_0x8e;
				undefined field143_0x8f;
				undefined field144_0x90;
				undefined field145_0x91;
				undefined field146_0x92;
				undefined field147_0x93;
				undefined field148_0x94;
				undefined field149_0x95;
				undefined field150_0x96;
				undefined field151_0x97;
				undefined field152_0x98;
				undefined field153_0x99;
				undefined field154_0x9a;
				undefined field155_0x9b;
				undefined field156_0x9c;
				undefined field157_0x9d;
				undefined field158_0x9e;
				undefined field159_0x9f;
				undefined field160_0xa0;
				undefined field161_0xa1;
				undefined field162_0xa2;
				undefined field163_0xa3;
				undefined field164_0xa4;
				undefined field165_0xa5;
				undefined field166_0xa6;
				undefined field167_0xa7;
				undefined field168_0xa8;
				undefined field169_0xa9;
				undefined field170_0xaa;
				undefined field171_0xab;
				undefined field172_0xac;
				undefined field173_0xad;
				undefined field174_0xae;
				undefined field175_0xaf;
				undefined field176_0xb0;
				undefined field177_0xb1;
				undefined field178_0xb2;
				undefined field179_0xb3;
				undefined field180_0xb4;
				undefined field181_0xb5;
				undefined field182_0xb6;
				undefined field183_0xb7;
				undefined field184_0xb8;
				undefined field185_0xb9;
				undefined field186_0xba;
				undefined field187_0xbb;
				undefined field188_0xbc;
				undefined field189_0xbd;
				undefined field190_0xbe;
				undefined field191_0xbf;
				undefined field192_0xc0;
				undefined field193_0xc1;
				undefined field194_0xc2;
				undefined field195_0xc3;
				undefined field196_0xc4;
				undefined field197_0xc5;
				undefined field198_0xc6;
				undefined field199_0xc7;
				undefined field200_0xc8;
				undefined field201_0xc9;
				undefined field202_0xca;
				undefined field203_0xcb;
				undefined field204_0xcc;
				undefined field205_0xcd;
				undefined field206_0xce;
				undefined field207_0xcf;
				undefined field208_0xd0;
				undefined field209_0xd1;
				undefined field210_0xd2;
				undefined field211_0xd3;
				undefined field212_0xd4;
				undefined field213_0xd5;
				undefined field214_0xd6;
				undefined field215_0xd7;
				undefined field216_0xd8;
				undefined field217_0xd9;
				undefined field218_0xda;
				undefined field219_0xdb;
				undefined field220_0xdc;
				undefined field221_0xdd;
				undefined field222_0xde;
				undefined field223_0xdf;
				undefined field224_0xe0;
				undefined field225_0xe1;
				undefined field226_0xe2;
				undefined field227_0xe3;
				undefined field228_0xe4;
				undefined field229_0xe5;
				undefined field230_0xe6;
				undefined field231_0xe7;
				undefined field232_0xe8;
				undefined field233_0xe9;
				undefined field234_0xea;
				undefined field235_0xeb;
				undefined field236_0xec;
				undefined field237_0xed;
				undefined field238_0xee;
				undefined field239_0xef;
				undefined field240_0xf0;
				undefined field241_0xf1;
				undefined field242_0xf2;
				undefined field243_0xf3;
				undefined field244_0xf4;
				undefined field245_0xf5;
				undefined field246_0xf6;
				undefined field247_0xf7;
				undefined field248_0xf8;
				undefined field249_0xf9;
				undefined field250_0xfa;
				undefined field251_0xfb;
				undefined field252_0xfc;
				undefined field253_0xfd;
				undefined field254_0xfe;
				undefined field255_0xff;
				undefined field256_0x100;
				undefined field257_0x101;
				undefined field258_0x102;
				undefined field259_0x103;
				undefined field260_0x104;
				undefined field261_0x105;
				undefined field262_0x106;
				undefined field263_0x107;
				undefined field264_0x108;
				undefined field265_0x109;
				undefined field266_0x10a;
				undefined field267_0x10b;
				undefined field268_0x10c;
				undefined field269_0x10d;
				undefined field270_0x10e;
				undefined field271_0x10f;
				undefined field272_0x110;
				undefined field273_0x111;
				undefined field274_0x112;
				undefined field275_0x113;
				undefined field276_0x114;
				undefined field277_0x115;
				undefined field278_0x116;
				undefined field279_0x117;
				undefined field280_0x118;
				undefined field281_0x119;
				undefined field282_0x11a;
				undefined field283_0x11b;
				undefined field284_0x11c;
				undefined field285_0x11d;
				undefined field286_0x11e;
				undefined field287_0x11f;
				undefined field288_0x120;
				undefined field289_0x121;
				undefined field290_0x122;
				undefined field291_0x123;
				undefined field292_0x124;
				undefined field293_0x125;
				undefined field294_0x126;
				undefined field295_0x127;
				undefined field296_0x128;
				undefined field297_0x129;
				undefined field298_0x12a;
				undefined field299_0x12b;
				undefined field300_0x12c;
				undefined field301_0x12d;
				undefined field302_0x12e;
				undefined field303_0x12f;
				undefined field304_0x130;
				undefined field305_0x131;
				undefined field306_0x132;
				undefined field307_0x133;
				undefined field308_0x134;
				undefined field309_0x135;
				undefined field310_0x136;
				undefined field311_0x137;
				undefined field312_0x138;
				undefined field313_0x139;
				undefined field314_0x13a;
				undefined field315_0x13b;
				undefined field316_0x13c;
				undefined field317_0x13d;
				undefined field318_0x13e;
				undefined field319_0x13f;
				undefined field320_0x140;
				undefined field321_0x141;
				undefined field322_0x142;
				undefined field323_0x143;
				undefined field324_0x144;
				undefined field325_0x145;
				undefined field326_0x146;
				undefined field327_0x147;
				undefined field328_0x148;
				undefined field329_0x149;
				undefined field330_0x14a;
				undefined field331_0x14b;
				undefined field332_0x14c;
				undefined field333_0x14d;
				undefined field334_0x14e;
				undefined field335_0x14f;
				undefined field336_0x150;
				undefined field337_0x151;
				undefined field338_0x152;
				undefined field339_0x153;
				undefined field340_0x154;
				undefined field341_0x155;
				undefined field342_0x156;
				undefined field343_0x157;
				undefined field344_0x158;
				undefined field345_0x159;
				undefined field346_0x15a;
				undefined field347_0x15b;
				undefined field348_0x15c;
				undefined field349_0x15d;
				undefined field350_0x15e;
				undefined field351_0x15f;
				undefined field352_0x160;
				undefined field353_0x161;
				undefined field354_0x162;
				undefined field355_0x163;
				undefined field356_0x164;
				undefined field357_0x165;
				undefined field358_0x166;
				undefined field359_0x167;
				undefined field360_0x168;
				undefined field361_0x169;
				undefined field362_0x16a;
				undefined field363_0x16b;
				undefined field364_0x16c;
				undefined field365_0x16d;
				undefined field366_0x16e;
				undefined field367_0x16f;
				undefined field368_0x170;
				undefined field369_0x171;
				undefined field370_0x172;
				undefined field371_0x173;
				undefined field372_0x174;
				undefined field373_0x175;
				undefined field374_0x176;
				undefined field375_0x177;
				undefined field376_0x178;
				undefined field377_0x179;
				undefined field378_0x17a;
				undefined field379_0x17b;
				undefined field380_0x17c;
				undefined field381_0x17d;
				undefined field382_0x17e;
				undefined field383_0x17f;
				undefined field384_0x180;
				undefined field385_0x181;
				undefined field386_0x182;
				undefined field387_0x183;
				undefined field388_0x184;
				undefined field389_0x185;
				undefined field390_0x186;
				undefined field391_0x187;
				undefined field392_0x188;
				undefined field393_0x189;
				undefined field394_0x18a;
				undefined field395_0x18b;
				undefined field396_0x18c;
				undefined field397_0x18d;
				undefined field398_0x18e;
				undefined field399_0x18f;
				undefined field400_0x190;
				undefined field401_0x191;
				undefined field402_0x192;
				undefined field403_0x193;
				undefined field404_0x194;
				undefined field405_0x195;
				undefined field406_0x196;
				undefined field407_0x197;
				undefined field408_0x198;
				undefined field409_0x199;
				undefined field410_0x19a;
				undefined field411_0x19b;
				undefined field412_0x19c;
				undefined field413_0x19d;
				undefined field414_0x19e;
				undefined field415_0x19f;
				undefined field416_0x1a0;
				undefined field417_0x1a1;
				undefined field418_0x1a2;
				undefined field419_0x1a3;
				undefined field420_0x1a4;
				undefined field421_0x1a5;
				undefined field422_0x1a6;
				undefined field423_0x1a7;
				undefined field424_0x1a8;
				undefined field425_0x1a9;
				undefined field426_0x1aa;
				undefined field427_0x1ab;
				undefined field428_0x1ac;
				undefined field429_0x1ad;
				undefined field430_0x1ae;
				undefined field431_0x1af;
				undefined field432_0x1b0;
				undefined field433_0x1b1;
				undefined field434_0x1b2;
				undefined field435_0x1b3;
				undefined field436_0x1b4;
				undefined field437_0x1b5;
				undefined field438_0x1b6;
				undefined field439_0x1b7;
				undefined field440_0x1b8;
				undefined field441_0x1b9;
				undefined field442_0x1ba;
				undefined field443_0x1bb;
				undefined field444_0x1bc;
				undefined field445_0x1bd;
				undefined field446_0x1be;
				undefined field447_0x1bf;
				undefined field448_0x1c0;
				undefined field449_0x1c1;
				undefined field450_0x1c2;
				undefined field451_0x1c3;
				undefined field452_0x1c4;
				undefined field453_0x1c5;
				undefined field454_0x1c6;
				undefined field455_0x1c7;
				undefined field456_0x1c8;
				undefined field457_0x1c9;
				undefined field458_0x1ca;
				undefined field459_0x1cb;
				undefined field460_0x1cc;
				undefined field461_0x1cd;
				undefined field462_0x1ce;
				undefined field463_0x1cf;
				undefined field464_0x1d0;
				undefined field465_0x1d1;
				undefined field466_0x1d2;
				undefined field467_0x1d3;
				undefined field468_0x1d4;
				undefined field469_0x1d5;
				undefined field470_0x1d6;
				undefined field471_0x1d7;
				undefined field472_0x1d8;
				undefined field473_0x1d9;
				undefined field474_0x1da;
				undefined field475_0x1db;
				undefined field476_0x1dc;
				undefined field477_0x1dd;
				undefined field478_0x1de;
				undefined field479_0x1df;
				undefined field480_0x1e0;
				undefined field481_0x1e1;
				undefined field482_0x1e2;
				undefined field483_0x1e3;
				undefined field484_0x1e4;
				undefined field485_0x1e5;
				undefined field486_0x1e6;
				undefined field487_0x1e7;
				undefined field488_0x1e8;
				undefined field489_0x1e9;
				undefined field490_0x1ea;
				undefined field491_0x1eb;
				undefined field492_0x1ec;
				undefined field493_0x1ed;
				undefined field494_0x1ee;
				undefined field495_0x1ef;
				undefined field496_0x1f0;
				undefined field497_0x1f1;
				undefined field498_0x1f2;
				undefined field499_0x1f3;
				undefined field500_0x1f4;
				undefined field501_0x1f5;
				undefined field502_0x1f6;
				undefined field503_0x1f7;
				undefined field504_0x1f8;
				undefined field505_0x1f9;
				undefined field506_0x1fa;
				undefined field507_0x1fb;
				undefined field508_0x1fc;
				undefined field509_0x1fd;
				undefined field510_0x1fe;
				undefined field511_0x1ff;
				undefined field512_0x200;
				undefined field513_0x201;
				undefined field514_0x202;
				undefined field515_0x203;
				undefined field516_0x204;
				undefined field517_0x205;
				undefined field518_0x206;
				undefined field519_0x207;
				undefined field520_0x208;
				undefined field521_0x209;
				undefined field522_0x20a;
				undefined field523_0x20b;
				undefined field524_0x20c;
				undefined field525_0x20d;
				undefined field526_0x20e;
				undefined field527_0x20f;
				undefined field528_0x210;
				undefined field529_0x211;
				undefined field530_0x212;
				undefined field531_0x213;
				undefined field532_0x214;
				undefined field533_0x215;
				undefined field534_0x216;
				undefined field535_0x217;
				undefined field536_0x218;
				undefined field537_0x219;
				undefined field538_0x21a;
				undefined field539_0x21b;
				undefined field540_0x21c;
				undefined field541_0x21d;
				undefined field542_0x21e;
				undefined field543_0x21f;
				undefined field544_0x220;
				undefined field545_0x221;
				undefined field546_0x222;
				undefined field547_0x223;
				undefined field548_0x224;
				undefined field549_0x225;
				undefined field550_0x226;
				undefined field551_0x227;
				undefined field552_0x228;
				undefined field553_0x229;
				undefined field554_0x22a;
				undefined field555_0x22b;
				undefined field556_0x22c;
				undefined field557_0x22d;
				undefined field558_0x22e;
				undefined field559_0x22f;
				undefined field560_0x230;
				undefined field561_0x231;
				undefined field562_0x232;
				undefined field563_0x233;
				undefined field564_0x234;
				undefined field565_0x235;
				undefined field566_0x236;
				undefined field567_0x237;
				undefined field568_0x238;
				undefined field569_0x239;
				undefined field570_0x23a;
				undefined field571_0x23b;
				undefined field572_0x23c;
				undefined field573_0x23d;
				undefined field574_0x23e;
				undefined field575_0x23f;
				undefined field576_0x240;
				undefined field577_0x241;
				undefined field578_0x242;
				undefined field579_0x243;
				undefined field580_0x244;
				undefined field581_0x245;
				undefined field582_0x246;
				undefined field583_0x247;
				undefined field584_0x248;
				undefined field585_0x249;
				undefined field586_0x24a;
				undefined field587_0x24b;
				undefined field588_0x24c;
				undefined field589_0x24d;
				undefined field590_0x24e;
				undefined field591_0x24f;
				undefined field592_0x250;
				undefined field593_0x251;
				undefined field594_0x252;
				undefined field595_0x253;
				undefined field596_0x254;
				undefined field597_0x255;
				undefined field598_0x256;
				undefined field599_0x257;
				undefined field600_0x258;
				undefined field601_0x259;
				undefined field602_0x25a;
				undefined field603_0x25b;
				undefined field604_0x25c;
				undefined field605_0x25d;
				undefined field606_0x25e;
				undefined field607_0x25f;
				undefined field608_0x260;
				undefined field609_0x261;
				undefined field610_0x262;
				undefined field611_0x263;
				undefined field612_0x264;
				undefined field613_0x265;
				undefined field614_0x266;
				undefined field615_0x267;
				undefined field616_0x268;
				undefined field617_0x269;
				undefined field618_0x26a;
				undefined field619_0x26b;
				undefined field620_0x26c;
				undefined field621_0x26d;
				undefined field622_0x26e;
				undefined field623_0x26f;
				undefined field624_0x270;
				undefined field625_0x271;
				undefined field626_0x272;
				undefined field627_0x273;
				undefined field628_0x274;
				undefined field629_0x275;
				undefined field630_0x276;
				undefined field631_0x277;
				undefined field632_0x278;
				undefined field633_0x279;
				undefined field634_0x27a;
				undefined field635_0x27b;
				undefined field636_0x27c;
				undefined field637_0x27d;
				undefined field638_0x27e;
				undefined field639_0x27f;
		};
		template<uint32_t i> class IntersectionTestQueue {
		public:
			void* ptr;
			void* ptrArray[i];
		};
		class IRenderSceneListener {};

		class SInviteAcceptedData {
		public:
			ECryLobbyService m_service;
			uint32_t m_user;
			SCrySessionID* m_id;
			ECryLobbyError m_error;
			ECryLobbyInviteType m_type;
			bool m_bannedFromSession;
			bool m_failedToAcceptInviteAsNotSignedIn;
		};
		class ArkAiManager{};
		class ArkAttentionManager{};
		class ArkAttractionManager{};
		class ArkAuralPerceptionManager{};
		class ArkCharacterManager{};
		class ArkCombatManager{};
		class ArkCystoidManager{};
		class ArkDistractionEntitySink{};
		class ArkDistractionManager{};
		class ArkDynamicCorpseManager{};
		class ArkEncounterManager{};
		class CArkFlowGraphManager{};
		class ArkEthericFogManager{};
		class ArkFactionManager{};
		class ArkGameDataManager{};
		class ArkGlintConfigManager{};
		class CArkGlooIslandNavLinkManager{};
		class ArkInstigationManager{};
		class ArkLightTimeManager{};
		class ArkListenerManager{};
		class ArkLurkManager{};
		class ArkMetaTagManager{};
		class ArkNightmareEtherformManager{};
		class ArkNightmareSpawnManager{};
		class ArkNpcAbilityManager{};
		class ArkNpcAreaManager{};
		class ArkNpcBlackboardManager{};
		class ArkNpcGameEffectManager{};
		class ArkNpcManager{};
		class ArkNpcSpawnManager{}; // 0x358
		class ArkNpcThrowPropManager{};
		class ArkNpcUnreachableTargetingManager{};
		class CArkPADialogManager{};
		class ArkPatrolManager{};
		class ArkPostEffectManager{};
		class CArkProjectileGooNetworkManager{};
		class CArkProjectileGooPhysicsManager{};
		class CArkProjectilePoolManager{};
		class ArkResponseManager{};
		class ArkRetreatManager{};
		class ArkRoomPerceptionManager{};
		class ArkSpatialManager{};
		class ArkTimeScaleManager{};
		class ArkVisualPerceptionManager{};
		class ArkWorldUIManager{};
		class CScriptBind_ArkBreakable{};
		class CScriptBind_ArkItem{};
		class CScriptBind_ArkFaction{};
		class CScriptBind_ArkKiosk{};
		class CScriptBind_ArkNpc{};
		class CScriptBind_ArkRoster{};
		class CScriptBind_ArkTurret{};
		class CScriptBind_Inventory{};
		class CScriptBind_ItemSystem{};
		class CScriptBind_LightningArc{};
		class ArkGame{};
		class ArkActiveUserManagerBase{};

		class CGame {
		public:
			undefined field0_0x0;
			undefined field1_0x1;
			undefined field2_0x2;
			undefined field3_0x3;
			undefined field4_0x4;
			undefined field5_0x5;
			undefined field6_0x6;
			undefined field7_0x7;
			undefined field8_0x8;
			undefined field9_0x9;
			undefined field10_0xa;
			undefined field11_0xb;
			undefined field12_0xc;
			undefined field13_0xd;
			undefined field14_0xe;
			undefined field15_0xf;
			undefined field16_0x10;
			undefined field17_0x11;
			undefined field18_0x12;
			undefined field19_0x13;
			undefined field20_0x14;
			undefined field21_0x15;
			undefined field22_0x16;
			undefined field23_0x17;
			undefined field24_0x18;
			undefined field25_0x19;
			undefined field26_0x1a;
			undefined field27_0x1b;
			undefined field28_0x1c;
			undefined field29_0x1d;
			undefined field30_0x1e;
			undefined field31_0x1f;
			undefined field32_0x20;
			undefined field33_0x21;
			undefined field34_0x22;
			undefined field35_0x23;
			undefined field36_0x24;
			undefined field37_0x25;
			undefined field38_0x26;
			undefined field39_0x27;
			undefined field40_0x28;
			undefined field41_0x29;
			undefined field42_0x2a;
			undefined field43_0x2b;
			undefined field44_0x2c;
			undefined field45_0x2d;
			undefined field46_0x2e;
			undefined field47_0x2f;
			SPlatformInfo m_platformInfo;
			CGameCache* m_pGameCache;
			CRndGen m_randomGenerator;
			IGameFramework* m_pFramework;
			IConsole* m_pConsole;
			CGamePhysicsSettings* m_pGamePhysicsSettings;
			bool m_bReload;
			bool m_gameTypeMultiplayer;
			bool m_gameTypeInitialized;
			bool m_userProfileChanged;
			bool m_bLastSaveDirty;
			bool m_needsInitPatchables;
			bool m_editorDisplayHelpers;
			undefined field61_0x67;
			CScriptBind_Actor* m_pScriptBindActor;
			CScriptBind_Item* m_pScriptBindItem;
			CScriptBind_GameRules* m_pScriptBindGameRules;
			CScriptBind_Game* m_pScriptBindGame;
			CScriptBind_GameAI* m_pScriptBindGameAI;
			CScriptBind_HitDeathReactions* m_pScriptBindHitDeathReactions;
			CScriptBind_ProtectedBinds* m_pScriptBindProtected;
			CPlayerVisTable* m_pPlayerVisTable;
			CDataPatchDownloader* m_pDataPatchDownloader;
			IAntiCheatManager* m_pAntiCheatManager;
			CGameLocalizationManager* m_pGameLocalizationManager;
			ITelemetryCollector* m_telemetryCollector;
			CGameActions* m_pGameActions;
			IPlayerProfileManager* m_pPlayerProfileManager;
			bool m_inDevMode;
			bool m_hasExclusiveController;
			bool m_bExclusiveControllerConnected;
			bool m_rebindExclusiveControllerOnNextInput;
			bool m_bPausedForControllerDisconnect;
			bool m_bPausedForSystemMenu;
			bool m_bDeferredSystemMenuPause;
			bool m_previousPausedGameState;
			bool m_wasGamePausedByPLM;
			undefined field85_0xe1;
			undefined field86_0xe2;
			undefined field87_0xe3;
			undefined field88_0xe4;
			undefined field89_0xe5;
			undefined field90_0xe6;
			undefined field91_0xe7;
			uint64_t m_exclusiveControllerDeviceId;
			int32_t m_currentXboxLivePartySize;
			uint32_t m_clientActorId;
			SCVars* m_pCVars;
			SItemStrings* m_pItemStrings;
			CGameSharedParametersStorage* m_pGameParametersStorage;
			CryStringT<char> m_lastSaveGame;
			CScreenEffects* m_pScreenEffects;
			CDownloadMgr* m_pDownloadMgr;
			CDLCManager* m_pDLCManager;
			CLightningGameEffect* m_pLightningGameEffect;
			CParameterGameEffect* m_pParameterGameEffect;
			CWorldBuilder* m_pWorldBuilder;
			IInputEventListener* m_pInputEventListenerOverride;
			std::map<CryStringT<char>, CryStringT<char>> m_variantOptions;
			std::map<CryFixedStringT<128>, int32_t, std::less<CryFixedStringT<128>>, std::allocator<std::pair<CryFixedStringT<128>const, int32_t>>> m_richPresence;
			std::vector<IRenderSceneListener*, std::allocator<IRenderSceneListener*>> m_renderSceneListeners;
			CColorGradientManager* m_colorGradientManager;
			CGameAISystem* m_pGameAISystem;
			RayCastQueue<41>* m_pRayCaster;
			IntersectionTestQueue<43>* m_pIntersectionTester;
			CUIManager* m_pUIManager;
			CHitDeathReactionsSystem* m_pHitDeathReactionsSystem;
			CBodyDamageManager* m_pBodyDamageManager;
			CMovementTransitionsSystem* m_pMovementTransitionsSystem;
			CGameMechanismManager* m_gameMechanismManager;
			CModInfoManager* m_pModInfoManager;
			float m_hostMigrationTimeStateChanged;
			float m_hostMigrationNetTimeoutLength;
			EHostMigrationState m_hostMigrationState;
			ERichPresenceState m_desiredRichPresenceState;
			ERichPresenceState m_pendingRichPresenceState;
			ERichPresenceState m_currentRichPresenceState;
			SCrySessionID* m_pendingRichPresenceSessionID;
			SCrySessionID* m_currentRichPresenceSessionID;
			float m_updateRichPresenceTimer;
			bool m_settingRichPresence;
			bool m_bRefreshRichPresence;
			bool m_bSignInOrOutEventOccured;
			undefined field131_0x207;
			SInviteAcceptedData m_inviteAcceptedData;
			enum EInviteAcceptedState m_inviteAcceptedState;
			bool m_bLoggedInFromInvite;
			bool m_gameDataInstalled;
			bool m_postLocalisationBootChecksDone;
			undefined field137_0x22f;
			class CTimeValue m_levelStartTime;
			int32_t m_iCachedGsmValue;
			float m_fCachedGsmRangeValue;
			float m_fCachedGsmRangeStepValue;
			enum ESaveIconMode m_saveIconMode;
			float m_saveIconTimer;
			int32_t m_cachedUserRegion;
			bool m_bUserHasPhysicalStorage;
			bool m_bCheckPointSave;
			undefined field147_0x252;
			undefined field148_0x253;
			undefined field149_0x254;
			undefined field150_0x255;
			undefined field151_0x256;
			undefined field152_0x257;
			std::vector<uint32_t, std::allocator<uint32_t>> m_deferredKills;
			std::unique_ptr<ArkAiManager, std::default_delete<ArkAiManager>> m_pArkAiManager;
			std::unique_ptr<ArkAttentionManager, std::default_delete<ArkAttentionManager>> m_pArkAttentionManager;
			std::unique_ptr<ArkAttractionManager, std::default_delete<ArkAttractionManager>> m_pArkAttractionManager;
			std::unique_ptr<ArkAuralPerceptionManager, std::default_delete<ArkAuralPerceptionManager>> m_pArkAuralPerceptionManager;
			std::unique_ptr<ArkCharacterManager, std::default_delete<ArkCharacterManager>> m_pArkCharacterManager;
			std::unique_ptr<ArkCombatManager, std::default_delete<ArkCombatManager>> m_pArkCombatManager;
			std::unique_ptr<ArkCystoidManager, std::default_delete<ArkCystoidManager>> m_pArkCystoidManager;
			std::unique_ptr<ArkDistractionEntitySink, std::default_delete<ArkDistractionEntitySink>> m_pArkDistractionEntitySink;
			std::unique_ptr<ArkDistractionManager, std::default_delete<ArkDistractionManager>> m_pArkDistractionManager;
			std::unique_ptr<ArkDynamicCorpseManager, std::default_delete<ArkDynamicCorpseManager>> m_pArkDynamicCorpseManager;
			std::unique_ptr<ArkEncounterManager, std::default_delete<ArkEncounterManager>> m_pArkEncounterManager;
			std::unique_ptr<CArkFlowGraphManager, std::default_delete<CArkFlowGraphManager>> m_pArkFlowGraphManager;
			std::unique_ptr<ArkEthericFogManager, std::default_delete<ArkEthericFogManager>> m_pArkEthericFogManager;
			std::unique_ptr<ArkFactionManager, std::default_delete<ArkFactionManager>> m_pArkFactionManager;
			std::unique_ptr<ArkGameDataManager, std::default_delete<ArkGameDataManager>> m_pArkGameDataManager;
			std::unique_ptr<ArkGlintConfigManager, std::default_delete<ArkGlintConfigManager>> m_pArkGlintConfigManager;
			std::unique_ptr<CArkGlooIslandNavLinkManager, std::default_delete<CArkGlooIslandNavLinkManager>> m_pArkGlooIslandNavLinkManager;
			std::unique_ptr<ArkInstigationManager, std::default_delete<ArkInstigationManager>> m_pArkInstigationManager;
			std::unique_ptr<ArkLightTimeManager, std::default_delete<ArkLightTimeManager>> m_pArkLightTimeManager;
			std::unique_ptr<ArkListenerManager, std::default_delete<ArkListenerManager>> m_pArkListenerManager;
			std::unique_ptr<ArkLurkManager, std::default_delete<ArkLurkManager>> m_pArkLurkManager;
			std::unique_ptr<ArkMetaTagManager, std::default_delete<ArkMetaTagManager>> m_pArkMetaTagManager;
			std::unique_ptr<ArkNightmareEtherformManager, std::default_delete<ArkNightmareEtherformManager>> m_pArkNightmareEtherformManager;
			std::unique_ptr<ArkNightmareSpawnManager, std::default_delete<ArkNightmareSpawnManager>> m_pArkNightmareSpawnManager;
			std::unique_ptr<ArkNpcAbilityManager, std::default_delete<ArkNpcAbilityManager>> m_pArkNpcAbilityManager;
			std::unique_ptr<ArkNpcAreaManager, std::default_delete<ArkNpcAreaManager>> m_pArkNpcAreaManager;
			std::unique_ptr<ArkNpcBlackboardManager, std::default_delete<ArkNpcBlackboardManager>> m_pArkNpcBlackboardManager;
			std::unique_ptr<ArkNpcGameEffectManager, std::default_delete<ArkNpcGameEffectManager>> m_pArkNpcGameEffectManager;
			std::unique_ptr<ArkNpcManager, std::default_delete<ArkNpcManager>> m_pArkNpcManager;
			std::unique_ptr<ArkNpcSpawnManager, std::default_delete<ArkNpcSpawnManager>> m_pArkNpcSpawnManager; // 0x358
			std::unique_ptr<ArkNpcThrowPropManager, std::default_delete<ArkNpcThrowPropManager>> m_pArkNpcThrowPropManager;
			std::unique_ptr<ArkNpcUnreachableTargetingManager, std::default_delete<ArkNpcUnreachableTargetingManager>> m_pArkNpcUnreachableTargetingManager;
			std::unique_ptr<CArkPADialogManager, std::default_delete<CArkPADialogManager>> m_pArkPADialogManager;
			std::unique_ptr<ArkPatrolManager, std::default_delete<ArkPatrolManager>> m_pArkPatrolManager;
			std::unique_ptr<ArkPostEffectManager, std::default_delete<ArkPostEffectManager>> m_pArkPostEffectManager;
			std::unique_ptr<CArkProjectileGooNetworkManager, std::default_delete<CArkProjectileGooNetworkManager>> m_pArkProjectileGooNetworkManager;
			std::unique_ptr<CArkProjectileGooPhysicsManager, std::default_delete<CArkProjectileGooPhysicsManager>> m_pArkProjectileGooPhysicsManager;
			std::unique_ptr<CArkProjectilePoolManager, std::default_delete<CArkProjectilePoolManager>> m_pArkProjectilePoolManager;
			std::unique_ptr<ArkResponseManager, std::default_delete<ArkResponseManager>> m_pArkResponseManager;
			std::unique_ptr<ArkRetreatManager, std::default_delete<ArkRetreatManager>> m_pArkRetreatManager;
			std::unique_ptr<ArkRoomPerceptionManager, std::default_delete<ArkRoomPerceptionManager>> m_pArkRoomPerceptionManager;
			std::unique_ptr<ArkSpatialManager, std::default_delete<ArkSpatialManager>> m_pArkSpatialManager;
			std::unique_ptr<ArkTimeScaleManager, std::default_delete<ArkTimeScaleManager>> m_pArkTimeScaleManager;
			std::unique_ptr<ArkVisualPerceptionManager, std::default_delete<ArkVisualPerceptionManager>> m_pArkVisualPerceptionManager;
			std::unique_ptr<ArkWorldUIManager, std::default_delete<ArkWorldUIManager>> m_pArkWorldUIManager;
			class CScriptBind_Ark* m_pScriptBindArk;
			std::unique_ptr<CScriptBind_ArkBreakable, std::default_delete<CScriptBind_ArkBreakable>> m_pScriptBindArkBreakable;
			std::unique_ptr<CScriptBind_ArkItem, std::default_delete<CScriptBind_ArkItem>> m_pScriptBindArkItem;
			std::unique_ptr<CScriptBind_ArkFaction, std::default_delete<CScriptBind_ArkFaction>> m_pScriptBindArkFaction;
			std::unique_ptr<CScriptBind_ArkKiosk, std::default_delete<CScriptBind_ArkKiosk>> m_pScriptBindArkKiosk;
			std::unique_ptr<CScriptBind_ArkNpc, std::default_delete<CScriptBind_ArkNpc>> m_pScriptBindArkNpc;
			std::unique_ptr<CScriptBind_ArkRoster, std::default_delete<CScriptBind_ArkRoster>> m_pScriptBindArkRoster;
			std::unique_ptr<CScriptBind_ArkTurret, std::default_delete<CScriptBind_ArkTurret>> m_pScriptBindArkTurret;
			std::unique_ptr<CScriptBind_Inventory, std::default_delete<CScriptBind_Inventory>> m_pScriptBindInventory;
			std::unique_ptr<CScriptBind_ItemSystem, std::default_delete<CScriptBind_ItemSystem>> m_pScriptBindItemSystem;
			std::unique_ptr<CScriptBind_LightningArc, std::default_delete<CScriptBind_LightningArc>> m_pScriptBindLightningArc;
			class CryStringT<char> m_arkLoadLocation;
			class XmlNodeRef m_gameLevelToLevelSave;
			std::unique_ptr<ArkGame, std::default_delete<ArkGame>> m_pArkGame;
			std::unique_ptr<ArkActiveUserManagerBase, std::default_delete<ArkActiveUserManagerBase>> m_pActiveUserManager;
		};
		

	
	


