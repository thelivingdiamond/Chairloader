#include <gtest/gtest.h>
#include "XmlTestUtils.h"

pugi::xml_document XmlTestUtils::LoadDocument(const fs::path& path, unsigned parseOptions)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(path.c_str(), parseOptions);

    if (!result)
    {
        throw std::runtime_error(fmt::format(
            "Failed to read XML document.\n"
            "Path: {}\n"
            "Offset: {}\n"
            "{}",
            path.u8string(), result.offset, result.description()
        ));
    }

    return doc;
}

std::tuple<pugi::xml_document, XmlErrorStack> XmlTestUtils::LoadDocumentWithErrorStack(const fs::path& path, unsigned parseOptions)
{
    pugi::xml_document doc = LoadDocument(path, parseOptions);
    XmlErrorStack errorStack(path);
    return std::make_tuple(std::move(doc), std::move(errorStack));
}

bool XmlTestUtils::CheckNodesEqual(const pugi::xml_node& lhs, const pugi::xml_node& rhs)
{
    bool result = CompareNodes(lhs, rhs, "");

    if (result)
        return true;

    constexpr unsigned PRINT_FLAGS = pugi::format_indent | pugi::format_indent_attributes;
    std::stringstream lhsText, rhsText;
    lhs.print(lhsText, "  ", PRINT_FLAGS);
    rhs.print(rhsText, "  ", PRINT_FLAGS);
    ADD_FAILURE() << "LHS = " << lhsText.str();
    ADD_FAILURE() << "RHS = " << rhsText.str();
    return false;
}

bool XmlTestUtils::CompareNodes(const pugi::xml_node& lhs, const pugi::xml_node& rhs, std::string nodePath)
{
    // Compare names
    if (strcmp(lhs.name(), rhs.name()))
    {
        // Non-equal names
        ADD_FAILURE() << nodePath << ": node name '" << lhs.name() << "' != '" << rhs.name() << "'";
        return false;
    }

    nodePath = nodePath + "/" + lhs.name();

    // Compare text
    if (strcmp(lhs.text().as_string(), rhs.text().as_string()))
    {
        // Non-equal contents
        ADD_FAILURE() << nodePath << ": content '" << lhs.text().as_string() << "' != '" << rhs.text().as_string() << "'";
        return false;
    }

    // Compare attributes
    {
        auto attrl = lhs.attributes();
        auto attrr = rhs.attributes();
        auto itl = attrl.begin();
        auto itr = attrr.begin();

        for (;;)
        {
            if (itl == attrl.end() && itr == attrr.end())
            {
                // Equal size and contents
                break;
            }
            else if (itl == attrl.end() || itr == attrr.end())
            {
                // One attr list is shorter
                ADD_FAILURE() << nodePath << ": attribute list is shorter in " << (itl == attrl.end() ? "lhs" : "rhs");
                return false;
            }

            assert(itl != attrl.end() && itr != attrr.end());

            // Compare attr contents
            if (strcmp(itl->name(), itr->name()))
            {
                // Non-equal names
                ADD_FAILURE() << nodePath << ": attribute name '" << itl->name() << "' != '" << itr->name() << "'";
                return false;
            }

            if (strcmp(itl->as_string(), itr->as_string()))
            {
                // Non-equal values
                ADD_FAILURE() << nodePath << "#" << itl->name() << ": attribute value '" << itl->as_string() << "' != '" << itr->as_string() << "'";
                return false;
            }

            ++itl;
            ++itr;
        }
    }

    // Compare children
    {
        auto childrenl = lhs.children();
        auto childrenr = rhs.children();
        auto itl = childrenl.begin();
        auto itr = childrenr.begin();
        int index = 0;

        for (;;)
        {
            if (itl == childrenl.end() && itr == childrenr.end())
            {
                // Equal size and contents
                break;
            }
            else if (itl == childrenl.end() || itr == childrenr.end())
            {
                // One child list is shorter
                ADD_FAILURE() << nodePath << ": child list is shorter in " << (itl == childrenl.end() ? "lhs" : "rhs");
                return false;
            }

            assert(itl != childrenl.end() && itr != childrenr.end());

            if (!CompareNodes(*itl, *itr, fmt::format("{}[{}]", nodePath, index)))
            {
                // Non-equal children
                ADD_FAILURE() << nodePath << ": child nodes are not equal";
                return false;
            }

            ++itl;
            ++itr;
            ++index;
        }
    }

    // All checks passed
    return true;
}
