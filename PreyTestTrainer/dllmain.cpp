// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <string>
#include "mem.h"
#include "preyFunctions.h"
#include "proc.h"
#include "preyDllObjects.h"
#include "preyFunctions.h"
#include "ChairloaderUtils.h"
// #include "ArkEntityArchetypeLibrary.h
#include <thread>
#include <queue>
#include <stack>
#include <algorithm>
#if _WIN32 || _WIN64
#if _WIN64
#define ENV64BIT
#else
#define ENV32BIT
#endif
#endif
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

// #include "pugixml.hpp"
// D3X HOOK DEFINITIONS
typedef HRESULT(__fastcall* IDXGISwapChainPresent)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef void(__stdcall* ID3D11DrawIndexed)(ID3D11DeviceContext* pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
// Definition of WndProc Hook. Its here to avoid dragging dependencies on <windows.h> types.
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main D3D11 Objects
ID3D11DeviceContext* pContext = NULL;
ID3D11Device* pDevice = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
static IDXGISwapChain* pSwapChain = NULL;
static WNDPROC OriginalWndProcHandler = nullptr;
HWND window = nullptr;
IDXGISwapChainPresent fnIDXGISwapChainPresent;

// Boolean
BOOL g_bInitialised = false;
bool g_ShowMenu = false;
bool g_PresentHooked = false;

// Gui variables
float my_color[4];
const float TEXT_BASE_WIDTH = ImGui::CalcTextSize("A").x;
const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();


// GUI DRAWING FUNCTIONS
LRESULT CALLBACK hWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    ImGuiIO& io = ImGui::GetIO();
    POINT mPos;
    GetCursorPos(&mPos);
    ScreenToClient(window, &mPos);
    ImGui::GetIO().MousePos.x = mPos.x;
    ImGui::GetIO().MousePos.y = mPos.y;

    // if (uMsg == WM_KEYUP)
    // {
    //     if (wParam == VK_INSERT)
    //     {
    //         g_ShowMenu = !g_ShowMenu;
    //     }
    //
    // }

    if (g_ShowMenu && GetForegroundWindow() == window)
    {
            ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
            return true;
    }

    return CallWindowProc(OriginalWndProcHandler, hWnd, uMsg, wParam, lParam);
}
HRESULT GetDeviceAndCtxFromSwapchain(IDXGISwapChain* pSwapChain, ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext)
{
    HRESULT ret = pSwapChain->GetDevice(__uuidof(ID3D11Device), (PVOID*)ppDevice);

    if (SUCCEEDED(ret))
        (*ppDevice)->GetImmediateContext(ppContext);

    return ret;
}
void drawGUI(bool* bShow);

HRESULT __fastcall Present(IDXGISwapChain* pChain, UINT SyncInterval, UINT Flags)
{
    if (!g_bInitialised) {
        g_PresentHooked = true;
        std::cout << "\t[+] Present Hook called by first time" << std::endl;
        if (FAILED(GetDeviceAndCtxFromSwapchain(pChain, &pDevice, &pContext)))
            return fnIDXGISwapChainPresent(pChain, SyncInterval, Flags);
        pSwapChain = pChain;
        DXGI_SWAP_CHAIN_DESC sd;
        pChain->GetDesc(&sd);
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        window = sd.OutputWindow;

        //Set OriginalWndProcHandler to the Address of the Original WndProc function
        OriginalWndProcHandler = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)hWndProc);



        ImGui_ImplWin32_Init(window);
        ImGui_ImplDX11_Init(pDevice, pContext);
        ImGui::GetIO().ImeWindowHandle = window;

        ID3D11Texture2D* pBackBuffer;

        pChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
        pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
        pBackBuffer->Release();

        g_bInitialised = true;
    }
    ImGui_ImplWin32_NewFrame();
    ImGui_ImplDX11_NewFrame();

    ImGui::NewFrame();
    //Menu is displayed when g_ShowMenu is TRUE
    
    if (g_ShowMenu)
    {
        bool bShow = true;
        ImGui::ShowDemoWindow(&bShow);
        drawGUI(&bShow);
    }
    ImGui::EndFrame();

    ImGui::Render();
    pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return fnIDXGISwapChainPresent(pChain, SyncInterval, Flags);
}


void detourDirectXPresent()
{
    std::cout << "[+] Calling fnIDXGISwapChainPresent Detour" << std::endl;
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    // Detours the original fnIDXGISwapChainPresent with our Present
    DetourAttach(&(LPVOID&)fnIDXGISwapChainPresent, (PBYTE)Present);
    DetourTransactionCommit();
}

void killDetourDirectX() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(LPVOID&)fnIDXGISwapChainPresent, (PBYTE)Present);
    DetourTransactionCommit();
}
// void detourDirectXDrawIndexed()
// {
//     std::cout << "[+] Calling fnID3D11DrawIndexed Detour" << std::endl;
//     DetourTransactionBegin();
//     DetourUpdateThread(GetCurrentThread());
//     // Detours the original fnIDXGISwapChainPresent with our Present fnID3D11DrawIndexed, (PBYTE)hookD3D11DrawIndexed
//     DetourAttach(&(LPVOID&)fnID3D11DrawIndexed, (PBYTE)hookD3D11DrawIndexed);
//     DetourTransactionCommit();
// }

void retrieveValues()
{
    DWORD_PTR hDxgi = (DWORD_PTR)GetModuleHandle(L"dxgi.dll");
#if defined(ENV64BIT)
    fnIDXGISwapChainPresent = (IDXGISwapChainPresent)((DWORD_PTR)hDxgi + 0x5070);
#elif defined (ENV32BIT)
    fnIDXGISwapChainPresent = (IDXGISwapChainPresent)((DWORD_PTR)hDxgi + 0x10230);
#endif
    std::cout << "[+] Present Addr: " << std::hex << fnIDXGISwapChainPresent << std::endl;
}

