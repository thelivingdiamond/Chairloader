// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class ArkMaterialAnimation;
struct IEntity;
struct IMaterial;

// Header: FromCpp
// Prey/GameDll/ark/ArkMaterialAnimationManager.h
class ArkMaterialAnimationManager // Id=8014235 Size=584
{
public:
	struct ActiveAnimationData // Id=8014288 Size=24
	{
		std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
	};

	struct SAttachmentMaterials // Id=8014289 Size=32
	{
		int meshSlot;
		string attachmentName;
		_smart_ptr<IMaterial> pMaterial;
		_smart_ptr<IMaterial> pOriginalMaterial;
	};

	IEntity *m_pEntity;
	std::vector<ArkMaterialAnimationManager::SAttachmentMaterials> m_attachmentMaterials;
	
	struct EnumClassHash // Id=801429E Size=1
	{
	};

	ArkMaterialAnimation const *m_pOneOffMaterialAnimation;
	ArkMaterialAnimationManager::ActiveAnimationData m_oneOffAnimationData;
	std::unordered_map<enum ArkMaterialAnimationType,ArkMaterialAnimation const *,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enum ArkMaterialAnimationType>,std::allocator<std::pair<enum ArkMaterialAnimationType const ,ArkMaterialAnimation const *> > > m_animationsByType;
	ArkMaterialAnimationManager::ActiveAnimationData m_activeAnimationsByType[18];
	std::vector<MaterialParameterRamp> m_materialParameterRamps;
	
	ArkMaterialAnimationManager();
	~ArkMaterialAnimationManager();
	void StartAnimation(ArkMaterialAnimationType _animationType, float _blendInTime) { FStartAnimationOv1(this,_animationType,_blendInTime); }
	bool UpdateAnimation(ArkMaterialAnimationType _animationType, float _currentTime, float _elapsedTime) { return FUpdateAnimationOv1(this,_animationType,_currentTime,_elapsedTime); }
	bool UpdateAnimation(ArkMaterialAnimationManager::ActiveAnimationData &_animation, ArkMaterialAnimation const *_pMaterialAnim, float _currentTime, float _elapsedTime) { return FUpdateAnimationOv0(this,_animation,_pMaterialAnim,_currentTime,_elapsedTime); }
	void StartOneOffAnimation(float _blendInTime) { FStartOneOffAnimation(this,_blendInTime); }
	bool UpdateOneOffAnimation(float _currentTime, float _elapsedTime) { return FUpdateOneOffAnimation(this,_currentTime,_elapsedTime); }
	void StopOneOffAnimation() { FStopOneOffAnimation(this); }
	void UpdateMaterialParams(float _frameTime) { FUpdateMaterialParams(this,_frameTime); }
	float GetDuration(ArkMaterialAnimationType _animationType) const { return FGetDuration(this,_animationType); }
	void SimpleLerpAnimation(ArkMaterialAnimationType _animationType, float _lerpPercent) { FSimpleLerpAnimation(this,_animationType,_lerpPercent); }
	void Initialize(IEntity &_entity) { FInitializeOv1(this,_entity); }
	void Initialize(IEntity &_entity, const uint64_t _oneOffAnimation) { FInitializeOv0(this,_entity,_oneOffAnimation); }
	void ShutDown() { FShutDown(this); }
	void SetMaterialParameter(IMaterial *_pMaterial, EMaterialParamFloat _paramFloat, EMaterialParamVec3 _paramVec3, const char *_paramName, float _floatValue, Vec3 const &_vectorValue, bool _bIsFloat, float _time) { FSetMaterialParameter(this,_pMaterial,_paramFloat,_paramVec3,_paramName,_floatValue,_vectorValue,_bIsFloat,_time); }
	ArkMaterialAnimation const *GetMaterialAnimationByType(ArkMaterialAnimationType _animationType) const { return FGetMaterialAnimationByType(this,_animationType); }
	IMaterial *GetUniqueMaterial(ArkMaterialAnimation const *_pMatAnim) { return FGetUniqueMaterial(this,_pMatAnim); }
	void ClearUniqueMaterial(ArkMaterialAnimation const *_pMatAnim) { FClearUniqueMaterial(this,_pMatAnim); }
	
#if 0
	void StartAnimation(ArkMaterialAnimationManager::ActiveAnimationData &arg0, ArkMaterialAnimation const *arg1, float arg2);
	void StopAnimation(ArkMaterialAnimationType arg0);
	void StopAllAnimations();
#endif
	
