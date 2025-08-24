#include <boost/algorithm/string.hpp>
#include <SHA256/SHA256.h>
#include <ChairMerger/LegacyModConverter.h>
#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/XmlValidator.h>
#include <ChairMerger/XmlMerger3.h>
#include "MetaAttributes.h"
#include "ExcelMerger.h"

static constexpr const char* LOCALIZATION_FOLDER_NAMES[] = {
    "English", // Must be first!
    "French",
    "Italian",
    "German",
    "Spanish",
    "Brazilian",
    "Russian",
    "Polish",
    "Japanese",
    "TChinese",
    "SChinese",
};

LegacyModConverter::ModInfo LegacyModConverter::AnalyzeFolder(const std::string& pakName, const fs::path& modDir)
{
    ModInfo result;
    result.pakType = EPakType::GameData;

    if (fs::exists(modDir / "levelinfo.xml"))
    {
        // Found LevelInfo. This is a level pak.
        result.pakType = EPakType::Level;

        // Read level name from LevelInfo
        // Level name looks like "gamesdk/levels/campaign/station/exterior"
        pugi::xml_document doc = XmlUtils::LoadDocument(modDir / "levelinfo.xml");
        std::string levelName = doc.first_child().attribute("Name").as_string();

        if (levelName.empty())
            throw std::runtime_error("Level name not set in LevelInfo");

        if (boost::istarts_with(levelName, "GameSDK/"))
        {
            // Strip GameSDK
            levelName = levelName.substr(8);
        }

        levelName += "/level"; // Chairloader stores level files there
        result.outputRelativePath = fs::u8path(levelName);
        return result;
    }
    
    // Check if all files begin with text_ or voice_
    bool isLocalization = true;

    for (const fs::directory_entry& i : fs::recursive_directory_iterator(modDir))
    {
        if (!i.is_regular_file())
            continue;

        fs::path filePath = i.path();

        // ark/campaign/levels contains unprefixed files. Skip them.
        if (boost::iequals(filePath.parent_path().filename().u8string(), "levels"))
            continue;

        std::string name = i.path().filename().u8string();

        if (!boost::istarts_with(name, "text_") && !boost::istarts_with(name, "voice_"))
        {
            // Not localization
            isLocalization = false;
            break;
        }
    }

    if (isLocalization)
    {
        result.pakType = EPakType::Localization;

        // Check pak name for language
        // Use English if not found
        const char* foundLanguage = LOCALIZATION_FOLDER_NAMES[0];

        for (const char* langName : LOCALIZATION_FOLDER_NAMES)
        {
            std::string prefix = fmt::format("{}_xml", langName);

            if (boost::istarts_with(pakName, prefix))
            {
                foundLanguage = langName;
                break;
            }
        }

        result.outputRelativePath = fs::u8path(fmt::format("Localization/{}_xml", foundLanguage));
    }

    return result;
}

void LegacyModConverter::PrePatchDocument(
    const fs::path& relPath,
    pugi::xml_document& legacyModDoc,
    const FileMergingPolicy3& policy)
{
    std::string fileName = relPath.filename().u8string();
    XmlErrorStack stack(fileName.c_str());

    if (boost::istarts_with(fileName, "mission_"))
    {
        // Remove UseInIndoors from Object. Not used by the game.
        // Found in Talos In The Dark
        // https://www.nexusmods.com/prey2017/mods/64
        bool done = false;

        for (pugi::xml_node node : legacyModDoc.first_child().child("Objects").children("Object"))
        {
            done |= node.remove_attribute("UseInIndoors");
        }

        if (done)
            AddLog(severityLevel::warning, "Removed UseInIndoors attribute", stack);
    }
    else if (boost::iequals(relPath.parent_path().filename().u8string(), "EntityArchetypes"))
    {
        std::set<std::string_view> ids;

        for (pugi::xml_node node : legacyModDoc.first_child().children("EntityPrototype"))
        {
            pugi::xml_attribute nameAttr = node.attribute("Name");
            pugi::xml_attribute classAttr = node.attribute("Class");
            pugi::xml_attribute idAttr = node.attribute("Id");
            pugi::xml_attribute aidAttr = node.attribute("ArchetypeId");
            const char* id = idAttr.as_string();

            if (id[0] == '\0')
                continue;

            // Fix duplicate GUIDs
            // Found in PREY for Death
            // https://www.nexusmods.com/prey2017/mods/1
            bool inserted = ids.insert(std::string_view(id)).second;

            if (!inserted)
            {
                // Found duplicate
                const char* name = nameAttr.as_string();
                const char* aid = aidAttr.as_string();
                SHA256 hash;
                hash.update(name);
                hash.update(aid);
                SHA256::Digest digest = hash.digest();

                std::string guid = SHA256::toString(digest.data());
                guid.resize(38);
                guid[0] = '{';
                guid[9] = '-';
                guid[14] = '-';
                guid[19] = '-';
                guid[24] = '-';
                guid[37] = '}';

                for (char& c : guid)
                {
                    if (c >= 'a' && c <= 'f')
                        c = c - 'a' + 'A';
                }

                AddLog(severityLevel::warning, fmt::format("Changed duplicate Id {} -> {}", id, guid), stack);
                idAttr.set_value(guid.c_str());
            }

            // Fix empty class of Data.Notes.Stickynote.Sorry
            // Found in PREY for Death
            // https://www.nexusmods.com/prey2017/mods/1
            if (!classAttr.as_string()[0] && boost::istarts_with(nameAttr.as_string(), "Data.Notes.Stickynote"))
                classAttr.set_value("ArkPages");

            // Rename duplicate Ammo.RecyclerGrenades
            // Found in PREY for Death
            // https://www.nexusmods.com/prey2017/mods/1
            if (aidAttr.as_ullong() == 10739735956177611862ULL)
            {
                nameAttr.set_value("Ammo.RecyclerGrenades.PFD");
            }
        }
    }

    // Run after manual fixes
    RemoveDuplicateKeys(legacyModDoc.first_child(), policy.GetRootNode(), stack);
}

