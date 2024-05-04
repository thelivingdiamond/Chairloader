#pragma once
#include <Chairloader/Private/XmlUtils.h>

class XmlTestUtils
{
public:
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
