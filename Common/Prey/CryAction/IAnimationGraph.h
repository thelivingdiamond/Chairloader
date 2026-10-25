// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class CAnimatedCharacter;
class CAnimation;
struct CryCharAnimationParams;
enum EAnimationGraphPauser;
enum EAnimationGraphTriggerUser;
enum EMotionParamID;
struct IAnimationGraphAuxillaryInputs;
struct IAnimationGraphExistanceQuery;
struct IAnimationGraphStateListener;
class ICrySizer;
struct IEntity;
struct SAnimationTarget;
struct SAnimationTargetRequest;

// CAnimationPlayerProxy
// Header:  CryEngine/cryaction/ianimationgraph.h
// Include: Prey/CryAction/IAnimationGraph.h
class CAnimationPlayerProxy
{ // Size=8 (0x8)
public:
	virtual ~CAnimationPlayerProxy();
	virtual bool StartAnimation(IEntity* entity, const char* szAnimName0, const CryCharAnimationParams& Params, float speedMultiplier);
	virtual bool StartAnimationById(IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier);
	virtual bool StopAnimationInLayer(IEntity* entity, int nLayer, float BlendOutTime);
	virtual bool RemoveAnimationInLayer(IEntity* entity, int nLayer, unsigned token);
	virtual float GetAnimationNormalizedTime(IEntity* pEntity, const CAnimation* pAnimation);
	virtual bool SetAnimationNormalizedTime(IEntity* pEntity, CAnimation* pAnimation, float normalizedTime);
	virtual float GetTopAnimExpectedSecondsLeft(IEntity* entity, int layer);
	virtual float GetTopAnimNormalizedTime(IEntity* entity, int layer);
	virtual const CAnimation* GetTopAnimation(IEntity* entity, int layer);
	virtual CAnimation* GetAnimation(IEntity* entity, int layer, unsigned token);

#ifndef MOONCRASH
	static inline auto FStartAnimation = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, const char* szAnimName0, const CryCharAnimationParams& Params, float speedMultiplier)>(0x4F5600);
	static inline auto FStartAnimationById = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier)>(0x4F5690);
	static inline auto FStopAnimationInLayer = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, int nLayer, float BlendOutTime)>(0x4F5720);
	static inline auto FRemoveAnimationInLayer = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, int nLayer, unsigned token)>(0x4F5780);
	static inline auto FGetAnimationNormalizedTime = PreyFunction<float(CAnimationPlayerProxy* const _this, IEntity* pEntity, const CAnimation* pAnimation)>(0x4F5830);
	static inline auto FSetAnimationNormalizedTime = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* pEntity, CAnimation* pAnimation, float normalizedTime)>(0x4F5890);
	static inline auto FGetTopAnimExpectedSecondsLeft = PreyFunction<float(CAnimationPlayerProxy* const _this, IEntity* entity, int layer)>(0x4F5900);
	static inline auto FGetTopAnimNormalizedTime = PreyFunction<float(CAnimationPlayerProxy* const _this, IEntity* entity, int layer)>(0x4F59C0);
	static inline auto FGetTopAnimation = PreyFunction<const CAnimation* (CAnimationPlayerProxy* const _this, IEntity* entity, int layer)>(0x4F5A60);
	static inline auto FGetAnimation = PreyFunction<CAnimation* (CAnimationPlayerProxy* const _this, IEntity* entity, int layer, unsigned token)>(0x4F5AD0);
#else
	static inline auto FStartAnimation = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, const char* szAnimName0, const CryCharAnimationParams& Params, float speedMultiplier)>(0x50E870);
	static inline auto FStartAnimationById = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, int animId, const CryCharAnimationParams& Params, float speedMultiplier)>(0x50E900);
	static inline auto FStopAnimationInLayer = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, int nLayer, float BlendOutTime)>(0x50E990);
	static inline auto FRemoveAnimationInLayer = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* entity, int nLayer, unsigned token)>(0x50E9F0);
	static inline auto FGetAnimationNormalizedTime = PreyFunction<float(CAnimationPlayerProxy* const _this, IEntity* pEntity, const CAnimation* pAnimation)>(0x50EAA0);
	static inline auto FSetAnimationNormalizedTime = PreyFunction<bool(CAnimationPlayerProxy* const _this, IEntity* pEntity, CAnimation* pAnimation, float normalizedTime)>(0x50EB00);
	static inline auto FGetTopAnimExpectedSecondsLeft = PreyFunction<float(CAnimationPlayerProxy* const _this, IEntity* entity, int layer)>(0x50EB70);
	static inline auto FGetTopAnimNormalizedTime = PreyFunction<float(CAnimationPlayerProxy* const _this, IEntity* entity, int layer)>(0x50EC30);
	static inline auto FGetTopAnimation = PreyFunction<const CAnimation* (CAnimationPlayerProxy* const _this, IEntity* entity, int layer)>(0x50ECD0);
	static inline auto FGetAnimation = PreyFunction<CAnimation* (CAnimationPlayerProxy* const _this, IEntity* entity, int layer, unsigned token)>(0x50ED40);
#endif
};

// IAnimationGraphState
// Header:  CryEngine/cryaction/ianimationgraph.h
// Include: Prey/CryAction/IAnimationGraph.h
struct IAnimationGraphState
{ // Size=8 (0x8)
	using InputID = uint8_t;

