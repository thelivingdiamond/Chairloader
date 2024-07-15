#pragma once
#include <Prey/GameDll/ark/ui/IUIEventListener.h>

namespace detail
{

struct StubSmartPtrIface
{
	void Release() {};
	void AddRef() {};
};

}

struct SAnimationContext;

template <typename T>
class [[sv::ignore]] ArkFlowNodeDialogTrigger;

struct [[sv::ignore]] IMaterial : detail::StubSmartPtrIface {};
struct [[sv::ignore]] ISaveGameThumbnail : detail::StubSmartPtrIface {};
struct [[sv::ignore]] SCrySessionID : detail::StubSmartPtrIface {};
struct [[sv::ignore]] IRenderMesh : detail::StubSmartPtrIface {};

class [[sv::ignore]] IAction : public detail::StubSmartPtrIface
{
public:
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

using ArkMaterialAnimationChannel = EMaterialParamFloat;

struct [[sv::ignore]] ArkMaterialAnimationKeyframe // Id=8014239 Size=36
{
	int m_subMaterialSlot;
	ArkMaterialAnimationChannel m_channel;
	float m_keyTime;
	float m_timeToNextKey;
	float m_floatValue;
	Vec3 m_vectorValue;
	bool m_bIsFloat;
};

struct [[sv::ignore]] MaterialParameterRamp {
	void* pad[9];
};

template<class CONTEXT>
class [[sv::ignore]] TAction : public IAction
{
};

// Header: Exact
// CryEngine/cryaction/icrymannequin.h
class [[sv::ignore]] CFragmentCache // Id=8004878 Size=72
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

// Header: MadeUp
// _unknown/ArkMaterialParamOverride.h
class [[sv::ignore]] ArkMaterialParamOverride // Id=8015FEF Size=16
{
public:
	string m_paramName;
	float m_paramValue;
};

struct IUIEventDispatchFct;

template <typename T>
struct [[sv::ignore]] SUIEventReceiverDispatcher : public IUIEventListener // Id=8005C4D Size=40
{
	using TFunctionMap = std::map<unsigned int, IUIEventDispatchFct*>;

	TFunctionMap mFunctionMap;
	IUIEventSystem* m_pEventSystem;
	T* m_pThis;

	virtual SUIArguments OnEvent(SUIEvent const& arg0);
	virtual void OnEventSystemDestroyed(IUIEventSystem* arg0);
};

template <typename T>
struct [[sv::ignore]] SUIEventSenderDispatcher // Id=801BBBE Size=24
{
	using TEventMap = std::map<T, unsigned int>;

	TEventMap m_EventMap;
	IUIEventSystem* m_pEventSystem;

#if 0
	void Init(IUIEventSystem* arg0);
#endif
};

struct [[sv::ignore]] SMannequinItemParams
{
	struct FragmentIDs;
	struct TagIDs;
	struct TagGroupIDs;
	struct ContextIDs;
	struct Fragments;
};

class [[sv::ignore]] ArkOffMeshLinkHelper
{
	void* pad[6];
};

template<ENavigationIDTag T>
struct [[sv::ignore]] TNavigationID
{
	uint32 id;
};

class [[sv::ignore]] ArkNpcMovementDesire
{
	void* pad[30];
};
