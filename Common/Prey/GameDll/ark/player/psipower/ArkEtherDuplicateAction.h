// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkMaterialAnimation;
struct IMaterial;

// ArkEtherDuplicateMaterialAnimation
// Header:  Prey/GameDll/ark/player/psipower/ArkEtherDuplicateAction.h
class ArkEtherDuplicateMaterialAnimation
{ // Size=24 (0x18)
public:
	_smart_ptr<IMaterial> m_pMaterial;
	const ArkMaterialAnimation* m_pMaterialAnimation;
	float m_elapsedSec;
	int m_keyFrameIndex;

	void Update(const float _frameTime) { FUpdate(this, _frameTime); }

#if 0
	ArkEtherDuplicateMaterialAnimation();
	ArkEtherDuplicateMaterialAnimation(IMaterial* _arg0_, const ArkMaterialAnimation* _arg1_);
	void Serialize(TSerialize _arg0_);
	int GetKeyFrameStartIndex() const;
#endif

	static inline auto FUpdate = PreyFunction<void(ArkEtherDuplicateMaterialAnimation* const _this, const float _frameTime)>(0x146BD70);
};

// ArkEtherDuplicateAction
// Header:  Prey/GameDll/ark/player/psipower/ArkEtherDuplicateAction.h
class ArkEtherDuplicateAction : public TAction<SAnimationContext>
{ // Size=168 (0xA8)
public:
	using BaseType = TAction<SAnimationContext>;

	ArkEtherDuplicateMaterialAnimation m_materialAnimation;
	const char* m_pGravityTag;
	const char* m_pDirectionTag;

	ArkEtherDuplicateAction(const char* _pGravityTag, const char* _pDirectionTag, IMaterial* _pMaterial, const ArkMaterialAnimation* _pMaterialAnimation);
	virtual ~ArkEtherDuplicateAction();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnInitialise();
	virtual IAction::EStatus Update(const float _frameTime);

#if 0
	ArkEtherDuplicateAction();
#endif

	static inline auto FArkEtherDuplicateActionOv0 = PreyFunction<void(ArkEtherDuplicateAction* const _this, const char* _pGravityTag, const char* _pDirectionTag, IMaterial* _pMaterial, const ArkMaterialAnimation* _pMaterialAnimation)>(0x146B880);
	static inline auto FSerialize = PreyFunction<void(ArkEtherDuplicateAction* const _this, TSerialize _ser)>(0x146BC20);
	static inline auto FOnInitialise = PreyFunction<void(ArkEtherDuplicateAction* const _this)>(0x146BB20);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkEtherDuplicateAction* const _this, const float _frameTime)>(0x146BD30);
};

