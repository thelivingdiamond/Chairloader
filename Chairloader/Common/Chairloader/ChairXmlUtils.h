#pragma once
#include <Chairloader/IChairXmlUtils.h>

//! Utility functions to work with XML files in CryEngine.
class ChairXmlUtils final : public IChairXmlUtils
{
public:
	// IChairXmlUtils
	virtual pugi::xml_document CryToPugi(XmlNodeRef cryXml) override;
	virtual void CopyNodeToPugi(XmlNodeRef cryNode, pugi::xml_node pugiRootNode) override;
	virtual pugi::xml_document LoadXmlFromBuffer(boost::span<const char> buf, pugi::xml_parse_result* result = nullptr) override;
	virtual pugi::xml_document LoadXmlFromFile(const char* filePath, pugi::xml_parse_result* result = nullptr) override;
	virtual bool IsBinaryXml(boost::span<const char> data) override;

private:
	pugi::xml_document LoadXmlFromBufferInternal(boost::span<const char> buf, pugi::xml_parse_result* result, std::string_view context);
};
