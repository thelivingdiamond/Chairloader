#pragma once
#include "pch.h"
#include "ChairloaderConfigManager.h"


#include "Logging.h"


ChairloaderConfigManager::ChairloaderConfigManager() {
	parameterNameMap.insert(ConfigParameterPair(parameterType::String, "string"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Bool, "bool"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Int, "int"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Uint, "uint"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Int64, "int64"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Uint64, "uint64"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Float, "float"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::XMLNode, "xmlnode"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Other, "other"));
	loadChairloaderConfigFile();
}
ChairloaderConfigManager::~ChairloaderConfigManager() {
	saveChairloaderConfigFile();
}

void ChairloaderConfigManager::Draw(bool* bShow) {
	if(ImGui::Begin("Config Menu", bShow)) {
		if (ImGui::BeginTabBar("configs")){
			for(auto & entry: modConfigs) {
				if(ImGui::BeginTabItem(entry.first.c_str())) {
					ImGui::Text("Config: %s", entry.first.c_str());
					if (ImGui::BeginTable(("ConfigTable" + entry.first).c_str(), 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_SizingStretchProp)) {
						// auto columnFlags = ImGuiTableColumnFlags;
						ImGui::TableSetupColumn("Parameter");
						ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("xmlnode ").x);
						ImGui::TableSetupColumn("Value");
						ImGui::TableHeadersRow();
						for(auto& parameter: entry.second->child(entry.first.c_str())) {
							ImGui::TableNextRow();
							ImGui::TableSetColumnIndex(0);
							ImGui::Text("%s", parameter.name());
							ImGui::TableSetColumnIndex(1);
							ImGui::Text("%s", parameter.attribute("type").value());
							ImGui::TableSetColumnIndex(2);
							auto type = parameterNameMap.right.find((std::string) parameter.attribute("type").value())->second;
							auto value = ParseXmlTextToParameter(parameter);
							// put text on imgui according to the type and value of the parameter
							switch (type) {
							case parameterType::String:
								ImGui::Text("%s", boost::get<std::string>(value).c_str());
								break;
							case parameterType::Bool:
								ImGui::Text("%u", boost::get<bool>(value));
								break;
							case parameterType::Int:
								ImGui::Text("%d", boost::get<int>(value));
								break;
							case parameterType::Uint:
								ImGui::Text("%u", boost::get<unsigned int>(value));
								break;
							case parameterType::Int64:
								ImGui::Text("%lld", boost::get<long long>(value));
								break;
							case parameterType::Uint64:
								ImGui::Text("%llu", boost::get<unsigned long long>(value));
								break;
							case parameterType::Float:
								ImGui::Text("%f", boost::get<float>(value));
								break;
							case parameterType::XMLNode:
								ImGui::Text("%s", boost::get<pugi::xml_node>(value).name());
								break;
							case parameterType::Other:
								ImGui::Text("%s", boost::get<std::string>(value).c_str());
								break;
							default:
								break;
							}
							ImGui::NextColumn();
						}
						ImGui::EndTable();
					}
					ImGui::EndTabItem();
				}
			}
			ImGui::EndTabBar();
		}
		ImGui::Separator();
		ConfigParameter daBoi;
		daBoi = "yes";
		daBoi = 2;
		auto var = boost::get<int>(daBoi);
		static std::string input = "In your mom";
		if (ImGui::Button("Load Config File")) {
			// loadConfigFile();
			loadModConfigFile("ExampleMod");
		}
		if(ImGui::Button("Save Parameter 1")) {
			setConfigValue("ExampleMod", "parameterName", "1", parameterType::Int);
		}
		ImGui::InputText("Config Save Location", &input);
		if (ImGui::Button("Save Parameter 2")) {
			setConfigValue("ExampleMod", "configSaveLocation", input.c_str(), parameterType::String);
		}
		if(ImGui::Button("Check filesystem shit")) {
			if (fs::exists(getConfigPath("ExampleMod")))
				CryLog("File exists yep");
			else
				CryLog("FUCK");
		}
	}
	ImGui::End();
}


void ChairloaderConfigManager::Update() {
	for(auto &entry: modConfigsDirty) {
		if(entry.second) {
			saveModConfigFile(entry.first);
		}
	}

}

ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::ParseXmlTextToParameter(pugi::xml_node parameterNode) {
	std::string typeStr = parameterNode.attribute("type").value();
	// CryLog(typeStr.c_str());
	auto type = parameterNameMap.right.find(typeStr)->second;
	if(type == parameterType::String) {
		std::string val = parameterNode.text().as_string();
		return val;
	} else if(type == parameterType::Bool) {
		return parameterNode.text().as_bool();
	} else if(type == parameterType::Int) {
		return parameterNode.text().as_int();
	} else if(type == parameterType::Uint) {
		return parameterNode.text().as_uint();
	} else if(type == parameterType::Int64) {
		return parameterNode.text().as_llong();
	} else if(type == parameterType::Uint64) {
		return parameterNode.text().as_ullong();
	} else if(type == parameterType::Float) {
		return parameterNode.text().as_float();
	} else if(type == parameterType::XMLNode) {
		return parameterNode;
	} else if(type == parameterType::Other) {
		std::string val = parameterNode.text().as_string();
		return val;
	} else {
		std::string val = "";
		return val;
	}
}


// Returns a boost::variant of the parameter. Returns "" if the parameter does not exist;
ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::getConfigValue(std::string modName, std::string parameterName) {
	if (modConfigs.find(modName) != modConfigs.end()) {
		auto configFile = modConfigs.find(modName)->second;
		if (configFile->child(modName.c_str()).child(parameterName.c_str())) {
			return ParseXmlTextToParameter(configFile->child(modName.c_str()).child(parameterName.c_str()));
		}
		else {
			return "";
		}
	}
}

