// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ICryMannequin.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/arketherduplicateaction.h>

class ArkMaterialAnimation;
struct IMaterial;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arketherduplicateaction.h
class ArkEtherDuplicateMaterialAnimation // Id=801930D Size=24
{
public:
	_smart_ptr<IMaterial> m_pMaterial;
	ArkMaterialAnimation const *m_pMaterialAnimation;
	float m_elapsedSec;
	int m_keyFrameIndex;
	
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	
#if 0
	void Serialize(TSerialize arg0);
	int GetKeyFrameStartIndex() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkEtherDuplicateMaterialAnimation *const _this, const float _frameTime)>(0x146BD70);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkEtherDuplicateAction.h
class ArkEtherDuplicateAction : public TAction<SAnimationContext> // Id=801930C Size=168
{
public:
	using BaseType = TAction<SAnimationContext>;
	
	ArkEtherDuplicateMaterialAnimation m_materialAnimation;
	const char *m_pGravityTag;
	const char *m_pDirectionTag;
	
	ArkEtherDuplicateAction(const char *_pGravityTag, const char *_pDirectionTag, IMaterial *_pMaterial, ArkMaterialAnimation const *_pMaterialAnimation);
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	virtual void OnInitialise();
	virtual IAction::EStatus Update(const float _frameTime);
	
	static inline auto FSerialize = PreyFunction<void(ArkEtherDuplicateAction *const _this, TSerialize _ser)>(0x146BC20);
	static inline auto FOnInitialise = PreyFunction<void(ArkEtherDuplicateAction *const _this)>(0x146BB20);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(ArkEtherDuplicateAction *const _this, const float _frameTime)>(0x146BD30);
};

