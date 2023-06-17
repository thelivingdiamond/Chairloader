#include <Preditor/PreditorConfig.h>
#include <App/Application.h>

PreditorConfig::PreditorConfig()
{
    FillEnvPaths();
}

bool PreditorConfig::ValidateConfig(std::string* error) const
{
    if (!GamePath::ValidateGamePath(m_RawGamePath, error))
        return false;

    return true;
}

bool PreditorConfig::LoadFromXml()
{
    fs::path path = GetPreditorRoot() / XML_FILE_PATH;
    if (!fs::exists(path))
        return false;

    pugi::xml_document doc;
    if (!doc.load_file(path.c_str()))
        return false;

    pugi::xml_node root = doc.child("PreditorConfig");
    SetRawGamePath(fs::u8path(root.child_value("GamePath")), nullptr);

    return true;
}

void PreditorConfig::SaveToXml()
{
    std::string validationError;
    if (!ValidateConfig(&validationError))
        throw std::logic_error("Invalid config: " + validationError);

    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("PreditorConfig");
    root.append_child("GamePath").text().set(m_GamePath.GetGamePath().u8string().c_str());

    fs::path path = GetPreditorRoot() / XML_FILE_PATH;
    doc.save_file(path.c_str());
}

bool PreditorConfig::SetRawGamePath(const fs::path& gameRootPath, std::string* error)
{
    m_RawGamePath = gameRootPath;
    return m_GamePath.TrySetGamePath(gameRootPath, error);
}

void PreditorConfig::FillEnvPaths()
{
    m_PreditorRoot = Application::Get()->GetProgramPath();
    m_PreyFiles = m_PreditorRoot / "PreyFiles";

    if (!fs::exists(m_PreyFiles))
        throw std::runtime_error("PreyFiles directory is missing.");

    // TODO: Un-comment once extraction mode is used. Remove the previous check.
    // if (!fs::exists(m_PreyFiles / "FilesExtracted.dat"))
    // 	throw std::runtime_error("File cache is invalid. Run ChairManager.");
}