void LegacyModConverter::PostPatchDocument(
    const fs::path& relPath,
    pugi::xml_document& modDoc,
    const FileMergingPolicy3& policy)
{
    std::string fileName = relPath.filename().u8string();

    if (boost::iequals(fileName, "ArkPickups.xml"))
    {
        pugi::xml_node rootNode = modDoc.first_child();
        pugi::xml_node curNode = rootNode.first_child();

        while (curNode)
        {
            pugi::xml_node thisNode = curNode;
            curNode = curNode.next_sibling();

            pugi::xml_attribute actionAttr = thisNode.attribute(MetaAttributes::ACTION);

            if (actionAttr && !strcmp(actionAttr.as_string(), "delete"))
            {
                const char* name = thisNode.attribute("Name").as_string();

                if (!strcmp(name, "Medical.TraumaPharmas.AntiBleed_2") ||
                    !strcmp(name, "Medical.TraumaPharmas.AntiBurn_2") ||
                    !strcmp(name, "Medical.TraumaPharmas.AntiConcussion_2") ||
                    !strcmp(name, "Medical.TraumaPharmas.AntiCripple_2"))
                {
                    // Restore post-Mooncrash archetypes
                    rootNode.remove_child(thisNode);
                }
            }
        }
    }
}

bool LegacyModConverter::ConvertNode(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    bool hasChanges = false;

    hasChanges |= ConvertAttributes(preyNode, legacyModNode, outNode, policy, errorStack);
    hasChanges |= ConvertText(preyNode, legacyModNode, outNode, policy, errorStack);

    switch (collection.type)
    {
    case MergingPolicy3::ECollectionType::None:
    {
        // No children allowed
        bool hasChildren = XmlValidator::NodeHasChildElements(legacyModNode);
        if (hasChildren)
        {
            AddLog(
                severityLevel::error,
                "Collection type is none, node may not have children",
                errorStack);
        }

        break;
    }
    case MergingPolicy3::ECollectionType::ReplaceOnly:
    case MergingPolicy3::ECollectionType::Array:
    {
        // Check if children are different
        if (!XmlUtils::XmlChildrenAreEqual(preyNode, legacyModNode))
        {
            // Replace all children
            hasChanges = true;

            outNode.append_attribute(MetaAttributes::ACTION).set_value("replaceChildren");

            for (pugi::xml_node childNode : legacyModNode)
            {
                outNode.append_copy(childNode);
            }
        }

        break;
    }
    case MergingPolicy3::ECollectionType::Dict:
    {
        hasChanges |= ConvertDict(preyNode, legacyModNode, outNode, policy, errorStack);
        break;
    }
    default:
        throw std::logic_error("Not implemented");
    }

    return hasChanges;
}

