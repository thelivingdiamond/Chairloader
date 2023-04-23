#include <boost/program_options.hpp>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CryGame/IGameStartup.h>
#include <WindowManager/WindowManager.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include "App/AppStage.h"
#include "Preditor.h"
#include "LoadGameStage.h"
#include "ExtractionStage.h"

ChairloaderGlobalEnvironment* gCL = nullptr;

Preditor::Preditor()
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

Preditor::~Preditor()
{
    IPreditorEngine::Get()->Shutdown();
}

void Preditor::OnConfigValidated(std::unique_ptr<PreditorConfig>&& pConfig)
{
    m_pConfig = std::move(pConfig);
    gPreditor->pConfig = m_pConfig.get();
    m_pProjectManager = std::make_unique<ProjectManager>();
}

AppStagePtr Preditor::OnGameLoaded()
{
    if (m_pExtractionOptions)
    {
        return std::make_unique<ExtractionStage>(*m_pExtractionOptions);
    }
    else
    {
        IPreditorEngine::Get()->SetAppImGui();
        std::unique_ptr<ProjectStage> pProjectStage = std::make_unique<ProjectStage>();
        // TODO: Move to Main
        // m_pLookingGlass = std::make_unique<LookingGlass>();
        // m_pLookingGlass->Init();

        return pProjectStage;
    }
}

void Preditor::Update()
{
    // Only the main stage has a dedicated main window.
    // Dock space needs to be created before any windows.
    if (ProjectStage::Get())
        ImGui::DockSpaceOverViewport();
}

void Preditor::ShowUI(bool* bOpen)
{
    if(m_Config.isShown())
        m_Config.ShowUI();

    // TODO: Move to Main
    // if (GetStage() == ProjectStage::Get() && m_pLookingGlass) // TODO: Hack to display LG after DockSpaceOverViewport
    //     m_pLookingGlass->ShowUI();
}

void Preditor::PostUpdate()
{
    // Engine must be updated at the end of the tick because it will end the ImGui frame.
    if (!IPreditorEngine::Get()->Update())
        QuitApp();
}

void Preditor::ParseCommandLine()
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
	auto pApp = std::make_unique<Preditor>();
	return pApp->Run();
}
