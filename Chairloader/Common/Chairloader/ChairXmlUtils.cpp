#include <Prey/CrySystem/File/CryFile.h>
#include <Chairloader/ChairXmlUtils.h>

pugi::xml_document ChairXmlUtils::CryToPugi(XmlNodeRef cryXml)
{
	pugi::xml_document pugiDoc;
	CopyNodeToPugi(cryXml, pugiDoc);
	return pugiDoc;
}

void ChairXmlUtils::CopyNodeToPugi(XmlNodeRef cryNode, pugi::xml_node pugiRootNode)
{
	pugi::xml_node pugiNode = pugiRootNode.append_child(cryNode->getTag());

	// Copy attributes
	int attrCount = cryNode->getNumAttributes();
	for (int i = 0; i < attrCount; i++)
	{
		const char* key;
		const char* value;
		cryNode->getAttributeByIndex(i, &key, &value);
		pugiNode.append_attribute(key).set_value(value);
	}

	// Copy text content
	pugiNode.text().set(cryNode->getContent());

	// Copy child nodes
	int childCount = cryNode->getChildCount();
	for (int i = 0; i < childCount; i++)
	{
		XmlNodeRef cryChild = cryNode->getChild(i);
		CopyNodeToPugi(cryChild, pugiNode);
	}
}

pugi::xml_document ChairXmlUtils::LoadXmlFromBuffer(boost::span<const char> buf, pugi::xml_parse_result* result)
{
	return LoadXmlFromBufferInternal(buf, result, "buffer");
}

pugi::xml_document ChairXmlUtils::LoadXmlFromFile(const char* filePath, pugi::xml_parse_result* result)
{
	CCryFile xmlFile;
	
	if (!xmlFile.Open(filePath, "rb"))
	{
		CryError("Load Xml: failed to open file ({})", filePath);

		if (result)
		{
			result->status = pugi::status_file_not_found;
			result->encoding = pugi::encoding_utf8;
			result->offset = 0;
		}

		return pugi::xml_document();
	}

	size_t fileSize = xmlFile.GetLength();
	if (fileSize == 0)
	{
		CryError("Load Xml: file is empty ({})", filePath);

		if (result)
		{
			result->status = pugi::status_no_document_element;
			result->encoding = pugi::encoding_utf8;
			result->offset = 0;
		}

		return pugi::xml_document();
	}

	std::vector<char> buf(fileSize);
	if (xmlFile.ReadRaw(buf.data(), buf.size()) != fileSize)
	{
		CryError("Load Xml: failed to read file ({})", filePath);

		if (result)
		{
			result->status = pugi::status_io_error;
			result->encoding = pugi::encoding_utf8;
			result->offset = 0;
		}

		return pugi::xml_document();
	}

	return LoadXmlFromBufferInternal(buf, result, filePath);
}

bool ChairXmlUtils::IsBinaryXml(boost::span<const char> data)
{
	// File format:
	// signature (8 bytes)
	// size (4 bytes)
	// ...
	constexpr char signature[] = "CryXmlB";
	constexpr uint32_t headerSize = 11 * sizeof(uint32_t);

	if (data.size() < headerSize)
		return false;

	if (memcmp(data.data(), signature, sizeof(signature)))
		return false;

	uint32_t sizeInHeader = 0;
	memcpy(&sizeInHeader, data.data() + sizeof(signature), sizeof(sizeInHeader));
	if (data.size() < sizeInHeader)
		return false;

	return true;
}

pugi::xml_document ChairXmlUtils::LoadXmlFromBufferInternal(boost::span<const char> buf, pugi::xml_parse_result* result, std::string_view context)
{
	try
	{
		if (IsBinaryXml(buf))
		{
			XmlNodeRef cryXml = gEnv->pSystem->GetXmlUtils()->LoadXmlFromBuffer(buf.data(), buf.size());
			if (!cryXml)
			{
				if (result)
				{
					result->status = pugi::status_internal_error;
					result->encoding = pugi::encoding_utf8;
					result->offset = 0;
				}

				return pugi::xml_document();
			}

			pugi::xml_document pugiXml = CryToPugi(cryXml);

			if (result)
			{
				result->status = pugi::status_ok;
				result->encoding = pugi::encoding_utf8;
				result->offset = 0;
			}

			return pugiXml;
		}
		else
		{
			pugi::xml_document pugiDoc;
			pugi::xml_parse_result res = pugiDoc.load_buffer(buf.data(), buf.size(), pugi::parse_default, pugi::encoding_utf8);

			if (!res)
			{
				CryError("Load Xml: {} (offset {}) ({})", res.description(), res.offset, context);
			}

			if (result)
				*result = res;

			return pugiDoc;
		}
	}
	catch (const std::exception& e)
	{
		CryError("Load Xml: exception: {} ({})", e.what(), context);
		return pugi::xml_document();
	}
}