void printValues()
{
    std::cout << "[+] ID3D11DeviceContext Addr: " << std::hex << pContext << std::endl;
    std::cout << "[+] ID3D11Device Addr: " << std::hex << pDevice << std::endl;
    std::cout << "[+] ID3D11RenderTargetView Addr: " << std::hex << mainRenderTargetView << std::endl;
    std::cout << "[+] IDXGISwapChain Addr: " << std::hex << pSwapChain << std::endl;
}

LRESULT CALLBACK DXGIMsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(hwnd, uMsg, wParam, lParam); }

void GetPresent()
{
    WNDCLASSEXA wc = { sizeof(WNDCLASSEX), CS_CLASSDC, DXGIMsgProc, 0L, 0L, GetModuleHandleA(NULL), NULL, NULL, NULL, NULL, "DX", NULL };
    RegisterClassExA(&wc);
    HWND hWnd = CreateWindowA("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, NULL, NULL, wc.hInstance, NULL);

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = 2;
    sd.BufferDesc.Height = 2;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    D3D_FEATURE_LEVEL FeatureLevelsRequested = D3D_FEATURE_LEVEL_11_0;
    UINT numFeatureLevelsRequested = 1;
    D3D_FEATURE_LEVEL FeatureLevelsSupported;
    HRESULT hr;
    IDXGISwapChain* swapchain = 0;
    ID3D11Device* dev = 0;
    ID3D11DeviceContext* devcon = 0;
    if (FAILED(hr = D3D11CreateDeviceAndSwapChain(NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        0,
        &FeatureLevelsRequested,
        numFeatureLevelsRequested,
        D3D11_SDK_VERSION,
        &sd,
        &swapchain,
        &dev,
        &FeatureLevelsSupported,
        &devcon)))
    {
        std::cout << "[-] Failed to hook Present with VT method." << std::endl;
        return;
    }
    DWORD_PTR* pSwapChainVtable = NULL;
    pSwapChainVtable = (DWORD_PTR*)swapchain;
    pSwapChainVtable = (DWORD_PTR*)pSwapChainVtable[0];
    fnIDXGISwapChainPresent = (IDXGISwapChainPresent)(DWORD_PTR)pSwapChainVtable[8];
    g_PresentHooked = true;
    std::cout << "[+] Present Addr:" << fnIDXGISwapChainPresent << std::endl;
    Sleep(2000);
}
//Chairloader vars

static bool spawnEntity = false;
static uint64_t entityToBeSpawned = 0;
static bool devMode = false;
static bool freeCam = false;
int GuiToggleKey, freeCamKey;
static ChairloaderUtils* chairloader;
DWORD WINAPI ChairloaderThread(HMODULE hModule) {
	// Create Console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    std::cout << "Welcome to funland sonic\n";
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"PreyDll.dll");
    chairloader = new ChairloaderUtils(moduleBase);
    
    std::ifstream ifile;
    char buf[MAX_PATH];
    GetModuleFileNameA(hModule, buf, MAX_PATH);
    std::string workingDir = buf;
    workingDir.erase(workingDir.find("ChairLoader.dll"));
    
    printf("path = %s\n", buf);
    printf("newpath = %s\n", workingDir.c_str());
    // ifile.open("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Prey\\Binaries\\Danielle\\x64\\Release\\chairloaderconfig.xml");
    ifile.open(workingDir + "chairloaderconfig.xml");
    if (ifile.is_open()) {
        printf("file exists\n");
    }
    else {
        printf("file doesn't exist\n");
        // return(-1);
    }  
    ifile.close();

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file((workingDir + "chairloaderconfig.xml").c_str());
    std::cout << doc.child("config").child("filepaths").child("PreyDirectory").attribute("path").value() << std::endl;
    for(auto itr = doc.child("config").child("keybinds").children().begin(); itr != doc.child("config").child("keybinds").children().end(); ++itr) {
        std::cout << itr->attribute("name").name() << "=" << itr->attribute("name").value() << std::endl;
        std::cout << itr->attribute("key").name() << "=" << itr->attribute("key").value() << std::endl;
    }
    std::cout << std::endl << doc.child("config").child("keybinds").find_child_by_attribute("action", "name", "GUIToggle").attribute("key").value() << std::endl;
    // Get Module base
    
    GuiToggleKey = std::stoi(doc.child("config").child("keybinds").find_child_by_attribute("action", "name", "GUIToggle").attribute("key").value());
    freeCamKey = std::stoi(doc.child("config").child("keybinds").find_child_by_attribute("action", "name", "FreeCam").attribute("key").value());
    // std::cout << std::hex << GuiToggleKey << std::endl;

    // bypass thread check for entity Spawning
    mem::Nop((BYTE*)(moduleBase + 0x020e2c5), 20);
    

    std::cout << "ChairLoader Initialized...\n";
    std::cout << "\nModule Base: 0x" << std::hex << moduleBase << std::dec << "\n\n";

    // Chairloader Variables or something
    bool bConsole = false;
    bool bGloo = 0;
    bool thirdPerson = false;
    
    bool lockFreeCam = false;
    bool oldFreeCam = false;
    // std::vector<CEntity*> spawnedEntities; 
    while(true) {
        // key input
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
        //free cam
        if (freeCam != oldFreeCam) {
            // freeCam = !freeCam;
            oldFreeCam = freeCam;
            printf("Freecam state: %u\n", freeCam);
            if(freeCam) {
                devMode = true;
                chairloader->internalPreyFunctions->CSystemF->setDevMode(chairloader->preyEnvironmentPointers->pSystem, devMode);
                chairloader->preyEnvironmentPointers->pGame->m_pConsole->ExecuteString((char*)"FreeCamEnable", false, true);
            } else {
                devMode = true;
                chairloader->internalPreyFunctions->CSystemF->setDevMode(chairloader->preyEnvironmentPointers->pSystem, devMode);
                chairloader->preyEnvironmentPointers->pGame->m_pConsole->ExecuteString((char*)"FreeCamDisable", false, true);
            }
        }
        // spawn Entity
        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
            
        }
        if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
            std::vector<ArkAbilityData>* abilities = &chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get()->m_abilities;
            if (!abilities->empty()) {
                //ImGui::Text("Size: %d\n", abilities->size());
                printf("Size: %llu\n", abilities->size());
                int clip = 0;
                for (auto itr = abilities->begin(); itr != abilities->end() && clip < abilities->size() + 100000; ++itr, clip++) {
                    // printf("%llu\n", itr->m_id);
                    if (itr->m_id != 0) {
                        static ArkAbilityLibrary library;
                        auto entry = library.arkAbilityMap.find(itr->m_id);
                        if (entry != library.arkAbilityMap.end()) {
                            // ImGui::Text(entry->second.c_str());
                            printf("%s\n", entry->second.c_str());
                            printf("Seen: %d\n Acquired: %d\n", itr->m_bSeen, itr->m_bAcquired);
                        }
                        else {
                            // ImGui::Text(std::to_string(itr->m_id).c_str());
                            // printf("%llu\n", itr->m_id);
                        }

                    }
                }
            }
        }
        if (GetAsyncKeyState(VK_NUMPAD3) & 1) {
            ArkAbilities* abilitiesPtr;
            // std::unordered_map<const ArkClass*, std::unique_ptr<ArkReflectedLibrary>>* classes = &chairloader->CGamePtr->m_pArkGameDataManager.get()->m_libraries;
            // for(auto itr = classes->begin(); itr != classes->end(); ++itr) {
            //     printf("%s: %p\n", itr->first->m_name, itr->second.get());
            //     if (strcmp(itr->first->m_name, "ArkAbilities") == 0) {
            //         abilitiesPtr = (ArkAbilities*)itr->second.get();
            //     }
            // }
            
            
        }
        if(GetAsyncKeyState(VK_NUMPAD4) & 1) {
            auto acquired = chairloader->internalPreyFunctions->ArkAbilityComponentF->GetAcquiredAbilities(chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get());
            printf("%llu\n", acquired.size());
            for (auto itr = acquired.begin(); itr != acquired.end(); ++itr) {
                printf("%llu\nacquired: %u\n", (*itr)->m_id, (*itr)->m_bAcquired);
            }
        }
	}
    // cleanup & eject
    if (f) {
        fclose(f);
    }
    FreeConsole();
    
    // DetourDetach(&(LPVOID&)fnIDXGISwapChainPresent, (PBYTE)Present);
    // DetourTransactionCommit(); 
    FreeLibraryAndExitThread(hModule, 0);
}
struct ExampleAppConsole
{
    char                  InputBuf[256];
    //TODO: implement a proper command structure
    ImVector<char*>       Items;
    ImVector<const char*> Commands;
    ImVector<char*>       History;
    int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
    ImGuiTextFilter       Filter;
    bool                  AutoScroll;
    bool                  ScrollToBottom;

