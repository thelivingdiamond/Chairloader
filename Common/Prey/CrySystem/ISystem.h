#pragma once
#include <cstdint>
#include <Prey/CrySystem/ITimer.h>
#include <Prey/CrySystem/IConsole.h>

enum ESystemEvent : __int32
{
	ESYSTEM_EVENT_RANDOM_SEED = 0x1,
	ESYSTEM_EVENT_RANDOM_ENABLE = 0x2,
	ESYSTEM_EVENT_RANDOM_DISABLE = 0x3,
	ESYSTEM_EVENT_CHANGE_FOCUS = 0xA,
	ESYSTEM_EVENT_MOVE = 0xB,
	ESYSTEM_EVENT_RESIZE = 0xC,
	ESYSTEM_EVENT_ACTIVATE = 0xD,
	ESYSTEM_EVENT_POS_CHANGED = 0xE,
	ESYSTEM_EVENT_STYLE_CHANGED = 0xF,
	ESYSTEM_EVENT_LEVEL_LOAD_START_PRELOADINGSCREEN = 0x10,
	ESYSTEM_EVENT_LEVEL_LOAD_RESUME_GAME = 0x11,
	ESYSTEM_EVENT_LEVEL_LOAD_PREPARE = 0x12,
	ESYSTEM_EVENT_LEVEL_LOAD_START_LOADINGSCREEN = 0x13,
	ESYSTEM_EVENT_LEVEL_LOAD_LOADINGSCREEN_ACTIVE = 0x14,
	ESYSTEM_EVENT_LEVEL_LOAD_START = 0x15,
	ESYSTEM_EVENT_LEVEL_LOAD_END = 0x16,
	ESYSTEM_EVENT_LEVEL_LOAD_ERROR = 0x17,
	ESYSTEM_EVENT_LEVEL_NOT_READY = 0x18,
	ESYSTEM_EVENT_LEVEL_PRECACHE_START = 0x19,
	ESYSTEM_EVENT_LEVEL_PRECACHE_CAMERA_READY = 0x1A,
	ESYSTEM_EVENT_LEVEL_PRECACHE_FIRST_FRAME = 0x1B,
	ESYSTEM_EVENT_LEVEL_GAMEPLAY_START = 0x1C,
	ESYSTEM_EVENT_LEVEL_UNLOAD = 0x1D,
	ESYSTEM_EVENT_LEVEL_POST_UNLOAD = 0x1E,
	ESYSTEM_EVENT_GAME_MATERIALS_UNLOADED = 0x1F,
	ESYSTEM_EVENT_GAME_CONTEXT_END_START = 0x20,
	ESYSTEM_EVENT_GAME_CONTEXT_END_DONE = 0x21,
	ESYSTEM_EVENT_TRANSITION_GAME_STATE_LOADED = 0x22,
	ESYSTEM_EVENT_GAME_POST_INIT = 0x23,
	ESYSTEM_EVENT_GAME_POST_INIT_DONE = 0x24,
	ESYSTEM_EVENT_FULL_SHUTDOWN = 0x25,
	ESYSTEM_EVENT_FAST_SHUTDOWN = 0x26,
	ESYSTEM_EVENT_LANGUAGE_CHANGE = 0x27,
	ESYSTEM_EVENT_TOGGLE_FULLSCREEN = 0x28,
	ESYSTEM_EVENT_SHARE_SHADER_COMBINATIONS = 0x29,
	ESYSTEM_EVENT_3D_POST_RENDERING_START = 0x2A,
	ESYSTEM_EVENT_3D_POST_RENDERING_END = 0x2B,
	ESYSTEM_EVENT_SWITCHING_TO_LEVEL_HEAP = 0x2C,
	ESYSTEM_EVENT_SWITCHED_TO_LEVEL_HEAP = 0x2D,
	ESYSTEM_EVENT_SWITCHING_TO_GLOBAL_HEAP = 0x2E,
	ESYSTEM_EVENT_SWITCHED_TO_GLOBAL_HEAP = 0x2F,
	ESYSTEM_EVENT_LEVEL_PRECACHE_END = 0x30,
	ESYSTEM_EVENT_GAME_MODE_SWITCH_START = 0x31,
	ESYSTEM_EVENT_GAME_MODE_SWITCH_END = 0x32,
	ESYSTEM_EVENT_VIDEO = 0x33,
	ESYSTEM_EVENT_GAME_PAUSED = 0x34,
	ESYSTEM_EVENT_GAME_RESUMED = 0x35,
	ESYSTEM_EVENT_TIME_OF_DAY_SET = 0x36,
	ESYSTEM_EVENT_EDITOR_ON_INIT = 0x37,
	ESYSTEM_EVENT_FRONTEND_INITIALISED = 0x38,
	ESYSTEM_EVENT_EDITOR_GAME_MODE_CHANGED = 0x39,
	ESYSTEM_EVENT_EDITOR_SIMULATION_MODE_CHANGED = 0x3A,
	ESYSTEM_EVENT_FRONTEND_RELOADED = 0x3B,
	ESYSTEM_EVENT_PLM_ON_RESUMING = 0x3C,
	ESYSTEM_EVENT_PLM_ON_SUSPENDING = 0x3D,
	ESYSTEM_EVENT_PLM_ON_CONSTRAINED = 0x3E,
	ESYSTEM_EVENT_PLM_ON_FULL = 0x3F,
	ESYSTEM_EVENT_PLM_ON_TERMINATED = 0x40,
	ESYSTEM_EVENT_PLM_ON_SUSPENDING_COMPLETED = 0x41,
	ESYSTEM_EVENT_CONTROLLER_REMOVED = 0x42,
	ESYSTEM_EVENT_CONTROLLER_ADDED = 0x43,
	ESYSTEM_EVENT_STREAMING_INSTALL_ERROR = 0x44,
	ESYSTEM_EVENT_ONLINE_SERVICES_INITIALISED = 0x45,
	ESYSTEM_EVENT_AUDIO_IMPLEMENTATION_LOADED = 0x46,
	ESYSTEM_EVENT_USER = 0x1000,
	ESYSTEM_EVENT_CRYSYSTEM_INIT_DONE = 0x1001,
	ESYSTEM_EVENT_ENTITY_UNLOAD = 0x1002,
	ESYSTEM_EVENT_LOAD_SAVE_STARTED = 0x1003,
	ESYSTEM_EVENT_QUICKLOAD_SAVE_FINISHED = 0x1004,
};

