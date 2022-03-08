#pragma once



#include <vector>
#include <optional>
#include <unordered_map>
#include <map>
#include <DirectXMath.h>

	// Created with ReClass.NET 1.2 by KN4CK3R
	 struct Vec3 { float x, y, z; };
	 struct Vec4 { float x, y, z, w; };
	 struct Vec2 { float x, y; };
	
	enum class EArkExaminationType : int32_t
	{
		none = 0,
		other = 3,
		telescope = 2,
		worldUI = 1
	};
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
	
	enum class EArkLegendControlScheme : int32_t
	{
		none = 0
	};
	

	enum class enumEPlayerSex : int32_t
	{
		none = 0
	};
	

	enum class EArkExaminationMode : int32_t
	{
		active = 1,
		exiting = 2,
		inactive = 0
	};
	enum class EArkExaminationState : int32_t
	{
		active = 1,
		exiting = 2,
		inactive = 0
	};

	enum class EArkFlyMode : int32_t
	{
		off = 0,
		on = 1,
		onNoCollision = 2
	};

	enum class EStance : int32_t
	{
	};

	enum class EArkZoomPriority : int32_t
	{
	};

	enum class EArkInteractionType : int32_t
	{
		TODO = 0
	};

	enum class Mode : int32_t
	{
		TODO = 0
	};

	enum class CinematicMode : int32_t
	{
		TODO = 0
	};

	enum class EQueuedDialog : int32_t
	{
		TODO = 0
	};

	enum class EArkGridSizes : int32_t
	{
		TODO = 0
	};

	enum class InventorySort : int32_t
	{
		TODO = 0
	};

	class CCryName
	{
	public:
		char* m_str; //0x0000
	}; //Size: 0x0008

	template<typename T> class CryStringT
	{
	public:
		T* m_str; //0x0000
	}; //Size: 0x0008

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
		EStance N000037B4; //0x000C
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
			std::vector<ArkStatModifier, std::allocator<ArkStatModifier>> m_Modifiers;
		};

		class ArkStatModifierPackages
		{
		public:
			std::vector<ArkStatModifierPackage, std::allocator<ArkStatModifierPackage>> m_Packages;
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
			std::vector<ArkModifier, std::allocator<ArkModifier>> m_modifiers;
		};
		class ArkStatsComponent
		{
		public:
			uint32_t m_ownerId; //0x0000
			uint32_t m_currentId; //0x0004
			//std::unordered_map<CCryName, ArkStat, std::hash<CCryName>, std::equal_to<CCryName>, std::allocator<std::pair<const CCryName, ArkStat>>> m_stats; //0x0008
			ArkStatModifierPackages m_packagesDesc; //0x0048
			//std::unordered_map<unsigned int, std::vector<unsigned int, std::allocator<unsigned int>>, std::hash<unsigned int>, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, std::vector<unsigned int, std::allocator<unsigned int>>>>> m_activePackages; //0x0060
		}; //Size: 0x00A0


	

	class ArkEquipmentModComponent
	{
	public:
		bool m_bSuitMods; //0x0000
		char pad_0001[7]; //0x0001
		std::vector<unsigned int, std::allocator<unsigned int>> m_ownedChipsets; //0x0008
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
		std::vector<ModeAndHandle, std::allocator<ModeAndHandle>> m_modeStack; //0x0010
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

	class ExamineMode
	{
	public:
		char pad_0000[4]; //0x0000
	}; //Size: 0x0004

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
		std::vector<ArkInputAction, std::allocator<ArkInputAction>> m_ActionList;
		EArkLegendControlScheme m_ControlScheme;
		bool m_enabled;
		CryStringT<wchar_t> m_localizedLabel;
		
	};
	

	class ArkInputLegend
	{
	public:
		std::vector<ArkInputLegendItem, std::allocator<ArkInputLegendItem>> m_Items; //0x0008
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
		class ExamineMode m_mode; //0x00A8
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
		class std::vector<CryStringT<char>, std::allocator<CryStringT<char>>> m_dragCorpseJointNames; //0x0068
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
		std::map<unsigned __int64, float, std::less<unsigned __int64>, std::allocator<std::pair<const unsigned __int64, float>>> m_itemTypePriorityMap; //0x0038
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
		class std::vector<CCryName, std::allocator<CCryName>> m_filteredActionIds; //0x0028
		class std::vector<CCryName, std::allocator<CCryName>> m_allowedActionIds; //0x0040
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
		std::vector<DimRange, std::allocator<DimRange>> m_dimRanges; //0x0050
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
		class CryStringT<char> N00001B07[17]; //0x0008
		float m_customUpdateFunction(Vec4);
		float m_customOffsetFunction(Vec3);
		SViewParams& m_customViewFunction();
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
		Vec4 m_target; //0x0008
		void* m_pOxygenComponent; //0x0018
		Vec2 m_tolerance; //0x0020
		class ArkSimpleTimer m_reactTimer; //0x0028
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
		uint32_t m_data;
	};

	class CArkWeapon {
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
		std::vector<ArkMaterialParamOverride, std::allocator<ArkMaterialParamOverride>> m_originalInterenceValues;
		float m_spawnFromCameraTestDistance;
		float m_spawnBehindCameraDistance;
		CryStringT<char> m_upgradeInfoDesc;
		CryStringT<char> m_focusDescription;
		CCryName m_leverageBaseName;
		CryStringT<char> m_muzzleLightAttachName;
		IParticleEffect* m_pMuzzleLight;
		std::vector<IArkWeaponEventListener*, std::allocator<IArkWeaponEventListener*>> m_listeners;
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
		std::vector<unsigned int, std::allocator<unsigned int>> m_weaponEntityIds; //0x0018
		std::vector<unsigned int, std::allocator<unsigned int>> m_specialWeaponIds; //0x0030
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
		std::vector<unsigned __int64, std::allocator<unsigned __int64>> m_weaponTypesAcquired; //0x0080
		std::vector<GameLogData, std::allocator<GameLogData>> m_sneakAttackData; //0x0098
		std::vector<GameLogData, std::allocator<GameLogData>> m_criticalHitData; //0x00B0
		std::vector<GameLogData, std::allocator<GameLogData>> m_mimicHitData; //0x00C8

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
		std::vector<ZoomData, std::allocator<ZoomData>> m_zoomStack;
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
		std::vector<ArkMaterialAnimationRgbKey, std::allocator<ArkMaterialAnimationRgbKey>> m_RgbKeys;

	};
	class ArkMaterialAnimationKey {
	public:
		float m_Time;
		float m_Value;
	};
	class ArkMaterialAnimationKeysArray {
	public:
		std::vector<ArkMaterialAnimationKey, std::allocator<ArkMaterialAnimationKey>> m_Keys;
	};
	class ArkMaterialAnimationSubMaterialData {
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
		unsigned __int64 m_Id;
		CryStringT<char> m_Name;
		CryStringT<char> m_AttachmentName;
		uint32_t m_MeshSlot;
		CryStringT<char> m_MaterialReference;
		std::vector<ArkMaterialAnimationSubMaterialData, std::allocator<ArkMaterialAnimationSubMaterialData>> m_SubMaterials;
		std::vector<ArkMaterialAnimationKeyframe, std::allocator<ArkMaterialAnimationKeyframe>> m_keyframeQueue;
	};

	class MaterialParameterRamp {
		IMaterial* m_PMaterial;
		EMaterialParamFloat m_paramFloat;
		EMaterialParamVec3 m_paramVec3;
		char* m_paramName;
		float m_initialFloatValue;
		float m_finalFloatValue;
		Vec3 m_initialVectorValue;
		Vec3 m_finalVectorValue;
		float m_currentTime;
		float m_finalTime;
		bool m_bIsFloat;
	};

	class ActiveAnimationData {
		std::vector<ArkMaterialAnimationKeyframe, std::allocator<ArkMaterialAnimationKeyframe>> m_keyframeQueue;
	}; 
	class ArkMaterialAnimationManager
	{
	public:
		void* m_pEntity; //0x0000
		std::vector<SAttachmentMaterials, std::allocator<SAttachmentMaterials>> m_attachmentMaterials; //0x0008
		void* m_pOneOffMaterialAnimation; //0x0020
		ActiveAnimationData m_oneOffAnimationData; //0x0028
		std::unordered_map<enumArkMaterialAnimationType, const ArkMaterialAnimation*, EnumClassHash, std::equal_to<enumArkMaterialAnimationType>, std::allocator<std::pair<const enumArkMaterialAnimationType, const ArkMaterialAnimation*>>> m_animationsByType; //0x0040
		ActiveAnimationData m_activeAnimationsByType[18]; //0x0080
		std::vector<MaterialParameterRamp, std::allocator<MaterialParameterRamp>> m_materialParameterRamps; //0x0230
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
		class ArkPlayerMovementFSM m_movementFSM; //0x0058
		class ArkPlayerComponent m_playerComponent; //0x0678
		class ArkStatsComponent m_statsComponent; //0x07C0
		class ArkEquipmentModComponent m_suitChipsetComponent; //0x0860
		class ArkEquipmentModComponent m_scopeChipsetComponent; //0x08A0
		class ArkPlayerInput m_input; //0x08E0
		class ArkExaminationMode m_examinationMode; //0x09B0
		class ArkPlayerInteraction m_interaction; //0x0AC8
		class ArkGroundColliderComponent m_groundColliderComponent; //0x11B0
		class ArkPlayerFlashlight m_flashlight; //0x11C0
		class ArkPlayerAudio m_audio; //0x1250
		class ArkPlayerCamera m_camera; //0x12A0
		class ArkPlayerHelmet m_helmet; //0x1468
		class ArkPlayerWeaponComponent m_weaponComponent; //0x14B8
		std::vector<IPlayerEventListener*, std::allocator<IPlayerEventListener*>> m_playerEventListenersVector; //0x1598
		std::vector<std::pair<CryStringT<char>, unsigned int>, std::allocator<std::pair<CryStringT<char>, unsigned int>>> m_attachmentFlagsVector; //0x15B0
		std::vector<unsigned __int64, std::allocator<unsigned __int64>> m_learnedNames; //0x15C8
		std::vector<unsigned __int64, std::allocator<unsigned __int64>> m_criticalHitMetaTags; //0x15E0
		std::vector<CryStringT<char>, std::allocator<CryStringT<char>>> m_animationTagsSetFromFG; //0x15F8
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
		std::vector<std::pair<unsigned int, Vec3&>, std::allocator<std::pair<unsigned int, Vec3&>>> m_rotationModifiers; //0x18D0
		int32_t m_mimicGrabSequenceEntityId; //0x18E8
		char pad_18EC[4]; //0x18EC
		 ArkMaterialAnimationManager m_materialAnimationManager; //0x18F0
	}; //Size: 0x1B38



	

	


	class StorageCell {
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
		std::vector<StorageCell, std::allocator<StorageCell>> m_storedItems; //0x0060
		class ArkSimpleTimer m_lookAtTimer; //0x0078
		InventorySort m_currentSort; //0x0080
		char pad_0084[4]; //0x0084
	}; //Size: 0x0088

	class N000034D3
	{
	public:
		char pad_0000[8]; //0x0000
	}; //Size: 0x0008



