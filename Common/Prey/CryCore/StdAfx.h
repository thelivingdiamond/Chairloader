#pragma once
//
// The precompiled header file to be used by all ChairLoader mods
// to include important and common CryEngine headers.
//

#include <Prey/CryCore/Project/CryModuleDefs.h>
#define eCryModule   eCryM_Game

#include <Prey/CryCore/Platform/platform.h>

// C headers
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <ctime>

// Containers
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Utilities
#include <algorithm>
#include <functional>
#include <utility>
#include <memory>
#include <limits>
#include <optional>

// Threading
#include <mutex>
#include <condition_variable>
#include <thread>

// File system
#include <filesystem>
namespace fs = std::filesystem;

// Reference additional interface headers your program requires here (not local headers)

// Core
#include <ChairLoader/IChairLogger.h>
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CryMath/Random.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/IConsole.h>
#include <Prey/CrySystem/ITimer.h>

// Entities
#include <Prey/CryEntitySystem/IEntity.h>
#include <Prey/CryEntitySystem/IEntityProxy.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryAction/IGameObjectSystem.h>
