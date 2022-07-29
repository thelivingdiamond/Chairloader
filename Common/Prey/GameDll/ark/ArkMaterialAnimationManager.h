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

