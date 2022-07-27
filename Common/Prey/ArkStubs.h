#pragma once

namespace detail
{

struct StubSmartPtrIface
{
	void Release();
};

}

template <typename T>
class ArkFlowNodeDialogTrigger;

struct IParticleEmitter : detail::StubSmartPtrIface {};
struct IParticleEffect : detail::StubSmartPtrIface {};

struct IParticleEffectListener // Id=8001CCA Size=8
{
	virtual ~IParticleEffectListener();
	virtual void OnCreateEmitter(IParticleEmitter* arg0) = 0;
	virtual void OnDeleteEmitter(IParticleEmitter* arg0) = 0;
};
