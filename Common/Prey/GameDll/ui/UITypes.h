#pragma once
#include <Prey/CryCore/Containers/CryListenerSet.h>

struct IUIControlSchemeListener;

typedef CListenerSet<IUIControlSchemeListener*> TUIControlSchemeListeners;
