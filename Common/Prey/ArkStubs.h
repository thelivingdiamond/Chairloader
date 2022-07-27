#pragma once

namespace detail
{

struct StubSmartPtrIface
{
	void Release();
};

}

struct SAnimationContext;

template <typename T>
class ArkFlowNodeDialogTrigger;

struct IParticleEmitter : detail::StubSmartPtrIface {};
struct IParticleEffect : detail::StubSmartPtrIface {};
struct IMaterial : detail::StubSmartPtrIface {};

struct IAction : detail::StubSmartPtrIface
{
	enum class EStatus
	{
		None = 0,
		Pending = 1,
		Installed = 2,
		Exiting = 3,
		Finished = 4,
	};

	void* pad[15];
};

struct IParticleEffectListener // Id=8001CCA Size=8
{
	virtual ~IParticleEffectListener();
	virtual void OnCreateEmitter(IParticleEmitter* arg0) = 0;
	virtual void OnDeleteEmitter(IParticleEmitter* arg0) = 0;
};

using ArkMaterialAnimationChannel = EMaterialParamFloat;

struct ArkMaterialAnimationKeyframe // Id=8014239 Size=36
{
	int m_subMaterialSlot;
	ArkMaterialAnimationChannel m_channel;
	float m_keyTime;
	float m_timeToNextKey;
	float m_floatValue;
	Vec3 m_vectorValue;
	bool m_bIsFloat;
};

struct MaterialParameterRamp {
	void* pad[9];
};

template<class CONTEXT>
class TAction : public IAction
{
};

// Header: Exact
// CryEngine/cryaction/icrymannequin.h
class CFragmentCache // Id=8004878 Size=72
{
public:
	struct SCacheAnims // Id=8004879 Size=4
	{
		unsigned m_crc;
	};

	struct FPredNotLoaded // Id=800487A Size=1
	{
	};

	using TAnimsCached = std::vector<CFragmentCache::SCacheAnims>;

	void* pad[9];
};

// Header: Exact
// CryEngine/cryanimation/facialanimation/faceeffector.h
class ArkPlayerAttentionObject // Id=8016E5B Size=48
{
	void* pad[6];
};

// Header: MadeUp
// _unknown/ArkMaterialParamOverride.h
class ArkMaterialParamOverride // Id=8015FEF Size=16
{
public:
	string m_paramName;
	float m_paramValue;
};
