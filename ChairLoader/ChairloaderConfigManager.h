#pragma once
#include "OverlayLog.h"
#include <pugixml.hpp>
#include <filesystem>
#include <boost/bimap.hpp>
#include <boost/variant.hpp>
#include "ChairLoader.h"

class ChairloaderConfigManager {
public:
	/* Example configuration file
	 *
	 	<?xml version="1.0"?>
		<ExampleMod>
		    <testString type="string">The quick brown fox fuckin jumped over the lazy dogwhat if I add \n???? what happens next</testString>
		    <testBool type="bool">1</testBool>
		    <testInt type="int">-691</testInt>
		    <testUInt type="uint">421</testUInt>
		    <testInt64 type="int64" readonly="1">-69000000001</testInt64>
		    <testUInt64 type="uint64">42000000001</testUInt64>
		    <testFloat type="float">69.6969</testFloat>
		    <testXMLNode type="xmlnode" readonly="1">
		        <node1>IDK put whatever tf you want here</node1>testXMLNode
		    </testXMLNode>
		</ExampleMod>
	 * Read only has to be set explicitly in the default configuration file. It will disallow changing the value in the config GUI manager
	 */

	// Enum for determining type of the parameter in a config parameter. Other will return the raw string.
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
	// Bimap for storing the parameter type and the corresponding string.
	using ConfigParameterPair = boost::bimap<parameterType, std::string>::value_type;
	using ConfigParameter = boost::variant<std::string, bool, int, unsigned int, int64, uint64, float, pugi::xml_node>;

	// store config files
	


	// TODO: load files from a given list of modNames (handled during mod registration)
	// Constructor and destructor
	ChairloaderConfigManager();

	// save all configs to file on destruction
	~ChairloaderConfigManager();

	// Draw the GUI menu
	void Draw(bool* bShow);

	// if any config files are dirty save them to disk
	void Update();

	// retrieve the typed value of a parameter
	ConfigParameter ParseXmlTextToParameter(pugi::xml_node parameterNode);

	// Returns a boost::variant of the parameter. Returns "" if the parameter does not exist;
	// use boost::get<type>(parameter) to get the value. assumes you know the type of the parameter you are getting. 
	ConfigParameter getConfigValue(std::string modName, std::string parameterName);

	// Sets the value of a parameter. Returns true if the parameter was written, false otherwise.
	bool setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type);

	// Returns the xml node <modName>. Use for custom parsing on the entire config file if needed. 
	pugi::xml_node* getConfigNode(std::string modName);

	// Returns the XML config file for a modName and stores it internally in the map
	// if the config is defined in Mods/config/ then it will return that file
	//    "Mods/config/modName.xml"
	// if the config is not found there, then it will check for the default config in the mod folder
	//    "Mods/modName/modName_default.xml"
	// Else, it will create a default file for you with only the root modName node. Good luck!
	//    "Mods/config/modName.xml"
	bool loadModConfigFile(std::string modName);

	// saves the config file to disk for a modName
	bool saveModConfigFile(std::string modName);

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

	// TODO: redo the chairloaderConfigFile
	pugi::xml_document chairloaderConfigFile;
	const fs::path chairloaderConfigFilePath = fs::path("./Mods/config/chairloader.xml");
	
	
	const char* rootNode = "config";
	const std::string modName = "Chairloader.ConfigManager";

};