    ExampleAppConsole()
    {
        // IMGUI_DEMO_MARKER("Examples/Console");
        ClearLog();
        memset(InputBuf, 0, sizeof(InputBuf));
        HistoryPos = -1;

        // "CLASSIFY" is here to provide the test case where "C"+[tab] completes to "CL" and display multiple matches.
        // TODO: load prey console commands
        Commands.push_back("HELP");
        Commands.push_back("HISTORY");
        Commands.push_back("CLEAR");
        Commands.push_back("CLASSIFY");
        AutoScroll = true;
        ScrollToBottom = false;
        AddLog("Chairloader Console Initializeed");
    }
    ~ExampleAppConsole()
    {
        ClearLog();
        for (int i = 0; i < History.Size; i++)
            free(History[i]);
    }

    // Portable helpers
    static int   Stricmp(const char* s1, const char* s2) { int d; while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; } return d; }
    static int   Strnicmp(const char* s1, const char* s2, int n) { int d = 0; while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; n--; } return d; }
    static char* Strdup(const char* s) { IM_ASSERT(s); size_t len = strlen(s) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)s, len); }
    static void  Strtrim(char* s) { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }

    void    ClearLog()
    {
        for (int i = 0; i < Items.Size; i++)
            free(Items[i]);
        Items.clear();
    }

    void    AddLog(const char* fmt, ...) IM_FMTARGS(2)
    {
        // FIXME-OPT
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
        buf[IM_ARRAYSIZE(buf) - 1] = 0;
        va_end(args);
        Items.push_back(Strdup(buf));
    }

    void Draw(const char* title, bool* p_open) {
        // ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
        if (!ImGui::BeginChild("ChildL", ImVec2(ImGui::GetContentRegionAvail().x * 0.5f, 260), false, ImGuiWindowFlags_None)) {
            ImGui::End();
            return;
        }
        // if (!ImGui::Begin(title, p_open))
        // {
        //     ImGui::End();
        //     return;
        // }

        // As a specific feature guaranteed by the library, after calling Begin() the last Item represent the title bar.
        // So e.g. IsItemHovered() will return true when hovering the title bar.
        // Here we create a context menu only available from the title bar.
        // if (ImGui::BeginPopupContextItem())
        // {
        //     if (ImGui::MenuItem("Close Console"))
        //         *p_open = false;
        //     ImGui::EndPopup();
        // }

        ImGui::TextWrapped(
            "This example implements a console with basic coloring, completion (TAB key) and history (Up/Down keys). A more elaborate "
            "implementation may want to store entries along with extra data such as timestamp, emitter, etc.");
        ImGui::TextWrapped("Enter 'HELP' for help.");

        // TODO: display items starting from the bottom

        if (ImGui::SmallButton("Add Debug Text")) { AddLog("%d some text", Items.Size); AddLog("some more text"); AddLog("display very important message here!"); }
        ImGui::SameLine();
        if (ImGui::SmallButton("Add Debug Error")) { AddLog("[error] something went wrong"); }
        ImGui::SameLine();
        if (ImGui::SmallButton("Clear")) { ClearLog(); }
        ImGui::SameLine();
        bool copy_to_clipboard = ImGui::SmallButton("Copy");
        //static float t = 0.0f; if (ImGui::GetTime() - t > 0.02f) { t = ImGui::GetTime(); AddLog("Spam %f", t); }

        ImGui::Separator();
        // Options menu
        if (ImGui::BeginPopup("Options"))
        {
            ImGui::Checkbox("Auto-scroll", &AutoScroll);
            ImGui::EndPopup();
        }

        // Options, Filter
        if (ImGui::Button("Options"))
            ImGui::OpenPopup("Options");
        ImGui::SameLine();
        Filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
        ImGui::Separator();

        // Reserve enough left-over height for 1 separator + 1 input text
        const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
        ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);
        if (ImGui::BeginPopupContextWindow())
        {
            if (ImGui::Selectable("Clear")) ClearLog();
            ImGui::EndPopup();
        }

        // Display every line as a separate entry so we can change their color or add custom widgets.
        // If you only want raw text you can use ImGui::TextUnformatted(log.begin(), log.end());
        // NB- if you have thousands of entries this approach may be too inefficient and may require user-side clipping
        // to only process visible items. The clipper will automatically measure the height of your first item and then
        // "seek" to display only items in the visible area.
        // To use the clipper we can replace your standard loop:
        //      for (int i = 0; i < Items.Size; i++)
        //   With:
        //      ImGuiListClipper clipper;
        //      clipper.Begin(Items.Size);
        //      while (clipper.Step())
        //         for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
        // - That your items are evenly spaced (same height)
        // - That you have cheap random access to your elements (you can access them given their index,
        //   without processing all the ones before)
        // You cannot this code as-is if a filter is active because it breaks the 'cheap random-access' property.
        // We would need random-access on the post-filtered list.
        // A typical application wanting coarse clipping and filtering may want to pre-compute an array of indices
        // or offsets of items that passed the filtering test, recomputing this array when user changes the filter,
        // and appending newly elements as they are inserted. This is left as a task to the user until we can manage
        // to improve this example code!
        // If your items are of variable height:
        // - Split them into same height items would be simpler and facilitate random-seeking into your list.
        // - Consider using manual call to IsRectVisible() and skipping extraneous decoration from your items.
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
        if (copy_to_clipboard)
            ImGui::LogToClipboard();
        for (int i = 0; i < Items.Size; i++)
        {
            const char* item = Items[i];
            if (!Filter.PassFilter(item))
                continue;

            // Normally you would store more information in your item than just a string.
            // (e.g. make Items[] an array of structure, store color/type etc.)
            ImVec4 color;
            bool has_color = false;
            if (strstr(item, "[error]")) { color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); has_color = true; }
            else if (strncmp(item, "# ", 2) == 0) { color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f); has_color = true; }
            if (has_color)
                ImGui::PushStyleColor(ImGuiCol_Text, color);
            ImGui::TextUnformatted(item);
            if (has_color)
                ImGui::PopStyleColor();
        }
        if (copy_to_clipboard)
            ImGui::LogFinish();

        if (ScrollToBottom || (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
            ImGui::SetScrollHereY(1.0f);
        ScrollToBottom = false;

        ImGui::PopStyleVar();
        ImGui::EndChild();
        ImGui::Separator();

        // Command-line
        bool reclaim_focus = false;
        ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
        if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), input_text_flags, &TextEditCallbackStub, (void*)this))
        {
            char* s = InputBuf;
            Strtrim(s);
            if (s[0])
                ExecCommand(s);
            strcpy_s(s, 1, "");
            reclaim_focus = true;
        }

        // Auto-focus on window apparition
        ImGui::SetItemDefaultFocus();
        if (reclaim_focus)
            ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

        ImGui::EndChild();
    }

    void    ExecCommand(const char* command_line)
    {
        AddLog("# %s\n", command_line);

        // Insert into history. First find match and delete it so it can be pushed to the back.
        // This isn't trying to be smart or optimal.
        HistoryPos = -1;
        for (int i = History.Size - 1; i >= 0; i--)
            if (Stricmp(History[i], command_line) == 0)
            {
                free(History[i]);
                History.erase(History.begin() + i);
                break;
            }
        History.push_back(Strdup(command_line));

        // Process command
        //TODO: Implement prey command execution and writeback
        if (Stricmp(command_line, "CLEAR") == 0)
        {
            ClearLog();
        }
        else if (Stricmp(command_line, "HELP") == 0)
        {
            AddLog("Commands:");
            for (int i = 0; i < Commands.Size; i++)
                AddLog("- %s", Commands[i]);
        }
        else if (Stricmp(command_line, "HISTORY") == 0)
        {
            int first = History.Size - 10;
            for (int i = first > 0 ? first : 0; i < History.Size; i++)
                AddLog("%3d: %s\n", i, History[i]);
        }
        else
        {
            AddLog("Unknown command: '%s'\n", command_line);
        }

        // On command input, we scroll to bottom even if AutoScroll==false
        ScrollToBottom = true;
    }

    // In C++11 you'd be better off using lambdas for this sort of forwarding callbacks
    static int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
    {
        ExampleAppConsole* console = (ExampleAppConsole*)data->UserData;
        return console->TextEditCallback(data);
    }

    int     TextEditCallback(ImGuiInputTextCallbackData* data)
    {
        //AddLog("cursor: %d, selection: %d-%d", data->CursorPos, data->SelectionStart, data->SelectionEnd);
        switch (data->EventFlag)
        {
        case ImGuiInputTextFlags_CallbackCompletion:
        {
            // Example of TEXT COMPLETION

            // Locate beginning of current word
            const char* word_end = data->Buf + data->CursorPos;
            const char* word_start = word_end;
            while (word_start > data->Buf)
            {
                const char c = word_start[-1];
                if (c == ' ' || c == '\t' || c == ',' || c == ';')
                    break;
                word_start--;
            }

            // Build a list of candidates
            ImVector<const char*> candidates;
            for (int i = 0; i < Commands.Size; i++)
                if (Strnicmp(Commands[i], word_start, (int)(word_end - word_start)) == 0)
                    candidates.push_back(Commands[i]);

            if (candidates.Size == 0)
            {
                // No match
                AddLog("No match for \"%.*s\"!\n", (int)(word_end - word_start), word_start);
            }
            else if (candidates.Size == 1)
            {
                // Single match. Delete the beginning of the word and replace it entirely so we've got nice casing.
                data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
                data->InsertChars(data->CursorPos, candidates[0]);
                data->InsertChars(data->CursorPos, " ");
            }
            else
            {
                // Multiple matches. Complete as much as we can..
                // So inputing "C"+Tab will complete to "CL" then display "CLEAR" and "CLASSIFY" as matches.
                int match_len = (int)(word_end - word_start);
                for (;;)
                {
                    int c = 0;
                    bool all_candidates_matches = true;
                    for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
                        if (i == 0)
                            c = toupper(candidates[i][match_len]);
                        else if (c == 0 || c != toupper(candidates[i][match_len]))
                            all_candidates_matches = false;
                    if (!all_candidates_matches)
                        break;
                    match_len++;
                }

                if (match_len > 0)
                {
                    data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
                    data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
                }

                // List matches
                AddLog("Possible matches:\n");
                for (int i = 0; i < candidates.Size; i++)
                    AddLog("- %s\n", candidates[i]);
            }

            break;
        }
        case ImGuiInputTextFlags_CallbackHistory:
        {
            // Example of HISTORY
            const int prev_history_pos = HistoryPos;
            if (data->EventKey == ImGuiKey_UpArrow)
            {
                if (HistoryPos == -1)
                    HistoryPos = History.Size - 1;
                else if (HistoryPos > 0)
                    HistoryPos--;
            }
            else if (data->EventKey == ImGuiKey_DownArrow)
            {
                if (HistoryPos != -1)
                    if (++HistoryPos >= History.Size)
                        HistoryPos = -1;
            }

            // A better implementation would preserve the data on the current input line along with cursor position.
            if (prev_history_pos != HistoryPos)
            {
                const char* history_str = (HistoryPos >= 0) ? History[HistoryPos] : "";
                data->DeleteChars(0, data->BufTextLen);
                data->InsertChars(0, history_str);
            }
        }
        }
        return 0;
    }
};
static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
#define GET_VARIABLE_NAME(Variable) (#Variable)
// gui variables
//
struct archetypeFilterRequest {
    std::string text;
};
// archetype filter
static std::string archetypeFilterText, oldArchetypeFilterText;
std::queue<archetypeFilterRequest> archetypeFilterRequestQueue;
std::vector<CEntityArchetype*> archetypeFilteredList;

