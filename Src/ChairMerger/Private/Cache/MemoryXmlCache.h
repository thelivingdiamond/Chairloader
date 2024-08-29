#pragma once
#include <ChairMerger/Export.h>
#include "Cache/BaseXmlCache.h"

class CHAIRMERGER_EXPORT MemoryXmlCache : public BaseXmlCache
{
public:
    MemoryXmlCache();
    ~MemoryXmlCache();

protected:
    // BaseXmlCache
    virtual bool LoadDocument(const fs::path& relPath, const std::string& relPathNorm, pugi::xml_document& outDoc) override;
};
