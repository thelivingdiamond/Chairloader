#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include "../IProvider.h"

namespace ReferenceCatalog
{

//! A provider that scans XML files for elements matching a name and pulls
//! (idAttr, nameAttr) pairs out of them. Handles the common case where a
//! library file is just a flat list of <Foo Id="..." Name="..."/> entries.
//!
//! By default reads through CryPak so vanilla paks, the project overlay, and
//! installed mod paks all merge into one view (engine handles priority).
//! Switch `useCryPak = false` to treat roots as absolute filesystem paths
//! (useful for non-game data, e.g. user-config catalogs).
class XmlFileProvider : public IProvider
{
public:
    struct Spec
    {
        //! Files or directories to scan. Game-relative when `useCryPak == true`
        //! (e.g. "Libs/GameTokens"), absolute otherwise. Single .xml roots are
        //! opened directly; anything else is treated as a directory.
        std::vector<std::filesystem::path> roots;

        //! Element tag whose attributes get extracted. Searched at every
        //! depth via recursion. Case-sensitive.
        std::string elementName;

        //! Attribute name for the entry id (required).
        std::string idAttr;

        //! Attribute name for the entry name (required).
        std::string nameAttr;

        //! When `true` and a root is a directory, recurse into subdirectories.
        bool recursive = false;

        //! When `true` (default), reads via gEnv->pCryPak — picks up vanilla
        //! paks, project overlay, and installed mod paks. When `false`, falls
        //! back to std::filesystem (roots must be absolute).
        bool useCryPak = true;

        //! When `true`, the value of `nameAttr` is run through Cry's
        //! ILocalizationManager when it begins with '@'. Use for libraries
        //! whose display strings live in the loc database (objectives, task
        //! descriptions, etc.). The id field is always preserved raw — only
        //! the human-readable name gets resolved. Falls back silently to the
        //! raw @key if the loc service isn't ready or the lookup fails.
        bool localizeName = false;

        //! Free-form description shown in the catalog browser.
        std::string description;
    };

    explicit XmlFileProvider(Spec spec);

    std::vector<Entry> Load() override;
    std::string Description() const override { return m_Spec.description; }

private:
    Spec m_Spec;
};

} // namespace ReferenceCatalog
