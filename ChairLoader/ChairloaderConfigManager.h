#pragma once
#include <pugixml.hpp>
#include <filesystem>


#include "ChairLoader/IChairloaderConfigManager.h"

class ChairloaderConfigManager : public IChairloaderConfigManager{
public:
	/* Example configuration file
	 *
	 	<?xml version="1.0"?>
		<ExampleMod version="1.0">
		    <testString type="string">The quick brown fox fuckin jumped over the lazy dogw. What happens next?</testString>
		    <testBool type="bool">1</testBool>
		    <testInt type="int">-691</testInt>
		    <testUInt type="uint">421</testUInt>
		    <testInt64 type="int64" readonly="1">-69000000001</testInt64>
		    <testUInt64 type="uint64">42000000001</testUInt64>
		    <testFloat type="float">69.6969</testFloat>
		    <testXMLNode type="xmlnode" readonly="1">
		        <node1>IDK put whatever you want here</node1>testXMLNode
		    </testXMLNode>
		</ExampleMod>
	 * Read only has to be set explicitly in the default configuration file. It will disallow changing the value in the config GUI manager
	 */

	// Enum for determining type of the parameter in a config parameter. Other will return the raw string.
	// Bimap for storing the parameter type and the corresponding string.
	

	// store config files
	


	// TODO: load files from a given list of modNames (handled during mod registration)
	// Constructor and destructor
	ChairloaderConfigManager();

	// save all configs to file on destruction
	~ChairloaderConfigManager();

	// Draw the GUI menu
	void Draw(bool* bShow);

	/**
	 \brief if any config files are dirty save them to disk
	*/
	void Update();

	// retrieve the typed value of a parameter
	ConfigParameter ParseXmlTextToParameter(pugi::xml_node parameterNode);

	// Returns a boost::variant of the parameter. Returns boost::blank if the parameter does not exist;
	// use boost::get<type>(parameter) to get the value. assumes you know the type of the parameter you are getting. 
	ConfigParameter getConfigValue(std::string modName, std::string parameterName) override;

	// Sets the value of a parameter. Returns true if the parameter was written, false otherwise.
	bool setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type) override;

	// Returns the xml node <modName>. Use for custom parsing on the entire config file if needed. 
	pugi::xml_node* getConfigNode(std::string modName) override;

	/**
	 * \brief Gets a chairloader-formatted parameter from an xml node. Use this function for parsing xmlnode parameters in your config file. 
	 * \param node 
	 * \param parameterName 
	 * \return boost::Variant of the value, will be type boost::blank if parameter does not exist
	 */
	ConfigParameter getNodeConfigValue(pugi::xml_node node, std::string parameterName) override;

	void setConfigDirty(std::string modName, bool bDirty) override;


	/**
	 * \brief Sets a chairloader-formatted parameter to an xml node. Use this function for writing to xmlnode parameters in your config file. 
	 * \param node: xmlnode to be written to
	 * \param parameterName: name of parameter
	 * \param value: string text of the parameter to be set
	 * \param type: type of node
	 * \return true if parameter was set succesfully
	 */
	bool setNodeConfigValue(pugi::xml_node node, std::string parameterName, std::string value, parameterType type) override;



	// Returns the XML config file for a modName and stores it internally in the map
	// if the config is defined in Mods/config/ then it will return that file
	//    "Mods/config/modName.xml"
	// if the config is not found there, then it will check for the default config in the mod folder
	//    "Mods/modName/modName_default.xml"
	// Else, it will create a default file for you with only the root modName node. Good luck!
	//    "Mods/config/modName.xml"
	bool loadModConfigFile(std::string modName) override;

	// saves the config file to disk for a modName
	bool saveModConfigFile(std::string modName) override;

	// intialize mod configs 
	bool copyDefaultModConfigFile(std::string modName);
	bool createDefaultModConfig(std::string modName); // someone was slacking so they don't get shit

	// retrive config file path
	fs::path getConfigPath(std::string modName);
	fs::path getDefaultConfigPath(std::string modName);
private:
	// store configs in a bimap
	boost::bimap<parameterType, std::string> parameterNameMap;
	std::map<std::string, pugi::xml_document*> modConfigs;
	std::map<std::string, bool> modConfigsDirty;

	const std::string modName = "ConfigManager";

};

extern ChairloaderConfigManager* gConf;