#pragma once


#include <set>
#include <unordered_set>
#include <boost/variant/variant.hpp>

#include <Prey/CryCore/CryEndian.h>
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryMath/Cry_Camera.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/IConsole.h>
#include <Prey/CrySystem/ITimer.h>
#include <Prey/CryThreading/CryThread_win32.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/ArkBasicTypes.h>
#include <Prey/ArkEnums.h>
#include <Prey/CryCore/Platform/CryWindows.h>

#include "ArkAudio.h"
#include "ArkInput.h"
#include "ArkItemSystem.h"
#include "ArkMaterialAnimation.h"
#include "ArkTimer.h"
#include "IAction.h"
#include "Prey/CryCore/functor.h"
#include "Prey/CryPhysics/physinterface.h"
#include "ArkNpc.h"
#include "EStance.h"
#include "IAttachment.h"
#include "RayCast.h"
#include "ArkPlayerStatus.h"
#include "ArkPlayerFatigueComponent.h"
// #include "Header.h"
	// Created with ReClass.NET 1.2 by KN4CK3R

class ArkAudioLogComponent;
class CActionMap;
class CActionMapManager;
class ArkPsiPowerTargetingComponent;
class ArkStatModifier;
class ArkResearchTopicData;
class CEntity;
class SScriptFuncHandle;
struct IGameObject;
class IXmlStringPool;
class CBinaryXmlNode;
class ChunkTypes;
enum class ELockMode;
class SComponentInitializer;
class ICrySizer;
class ScriptAnyValue;
class CTimeValue;
class SNetObjectID;
class ISerializeUpdateFunction;
class SSerializeString;
struct ISerialize;
class IXmlNode;
class CXmlNode;
struct IEntity;
class ArkNpcAbility;
class ArkInventory;
class StorageCell;
class IAntiCheatManager;
struct IPhysicalEntity;
class ArkAimAssistComponent;
class ArkNpcAbilityInstance;
struct I3DEngine;
class CEntityClass;
class CSystem;
struct IEntityClass;
struct CActor;
struct IActor;
struct IArkPlayer;
struct ArkPlayer;
class ArkSimpleTimer;
//ArkGame * getArkGame(
	// CGame* (18)0x2c09010
	// GEnv		  0x22418c0
class ITexture;
struct ILog;
struct SRenderingPassInfo;
struct IViewSystem;
class CryMutex;
class CGameObject;
struct IParticleManager;
struct IProcess;
struct IPhysicsDebugRenderer;
struct IPhysicalWorld;
struct IPhysRenderer;
struct IThreadTask;
struct EventPhysCollision;
class ArkAudioTrigger;
class ArkProperty;