static CEntityArchetype* archetypeToSpawn;
struct spawnRequest {
    CEntityArchetype* archetype;
    std::string name;
    Vec3_tpl<float> pos;
    Vec4_tpl<float> rot = { 0,0,0,1 };
    int spawnCount;
    bool usePlayerPos, offsetFromPlayer;
};
std::queue<spawnRequest> archetypeSpawnRequestQueue;

struct abilityEntry {
    uint64_t id;
    std::string name;
    bool acquired{ false };
};
bool AbilityEntrySortByName(const abilityEntry& lhs, const abilityEntry& rhs) {
    return lhs.name < rhs.name;
}
bool AbilityListInitialized, refreshAbilityList;
std::vector<abilityEntry> abilityDisplayList;
std::queue<uint64_t> abilityRequestQueue;
// std::map<uint64_t, bool> abilitiesGiven;

void drawGUI(bool* bShow) {
    if (*bShow) {
        ImGui::Begin("Chairloader");                          // Create a window called "Hello, world!" and append into it.
        if (ImGui::BeginMenuBar()) {
            if(ImGui::BeginMenu("Menu")) {
	            if(ImGui::MenuItem("Hide")) {
                    g_ShowMenu = false;
	            }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_Reorderable;
        if (ImGui::BeginTabBar("Chairloader Menu", tab_bar_flags)) {
            if (ImGui::BeginTabItem("Entities")) {
                const float TEXT_BASE_WIDTH = 7.0f;
                const float TEXT_BASE_HEIGHT = 17.0f;
                // Helper class to easy setup a text filter.
                // You may want to implement a more feature-full filtering scheme in your own application.
                static bool usePlayerPos, offsetFromPlayer;
                static std::string inputId, inputName;
                static std::string statusMessage;
                static float spawnX, spawnY, spawnZ;
                static ImVec4 color{ 1,1,1,1 };
                static time_t statusTimer;
                static int spawnCount{1};
                ImGui::TextColored(color, statusMessage.c_str());
                if (archetypeToSpawn == nullptr) {
                    ImGui::Text("Entity Archetype Name: ");
                    ImGui::Text("Entity ID: ");
                    
                } else {
                    ImGui::Text("Entity Archetype Name: %s", archetypeToSpawn->m_name.m_str);
                    ImGui::Text("Entity ID: %d", archetypeToSpawn->m_id);
                }
                ImGui::InputText("Entity Name", &inputName, ImGuiInputTextFlags_None);
                ImGui::InputInt("Spawn Count", &spawnCount);
                ImGui::Checkbox("Use Player Pos", &usePlayerPos);
                if (usePlayerPos) {
                    ImGui::Checkbox("Offset In front of Player", &offsetFromPlayer);
                }
                else {
                    ImGui::InputFloat("X", &spawnX);
                    ImGui::InputFloat("Y", &spawnY);
                    ImGui::InputFloat("Z", &spawnZ);
                }

                if (ImGui::Button("Spawn Entity")) {
                    //TODO: make it spawn an entity when the button is pushed
                    try {
                        if (archetypeToSpawn != nullptr) {
                            if (inputName != "") {
                                spawnRequest request;
                                request.archetype = archetypeToSpawn;
                                request.usePlayerPos = usePlayerPos;
                                request.offsetFromPlayer = offsetFromPlayer;
                                request.name = inputName;
                                if (spawnCount >= 1) {
                                    request.spawnCount = spawnCount;
                                } else {
                                	if (spawnCount > 999) {
                                        throw("Error, invalid spawn count (spawn count too high)");
	                                }

                                    throw("Error, invalid spawn count");
                                }
                                request.pos.x = spawnX;
                                request.pos.y = spawnY;
                                request.pos.z = spawnZ;
                                archetypeSpawnRequestQueue.push(request);
                                // done
                                color = { 1,1,1,1 };
                                statusMessage = "spawned an entity: " + inputName;
                                time(&statusTimer);
                            } else {
                                throw ("Error, invalid entity name");
                            }
                        } else {
                            throw("Error, no archetype selected");
                        }
                    } catch(const char* c) {
                        color = { 1,0,0,1 };
                        statusMessage = c;
                        time(&statusTimer);
                    }
                }
                ImGui::Text("Filter:");
                ImGui::InputText("", &archetypeFilterText);
                if (archetypeFilterText != oldArchetypeFilterText) {
                    oldArchetypeFilterText = archetypeFilterText;
                    archetypeFilterRequestQueue.push(archetypeFilterRequest{archetypeFilterText});
                    // printf("requested: %s\n", archetypeFilterText.c_str());
                }
                // filter.Draw(" ");
                ImGui::SameLine();
                HelpMarker("Filter usage:\n"
                    "  \"\"         display all lines\n"
                    "  \"xxx\"      display lines containing \"xxx\"\n"
                    "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n"
                    "  \"-xxx\"     hide lines containing \"xxx\"");
                //TODO: Replace this with actual archetype list, potentially with custom struct for easy sorting
                static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Hideable;
                ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 16.0f);
                if (ImGui::BeginTable("3ways", 3, flags, outer_size)) {

                    ImGui::TableSetupScrollFreeze(0, 1);
                    ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_None);
                    // if (ImGui::IsItemHovered())
                    //     ImGui::SetTooltip("Click to view archetype information");
                    ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_None);
                    // if (ImGui::IsItemHovered())
                    //     ImGui::SetTooltip("Click to select archetype");
                    ImGui::TableSetupColumn("Library", ImGuiTableColumnFlags_None);
                    ImGui::TableHeadersRow();
                    //TODO: probably implement clipper
                    // if filter changes
                    // filter through all archetypes
                    // if filter is empty or smaller than x characters do not update
                    



                    // ImGuiListClipper clipper;
                    // clipper.Begin(200);
                    // while (clipper.Step()) {
                        auto itr = archetypeFilteredList.begin();
	                    for(int clip = 0; clip < 200 && itr != archetypeFilteredList.end(); clip++, ++itr) {
                            static bool nameClicked, idClicked;
                            CEntityArchetype* archetype = *itr;
                            ImGui::TableNextRow();
                            //TODO: Context popup for archetype info?
                            //TODO: Pull information out of archetypes
                            ImGui::TableSetColumnIndex(0);
                            
                            nameClicked = ImGui::Selectable(archetype->m_name.m_str);
                            // printf("Name Printed\n");
                            if (ImGui::BeginPopupContextItem(NULL, ImGuiPopupFlags_MouseButtonLeft)) // <-- use last item id as popup id
                            {
                                ImGui::Text("Display information about the archetype here");
                                if (ImGui::Button("Choose"))
                                    // inputId = std::to_string(archetype->m_id);
                                    archetypeToSpawn = archetype;
                                if (ImGui::Button("Close"))
                                    ImGui::CloseCurrentPopup();
                                ImGui::EndPopup();
                            }

                            ImGui::TableSetColumnIndex(1);
                            if(ImGui::Selectable(std::to_string(archetype->m_id).c_str())) {
                                // inputId = std::to_string(archetype->m_id);
                                archetypeToSpawn = archetype;
                            }
                            // printf("id Printed\n");
                            ImGui::TableSetColumnIndex(2);
                            ImGui::Text("Thing");
	                    }
                    // }
                    if (time(NULL) > statusTimer + 3)
                        statusMessage = "";
                    // }
                    ImGui::EndTable();
                    ImGui::EndTabItem();
                }
            }
            if (ImGui::BeginTabItem("Console")) {
                // ImGui::Text("This is the Broccoli tab!\nblah blah blah blah blah");
                static bool consoleOpen, devMode, godMode;
                static ExampleAppConsole console;
                ImGui::Checkbox("Show Console", &consoleOpen);
                if (consoleOpen)
                    console.Draw("Console", &consoleOpen);
                else
                    ImGui::Checkbox("Dev Mode", &devMode);
                ImGui::Checkbox("Dev Mode", &godMode);
                if(ImGui::Button("Free Cam"))
					freeCam = !freeCam;
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Inventories")) {
                
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Abilities")) {
                refreshAbilityList = ImGui::Button("Refresh");
                if (ImGui::BeginChild("AbilityList", ImGui::GetContentRegionAvail(), false, ImGuiWindowFlags_HorizontalScrollbar)) {
                    for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
                        if (!itr->acquired) {
                            if (ImGui::Selectable(itr->name.c_str())) {
                                abilityRequestQueue.push(itr->id);
                            }
                        }
                        else {
                            ImGui::TextColored(ImVec4{ 1.0f,1.0f,1.0f,0.7f}, "%s - acquired", itr->name.c_str());
                        }
                    }
                    ImGui::EndChild();
                }
                // std::vector<ArkAbilityData>* abilities = &chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get()->m_abilities;
                // if (!abilities->empty()) {
                //     ImGui::Text("Size: %d\n", abilities->size());
                //     int clip = 0;
                //     for (auto itr = abilities->begin(); itr != abilities->end() && clip <= 1000; ++itr, clip++) {
                //         if (itr->m_id != 0) {
                //             static ArkAbilityLibrary library;
                //             auto entry = library.arkAbilityMap.find(itr->m_id);
                //             if(entry != library.arkAbilityMap.end()) {
                //                 ImGui::Text(entry->second.c_str());
                //             } else {
                //                 ImGui::Text(std::to_string(itr->m_id).c_str());
                //             }
                //             
                //         }
                //     }
                // }
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
            
        }
        // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
};
void checkAbilities() {
	if(refreshAbilityList) {
        for(auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
            if (chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
                itr->acquired = chairloader->internalPreyFunctions->ArkAbilityComponentF->HasAbility(chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get(), itr->id);
            }
            //abilityDisplayList.emplace_back(entry);
        }
        std::sort(abilityDisplayList.begin(), abilityDisplayList.end(), AbilityEntrySortByName);
        refreshAbilityList = false;
	}
}
void abilityRequestHandler() {
    try {
        if (!AbilityListInitialized) {
            for (auto itr = chairloader->abilityLibrary.arkAbilityMap.begin(); itr != chairloader->abilityLibrary.arkAbilityMap.end(); ++itr) {
                abilityEntry entry = { itr->first, itr->second, false };
                if (chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get() != nullptr) {
                    if(chairloader->internalPreyFunctions->ArkAbilityComponentF->HasAbility(chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get(), itr->first)) {
                        entry.acquired = true;
                    }
                }
                abilityDisplayList.emplace_back(entry);
                
            }
            std::sort(abilityDisplayList.begin(), abilityDisplayList.end(), AbilityEntrySortByName);
            AbilityListInitialized = true;
        }
        else {
            if (!abilityRequestQueue.empty()) {
                uint64_t id = abilityRequestQueue.front();
                abilityRequestQueue.pop();
                abilityEntry* entry = nullptr;
                for (auto itr = abilityDisplayList.begin(); itr != abilityDisplayList.end(); ++itr) {
                    if (itr->id == id) {
                        entry = itr._Ptr;
                    }
                }
                if (entry != nullptr) {
                    if (!entry->acquired) {
                        if (chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get() != nullptr && !chairloader->internalPreyFunctions->ArkAbilityComponentF->HasAbility(chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get(), entry->id)) {
                            chairloader->internalPreyFunctions->ArkAbilityComponentF->GrantAbility(chairloader->ArkPlayerPtr->m_playerComponent.m_pAbilityComponent.get(), entry->id);
                            printf("Granted Ability: %s\n", chairloader->abilityLibrary.arkAbilityMap.find(entry->id)->second.c_str());
                            entry->acquired = true;
                        }
                        else {
                            throw("Error, Ability Component Not Found");
                        }
                    }
                } else {
                    throw("Error, invalid ability id");
                }
            }
        }
    } catch (char* c) {
        printf("%s\n", c);
    }
}