struct ISystemEventListener
{
	virtual ~ISystemEventListener() {}
	virtual void OnSystemEvent(ESystemEvent event, uintptr_t wparam, uintptr_t lparam) = 0;
};

struct SSystemGlobalEnvironment;
extern SSystemGlobalEnvironment *gEnv;

#define CVARHELP(_comment) _comment

//! Preferred way to register a CVar
#define REGISTER_CVAR(_var, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(( # _var), &(_var), (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register a CVar with a callback
#define REGISTER_CVAR_CB(_var, _def_val, _flags, _comment, _onchangefunction) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(( # _var), &(_var), (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register a string CVar
#define REGISTER_STRING(_name, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->RegisterString(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register a string CVar with a callback
#define REGISTER_STRING_CB(_name, _def_val, _flags, _comment, _onchangefunction) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->RegisterString(_name, (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register an int CVar
#define REGISTER_INT(_name, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->RegisterInt(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register an int CVar with a callback
#define REGISTER_INT_CB(_name, _def_val, _flags, _comment, _onchangefunction) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->RegisterInt(_name, (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register an int64 CVar
#define REGISTER_INT64(_name, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->RegisterInt64(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register a float CVar
#define REGISTER_FLOAT(_name, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->RegisterFloat(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Offers more flexibility but more code is required
#define REGISTER_CVAR2(_name, _var, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(_name, _var, (_def_val), (_flags), CVARHELP(_comment)))

//! Offers more flexibility but more code is required
#define REGISTER_CVAR2_CB(_name, _var, _def_val, _flags, _comment, _onchangefunction) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(_name, _var, (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Offers more flexibility but more code is required, explicit address taking of destination variable
#define REGISTER_CVAR3(_name, _var, _def_val, _flags, _comment) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(_name, &(_var), (_def_val), (_flags), CVARHELP(_comment)))

//! Offers more flexibility but more code is required, explicit address taking of destination variable
#define REGISTER_CVAR3_CB(_name, _var, _def_val, _flags, _comment, _onchangefunction) (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(_name, &(_var), (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register a console command
#define REGISTER_COMMAND(_name, _func, _flags, _comment) (gEnv->pConsole == 0 ? (void)0 : gEnv->pConsole->AddCommand(_name, _func, (_flags), CVARHELP(_comment)))
