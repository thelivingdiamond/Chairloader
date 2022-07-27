#pragma once

namespace detail
{

struct StubSmartPtrIface
{
	void Release();
};

}

struct IParticleEmitter : detail::StubSmartPtrIface {};
struct IParticleEffect : detail::StubSmartPtrIface {};