static bool wentOutOfFocus;

void archetypeSpawnRequestHandler() {
    if (!archetypeSpawnRequestQueue.empty() && !chairloader->preyEnvironmentPointers->pSystem->IsPaused()) {
        try {
            spawnRequest request = archetypeSpawnRequestQueue.front();
            archetypeSpawnRequestQueue.pop();
            std::string archetypeName = request.archetype->m_name.m_str;
           
                // chairloader->entityArchetypeLibrary.
            if (request.usePlayerPos) {
                Vec3_tpl<float> playerPos;
                ArkPlayer* player = chairloader->internalPreyFunctions->ArkPlayerF->getInstance();
                chairloader->internalPreyFunctions->ArkPlayerF->getPlayerWorldEyePos(player, &playerPos);
                if (player != nullptr) {
                    // player->GetLocalEyePos(&playerPos);
                    // printf("Player Position x: %f y: %f z:%f\n", playerPos.x, playerPos.y, playerPos.z);
                    if (playerPos.x != 0 && playerPos.y != 0 && playerPos.z != 0) {
                        if (request.offsetFromPlayer) {
                            playerPos.x += chairloader->ArkPlayerPtr->m_cachedReticleDir.x * 5;
                            playerPos.y += chairloader->ArkPlayerPtr->m_cachedReticleDir.y * 5;
                        }
                        request.pos = playerPos;
                    }
                    else {
                        throw ("Error, null player position");
                    }
                }
                else {
                    throw("Error, null player pointer");
                }
            }
            if (archetypeName.find("ArkRobots") != std::string::npos || archetypeName.find("ArkHumans") != std::string::npos || archetypeName.find("ArkNpcs") != std::string::npos) {
                if (request.spawnCount == 1) {
                    IEntity* spawnerEntity = chairloader->spawnerHelper->getVictimSpawnerEntity(ChairloaderUtils::EntityType::mimic);
                    if (spawnerEntity != nullptr) {
                        char* oldArchetypeName = chairloader->spawnerHelper->setEntityArchetype(request.archetype->m_id, spawnerEntity);
                        if (oldArchetypeName != nullptr) {
                            CArkNpcSpawner* spawner = chairloader->internalPreyFunctions->CEntity->getArkNpcSpawner((CEntity*)spawnerEntity);
                            IEntity* newEntity = chairloader->spawnerHelper->spawnNpc(spawner, (char*)request.name.c_str());
                            printf("spawned an entity\n");
                            if (newEntity != nullptr) {
                                newEntity->SetPos(&request.pos, 0, true, false);
                                // printf("set position of an entity to x: %f y: %f z:%f\n", request.pos.x, request.pos.y, request.pos.z);
                            }
                            else {
                                throw("Error, null entity spawned");
                            }
                            chairloader->spawnerHelper->setEntityArchetype(oldArchetypeName, spawnerEntity);
                        }
                        else {
                            throw("Error, Old archetype Was null (single spawn)");
                        }
                    }
                    else {
                        throw("Error, spawner Entity Was null (single spawn)");
                    }
                }
                else {
                    IEntity* spawnerEntity = chairloader->spawnerHelper->getVictimSpawnerEntity(ChairloaderUtils::EntityType::mimic);
                    if (spawnerEntity != nullptr) {
                        char* oldArchetypeName = chairloader->spawnerHelper->setEntityArchetype(request.archetype->m_id, spawnerEntity);
                        if (oldArchetypeName != nullptr) {
                            CArkNpcSpawner* spawner = chairloader->internalPreyFunctions->CEntity->getArkNpcSpawner((CEntity*)spawnerEntity);
                            for (int i = 0; i < request.spawnCount; i++) {
                                IEntity* newEntity = chairloader->spawnerHelper->spawnNpc(spawner, (char*)request.name.c_str());
                                if (newEntity != nullptr) {
                                    newEntity->SetPos(&request.pos, 0, true, false);
                                    // printf("set position of an entity to x: %f y: %f z:%f\n", request.pos.x, request.pos.y, request.pos.z);
                                }
                                else {
                                    throw("Error, null entity spawned");
                                }
                            }
                            chairloader->spawnerHelper->setEntityArchetype(oldArchetypeName, spawnerEntity);
                        }
                        else {
                            throw("Error, Old archetype Was null (single spawn)");
                        }
                    }
                    else {
                        throw("Error, spawner Entity Was null (single spawn)");
                    }
                }
            } else {
                printf("Using non-npc spawning process\n");
                SEntitySpawnParams* params = new SEntitySpawnParams;

                params->vScale.x = 1;
                params->vScale.y = 1;
                params->vScale.z = 1;
                uint32_t id = chairloader->internalPreyFunctions->CEntitySystemF->generateEntityId(chairloader->preyEnvironmentPointers->pEntitySystem, true);
                params->id = id;
                params->vPosition.x = request.pos.x;
                params->vPosition.y = request.pos.y;
                params->vPosition.z = request.pos.z;
                params->qRotation.x = request.rot.x;
                params->qRotation.y = request.rot.y;
                params->qRotation.z = request.rot.z;
                params->qRotation.w = request.rot.w;
                params->sLayerName = (char*)"";
                params->pClass = (CEntityClass*)(0x0);
                params->pArchetype = (CEntityArchetype*)(0x0);
                params->guid = 0;
                params->prevGuid = 0;
                params->prevId = 0;
                params->bCreatedThroughPool = 0;
                params->bIgnoreLock = 0;
                params->bStaticEntityId = 0;
                params->nFlags = 0;
                params->nFlagsExtended = 0;
                params->sName = (char*)request.name.c_str();
                params->entityNode.ptr = (IXmlNode*)0x0;
                params->shadowCasterType = '\0';
                params->pUserData = (void*)0x0;
                params->sceneMask = '\0';
                IEntity* entity;

                // IEntityArchetype* archetype = (IEntityArchetype*)chairloader->preyEnvironmentPointers->pEntitySystem->GetEntityArchetype();
                if (request.archetype != nullptr) {
                    entity = chairloader->preyEnvironmentPointers->pEntitySystem->SpawnEntityFromArchetype((IEntityArchetype*)request.archetype, params, true);
                }
                else {
                    printf("Error, no archetype found\n");
                }




            }
        } catch (const char* c) {
            printf("%s\n", c);
        }
    }
}