	static inline auto FBitNotArkMaterialAnimationManager = PreyFunction<void(ArkMaterialAnimationManager *const _this)>(0x1199F80);
	static inline auto FStartAnimationOv1 = PreyFunction<void(ArkMaterialAnimationManager *const _this, ArkMaterialAnimationType _animationType, float _blendInTime)>(0x119B540);
	static inline auto FUpdateAnimationOv1 = PreyFunction<bool(ArkMaterialAnimationManager *const _this, ArkMaterialAnimationType _animationType, float _currentTime, float _elapsedTime)>(0x119B800);
	static inline auto FUpdateAnimationOv0 = PreyFunction<bool(ArkMaterialAnimationManager *const _this, ArkMaterialAnimationManager::ActiveAnimationData &_animation, ArkMaterialAnimation const *_pMaterialAnim, float _currentTime, float _elapsedTime)>(0x119B640);
	static inline auto FStartOneOffAnimation = PreyFunction<void(ArkMaterialAnimationManager *const _this, float _blendInTime)>(0x119B5D0);
	static inline auto FUpdateOneOffAnimation = PreyFunction<bool(ArkMaterialAnimationManager *const _this, float _currentTime, float _elapsedTime)>(0x119BAE0);
	static inline auto FStopOneOffAnimation = PreyFunction<void(ArkMaterialAnimationManager *const _this)>(0x119B140);
	static inline auto FUpdateMaterialParams = PreyFunction<void(ArkMaterialAnimationManager *const _this, float _frameTime)>(0x119B860);
	static inline auto FGetDuration = PreyFunction<float(ArkMaterialAnimationManager const *const _this, ArkMaterialAnimationType _animationType)>(0x119A800);
	static inline auto FSimpleLerpAnimation = PreyFunction<void(ArkMaterialAnimationManager *const _this, ArkMaterialAnimationType _animationType, float _lerpPercent)>(0x119B150);
	static inline auto FInitializeOv1 = PreyFunction<void(ArkMaterialAnimationManager *const _this, IEntity &_entity)>(0x119AC70);
	static inline auto FInitializeOv0 = PreyFunction<void(ArkMaterialAnimationManager *const _this, IEntity &_entity, const uint64_t _oneOffAnimation)>(0x119AF00);
	static inline auto FShutDown = PreyFunction<void(ArkMaterialAnimationManager *const _this)>(0x119B140);
	static inline auto FSetMaterialParameter = PreyFunction<void(ArkMaterialAnimationManager *const _this, IMaterial *_pMaterial, EMaterialParamFloat _paramFloat, EMaterialParamVec3 _paramVec3, const char *_paramName, float _floatValue, Vec3 const &_vectorValue, bool _bIsFloat, float _time)>(0x119AF60);
	static inline auto FGetMaterialAnimationByType = PreyFunction<ArkMaterialAnimation const *(ArkMaterialAnimationManager const *const _this, ArkMaterialAnimationType _animationType)>(0x119A8A0);
	static inline auto FGetUniqueMaterial = PreyFunction<IMaterial *(ArkMaterialAnimationManager *const _this, ArkMaterialAnimation const *_pMatAnim)>(0x119A910);
	static inline auto FClearUniqueMaterial = PreyFunction<void(ArkMaterialAnimationManager *const _this, ArkMaterialAnimation const *_pMatAnim)>(0x119A3D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkMaterialAnimationKeyframe.h>
#include <_unknown/MaterialParameterRamp.h>

class ArkMaterialAnimation;
enum class ArkMaterialAnimationType;
enum class EMaterialParamFloat;
enum class EMaterialParamVec3;
struct IEntity;
struct IMaterial;

// ArkMaterialAnimationManager
// Header:  Prey/GameDll/ark/ArkMaterialAnimationManager.h
class ArkMaterialAnimationManager
{ // Size=584 (0x248)
public:
	// ArkMaterialAnimationManager::ActiveAnimationData
	// Header:  Prey/GameDll/ark/ArkMaterialAnimationManager.h
	struct ActiveAnimationData
	{ // Size=24 (0x18)
		std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
	};

	// ArkMaterialAnimationManager::SAttachmentMaterials
	// Header:  Prey/GameDll/ark/ArkMaterialAnimationManager.h
	struct SAttachmentMaterials
	{ // Size=32 (0x20)
		int meshSlot;
		string attachmentName;
		_smart_ptr<IMaterial> pMaterial;
		_smart_ptr<IMaterial> pOriginalMaterial;
	};

	// ArkMaterialAnimationManager::EnumClassHash
	// Header:  Prey/GameDll/ark/ArkMaterialAnimationManager.h
	struct EnumClassHash
	{ // Size=1 (0x1)
	};

	IEntity* m_pEntity;
	std::vector<ArkMaterialAnimationManager::SAttachmentMaterials> m_attachmentMaterials;
	const ArkMaterialAnimation* m_pOneOffMaterialAnimation;
	ArkMaterialAnimationManager::ActiveAnimationData m_oneOffAnimationData;
	std::unordered_map<enum ArkMaterialAnimationType,ArkMaterialAnimation const *,ArkMaterialAnimationManager::EnumClassHash,std::equal_to<enum ArkMaterialAnimationType>,std::allocator<std::pair<enum ArkMaterialAnimationType const ,ArkMaterialAnimation const *> > > m_animationsByType;
	ArkMaterialAnimationManager::ActiveAnimationData m_activeAnimationsByType[18];
	std::vector<MaterialParameterRamp> m_materialParameterRamps;

	ArkMaterialAnimationManager();
	~ArkMaterialAnimationManager();
	void StartAnimation(ArkMaterialAnimationType _animationType, float _blendInTime) { FStartAnimationOv1(this, _animationType, _blendInTime); }
	bool UpdateAnimation(ArkMaterialAnimationType _animationType, float _currentTime, float _elapsedTime) { return FUpdateAnimationOv1(this, _animationType, _currentTime, _elapsedTime); }
	bool UpdateAnimation(ArkMaterialAnimationManager::ActiveAnimationData& _animation, const ArkMaterialAnimation* _pMaterialAnim, float _currentTime, float _elapsedTime) { return FUpdateAnimationOv0(this, _animation, _pMaterialAnim, _currentTime, _elapsedTime); }
	void StartOneOffAnimation(float _blendInTime) { FStartOneOffAnimation(this, _blendInTime); }
	bool UpdateOneOffAnimation(float _currentTime, float _elapsedTime) { return FUpdateOneOffAnimation(this, _currentTime, _elapsedTime); }
	void StopOneOffAnimation() { FStopOneOffAnimation(this); }
	void UpdateMaterialParams(float _frameTime) { FUpdateMaterialParams(this, _frameTime); }
	float GetDuration(ArkMaterialAnimationType _animationType) const { return FGetDuration(this, _animationType); }
	void SimpleLerpAnimation(ArkMaterialAnimationType _animationType, float _lerpPercent) { FSimpleLerpAnimation(this, _animationType, _lerpPercent); }
	void Initialize(IEntity& _entity) { FInitializeOv1(this, _entity); }
	void Initialize(IEntity& _entity, const uint64_t _oneOffAnimation) { FInitializeOv0(this, _entity, _oneOffAnimation); }
	void ShutDown() { FShutDown(this); }
	void SetMaterialParameter(IMaterial* _pMaterial, EMaterialParamFloat _paramFloat, EMaterialParamVec3 _paramVec3, const char* _paramName, float _floatValue, const Vec3& _vectorValue, bool _bIsFloat, float _time) { FSetMaterialParameter(this, _pMaterial, _paramFloat, _paramVec3, _paramName, _floatValue, _vectorValue, _bIsFloat, _time); }
	const ArkMaterialAnimation* GetMaterialAnimationByType(ArkMaterialAnimationType _animationType) const { return FGetMaterialAnimationByType(this, _animationType); }
	IMaterial* GetUniqueMaterial(const ArkMaterialAnimation* _pMatAnim) { return FGetUniqueMaterial(this, _pMatAnim); }
	void ClearUniqueMaterial(const ArkMaterialAnimation* _pMatAnim) { FClearUniqueMaterial(this, _pMatAnim); }

#if 0
	void StartAnimation(ArkMaterialAnimationManager::ActiveAnimationData& _arg0_, const ArkMaterialAnimation* _arg1_, float _arg2_);
	void StopAnimation(ArkMaterialAnimationType _arg0_);
	void StopAllAnimations();
#endif

	static inline auto FArkMaterialAnimationManagerOv1 = PreyFunction<void(ArkMaterialAnimationManager* const _this)>(0x1215CA0);
	static inline auto FBitNotArkMaterialAnimationManager = PreyFunction<void(ArkMaterialAnimationManager* const _this)>(0x1215F60);
	static inline auto FStartAnimationOv1 = PreyFunction<void(ArkMaterialAnimationManager* const _this, ArkMaterialAnimationType _animationType, float _blendInTime)>(0x1217510);
	static inline auto FUpdateAnimationOv1 = PreyFunction<bool(ArkMaterialAnimationManager* const _this, ArkMaterialAnimationType _animationType, float _currentTime, float _elapsedTime)>(0x12177E0);
	static inline auto FUpdateAnimationOv0 = PreyFunction<bool(ArkMaterialAnimationManager* const _this, ArkMaterialAnimationManager::ActiveAnimationData& _animation, const ArkMaterialAnimation* _pMaterialAnim, float _currentTime, float _elapsedTime)>(0x1217620);
	static inline auto FStartOneOffAnimation = PreyFunction<void(ArkMaterialAnimationManager* const _this, float _blendInTime)>(0x12175A0);
	static inline auto FUpdateOneOffAnimation = PreyFunction<bool(ArkMaterialAnimationManager* const _this, float _currentTime, float _elapsedTime)>(0x1217AC0);
	static inline auto FStopOneOffAnimation = PreyFunction<void(ArkMaterialAnimationManager* const _this)>(0x1217610);
	static inline auto FUpdateMaterialParams = PreyFunction<void(ArkMaterialAnimationManager* const _this, float _frameTime)>(0x1217840);
	static inline auto FGetDuration = PreyFunction<float(const ArkMaterialAnimationManager* const _this, ArkMaterialAnimationType _animationType)>(0x12167E0);
	static inline auto FSimpleLerpAnimation = PreyFunction<void(ArkMaterialAnimationManager* const _this, ArkMaterialAnimationType _animationType, float _lerpPercent)>(0x1217120);
	static inline auto FInitializeOv1 = PreyFunction<void(ArkMaterialAnimationManager* const _this, IEntity& _entity)>(0x1216C50);
	static inline auto FInitializeOv0 = PreyFunction<void(ArkMaterialAnimationManager* const _this, IEntity& _entity, const uint64_t _oneOffAnimation)>(0x1216EE0);
	static inline auto FShutDown = PreyFunction<void(ArkMaterialAnimationManager* const _this)>(0x1217610);
	static inline auto FSetMaterialParameter = PreyFunction<void(ArkMaterialAnimationManager* const _this, IMaterial* _pMaterial, EMaterialParamFloat _paramFloat, EMaterialParamVec3 _paramVec3, const char* _paramName, float _floatValue, const Vec3& _vectorValue, bool _bIsFloat, float _time)>(0x1216F40);
	static inline auto FGetMaterialAnimationByType = PreyFunction<const ArkMaterialAnimation* (const ArkMaterialAnimationManager* const _this, ArkMaterialAnimationType _animationType)>(0x1216880);
	static inline auto FGetUniqueMaterial = PreyFunction<IMaterial* (ArkMaterialAnimationManager* const _this, const ArkMaterialAnimation* _pMatAnim)>(0x12168F0);
	static inline auto FClearUniqueMaterial = PreyFunction<void(ArkMaterialAnimationManager* const _this, const ArkMaterialAnimation* _pMatAnim)>(0x12163B0);
};
#endif // !MOONCRASH
