#include "ProjectHistory.h"

std::vector<fs::path> ProjectHistory::ReadHistory()
{
    fs::path filePath = gPreditor->pConfig->GetPreditorRoot() / FILE_PATH;
    if (!fs::exists(filePath))
        return {};

    pugi::xml_document doc;
    if (!doc.load_file(filePath.c_str()))
        return {};

    std::vector<fs::path> paths;

    for (pugi::xml_node i : doc.child("ProjectHistory").children())
    {
        paths.push_back(fs::u8path(i.text().as_string()));
    }

    return paths;
}

void ProjectHistory::AddToHistory(const fs::path& path)
{
    std::vector<fs::path> existingHistory = ReadHistory();

    // Find the path in existing history
    auto it = std::find(existingHistory.begin(), existingHistory.end(), path);
    if (it != existingHistory.end())
        existingHistory.erase(it);

    // Add to the top
    existingHistory.insert(existingHistory.begin(), path);

    // Save to the file
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("ProjectHistory");
    
    for (const fs::path& i : existingHistory)
    {
        root.append_child("Path").set_value(i.u8string().c_str());
    }

    fs::path filePath = gPreditor->pConfig->GetPreditorRoot() / FILE_PATH;
    doc.save_file(filePath.c_str());
}