void archetypeFilterRequestHandler() {
    if (!archetypeFilterRequestQueue.empty()) {
        archetypeFilterRequest request = archetypeFilterRequestQueue.front();
        std::string filterText = request.text;

        // static ImGuiTextFilter filter;
        std::map<const char*, CEntityArchetype*>* archetypeList = &chairloader->preyEnvironmentPointers->pEntitySystem->m_pEntityArchetypeManager->m_nameToArchetypeMap;
        auto itr = archetypeList->begin();
        archetypeFilteredList.clear();
        // if (filterText.size() < strlen(filter.InputBuf)) {
        // strcpy_s(filter.InputBuf, filterText.size(), filterText.c_str());
        // }
        for (int i = 0; i < 400 && itr != archetypeList->end(); ++itr) {
            std::string archetypeName = itr->first;
            // size_t last_period = archetypeName.find_last_of('.');
            // archetypeName = archetypeName.substr(last_period, archetypeName.size());
            std::transform(archetypeName.begin(), archetypeName.end(), archetypeName.begin(), ::tolower);
            std::transform(filterText.begin(), filterText.end(), filterText.begin(), ::tolower);
            if (archetypeName.find(filterText) != std::string::npos || filterText.empty()) {
                archetypeFilteredList.emplace_back(itr->second);
                i++;

            }
        }
        archetypeFilterRequestQueue.pop();
        // printf("processed: %s\n", filterText.c_str());
    }
}