bool LegacyModConverter::ConvertDocument(
    const pugi::xml_document& preyDoc,
    const pugi::xml_document& legacyModDoc,
    pugi::xml_document& outDoc,
    const FileMergingPolicy3& policy)
{
    if (policy.GetMethod() == FileMergingPolicy3::EMethod::ReadOnly)
        throw std::logic_error("This file can't be merged");

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        throw std::logic_error("Excel files must use a different method");

    if (policy.GetMethod() == FileMergingPolicy3::EMethod::Replace)
    {
        // Replace the entire file
        if (XmlUtils::XmlNodesAreEqual(preyDoc, legacyModDoc))
            return false;

        outDoc.reset(preyDoc);
        return true;
    }

    CRY_ASSERT(policy.GetMethod() == FileMergingPolicy3::EMethod::Merge);

    outDoc.reset();
    pugi::xml_node preyNode = preyDoc.first_child();
    pugi::xml_node legacyModNode = legacyModDoc.first_child();
    pugi::xml_node outNode = outDoc.append_child(preyNode.name());
    XmlErrorStack outErrorStack(preyNode.name());

    // Add xmlns attributes
    constexpr const char* XMLNS_ATTRS[] = {
        "xmlns",
        "xmlns:ch",
        "xmlns:xsi",
        "xsi:schemaLocation",
    };

    for (const char* attrName : XMLNS_ATTRS)
    {
        if (pugi::xml_attribute attr = preyNode.attribute(attrName))
            outNode.append_attribute(attr.name()).set_value(attr.as_string());
    }

    // Convert root node
    return ConvertNode(preyNode, legacyModNode, outNode, policy.GetRootNode(), outErrorStack);
}

bool LegacyModConverter::ConvertExcelDocument(
    const pugi::xml_document& preyDoc,
    const pugi::xml_document& legacyModDoc,
    pugi::xml_document& outDoc,
    const FileMergingPolicy3& policy)
{
    if (policy.GetMethod() != FileMergingPolicy3::EMethod::Excel2003)
        throw std::logic_error("Not an Excel file policy");

    // Parse both spreadsheets
    ExcelTable preyTable;
    preyTable.ReadTable(policy.GetExcelKeyColName(), preyDoc);

    ExcelTable legacyModTable;
    legacyModTable.ReadTable(policy.GetExcelKeyColName(), legacyModDoc);

    ExcelTable outTable;
    outTable.columnNames = legacyModTable.columnNames;
    outTable.keyColumnIdx = legacyModTable.keyColumnIdx;

    // Compare each key in mod with prey
    std::vector<size_t> colsToAdd;

    for (size_t rowIdx = 0; rowIdx < legacyModTable.rows.size(); rowIdx++)
    {
        colsToAdd.clear();
        const ExcelTable::Row& row = legacyModTable.rows[rowIdx];

        if (row[legacyModTable.keyColumnIdx].empty())
            continue;

        // Find the Prey row with the same key
        const std::string& rowKey = row[legacyModTable.keyColumnIdx];
        auto preyRowIt = std::find_if(preyTable.rows.begin(), preyTable.rows.end(), [&](const ExcelTable::Row& x) { return x[preyTable.keyColumnIdx] == rowKey; });

        if (preyRowIt == preyTable.rows.end())
        {
            // Row not found in Prey files. Add it.
            outTable.rows.push_back(row);
            continue;
        }

        for (size_t colIdx = 0; colIdx < row.size(); colIdx++)
        {
            const std::string& colName = legacyModTable.columnNames[colIdx];
            const std::string& cellValue = row[colIdx];

            if (colName.empty() || cellValue.empty())
                continue;

            // Find the column in prey
            auto preyColNameIt = std::find(preyTable.columnNames.begin(), preyTable.columnNames.end(), colName);

            if (preyColNameIt == preyTable.columnNames.end())
            {
                // Column doesn't exist and the cell has the value. Add the row
                colsToAdd.push_back(colIdx);
                continue;
            }

            // Compare cell values
            size_t preyColIdx = preyColNameIt - preyTable.columnNames.begin();

            if ((*preyRowIt)[preyColIdx] != cellValue)
            {
                // Column is different from Prey
                colsToAdd.push_back(colIdx);
            }
        }

        if (colsToAdd.empty())
        {
            // No columns to add
            continue;
        }

        ExcelTable::Row newRow(outTable.columnNames.size());
        newRow[outTable.keyColumnIdx] = row[legacyModTable.keyColumnIdx];

        for (size_t colIdx : colsToAdd)
        {
            newRow[colIdx] = row[colIdx];
        }

        outTable.rows.emplace_back(std::move(newRow));
    }

    if (outTable.rows.empty())
        return false;

    // Save the table
    outDoc = outTable.ExportExcelXml();
    return true;
}

void LegacyModConverter::AddLog(severityLevel level, std::string_view message, const XmlErrorStack& errorStack)
{
    m_Logs.push_back(LogEntry {
        level, std::string(message), errorStack.GetStackTrace()
    });
}