bool ChairloaderConfigManager::setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type) {
	if(modConfigs.find(modName) != modConfigs.end()) {
		auto configFile = modConfigs.find(modName)->second;
		auto modNode = configFile->child(modName.c_str());
		if (modNode) {
			auto parameterNode = modNode.child(parameterName.c_str());
			if (parameterNode) {
				parameterNode.text().set(value.c_str());
				parameterNode.attribute("type").set_value(parameterNameMap.left.find(type)->get_right().c_str());
				modConfigsDirty.find(modName)->second = true;
			}
			else {
				modNode.append_child(parameterName.c_str()).text().set(value.c_str());
				modNode.child(parameterName.c_str()).append_attribute("type").set_value(parameterNameMap.left.find(type)->second.c_str());
				modConfigsDirty.find(modName)->second = true;
			}
			return true;
		}
	}
	CryError("%s: config not found", modName.c_str());
	return false;
}
// // check if the actual node exists
// if (chairloaderConfigFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str())) {
// 	chairloaderConfigFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).text().set(value.c_str());
// 	chairloaderConfigFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).attribute("type").set_value(parameterNameMap.left.find(type)->get_right().c_str());
// 	configDirty = true;
// }
// else {
// 	// check if the mod config exists
// 	if (chairloaderConfigFile.child(rootNode).child(modName.c_str())) {
// 		chairloaderConfigFile.child(rootNode).child(modName.c_str()).append_child(parameterName.c_str()).text().set(value.c_str());
// 		configDirty = true;
// 	}
// 	else {
// 		// if mod config node doesn't exist then add it 
// 		chairloaderConfigFile.child(rootNode).append_child(modName.c_str()).append_child(parameterName.c_str()).text().set(value.c_str());
// 		configDirty = true;
// 	}
// 	chairloaderConfigFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).append_attribute("type").set_value(parameterNameMap.left.find(type)->get_right().c_str());
// }

bool ChairloaderConfigManager::loadModConfigFile(std::string modName) { 
	fs::path configFilePath = getConfigPath(modName);
	fs::path defaultFilePath = getDefaultConfigPath(modName);



	pugi::xml_document* configFile;
	if(modConfigs.find(modName) != modConfigs.end()) {
		configFile = modConfigs.find(modName)->second;
		modConfigsDirty.find(modName)->second = false;
	} else {
		configFile = new pugi::xml_document;
		modConfigs.insert(std::pair{ modName, configFile});
		modConfigsDirty.insert(std::pair{ modName, false});
	}
	
	// load existing config file
	if (fs::exists(configFilePath)) {
		// continue on to load
	} else { // check for default config
		if(fs::exists(defaultFilePath)) {
			if (!copyDefaultModConfigFile(modName)) {
				CryError("%s: copying default mod config failed", modName.c_str());
				return false;
			}
		} else {
			// someone just gets the default config good luck and hope they handled null return values if they try and load
			if (!createDefaultModConfig(modName)) {
				CryError("%s: creating default mod config failed", modName.c_str());
				return false;
			}
		}
	}
	auto result = configFile->load_file(configFilePath.string().c_str());
	if (result.status == pugi::xml_parse_status::status_ok) {
		CryLog("%s: Config Loaded", modName.c_str());
		return true;
	}
	else {
		CryError("%s: Config Loading Failed, could not find config file at %s because %s", modName.c_str(), configFilePath.string().c_str(), result.description());
		return false;
	}
}

bool ChairloaderConfigManager::saveModConfigFile(std::string modName) {
	if(modConfigs.find(modName) != modConfigs.end()) {
		modConfigsDirty.find(modName)->second = false;
		bool saved = modConfigs.find(modName)->second->save_file(getConfigPath(modName).string().c_str());
		if (saved)
			CryLog("%s: Config Saved", modName.c_str());
		else
			CryError("%s: Config Saving Failed", modName.c_str());
		return saved;
	}
	return false;
}

bool ChairloaderConfigManager::copyDefaultModConfigFile(std::string modName) {
	CryLog("%s: copying default mod config", modName.c_str());
	return fs::copy_file(getDefaultConfigPath(modName), getConfigPath(modName));
}

bool ChairloaderConfigManager::createDefaultModConfig(std::string modName) {
	CryLog("%s: default not found, creating mod config", modName.c_str());
	pugi::xml_document newDocument;
	newDocument.append_child(modName.c_str());
	return newDocument.save_file(getConfigPath(modName).string().c_str());
}

fs::path ChairloaderConfigManager::getConfigPath(std::string modName) {
	CryLog(("./Mods/config/" + modName + ".xml").c_str());
	return fs::path{ ("./Mods/config/" + modName + ".xml").c_str() };
}

fs::path ChairloaderConfigManager::getDefaultConfigPath(std::string modName) {
	return fs::path{ ("./Mods/" + modName + "/" + modName + "_default.xml").c_str() };
}


bool ChairloaderConfigManager::loadChairloaderConfigFile() {
	// find preexisting config file
	if(chairloaderConfigFile.load_file((chairloaderConfigFilePath).c_str()).status == pugi::xml_parse_status::status_ok) {
		return true;
	} else {
		// create new one
		chairloaderConfigFile.append_child(rootNode).append_attribute("version");
		chairloaderConfigFile.save_file(chairloaderConfigFilePath.c_str());
		return false;
	}
}

bool ChairloaderConfigManager::saveChairloaderConfigFile() {
	return chairloaderConfigFile.save_file(chairloaderConfigFilePath.c_str());
}
