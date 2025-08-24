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

#ifdef EXAMPLE
// Mod Interface Example
// Define an interface like this in a header file.
// Then inherit ModMain from that interface.
struct IModName : public IModInterface
{
    static constexpr char IFACE_NAME[] = "IModName001";
    static constexpr int VERSION = 1;

    virtual int GetInterfaceVersion() = 0;

    //! Does something mod-specific.
    virtual void ExampleMethod() = 0;
};
#endif


//---------------------------------------------------------------------------------
// Mod Initialization
//---------------------------------------------------------------------------------
void ModMain::FillModInfo(ModDllInfoEx& info)
{
    info.modName = "TheChair.ExampleMod"; // CHANGE ME
    info.logTag = "ExampleMod"; // CHANGE ME
    info.supportsHotReload = true; // TODO: Add comment/wiki link
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

void ModMain::InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo)
{
    BaseClass::InitSystem(initInfo, dllInfo);
    // Your code goes here
    
    //! CVar example
#ifdef EXAMPLE
    // If you want to store variables between restarts, use a CVar with the DUMPTOCHAIR flag.
    // This will save the value to a file, and the value will be restored on launch.
    // Cvars can be changed with the console, or by simply changing the variable in code.
    // A great example would be storing whether a window is open or not.
    // You will typically use the macros REGISTER_CVAR(...) or REGISTER_CVAR2(...) to register a CVar.
    // See Common/Prey/CrySystem/IConsole.h for the documentation on CVars

    //! Best used for simple user preferences. For more complex data, You will need to use an actual config file.
    static int m_bDoSomething = false;
    REGISTER_CVAR2("ExampleMod.DoSomething", &m_bDoSomething, 0, VF_DUMPTOCHAIR, "ExampleMod.DoSomething");
#endif
}

void ModMain::InitGame(bool isHotReloading)
{
    BaseClass::InitGame(isHotReloading);
    // Your code goes here
}

//---------------------------------------------------------------------------------
// Mod Shutdown
//---------------------------------------------------------------------------------
void ModMain::ShutdownGame(bool isHotUnloading)
{
    // Your code goes here
    BaseClass::ShutdownGame(isHotUnloading);
}

void ModMain::ShutdownSystem(bool isHotUnloading)
{
    // Your code goes here
    BaseClass::ShutdownSystem(isHotUnloading);
}

//---------------------------------------------------------------------------------
// GUI
//---------------------------------------------------------------------------------
void ModMain::Draw()
{
    // Modders, please move to a method, it's just an example
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Example Mod"))
        {
            ImGui::MenuItem("An example of how to add tabs to the menu bar.");
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

    if (ImGui::Begin("Example Mod"))
    {
        static bool state = false;
        static time_t loadTime = std::time(nullptr);
        const char* text = !state ? "That Heavy is dead!" : "Yes! He died!";
        ImGui::Text("%s", text);
        ImGui::Text("Load time: %lld", (long long)loadTime);

        if (ImGui::Button("The Heavy is dead???"))
        {
            state = !state;
        }
    }

    ImGui::End();
}

//---------------------------------------------------------------------------------
// Main Update Loop
//---------------------------------------------------------------------------------
void ModMain::MainUpdate(unsigned updateFlags)
{
    // Your code goes here
}

//---------------------------------------------------------------------------------
// Mod Interfacing
//---------------------------------------------------------------------------------
#ifdef EXAMPLE
void *ModMain::QueryInterface(const char *ifaceName)
{
    // This function is called by other mods to get interfaces.
    // Check if you implement the interface. If so, return a pointer to it.
    // This example assumes ModMain inherits from the interface class. You may choose a different object if you want.
    if (!strcmp(ifaceName, IModName::IFACE_NAME))
        return static_cast<IModName*>(this);

    return nullptr;
}

void ModMain::Connect(const std::vector<IChairloaderMod *> &mods)
{
    IModName* pModName = nullptr; // Add this to ModMain

    // You can use one of these helper functions. They will handle finding and version checking.
    pModName = GetInterfaceFromModList<IModName>(mods, "Other Mod Name");
    pModName = GetRequiredInterfaceFromModList<IModName>(mods, "Other Mod Name");
}
#endif

//---------------------------------------------------------------------------------
// Exported Functions
//---------------------------------------------------------------------------------
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