bool LegacyModConverter::ConvertAttributes(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    bool hasChanges = false;

    auto fnConvertAttribute = [&](const char* name, const MergingPolicy3::Attribute* pAttrPolicy)
    {
        const pugi::xml_attribute preyAttr = preyNode.attribute(name);
        const pugi::xml_attribute legacyModAttr = legacyModNode.attribute(name);

        if (!preyAttr && !legacyModAttr)
        {
            // Attribute doesn't exist. Ignore it.
            return;
        }

        if (pAttrPolicy && pAttrPolicy->prohibitInMods)
        {
            // Attribute is not allowed in mods
            return;
        }

        if (preyAttr && !legacyModAttr)
        {
            // Mod removed the attribute
            if (pAttrPolicy && !pAttrPolicy->allowEmpty)
            {
                AddLog(
                    severityLevel::warning,
                    fmt::format("Mod has removed the attribute '{}'. This attribute can't be empty. It is left as-is.", name),
                    errorStack);
                return;
            }
                
            AddLog(
                severityLevel::warning,
                fmt::format("Mod has removed the attribute '{}'. This attribute will be set to an empty string.", name),
                errorStack);

            outNode.append_attribute(name).set_value("");
            hasChanges |= true;
            return;
        }

        if (preyAttr && legacyModAttr)
        {
            // Both attributes exist. Check if they are different
            if (!strcmp(preyAttr.as_string(), legacyModAttr.as_string()))
                return;
        }

        // Add the attribute
        outNode.append_attribute(name).set_value(legacyModAttr.as_string());
        hasChanges |= true;
    };

    // Convert known attributes first
    for (const MergingPolicy3::Attribute& attr : policy.GetAttributes())
    {
        fnConvertAttribute(attr.name.c_str(), &attr);
    }

    // Convert unknown attributes
    for (pugi::xml_attribute attr : legacyModNode.attributes())
    {
        // Skip meta attributes
        if (MetaAttributes::IsKnownMetaAttr(attr))
            continue;

        auto it = std::find_if(policy.GetAttributes().begin(), policy.GetAttributes().end(), [&](auto& x) { return x.name == attr.name(); });

        if (it == policy.GetAttributes().end())
        {
            // Unknown attribute
            if (!policy.IsAllowingUnknownAttributes())
            {
                AddLog(
                    severityLevel::error,
                    fmt::format("Mod contains unknown attribute '{}'", attr.name()),
                    errorStack);
            }

            fnConvertAttribute(attr.name(), nullptr);
        }
    }

    return hasChanges;
}

bool LegacyModConverter::ConvertText(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    pugi::xml_text preyText = preyNode.text();
    pugi::xml_text legacyModText = legacyModNode.text();

    if (legacyModText.empty() && !preyText.empty())
    {
        // Remove text
        preyText.set("");
        return true;
    }
    else if (
        ( legacyModText.empty() &&  preyText.empty()) ||
        (!legacyModText.empty() && !preyText.empty() && !strcmp(legacyModText.as_string(), preyText.as_string())))
    {
        // Text is equal
        return false;
    }

    // Set text
    if (policy.GetTextType().empty())
    {
        AddLog(
            severityLevel::error,
            "Mod node contains text, which is not allowed",
            errorStack);
    }

    outNode.text().set(legacyModText.as_string());
    return true;
}

