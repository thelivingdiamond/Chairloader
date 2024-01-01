#include <Preditor/FileHistory.h>

std::vector<std::string> FileHistory::ReadHistory(const fs::path& historyFile)
{
    if (!fs::exists(historyFile))
        return {};

    pugi::xml_document doc;
    if (!doc.load_file(historyFile.c_str()))
        return {};

    std::vector<std::string> paths;

    for (pugi::xml_node i : doc.child("FileHistory").children())
    {
        paths.push_back(i.text().as_string());
    }

    return paths;
}

void FileHistory::AddToHistory(const fs::path& historyFile, const std::string& path)
{
    std::vector<std::string> existingHistory = ReadHistory(historyFile);

    // Find the path in existing history
    auto it = std::find(existingHistory.begin(), existingHistory.end(), path);
    if (it != existingHistory.end())
        existingHistory.erase(it);

    // Add to the top
    existingHistory.insert(existingHistory.begin(), path);

    // Save to the file
    pugi::xml_document doc;
    pugi::xml_node root = doc.append_child("FileHistory");
    
    for (const std::string& i : existingHistory)
    {
        root.append_child("Path").text().set(i.c_str());
    }

    doc.save_file(historyFile.c_str());
}
