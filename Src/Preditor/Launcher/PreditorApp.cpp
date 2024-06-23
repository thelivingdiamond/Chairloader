#include <boost/program_options.hpp>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Main/IPreditor.h>
#include "App/AppStage.h"
#include "PreditorApp.h"
#include "LoadGameStage.h"
#include "MainStage.h"
#include "ExtractionStage.h"

SPreditorEnvironment gPreditorEnv;
SPreditorEnvironment* gPreditor = &gPreditorEnv;
ChairloaderGlobalEnvironment* gCL = nullptr;

extern "C"
{
    DLL_EXPORT unsigned long NvOptimusEnablement = 1;
    DLL_EXPORT int AmdPowerXpressRequestHighPerformance = 1;
}

PreditorApp::PreditorApp()
{
    gPreditor->pPaths = &m_Paths;
    ParseCommandLine();

    if (m_pExtractionOptions)
    {
        // Don't need to load the config, just start the engine
        SetStage(std::make_unique<LoadGameStage>(m_pExtractionOptions.get()));
    }
    else
    {
        SetStage(std::make_unique<ConfigValidationStage>());
    }
}

PreditorApp::~PreditorApp()
{
    IPreditorEngine::Get()->Shutdown();
    m_pMainPreditor = nullptr;
}

void PreditorApp::OnConfigValidated(std::unique_ptr<PreditorConfig>&& pConfig)
{
    m_pConfig = std::move(pConfig);
    gPreditor->pConfig = m_pConfig.get();
}

void PreditorApp::CreatePreditorMain()
{
    m_pMainPreditor = IPreditor::CreateInstance();
    gPreditor->pMain = m_pMainPreditor.get();

    // This should probably be somewhere else but IPreditorEngine is a global variable.
    gPreditor->pEngine = IPreditorEngine::Get();
}

AppStagePtr PreditorApp::OnGameLoaded()
{
    if (m_pExtractionOptions)
    {
        return std::make_unique<ExtractionStage>(*m_pExtractionOptions);
    }
    else
    {
        IPreditorEngine::Get()->SetAppImGui();
        auto pMainStage = std::make_unique<MainStage>();
        return pMainStage;
    }
}

void PreditorApp::Update()
{
    // Only the main stage has a dedicated main window.
    // Dock space needs to be created before any windows.
    if (gPreditor->pMain)
        ImGui::DockSpaceOverViewport();
}

void PreditorApp::ShowUI(bool* bOpen)
{
    // TODO: Move to Main
    // if (GetStage() == ProjectStage::Get() && m_pLookingGlass) // TODO: Hack to display LG after DockSpaceOverViewport
    //     m_pLookingGlass->ShowUI();
}

void PreditorApp::PostUpdate()
{
    // Engine must be updated at the end of the tick because it will end the ImGui frame.
    if (!IPreditorEngine::Get()->Update())
        QuitApp();
}

void PreditorApp::ParseCommandLine()
{
    try
    {
        namespace po = boost::program_options;
        std::wstring cmdLine = GetCommandLineW();
        std::vector<std::wstring> args = po::split_winmain(cmdLine);
        std::vector<const wchar_t*> argv(args.size());
        for (int i = 0; i < args.size(); i++)
            argv[i] = args[i].c_str();

        // Declare the supported options.
        po::options_description desc("Allowed options");
        desc.add_options()
            ("extract", "Extract game files")
            ("game-path", po::value<std::string>(), "path to the game root directory")
            ("output-path", po::value<std::string>(), "path to the output directory");

        po::variables_map vm;
        po::store(po::parse_command_line(argv.size(), argv.data(), desc), vm);
        po::notify(vm);

        if (vm.count("extract"))
        {
            m_pExtractionOptions = std::make_unique<ExtractionOptions>();
            m_pExtractionOptions->gamePath = fs::u8path(vm["game-path"].as<std::string>());
            m_pExtractionOptions->outputPath = fs::u8path(vm["output-path"].as<std::string>());

            m_pExtractionOptions->gamePath = fs::absolute(m_pExtractionOptions->gamePath);
            m_pExtractionOptions->outputPath = fs::absolute(m_pExtractionOptions->outputPath);

            fs::create_directories(m_pExtractionOptions->outputPath);
        }
    }
    catch (const std::exception& e)
    {
        std::string text = std::string("Failed to parse the command line:\n\n") + e.what();
        MessageBoxA(nullptr, text.c_str(), "Preditor Error", MB_OK | MB_ICONERROR);
        std::exit(-1);
    }
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	auto pApp = std::make_unique<PreditorApp>();
	return pApp->Run();
}
