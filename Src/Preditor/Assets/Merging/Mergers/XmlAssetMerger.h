#pragma once
#include "Merging/Mergers/AssetMerger.h"

class FileMergingPolicy3;

namespace Assets
{

class AssetMergeSource;
class AssetMergeSystem;

//! Merges XML files using ChairManager's XML merger.
class XmlAssetMerger : public AssetMerger
{
public:
    static constexpr char NAME[] = "xml";

    XmlAssetMerger(AssetMergeSystem* pSys);
    ~XmlAssetMerger();

protected:
    // AssetMerger
    virtual void DoMerge(const std::vector<InputFile>& inputFiles) override;

private:
    AssetMergeSystem* m_pSys = nullptr;
    unsigned m_ParseFlags = pugi::parse_default; //!< Flags for xml_document::load_file

    //! Reads the input file.
    pugi::xml_document ReadFile(const fs::path& file);

    //! Reads the input file. Resolves wildcards.
    pugi::xml_document ReadFile(const InputFile& file);

    //! Resolves wildcards for the document.
    //! Wildcards are Lua expressions embedded into XML attributes.
    void ResolveWildcards(pugi::xml_document& doc, AssetMergeSource* pSource);

    //! Finalizes and writes XML document into the output file.
    void SaveFinalXml(pugi::xml_document& doc, const FileMergingPolicy3& policy);
};

} // namespace Assets
