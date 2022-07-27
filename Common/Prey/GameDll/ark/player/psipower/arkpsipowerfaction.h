// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <_unknown/CAkKeyArray_unsigned long,CAkFeedbackNode__SrcInfo _,AkArrayAllocatorNoAlign__ArrayPoolDefault_,1,AkAssignmentMovePolicy_MapStruct_unsigned long,CAkFeedbackNode__SrcInfo __ _ _.h>

struct ActionParams;
struct ActionParamsExcept;
struct AkPBIModValues;
class AkRTPCKey;
struct AkSoundParamsEx;
class ArkClass;
struct CounterParameters;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
class ArkPsiPowerFactionProperties : public ArkReflectedObject // Id=801C0F5 Size=8
{
public:
	class ArkExecuteAudioTriggerProperty : public ArkProperty // Id=801C0F6 Size=32
	{
	public:
		ArkExecuteAudioTriggerProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerFactionProperties::ArkExecuteAudioTriggerProperty s_ArkExecuteAudioTriggerProperty;
	string m_ExecuteAudioTrigger;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	void SetExecuteAudioTrigger(string arg0);
	string const &GetExecuteAudioTrigger() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x13644E0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h
class CAkFeedbackNode : public CAkSoundBase // Id=801F07D Size=200
{
public:
	class SrcInfo : public CAkSource // Id=801F07E Size=40
	{
	public:
		uint16_t m_idDeviceCompany;
		uint16_t m_idDevicePlugin;
		float m_fVolumeOffset;
	};

	using SrcInfoArray = CAkKeyArray<unsigned long,CAkFeedbackNode::SrcInfo *,AkArrayAllocatorNoAlign<_ArrayPoolDefault>,1,AkAssignmentMovePolicy<MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> > >;
	
	CAkKeyArray<unsigned long,CAkFeedbackNode::SrcInfo *,AkArrayAllocatorNoAlign<_ArrayPoolDefault>,1,AkAssignmentMovePolicy<MapStruct<unsigned long,CAkFeedbackNode::SrcInfo *> > > m_arSrcInfo;
	
	static CAkFeedbackNode *Create(unsigned long in_ulID) { return FCreate(in_ulID); }
	virtual AkNodeCategory NodeCategory();
	virtual AKRESULT PlayInternal(AkPBIParams &in_rPBIParams);
	virtual void ExecuteAction(ActionParams &in_rAction);
	virtual void ExecuteActionExcept(ActionParamsExcept &in_rAction);
	AKRESULT AddPluginSource(unsigned long in_srcID, uint16_t in_idDeviceCompany, uint16_t in_idDevicePlugin) { return FAddPluginSource(this,in_srcID,in_idDeviceCompany,in_idDevicePlugin); }
	void SetSourceVolumeOffset(unsigned long in_srcID, float in_fOffset) { FSetSourceVolumeOffset(this,in_srcID,in_fOffset); }
	float GetSourceVolumeOffset(CAkSource *in_pSource) { return FGetSourceVolumeOffset(this,in_pSource); }
	void RemoveAllSources() { FRemoveAllSources(this); }
	virtual AkObjectCategory Category();
	virtual AKRESULT IncrementPlayCount(CounterParameters &io_params);
	virtual AKRESULT PrepareData();
	virtual void UnPrepareData();
	AKRESULT SetInitialValues(uint8_t *in_pData, unsigned long in_ulDataSize, CAkUsageSlot *in_pUsageSlot, bool in_bIsPartialLoadOnly) { return FSetInitialValues(this,in_pData,in_ulDataSize,in_pUsageSlot,in_bIsPartialLoadOnly); }
	virtual ~CAkFeedbackNode();
	virtual AKRESULT GetFeedbackParameters(AkFeedbackParams &io_Params, CAkSource *in_pSource, CAkRegisteredObj *in_GameObjPtr, bool in_bDoBusCheck);
	virtual AKRESULT GetAudioParameters(AkSoundParamsEx &io_Parameters, unsigned long in_ulParamSelect, AkMutedMap &io_rMutedMap, AkRTPCKey const &in_rtpcKey, bool in_bIncludeRange, AkPBIModValues &io_Ranges, bool in_bDoBusCheck);
	
#if 0
	void RemoveSource(unsigned long arg0);
	bool HasBankSource();
	bool SourceLoaded();
	AKRESULT Init();
#endif
	
	static inline auto FCreate = PreyFunction<CAkFeedbackNode *(unsigned long in_ulID)>(0x1A275F0);
	static inline auto FNodeCategory = PreyFunction<AkNodeCategory(CAkFeedbackNode *const _this)>(0x1583B30);
	static inline auto FPlayInternal = PreyFunction<AKRESULT(CAkFeedbackNode *const _this, AkPBIParams &in_rPBIParams)>(0x1A27860);
	static inline auto FExecuteAction = PreyFunction<void(CAkFeedbackNode *const _this, ActionParams &in_rAction)>(0x1A27690);
	static inline auto FExecuteActionExcept = PreyFunction<void(CAkFeedbackNode *const _this, ActionParamsExcept &in_rAction)>(0x1A32FB0);
	static inline auto FAddPluginSource = PreyFunction<AKRESULT(CAkFeedbackNode *const _this, unsigned long in_srcID, uint16_t in_idDeviceCompany, uint16_t in_idDevicePlugin)>(0x1A274A0);
	static inline auto FSetSourceVolumeOffset = PreyFunction<void(CAkFeedbackNode *const _this, unsigned long in_srcID, float in_fOffset)>(0x1A27B30);
	static inline auto FGetSourceVolumeOffset = PreyFunction<float(CAkFeedbackNode *const _this, CAkSource *in_pSource)>(0x1A277A0);
	static inline auto FRemoveAllSources = PreyFunction<void(CAkFeedbackNode *const _this)>(0x1A27970);
	static inline auto FCategory = PreyFunction<AkObjectCategory(CAkFeedbackNode *const _this)>(0x9DD2D0);
	static inline auto FIncrementPlayCount = PreyFunction<AKRESULT(CAkFeedbackNode *const _this, CounterParameters &io_params)>(0x1A277F0);
	static inline auto FPrepareData = PreyFunction<AKRESULT(CAkFeedbackNode *const _this)>(0x1A27900);
	static inline auto FUnPrepareData = PreyFunction<void(CAkFeedbackNode *const _this)>(0x1A27C30);
	static inline auto FSetInitialValues = PreyFunction<AKRESULT(CAkFeedbackNode *const _this, uint8_t *in_pData, unsigned long in_ulDataSize, CAkUsageSlot *in_pUsageSlot, bool in_bIsPartialLoadOnly)>(0x1A27A10);
	static inline auto FBitNotCAkFeedbackNode = PreyFunction<void(CAkFeedbackNode *const _this)>(0x1A273F0);
	static inline auto FGetFeedbackParameters = PreyFunction<AKRESULT(CAkFeedbackNode *const _this, AkFeedbackParams &io_Params, CAkSource *in_pSource, CAkRegisteredObj *in_GameObjPtr, bool in_bDoBusCheck)>(0x1A276D0);
	static inline auto FGetAudioParameters = PreyFunction<AKRESULT(CAkFeedbackNode *const _this, AkSoundParamsEx &io_Parameters, unsigned long in_ulParamSelect, AkMutedMap &io_rMutedMap, AkRTPCKey const &in_rtpcKey, bool in_bIncludeRange, AkPBIModValues &io_Ranges, bool in_bDoBusCheck)>(0x1A276B0);
};

