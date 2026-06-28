// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
struct IEntity;
struct IGameObject;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkTelescope.h
class ArkTelescope : public ArkEnvironmentalObject, public IArkPlayerInteractionListener // Id=8019736 Size=160
{
public:
	QuatT m_cameraInterpTarget;
	QuatT m_cameraStablePosition;
	float m_cameraStableFOV;
	
	virtual ~ArkTelescope();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void LoadProperties();
	
#if 0
	QuatT GetCameraInterpTarget() const;
	QuatT GetCameraStablePosition() const;
	float GetCameraStableFOV() const;
#endif
	
	static inline auto FPostInit = PreyFunction<void(ArkTelescope *const _this, IGameObject *_pGameObject)>(0x11BB1E0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkTelescope *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x11BB1B0);
	static inline auto FTestInteraction = PreyFunction<bool(ArkTelescope const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x11BB220);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkTelescope const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x11BB1D0);
	static inline auto FLoadProperties = PreyFunction<void(ArkTelescope *const _this)>(0x11BAEB0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
struct IEntity;
struct IGameObject;

// ArkTelescope
// Header:  Prey/GameDll/ark/environment/ArkTelescope.h
class ArkTelescope : public ArkEnvironmentalObject, public IArkPlayerInteractionListener
{ // Size=160 (0xA0)
public:
	QuatT m_cameraInterpTarget;
	QuatT m_cameraStablePosition;
	float m_cameraStableFOV;

	virtual ~ArkTelescope();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual void LoadProperties();

#if 0
	ArkTelescope();
	QuatT GetCameraInterpTarget() const;
	QuatT GetCameraStablePosition() const;
	float GetCameraStableFOV() const;
#endif

	static inline auto FPostInit = PreyFunction<void(ArkTelescope* const _this, IGameObject* _pGameObject)>(0x123CAA0);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x123CA70);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x123CAE0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x123CA90);
	static inline auto FLoadProperties = PreyFunction<void(ArkTelescope* const _this)>(0x123C770);
};
#endif // !MOONCRASH
