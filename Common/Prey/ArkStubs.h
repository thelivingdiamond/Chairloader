#pragma once
#include <Prey/GameDll/ark/ui/IUIEventListener.h>
// Mannequin types are defined in <Prey/CryAction/ICryMannequin.h>. Only forward-declared here: this PCH
// header can be reached from ISystem.h before gEnv is declared.
class IAction;
template<class CONTEXT> class TAction;
class CFragmentCache;
struct SMannequinItemParams;

namespace detail
{

struct StubSmartPtrIface
{
	void Release() {};
	void AddRef() {};
};

}

#include <Prey/CryRenderer/IRenderMesh.h> // replaces the former IRenderMesh stub (StubSmartPtrIface)

struct SAnimationContext;

template <typename T>
class ArkFlowNodeDialogTrigger;

struct IMaterial : detail::StubSmartPtrIface {};
struct ISaveGameThumbnail : detail::StubSmartPtrIface {};
struct SCrySessionID : detail::StubSmartPtrIface {};

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

// Header: MadeUp
// _unknown/ArkMaterialParamOverride.h
class ArkMaterialParamOverride // Id=8015FEF Size=16
{
public:
	string m_paramName;
	float m_paramValue;
};

struct IUIEventDispatchFct;

template <typename T>
struct SUIEventReceiverDispatcher : public IUIEventListener // Id=8005C4D Size=40
{
	using TFunctionMap = std::map<unsigned int, IUIEventDispatchFct*>;

	TFunctionMap mFunctionMap;
	IUIEventSystem* m_pEventSystem;
	T* m_pThis;

	virtual SUIArguments OnEvent(SUIEvent const& arg0);
	virtual void OnEventSystemDestroyed(IUIEventSystem* arg0);
};

template <typename T>
struct SUIEventSenderDispatcher // Id=801BBBE Size=24
{
	using TEventMap = std::map<T, unsigned int>;

	TEventMap m_EventMap;
	IUIEventSystem* m_pEventSystem;

#if 0
	void Init(IUIEventSystem* arg0);
#endif
};


class ArkOffMeshLinkHelper
{
	void* pad[6];
};

template<ENavigationIDTag T>
struct TNavigationID
{
	uint32 id;
};

