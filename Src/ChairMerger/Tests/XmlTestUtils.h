#pragma once
#include <Chairloader/Private/XmlUtils.h>

class XmlTestUtils
{
public:
    //! Loads an XML document from file. Throws on error.
    //! @param  path            Path to the file.
    //! @param  parseOptions    Options to load_file.
    static pugi::xml_document LoadDocument(const fs::path& path, unsigned parseOptions = pugi::parse_default);
    static std::tuple<pugi::xml_document, XmlErrorStack> LoadDocumentWithErrorStack(const fs::path& path, unsigned parseOptions = pugi::parse_default);

    //! Checks that two XML nodes are identical (contain identical values recursively).
    //! If not, causes the current test to fail and print detailed info.
    //! @param  lhs     The left-hand side node
    //! @param  rhs     The right-hand side node.
    //! @returns Whether the nodes are identical.
    //! @{
    static bool CheckNodesEqual(const pugi::xml_node& lhs, const pugi::xml_node& rhs);
    //! @}

private:
    static bool CompareNodes(const pugi::xml_node& lhs, const pugi::xml_node& rhs, std::string nodePath);
};
