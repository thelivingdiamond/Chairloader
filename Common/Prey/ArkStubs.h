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