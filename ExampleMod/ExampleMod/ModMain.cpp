#include "ModMain.h"

ModMain* gMod = nullptr;

#ifdef EXAMPLE
// You can define PreyDll.dll function using PreyFunction
// auto fnFuncName = PreyFunction<void(T funcArgs)>(functionOffset);
// Many functions are defined as static members with F prefix:
//  ArkPlayer.h
//     static inline auto FHasAbility = PreyFunction<bool(ArkPlayer* _this, uint64_t _abilityID)>(0x1550330);
static auto fn_ArkPlayer_HasAbility = PreyFunction<bool(ArkPlayer* _this, uint64_t _abilityID)>(0x1550330);

// Use MakeHook() method of PreyFunction to create a hook.
// See ModMain::InitHooks for more.
static auto s_hook_ArkPlayer_HasAbility = fn_ArkPlayer_HasAbility.MakeHook();

// This function will be called in place of ArkPlayer::HasAbility.
// See ModMain::InitHooks for more.
static bool ArkPlayer_HasAbility_Hook(ArkPlayer* _this, uint64_t _abilityID)
{
	// NOTE: This particular method of ability unlocking is unreliable.
	// NOTE: It's only used as an example of function hooking.

	if (_abilityID % 2 == 0)
	{
		// Player always has abilities whose ID is even.
		return true;
	}

	// Use InvokeOrig of PreyFunctionHook to call the original (non-hooked) function.
	return s_hook_ArkPlayer_HasAbility.InvokeOrig(_this, _abilityID);
}

#endif

std::string ModMain::GetModName()
{
	return "ExampleMod"; // CHANGE ME
}

void ModMain::InitHooks()
{
#ifdef EXAMPLE
	// Functions hooks are intalled early into mod loading process,
	// before any engine subsystem is initialized.
	// But for hook to succeed PreyFunctionHook needs to know the hook function
	// (that will be called in place of original one)
	// That's why ModMain::InitHooks exists.
	// Call SetHookFunc from here.
	s_hook_ArkPlayer_HasAbility.SetHookFunc(&ArkPlayer_HasAbility_Hook);
#endif
}

void ModMain::InitSystem(ISystem* pSystem, uintptr_t moduleBase)
{
	BaseClass::InitSystem(pSystem, moduleBase);
	// Your code goes here
}

void ModMain::InitGame(IGameFramework* pFramework, IChairloader* chairloader)
{
	BaseClass::InitGame(pFramework, chairloader);
	// Your code goes here
}

void ModMain::Draw()
{
	if (ImGui::Begin("Example Mod"))
	{
		static bool state = false;
		const char* text = !state ? "That Heavy is dead!" : "Yes! He died!";
		ImGui::Text(text);

		if (ImGui::Button("The heavy is dead???"))
		{
			state = !state;
		}
	}

	ImGui::End();
}

void ModMain::PreUpdate()
{
	// Your code goes here
}

void ModMain::PostUpdate()
{
	// Your code goes here
}

void ModMain::ShutdownGame()
{
	// Your code goes here
	BaseClass::ShutdownGame();
}

void ModMain::ShutdownSystem()
{
	// Your code goes here
	BaseClass::ShutdownSystem();
}

extern "C" DLL_EXPORT IChairloaderMod* ClMod_Initialize()
{
	CRY_ASSERT(!gMod);
	gMod = new ModMain();
	return gMod;
}

extern "C" DLL_EXPORT void ClMod_Shutdown()
{
	CRY_ASSERT(gMod);
	delete gMod;
	gMod = nullptr;
}

// Validate that declarations haven't changed
static_assert(std::is_same_v<decltype(ClMod_Initialize), IChairloaderMod::ProcInitialize>);
static_assert(std::is_same_v<decltype(ClMod_Shutdown), IChairloaderMod::ProcShutdown>);
