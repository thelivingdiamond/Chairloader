#pragma once
#include <ChairMerger/Export.h>
#include "Cache/IXmlCache.h"
#include "Cache/BaseXmlCache.h"

class CHAIRMERGER_EXPORT DiskXmlCache : public BaseXmlCache
{
public:
    DiskXmlCache();
    ~DiskXmlCache();

    //! @returns The root dir for loading.
    fs::path GetRootDir() const;
    void SetRootDir(const fs::path& value);

    //! Saves all modified files to the directory.
    void ExportModifiedFiles(const fs::path& outRootDir);

protected:
    virtual bool LoadDocument(const fs::path& relPath, const std::string& relPathNorm, pugi::xml_document& outDoc) override;

private:
    fs::path m_RootDir;
};
