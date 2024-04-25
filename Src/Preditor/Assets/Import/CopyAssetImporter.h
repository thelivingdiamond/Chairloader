#pragma once
#include "Import/AssetImporter.h"

namespace Assets
{

//! An asset importer that copies the input file with a different extension.
class CopyAssetImporter : public AssetImporter
{
public:
    static constexpr char NAME[] = "copy";
    static constexpr char XML_NODE[] = "CopyAssetImporter";

protected:
    // AssetImporter
    virtual void Import() override;
};

} // namespace Assets