	virtual ~IAnimationGraphState();
	virtual bool SetInput(uint8_t __unnamed1, float __unnamed2, unsigned* pQueryID) = 0;
	virtual bool SetInput(uint8_t __unnamed1, int __unnamed2, unsigned* pQueryID) = 0;
	virtual bool SetInput(uint8_t iid, const char* value, unsigned* pQueryID) = 0;
	virtual bool SetInputOptional(uint8_t iid, const char* value, unsigned* pQueryID) = 0;
	void QueryChangeInput(const char* name, unsigned* pQueryID) { FQueryChangeInputOv1(this, name, pQueryID); }
	virtual void QueryChangeInput(uint8_t iid, unsigned* pQuery) = 0;
	virtual void LockInput(uint8_t __unnamed1, bool locked) = 0;
	virtual void ClearInput(uint8_t __unnamed1) = 0;
	virtual bool SetVariationInput(const char* name, const char* value) = 0;
	virtual bool SetVariationInput(uint8_t inputID, const char* value) = 0;
	virtual const char* GetVariationInput(uint8_t inputID) const = 0;
	virtual void GetInput(uint8_t iid, char* value) const = 0;
	virtual void GetInput(uint8_t iid, char* value, int layerIndex) const = 0;
	virtual bool IsDefaultInputValue(uint8_t iid) const = 0;
	virtual const char* GetInputName(uint8_t iid) const = 0;
	virtual const char* GetVariationInputName(uint8_t __unnamed1) const = 0;
	virtual void QueryLeaveState(unsigned* pQueryID) = 0;
	virtual void AddListener(const char* name, IAnimationGraphStateListener* pListener) = 0;
	virtual void RemoveListener(IAnimationGraphStateListener* pListener) = 0;
	virtual bool DoesInputMatchState(uint8_t __unnamed1) const = 0;
	virtual void SetAnimatedCharacter(CAnimatedCharacter* animatedCharacter, int layerIndex, IAnimationGraphState* parentLayerState) = 0;
	virtual bool Update() = 0;
	virtual void Release() = 0;
	virtual void ForceTeleportToQueriedState() = 0;
	virtual void PushForcedState(const char* state, unsigned* pQueryID) = 0;
	virtual void ClearForcedStates() = 0;
	virtual float GetInputAsFloat(uint8_t inputId) = 0;
	virtual uint8_t GetInputId(const char* input) = 0;
	virtual uint8_t GetVariationInputId(const char* variationInputName) const = 0;
	virtual void Serialize(TSerialize ser) = 0;
	virtual void SetAnimationActivation(bool activated) = 0;
	virtual bool GetAnimationActivation() = 0;
	virtual const char* GetCurrentStateName() = 0;
	virtual void Pause(bool pause, EAnimationGraphPauser pauser, float fOverrideTransTime) = 0;
	virtual bool IsInDebugBreak() = 0;
	virtual const char* QueryOutput(const char* name) = 0;
	virtual IAnimationGraphAuxillaryInputs* SetTrigger(const SAnimationTargetRequest& req, EAnimationGraphTriggerUser user, unsigned* pQueryStart, unsigned* pQueryEnd) = 0;
	virtual void ClearTrigger(EAnimationGraphTriggerUser user) = 0;
	virtual const SAnimationTarget* GetAnimationTarget() = 0;
	virtual bool HasAnimationTarget() const = 0;
	virtual bool IsUpdateReallyNecessary() = 0;
	virtual IAnimationGraphExistanceQuery* CreateExistanceQuery() = 0;
	virtual IAnimationGraphExistanceQuery* CreateExistanceQuery(int layer) = 0;
	virtual void Reset() = 0;
	virtual void Hurry() = 0;
	virtual void SetFirstPersonMode(bool on) = 0;
	virtual void GetMemoryUsage(ICrySizer* s) const = 0;
	virtual bool IsMixingAllowedForCurrentState() const = 0;
	virtual bool IsSignalledInput(uint8_t iid) const = 0;

#if 0
	bool SetInputOptional(const char* _arg0_, const char* _arg1_, unsigned* _arg2_);
	void LockInput(const char* _arg0_, bool _arg1_);
#endif

#ifndef MOONCRASH
	static inline auto FQueryChangeInputOv1 = PreyFunction<void(IAnimationGraphState* const _this, const char* name, unsigned* pQueryID)>(0x3FC190);
#else
	static inline auto FQueryChangeInputOv1 = PreyFunction<void(IAnimationGraphState* const _this, const char* name, unsigned* pQueryID)>(0x415A90);
#endif
};

// SPredictedCharacterStates
// Header:  CryEngine/cryaction/ianimationgraph.h
// Include: Prey/CryAction/IAnimationGraph.h
struct SPredictedCharacterStates
{ // Size=32 (0x20)
	float m_motionParameter[6];
	uint8_t m_motionParameterID[6];
	uint8_t m_numParams;

	bool SetParam(EMotionParamID motionParameterID, float value) { return FSetParam(this, motionParameterID, value); }

#if 0
	SPredictedCharacterStates();
	bool IsSet() const;
	void Reset();
	bool GetParam(EMotionParamID _arg0_, float& _arg1_) const;
	bool IsValid() const;
#endif

#ifndef MOONCRASH
	static inline auto FSetParam = PreyFunction<bool(SPredictedCharacterStates* const _this, EMotionParamID motionParameterID, float value)>(0x1773A40);
#else
	static inline auto FSetParam = PreyFunction<bool(SPredictedCharacterStates* const _this, EMotionParamID motionParameterID, float value)>(0x189A550);
#endif
};

