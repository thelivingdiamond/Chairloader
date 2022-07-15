#pragma once
#include "Mannequin.h"

enum class EActionFailure : __int32
{
    AF_QueueFull = 0x0,
    AF_InvalidContext = 0x1,
};
enum class EPriorityComparison : __int32
{
    Lower = 0x0,
    Equal = 0x1,
    Higher = 0x2,
};
template<int32_t s> class STagState {
    unsigned char state[s];
};
class IScope;
class SAnimationContext;
class IProceduralClip;
class IProceduralParams;
class AnimEventInstance;
class IAction
{
public:
    enum EStatus
    {
        None = 0,
        Pending = 1,
        Installed = 2,
        Exiting = 3,
        Finished = 4
    };
    enum EFlags
    {
        BlendOut = 1,
        NoAutoBlendOut = 2,
        Interruptable = 4,
        Installing = 16,
        Started = 32,
        Requeued = 64,
        TrumpSelf = 128,
        Transitioning = 256,
        PlayingFragment = 512,
        TransitioningOut = 1024,
        TransitionPending = 2048,
        FragmentIsOneShot = 4096,
        Stopping = 8192,
        OverrideBlendIn = 16384,
        OverrideBlendOut = 32768,
        PlaybackStateMask = 1792
    };
    virtual ~IAction() = 0;
    virtual void Install() = 0;
    virtual void Enter() = 0;
    virtual void Fail(EActionFailure) = 0;
    virtual void Exit() = 0;
    virtual IAction::EStatus UpdatePending(float) = 0;
    virtual IAction::EStatus Update(float) = 0;
    virtual void OnResolveActionInstallations() = 0;
    virtual EPriorityComparison ComparePriority(const IAction*) = 0;
    virtual void OnRequestBlendOut(EPriorityComparison) = 0;
    virtual void OnSequenceFinished(int, unsigned int) = 0;
    virtual IAction* CreateSlaveAction(int, const STagState<12>*, SAnimationContext*) = 0;
    virtual void OnTransitionStarted() = 0;
    virtual void OnFragmentStarted() = 0;
    virtual void OnTransitionOutStarted() = 0;
    virtual void OnInitialise() = 0;
    virtual void OnActionFinished() = 0;
    virtual void OnEvent(const SGameObjectEvent*) = 0;
    virtual void OnAnimationEvent(ICharacterInstance*, const AnimEventInstance*) = 0;
    virtual void OnActionEvent(const unsigned int) = 0;
    virtual void OnProceduralClipBegin(IProceduralClip*, unsigned int) = 0;
    virtual void OnProceduralClipEnd(IProceduralClip*, unsigned int) = 0;
    virtual void OnCustomActionEvent(const unsigned int, IProceduralClip*, const IProceduralParams*) = 0;
    virtual bool GetBlendInOverride(int, float*) = 0;
    virtual bool GetBlendOutOverride(int, float*) = 0;
    virtual const char* GetName() = 0;
    virtual void DoDelete() = 0;


    SAnimationContext* m_context;
    float m_activeTime;
    float m_queueTime;
    unsigned int m_forcedScopeMask;
    unsigned int m_installedScopeMask;
    int m_subContext;
    int m_priority;
    IAction::EStatus m_eStatus;
    unsigned int m_flags;
    IScope* m_rootScope;
    int m_fragmentID;
    STagState<12> m_fragTags;
    unsigned int m_optionIdx;
    unsigned int m_userToken;
    int m_refCount;
    float m_speedBias;
    float m_animWeight;
    CMannequinParams m_mannequinParams;
    DynArray<_smart_ptr<IAction>, int, NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > m_slaveActions;
};
template <typename T> class TAction : public IAction {

};