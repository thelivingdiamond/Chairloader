#include <cstring>
#include <vector>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Preditor/Environment.h>
#include <Preditor/ReferenceCatalog/Providers/XmlFileProvider.h>

namespace fs = std::filesystem;

namespace ReferenceCatalog
{

namespace
{

//! Win32 wide → UTF-8 conversion. Cry's wstring is CryStringT<wchar_t>; the
//! WideCharToMultiByte path matches what imgui.cpp does for clipboard text.
std::string WideToUtf8(const wchar_t* w)
{
    if (!w || !*w)
        return {};
    const int n = WideCharToMultiByte(CP_UTF8, 0, w, -1, nullptr, 0, nullptr, nullptr);
    if (n <= 1)
        return {};
    std::string out(n - 1, '\0');
    WideCharToMultiByte(CP_UTF8, 0, w, -1, out.data(), n, nullptr, nullptr);
    return out;
}

//! If `value` starts with '@' and `enabled` is true, resolve it through Cry's
//! ILocalizationManager and return the resolved UTF-8 string. Otherwise (or
//! on failure) returns value unchanged.
std::string MaybeLocalize(const std::string& value, bool enabled)
{
    if (!enabled || value.empty() || value.front() != '@')
        return value;
    if (!gEnv || !gEnv->pSystem)
        return value;
    auto* loc = gEnv->pSystem->GetLocalizationManager();
    if (!loc)
        return value;

    wstring wide;
    if (!loc->LocalizeString(value.c_str(), wide) || wide.empty())
        return value;
    std::string utf8 = WideToUtf8(wide.c_str());
    return utf8.empty() ? value : utf8;
}

void CollectFromXml(const XmlNodeRef& node,
                    const XmlFileProvider::Spec& spec,
                    const std::string& sourceLabel,
                    std::vector<Entry>& out)
{
    if (!node)
        return;

    if (node->isTag(spec.elementName.c_str()))
    {
        const char* id = node->getAttr(spec.idAttr.c_str());
        if (id && *id)
        {
            Entry e;
            e.id = id;
            const char* nm = node->getAttr(spec.nameAttr.c_str());
            e.name = MaybeLocalize(nm ? nm : "", spec.localizeName);
            e.sourceLabel = sourceLabel;
            out.push_back(std::move(e));
        }
    }

    const int n = node->getChildCount();
    for (int i = 0; i < n; ++i)
        CollectFromXml(node->getChild(i), spec, sourceLabel, out);
}

//! Loads any XML file Cry can resolve — paks (binary XML) and loose filesystem
//! (plain XML) — and harvests matching elements.
void LoadXmlFile(const std::string& pathStr,
                 const XmlFileProvider::Spec& spec,
                 std::vector<Entry>& out)
{
    if (!gEnv || !gEnv->pSystem)
        return;

    XmlNodeRef root = gEnv->pSystem->LoadXmlFromFile(
        pathStr.c_str(), /*bReuseStrings*/ false, /*bAllowUseFilesystem*/ true);
    if (!root)
    {
        CryLog("ReferenceCatalog: LoadXmlFromFile failed for '{}'", pathStr);
        return;
    }

    CollectFromXml(root, spec, fs::path(pathStr).filename().string(), out);
}

void WalkPakDirectory(const std::string& gameRelDir,
                      const XmlFileProvider::Spec& spec,
                      std::vector<Entry>& out)
{
    if (!gEnv || !gEnv->pCryPak)
        return;

    // bAllowUseFileSystem = true so we also see loose-filesystem mods
    // (AddMod-registered directories). Without it, FindFirst is paks-only.
    {
        const std::string pattern = gameRelDir + "/*.xml";
        _finddata_t cf;
        intptr_t h = gEnv->pCryPak->FindFirst(pattern.c_str(), &cf, 0, true);
        if (h != -1)
        {
            do
            {
                if ((cf.attrib & _A_SUBDIR) != 0)
                    continue;
                LoadXmlFile(gameRelDir + "/" + cf.name, spec, out);
            } while (gEnv->pCryPak->FindNext(h, &cf) == 0);
            gEnv->pCryPak->FindClose(h);
        }
    }

    if (spec.recursive)
    {
        const std::string pattern = gameRelDir + "/*.*";
        _finddata_t cf;
        intptr_t h = gEnv->pCryPak->FindFirst(pattern.c_str(), &cf, 0, true);
        if (h != -1)
        {
            do
            {
                if ((cf.attrib & _A_SUBDIR) == 0)
                    continue;
                if (std::strcmp(cf.name, ".") == 0 || std::strcmp(cf.name, "..") == 0)
                    continue;
                WalkPakDirectory(gameRelDir + "/" + cf.name, spec, out);
            } while (gEnv->pCryPak->FindNext(h, &cf) == 0);
            gEnv->pCryPak->FindClose(h);
        }
    }
}

//! std::filesystem fallback — only for absolute paths outside the game tree.
void WalkDiskRoot(const fs::path& root,
                  const XmlFileProvider::Spec& spec,
                  std::vector<Entry>& out)
{
    std::error_code ec;
    if (!fs::exists(root, ec))
        return;

    if (fs::is_regular_file(root, ec))
    {
        if (root.extension() == ".xml")
            LoadXmlFile(root.u8string(), spec, out);
        return;
    }
    if (!fs::is_directory(root, ec))
        return;

    if (spec.recursive)
    {
        for (const auto& entry : fs::recursive_directory_iterator(root, ec))
            if (entry.is_regular_file() && entry.path().extension() == ".xml")
                LoadXmlFile(entry.path().u8string(), spec, out);
    }
    else
    {
        for (const auto& entry : fs::directory_iterator(root, ec))
            if (entry.is_regular_file() && entry.path().extension() == ".xml")
                LoadXmlFile(entry.path().u8string(), spec, out);
    }
}

} // namespace

XmlFileProvider::XmlFileProvider(Spec spec)
    : m_Spec(std::move(spec))
{
}

std::vector<Entry> XmlFileProvider::Load()
{
    std::vector<Entry> out;

    if (!gEnv || !gEnv->pSystem)
    {
        CryLog("ReferenceCatalog: gEnv->pSystem unavailable; provider load aborted");
        return out;
    }

    for (const fs::path& root : m_Spec.roots)
    {
        if (m_Spec.useCryPak)
        {
            std::string gameRel = root.generic_string();
            while (!gameRel.empty() && (gameRel.back() == '/' || gameRel.back() == '\\'))
                gameRel.pop_back();

            if (root.extension() == ".xml")
                LoadXmlFile(gameRel, m_Spec, out);
            else
                WalkPakDirectory(gameRel, m_Spec, out);
        }
        else
        {
            WalkDiskRoot(root, m_Spec, out);
        }
    }

    if (out.empty())
        CryWarning("ReferenceCatalog: provider for element '{}' loaded zero entries from {} root(s)",
                   m_Spec.elementName, m_Spec.roots.size());
    return out;
}

} // namespace ReferenceCatalog