bool LegacyModConverter::ConvertDict(
    const pugi::xml_node& preyNode,
    const pugi::xml_node& legacyModNode,
    pugi::xml_node outNode,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();
    int index = 0;
    bool hasChanges = false;

    auto fnAddKeyAttrs = [&](const pugi::xml_node& sourceNode, pugi::xml_node& destNode)
    {
        for (const std::string& keyAttrName : collection.keyChildAttributes)
        {
            pugi::xml_attribute srcKeyAttr = sourceNode.attribute(keyAttrName.c_str());

            if (!srcKeyAttr)
                continue;

            const char* value = sourceNode.attribute(keyAttrName.c_str()).as_string();
            destNode.append_attribute(keyAttrName.c_str()).set_value(value);
        }
    };

    for (const pugi::xml_node legacyModChildNode : legacyModNode.children())
    {
        if (XmlUtils::IsTextNode(legacyModChildNode))
            continue;

        XmlErrorStack legacyModChildErrorStack = errorStack.GetChild(legacyModChildNode);
        legacyModChildErrorStack.SetIndex(index);

        const MergingPolicy3* pChildPolicy = policy.FindChildNode(legacyModChildNode.name());

        if (!pChildPolicy)
            legacyModChildErrorStack.ThrowException(fmt::format("Node '{}' not found in merging policy", legacyModChildNode.name()));

        const pugi::xml_node& preyChildNode = XmlMerger3::FindBaseNodeByModKey(preyNode, legacyModChildNode, policy, legacyModChildErrorStack);

        if (preyChildNode)
        {
            // An existing node. Merge it.
            pugi::xml_node modChildNode = outNode.append_child(legacyModChildNode.name());

            // Add key attributes
            fnAddKeyAttrs(legacyModChildNode, modChildNode);

            bool hasChangesInNew = ConvertNode(preyChildNode, legacyModChildNode, modChildNode, *pChildPolicy, legacyModChildErrorStack);

            if (!hasChangesInNew)
            {
                // No changes. Erase the created node.
                outNode.remove_child(modChildNode);
            }
            else
            {
                hasChanges = true;
            }
        }
        else
        {
            // New node
            pugi::xml_node newNode = outNode.append_copy(legacyModChildNode);
            FixUpNewNode(newNode, *pChildPolicy, legacyModChildErrorStack);
            hasChanges = true;
        }

        index++;
    }

    // Check for deleted nodes
    index = 0;

    for (const pugi::xml_node preyChildNode : preyNode.children())
    {
        if (XmlUtils::IsTextNode(preyChildNode))
            continue;

        XmlErrorStack preyChildNodeErrorStack = errorStack.GetChild(preyChildNode);
        preyChildNodeErrorStack.SetIndex(index);

        const pugi::xml_node& legacyModChildNode = XmlMerger3::FindBaseNodeByModKey(legacyModNode, preyChildNode, policy, preyChildNodeErrorStack);

        if (!legacyModChildNode)
        {
            // Node was removed in the mod
            pugi::xml_node modChildNode = outNode.append_child(preyChildNode.name());
            fnAddKeyAttrs(preyChildNode, modChildNode);
            modChildNode.append_attribute(MetaAttributes::ACTION).set_value("delete");
            hasChanges = true;
        }
    }

    return hasChanges;
}

void LegacyModConverter::RemoveDuplicateKeys(
    pugi::xml_node node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    const MergingPolicy3::Collection& collection = policy.GetCollection();

    if (collection.type == MergingPolicy3::ECollectionType::Dict)
    {
        std::map<std::string, pugi::xml_node> keyToNodeMap;
        pugi::xml_node curNode = node.last_child();

        // Iterate in reverse so the last duplicate element remains
        while (curNode)
        {
            XmlErrorStack childErrorStack = errorStack.GetChild(curNode);
            std::string key;

            if (collection.keyChildName)
            {
                key += curNode.name();
                key += '|';
            }

            if (collection.keyChildText)
            {
                key += curNode.text().as_string();
                key += '|';
            }

            for (const std::string& attrName : collection.keyChildAttributes)
            {
                pugi::xml_attribute attr = curNode.attribute(attrName.c_str());

                if (attr)
                    key += attr.as_string();
                else
                    key += "<not set>";

                key += '|';
            }

            bool inserted = keyToNodeMap.insert({ key, curNode }).second;

            if (!inserted)
            {
                AddLog(severityLevel::warning, fmt::format("Removed duplicate item {}", key), childErrorStack);
                pugi::xml_node toRemove = curNode;
                curNode = curNode.previous_sibling();
                node.remove_child(toRemove);
            }
            else
            {
                curNode = curNode.previous_sibling();
            }
        }
    }

    // Recurse down whatever is left
    for (pugi::xml_node& childNode : node.children())
    {
        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        const MergingPolicy3* childPolicy = policy.FindChildNode(childNode.name());

        if (!childPolicy)
            continue; // Validation will handle this

        RemoveDuplicateKeys(childNode, *childPolicy, childErrorStack);
    }
}

void LegacyModConverter::FixUpNewNode(
    pugi::xml_node& node,
    const MergingPolicy3& policy,
    const XmlErrorStack& errorStack)
{
    // Remove prohibited attributes
    for (const MergingPolicy3::Attribute& poilicyAttr : policy.GetAttributes())
    {
        if (poilicyAttr.prohibitInMods)
            node.remove_attribute(poilicyAttr.name.c_str());
    }

    // Recurse down
    for (pugi::xml_node& childNode : node.children())
    {
        if (XmlUtils::IsTextNode(childNode))
            continue;

        XmlErrorStack childErrorStack = errorStack.GetChild(childNode);
        const MergingPolicy3* childPolicy = policy.FindChildNode(childNode.name());

        if (!childPolicy)
            continue; // Validation will handle this

        FixUpNewNode(childNode, *childPolicy, childErrorStack);
    }
}
