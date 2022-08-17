
#include <Prey/CryCore/StlUtils.h>
#include <Prey/Cry3DEngine/CryPodArray.h>
#include <Prey/CryMath/Cry_Vector3.h>
#include <Prey/CryMath/Cry_Quat.h>
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryMemory/STLAlignedAlloc.h>
template <typename T> class CListenerSet// Size=0x28 (Id=16460)
{
public:
    struct ListenerRecord// Size=0x8 (Id=1707282)
    {
        T * m_pListener;// Offset=0x0 Size=0x8
    };
    std::vector<ListenerRecord> m_listeners;// Offset=0x0 Size=0x18
    unsigned m_activeNotifications;// Offset=0x18 Size=0x8
    bool m_cleanupRequired;// Offset=0x20 Size=0x1
    bool m_freeMemOnCleanup;// Offset=0x21 Size=0x1
    char pad[6];
};
static_assert(sizeof(CListenerSet<int*>) == 0x28, "Size of CListenerSet is wrong");
