#pragma once
#include <boost/bimap.hpp>
#include <boost/variant.hpp>
#include "ConfigNode.h"

struct IChairloaderConfigManager {

	enum class parameterType {
		String,
		Bool,
		Int,
		Uint,
		Int64,
		Uint64,
		Float,
		XMLNode,
		Other
	};

	using ConfigParameterPair = boost::bimap<parameterType, std::string>::value_type;
	using ConfigParameter = boost::variant<std::string, bool, int, unsigned int, int64, uint64, float, pugi::xml_node, boost::blank>;

	// Returns a boost::variant of the parameter. Returns "" if the parameter does not exist;
	// use boost::get<type>(parameter) to get the value. assumes you know the type of the parameter you are getting. 
	virtual ConfigParameter getConfigValue(std::string modName, std::string parameterName)=0;

	// Sets the value of a parameter. Returns true if the parameter was written, false otherwise.
	virtual bool setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type) = 0;

	// Returns the xml node <modName>. Use for custom parsing on the entire config file if needed. 
	virtual pugi::xml_node getConfigNode(std::string modName) = 0;

	/**
	 * \brief Gets a chairloader-formatted parameter from an xml node. Use this function for parsing xmlnode parameters in your config file.
	 * \param node
	 * \param parameterName
	 * \return boost::Variant of the value, or an empty string "" if parameter does not exist
	 */
	virtual ConfigParameter getNodeConfigValue(pugi::xml_node node, std::string parameterName) = 0;

	virtual void setConfigDirty(std::string modName, bool bDirty) = 0;
    virtual bool getConfigDirty(std::string modName) = 0;

	/**
	 * \brief Sets a chairloader-formatted parameter to an xml node. Use this function for writing to xmlnode parameters in your config file.
	 * \param node: xmlnode to be written to
	 * \param parameterName: name of parameter
	 * \param value: string text of the parameter to be set
	 * \param type: type of node
	 * \return true if parameter was set succesfully
	 */
	virtual bool setNodeConfigValue(pugi::xml_node node, std::string parameterName, std::string value, parameterType type) = 0;


	// Returns the XML config file for a modName and stores it internally in the map
	// if the config is defined in Mods/config/ then it will return that file
	//    "Mods/config/modName.xml"
	// if the config is not found there, then it will check for the default config in the mod folder
	//    "Mods/modName/modName_default.xml"
	// Else, it will create a default file for you with only the root modName node. Good luck!
	//    "Mods/config/modName.xml"
	virtual bool loadModConfigFile(std::string modName) = 0;

	// saves the config file to disk for a modName
	virtual bool saveModConfigFile(std::string modName) = 0;

	// intialize mod configs 

	// retrive config file path
	virtual fs::path getConfigPath(std::string modName) = 0;
	virtual fs::path getDefaultConfigPath(std::string modName) = 0;

    virtual ConfigNode getModConfig(std::string modName) = 0;
};