DWORD WINAPI GUIThread(HMODULE hModule) {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    GetPresent();
    // begin gui hooking
    if (!g_PresentHooked) {
        retrieveValues();
    }
    // detour time
    detourDirectXPresent();
    while (!g_bInitialised) {
        Sleep(1000);
    }
    while(true) {
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            g_ShowMenu = !g_ShowMenu;
        }
       
        if(GetForegroundWindow() != window) {
            g_ShowMenu = false;
            // wentOutOfFocus = true;
            // printf("went out of focus\n");
        }
        if (!chairloader->preyEnvironmentPointers->pGame->m_pFramework->IsInLevelLoad() || !chairloader->preyEnvironmentPointers->pGame->m_pFramework->IsLoadingSaveGame()) {
            archetypeFilterRequestHandler();
            archetypeSpawnRequestHandler();
            abilityRequestHandler();
            checkAbilities();
        }
    	// if(GetForegroundWindow() == window && wentOutOfFocus) {
     //        g_ShowMenu = true;
     //        wentOutOfFocus = false;
     //        printf("back in baby\n");
     //    }
    }
    g_ShowMenu = false;
    g_PresentHooked = false;
    g_bInitialised = false;
    FreeLibraryAndExitThread(hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ChairloaderThread, hModule, 0, nullptr));
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)GUIThread, hModule, 0, nullptr));
        // CloseHandle(CreateThread(nullptr, 0 (LPTHREAD_START_ROUTINE), hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        killDetourDirectX();
        break;
    }
    return TRUE;
}