enum class EWinVersion {
	WinUndetected = 0,
	Win2000 = 1,
	WinXP = 2,
	WinSrv2003 = 3,
	WinVista = 4,
	Win7 = 5,
	Win8 = 6,
	Win8Point1 = 7,
	Win10 = 8
};
class CEntitySystem;


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
	

	
	
	



	

	

	

	enum class ScrollDir {
		sdDOWN = 0,
		sdUP = 1,
		sdNONE = 2
	};

	

	enum class EType {
		Button = 0,
		Toggle = 1,
		RawAxis = 2,
		Axis = 3,
		Trigger = 4
	};
	
	enum class ECpuVendor {
		eCVendor_Unknown = 0,
		eCVendor_Intel = 1,
		eCVendor_Cyrix = 2,
		eCVendor_AMD = 3,
		eCVendor_Centaur = 4,
		eCVendor_NexGen = 5,
		eCVendor_UMC = 6,
		eCVendor_M68K = 7
	};
	enum class ECpuModel {
		eCpu_Unknown = 0,
		eCpu_8086 = 1,
		eCpu_80286 = 2,
		eCpu_80386 = 3,
		eCpu_80486 = 4,
		eCpu_Pentium = 5,
		eCpu_PentiumPro = 6,
		eCpu_Pentium2 = 7,
		eCpu_Pentium3 = 8,
		eCpu_Pentium4 = 9,
		eCpu_Pentium2Xeon = 10,
		eCpu_Pentium3Xeon = 11,
		eCpu_Celeron = 12,
		eCpu_CeleronA = 13,
		eCpu_Am5x86 = 14,
		eCpu_AmK5 = 15,
		eCpu_AmK6 = 16,
		eCpu_AmK6_2 = 17,
		eCpu_AmK6_3 = 18,
		eCpu_AmK6_3D = 19,
		eCpu_AmAthlon = 20,
		eCpu_AmDuron = 21,
		eCpu_CyrixMediaGX = 22,
		eCpu_Cyrix6x86 = 23,
		eCpu_CyrixGXm = 24,
		eCpu_Cyrix6x86MX = 25,
		eCpu_CenWinChip = 26,
		eCpu_CenWinChip2 = 27
	};
	// enum class ELanguageID {
	// 	eLID_English = 0,
	// 	eLID_French = 1,
	// 	eLID_Italian = 2,
	// 	eLID_German = 3,
	// 	eLID_Spanish = 4,
	// 	eLID_Latin_American_Spanish = 5,
	// 	eLID_Brazilian_Portuguese = 6,
	// 	eLID_Russian = 7,
	// 	eLID_Polish = 8,
	// 	eLID_Japanese = 9,
	// 	eLID_Traditional_Chinese = 10,
	// 	eLID_Simplified_Chinese = 11,
	// 	eLID_MAX_OR_INVALID = 12
	// };
	enum class EStreamSourceMediaType {
		eStreamSourceTypeUnknown = 0,
		eStreamSourceTypeHDD = 1,
		eStreamSourceTypeDisc = 2,
		eStreamSourceTypeMemory = 3
	};
	

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
	

	class ArkSignalModifier{};
	class ArkAbilityUpgradeState {
		
	};
	class ArkTyphonStatus {
		
	};
	class ArkAbility {
		uint64_t m_ID;
		CryStringT<char> m_Icon, m_Name, m_Label, m_description;
		int32_t m_tier;
		float m_NightmareHeat;
		unsigned char m_Cost;
		bool m_RequireScanner;
		char pad[6];
		std::vector<uint64_t> m_Prereqs;
		EArkPsiPowers m_Power;
		unsigned char m_PowerLevel;
		char pad2[3];
		std::vector<ArkSignalModifier> m_SignalModifiers;
		std::vector<ArkStatModifier> m_StatModifiers;
		CryStringT<char> m_Tutorial, m_TutorialPC, m_TutorialImage;
	};
	class ArkAbilityData {
	public:
		std::vector<ArkAbilityData*> m_prereqs;
		std::vector<ArkAbilityData*> m_children;
		std::vector<ArkResearchTopicData*> m_researchTopicData;
		std::vector<unsigned int> m_modifiers;
		uint64_t m_id;
		bool m_bSeen, m_bAcquired;
		char pad[6];
	};
	class ArkResearchTopicData {
		
	};
	class ArkAbilities {
	public:
		void* ptr;
		std::vector<ArkAbility> m_Abilities;
	};

	class IArkPDAListener
	{
	public:
		virtual void OnPDAOpen() = 0;
		virtual void OnPDAOpenComplete() = 0;
		virtual void OnPDAClose() = 0;
	};

	class ArkAbilityComponent : IArkPDAListener{
	public:
		std::vector<ArkAbilityData> m_abilities;
		std::vector<ArkResearchTopicData> m_researchTopics;
		uint64_t m_lastResearchedAbility;
		int32_t m_partialTyphonThreshold,
				m_fullTyphonThreshold;
		static inline auto GetAcquiredAbilities = PreyFunction < std::vector<ArkAbilityData const*>(ArkAbilityComponent* _this)>(0x153A5D0);
	};

	
	
	class ArkDialogPlayer{};
	class ArkDialogPlayerTranscribe{};

		

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

	


	class ArkEntityGrabber
	{
	public:
		float m_breakDistanceSq; //0x0000
		float m_lastDesiredLerpVelocity; //0x0004
		float m_timeUnderDesiredLerpVelocity; //0x0008
		float m_totalDistanceForLerp; //0x000C
		float m_lerpSpeed; //0x0010
		float m_lerpObedSpeed; //0x0014
		float m_lerpAcceleration; //0x0018
		float m_lerpObedAcceleration; //0x001C
		float m_maxTimeAllowedUnderDesiredLerpVelocity; //0x0020
		bool m_bConstrained; //0x0024
		char pad_0025[3]; //0x0025
	}; //Size: 0x0028

	


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
		CryStringT<char> m_displayText; //0x0008
		float m_holdDuration; //0x0010
		char pad_0014[4]; //0x0014
	}; //Size: 0x0018
	// class Map
	// {
	// public:
	// 	char pad_0000[16]; //0x0000
	// }; //Size: 0x0010
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
		CryStringT<char> m_actionMap; //0x0008
		ArkSimpleTimer m_holdTimer; //0x0010
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
		CryStringT<char> m_filterName; //0x0018
		CryStringT<char> m_actionMap; //0x0020
		std::vector<CCryName> m_filteredActionIds; //0x0028
		std::vector<CCryName> m_allowedActionIds; //0x0040
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


	class ArkPlayerLightEntity
	{
	public:
		char pad_0000[32]; //0x0000
		uint32_t m_attachmentEntity; //0x0020
		uint32_t m_lightEntity; //0x0024
		CryStringT<char> m_archetypeName; //0x0028
		CryStringT<char> m_attachmentName; //0x0030
	}; //Size: 0x0038


	class DimRange {
		float m_distanceSq;
		float m_diffuseMultiplier;
	};
	class XmlNodeRef;
	






	class ArkRegularOutcome {
	public:
		uint32_t m_data;
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

	
	
	// class CMannequinParams {
	// 	//TODO: CMannequinParams
	// 	char pad[24];
	// };
	

	


	class ArkWeaponMods {
	public:
		std::unordered_map<unsigned __int64, int32_t, std::hash<unsigned __int64>, std::equal_to<unsigned __int64>> m_weaponModIds;
	};

	

	class ArkMaterialParamOverride {
	public:
		CryStringT<char> m_paramName;
		float m_paramValue;
	};
	class IArkWeaponEventListener {
	public:
		void* ptr;
	};
	
	class IUIElement {
	public:
		void* ptr;
	};
	enum class ScriptAnyType {
		ANY_ANY = 0,
		ANY_TNIL = 1,
		ANY_TBOOLEAN = 2,
		ANY_THANDLE = 3,
		ANY_TNUMBER = 4,
		ANY_TSTRING = 5,
		ANY_TTABLE = 6,
		ANY_TFUNCTION = 7,
		ANY_TUSERDATA = 8,
		ANY_TVECTOR = 9,
		ANY_COUNT = 0xa
	};
	class userData {
	public:
		void* ptr;
		int32_t nRef;
		char pad[4];
	};

	class ScriptAnyValue {
	public:
		struct Vec3Triv {
			float x, y, z;
		};

		ScriptAnyType type;
		char pad[4];

		union {
			bool b;
			float number;
			const char *str;
			IScriptTable *table;
			const void *ptr;
			SScriptFuncHandle *function;
			Vec3Triv vec3;
			userData ud;
		} value;
	};
	class ScriptVarType {
		
	};
	namespace CScriptTableName {
		class Iterator {
		public:
			char* sKey;
			int nKey;
			char pad2[4];
			ScriptAnyValue value;
			ScriptAnyValue Key;
			char unknownThing[12];
			char pad[4];
		};
	}
	class SUserFunctionDesc {
	public:
		char* sFunctioName;
		char* sFunctioNParams;
		char* sGlobalName;
		char pFunctor[24];
		void* pFunctorThunk;
		int32_t nParamIdOffset;
		char pad[4];
		void* pUserDataFunc;
		void* pDataBuffer;
		int32_t nDataSize;
		char pad2[4];
	};
	class IScriptTableDumpSink{};
	class CScriptTable {
	public:
		virtual void*   _ECScriptTable(uint32_t param_1) {}
		virtual  IScriptSystem*  GetScriptSystem() {}
		virtual void  AddRef() {}
		virtual void  Release() {}
		virtual void  Delegate( IScriptTable* param_1) {}
		virtual void*  GetUserDataValue() {}
		virtual void  SetValueAny(const char* param_1,  ScriptAnyValue* param_2, bool param_3) {}
		virtual bool  GetValueAny(const char* param_1,  ScriptAnyValue* param_2, bool param_3) {}
		virtual bool  BeginSetGetChain() {}
		virtual void  EndSetGetChain() {}
		virtual  ScriptVarType*  GetValueType(char* param_1) {}
		virtual  ScriptVarType*  GetAtType(int32_t param_1) {}
		virtual void  SetAtAny(int32_t param_1,  ScriptAnyValue* param_2) {}
		virtual bool  GetAtAny(int32_t param_1,  ScriptAnyValue* param_2) {}
		virtual  CScriptTableName::Iterator*  BeginIteration(CScriptTableName::Iterator* __return_storage_ptr__, bool param_1) {}
		virtual bool  MoveNext(CScriptTableName::Iterator* param_1) {}
		virtual void  EndIteration(CScriptTableName::Iterator* param_1) {}
		virtual void  Clear() {}
		virtual int32_t  Count() {}
		virtual bool  Clone( IScriptTable* param_1, bool param_2, bool param_3) {}
		virtual void  Dump( IScriptTableDumpSink* param_1) {}
		virtual bool  AddFunction( SUserFunctionDesc* param_1) {}
		int32_t m_nRefCount;
		int32_t m_nRef;
	};
	class SmartScriptTable {
	public:
		IScriptTable* ptr;
	};
	
	class SSurfaceTypeAIParams {
		
	};
	struct IXmlStringData;
	class CXmlStringPool;
	class XmlString;
	class XmlNodeRef;

	class XmlAttribute {
	public:
		char* key;
		char* value;
	};
	class CXmlNode {
	public:
		virtual void  DeleteThis() {}
		virtual void* _ECXmlNode(uint32_t param_1) {}
		virtual  XmlNodeRef* createNode(char* param_1) {}
		virtual void  AddRef() {}
		virtual void  Release() {}
		virtual uint32_t  GetAudioObjectID() {}
		virtual  ArkNpcAbilityInstance* GetAbilityInstance() {}
		virtual void  setTag(char* param_1) {}
		virtual bool  isTag(char* param_1) {}
		virtual int  getNumAttributes() {}
		virtual bool  getAttributeByIndex(int param_1, char** param_2, char** param_3) {}
		virtual void  copyAttributes(XmlNodeRef* param_1) {}
		virtual bool  removeAttr(char* param_1) {}
		virtual bool  getAttr(char* param_1, Color_tpl<unsigned char>* param_2) {}
		virtual bool  getAttr(char* param_1, XmlString* param_2) {}
		virtual bool  getAttr(char* param_1, bool* param_2) {}
		virtual bool  getAttr(char* param_1, Quat_tpl<float>* param_2) {}
		virtual bool  getAttr(char* param_1, Vec3_tpl<double>* param_2) {}
		virtual bool  getAttr(char* param_1, Vec4_tpl<float>* param_2) {}
		virtual bool  getAttr(char* param_1, Vec3_tpl<float>* param_2) {}
		virtual bool  getAttr(char* param_1, Ang3_tpl<float>* param_2) {}
		virtual bool  getAttr(char* param_1, Vec2_tpl<double>* param_2) {}
		virtual bool  getAttr(char* param_1, Vec2_tpl<float>* param_2) {}
		virtual bool  getAttr(char* param_1, double* param_2) {}
		virtual bool  getAttr(char* param_1, float* param_2) {}
		virtual bool  getAttr(char* param_1, uint64_t* param_2) {}
		virtual bool  getAttr(char* param_1, int64_t* param_2) {}
		virtual bool  getAttr(char* param_1, uint32_t* param_2) {}
		virtual bool  getAttr(char* param_1, int* param_2) {}
		virtual bool  getAttr(char* param_1, char** param_2) {}
		virtual char* getAttr(char* param_1) {}
		virtual bool  haveAttr(char* param_1) {}
		virtual void  addChild(XmlNodeRef* param_1) {}
		virtual  XmlNodeRef* newChild(char* param_1) {}
		virtual void  removeChild(XmlNodeRef* param_1) {}
		virtual void  insertChild(XmlNodeRef* param_1, XmlNodeRef* param_2) {}
		virtual void  insertChild(int param_1, XmlNodeRef* param_2) {}
		virtual void  replaceChild(int param_1, XmlNodeRef* param_2) {}
		virtual void  removeAllChilds() {}
		virtual int  getChildCount() {}
		virtual  XmlNodeRef* getChild(int param_1) {}
		virtual void  _xPathFindNodes(std::function<void __cdecl(XmlNodeRef)>* param_1, char* param_2) {}
		virtual  XmlNodeRef* ensureChild(char* param_1) {}
		virtual  XmlNodeRef* getRoot() {}
		virtual void  xPathIDFromAttribute(char* param_1, CryStackStringT<char, 512>* param_2) {}
		virtual bool  MatchesXPath(char* param_1) {}
		virtual int  findChildIndex(XmlNodeRef* param_1) {}
		virtual  XmlNodeRef* findChild(char* param_1) {}
		virtual  XmlNodeRef* findChildWithAttibuteValue(char* param_1, char* param_2) {}
		virtual  XmlNodeRef* getParent() {}
		virtual void  Initialize(SComponentInitializer* param_1) {}
		virtual  SSurfaceTypeAIParams* GetAIParams() {}
		virtual void  setContent(char* param_1) {}
		virtual  XmlNodeRef* clone() {}
		virtual int  GetActionMapsCount() {}
		virtual void  SetTargetLock(ELockMode* param_1) {}
		virtual  IXmlStringData* getXMLData(int param_1) {}
		virtual  XmlString* getXML(int param_1) {}
		virtual bool  saveToFile(char* param_1, uint64_t param_2, _iobuf* param_3, bool param_4) {}
		virtual bool  saveToFile(char* param_1, bool param_2) {}
		virtual void  setAttr(char* param_1, Quat_tpl<float>* param_2) {}
		virtual void  setAttr(char* param_1, Vec3_tpl<double>* param_2) {}
		virtual void  setAttr(char* param_1, Vec4_tpl<float>* param_2) {}
		virtual void  setAttr(char* param_1, Ang3_tpl<float>* param_2) {}
	private:
		virtual void  garbage0() {}
	public:
		virtual void  setAttr(char* param_1, Vec2_tpl<double>* param_2) {}
		virtual void  setAttr(char* param_1, Vec2_tpl<float>* param_2) {}
		virtual void  setAttr(char* param_1, double param_2) {}
		virtual void  setAttr(char* param_1, float param_2) {}
		virtual void  setAttr(char* param_1, uint64_t param_2) {}
		virtual void  setAttr(char* param_1, int64_t param_2) {}
		virtual void  setAttr(char* param_1, uint32_t param_2) {}
		virtual void  setAttr(char* param_1, int param_2) {}
		virtual void  setAttr(char* param_1, char* param_2) {}
		virtual void  setAttrHex(char* param_1, uint64_t param_2) {}
		virtual void  delAttr(char* param_1) {}
		virtual void  removeAllAttributes() {}
		virtual bool  getAttrHex(char* param_1, uint64_t* param_2) {}
		virtual void  GetMemoryUsage(ICrySizer* param_1) {}
		virtual void  shareChildren(XmlNodeRef* param_1) {}
		virtual void  deleteChildAt(int param_1) {}
		virtual  XmlString* getXMLUnsafe(int param_1, char* param_2, uint32_t param_3) {}
		virtual bool  getAttributeByIndex(int param_1, XmlString* param_2, XmlString* param_3) {}
	private:
		virtual void garbage() {}
	public:
		virtual void* _ECXmlNodeReuse(uint32_t param_1) {}
	private:
		virtual void garbage100() {}
		virtual void garbage1() {}
		virtual void garbage2() {}
		virtual void garbage3() {}
		virtual void garbage4() {}
		virtual void garbage5() {}
		virtual void garbage6() {}
		virtual void garbage7() {}
		virtual void garbage8() {}
		virtual void garbage9() {}
		virtual void garbage101() {}
		virtual void garbage11() {}
		virtual void garbage12() {}
		virtual void garbage13() {}
		virtual void garbage14() {}
		virtual void garbage15() {}
		virtual void garbage16() {}
		virtual void garbage17() {}
		virtual void garbage18() {}
		virtual void garbage19() {}
		virtual void garbage20() {}
		virtual void garbage21() {}
		virtual void garbage22() {}
		virtual void garbage23() {}
		virtual void garbage24() {}
		virtual void garbage25() {}
		virtual void garbage26() {}
		virtual void garbage27() {}
		virtual void garbage28() {}
		virtual void garbage29() {}
		virtual void garbage30() {}
		virtual void garbage31() {}
		virtual void garbage32() {}
		virtual void garbage33() {}
		virtual void garbage34() {}
		virtual void garbage35() {}
		virtual void garbage36() {}
		virtual void garbage37() {}
		virtual void garbage38() {}
		virtual void garbage39() {}
		virtual void garbage40() {}
		virtual void garbage41() {}
		virtual void garbage42() {}
		virtual void garbage43() {}
		virtual void garbage44() {}
		virtual void garbage45() {}
		virtual void garbage46() {}
		virtual void garbage47() {}
		virtual void garbage48() {}
		virtual void garbage49() {}
		virtual void garbage50() {}
		virtual void garbage51() {}
		virtual void garbage52() {}
		virtual void garbage53() {}
		virtual void garbage54() {}
		virtual void garbage55() {}
		virtual void garbage56() {}
		virtual void garbage57() {}
		virtual void garbage58() {}
		virtual void garbage59() {}
		virtual void garbage60() {}
		virtual void garbage61() {}
		virtual void garbage62() {}
		virtual void garbage63() {}
		virtual void garbage64() {}
		virtual void garbage65() {}
		virtual void garbage66() {}
		virtual void garbage67() {}
		virtual void garbage68() {}
		virtual void garbage69() {}
		virtual void garbage70() {}
		virtual void garbage71() {}
		virtual void garbage72() {}
		virtual void garbage73() {}
		virtual void garbage74() {}
		virtual void garbage75() {}
		virtual void garbage76() {}
		virtual void garbage77() {}
		virtual void garbage78() {}
		virtual void garbage79() {}
		virtual void garbage80() {}
	public:
		virtual void* _ECXmlNodePool(uint32_t param_1) {}
		virtual void  OnRelease(int param_1, void* param_2) {}
		char pad[8];
		IXmlStringPool* m_pStringPool;
		char* m_tag;
		char* m_content;
		IXmlNode* m_parent;
		std::vector < IXmlNode*> m_pChilds;
		std::vector<XmlAttribute> m_pAttributes;
		int32_t m_line;
		char pad2[4];
	};
	class CXmlTableReader {
	public:
		virtual void* _ECXmlTableReader(uint32_t param_1) {}
		virtual void  Complete() {}
		virtual bool  Begin(XmlNodeRef* param_1) {}
		virtual int  GetEstimatedRowCount() {}
		virtual bool  ReadRow(int* param_1) {}
		virtual bool  ReadCell(int* param_1, char** param_2, uint64_t* param_3) {}
		bool m_bExcel;
		char pad[7];
		XmlNodeRef m_tableNode,
			m_rowNode;
		int32_t m_rowNodeIndex,
			m_row,
			m_columnNodeIndex,
			m_column;
		uint64_t m_rowTextSize,
			rwoTextPos;
	};

	class IXmlStringPool {
	public:
		virtual void* _EIXmlStringPool(uint32_t param_1) {}
		virtual undefined _purecall() {}
		virtual undefined _purecall_1() {}
		int32_t m_refCount;
		char pad[4];
	};
	class CXmlStringPool {
	public:
		virtual void* _ECXmlStringPool(uint32_t param_1) {}
		virtual char* AddString(char* param_1) {}
		virtual void  GetMemoryUsage(ICrySizer* param_1) {}
		char pad[8];
		CSimpleStringPool m_stringPool;
	};
	class SStackEntity {
	public:
		XmlNodeRef node;
		std::vector<IXmlNode*> childs;
	};
	class XmlParserImp {
	public:
		virtual void* _EXmlParserImp(uint32_t param_1) {}
		virtual char* AddString(char* param_1) {}
		virtual void  GetMemoryUsage(ICrySizer* param_1) {}
		char pad[8];
		std::vector<SStackEntity> m_nodeStack;
		int32_t m_nNodeStackTop;
		char pad2[4];
		XmlNodeRef m_root;
		void* m_parser;
		CSimpleStringPool m_stringPool;
	};
	class XmlParser {
	public:
		virtual void* _EXmlParser(uint32_t param_1) {}
		virtual void  AddRef() {}
		virtual void  Release() {}
		virtual XmlNodeRef* ParseFile(char* param_1, bool param_2, bool param_3) {}
		virtual XmlNodeRef* ParseBuffer(char* param_1, int32_t param_2, bool param_3) {}
		virtual void  GetMemoryUsage(ICrySizer* param_1) {}
		int32_t m_nRefCount;
		char pad[4];
		XmlString m_errorString;
		XmlParserImp* m_pImpl;
	};

	class IReadXMLSink {};
	class IWriteXMLSource {};
	class IReadWriteXmlSink {};
	class CXmlNodePool {};
	class CXMLPatcher {};
	class Node {
	public:
		uint32_t nTagStringOffset,
			nContentStringOffset;
		unsigned short nAttributeCount,
			nChildCount;
		uint32_t nParentIndex,
			nFirstAttributeIndex,
			nFirstChildIndex;
		char pad[4];
	};
	class Attribute {
	public:
		uint32_t nKeyStringOffset;
		uint32_t nValueStringOffset;
	};
	class CBinaryXmlData {
	public:
		Node* pNodes;
		Attribute* pAttributes;
		uint32_t * pChildIndices;
		char* pStringData;
		char* pFileContents;
		uint64_t nFileSize;
		bool bOwnsFileContentsMemory;
		char pad[7];
		CBinaryXmlNode* pBinaryNodes;
		int32_t nRefCount;
		char pad2[4];
	};
	class CBinaryXmlNode {
	public:
		virtual void   $FunctionCaller( EArkNpcFacingDesireCallbackEvent* param_2) {}
		virtual void*   _ECBinaryXmlNode(uint32_t param_1) {}
		virtual void garbage0() {}
		virtual void  AddRef() {}
		virtual void  Release() {}
		virtual uint32_t  GetAudioObjectID() {}
		virtual char*  getTag() {}
		virtual void   garbage1() {}
		virtual bool  isTag(char* param_1) {}
		virtual int32_t  getNumAttributes() {}
		virtual bool  getAttributeByIndex(int32_t param_1, char** param_2, char** param_3) {}
		virtual void   $destroy( XmlNodeRef* param_2) {}
		virtual bool   RIArchive(char* param_1, char* param_2, char* param_3) {}
		virtual bool  getAttr(char* param_1,  Color_tpl<unsigned char>*param_2) {}
		virtual bool  getAttr(char* param_1,  XmlString* param_2) {}
		virtual bool  getAttr(char* param_1, bool* param_2) {}
		virtual bool  getAttr(char* param_1,  Quat_tpl<float>*param_2) {}
		virtual bool  getAttr(char* param_1,  Vec3_tpl<double>*param_2) {}
		virtual bool  getAttr(char* param_1,  Vec4_tpl<float>*param_2) {}
		virtual bool  getAttr(char* param_1,  Vec3_tpl<float>*param_2) {}
		virtual bool  getAttr(char* param_1,  Ang3_tpl<float>*param_2) {}
		virtual bool  getAttr(char* param_1,  Vec2_tpl<double>*param_2) {}
		virtual bool  getAttr(char* param_1,  Vec2_tpl<float>*param_2) {}
		virtual bool  getAttr(char* param_1, double* param_2) {}
		virtual bool  getAttr(char* param_1, float* param_2) {}
		virtual bool  getAttr(char* param_1, uint64_t * param_2) {}
		virtual bool  getAttr(char* param_1, int64_t* param_2) {}
		virtual bool  getAttr(char* param_1, uint32_t * param_2) {}
		virtual bool  getAttr(char* param_1, int32_t* param_2) {}
		virtual bool  getAttr(char* param_1, char** param_2) {}
		virtual char*  getAttr(char* param_1) {}
		virtual bool  haveAttr(char* param_1) {}
		virtual void garbage() {}
		virtual void garbage2() {}
		virtual void garbage19() {}
		virtual void garbage18() {}
		virtual void garbage3() {}
		virtual void garbage4() {}
		virtual void garbage5() {}
		virtual int32_t  getChildCount() {}
		virtual  XmlNodeRef*  getChild(int32_t param_1) {}
		virtual void  _xPathFindNodes(std::function<void __cdecl(XmlNodeRef)>* param_1, char* param_2) {} 
		virtual void garbage6() {}
		virtual void garbage7() {}
		virtual void garbage8() {}
		virtual void garbage9() {}
		virtual int32_t  AddChunk( ChunkTypes* param_1, int32_t param_2,  EEndianness* param_3, void* param_4, int32_t param_5) {}
		virtual  XmlNodeRef*  findChild(char* param_1) {}
		virtual void garbage10() {}
		virtual  XmlNodeRef*  getParent() {}
		virtual void   garbage11() {}
		virtual char*  getContent() {}
		virtual void  garbage12() {}
		virtual void garbage13() {}
		virtual wchar_t*  Action() {}
		virtual void   garbage14() {}
		virtual void  garbage15() {}
		virtual  XmlString*  getXML(int32_t param_1) {}
		virtual void garbage20(){}
		virtual void garbage21(){}
		virtual void garbage22(){}
		virtual void garbage23(){}
		virtual void garbage24(){}
		virtual void garbage25(){}
		virtual void garbage26(){}
		virtual void garbage27(){}
		virtual void garbage28(){}
		virtual void garbage29(){}
		virtual void garbage30() {}
		virtual void garbage31() {}
		virtual void garbage32() {}
		virtual void garbage33() {}
		virtual void garbage34() {}
		virtual void garbage35() {}
		virtual void garbage36() {}
		virtual void garbage37() {}
		virtual void garbage38() {}
		virtual bool  getAttrHex(char* param_1, uint64_t * param_2) {}
		virtual void  GetMemoryUsage( ICrySizer* param_1) {}
		virtual void garbage39() {}
		virtual void garbage40() {}
		virtual  XmlString*  getXMLUnsafe(int32_t param_1, char* param_2, uint32_t param_3) {}
		virtual bool  getAttributeByIndex(int32_t param_1,  XmlString* param_2,  XmlString* param_3) {}
		char pad[8];
		CBinaryXmlData* m_pData;
	};
	class CXmlUtils {
	public:
		char pad[8];
		virtual void* _ECXmlUtils(uint32_t param_1) {}
		virtual  XmlNodeRef* LoadXmlFromFile(char* sFilename, bool bReuseStrings, bool bEnablePatching, bool bAllowUseFileSystem) {}
		virtual  XmlNodeRef* LoadXmlFromBuffer(char* param_1, uint64_t param_2, bool param_3) {}
		virtual char* HashXml(XmlNodeRef* param_1) {}
		virtual  ArkNpcAbilityInstance* GetAbilityInstance() {}
		virtual  IXmlSerializer* CreateXmlSerializer() {}
		virtual  IXmlParser* CreateXmlParser() {}
		virtual bool  SaveBinaryXmlFile(char* param_1, XmlNodeRef* param_2) {}
		virtual  XmlNodeRef* LoadBinaryXmlFile(char* param_1, bool param_2) {}
		virtual bool  EnableBinaryXmlLoading(bool param_1) {}
		virtual  IXmlTableReader* CreateXmlTableReader() {}
		virtual void  InitStatsXmlNodePool(uint32_t param_1) {}
		virtual  XmlNodeRef* CreateStatsXmlNode(char* param_1) {}
		virtual void   $FunctionCaller(EArkNpcFacingDesireCallbackEvent* param_2) {}
		virtual void  FlushStatsXmlNodePool() {}
		virtual void  SetXMLPatcher(XmlNodeRef* param_1) {}
		virtual void  GetMemoryUsage(ICrySizer* param_1) {}
		virtual void  garbage0() {}
		virtual void  garbage1() {}
		virtual void  OnSystemEvent(ESystemEvent* param_1, uint64_t param_2, uint64_t param_3) {}
		virtual void* _ECReadWriteXMLSink(uint32_t param_1) {}
		virtual bool  ReadXML(XmlNodeRef* param_1, XmlNodeRef* param_2, IReadXMLSink* param_3) {}
		virtual bool  ReadXML(XmlNodeRef* param_1, char* param_2, IReadXMLSink* param_3) {}
		virtual bool  ReadXML(char* param_1, XmlNodeRef* param_2, IReadXMLSink* param_3) {}
		virtual bool  ReadXML(char* param_1, char* param_2, IReadXMLSink* param_3) {}
		virtual  XmlNodeRef* CreateXMLFromSource(char* param_1, IWriteXMLSource* param_2) {}
		virtual bool  WriteXML(char* param_1, char* param_2, IWriteXMLSource* param_3) {}
		virtual void* _ECXmlSerializer(uint32_t param_1) {}
		virtual void  AddRef() {}
		virtual void  Release() {}
		virtual  ISerialize* GetWriter(XmlNodeRef* param_1) {}
		virtual  ISerialize* GetReader(XmlNodeRef* param_1) {}
		virtual void  garbage2() {}
		virtual void* $CSimpleSerialize(uint32_t param_1) {}
		virtual void  ReadStringValue(char* param_1, SSerializeString* param_2, uint32_t param_3) {}
		virtual void  garbage4() {}
		virtual void  Update(ISerializeUpdateFunction* param_1) {}
		virtual void  garbage5() {}
		virtual void  BeginGroup(char* param_1) {}
		virtual bool  BeginOptionalGroup(char* param_1, bool param_2) {}
		virtual void  EndGroup() {}
		virtual bool  Activating(float param_1) {}
		virtual bool  ShouldCommitValues() {}
		virtual wchar_t* Action() {}
		virtual bool  Ok() {}
		virtual void  Value(char* param_1, XmlNodeRef* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, SNetObjectID* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, CTimeValue* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, ScriptAnyValue* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, uint64_t* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, uint32_t* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, unsigned short* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, unsigned char* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, int64_t* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, int32_t* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, short* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, char* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, Ang3_tpl<float>* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, Quat_tpl<float>* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, Vec3_tpl<float>* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, Vec2_tpl<float>* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, float* param_2, uint32_t param_3) {}
		virtual void  Value(char* param_1, bool* param_2, uint32_t param_3) {}
		virtual void  ValueWithDefault(char* param_1, SSerializeString* param_2, SSerializeString* param_3) {}
		virtual void  ValueWithDefault(char* param_1, XmlNodeRef* param_2, XmlNodeRef* param_3) {}
		virtual void  ValueWithDefault(char* param_1, SNetObjectID* param_2, SNetObjectID* param_3) {}
		virtual void  ValueWithDefault(char* param_1, CTimeValue* param_2, CTimeValue* param_3) {}
		virtual void  ValueWithDefault(char* param_1, ScriptAnyValue* param_2, ScriptAnyValue* param_3) {}
		virtual void  ValueWithDefault(char* param_1, uint64_t* param_2, uint64_t* param_3) {}
		virtual void  ValueWithDefault(char* param_1, uint32_t* param_2, uint32_t* param_3) {}
		virtual void  ValueWithDefault(char* param_1, unsigned short* param_2, unsigned short* param_3) {}
		virtual void  ValueWithDefault(char* param_1, unsigned char* param_2, unsigned char* param_3) {}
		virtual void  ValueWithDefault(char* param_1, int64_t* param_2, int64_t* param_3) {}
		virtual void  ValueWithDefault(char* param_1, int32_t* param_2, int32_t* param_3) {}
		virtual void  ValueWithDefault(char* param_1, short* param_2, short* param_3) {}
		virtual void  ValueWithDefault(char* param_1, char* param_2, char* param_3) {}
		virtual void  ValueWithDefault(char* param_1, Ang3_tpl<float>* param_2, Ang3_tpl<float>* param_3) {}
		virtual void  ValueWithDefault(char* param_1, Quat_tpl<float>* param_2, Quat_tpl<float>* param_3) {}
		virtual void  ValueWithDefault(char* param_1, Vec3_tpl<float>* param_2, Vec3_tpl<float>* param_3) {}
		virtual void  ValueWithDefault(char* param_1, Vec2_tpl<float>* param_2, Vec2_tpl<float>* param_3) {}
		virtual void  ValueWithDefault(char* param_1, float* param_2, float* param_3) {}
		virtual void  ValueWithDefault(char* param_1, bool* param_2, bool* param_3) {}
		virtual void  garbage11() {}
		virtual void  garbage12() {}
		virtual void  garbage13() {}
		virtual void  garbage14() {}
		virtual void  garbage15() {}
		virtual void  garbage16() {}
		virtual void  garbage17() {}
		virtual void  garbage18() {}
		virtual bool   RIArchive(char* param_1, char* param_2, char* param_3) {}
		virtual void  garbage20() {}
		virtual void  garbage21() {}
		virtual void  garbage22() {}
		virtual void  garbage23() {}
		virtual void  garbage24() {}
		virtual void  garbage25() {}
		virtual void  garbage26() {}
		virtual void  garbage27() {}
		virtual void  garbage28() {}
		virtual void  garbage29() {}
		virtual void  garbage30() {}
		virtual void  garbage31() {}
		virtual void  garbage32() {}
		virtual void  garbage33() {}
		virtual void  garbage34() {}
		virtual void  garbage35() {}
		virtual void  garbage36() {}
		virtual void  garbage37() {}
		virtual void  garbage38() {}
		virtual void  garbage39() {}
		virtual void  garbage40() {}
		virtual void  garbage41() {}
		virtual void  garbage42() {}
		virtual void  garbage43() {}
		virtual void  garbage44() {}
		virtual void  garbage45() {}
		virtual void  garbage46() {}
		virtual void  garbage47() {}
		virtual void  garbage48() {}
		virtual void  garbage49() {}
		virtual void  garbage50() {}
		virtual void  garbage51() {}
		virtual void  garbage52() {}
		virtual void  garbage53() {}
		virtual void  garbage54() {}
		virtual void  garbage55() {}
		virtual void  garbage56() {}
		virtual void  garbage57() {}
		virtual void  garbage58() {}
		virtual void  garbage59() {}
		virtual void* _ECXmlBinaryDataWriterFile(uint32_t param_1) {}
		virtual void  Write(void* param_1, uint64_t param_2) {}
		virtual bool  $ContainerArray() {}
		virtual void* _ECXmlTableReader(uint32_t param_1) {}
		virtual void  Complete() {}
		virtual bool  Begin(XmlNodeRef* param_1) {}
		virtual int32_t  GetEstimatedRowCount() {}
		virtual bool  ReadRow(int32_t* param_1) {}
		virtual bool  ReadCell(int32_t* param_1, char** param_2, uint64_t* param_3) {}
		IReadWriteXmlSink* m_pReadWriteXMLSink;
		CXmlNodePool* m_pStatsXmlNodePool;
		CXMLPatcher* m_pXMLPatcher;
	};

	class CEntityArchetype : public IEntityArchetype {
	public:
		char pad[16];
		CryStringT<char> m_name;
		uint64_t m_id;
		SmartScriptTable m_pProperties;
		XmlNodeRef m_ObjectVars;
		IEntityClass* m_pClass;
	};
	class CArkWeapon {
	public:
		char pad1[416];
		ArkRegularOutcome m_criticalOutcome;
		char pad2[4];
		ArkStatsComponent m_statsComponent;
		ArkWeaponMods m_weaponMods;
		EntityEffects::CEffectsController m_effectController;
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

	struct IMaterial {
	public:
		char pad1[8];
		unsigned char m_ucDefaultMappingAxis;
		char pad2[3];
		float m_fDefaultMappingScale;
	};

	
	
	

	
	
	class IPlayerEventListener
	{
	public:
		uint64_t N0000349A; //0x0000
	}; //Size: 0x0008
	class IDatagramSocket{};
	class ICrySizer{};
	class ChunkTypes{};
	class SIPv4Addr{};
	class SNullAddr{};
	class LobbyIdAddr{};
	
	


	
	enum class Category : uint32_t {
		none = 0,
		weapons = 1,
		consumable = 2,
		junk = 3,
		special = 4
	};
	class CArkItem {
	public:
		//TODO: add vtable here
		undefined pad[72];
		int32_t m_maxRandomCount, m_minRandomCount;
		bool m_bFabricating;
		undefined pad2[3];
		int32_t m_count;
		uint32_t m_ownerId;
		bool m_bIsRandom,
			m_bUniqueRandom,
			m_bHideOnSerialize,
			m_bPhysicalizeStatic,
			m_bAddToInventory;
		undefined pad3[3];
		int32_t m_maxStackSize;
		ArkAudioTrigger m_pickupAudioTrigger;
		undefined pad4[4];
		uint64_t m_lootRequirement;
		bool m_bFavorite;
		bool m_bJunk;
		undefined pad5[6];
		uint64_t m_associatedEntitlement;
		uint64_t m_selectedArchetype;
		CryStringT<char> m_pickupModel,
			m_pickupMaterial,
			m_equippedModel,
			m_equippedMaterial;
		float m_pickupLerpSpeed;
		undefined pad6[4];
		CryStringT<char> m_inventoryDescription,
			m_inventoryName;
		CryStringT<wchar_t> m_descKeyword, m_descKeyword2;
		int32_t m_baseDuration;
		undefined pad7[4];
		uint64_t m_consumeSignalId,
			m_consumeSignalId2,
			m_consumeSignalPackage,
			m_consueInboundSignalModPkgId;
		float m_signalDescScale,
			m_signalDescScale2;
		CryStringT<char> m_inventoryIcon,
			m_hudIcon,
			m_stylizedIcon;
		int32_t m_inventoryWidth,
			m_inventoryHeight;
		Category m_category;
		bool m_bStackable;
		undefined pad8[3];
		CryStringT<char> m_consumeVerb;
		float m_dropHeightOffset,
			m_dropDistance,
			m_dropRotationMin,
			m_dropRotationMax;
		bool m_bIsGrenade,
			m_bIsUsable,
			m_bIsConsumable;
		undefined pad9[5];
		CryStringT<char> m_type;
		bool m_bIsUnlimited,
			m_bIsImportant;
		undefined pad10[2];
		int32_t m_dismantleCount;
		bool m_bPlotCritical;
		undefined pad11[7];
	};
	class IArkInventory {
	public:
		virtual int  GetWidth() {}
		virtual int  GetMaxWidth() {}
		virtual int  GetHeight() {}
		virtual bool  Contains(uint32_t entityId) {}
		virtual int  GetCountOfArchetype(uint64_t archetypeId) {}
		virtual  std::vector<IArkItem*>  GetItemsOfArchetype(uint64_t archetypeId) {}
		virtual uint32_t  GetNextItem(int param_1, int param_2, uint32_t param_3) {}
		virtual std::pair<int, int>  GetLocationOfItem(uint32_t entityId) {}
		virtual uint32_t  GetItemAtLocation(int x, int y, uint32_t param_3) {}
		virtual std::vector<uint32_t>  GetItemIDs() {}
		virtual std::vector<uint32_t>  GetOverlappingItems(uint32_t param_1, int param_2, int param_3, int param_4, int param_5) {}
		virtual bool  AddItem(uint32_t entityId) {}
		virtual uint32_t  PlaceItem(uint32_t entityId, int param_2, int param_3) {}
		virtual bool  CanPlaceItem(uint32_t entityId, int param_2, int param_3, bool param_4) {}
		virtual bool  TryPlaceItem(uint32_t entityId, int param_2, int param_3) {}
		virtual bool  CanPackItem(uint32_t param_1) {}
		virtual void  RemoveItem(uint64_t entityId, int count) {}
		virtual void  RemoveItem(uint32_t entityId) {}
		virtual uint32_t  GetOwnerId() {}
		virtual bool  GetTakesTrash() {}
		virtual bool  IsEmpty() {}
		virtual void  NotifyAdded(uint32_t param_1, uint32_t param_2) {}
		virtual void  NotifyOfItemCountChange(uint32_t param_1) {}
		virtual void  DoMetricsSnapshot(XmlNodeRef* param_1) {}
	};
	class ArkInteractionTestResult {
	public:
		bool m_bPassedTest;
		bool m_bHideLine;
		CryStringT<char> m_actionVerb;
		CryStringT<wchar_t> m_localizedActionVerb;
		CryStringT<char> m_requirementText;
		CryStringT<wchar_t> m_localizedRequirementText;
	};
	class IArkPlayerInteractionListener {
	public:
		virtual bool OnInteraction( EArkInteractionType,  EArkInteractionMode, const  IEntity*) = 0;// Offset=0x0 Size=0x3
		virtual bool OnHoldToUseStopped(const  IEntity*) = 0;// Offset=0x0 Size=0x3
		virtual bool OnSpecialUseStopped(const  IEntity*) = 0;// Offset=0x0 Size=0x3
		virtual bool TestInteraction(const  IEntity*,  ArkInteractionInfo&,  EArkInteractionMode,  ArkInteractionTestResult&) = 0;// Offset=0x0 Size=0x3
		virtual bool PopulateInteractionInfo(const  IEntity*,  std::array<ArkInteractionInfo, 4>&) = 0;// Offset=0x0 Size=0x3
		virtual bool PopulateRemoteManipulationInteraction(const  IEntity*,  ArkInteractionInfo&) = 0;// Offset=0x0 Size=0x3
		virtual Vec3_tpl<float> GetInteractionPosition(const  IEntity*) = 0;// Offset=0x0 Size=0xc
		virtual void OnStartLookingAt(unsigned int) = 0;// Offset=0x0 Size=0x3
		virtual void OnStopLookingAt(unsigned int) = 0;// Offset=0x0 Size=0x3
		virtual void OnInteractionInfoChanged(unsigned int) = 0;// Offset=0x0 Size=0x3
		virtual bool HideDisplayName(const  IEntity*) = 0;// Offset=0x0 Size=0x3
	};
	class ArkInventory : public CGameObjectExtensionHelper<ArkInventory, IGameObjectExtension, 64>, public IArkPlayerInteractionListener, public IEntityEventListener, public IArkInventory// Size=0x88 (Id=125206)
	{
	public:
		static const int k_defaultExternalInventoryWidth = 6;// Offset=0x0 Size=0x4
		static const int k_tinyExternalInventoryWidth = 1;// Offset=0x0 Size=0x4
		static const int k_tinyExternalInventoryHeight = 1;// Offset=0x0 Size=0x4
		static const int k_smallExternalInventoryHeight = 2;// Offset=0x0 Size=0x4
		static const int k_mediumExternalInventoryHeight = 4;// Offset=0x0 Size=0x4
		static const int k_largeExternalInventoryHeight = 8;// Offset=0x0 Size=0x4
		static const int k_chipSetHeight = 100;// Offset=0x0 Size=0x4
		enum EArkGridSizes
		{
			tinyExternal = 0,
			smallExternal = 1,
			mediumExternal = 2,
			largeExternal = 3,
			chipSet = 4,
			player = 5,
			overflow = 6
		};
		struct StorageCell// Size=0x14 (Id=490101)
		{
			unsigned int m_entityId;// Offset=0x0 Size=0x4
			int m_x;// Offset=0x4 Size=0x4
			int m_y;// Offset=0x8 Size=0x4
			int m_width;// Offset=0xc Size=0x4
			int m_height;// Offset=0x10 Size=0x4
		};
		bool m_bSortDirty;// Offset=0x58 Size=0x1
		bool m_bSerializeOpen;// Offset=0x59 Size=0x1
		bool m_bPreventStorage;// Offset=0x5a Size=0x1
		bool m_bTakesTrash;// Offset=0x5b Size=0x1
		EArkGridSizes m_size;// Offset=0x5c Size=0x4
		class std::vector<ArkInventory::StorageCell> m_storedItems;// Offset=0x60 Size=0x18
		class ArkSimpleTimer m_lookAtTimer;// Offset=0x78 Size=0x8
		enum InventorySort
		{
			none = 0,
			name = 1,
			category = 2,
			size = 3,
			last = 4
		};
		InventorySort m_currentSort;// Offset=0x80 Size=0x4
	};



	//todo:check enum sizes
	// enum class ECryAiSystemActiveState {
	// 	unknown = -1,
	// 	inactive = 0,
	// 	active = 1
	// };
	
	



	

	


	
	enum class EStatus : int32_t {
		None = 0,
		Pending = 1,
		Installed = 2,
		Exiting = 3,
		Finished = 4
	};
	

	

	

	class ArkMaterialAnimationType{};
	class Package{};
	

	
	
	


		class SBindings		   {};
		class SGridLocation	   {};
		class SProximityElement{};
		
		struct IScriptTable {
			void* ptr;
			uint32_t m_nrefCount,
				m_nRef;
		};
		class ArkSafeScriptTable {
		public:
			CScriptTable* ptr;
		};
		class SEntityLoadParams {
		public:
			SEntitySpawnParams spawnParams;
			CEntity* pReuseEntity;
			bool bCallInit;
			int32_t clonedLayerId;
		};
		class ArkHealthExtension : public IGameObjectExtension{
		public:
			float m_health;
			float m_maxHealth;
		};
		
		struct IParticleEmitter{};
		
		class CScriptBind_ArkPlayer{};
		class CDLight{};
		class SComponentInitializer{};
		class CEntity {
		
		public:
			char pad[8];
			unsigned char m_flags1;
			unsigned char m_flags2;
			unsigned char m_flags3;
			// uint32_t m_bActive : 1;
			// uint32_t m_bInActiveList : 1;
			// uint32_t m_bBoundsValid : 1;
			// uint32_t m_bInitialized : 1;
			// uint32_t m_bHidden : 1;
			// uint32_t m_bGarbage : 1;
			// uint32_t m_bHaveEventListeners : 1;
			// uint32_t m_bTrigger : 1;
			// uint32_t m_bWasRellocated : 1;
			// uint32_t m_nUpdateCounter : 4;
			// uint32_t m_eUpdatePolicy : 4;
			// uint32_t m_bInvisible : 1;
			// uint32_t m_bNotInheritXform : 1;
			// uint32_t m_bInShutDown : 1;
			// uint32_t m_bIsFromPool : 1;
			undefined field23_0xb;
			bool m_bDirtyForwardDir : 1;
			undefined field25_0xd;
			undefined field26_0xe;
			undefined field27_0xf;
			unsigned char m_flags4;
			// uint32_t m_bLoadedFromLevelFile : 1;
			// uint32_t m_bHasPhysicsState : 1;
			undefined field30_0x11;
			undefined field31_0x12;
			undefined field32_0x13;
			uint32_t m_nID;
			uint64_t m_guid;
			uint32_t m_flags;
			uint32_t m_flagsExtended;
			IEntityClass* m_pClass;
			CEntityArchetype* m_pArchetype;
			Vec3_tpl<float> m_vPos;
			Quat_tpl<float> m_qRotation;
			Vec3_tpl<float> m_vScale;
			Matrix34_tpl<float> m_worldTM;
			Vec3_tpl<float> m_vForwardDir;
			undefined field44_0x9c;
			undefined field45_0x9d;
			undefined field46_0x9e;
			undefined field47_0x9f;
			SBindings* m_pBinds;
			uint32_t m_aiObjectID;
			undefined field50_0xac;
			undefined field51_0xad;
			undefined field52_0xae;
			undefined field53_0xaf;
			IMaterial* m_pMaterial;
			std::map<int, std::shared_ptr<IEntityProxy>> m_proxy;
			std::set<std::shared_ptr<IComponent>> m_components;
			IEntityLink* m_pEntityLinks;
			SGridLocation* m_pGridLocation;
			SProximityElement* m_pProximityEntity;
			uint32_t m_nKeepAliveCounter;
			undefined field61_0xf4;
			undefined field62_0xf5;
			undefined field63_0xf6;
			undefined field64_0xf7;
			CryStringT<char> m_szName;
			int32_t m_cloneLayerId;
			unsigned char m_initialSceneMask;
			undefined field68_0x105;
			undefined field69_0x106;
			undefined field70_0x107;
			CryStringT<char> m_displayName;
		};
		class OnEventSink {
		public:
			uint64_t subscriptions;
			IEntitySystemSink* pSink;
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
		class IEntityRegistryListener {
			
		};
		class SEntityDesc {
			
		};
		class CEntityClassRegistry {
		public:
			virtual void*   _ECEntityRegistry(uint32_t param_1) {}
			virtual bool  RegisterEntity( IEntity* param_1) {}
			virtual bool  UnregisterEntity( IEntity* param_1) {}
			virtual  IEntity*  Find(char* param_1) {}
			virtual  ArkNpcAbilityInstance*  GetAbilityInstance() {}
			virtual void  Loades(char* param_1, bool param_2) {}
			virtual  IEntity*  RegisterStd( SEntityDesc* param_1) {}
			virtual void  RegisterListener( IEntityRegistryListener* param_1) {}
			virtual void  UnregisterListener( IEntityRegistryListener* param_1) {}
			virtual void  IteratorMoveFirst() {}
			virtual  IEntity*  IteratorNext() {}
			virtual uint32_t  DoGetCurrentRoomEntityId() {}
			std::map<CryStringT<char>, CEntityClass*> m_mapClassName;
			IEntityClass* m_pDefaultClass;
			ISystem* m_pSystem;
			void* ptr;
			char m_listeners[40];
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
		class IEntityRegistry{};
		//class ArkAimAssistComponent{};
		struct IEntityPoolManager{};
		struct IEntityArchetypeListener{};
		class CEntitySystem : public IEntitySystem {
		public:
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
		namespace CGameName {
			class SPlatformInfo {
			public:
				EPlatform platformId;
				unsigned char devices;
				char pad[3];
			};
		}
		class CGameCache{};
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
		class CGameLocalizationManager		 {};
		class ITelemetryCollector			 {};
		class IPlayerProfileManager			 {};

		 class SPlayerMovement {
		 public:
			float nonCombat_heavy_weapon_speed_scale;
			float nonCombat_heavy_weapon_sprint_scale;
			float nonCombat_heavy_weapon_strafe_speed_scale;
			float nonCombat_heavy_weapon_sneak_speed_scale;
			float power_sprint_targetFov;
			float ground_timeInAirToFall;
			float speedScale;
			float strafe_SpeedScale;
			float sprint_SpeedScale;
			float sneak_SpeedScale;
			int sprintStamina_debug;
			float mp_slope_speed_multiplier_uphill;
			float mp_slope_speed_multiplier_downhill;
			float mp_slope_speed_multiplier_minHill;
		};

		class SPlayerEnemyRamming {
		public:
			float player_to_player;
			float ragdoll_to_player;
			float fall_damage_threashold;
			float safe_falling_speed;
			float fatal_falling_speed;
			float max_falling_damage;
			float min_momentum_to_fall;
		};

		 class SDeathCamSPParams {
		 public:
			int enable;
			int dof_enable;
			float updateFrequency;
			float dofRange;
			float dofRangeNoKiller;
			float dofRangeSpeed;
			float dofDistanceSpeed;
		};

		 class SCaptureTheFlagParams {
		 public:
			float carryingFlag_SpeedScale;
		};

		 class SPlayerPickAndThrow {
		 public:
			int debugDraw;
			int useProxies;
			int cloakedEnvironmentalWeaponsAllowed;
			float maxOrientationCorrectionTime;
			float orientationCorrectionTimeMult;
			float environmentalWeaponObjectImpulseScale;
			float environmentalWeaponImpulseScale;
			float environmentalWeaponHitConeInDegrees;
			float minRequiredThrownEnvWeaponHitVelocity;
			float awayFromPlayerImpulseRatio;
			float environmentalWeaponDesiredRootedGrabAnimDuration;
			float environmentalWeaponDesiredGrabAnimDuration;
			float environmentalWeaponDesiredPrimaryAttackAnimDuration;
			float environmentalWeaponDesiredComboAttackAnimDuration;
			float environmentalWeaponUnrootedPickupTimeMult;
			float environmentalWeaponThrowAnimationSpeed;
			float environmentalWeaponFlippedImpulseOverrideMult;
			float environmentalWeaponFlipImpulseThreshold;
			float environmentalWeaponLivingToArticulatedImpulseRatio;
			int enviromentalWeaponUseThrowInitialFacingOveride;
			float environmentalWeaponMinViewClamp;
			float environmentalWeaponViewLerpZOffset;
			float environmentalWeaponViewLerpSmoothTime;
			float complexMelee_snap_angle_limit;
			float complexMelee_lerp_target_speed;
			float objectImpulseLowMassThreshold;
			float objectImpulseLowerScaleLimit;
			float comboInputWindowSize;
			float minComboInputWindowDurationInSecs;
			float impactNormalGroundClassificationAngle;
			float impactPtValidHeightDiffForImpactStick;
			float reboundAnimPlaybackSpeedMultiplier;
			int environmentalWeaponSweepTestsEnabled;
			float chargedThrowAutoAimDistance;
			float chargedThrowAutoAimConeSize;
			float chargedThrowAutoAimDistanceHeuristicWeighting;
			float chargedThrowAutoAimAngleHeuristicWeighting;
			float chargedThrowAimHeightOffset;
			int chargedthrowAutoAimEnabled;
			int intersectionAssistDebugEnabled;
			int intersectionAssistDeleteObjectOnEmbed;
			float intersectionAssistCollisionsPerSecond;
			float intersectionAssistTimePeriod;
			float intersectionAssistTranslationThreshold;
			float intersectionAssistPenetrationThreshold;
		};

		 class SPredatorParams {
		 public:
			float hudTimerAlertWhenTimeRemaining;
			float hintMessagePauseTime;
		};

		 class SJumpAirControl {
		 public:
			float air_control_scale;
			float air_resistance_scale;
			float air_inertia_scale;
		};

		 class SAIPerceptionCVars{
		 public:
			int movement_useSurfaceType;
			float movement_movingSurfaceDefault;
			float movement_standingRadiusDefault;
			float movement_crouchRadiusDefault;
			float movement_standingMovingMultiplier;
			float movement_crouchMovingMultiplier;
			float landed_baseRadius;
			float landed_speedMultiplier;
		};

		 class SPostEffect {
		 public:
			float FilterGrain_Amount;
			float FilterRadialBlurring_Amount;
			float FilterRadialBlurring_ScreenPosX;
			float FilterRadialBlurring_ScreenPosY;
			float FilterRadialBlurring_Radius;
			float Global_User_ColorC;
			float Global_User_ColorM;
			float Global_User_ColorY;
			float Global_User_ColorK;
			float Global_User_Brightness;
			float Global_User_Contrast;
			float Global_User_Saturation;
			float Global_User_ColorHue;
		};

		 class SPlayerLadder {
		 public:
			int ladder_renderPlayerLast;
			int ladder_logVerbosity;
		};

		 class SGameReleaseConstantCVars {
		 public:
			undefined field0_0x0;
		};

		 class SPlayerSlideControl {
		 public:
			float min_speed_threshold;
			float min_speed;
			float deceleration_speed;
			float min_downhill_threshold;
			float max_downhill_threshold;
			float max_downhill_acceleration;
		};

		 class SPowerSprintParams {
		 public:
			float foward_angle;
		};

		 class SSpectacularKillCVars {
		 public:
			float maxDistanceError;
			float minTimeBetweenKills;
			float minTimeBetweenSameKills;
			float minKillerToTargetDotProduct;
			float maxHeightBetweenActors;
			float sqMaxDistanceFromPlayer;
			int debug;
		};

		 class SPlayerMelee{
		 public:
			float melee_snap_angle_limit;
			float melee_snap_blend_speed;
			float melee_snap_target_select_range;
			float melee_snap_end_position_range;
			float melee_snap_move_speed_multiplier;
			float damage_multiplier_from_behind;
			float damage_multiplier_mp;
			float angle_limit_from_behind;
			float mp_victim_screenfx_intensity;
			float mp_victim_screenfx_duration;
			float mp_victim_screenfx_blendout_duration;
			float mp_victim_screenfx_dbg_force_test_duration;
			int impulses_enable;
			int debug_gfx;
			int mp_melee_system;
			int mp_melee_system_camera_lock_and_turn;
			int mp_knockback_enabled;
			float mp_melee_system_camera_lock_time;
			float mp_melee_system_camera_lock_crouch_height_offset;
			float mp_knockback_strength_vert;
			float mp_knockback_strength_hor;
			int mp_sliding_auto_melee_enabled;
		};

		 class SExtractionParams {
		 public:
			float carryingTick_SpeedScale;
			float carryingTick_EnergyCostPerHit;
			float carryingTick_DamageAbsorbDesperateEnergyCost;
		};

		 class SPlayerLedgeClamber {
		 public:
			float cameraBlendWeight;
			int debugDraw;
			int enableVaultFromStanding;
		};

		 class SAICollisions {
		 public:
			float minSpeedForFallAndPlay;
			float minMassForFallAndPlay;
			float dmgFactorWhenCollidedByObject;
			int showInLog;
		};

		 class SAIThreatModifierCVars {
		 public:
			char* DebugAgentName;
			float SOMIgnoreVisualRatio;
			float SOMDecayTime;
			float SOMMinimumRelaxed;
			float SOMMinimumCombat;
			float SOMCrouchModifierRelaxed;
			float SOMCrouchModifierCombat;
			float SOMMovementModifierRelaxed;
			float SOMMovementModifierCombat;
			float SOMWeaponFireModifierRelaxed;
			float SOMWeaponFireModifierCombat;
			float SOMCloakMaxTimeRelaxed;
			float SOMCloakMaxTimeCombat;
			float SOMUncloakMinTimeRelaxed;
			float SOMUncloakMinTimeCombat;
			float SOMUncloakMaxTimeRelaxed;
			float SOMUncloakMaxTimeCombat;
		};

		 class SAltNormalization {
		 public:
			int enable;
			float hud_ctrl_Curve_Unified;
			float hud_ctrl_Coeff_Unified;
		};

		 class SPlayerHealth {
		 public:
			float normal_regeneration_rateSP;
			float critical_health_thresholdSP;
			float critical_health_updateTimeSP;
			float normal_threshold_time_to_regenerateSP;
			float normal_regeneration_rateMP;
			float critical_health_thresholdMP;
			float fast_regeneration_rateMP;
			float slow_regeneration_rateMP;
			float normal_threshold_time_to_regenerateMP;
			int enable_FallandPlay;
			int collision_health_threshold;
			float fallDamage_SpeedSafe;
			float fallDamage_SpeedFatal;
			float fallSpeed_HeavyLand;
			float fallDamage_SpeedFatalArmor;
			float fallSpeed_HeavyLandArmor;
			float fallDamage_SpeedSafeArmorMP;
			float fallDamage_SpeedFatalArmorMP;
			float fallSpeed_HeavyLandArmorMP;
			float fallDamage_CurveAttackMP;
			float fallDamage_CurveAttack;
			int fallDamage_health_threshold;
			int debug_FallDamage;
			int enableNewHUDEffect;
			int minimalHudEffect;
		};
		 class SCVars {
		 public:
		 	SGameReleaseConstantCVars m_releaseConstants;
			char pad[3];
			float cl_fov;
			float cl_hfov;
			float cl_mp_fov_scalar;
			float cl_tpvDist;
			float cl_tpvYaw;
			float cl_sensitivity;
			float cl_sensitivityController;
			float cl_sensitivityControllerMP;
			float cl_reticleSensitivityController;
			int cl_invertMouse;
			int cl_invertController;
			int cl_sneakToggle;
			int cl_worldUIExaminationToggle;
			int cl_sprintToggle;
			int cl_debugSwimming;
			int cl_logAsserts;
			int cl_zoomToggle;
			float cl_motionBlurVectorScale;
			float cl_motionBlurVectorScaleSprint;
			int g_enableMPDoubleTapGrenadeSwitch;
		 	ICVar* ca_GameControlledStrafingPtr;
			float cl_shallowWaterSpeedMulPlayer;
			float cl_shallowWaterSpeedMulAI;
			float cl_shallowWaterDepthLo;
			float cl_shallowWaterDepthHi;
			float cl_speedToBobFactor;
			float cl_bobAmount;
			float cl_rollAmount;
			float cl_bobWidth;
			float cl_bobHeight;
			float cl_bobSprintMultiplier;
			float cl_bobVerticalMultiplier;
			float cl_bobMaxHeight;
			float cl_strafeHorzScale;
			float g_highlightingMaxDistanceToHighlightSquared;
			float g_highlightingMovementDistanceToUpdateSquared;
			float g_highlightingTimeBetweenForcedRefresh;
			float g_ledgeGrabClearHeight;
			float g_ledgeGrabMovingledgeExitVelocityMult;
			float g_vaultMinHeightDiff;
			float g_vaultMinAnimationSpeed;
			int g_cloakFlickerOnRun;
			int kc_useAimAdjustment;
			float kc_aimAdjustmentMinAngle;
			float kc_precacheTimeStartPos;
			float kc_precacheTimeWeaponModels;
			int g_useQuickGrenadeThrow;
			int g_debugWeaponOffset;
			int g_MicrowaveBeamStaticObjectMaxChunkThreshold;
			float i_fastSelectMultiplier;
			float cl_idleBreaksDelayTime;
			int cl_postUpdateCamera;
			int p_collclassdebug;
			float pl_cameraTransitionTime;
			float pl_cameraTransitionTimeLedgeGrabIn;
			float pl_cameraTransitionTimeLedgeGrabOut;
			float pl_slideCameraFactor;
			float cl_slidingBlurRadius;
			float cl_slidingBlurAmount;
			float cl_slidingBlurBlendSpeed;
			int sv_votingTimeout;
			int sv_votingCooldown;
			int sv_votingEnable;
			int sv_votingMinVotes;
			float sv_votingRatio;
			float sv_votingTeamRatio;
			float sv_votingBanTime;
			int sv_input_timeout;
			ICVar* sv_aiTeamName;
			ICVar* performance_profile_logname;
			int g_infiniteAmmoTutorialMode;
			int i_lighteffects;
			int i_particleeffects;
			int i_rejecteffects;
			int i_grenade_showTrajectory;
			float i_grenade_trajectory_resolution;
			float i_grenade_trajectory_dashes;
			float i_grenade_trajectory_gaps;
			int i_grenade_trajectory_useGeometry;
			int i_ironsight_while_jumping_mp;
			int i_ironsight_while_falling_mp;
			float i_ironsight_falling_unzoom_minAirTime;
			float i_weapon_customisation_transition_time;
			int i_highlight_dropped_weapons;
			float i_laser_hitPosOffset;
			float pl_inputAccel;
			int pl_debug_energyConsumption;
			int pl_debug_pickable_items;
			float pl_useItemHoldTime;
			int pl_autoPickupItemsWhenUseHeld;
			float pl_autoPickupMinTimeBetweenPickups;
			int pl_debug_projectileAimHelper;
			float pl_nanovision_timeToRecharge;
			float pl_nanovision_timeToDrain;
			float pl_nanovision_minFractionToUse;
			float pl_refillAmmoDelay;
			int pl_spawnCorpseOnDeath;
			int pl_doLocalHitImpulsesMP;
			int kc_enable;
			int kc_debug;
			int kc_debugStressTest;
			int kc_debugVictimPos;
			int kc_debugWinningKill;
			int kc_debugSkillKill;
			int kc_memStats;
			int kc_maxFramesToPlayAtOnce;
			int kc_cameraCollision;
			int kc_showHighlightsAtEndOfGame;
			int kc_enableWinningKill;
			int kc_canSkip;
			float kc_length;
			float kc_skillKillLength;
			float kc_bulletSpeed;
			float kc_bulletHoverDist;
			float kc_bulletHoverTime;
			float kc_bulletHoverTimeScale;
			float kc_bulletPostHoverTimeScale;
			float kc_bulletTravelTimeScale;
			float kc_bulletCamOffsetX;
			float kc_bulletCamOffsetY;
			float kc_bulletCamOffsetZ;
			float kc_bulletRiflingSpeed;
			float kc_bulletZoomDist;
			float kc_bulletZoomTime;
			float kc_bulletZoomOutRatio;
			float kc_kickInTime;
			float kc_projectileDistance;
			float kc_projectileHeightOffset;
			float kc_largeProjectileDistance;
			float kc_largeProjectileHeightOffset;
			float kc_projectileVictimHeightOffset;
			float kc_projectileMinimumVictimDist;
			float kc_smoothing;
			float kc_grenadeSmoothingDist;
			float kc_cameraRaiseHeight;
			float kc_resendThreshold;
			float kc_chunkStreamTime;
			float g_multikillTimeBetweenKills;
			float g_flushed_timeBetweenGrenadeBounceAndSkillKill;
			float g_gotYourBackKill_targetDistFromFriendly;
			float g_gotYourBackKill_FOVRange;
			float g_guardian_maxTimeSinceLastDamage;
			float g_defiant_timeAtLowHealth;
			float g_defiant_lowHealthFraction;
			float g_intervention_timeBetweenZoomedAndKill;
			float g_blinding_timeBetweenFlashbangAndKill;
			float g_blinding_flashbangRecoveryDelayFrac;
			float g_neverFlagging_maxMatchTimeRemaining;
			float g_combinedFire_maxTimeBetweenWeapons;
			float g_fovToRotationSpeedInfluence;
			int dd_maxRMIsPerFrame;
			float dd_waitPeriodBetweenRMIBatches;
			int g_debugSpawnPointsRegistration;
			int g_debugSpawnPointValidity;
			float g_randomSpawnPointCacheTime;
			int g_detachCamera;
			int g_moveDetachedCamera;
			float g_detachedCameraMoveSpeed;
			float g_detachedCameraRotateSpeed;
			float g_detachedCameraTurboBoost;
			int g_detachedCameraDebug;
			int g_difficultyLevel;
			int g_difficultyLevelLowestPlayed;
			float g_flashBangMinSpeedMultiplier;
			float g_flashBangSpeedMultiplierFallOffEase;
			float g_flashBangNotInFOVRadiusFraction;
			float g_flashBangMinFOVMultiplier;
			int g_flashBangFriends;
			int g_flashBangSelf;
			float g_friendlyLowerItemMaxDistance;
			int g_holdObjectiveDebug;
			int g_gameRayCastQuota;
			int g_gameIntersectionTestQuota;
			int g_STAPCameraAnimation;
			float g_reticleYPercentage;
			float g_ExplosionImpulseScale;
			int g_debugaimlook;
			float g_playerLowHealthThreshold;
			float g_playerMidHealthThreshold;
			int g_SurvivorOneVictoryConditions_watchLvl;
			int g_SimpleEntityBasedObjective_watchLvl;
			int g_CTFScoreElement_watchLvl;
			int g_KingOfTheHillObjective_watchLvl;
			float g_HoldObjective_secondsBeforeStartForSpawn;
			int g_CombiCaptureObjective_watchLvl;
			int g_CombiCaptureObjective_watchTerminalSignalPlayers;
			int g_disable_OpponentsDisconnectedGameEnd;
			int g_victoryConditionsDebugDrawResolution;
			int g_restartWhenPrematchFinishes;
			float g_predator_marineRedCrosshairDelay;
			int sv_pacifist;
			int g_devDemo;
			int g_bulletPenetrationDebug;
			float g_bulletPenetrationDebugTimeout;
			int g_fpDbaManagementEnable;
			int g_fpDbaManagementDebug;
			int g_charactersDbaManagementEnable;
			int g_charactersDbaManagementDebug;
			int g_thermalVisionDebug;
			float g_droppedItemVanishTimer;
			float g_droppedHeavyWeaponVanishTimer;
			int g_corpseManager_maxNum;
			float g_corpseManager_timeoutInSeconds;
			float g_explosion_materialFX_raycastLength;
			int g_ec_enable;
			float g_ec_radiusScale;
			float g_ec_volume;
			float g_ec_extent;
			int g_ec_removeThreshold;
			float g_radialBlur;
			float g_timelimit;
			float g_timelimitextratime;
			float g_roundScoreboardTime;
			float g_roundStartTime;
			int g_roundlimit;
			float g_friendlyfireratio;
			int g_revivetime;
			int g_minplayerlimit;
			float g_hostMigrationResumeTime;
			int g_hostMigrationUseAutoLobbyMigrateInPrivateGames;
			int g_minPlayersForRankedGame;
			float g_gameStartingMessageTime;
			int g_mpRegenerationRate;
			int g_mpHeadshotsOnly;
			int g_mpNoVTOL;
			int g_mpNoEnvironmentalWeapons;
			int g_allowCustomLoadouts;
			int g_allowFatalityBonus;
			float g_spawnPrecacheTimeBeforeRevive;
			float g_autoReviveTime;
			float g_spawn_timeToRetrySpawnRequest;
			float g_spawn_recentSpawnTimer;
			float g_forcedReviveTime;
			int g_numLives;
			int g_autoAssignTeams;
			float g_maxHealthMultiplier;
			int g_mp_as_DefendersMaxHealth;
			float g_xpMultiplyer;
			int g_allowExplosives;
			int g_forceWeapon;
			int g_allowSpectators;
			int g_infiniteCloak;
			int g_allowWeaponCustomisation;
			ICVar* g_forceHeavyWeapon;
			ICVar* g_forceLoadoutPackage;
			int g_switchTeamAllowed;
			int g_switchTeamRequiredPlayerDifference;
			int g_switchTeamUnbalancedWarningDifference;
			float g_switchTeamUnbalancedWarningTimer;
			int g_tk_punish;
			int g_tk_punish_limit;
			int g_debugNetPlayerInput;
			int g_debugCollisionDamage;
			int g_debugHits;
			int g_suppressHitSanityCheckWarnings;
			int g_drawLeaks;
			int g_transcribeAutosaveFrequency;
			int g_enableLanguageSelectionMenu;
			int g_multiplayerDefault;
			int g_multiplayerModeOnly;
			int g_EPD;
			int g_frontEndRequiredEPD;
			int g_EnableDevMenuOptions;
			int g_frontEndUnicodeInput;
			int g_DisableMenuButtons;
			int g_EnablePersistantStatsDebugScreen;
			int g_craigNetworkDebugLevel;
			int g_presaleUnlock;
			int g_dlcPurchaseOverwrite;
			int g_MatchmakingVersion;
			int g_MatchmakingBlock;
			int g_enableInitialLoadoutScreen;
			int g_ProcessOnlineCallbacks;
			float g_gameRules_startTimerLength;
			float g_gameRules_postGame_HUDMessageTime;
			float g_gameRules_postGame_Top3Time;
			float g_gameRules_postGame_ScoreboardTime;
			int g_gameRules_startTimerMinPlayers;
			int g_gameRules_startTimerMinPlayersPerTeam;
			float g_gameRules_startTimerPlayersRatio;
			float g_gameRules_startTimerOverrideWait;
			int g_gameRules_preGame_StartSpawnedFrozen;
			int g_debug_fscommand;
			int g_skipIntro;
			int g_skipAfterLoadingScreen;
			int g_goToCampaignAfterTutorial;
			int g_aiCorpses_Enable;
			int g_aiCorpses_DebugDraw;
			int g_aiCorpses_MaxCorpses;
			float g_aiCorpses_DelayTimeToSwap;
			float g_aiCorpses_CullPhysicsDistance;
			float g_aiCorpses_ForceDeleteDistance;
			int g_scoreLimit;
			int g_scoreLimitOverride;
			float g_spawn_explosiveSafeDist;
			int g_logPrimaryRound;
			int g_server_region;
			int g_enableInitialLoginSilent;
			float g_dataRefreshFrequency;
			int g_maxGameBrowserResults;
			int g_inventoryNoLimits;
			int g_inventoryWeaponCapacity;
			int g_inventoryExplosivesCapacity;
			int g_inventoryGrenadesCapacity;
			int g_inventorySpecialCapacity;
			int g_loadoutServerControlled;
			 ICVar* pl_debug_filter;
			int pl_debug_vistable;
			int pl_debug_movement;
			int pl_debug_jumping;
			int pl_debug_aiming;
			int pl_debug_aiming_input;
			int pl_debug_view;
			int pl_debug_hit_recoil;
			int pl_debug_look_poses;
			int pl_renderInNearest;
			int pl_aim_assistance_enabled;
			int pl_aim_assistance_disabled_atDifficultyLevel;
			int pl_aim_acceleration_enabled;
			float pl_aim_cloaked_multiplier;
			float pl_aim_near_lookat_target_distance;
			int pl_targeting_debug;
			int pl_switchTPOnKill;
			int pl_stealthKill_allowInMP;
			int pl_stealthKill_uncloakInMP;
			int pl_stealthKill_debug;
			float pl_stealthKill_aimVsSpineLerp;
			float pl_stealthKill_maxVelocitySquared;
			int pl_slealth_cloakinterference_onactionMP;
			int pl_stealthKill_usePhysicsCheck;
			int pl_stealthKill_useExtendedRange;
			float pl_stealth_shotgunDamageCap;
			float pl_shotgunDamageCap;
			float pl_freeFallDeath_cameraAngle;
			float pl_freeFallDeath_fadeTimer;
			float pl_fall_intensity_multiplier;
			float pl_fall_intensity_max;
			float pl_fall_time_multiplier;
			float pl_fall_time_max;
			float pl_fall_intensity_hit_multiplier;
			float pl_TacticalScanDuration;
			float pl_TacticalScanDurationMP;
			float pl_TacticalTaggingDuration;
			float pl_TacticalTaggingDurationMP;
			float controller_power_curve;
			float controller_multiplier_z;
			float controller_multiplier_x;
			float controller_full_turn_multiplier_x;
			float controller_full_turn_multiplier_z;
			int ctrlr_corner_smoother;
			int ctrlr_corner_smoother_debug;
			int ctrlr_OUTPUTDEBUGINFO;
			float pl_stampTimeout;
			int pl_stampTier;
			float pl_jump_maxTimerValue;
			float pl_jump_baseTimeAddedPerJump;
			float pl_jump_currentTimeMultiplierOnJump;
			float pl_jump_quickPressThresh;
			int pl_showClimbIndicator;
			int pl_boostedMelee_allowInMP;
			float pl_velocityInterpAirControlScale;
			int pl_velocityInterpSynchJump;
			int pl_debugInterpolation;
			float pl_velocityInterpAirDeltaFactor;
			float pl_velocityInterpPathCorrection;
			int pl_velocityInterpAlwaysSnap;
			int pl_adjustJumpAngleWithFloorNormal;
			float pl_netAimLerpFactor;
			float pl_netSerialiseMaxSpeed;
			int pl_serialisePhysVel;
			float pl_clientInertia;
			float pl_fallHeight;
			float pl_legs_colliders_dist;
			float pl_legs_colliders_scale;
			float g_manualFrameStepFrequency;
			SPowerSprintParams pl_power_sprint;
			SJumpAirControl pl_jump_control;
			SPlayerHealth pl_health;
			SPlayerMovement pl_movement;
			SPlayerLedgeClamber pl_ledgeClamber;
			SPlayerLadder pl_ladderControl;
			SPlayerPickAndThrow pl_pickAndThrow;
			SPlayerSlideControl pl_sliding_control;
			SPlayerSlideControl pl_sliding_control_mp;
			SPlayerEnemyRamming pl_enemy_ramming;
			SAICollisions AICollisions;
			SPlayerMelee pl_melee;
			SAltNormalization aim_altNormalization;
			SCaptureTheFlagParams mp_ctfParams;
			SExtractionParams mp_extractionParams;
			SPredatorParams mp_predatorParams;
			int g_FootstepSoundsFollowEntity;
			int g_FootstepSoundsDebug;
			float g_footstepSoundMaxDistanceSq;
			float pl_swimBackSpeedMul;
			float pl_swimSideSpeedMul;
			float pl_swimVertSpeedMul;
			float pl_swimNormalSprintSpeedMul;
			int pl_swimAlignArmsToSurface;
			int pl_drownDamage;
			float pl_drownTime;
			float pl_drownRecoveryTime;
			float pl_drownDamageInterval;
			int pl_mike_debug;
			int pl_mike_maxBurnPoints;
			int pl_impulseEnabled;
			float pl_impulseDuration;
			int pl_impulseLayer;
			float pl_impulseFullRecoilFactor;
			float pl_impulseMaxPitch;
			float pl_impulseMaxTwist;
			float pl_impulseCounterFactor;
			int pl_ZeroGRollFixInputMode;
			int pl_ZeroGRollMode;
			int pl_ZeroGRollPivotOffset;
			float pl_ExplosionUpImpulseScale;
			float pl_PsiTargetingDepthCamSpeed;
			float pl_fictionalTimeScale;
			int pl_unlimitedPsi;
			int pl_forceFlashlight;
			int pl_infiniteFlashlight;
			int pl_useFemaleModel;
			float pl_cameraNearZ;
			int pl_enableTraumas;
			int g_assertWhenVisTableNotUpdatedForNumFrames;
			float gl_time;
			float gl_waitForBalancedGameTime;
			int hud_ContextualHealthIndicator;
			float hud_objectiveIcons_flashTime;
			int hud_faderDebug;
			int hud_ctrlZoomMode;
			int hud_aspectCorrection;
			float hud_canvas_width_adjustment;
			int hud_colorLine;
			int hud_colorOver;
			int hud_colorText;
			float hud_defaultObjectiveTaskOpaqueDistance;
			float hud_objectiveTaskFadeDistance;
			float hud_objectiveTaskTextFadeDistance;
			float hud_logVisibleDuration;
			int hud_subtitles;
			int hud_tutorials;
			int hud_playstationContext;
			int hud_forceControllerGlyphs;
			int hud_startPaused;
			int hud_allowMouseInput;
			int hud_reticleSetting;
			int hud_showOptionalHud;
			int hud_showPlayerState;
			int hud_showHitFeedback;
			int hud_showObjectiveMarkers;
			int hud_showEnemyMarkers;
			int hud_showPsiScanPrompt;
			int hud_showHudLog;
			int hud_showLegends;
			int hud_showInteractPrompt;
			int hud_showEnemyHealthBar;
			int hud_psychoPsycho;
			int hud_hide;
			int menu3D_enabled;
			int g_flashrenderingduringloading;
			int g_levelfadein_levelload;
			int g_levelfadein_quickload;
			float aim_assistMinDistance;
			float aim_assistMaxDistance;
			float aim_assistMaxDistanceTagged;
			float aim_assistFalloffDistance;
			float aim_assistInputForFullFollow_Ironsight;
			float aim_assistMinTurnScale;
			float aim_assistSlowFalloffStartDistance;
			float aim_assistSlowDisableDistance;
			float aim_assistSlowThresholdOuter;
			float aim_assistSlowDistanceModifier;
			float aim_assistSlowStartFadeinDistance;
			float aim_assistSlowStopFadeinDistance;
			float aim_assistStrength;
			float aim_assistSnapRadiusScale;
			float aim_assistSnapRadiusTaggedScale;
			float aim_assistStrength_IronSight;
			float aim_assistMaxDistance_IronSight;
			float aim_assistMinTurnScale_IronSight;
			float aim_assistStrength_SniperScope;
			float aim_assistMaxDistance_SniperScope;
			float aim_assistMinTurnScale_SniperScope;
			ICVar* i_debuggun_1;
			ICVar* i_debuggun_2;
			float slide_spread;
			int i_debug_projectiles;
			int i_debug_weaponActions;
			int i_debug_spread;
			int i_debug_recoil;
			int i_auto_turret_target;
			int i_auto_turret_target_tacshells;
			int i_debug_zoom_mods;
			int i_debug_turrets;
			int i_debug_sounds;
			int i_debug_mp_flowgraph;
			int i_flashlight_has_shadows;
			int i_flashlight_has_fog_volume;
			int i_debug_itemparams_memusage;
			int i_debug_weaponparams_memusage;
			float i_failedDetonation_speedMultiplier;
			float i_failedDetonation_lifetime;
			float i_hmg_detachWeaponAnimFraction;
			float i_hmg_impulseLocalDirection_x;
			float i_hmg_impulseLocalDirection_y;
			float i_hmg_impulseLocalDirection_z;
			int g_displayIgnoreList;
			int g_buddyMessagesIngame;
			int g_enableFriendlyAIHits;
			int g_enableFriendlyPlayerHits;
			int g_mpAllSeeingRadar;
			int g_mpAllSeeingRadarSv;
			int g_mpDisableRadar;
			int g_mpNoEnemiesOnRadar;
			int g_mpHatsBootsOnRadar;
			int g_spectate_TeamOnly;
			int g_spectate_DisableManual;
			int g_spectate_DisableDead;
			int g_spectate_DisableFree;
			int g_spectate_DisableFollow;
			float g_spectate_skipInvalidTargetAfterTime;
			float g_spectate_follow_orbitYawSpeedDegrees;
			int g_spectate_follow_orbitAlsoRotateWithTarget;
			float g_spectate_follow_orbitMouseSpeedMultiplier;
			float g_spectate_follow_orbitMinPitchRadians;
			float g_spectate_follow_orbitMaxPitchRadians;
			int g_deathCam;
			int g_spectatorOnly;
			float g_spectatorOnlySwitchCooldown;
			int g_forceIntroSequence;
			int g_IntroSequencesEnabled;
			 SDeathCamSPParams g_deathCamSP;
			float g_tpdeathcam_timeOutKilled;
			float g_tpdeathcam_timeOutSuicide;
			float g_tpdeathcam_lookDistWhenNoKiller;
			float g_tpdeathcam_camDistFromPlayerStart;
			float g_tpdeathcam_camDistFromPlayerEnd;
			float g_tpdeathcam_camDistFromPlayerMin;
			float g_tpdeathcam_camHeightTweak;
			float g_tpdeathcam_camCollisionRadius;
			float g_tpdeathcam_maxBumpCamUpOnCollide;
			float g_tpdeathcam_zVerticalLimit;
			float g_tpdeathcam_testLenIncreaseRestriction;
			float g_tpdeathcam_collisionEpsilon;
			float g_tpdeathcam_directionalFocusGroundTestLen;
			float g_tpdeathcam_camSmoothSpeed;
			float g_tpdeathcam_maxTurn;
			int g_killercam_disable;
			float g_killercam_displayDuration;
			float g_killercam_dofBlurAmount;
			float g_killercam_dofFocusRange;
			int g_killercam_canSkip;
			float g_postkill_minTimeForDeathCamAndKillerCam;
			float g_postkill_splitScaleDeathCam;
			int g_useHitSoundFeedback;
			int g_useSkillKillSoundEffects;
			int g_hasWindowFocus;
			int g_displayPlayerDamageTaken;
			int g_displayDbgText_hud;
			int g_displayDbgText_silhouettes;
			int g_displayDbgText_plugins;
			int g_displayDbgText_pmv;
			int g_displayDbgText_actorState;
			int g_spawn_vistable_numLineTestsPerFrame;
			int g_spawn_vistable_numAreaTestsPerFrame;
			int g_showShadowChar;
			int g_infiniteAmmo;
			float g_persistantStats_gamesCompletedFractionNeeded;
			int g_animatorDebug;
			int g_hideArms;
			int g_debugSmokeGrenades;
			float g_smokeGrenadeRadius;
			float g_empOverTimeGrenadeLife;
			int g_kickCarDetachesEntities;
			float g_kickCarDetachStartTime;
			float g_kickCarDetachEndTime;
			int g_playerUsesDedicatedInput;
			int watch_enabled;
			float watch_text_render_start_pos_x;
			float watch_text_render_start_pos_y;
			float watch_text_render_size;
			float watch_text_render_lineSpacing;
			float watch_text_render_fxscale;
			int autotest_enabled;
			 ICVar* autotest_state_setup;
			int autotest_quit_when_done;
			int autotest_verbose;
			int designer_warning_enabled;
			int designer_warning_level_resources;
			int g_teamDifferentiation;
			 SPostEffect g_postEffect;
			int g_gameFXSystemDebug;
			int g_gameFXLightningProfile;
			int g_DebugDrawPhysicsAccess;
			int ai_DebugVisualScriptErrors;
			int ai_EnablePressureSystem;
			int ai_DebugPressureSystem;
			int ai_DebugAggressionSystem;
			int ai_DebugBattleFront;
			int ai_DebugSearch;
			int ai_DebugDeferredDeath;
			float ai_CloakingDelay;
			float ai_CompleteCloakDelay;
			float ai_UnCloakingDelay;
			int ai_HazardsDebug;
			int ai_SquadManager_DebugDraw;
			float ai_SquadManager_MaxDistanceFromSquadCenter;
			float ai_SquadManager_UpdateTick;
			float ai_ProximityToHostileAlertnessIncrementThresholdDistance;
			int ai_invulnerable;
			int ai_cantdie;
			int ai_forceEnableNightmareManager;
			int g_actorViewDistRatio;
			int g_playerLodRatio;
			float g_itemsLodRatioScale;
			float g_itemsViewDistanceRatioScale;
			int g_hitDeathReactions_enable;
			int g_hitDeathReactions_useLuaDefaultFunctions;
			int g_hitDeathReactions_disable_ai;
			int g_hitDeathReactions_debug;
			int g_hitDeathReactions_disableRagdoll;
			int g_hitDeathReactions_usePrecaching;
			int g_hitDeathReactions_logReactionAnimsOnLoading;
			int g_hitDeathReactions_streaming;
			 SSpectacularKillCVars g_spectacularKill;
			int g_movementTransitions_enable;
			int g_movementTransitions_log;
			int g_movementTransitions_debug;
			float g_maximumDamage;
			float g_instantKillDamageThreshold;
			int g_flyCamLoop;
			int g_dummyPlayersFire;
			int g_dummyPlayersMove;
			int g_dummyPlayersChangeWeapon;
			float g_dummyPlayersJump;
			int g_dummyPlayersRespawnAtDeathPosition;
			int g_dummyPlayersCommitSuicide;
			int g_dummyPlayersShowDebugText;
			float g_dummyPlayersMinInTime;
			float g_dummyPlayersMaxInTime;
			float g_dummyPlayersMinOutTime;
			float g_dummyPlayersMaxOutTime;
			 ICVar* g_dummyPlayersGameRules;
			int g_dummyPlayersRanked;
			int g_muzzleFlashCull;
			float g_muzzleFlashCullDistance;
			int g_rejectEffectVisibilityCull;
			float g_rejectEffectCullDistance;
			int g_mpCullShootProbablyHits;
			float g_cloakRefractionScale;
			float g_cloakBlendSpeedScale;
			int g_telemetry_onlyInGame;
			int g_telemetry_drawcall_budget;
			int g_telemetry_memory_display;
			int g_telemetry_memory_size_sp;
			int g_telemetry_memory_size_mp;
			int g_telemetry_gameplay_enabled;
			int g_telemetry_gameplay_save_to_disk;
			int g_telemetry_gameplay_gzip;
			int g_telemetry_gameplay_copy_to_global_heap;
			int g_telemetryEnabledSP;
			float g_telemetrySampleRatePerformance;
			float g_telemetrySampleRateBandwidth;
			float g_telemetrySampleRateMemory;
			float g_telemetrySampleRateSound;
			float g_telemetry_xp_event_send_interval;
			float g_telemetry_mp_upload_delay;
			char* g_telemetryTags;
			char* g_telemetryConfig;
			int g_telemetry_serialize_method;
			int g_telemetryDisplaySessionId;
			char* g_telemetryEntityClassesToExport;
			int g_modevarivar_proHud;
			int g_modevarivar_disableKillCam;
			int g_modevarivar_disableSpectatorCam;
			char* g_dataCentreConfigStr;
			char* g_downloadMgrDataCentreConfigStr;
			int g_ignoreDLCRequirements;
			float sv_netLimboTimeout;
			float g_idleKickTime;
			int g_useOnlineServiceForDedicated;
			int g_enablePoolCache;
			int g_setActorModelFromLua;
			int g_loadPlayerModelOnLoad;
			int g_enableActorLuaCache;
			int g_enableSlimCheckpoints;
			float g_mpLoaderScreenMaxTime;
			float g_mpLoaderScreenMaxTimeSoftLimit;
			int g_mpKickableCars;
			float g_forceItemRespawnTimer;
			float g_defaultItemRespawnTimer;
			float g_updateRichPresenceInterval;
			int g_useNetSyncToSpeedUpRMIs;
			ICVar* g_presaleURL;
			ICVar* g_messageOfTheDay;
			ICVar* g_serverImageUrl;
			SAIPerceptionCVars ai_perception;
			SAIThreatModifierCVars ai_threatModifiers;
			int pl_showInactiveTasks;
			float pl_maxRegen;
			float pl_taskLabelShowAngle;
			int pl_enableFPIK;
			float pl_incrementCameraYaw;
			int g_debugTimerEvents;
			int beta_debugShift;
			int pl_playerVoiceOn;
			int pl_playerVoiceFemale;
			int pl_danielleRobo;
			int s_DrawDialogAudioLatency;
			int pl_traumaDebug;
			int g_shownightmareheat;
			int g_debugdistraction;
			int g_debugDistractionCurrentAI;
			int wpn_firstTimePickup;
			float g_arkLightDisableDistance;
		};
		class SItemStrings {};
		class CGameSharedParametersStorage {};
		class CScreenEffects{};
		class CDownloadMgr{};
		class CDLCManager{};
		class CLightningGameEffect{};
		class CParameterGameEffect{};
		class CWorldBuilder{};
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

		
		class IFFont		   {};
		
		class CConsoleCommand {
		public:
			CryStringT<char> m_sName,
				m_sCommand,
				m_sHelp;
			int32_t m_nFlags;
			char pad[4];
			void* m_func;

		};
		class SDeferredCommand {
		public:
			CryStringT<char> command;
			bool silentMode;
			char pad[7];
		};
		class SConfigVar {
		public:
			CryStringT<char> m_value;
			bool m_partOfGroup;
			char pad[7];
		};
		class SDefaultValidator{};
		class CCpuFeatures{};
		class CStreamEngine{};
		class CPhysRenderer{};
		
		class IArchiveHost{};
		class CrySizerStats{};
		class CrySizerImpl{};
		class CThreadProfiler{};
		class CFileStream{};
		class CUDPStream{};
		class CDownloadManager{};
		class ILoadingProgressListener{};
		class CCmdLine{};
		class CThreadTaskManager{};
		class CResourceManager{};
		class IMiniGUI{};
		class IArkBethesdaNetManage{};
		class CLocalizedStringsManager{};
		class CServerThrottle{};
		enum class ELockMode {};
		
		class SSerializeString{};
		class ISerializeUpdateFunction{};
		class SNetObjectID{};
		
		

		
		class SDllHandles {
		public:
			char pad[120];
		};
		class CCryNameCRC {
		public:
			uint32_t m_nId;
		};
		class CFrameProfileSystem {
		public:
			void* ptr;
		};
		class CNameTable {
		public:
			char pad[72];
		};
		class CMemoryFragmentationProfiler {
		public:
			uint32_t m_dwLine;
		};
		class SErrorMessage {
		public:
			CryStringT<char> m_Message;
			float m_fTimeToShow;
			float m_Color[4];
			bool m_HardFailure;
			char pad[3];
		};
		class CProfilingSystem {
		public:
			void* ptr;
		};
		class CWindowsConsole {
		public:
		};
		class CVar {
		public:
			bool m_param;
		};
		class ArkNpcAbilityInstance {};
		class IAISignalExtraData{};
		class CPNoise3{};
		class SModuleInitInfo{};

		struct ArkBuildInfo
		{
			bool m_isLocalBuild;
			std::map<string, string> m_buildInfo;
			const string k_buildIDKey;
			const string k_branchKey;
			const string k_changeListKey;
			string m_Description;
			string m_FullInfo;
			std::mutex m_buildInfoMutex;
		};

		typedef void(_cdecl FuncDef259)();
		typedef void(_cdecl FuncDef258)();
		typedef void(_cdecl FuncDef257)();
		typedef void(_cdecl FuncDef256)();
		typedef void(_cdecl FuncDef255)();
		typedef void(_cdecl FuncDef254)();
		typedef void(_cdecl FuncDef254)();
		typedef void(_cdecl FuncDef253)();
		typedef void(_cdecl FuncDef252)();
		class ArkTutorialSystem{};
		class EGoalOpResult{};
		class CPipeUser{};
		//class ArkAudioLogComponent{};
		class IAudioSystemImplementation{};
		class AKRESULT{};
		class CXConsole {
		public:
			virtual void*   _ECXConsole(uint32_t param_1) {}
			virtual void  Complete() {}
			virtual  ICVar*  RegisterString(char* param_1, char* param_2, int32_t param_3, char* param_4,  FuncDef259* param_5) {}
			virtual  ICVar*  RegisterInt(char* param_1, int32_t param_2, int32_t param_3, char* param_4,  FuncDef258* param_5) {}
			virtual  ICVar*  RegisterInt64(char* param_1, __int64 param_2, int32_t param_3, char* param_4,  FuncDef257* param_5) {}
			virtual  ICVar*  RegisterFloat(char* param_1, float param_2, int32_t param_3, char* param_4,  FuncDef256* param_5) {}
			virtual  ICVar*  Register(char* param_1, char** param_2, char* param_3, int32_t param_4, char* param_5,  FuncDef255* param_6, bool param_7) {}
			virtual  ICVar*  Register(char* param_1, int32_t* param_2, int32_t param_3, int32_t param_4, char* param_5,  FuncDef253* param_6, bool param_7) {}
			virtual  ICVar*  Register(char* param_1, float* param_2, float param_3, int32_t param_4, char* param_5,  FuncDef254* param_6, bool param_7) {}
			virtual void  UnregisterVariable(char* param_1, bool param_2) {}
			virtual void  SetScrollMax(int32_t param_1) {}
			virtual void  AddOutputPrintSink( IOutputPrintSink* param_1) {}
			virtual void  RemoveOutputPrintSink( IOutputPrintSink* param_1) {}
			virtual void  ShowConsole(bool param_1, int32_t param_2) {}
			virtual void  DumpCVars( ICVarDumpSink* param_1, uint32_t param_2) {}
			virtual void  DumpCVarsToFile(char* param_1, uint32_t param_2) {}
			virtual void  CreateKeyBind(char* param_1, char* param_2) {}
			virtual void  SetImage( ITexture* param_1, bool param_2) {}
			virtual  ArkTutorialSystem*  GetArkTutorialSystem() {}
			virtual void  StaticBackground(bool param_1) {}
			virtual void  SetLoadingImage(char* param_1) {}
			virtual bool  GetLineNo(int32_t param_1, char* param_2, int32_t param_3) {}
			virtual int32_t  GetFlags2() {}
			virtual  ICVar*  GetCVar(char* param_1) {}
			virtual float  CalcEnergy(float param_1) {}
			virtual wchar_t*  Action() {}
			virtual void  PrintLine(char* param_1) {}
			virtual void  PrintLinePlus(char* param_1) {}
			virtual bool  GetStatus() {}
			virtual void  Clear() {}
			virtual void  Update() {}
			virtual void  Draw() {}
			virtual void  CopyToClipboard(char* param_1) {}
			virtual void  AddCommand(char* param_1, char* param_2, int32_t param_3, char* param_4) {}
			virtual void  AddCommand(char* param_1,  FuncDef252* param_2, int32_t param_3, char* param_4) {}
			virtual void  RemoveCommand(char* param_1) {}
			virtual void  ExecuteString(char* param_1, bool param_2, bool param_3) {}
			virtual void  Exit(char* param_1) {}
			virtual bool  IsOpened() {}
			virtual uint32_t  GetInstanceID() {}
			virtual uint64_t  GetSortedVars(char** param_1, uint64_t param_2, char* param_3) {}
			virtual char*  AutoComplete(char* param_1) {}
			virtual char*  AutoCompletePrev(char* param_1) {}
			virtual char*  ProcessCompletion(char* param_1) {}
			virtual void  RegisterAutoComplete(char* param_1,  IConsoleArgumentAutoComplete* param_2) {}
			virtual void  UnRegisterAutoComplete(char* param_1) {}
			virtual void  ResetAutoCompletion() {}
			virtual void  GetMemoryUsage( ICrySizer* param_1) {}
			virtual void  ResetProgressBar(int32_t param_1) {}
			virtual void  TickProgressBar() {}
			virtual void  SetInputLine(char* param_1) {}
			virtual void  DumpKeyBinds( IKeyBindDumpSink* param_1) {}
			virtual char*  FindKeyBind(char* param_1) {}
			virtual int32_t  GetNumCheatVars() {}
			virtual void  SetCheatVarHashRange(uint64_t param_1, uint64_t param_2) {}
			virtual void  CalcCheatVarHash() {}
			virtual bool  IsHashCalculated() {}
			virtual uint64_t  GetCheatVarHash() {}
			virtual void   $FunctionCaller( EArkNpcFacingDesireCallbackEvent* param_2) {}
			virtual char*  GetCheatVarAt(uint32_t param_1) {}
			virtual void  AddConsoleVarSink( IConsoleVarSink* param_1) {}
			virtual void  RemoveConsoleVarSink( IConsoleVarSink* param_1) {}
			virtual char*  GetHistoryElement(bool param_1) {}
			virtual void  AddCommandToHistory(char* param_1) {}
			virtual void  LoadConfigVar(char* param_1, char* param_2) {}
			virtual void  EnableActivationKey(bool param_1) {}
			virtual void  FindVar(char* param_1) {}
			virtual bool  OnBeforeVarChange( ICVar* param_1, char* param_2) {}
			virtual void  OnAfterVarChange( ICVar* param_1) {}
		private:
			virtual void*   Garbage0() {}
		public:
			virtual bool   RIArchive(char* param_1, char* param_2, char* param_3) {}
		private:
			virtual bool   Garbage1() {}
			virtual wchar_t* Garbage2() {}
			virtual void* Garbage3() {}
		public:
			virtual void  OnConsoleCommand(char* param_1) {}
		private:
			virtual void   Garbage4() {}
		public:
			virtual void*   _ECXConsoleVariableString(uint32_t param_1) {}
			virtual void  Release() {}
			virtual int32_t  GetIVal() {}
			virtual __int64  GetI64Val() {}
			virtual float  GetFVal() {}
			virtual uint64_t  GetCurrentContextIndex() {}
			virtual char*  GetDataProbeString() {}
			virtual void  Set(int32_t param_1) {}
			virtual void  Set(float param_1) {}
			virtual void  Set(char* param_1) {}
			virtual void  ForceSet(char* param_1) {}
			virtual void  ClearFlags(int32_t param_1) {}
			virtual int32_t  GetDepth() {}
			virtual int32_t  SetFlags(int32_t param_1) {}
			virtual  EGoalOpResult*  Execute( CPipeUser* param_1) {}
			virtual  HWND*   $GetValueFromMemberVariable() {}
			virtual  ArkAudioLogComponent*  GetAudioLogComponent() {}
			virtual bool  IsConstCVar() {}
			virtual void  Init( IAudioSystemImplementation* param_1) {}
			virtual void  AddOnChangeFunctor( SFunctor* param_1) {}
			virtual uint64_t  GetNumberOfOnChangeFunctors() {}
			virtual  SFunctor*  GetOnChangeFunctor(uint64_t param_1) {}
			virtual bool  RemoveOnChangeFunctor(uint64_t param_1) {}
			virtual  IEntityClass*  GetClass() {}
		private:
			virtual void  Garbage5() {}
		public:
			virtual void  ExecuteDry( CPipeUser* param_1) {}
		private:
			virtual void   Garbage6() {}
		public:
			virtual bool  DecreaseValue() {}
			virtual void*   _ECXConsoleVariableFloat(uint32_t param_1) {}
		private:
			virtual void  Garbage7() {}
		public:
			virtual int32_t  GetFlags() {}
		private:
			virtual __int64  Garbage8() {}
			virtual float  Garbage9() {}
		public:
			virtual char*  GetString() {}
		private:
			virtual char* Garbage10() {}
			virtual void  Garbage11() {}
			virtual void  Garbage12() {}
			virtual void  Garbage13() {}
			virtual void  Garbage14() {}
			virtual void  Garbage15() {}
			virtual int32_t  Garbage16() {}
			virtual int32_t  Garbage17() {}
		public:
			virtual  AKRESULT*  ActivateTrigger(bool param_2) {}
		private:
			virtual  HWND* Garbage18() {}
			virtual  ArkAudioLogComponent* Garbage138() {}
			virtual bool Garbage19() {}
			virtual void Garbage20() {}
			virtual bool Garbage21() {}
			virtual void Garbage22() {}
			virtual bool Garbage23() {}
			virtual void Garbage24() {}
			virtual bool Garbage25() {}
			virtual void Garbage26() {}
			virtual bool Garbage27() {}
			virtual void Garbage28() {}
			virtual bool Garbage29() {}
			virtual void Garbage30() {}
			virtual bool Garbage31() {}
			virtual void Garbage32() {}
			virtual bool Garbage33() {}
			virtual void Garbage34() {}
			virtual bool Garbage35() {}
			virtual void Garbage36() {}
			virtual bool Garbage37() {}
			virtual void Garbage38() {}
			virtual bool Garbage39() {}
			virtual void Garbage40() {}
			virtual bool Garbage41() {}
			virtual void Garbage42() {}
			virtual bool Garbage43() {}
			virtual void Garbage44() {}
			virtual bool Garbage45() {}
			virtual void Garbage46() {}
			virtual bool Garbage47() {}
			virtual void Garbage48() {}
			virtual bool Garbage49() {}
			virtual void Garbage50() {}
			virtual bool Garbage51() {}
			virtual void Garbage52() {}
			virtual bool Garbage53() {}
			virtual void Garbage54() {}
			virtual bool Garbage55() {}
			virtual void Garbage56() {}
			virtual bool Garbage57() {}
			virtual void Garbage58() {}
			virtual bool Garbage59() {}
			virtual void Garbage60() {}
			virtual bool Garbage61() {}
			virtual void Garbage62() {}
			virtual bool Garbage63() {}
			virtual void Garbage64() {}
			virtual bool Garbage65() {}
			virtual void Garbage66() {}
			virtual bool Garbage67() {}
			virtual void Garbage68() {}
			virtual bool Garbage69() {}
			virtual void Garbage70() {}
			virtual bool Garbage71() {}
			virtual void Garbage72() {}
			virtual bool Garbage73() {}
			virtual void Garbage74() {}
			virtual bool Garbage75() {}
			virtual void Garbage76() {}
			virtual bool Garbage77() {}
			virtual void Garbage78() {}
			virtual bool Garbage79() {}
			virtual void Garbage80() {}
			virtual bool Garbage81() {}
			virtual void Garbage82() {}
			virtual bool Garbage83() {}
			virtual void Garbage84() {}
			virtual bool Garbage85() {}
			virtual void Garbage86() {}
			virtual bool Garbage87() {}
			virtual void Garbage88() {}
			virtual bool Garbage89() {}
			virtual void Garbage90() {}
			virtual bool Garbage91() {}
			virtual void Garbage92() {}
			virtual bool Garbage93() {}
			virtual void Garbage94() {}
		public:
			virtual void  Set(__int64 param_1) {}
		private:
			virtual bool Garbage95() {}
			virtual void Garbage96() {}
			virtual bool Garbage97() {}
			virtual void Garbage98() {}
			virtual bool Garbage99() {}
			virtual void Garbage100() {}
			virtual bool Garbage101() {}
			virtual void Garbage102() {}
			virtual bool Garbage103() {}
			virtual void Garbage104() {}
			virtual bool Garbage105() {}
			virtual void Garbage106() {}
			virtual bool Garbage107() {}
			virtual void Garbage108() {}
			virtual bool Garbage109() {}
			virtual void Garbage110() {}
			virtual bool Garbage111() {}
			virtual void Garbage112() {}
			virtual bool Garbage113() {}
			virtual void Garbage114() {}
			virtual bool Garbage115() {}
			virtual void Garbage116() {}
			virtual bool Garbage117() {}
			virtual void Garbage118() {}
			virtual bool Garbage119() {}
			virtual void Garbage120() {}
			virtual bool Garbage121() {}
			virtual void Garbage122() {}
		public:
			virtual  EPriorityComparison*  ComparePriority( IAction* param_1) {}
		private:
			virtual void Garbage123(){}
			virtual void Garbage124(){}
			virtual void Garbage125(){}
			virtual void Garbage126(){}
			virtual void Garbage127(){}
			virtual void Garbage128(){}
			virtual void Garbage129(){}
			virtual void Garbage130(){}
			virtual void Garbage131(){}
			virtual void Garbage132(){}
			virtual void Garbage133(){}
			virtual void Garbage134(){}
		public:
			virtual char*  GetOwnDataProbeString() {}
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
			std::deque<CryStringT<char>, std::allocator<CryStringT<char>>> m_dqConsoleBuffer;
			std::deque<CryStringT<char>, std::allocator<CryStringT<char>>> m_dqHistory;
			bool m_bStaticBackground;
			undefined field27_0x69;
			undefined field28_0x6a;
			undefined field29_0x6b;
			int32_t m_nLoadingBackTexID;
			int32_t m_nWhiteTexID;
			int32_t m_nProgress;
			int32_t m_nProgressRange;
			undefined field34_0x7c;
			undefined field35_0x7d;
			undefined field36_0x7e;
			undefined field37_0x7f;
			CryStringT<char> m_sInputBuffer;
			CryStringT<char> m_sReturnString;
			CryStringT<char> m_sPrevTab;
			int32_t m_nTabCount;
			undefined field42_0x9c;
			undefined field43_0x9d;
			undefined field44_0x9e;
			undefined field45_0x9f;
			std::map<CryStringT<char>, CConsoleCommand> m_mapCommands;
			std::map<CryStringT<char>, CryStringT<char>> m_mapBinds;
			std::map<const char*, ICVar*> m_mapVariables;
			std::vector<std::pair<const char*, ICVar*>> m_randomCheckedVariables;
			std::vector<std::pair<const char*, ICVar*>> m_alwaysCheckedVariables;
			std::vector<IOutputPrintSink*> m_OutputSinks;
			std::list<SDeferredCommand> m_deferredCommands;
			bool m_deferredExecution;
			undefined field54_0x129;
			undefined field55_0x12a;
			undefined field56_0x12b;
			int32_t m_waitFrames;
			CTimeValue m_waitSeconds;
			int32_t m_blockCounter;
			undefined field60_0x13c;
			undefined field61_0x13d;
			undefined field62_0x13e;
			undefined field63_0x13f;
			std::map<CryStringT<char>, IConsoleArgumentAutoComplete*> m_mapArgumentAutoComplete;
			std::list<IConsoleVarSink*> m_consoleVarSinks;
			std::map<CryStringT<char>, SConfigVar> m_configVars;
			int32_t m_nScrollPos;
			int32_t m_nTempScrollMax;
			int32_t m_nScrollMax;
			int32_t m_nScrollLine;
			int32_t m_nHistoryPos;
			int32_t m_nCursorPos;
			ITexture* m_pImage;
			float m_fRepeatTimer;
			undefined field75_0x194;
			undefined field76_0x195;
			undefined field77_0x196;
			undefined field78_0x197;
			SInputEvent m_nRepeatEvent;
			float m_fCursorBlinkTimer;
			bool m_bDrawCursor;
			undefined field82_0x1d5;
			undefined field83_0x1d6;
			undefined field84_0x1d7;
			 ScrollDir m_sdScrollDir;
			bool m_bConsoleActive;
			bool m_bActivationKeyEnable;
			bool m_bIsProcessingGroup;
			undefined field89_0x1df;
			uint64_t m_nCheatHashRangeFirst;
			uint64_t m_nCheatHashRangeLast;
			bool m_bCheatHashDirty;
			undefined field93_0x1f1;
			undefined field94_0x1f2;
			undefined field95_0x1f3;
			undefined field96_0x1f4;
			undefined field97_0x1f5;
			undefined field98_0x1f6;
			undefined field99_0x1f7;
			uint64_t m_nCheatHash;
			CSystem* m_pSystem;
			IFFont* m_pFont;
			IRenderer* m_pRenderer;
			IInput* m_pInput;
			ITimer* m_pTimer;
			INetwork* m_pNetwork;
			ICVar* m_pSysDeactivateConsole;
			bool m_bConsoleIsEmerging;
			undefined field109_0x239;
			undefined field110_0x23a;
			undefined field111_0x23b;
			undefined field112_0x23c;
			undefined field113_0x23d;
			undefined field114_0x23e;
			undefined field115_0x23f;
		};
		class CXConsoleFloatRef {
		public:
			virtual void*   _ECXConsoleVariableFloat(uint32_t param_1) {}
			virtual void  Release() {}
			virtual int  GetIVal() {}
			virtual __int64  GetI64Val() {}
			virtual float  GetFVal() {}
			virtual char*  GetString() {}
			virtual char*  GetDataProbeString() {}
			virtual void  Set(int param_1) {}
			virtual void  Set(float param_1) {}
			virtual void  Set(char* param_1) {}
			virtual void  ForceSet(char* param_1) {}
			virtual void  ClearFlags(int param_1) {}
			virtual int  GetDepth() {}
			virtual int  SetFlags(int param_1) {}
			virtual  EPriorityComparison*  ComparePriority( IAction* param_1) {}
			virtual  HWND*   $GetValueFromMemberVariable() {}
			virtual  ArkAudioLogComponent*  GetAudioLogComponent() {}
			virtual bool  IsConstCVar() {}
			virtual void  Init( IAudioSystemImplementation* param_1) {}
			virtual void  AddOnChangeFunctor( SFunctor* param_1) {}
			virtual uint64_t  GetNumberOfOnChangeFunctors() {}
			virtual  SFunctor*  GetOnChangeFunctor(uint64_t param_1) {}
			virtual bool  RemoveOnChangeFunctor(uint64_t param_1) {}
			virtual  IEntityClass*  GetClass() {}
			virtual void  GetMemoryUsage( ICrySizer* param_1) {}
			virtual void  ExecuteDry( CPipeUser* param_1) {}
			virtual void   $FunctionCaller( EArkNpcFacingDesireCallbackEvent* param_2) {}
			virtual char*  GetOwnDataProbeString() {}
			char pad[64];
			float* m_fValue;
		};
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
		class IArkFactionListener{};
		class ArkFactionManager {
		public:
			virtual uint32_t  GetFactionIndex(uint64_t * param_1) {}
			virtual uint32_t  GetFactionIndex(char* param_1) {}
			virtual  CryStringT<char>*  GetFactionName(uint64_t param_1) {}
			virtual  CryStringT<char>*  GetFactionName(uint32_t param_1) {}
			virtual uint64_t  GetFactionId(uint32_t param_1) {}
			virtual uint64_t  GetFactionId(char* param_1) {}
			virtual uint32_t  GetEntityFaction(uint32_t param_1) {}
			virtual void  SetEntityDispositionToEntity(uint32_t _fromEntityId, uint32_t _toEntityId,  EArkDisposition* dispositiion, bool reciprocate) {}
			virtual void  SetFactionDispositionToEntity(uint32_t _fromFaction, uint32_t _toEntityId,  EArkDisposition* dispositiion, bool reciprocate) {}
			virtual void  SetFactionDispositionToFaction(uint32_t _fromFaction, uint32_t _toFaction,  EArkDisposition* param_3, bool param_4) {}
			virtual  EArkDisposition*  GetEffectiveFactionDispositionToEntity(uint32_t param_1, uint32_t param_2) {}
			virtual  EArkDisposition*  GetEffectiveEntityDispositionToEntity(uint32_t param_1, uint32_t param_2) {}
			virtual void  ReloadFactions() {}
			virtual uint64_t*   $GetConstReferenceFromMemberVariable() {}
			uint32_t m_numberOfFactions;
			char pad[4];
			std::unordered_map<uint32_t, uint32_t> m_entityFactionMap;
			std::vector<std::vector<uint32_t>> m_factionFollowers;
			std::vector<EArkDisposition> m_factionDispositions;
			std::unordered_map<std::pair<uint32_t, uint32_t>, EArkDisposition> m_factionToEntityDisposition;
			std::unordered_map<std::pair<uint32_t, uint32_t>, EArkDisposition> m_entityToFactionDisposition;
			std::unordered_map<std::pair<uint32_t, uint32_t>, EArkDisposition> m_entityToEntityDisposition;
			std::set<IArkFactionListener*> m_factionListeners;
			std::unordered_map<CryStringT<char>, uint32_t> m_nameToIndexMap;
			std::unordered_map<uint64_t, uint32_t> m_idToIndexMap;
			bool m_bDisableListeners;
			char pad2[7];
		};
		
		class ArkClass {
		public:
			std::unordered_map<CryStringT<char>, ArkProperty*> m_properties;
			ArkClass* m_baseClass;
			char* m_name;
			void* m_ObjectFactory;
		};
		class ArkReflectedLibrary {
			void* ptr;
		};
		class ArkGameDataManager {
		public:
			std::unordered_map<const ArkClass*, std::unique_ptr<ArkReflectedLibrary>> m_libraries;
		};
		class ArkGlintConfigManager{};
		class CArkGlooIslandNavLinkManager{};
		class ArkInstigationManager{};
		class ArkLightTimeManager{};
		class ArkListenerManager{};
		class ArkLurkManager{};
		class ArkMetaTagManager{};
		class ArkNightmareEtherformManager{};
		class NightmareInfo {
		public:
			uint32_t m_id;
			char pad[4];
			CryStringT<char> m_levelName;
		};
		class INightmareSpawnObserver {};
		class SShakeParams {
		public:
			Vec3_tpl<float> shakeAngle;
			Vec3_tpl<float> shakeShift;
			float sustainDuration,
				fadeInDuration,
				fadeOutDuration,
				speed,
				frequency,
				randomness;
			uint32_t shakeId;
			bool bFlipVec,
				bUpdateOnly,
				bGroundOnly,
				bPermanent,
				isSmooth;
			char pad[3];
		};
		class ArkNightmareSpawnManager {
		public:
			undefined field0_0x0;
			undefined field1_0x1;
			undefined field2_0x2;
			undefined field3_0x3;
			undefined field4_0x4;
			undefined field5_0x5;
			undefined field6_0x6;
			undefined field7_0x7;
			IEntityArchetype* m_pNightmareArchetype;
			NightmareInfo m_currentNightmare;
			std::vector<NightmareInfo> m_nightmaresToRemove;
			std::vector<CryStringT<char>, std::allocator<CryStringT<char>>> m_noSpawningInLevels;
			std::vector<uint32_t> m_currentLevelNightmareSpawners;
			std::unordered_set<INightmareSpawnObserver*, std::hash<INightmareSpawnObserver*>, std::equal_to<INightmareSpawnObserver*>, std::allocator<INightmareSpawnObserver*>> m_spawnObservers;
			SShakeParams m_cameraShakeParams;
			ArkAudioTrigger m_attentionAudioTrigger;
			ArkAudioTrigger m_nightmareAudioTrigger;
			ArkAudioTrigger m_cameraShakeAudioTrigger;
			ArkSimpleTimer m_spawnDelayTimer;
			ArkSimpleTimer m_postSpawnFxDelayTimer;
			float m_offscreenTimeRequiredToSpawn;
			float m_passiveSpawnTimer;
			float m_passiveInitialCooldownOnEnableInSeconds;
			float m_passiveCooldownOnCombatInSeconds;
			float m_passiveCooldownOnPassiveSpawnInSeconds;
			float m_respawnCooldownTimer;
			float m_respawnCooldownOnSpawnInSeconds;
			float m_respawnCooldownOnDeathInSeconds;
			float m_nightmareHeatSpawnThreshold;
			float m_currentNightmareHeat;
			float m_nightmareHeatLeakPerASecond;
			bool m_bEnabled;
			bool m_bTriedToSpawnNightmareOnCD;
			bool m_bShouldSpawnNightmare;
			bool m_bShouldPlayPostSpawnFx;
			bool m_bSpawningActively;
			bool m_bNeedsAttentionUpdate;
			bool m_bDelayedRemove;
			undefined field38_0x133;
			undefined field39_0x134;
			undefined field40_0x135;
			undefined field41_0x136;
			undefined field42_0x137;
		};
		class SExtensionInfo{};
		class CProtocolDef {
		public:
			void* ptr;
		};
		class CGameObjectDispatch {
		public:
			bool m_bSafety;
			char pad[7];
			std::vector<SGameObjectExtensionRMI*> m_messages;
			std::vector <SNetMessageDef> m_serverCalls;
			std::vector<SNetMessageDef> m_clientCalls;
			CProtocolDef m_serverDef,
				m_clientDef;
		};
		class SSpawnSerializer{};
		class IDebugHistory{};
		class SEntityClassDesc{};

		struct SEntitySchedulingProfiles
		{
			unsigned int normal;
			unsigned int owned;
		};

		class CGameObjectSystem {
		public:
			virtual void*   _ECGameObjectSystem(uint32_t param_1) {}
			virtual unsigned short  GetID(char* param_1) {}
			virtual char*  GetName(unsigned short param_1) {}
			virtual uint32_t  GetExtensionSerializationPriority(unsigned short param_1) {}
			virtual  std::shared_ptr<IGameObjectExtension>*  Instantiate(unsigned short param_1,  IGameObject* param_2) {}
			virtual void  BroadcastEvent( SGameObjectEvent* param_1) {}
			virtual void  RegisterEvent(uint32_t param_1, char* param_2) {}
			virtual uint32_t  GetEventID(char* param_1) {}
			virtual char*  GetEventName(uint32_t param_1) {}
			virtual  IGameObject*  CreateGameObjectForEntity(uint32_t param_1) {}
			virtual  std::shared_ptr<IEntityProxy>*  CreateGameObjectEntityProxy( IEntity* param_1,  IGameObject** param_2) {}
			virtual void  RegisterExtension(char* param_1,  IGameObjectExtensionCreatorBase* param_2,  SEntityClassDesc* param_3) {}
			virtual void  DefineProtocol(bool param_1,  IProtocolBuilder* param_2) {}
			virtual void  PostUpdate(float param_1) {}
			virtual void  SetPostUpdate( IGameObject* param_1, bool param_2) {}
			virtual void  Reset() {}
			virtual void  SetSpawnSerializerForEntity(uint32_t param_1,  CSerializeWrapper<ISerialize>*param_2) {}
			virtual void  ClearSpawnSerializerForEntity(uint32_t param_1) {}
			virtual void  AddSink( IGameObjectSystemSink* param_1) {}
			virtual void  RemoveSink( IGameObjectSystemSink* param_1) {}
			virtual void*   _ECNetworkStallTickerThread(uint32_t param_1) {}
			virtual void  Run() {}
			virtual void   $FunctionCaller( EArkNpcFacingDesireCallbackEvent* param_2) {}
			virtual void garbage0() {}
			virtual void garbage1() {}
			virtual void*   _ECDebugHistoryManager(uint32_t param_1) {}
			virtual  IDebugHistory*  CreateHistory(char* param_1, char* param_2) {}
			virtual void  RemoveHistory(char* param_1) {}
			virtual  IDebugHistory*  GetHistory(char* param_1) {}
			virtual void  Clear() {}
			virtual void  GetMemoryUsage( ICrySizer* param_1) {}
			virtual void  Complete() {}
			virtual void  LayoutHelper(char* param_1, char* param_2, bool param_3, float param_4, float param_5, float param_6, float param_7, float param_8, float param_9, float param_10, float param_11) {}
			std::map<CryStringT<char>, unsigned short> m_nameToID;
			std::vector<SExtensionInfo> m_extensionInfo;
			CGameObjectDispatch m_dispatch;
			IEntityClass* m_pClassPlayerProximityTrigger;
			std::vector<SSpawnSerializer> m_spawnSerializers;
			std::map<CryStringT<char>, SEntitySchedulingProfiles> m_schedulingParams;
			SEntitySchedulingProfiles m_defaultProfiles;
			std::map<CryStringT<char>, uint32_t> m_eventNameToID;
			std::map<uint32_t, CryStringT<char>> m_eventIDToName;
			std::list<IGameObjectSystemSink*> m_lstSinks;
			std::vector<IGameObject*> m_tempObjects;
			std::vector<unsigned short> m_activatedExtension_top;
			std::vector<CryStringT<char>> m_serializationOrderList;
		};
		
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
		class ArkCameraShakeManager{};
		class ArkDialogSubtitleManager{};
		class ArkDifficultyComponent{};
		class ArkEventScheduler{};
		class ArkGameStateConditionManager{};
		class ArkHackingUI{};
		class ArkIndicatorIconManager{};
		class ArkLevelMapComponent{};
		class ArkLightManager{};
		class ArkLocationManager{};
		class ArkNoiseAttentionParams{};
		class ArkObjectiveComponent{};
		class Manager{};
		class ArkTipComponent{};
		class ArkApexVolumeManager{};
		class ArkGameModeManager{};
		class ArkNewGamePlus {};
		class ISaveGameEnumerator{};
		class IArkGameLoadSaveListener{};
		class LocationInfo {
			CryStringT<char> label,
				screenshotPath;
		};
		class ScreenBlackFadeInfo {
		public:
			float m_blackDuration,
				m_fadeOutDuration;
		};
		enum class PauseRequestStatus {
			none = 0,
			pause = 1,
			pausedByRequest = 2,
			unpause = 3
		};
		class ArkGame {
		public:
			void* vftable;
			char pad[8];
			ScreenBlackFadeInfo m_levelLoadFade;
			ScreenBlackFadeInfo m_quickLoadFade;
			std::vector<CryStringT<char>, std::allocator<CryStringT<char>>> m_captureVolumeWhiteList;
			std::array<ISaveGameEnumerator*, 3> m_saveGameEnumerators;
			std::array<std::vector<CryStringT<char>, std::allocator<CryStringT<char>>>, 3> m_saveGameToUpdate;
			std::array<uint64_t, 3> m_campaignGuids;
			ArkSimpleTimer m_autoSaveDelay;
			ArkSimpleTimer m_blockAutoSaveWindow;
			ArkSimpleTimer m_screenBlackTimer;
			ArkSimpleTimer m_screenFadeOutTimer;
			CryStringT<char> m_saveFileToLoad;
			CryStringT<char> m_loadLocationOverride;
			IArkGameLoadSaveListener* m_pLoadListener;
			uint64_t m_campaignPlayTime;
			float m_campaignTimerAccumulator;
			undefined field31_0xf4;
			undefined field32_0xf5;
			undefined field33_0xf6;
			undefined field34_0xf7;
			uint64_t m_currentLocationId;
			 XmlNodeRef m_levelProperties;
			std::unique_ptr<CScriptBind_ArkPlayer, std::default_delete<CScriptBind_ArkPlayer>> m_pScriptBindArkPlayer;
			std::unique_ptr<ArkCameraShakeManager, std::default_delete<ArkCameraShakeManager>> m_pArkCameraShakeManager;
			std::unique_ptr<ArkDialogSubtitleManager, std::default_delete<ArkDialogSubtitleManager>> m_pArkDialogSubtitleManager;
			std::unique_ptr<ArkDifficultyComponent, std::default_delete<ArkDifficultyComponent>> m_pArkDifficultyComponent;
			std::unique_ptr<ArkEventScheduler, std::default_delete<ArkEventScheduler>> m_pArkEventScheduler;
			std::unique_ptr<ArkGameStateConditionManager, std::default_delete<ArkGameStateConditionManager>> m_pArkGameStateConditionManager;
			std::unique_ptr<ArkHackingUI, std::default_delete<ArkHackingUI>> m_pArkHackingUI;
			std::unique_ptr<ArkIndicatorIconManager, std::default_delete<ArkIndicatorIconManager>> m_pArkIndicatorIconManager;
			std::unique_ptr<ArkItemSystem, std::default_delete<ArkItemSystem>> m_pArkItemSystem;
			std::unique_ptr<ArkLevelMapComponent, std::default_delete<ArkLevelMapComponent>> m_pArkLevelMapComponent;
			std::unique_ptr<ArkLightManager, std::default_delete<ArkLightManager>> m_pArkLightManager;
			std::unique_ptr<ArkLocationManager, std::default_delete<ArkLocationManager>> m_pArkLocationManager;
			std::unique_ptr<ArkNoiseAttentionParams, std::default_delete<ArkNoiseAttentionParams>> m_pArkNoiseAttentionParams;
			std::unique_ptr<ArkObjectiveComponent, std::default_delete<ArkObjectiveComponent>> m_pArkObjectiveComponent;
			std::unique_ptr<Manager, std::default_delete<Manager>> m_pArkSignalManager;
			std::unique_ptr<ArkTipComponent, std::default_delete<ArkTipComponent>> m_pArkTipComponent;
			std::unique_ptr<ArkTutorialSystem, std::default_delete<ArkTutorialSystem>> m_pArkTutorialSystem;
			std::unique_ptr<ArkApexVolumeManager, std::default_delete<ArkApexVolumeManager>> m_pApexVolumeManager;
			std::unique_ptr<ArkGameModeManager, std::default_delete<ArkGameModeManager>> m_pArkGameModeManager;
			std::unique_ptr<ArkNewGamePlus, std::default_delete<ArkNewGamePlus>> m_pNewGamePlus;
			AABB m_playerSafeBounds;
			EArkLoadDisconnectReason m_loadDisconnectReason;
			PauseRequestStatus m_pauseRequestStatus;
			float m_playerWarningBuffer;
			float m_timeSinceLastAutoSave;
			bool m_bLevelToLevelTransition;
			bool m_bSaveHasJustBeenDeletedBySystem;
			bool m_bPreTextureStreamerRunning;
			bool m_bNeedsToAutosaveOnMapLoad;
			bool m_bPerformingIronmanSave;
			undefined field67_0x1d5;
			undefined field68_0x1d6;
			undefined field69_0x1d7;
			static inline auto GetArkGame = PreyFunction<ArkGame*()>(0x116d820);
		};
		class ArkActiveUserManagerBase{};
		class CLevelSystem{};
		class CItemSystem{};
		class CSharedParamsManager{};
		class CActionMapAction : IActionMapAction
		{
		public:


			CryFixedStringT<32> m_triggeredInput;
			CCryName m_actionId;
			std::vector<SActionInput*> m_actionInputs;
			CActionMap* m_pParentActionMap;
			int m_iNumRebindedInputs;
		};
		template <typename T> class CListenerSet// Size=0x28 (Id=16460)
		{
		public:
			struct ListenerRecord// Size=0x8 (Id=1707282)
			{
				T m_pListener;// Offset=0x0 Size=0x8
			};
			std::vector<CListenerSet<T>::ListenerRecord> m_listeners;// Offset=0x0 Size=0x18
			unsigned __int64 m_activeNotifications;// Offset=0x18 Size=0x8
			bool m_cleanupRequired;// Offset=0x20 Size=0x1
			bool m_freeMemOnCleanup;// Offset=0x21 Size=0x1
		};
		class CActionMap : IActionMap
		{
		public:
			bool m_enabled;
			CActionMapManager* m_pActionMapManager;
			std::map<CCryName, CActionMapAction> m_actions;
			unsigned int m_listenerId;
			CListenerSet<IActionListener*> m_actionMapListeners;
			CryStringT<char> m_name;
			int m_iNumRebindedInputs;
		};
		class CActionFilter : IActionFilter
		{
		public:


			bool m_enabled;
			CActionMapManager* m_pActionMapManager;
			IInput* m_pInput;
			std::set<CCryName> m_filterActions;
			EActionFilterType m_type;
			CryStringT<char> m_name;
		};
		class IActionFilterStack
		{
		public:
			virtual void PushFrame() = 0;
			virtual void PopFrame() = 0;


		};
		class ArkActionFilterStack 
		{
		public:
			void* vtable;
			std::vector<std::vector<IActionFilter*>> m_FilterStack;
		};
		static_assert(sizeof(ArkActionFilterStack) == 0x20);
		class CActionMapManager : IActionMapManager, IInputEventListener
		{
		public:
			struct SBindData// Size=0x18 (Id=1027099)
			{
				struct SActionInput* m_pActionInput;// Offset=0x0 Size=0x8
				class CActionMapAction* m_pAction;// Offset=0x8 Size=0x8
				class CActionMap* m_pActionMap;// Offset=0x10 Size=0x8
			};
			struct SRefireBindData// Size=0x20 (Id=1027104)
			{
				struct CActionMapManager::SBindData m_bindData;// Offset=0x0 Size=0x18
				bool m_bIgnoreNextUpdate;// Offset=0x18 Size=0x1
				bool m_bDelayedPressNeedsRelease;// Offset=0x19 Size=0x1
			};
			struct SRefireData// Size=0x58 (Id=1027110)
			{
				unsigned int m_inputCRC;// Offset=0x0 Size=0x4
				struct SInputEvent m_inputEvent;// Offset=0x8 Size=0x38
				class std::vector<CActionMapManager::SRefireBindData, std::allocator<CActionMapManager::SRefireBindData> > m_refireBindData;// Offset=0x40 Size=0x18
			};
			struct SRefireReleaseListData// Size=0x48 (Id=1027135)
			{
				struct SInputEvent m_inputEvent;// Offset=0x0 Size=0x38
				class std::list<CActionMapManager::SBindData const*, std::allocator<CActionMapManager::SBindData const*> > m_inputsList;// Offset=0x38 Size=0x10
			};

			std::vector<IActionListener*> m_ExtraActionListeners;
			CryStringT<char> m_loadedXMLPath;
			IInput* m_pInput;
			std::map<CryStringT<char>, CActionMap*, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, CActionMap*> > > m_actionMaps;
			std::map<CryStringT<char>, CActionFilter*, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, CActionFilter*> > > m_actionFilters;
			std::multimap<unsigned int, CActionMapManager::SBindData> m_inputCRCToBind;
			std::map<unsigned int, CActionMapManager::SRefireData*> m_inputCRCToRefireData;
			std::list<std::shared_ptr<IBlockingActionListener>> m_alwaysActionListeners;
			std::map<CryStringT<char>, XmlNodeRef, std::less<CryStringT<char> >, std::allocator<std::pair<CryStringT<char> const, XmlNodeRef> > > m_preloadedControllerLayouts;
			std::vector<SActionInputDeviceData> m_inputDeviceData;
			EKeyId m_currentInputKeyID;
			ArkActionFilterStack m_actionFilterStack;
			int m_version;
			bool m_enabled;
			bool m_bRefiringInputs;
			bool m_bDelayedRemoveAllRefiringData;
			bool m_bIncomingInputRepeated;
			bool m_bRepeatedInputHoldTriggerFired;
			std::list<IActionMapEventListener*> m_actionMapEventListeners;
			unsigned int m_defaultEntityId;
		};
		static_assert(sizeof(CActionMapManager) == 0x100);
		class CViewSystem{};
		class CGameplayRecorder{};
		class CGameRulesSystem{};
		class CFlowSystem{};
		
		class CUIDraw{};
		class CScriptRMI{};
		class CAnimationGraphCVars{};
		class IMannequin{};
		class CMaterialEffects{};
		class CPlayerProfileManager{};
		class CDialogSystem{};
		class CSubtitleManager{};
		class IGameTokenSystem{};
		class IEffectSystem{};
		class CGameSerialize{};
		class CallbackTimer{};
		class CGameplayAnalyst{};
		class CVisualLog{};
		class CForceFeedBackSystem{};
		class ILanQueryListener{};
		class CCustomActionManager{};
		class CCustomEventManager{};
		class CGameStatsConfig{};
		class IGameStatistics{};
		class ICooperativeAnimationManager{};
		class IGameSessionHandler{};
		class CAIProxyManager{};
		class IGameVolumes{};
		class CDevMode{};
		class CTimeDemoRecorder{};
		class CGameQueryListener{};
		class CRuntimeAreaManager{};
		class CScriptBind_Action{};
		class CScriptBind_ActorSystem{};
		class CScriptBind_Network{};
		class CScriptBind_ActionMapManager{};
		class CScriptBind_DialogSystem{};
		class CScriptBind_MaterialEffects{};
		class CScriptBind_UIAction{};
		class CTimeOfDayScheduler{};
		class CPersistantDebug{};
		class CAIDebugRenderer{};
		class CAINetworkDebugRenderer{};
		class CNetworkCVars{};
		class CCryActionCVars{};
		class CNetworkStallTickerThread{};
		class CActionGame{};
		class CMaterialEffectsCVars{};
		class CCryActionPhysicQueues{};
		class SLocalAllocs{};
		struct IBreakEventListener{};
		class CNetMessageDistpatcher{};
		class ICryUnknown{};
		class SGameFrameworkListener{};

		class ArkSaveLoadSystem {
		public:
			char pad[320];
		};
		class ArkGameNoises {
		public:
			char pad[48];
		};
		
		class SAudioRequest {
			char pad[40];
		};
		template<int i> class SAudioManagerRequestData {
		public:
			char pad[24];
		};
		class CActorIterator {};
		class IActorCreator{};
		struct IEntityScript{};
		class SScriptFuncHandle{};
		class SScriptStateFunctions{};
		enum class EventValueType : uint32_t {
			EVT_INT = 0,
			EVT_FLOAT = 1,
			EVT_BOOL = 2,
			EVT_VECTOR = 3,
			EVT_ENTITY = 4,
			EVT_STRING = 5
		};
		class SEntityScriptEvent {
		public:
			CryStringT<char> name;
			SScriptFuncHandle* func;
			EventValueType valueType;
			unsigned char bflags;

		};
		class SScriptState {
		public:
			CryStringT<char> name;
			SScriptStateFunctions* pStateFuns[2];
		};
		class CEntityScript {
		public:
			void* vtable;
			IScriptSystem* m_pScriptSystem;
			SmartScriptTable m_pEntityTable;
			SmartScriptTable m_pPropertiesTable;
			CryStringT<char> m_sTableName;
			CryStringT<char> m_sScriptFilename;
			SScriptFuncHandle* m_pOnSpawnfunc;
			SScriptFuncHandle* m_pOnDestroyFunc;
			SScriptFuncHandle* m_pOnInitFunc[2];
			SScriptFuncHandle* m_pOnShutdown[2];
			SScriptFuncHandle* m_pOnReset;
			SScriptFuncHandle* m_pOnTransformFromEditorDone;
			SScriptState m_defaultState;
			std::vector<SScriptState> m_states;
			std::vector<SEntityScriptEvent> m_events;
			bool m_bScriptLoaded;
			bool m_bDefaultOnly;
			char pad[6];
		};
		class CEntityClass {
		public:
			virtual void*   _ECEntityClass(uint32_t param_1) {}
			virtual void  Complete() {}
			virtual class ArkAudioLogComponent*  GetAudioLogComponent() {}
			virtual uint32_t  GetAudioObjectID() {}
			virtual void  SetFlags(int32_t param_1) {}
			virtual class ArkNpcAbilityInstance*  GetAbilityInstance() {}
			virtual class SSurfaceTypeAIParams*  GetAIParams() {}
			virtual IScriptTable*  GetScriptTable() {}
			virtual IBSPTree3D*  GetBspTree() {}
			virtual int64_t  GetCurrentContextIndex() {}
			virtual char*  GetCharacter() {}
			virtual float*   $GetConstReferenceFromMemberVariable() {}
			virtual void  SetEditorClassInfo(SEditorClassInfo* param_1) {}
			virtual bool  LoadScript(bool param_1) {}
			virtual class ArkNpcAbility*  GetAbility() {}
			virtual IEntityArchetype*  GetArchetype() {}
			virtual int32_t  GetEventCount() {}
			virtual class SEventInfo*  GetEventInfo(class SEventInfo* __return_storage_ptr__, int32_t param_1) {}
			virtual bool  FindEventInfo(char* param_1, class SEventInfo* param_2) {}
			virtual int64_t*   garbage0() {}
			virtual int64_t*   garbage1() {}
			virtual int64_t*   garbage2() {}
			virtual int64_t*   garbage3() {}
			virtual void  GetMemoryUsage(class ICrySizer* param_1) {}
			uint32_t m_nFlags;
			char pad2[4];
			CryStringT<char> m_sName,
				m_SScriptFile;
			IEntityScript* m_pEntityScript;
			void* m_pfnUserProxyCreate;
			void* m_pUserProxyUserData;
			bool m_bScriptLoaded;
			char pad3[7];
			IEntityPropertyHandler* m_pPropertyHandler;
			IEntityEventHandler* m_pEventHandler;
			IEntityScriptFileHandler* m_pScriptFileHandler;
			SEditorClassInfo m_EditorClassInfo;
			void* m_entityAttributes;
			void* m_classAttributes;
		};
		class SActorClassDesc {
		public:
			CEntityClass* pEntityClass;
			IActorCreator* pCreator;
		};
		class CItemsParamNode {
		public:
			char pad[8];
			CCryName m_name;
			CryStringT<char> m_nameAttribute;
			char pad2[8];
			char pad3[8];
			uint32_t m_refs;
			char pad4[4];
		};
		class SActorParamsDesc {
		public:
			CItemsParamNode* params;
		};
		class DemoSpectatorSystem {
		public:
			uint32_t m_originalActor,
				m_currentActor;
		};
		class CActorSystem {
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
			DemoSpectatorSystem m_demoSpectatorSystem;
			uint32_t m_demoPlaybackMappedOriginalServerPlayer;
			undefined field26_0x24;
			undefined field27_0x25;
			undefined field28_0x26;
			undefined field29_0x27;
			ISystem* m_pSystem;
			IEntitySystem* m_pEntitySystem;
			std::map<uint32_t, CActor*> m_actors;
			std::map<CryStringT<char>, SActorClassDesc> m_classes;
			std::vector<CActorIterator*> m_iteratorPool;
			std::map<CryStringT<char>, SActorParamsDesc> m_actorParams;
			CryStringT<char> m_actorParamsFolder;
		};
		class IGameObjectExtensionCreator{};
		class  IItemCreator {};
		class FuncDef60{};
		class FuncDef61{};
		enum class EUIDRAWVERTICAL{};
		enum class EUIDRAWHORIZONTAL{};
		class IUIDraw {
			virtual void*  _ECCheckpointSystem(uint32_t param_1) {}
			virtual void  Complete() {}
			virtual void  PreRender() {}
			virtual void  PostRender() {}
			virtual void  DrawLine(float param_1, float param_2, float param_3, float param_4, uint32_t param_5) {}
			virtual void  DrawTextSimple( IFFont* param_1, float param_2, float param_3, float param_4, float param_5, char* param_6,  Color_tpl<float>*param_7,  EUIDRAWHORIZONTAL* param_8,  EUIDRAWVERTICAL* param_9) {}
			virtual void  DrawTextW( IFFont* param_1, float param_2, float param_3, float param_4, float param_5, char* param_6, float param_7, float param_8, float param_9, float param_10,  EUIDRAWHORIZONTAL* param_11,  EUIDRAWVERTICAL* param_12,  EUIDRAWHORIZONTAL* param_13,  EUIDRAWVERTICAL* param_14) {}
			virtual void  GetTextDim( IFFont* param_1, float* param_2, float* param_3, float param_4, float param_5, char* param_6) {}
			virtual int  DrawTextW( LPCWSTR* lpchText, int cchText,  LPRECT* lprc,  UINT* format) {}
			virtual void  GetTextDimW( IFFont* param_1, float* param_2, float* param_3, float param_4, float param_5, wchar_t* param_6) {}
		};
		enum class  ELoadGameResult{};
		enum class EFRAMEWORKLISTENERPRIORITY{};
		class ILevelSystem {};
		class IActorSystem {};
		class IItemSystem {};
		// class IActionMapManager {
		// public:
		// 	virtual void* _ECActionMapManager(uint32_t param_1) {}
		// 	virtual void  Update() {}
		// 	virtual void  Reset() {}
		// 	virtual void  ResetBindings() {}
		// 	virtual void  Clear() {}
		// 	virtual bool  InitActionMaps(char* param_1) {}
		// 	virtual void  SetLoadFromXMLPath(char* param_1) {}
		// 	virtual  ArkNpcAbility* GetAbility() {}
		// 	virtual bool  LoadFromXML(XmlNodeRef* param_1) {}
		// 	virtual bool  LoadRebindDataFromXML(XmlNodeRef* param_1) {}
		// 	virtual bool  SaveRebindDataToXML(XmlNodeRef* param_1) {}
		// 	virtual bool  AddExtraActionListener(IActionListener* param_1, char* param_2) {}
		// 	virtual bool  RemoveExtraActionListener(IActionListener* param_1, char* param_2) {}
		// 	virtual float* $GetConstReferenceFromMemberVariable() {}
		// 	virtual void  AddAlwaysActionListener(std::shared_ptr<IBlockingActionListener>* param_1) {}
		// 	virtual void  RemoveAlwaysActionListener(std::shared_ptr<IBlockingActionListener>* param_1) {}
		// 	virtual void  RemoveAllAlwaysActionListeners() {}
		// 	virtual  IActionMap* CreateActionMap(char* param_1) {}
		// 	virtual bool  RemoveActionMap(char* param_1) {}
		// 	virtual void  RemoveAllActionMaps() {}
		// 	virtual  IActionMap* GetActionMap(char* param_1) {}
		// 	virtual  IActionFilter* CreateActionFilter(char* param_1, EActionFilterType* param_2) {}
		// 	virtual  IActionFilter* GetActionFilter(char* param_1) {}
		// 	virtual  IActionMapIterator* CreateActionMapIterator() {}
		// 	virtual  IActionFilterIterator* CreateActionFilterIterator() {}
		// 	virtual  SActionInput* GetActionInput(char* param_1, CCryName* param_2, EActionInputDevice* param_3, int param_4) {}
		// 	virtual void  Enable(bool enable, bool resetStateOnDisable = false) {}
		// 	virtual void  EnableActionMap(char* param_1, bool param_2) {}
		// 	virtual void  EnableFilter(char* param_1, bool param_2) {}
		// 	virtual bool  IsFilterEnabled(char* param_1) {}
		// 	virtual void  ReleaseFilteredActions() {}
		// 	virtual void  ClearStoredCurrentInputData() {}
		// 	virtual bool  ReBindActionInput(char* param_1, CCryName* param_2, EActionInputDevice* param_3, int param_4, char* param_5) {}
		// 	virtual bool  ReBindActionInput(char* param_1, CCryName* param_2, char* param_3, char* param_4) {}
		// 	virtual int  GetLockIdx() {}
		// 	virtual void  SetVersion(int param_1) {}
		// 	virtual void  EnumerateActions(IActionMapPopulateCallBack* param_1) {}
		// 	virtual int  GetActionsCount() {}
		// 	virtual int  GetActionMapsCount() {}
		// 	virtual bool  AddInputDeviceMapping(EActionInputDevice* param_1, char* param_2) {}
		// 	virtual bool  RemoveInputDeviceMapping(EActionInputDevice* param_1) {}
		// 	virtual void  ClearInputDevicesMappings() {}
		// 	virtual int  GetNumInputDeviceData() {}
		// 	virtual  SActionInputDeviceData* GetInputDeviceDataByIndex(int param_1) {}
		// 	virtual  SActionInputDeviceData* GetInputDeviceDataByType(char* param_1) {}
		// 	virtual  SActionInputDeviceData* GetInputDeviceDataByType(EActionInputDevice* param_1) {}
		// 	virtual void  RemoveAllRefireData() {}
		// 	virtual bool  LoadControllerLayoutFile(char* param_1) {}
		// 	virtual uint32_t  GetDefaultActionEntity() {}
		// 	virtual void  SetDefaultActionEntity(uint32_t param_1, bool param_2) {}
		// 	virtual void  RegisterActionMapEventListener(IActionMapEventListener* param_1) {}
		// 	virtual void  UnregisterActionMapEventListener(IActionMapEventListener* param_1) {}
		// 	virtual void   garbage() {}
		// 	virtual bool  ActionFiltered(CCryName* param_1) {}
		// 	virtual  void  garbage0() {}
		// 	virtual void  RemoveAllFilters() {}
		// };
		
		class IGameRulesSystem {};
		class ISubtitleManager {};
		class ITweakMenuController {};
		class ICheckpointSystem {};
		class IForceFeedbackSystem {};
		class ICustomActionManager {};
		class ICustomEventManager {};
		class ISharedParamsManager {};
		class SGameStartParams {};
		class SGameContextParams {};
		class ArkGameNoiseLoudness {};
		class ISerializeHelper {};
		class SEntityTagParams{};
		class IPersistantDebug {
			virtual void*   _ECPersistantDebug(uint32_t param_1) {}
			virtual void  Begin(char* param_1, bool param_2) {}
			virtual void  AddSphere( Vec3_tpl<float>*param_1, float param_2,  Color_tpl<float>*param_3, float param_4) {}
			virtual void  AddDirection( Vec3_tpl<float>*param_1, float param_2,  Vec3_tpl<float>*param_3,  Color_tpl<float>*param_4, float param_5) {}
			virtual void  AddLine( Vec3_tpl<float>*param_1,  Vec3_tpl<float>*param_2,  Color_tpl<float>*param_3, float param_4) {}
			virtual void  AddPlanarDisc( Vec3_tpl<float>*param_1, float param_2, float param_3,  Color_tpl<float>*param_4, float param_5) {}
			virtual void  AddCone( Vec3_tpl<float>*param_1,  Vec3_tpl<float>*param_2, float param_3, float param_4,  Color_tpl<float>*param_5, float param_6) {}
			virtual void  AddCylinder( Vec3_tpl<float>*param_1,  Vec3_tpl<float>*param_2, float param_3, float param_4,  Color_tpl<float>*param_5, float param_6) {}
			virtual void  Add2DText(char* param_1, float param_2,  Color_tpl<float>*param_3, float param_4) {}
			virtual void  AddText(float param_1, float param_2, float param_3,  Color_tpl<float>*param_4, float param_5, char* param_6) {}
			virtual void  Add2DLine(float param_1, float param_2, float param_3, float param_4,  Color_tpl<float>*param_5, float param_6) {}
			virtual void  AddQuat( Vec3_tpl<float>*param_1,  Quat_tpl<float>*param_2, float param_3,  Color_tpl<float>*param_4, float param_5) {}
			virtual void  AddAABB( Vec3_tpl<float>*param_1,  Vec3_tpl<float>*param_2,  Color_tpl<float>*param_3, float param_4) {}
			virtual void  AddEntityTag( SEntityTagParams* param_1, char* param_2) {}
			virtual void  ClearEntityTags(uint32_t param_1) {}
			virtual void  ClearStaticTag(uint32_t param_1, char* param_2) {}
			virtual void  ClearTagContext(char* param_1, uint32_t param_2) {}
			virtual void  ClearTagContext(char* param_1) {}
			virtual void  Reset() {}
		};
		class INetNub {};
		class INetContext {};
		class IDebugHistoryManager {};
		class CryGUID {};
		class CGameServerNub {};
		class IAIActorProxy {};
		class Params{};
		class CCryAction {
		public:
			virtual void  RegisterFactory(char* param_1,  IGameObjectExtensionCreator* param_2, bool param_3) {}
			virtual void  RegisterFactory(char* param_1,  IItemCreator* param_2, bool param_3) {}
			virtual void  RegisterFactory(char* param_1,  IActorCreator* param_2, bool param_3) {}
			virtual void  RegisterFactory(char* param_1,  FuncDef60* param_2, bool param_3) {}
			virtual void  RegisterFactory(char* param_1,  FuncDef61* param_2, bool param_3) {}
			virtual void*   _ECCryAction(uint32_t param_1) {}
			virtual bool  Init( SSystemInitParams* param_1) {}
			virtual void  InitGameType(bool param_1, bool param_2) {}
			virtual bool  CompleteInit() {}
			virtual void  Shutdown() {}
			virtual bool  PreUpdate(bool param_1, uint32_t param_2) {}
			virtual void  PostUpdate(bool param_1, uint32_t param_2) {}
			virtual void  Reset(bool param_1) {}
			virtual void  PauseGame(bool param_1, bool param_2, uint32_t param_3, bool param_4) {}
			virtual bool  IsGamePaused() {}
			virtual bool  IsGameStarted() {}
			virtual bool  IsLevelPrecachingDone() {}
			virtual void  SetLevelPrecachingDone(bool param_1) {}
			virtual  ArkAudioLogComponent*  GetAudioLogComponent() {}
			virtual  ILanQueryListener*  GetILanQueryListener() {}
			virtual  IUIDraw*  GetIUIDraw() {}
			virtual  IMannequin*  GetMannequinInterface() {}
			virtual  IGameObjectSystem*  GetIGameObjectSystem() {}
			virtual  ILevelSystem*  GetILevelSystem() {}
			virtual  IActorSystem*  GetIActorSystem() {}
			virtual  IItemSystem*  GetIItemSystem() {}
			virtual  IActionMapManager*  GetIActionMapManager() {}
			virtual  IViewSystem*  GetIViewSystem() {}
			virtual  IStatObj*  GetGeometry() {}
			virtual  IGameRulesSystem*  GetIGameRulesSystem() {}
			virtual  IFlowSystem*  GetIFlowSystem() {}
			virtual  IGameTokenSystem*  GetIGameTokenSystem() {}
			virtual  IEffectSystem*  GetIEffectSystem() {}
			virtual  IMaterialEffects*  GetIMaterialEffects() {}
			virtual  IDialogSystem*  GetIDialogSystem() {}
			virtual  IPlayerProfileManager*  GetIPlayerProfileManager() {}
			virtual  ISubtitleManager*  GetISubtitleManager() {}
			virtual  ITweakMenuController*  CreateITweakMenuController() {}
			virtual  IGameStatistics*  GetIGameStatistics() {}
			virtual  IVisualLog*  GetIVisualLog() {}
			virtual  ICooperativeAnimationManager*  GetICooperativeAnimationManager() {}
			virtual  ICheckpointSystem*  GetICheckpointSystem() {}
			virtual  IForceFeedbackSystem*  GetIForceFeedbackSystem() {}
			virtual  ICustomActionManager*  GetICustomActionManager() {}
			virtual  ICustomEventManager*  GetICustomEventManager() {}
			virtual  IGameSessionHandler*  GetIGameSessionHandler() {}
			virtual  ISharedParamsManager*  GetISharedParamsManager() {}
			virtual bool  StartGameContext( SGameStartParams* param_1) {}
			virtual bool  ChangeGameContext( SGameContextParams* param_1) {}
			virtual void  EndGameContext() {}
			virtual bool  StartedGameContext() {}
			virtual bool  StartingGameContext() {}
			virtual void  SetGameSessionHandler( IGameSessionHandler* param_1) {}
			virtual bool  BlockingSpawnPlayer() {}
			virtual void  FlushBreakableObjects() {}
			virtual void  ResetBrokenGameObjects() {}
			virtual  IEntityProxy*  CreateGameObject(uint32_t param_1) {}
			virtual void  RegisterProjectileExtension(char* param_1) {}
			virtual void  DeleteAllProjectiles() {}
			virtual  ArkSaveLoadSystem*  GetArkSaveLoadSystem() {}
			virtual void  OnGameModeChanged() {}
			virtual void  ReloadArkGameNoises() {}
			virtual void  EmitArkGameNoise(uint32_t param_1,  Vec3_tpl<float>*param_2,  Params* param_3) {}
			virtual  ArkGameNoiseLoudness*  FindArkGameNoiseLoudness(uint64_t param_1) {}
			virtual void  InitEditor( IGameToEditorInterface* param_1) {}
			virtual void  SetEditorLevel(char* param_1, char* param_2) {}
			virtual void  GetEditorLevel(char** param_1, char** param_2) {}
			virtual void  BeginLanQuery() {}
			virtual void  EndCurrentQuery() {}
			virtual  IActor*  GetClientActor() {}
			virtual uint32_t  GetClientActorId() {}
			virtual  IEntity*  GetClientEntity() {}
			virtual uint32_t  GetClientEntityId() {}
			virtual  INetChannel*  GetClientChannel() {}
			virtual void  DelegateAuthority(uint32_t param_1, unsigned short param_2) {}
			virtual  CTimeValue*  GetServerTime() {}
			virtual unsigned short  GetGameChannelId( INetChannel* param_1) {}
			virtual bool  IsChannelOnHold(unsigned short param_1) {}
			virtual  INetChannel*  GetNetChannel(unsigned short param_1) {}
			virtual  IGameObject*  GetGameObject(uint32_t param_1) {}
			virtual bool  GetNetworkSafeClassId(unsigned short * param_1, char* param_2) {}
			virtual bool  GetNetworkSafeClassName(char* param_1, uint64_t param_2, unsigned short param_3) {}
			virtual  IGameObjectExtension*  QueryGameObjectExtension(uint32_t param_1, char* param_2) {}
			virtual bool  SaveGame(char* param_1, bool param_2, bool param_3,  ESaveGameReason* param_4, bool param_5, char* param_6) {}
			virtual  ELoadGameResult*  LoadGame(char* param_1, bool param_2, bool param_3) {}
			virtual void  ScheduleEndLevelNow(char* param_1) {}
			virtual void  OnEditorSetGameMode(int param_1) {}
			virtual bool  IsEditing() {}
			virtual bool  IsInLevelLoad() {}
			virtual bool  IsLoadingSaveGame() {}
			virtual bool  IsInTimeDemo() {}
			virtual bool  IsTimeDemoRecording() {}
			virtual void  AllowSave(bool param_1) {}
			virtual void  AllowLoad(bool param_1) {}
			virtual bool  CanSave() {}
			virtual bool  CanLoad() {}
			virtual bool  IsSavePending() {}
			virtual void  FinishWritingSave() {}
			virtual bool  IsWritingSave() {}
			virtual  ISerializeHelper*  GetSerializeHelper() {}
			virtual bool  CanCheat() {}
			virtual char*  GetLevelName() {}
			virtual char*  GetAbsLevelPath(char* param_1, uint32_t param_2) {}
			virtual  IPersistantDebug*  GetIPersistantDebug() {}
			virtual void  AddBreakEventListener( IBreakEventListener* param_1) {}
			virtual void  RemoveBreakEventListener( IBreakEventListener* param_1) {}
			virtual void  RegisterListener( IGameFrameworkListener* param_1, char* param_2,  EFRAMEWORKLISTENERPRIORITY* param_3) {}
			virtual void  UnregisterListener( IGameFrameworkListener* param_1) {}
			virtual  INetNub*  GetServerNetNub() {}
			virtual  INetNub*  GetClientNetNub() {}
			virtual void  SetGameGUID(char* param_1) {}
			virtual char*  GetGameGUID() {}
			virtual  INetContext*  GetNetContext() {}
			virtual void  GetMemoryUsage( ICrySizer* param_1) {}
			virtual void  EnableVoiceRecording(bool param_1) {}
			virtual void   $FunctionCaller( EArkNpcFacingDesireCallbackEvent* param_2) {}
			virtual  IDebugHistoryManager*  CreateDebugHistoryManager() {}
			virtual void  DumpMemInfo(char* param_1) {}
			virtual bool  IsVoiceRecordingEnabled() {}
			virtual bool  IsImmersiveMPEnabled() {}
			virtual void  ExecuteCommandNextFrame(char* param_1) {}
			virtual char*  GetNextFrameCommand() {}
			virtual void  ClearNextFrameCommand() {}
			virtual void  ShowPageInBrowser(char* param_1) {}
			virtual bool  StartProcess(char* param_1) {}
			virtual bool  SaveServerConfig(char* param_1) {}
			virtual void  PrefetchLevelAssets(bool param_1) {}
			virtual void  ReleaseGameStats() {}
			virtual void  OnBreakageSpawnedEntity( IEntity* param_1,  IPhysicalEntity* param_2,  IPhysicalEntity* param_3) {}
			virtual bool  IsGameSession(uint32_t param_1) {}
			virtual bool  ShouldMigrateNub(uint32_t param_1) {}
			// virtual uint32_t  AddTimer( CTimeValue* param_1, bool param_2,  Functor2<void* ___ptr64, unsigned_int> param_3, void* param_4) {}
			virtual void GARBAGEaddTimer() {}
			virtual void*  RemoveTimer(uint32_t param_1) {}
			virtual void  ClearTimers() {}
			virtual uint32_t  GetPreUpdateTicks() {}
			virtual float  GetLoadSaveDelay() {}
			virtual void  StartNetworkStallTicker(bool param_1) {}
			virtual void  StopNetworkStallTicker() {}
			virtual  IGameVolumes*  GetIGameVolumesManager() {}
			virtual void  PreloadAnimatedCharacter( IScriptTable* param_1) {}
			virtual void  RegisterExtension( std::shared_ptr<ICryUnknown>*param_1) {}
			virtual void  ReleaseExtensions() {}
			virtual  std::shared_ptr<ICryUnknown>*  QueryExtensionInterfaceById( CryGUID* param_1) {}
			virtual  void garbage() {}
			virtual void  ScheduleEndLevel(char* param_1) {}
			virtual  CGameServerNub*  GetGameServerNub() {}
			virtual  CGameStatsConfig*  GetGameStatsConfig() {}
			virtual  IAIActorProxy*  GetAIActorProxy(uint32_t param_1) {}
			bool m_paused;
			bool m_forcedpause;
			bool m_levelPrecachingDone;
			bool m_usingLevelHeap;
			undefined field12_0xc;
			undefined field13_0xd;
			undefined field14_0xe;
			undefined field15_0xf;
			ISystem* m_pSystem;
			INetwork* m_pNetwork;
			I3DEngine* m_p3DEngine;
			IScriptSystem* m_pScriptSystem;
			IEntitySystem* m_pEntitySystem;
			ITimer* m_pTimer;
			ILog* m_pLog;
			void* m_systemDll;
			CActionGame* m_pGame;
			char m_editorLevelName[512];
			char m_editorLevelFolder[512];
			char m_gameGUID[128];
			CLevelSystem* m_pLevelSystem;
			CActorSystem* m_pActorSystem;
			CItemSystem* m_pItemSystem;
			CSharedParamsManager* m_pSharedParamsManager;
			CActionMapManager* m_pActionMapManager;
			CViewSystem* m_pViewSystem;
			CGameplayRecorder* m_pGameplayRecorder;
			CGameRulesSystem* m_pGameRulesSystem;
			CFlowSystem* m_pFlowSystem;
			CGameObjectSystem* m_pGameObjectSystem;
			CUIDraw* m_pUIDraw;
			CScriptRMI* m_pScriptRMI;
			CAnimationGraphCVars* m_pAnimationGraphCvars;
			IMannequin* m_pMannequin;
			CMaterialEffects* m_pMaterialEffects;
			CPlayerProfileManager* m_pPlayerProfileManager;
			CDialogSystem* m_pDialogSystem;
			CSubtitleManager* m_pSubtitleManager;
			IGameTokenSystem* m_pGameTokenSystem;
			IEffectSystem* m_pEffectSystem;
			CGameSerialize* m_pGameSerialize;
			CallbackTimer* m_pCallbackTimer;
			CGameplayAnalyst* m_pGameplayAnalyst;
			CVisualLog* m_pVisualLog;
			CForceFeedBackSystem* m_pForceFeedBackSystem;
			ILanQueryListener* m_pLanQueryListener;
			CCustomActionManager* m_pCustomActionManager;
			CCustomEventManager* m_pCustomEventManager;
			CGameStatsConfig* m_pGameStatsConfig;
			IGameStatistics* m_pGameStatistics;
			ICooperativeAnimationManager* m_pCooperativeAnimationManager;
			IGameSessionHandler* m_pGameSessionHandler;
			CAIProxyManager* m_pAIProxyManager;
			IGameVolumes* m_pGameVolumesManager;
			CDevMode* m_pDevMode;
			CTimeDemoRecorder* m_pTimeDemoRecorder;
			CGameQueryListener* m_pGameQueryListener;
			CRuntimeAreaManager* m_pRuntimeAreaManager;
			CScriptBind_Action* m_pScriptA;
			CScriptBind_ActorSystem* m_pScriptAS;
			CScriptBind_Network* m_pScriptNet;
			CScriptBind_ActionMapManager* m_pScriptAMM;
			CScriptBind_DialogSystem* m_pScriptBindDS;
			CScriptBind_MaterialEffects* m_pScriptBindMFX;
			CScriptBind_UIAction* m_pScriptBindUIAction;
			CTimeOfDayScheduler* m_pTimeOfDayScheduler;
			CPersistantDebug* m_pPersistantDebug;
			CAIDebugRenderer* m_pAIDebugRenderer;
			CAINetworkDebugRenderer* m_pAINetworkDebugRenderer;
			CNetworkCVars* m_pNetworkCVars;
			CCryActionCVars* m_pCryActionCVars;
			CNetworkStallTickerThread* m_pNetworkStallTickerThread;
			uint32_t m_networkStallTickerReferences;
			undefined field81_0x67c;
			undefined field82_0x67d;
			undefined field83_0x67e;
			undefined field84_0x67f;
			CMaterialEffectsCVars* m_pMaterialEffectsCVars;
			CCryActionPhysicQueues* m_pPhysicsQueues;
			std::vector<std::shared_ptr<ICryUnknown>> m_frameworkExtensions;
			ICVar* m_pEnableLoadingScreen;
			ICVar* m_pCheats;
			ICVar* m_pShowLanBrowserCVAR;
			ICVar* m_pDebugSignalTimers;
			ICVar* m_pDebugRangeSignaling;
			bool m_bShowLanBrowser;
			bool m_isEditing;
			bool m_bScheduleLevelEnd;
			undefined field96_0x6d3;
			ESaveGameMethod m_delayedSaveGameMethod;
			ESaveGameReason m_delayedSaveGameReason;
			int m_delayedSaveCountDown;
			SLocalAllocs* m_pLocalAllocs;
			std::vector<SGameFrameworkListener>* m_pGFListeners;
			IBreakEventListener* m_pBreakEventListener;
			std::vector<bool, std::allocator<bool>> m_validListeners;
			int32_t m_VoiceRecordingEnabled;
			bool m_bAllowSave;
			bool m_bAllowLoad;
			undefined field107_0x71e;
			undefined field108_0x71f;
			 CryStringT<char>* m_nextFrameCommand;
			 CryStringT<char>* m_connectServer;
			float m_lastSaveLoad;
			float m_lastFrameTimeUI;
			bool m_pbSvEnabled;
			bool m_pbClEnabled;
			undefined field115_0x73a;
			undefined field116_0x73b;
			uint32_t m_PreUpdateTicks;
			CNetMessageDistpatcher* m_pNetMsgDispatcher;
			ArkSaveLoadSystem m_arkSaveLoadSystem;
			ArkGameNoises m_arkGameNoiseData;
			std::vector<int, std::allocator<int>> m_projectileExtensionIds;
			ArkAudioSwitchManager m_arkAudioSwitchManager;
			SAudioRequest m_pauseAudioRequest;
			SAudioRequest m_resumeAudioRequest;
			SAudioManagerRequestData<16777216> m_pauseAudioRequestData;
			SAudioManagerRequestData<33554432> m_resumeAudioRequestData;
		};
		// class IGameToEditorInterface {};
		class ExportFilesInfo{};
		namespace ArkObjectiveUtils {
			class CArkObjectiveTaskData {
			public:
				CryStringT<char> m_text,
					m_displayName,
					m_markerLabel,
					m_timerLabel;
				int64_t m_id;
				uint64_t m_originalLocationId,
					m_targetCharacterId,
					m_descriptionId;
				bool m_bOptional;
				char pad[7];
			};
			class CArkObjectiveDescriptionData {
			public:
				uint64_t m_id;
				CryStringT<char> m_text,
					m_displayName;
			};
			class CArkObjectiveClueData {
			public:
				uint64_t m_id;
				CryStringT<char> m_text,
					m_displayName;
			};
		}
		class CArkObjectiveData{
		public:
			std::vector<ArkObjectiveUtils::CArkObjectiveTaskData> m_tasks;
			std::vector<ArkObjectiveUtils::CArkObjectiveDescriptionData> m_descriptions;
			std::vector<ArkObjectiveUtils::CArkObjectiveClueData>m_clues;
			CryStringT<char> m_title;
			int64_t m_id;
			bool m_bOptional;
			char pad[7];
		};
		
		class CGoalPipe {};
		class CClearRegionPass {};
		class IArkNpc {};
		class CaptureVolumeInfo{};
		
		class CGodMode {
		public:
			uint32_t m_godMode,
				m_demiGodRevivesAtCheckpoint;
			bool m_hasHitCheckpoint;
			char pad[3];
			Matrix34_tpl<float> m_lastCheckpointWorldTM;
		};
	 

		class ArkNpcSpawnRequester {
		public:
			void* ptr;
		};
		class SExtension {
		public:
			uint64_t eventReg;
			std::shared_ptr<IGameObjectExtension> pExtension;
			unsigned short id;
			unsigned char refCount;
			unsigned char updateEnables[5];
			unsigned char forceEnables[5];
			char pad[11];
		};
		
		class IProceduralContext{};
		class CRMIBody{};
		class IArkNpcSpawner {
			virtual void* _ECArkNpcSpawner(uint32_t param_1) {}
			virtual void  ProcessEvent(SEntityEvent* param_1) {}
			virtual  AKRESULT* ActivateTrigger(bool param_2) {}
			virtual void   garbage0() {}
			virtual void   garbage1() {}
			virtual bool  Init(IGameObject* param_1) {}
			virtual void   garbage2() {}
			virtual void   garbage3() {}
			virtual void   garbage4() {}
			virtual bool  Activating(float param_1) {}
			virtual void   garbage5() {}
			virtual bool  GetEntityPoolSignature(CSerializeWrapper<ISerialize>* param_1) {}
			virtual void  Complete() {}
			virtual void  FullSerialize(CSerializeWrapper<ISerialize>* param_1) {}
			virtual bool  garbage6() {}
			virtual int  AddChunk(ChunkTypes* param_1, int param_2, EEndianness* param_3, void* param_4, int param_5) {}
			virtual void  garbage7() {}
			virtual void  garbage8() {}
			virtual  IDatagramSocket* CreateDatagramSocket(boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<4>, SNullAddr, boost::mpl::l_item<boost::mpl::long_<3>, unsigned short, boost::mpl::l_item<boost::mpl::long_<2>, SIPv4Addr, boost::mpl::l_item<boost::mpl::long_<1>, LobbyIdAddr, boost::mpl::l_end>>>>>>* param_1, uint32_t param_2) {}
			virtual void  Update(SEntityUpdateContext* param_1, int param_2) {}
			virtual void  garbage9() {}
			virtual void  garbage10() {}
			virtual void  garbage11() {}
			virtual void* GetRMIBase() {}
			virtual void   garbage12() {}
			virtual void   garbage13() {}
			virtual void  OnFirstTimeInLevel() {}
		};
		class CArkNpcSpawner {
		public:
			void* vtable;
			// IGameObjectExtension m_ext;
			char pad[32];
			CGameObject* m_gameObject;
			char pad2[8];
			CEntity* m_Entity;
			char pad3[8];
			uint64_t m_pendingSpawnCount;
			uint32_t m_lastSpawnedEntityId;
			char pad4[4];
			CryStringT<char> m_ManagedByEncounter;
		};
		class CArkNpcSpawnCystoid {
		public:
			virtual void* _ECArkNpcSpawner(uint32_t param_1) {}
			virtual void  ProcessEvent(SEntityEvent* param_1) {}
			virtual  AKRESULT* ActivateTrigger(bool param_2) {}
			virtual void   garbage0() {}
			virtual void   garbage1() {}
			virtual bool  Init(IGameObject* param_1) {}
			virtual void   garbage2() {}
			virtual void   garbage3() {}
			virtual void   garbage4() {}
			virtual bool  Activating(float param_1) {}
			virtual void   garbage5() {}
			virtual bool  GetEntityPoolSignature(CSerializeWrapper<ISerialize>* param_1) {}
			virtual void  Complete() {}
			virtual void  FullSerialize(CSerializeWrapper<ISerialize>* param_1) {}
			virtual bool  garbage6() {}
			virtual int  AddChunk(ChunkTypes* param_1, int param_2, EEndianness* param_3, void* param_4, int param_5) {}
			virtual void  garbage7() {}
			virtual void  garbage8() {}
			virtual  IDatagramSocket* CreateDatagramSocket(boost::variant<boost::detail::variant::over_sequence<boost::mpl::l_item<boost::mpl::long_<4>, SNullAddr, boost::mpl::l_item<boost::mpl::long_<3>, unsigned short, boost::mpl::l_item<boost::mpl::long_<2>, SIPv4Addr, boost::mpl::l_item<boost::mpl::long_<1>, LobbyIdAddr, boost::mpl::l_end>>>>>>* param_1, uint32_t param_2) {}
			virtual void  Update(SEntityUpdateContext* param_1, int param_2) {}
			virtual void  garbage9() {}
			virtual void  garbage10() {}
			virtual void  garbage11() {}
			virtual void* GetRMIBase() {}
			virtual void   garbage12() {}
			virtual void   garbage13() {}
			virtual void  OnFirstTimeInLevel() {}
			uint64_t m_pendingSpawnCount;
			uint32_t m_lastSpawnedEntityId;
			char pad4[4];
			CryStringT<char> m_ManagedByEncounter;
		};
		

		
		
		class SMFXAudioEffectRtpc
		{
			const char* rtpcName;
			float rtpcValue;
		};
		class SMFXRunTimeEffectParams
		{
			unsigned __int16 playSoundFP;
			unsigned __int16 playflags;
			float fLastTime;
			float fDecalPlacementTestMaxSize;
			unsigned int src;
			unsigned int trg;
			int srcSurfaceId;
			int trgSurfaceId;
			IRenderNode* srcRenderNode;
			IRenderNode* trgRenderNode;
			int partID;
			Vec3_tpl<float> pos;
			Vec3_tpl<float> decalPos;
			Vec3_tpl<float> dir[2];
			Vec3_tpl<float> normal;
			float angle;
			float scale;
			unsigned int audioProxyEntityId;
			Vec3_tpl<float> audioProxyOffset;
			SMFXAudioEffectRtpc audioRtpcs[4];
			unsigned int numAudioRtpcs;
		};
		class STagMask
		{
			unsigned __int8 byte;
			unsigned __int8 mask;
		};
		class SCRCRefHash_CRC32Lowercase
		{
		};
		template<int i, typename T> class SCRCRef// Size=0x10 (Id=16962)
		{
				const unsigned int INVALID = 0;// Offset=0x0 Size=0x4
				unsigned int crc;// Offset=0x0 Size=0x4
				char* stringValue;// Offset=0x8 Size=0x8
		};
		class CTagDefinition
		{
			struct SPriorityCount// Size=0x8 (Id=2087732)
			{
				int priority;// Offset=0x0 Size=0x4
				int count;// Offset=0x4 Size=0x4
			};
			struct STagGroup// Size=0x10 (Id=2087841)
			{
				struct SCRCRef<1, SCRCRefHash_CRC32Lowercase> m_name;// Offset=0x0 Size=0x10
			};
			struct STag// Size=0x20 (Id=2087842)
			{
				unsigned int m_priority;// Offset=0x0 Size=0x4
				int m_groupID;// Offset=0x4 Size=0x4
				class CTagDefinition* m_pTagDefinition;// Offset=0x8 Size=0x8
				struct SCRCRef<1, SCRCRefHash_CRC32Lowercase> m_name;// Offset=0x10 Size=0x10
			};
			
			struct STagDefData// Size=0x18 (Id=2087790)
			{
				struct DynArray<STagMask, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > tagMasks;// Offset=0x0 Size=0x8
				struct DynArray<STagMask, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > groupMasks;// Offset=0x8 Size=0x8
				unsigned int numBits;// Offset=0x10 Size=0x4
			};
			CryStringT<char> m_filename;
			DynArray<CTagDefinition::STag, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_tags;
			DynArray<CTagDefinition::STagGroup, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_tagGroups;
			CTagDefinition::STagDefData m_defData;
			DynArray<CTagDefinition::SPriorityCount, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_priorityTallies;
			bool m_hasMasks;
		};
		
		
		
		
		
		
		

