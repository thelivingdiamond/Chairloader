#pragma once
#include <boost/core/span.hpp>

//! Utility functions to work with XML files in CryEngine.
struct IChairXmlUtils
{
	virtual ~IChairXmlUtils() {}

	//! Converts a CryEngine IXmlNode to a pugixml document.
	//! @param	cryXml	CryEngine XML node.
	//! @returns	pugi xml document with the node as its root.
	virtual pugi::xml_document CryToPugi(XmlNodeRef cryXml) = 0;

	//! Copies an IXmlNode into pugiRootNode. A new node will be created in pugiRootNode.
	//! @param	cryNode			Source XML node.
	//! @param	pugiRootNode	Parent for the new node to be created.
	virtual void CopyNodeToPugi(XmlNodeRef cryNode, pugi::xml_node pugiRootNode) = 0;

	//! Loads an XML from buffer. If it's a binary XML, it is automatically converted.
	//! @param	buf		The data buffer.
	//! @param	result	[out] Parse result.
	//! @returns XML document.
	//! @{
	virtual pugi::xml_document LoadXmlFromBuffer(boost::span<const char> buf, pugi::xml_parse_result* result = nullptr) = 0;
	pugi::xml_document LoadXmlFromBuffer(boost::span<const uint8_t> buf, pugi::xml_parse_result* result = nullptr)
	{
		return LoadXmlFromBuffer(boost::span((const char*)buf.data(), buf.size()), result);
	}
	//! @}

	//! Loads an XML from a file using CryEngine file system. If it's a binary XML, it is automatically converted.
	//! @param	buf		The data buffer.
	//! @param	result	[out] Parse result.
	//! @returns XML document.
	virtual pugi::xml_document LoadXmlFromFile(const char* filePath, pugi::xml_parse_result* result = nullptr) = 0;

	//! Checks whether the supplied binary data looks like a binary XML file.
	//! Only checks the header and size.
	//! @param	data	XML data.
	//! @returns true if a binary XML.
	//! @{
	virtual bool IsBinaryXml(boost::span<const char> data) = 0;
	bool IsBinaryXml(boost::span<const uint8_t> data)
	{
		return IsBinaryXml(boost::span((const char*)data.data(), data.size()));
	}
	//! @}
};
