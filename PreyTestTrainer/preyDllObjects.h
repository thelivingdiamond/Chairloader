#pragma once



#include <vector>
#include <optional>
#include <unordered_map>
#include <map>
#include <DirectXMath.h>
#include <array>
#include <variant>

#include "ArkBasicTypes.h"
#include "EArk.h"
	// Created with ReClass.NET 1.2 by KN4CK3R

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
		void* ptr;
	};
	class IEntityArchetype {
		void* ptr;
		
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







	
	


