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
	loadConfigFile();
}
ChairloaderConfigManager::~ChairloaderConfigManager() {
	saveConfigFile();
}

void ChairloaderConfigManager::Draw(bool* bShow) {
	if(ImGui::Begin("Config Menu", bShow)) {
		if (ImGui::BeginTabBar("configs")){
			for (auto& child : configFile.child("config")) {
				if(ImGui::BeginTabItem(child.name())) {
					ImGui::Text("Module: %s", child.name());
					if (ImGui::BeginTable((((std::string)"mod") + child.name()).c_str(), 2)) {
						ImGui::TableSetupColumn("Parameter Name");
						ImGui::TableSetupColumn("Value");
						ImGui::TableHeadersRow();
						//TODO: write parameters
						//TODO: automatic parameter typing (maybe have mods report parameter type?)
						for (auto& parameter : child) {
							ImGui::TableNextColumn();
							ImGui::Text("%s", parameter.name());
							ImGui::TableNextColumn();
							ImGui::Text("%s", parameter.text().as_string());
							ImGui::TableNextRow();
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
			auto file = &configFile;
			GUILog->logItem(configFile.name(), modName);
		}
		if(ImGui::Button("Save Parameter 1")) {
			setConfigValue(modName, "parameterName", "1", parameterType::Int64);
		}
		ImGui::InputText("Config Save Location", &input);
		if (ImGui::Button("Save Parameter 2")) {
			setConfigValue(modName, "configSaveLocation", input.c_str(), parameterType::String);
		}
	}
	ImGui::End();
}


void ChairloaderConfigManager::Update() {
	if(config_dirty()) {
		saveConfigFile();
		configDirty = false;
	}
}

bool ChairloaderConfigManager::getConfig(std::string modName, pugi::xml_node* node) {
	if (configLoaded) {
		*node = configFile.child(rootNode).child(modName.c_str());
		return *node;
	} else {
		loadConfigFile();
	}
	return false;
}

void ChairloaderConfigManager::writeConfig(std::string modName, pugi::xml_node* node) {
	if(configFile && *node) {
		// existing case
		if (configFile.child(rootNode).child(modName.c_str())) {
			configFile.child(rootNode).child(modName.c_str()).text().set(node->text().get());
			configDirty = true;
		} else {
			configFile.child(rootNode).append_copy(*node);
			configDirty = true;
		}
	}
}

ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::ParseXmlTextToParameter(pugi::xml_text) {
	return 0;
}

ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::getConfigValue(std::string modName, std::string parameterName) {
	return ParseXmlTextToParameter(configFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).text());
}

void ChairloaderConfigManager::setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type) {
	// check if the actual node exists
	if (configFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str())) {
		configFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).text().set(value.c_str());
		configFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).attribute("type").set_value(parameterNameMap.left.find(type)->get_right().c_str());
		configDirty = true;
	} else {
		// check if the mod config exists
		if(configFile.child(rootNode).child(modName.c_str())) {
			configFile.child(rootNode).child(modName.c_str()).append_child(parameterName.c_str()).text().set(value.c_str());
			configDirty = true;
		} else {
			// if mod config node doesn't exist then add it 
			configFile.child(rootNode).append_child(modName.c_str()).append_child(parameterName.c_str()).text().set(value.c_str());
			configDirty = true;
		}
		configFile.child(rootNode).child(modName.c_str()).child(parameterName.c_str()).append_attribute("type").set_value(parameterNameMap.left.find(type)->get_right().c_str());
	}
}


bool ChairloaderConfigManager::loadConfigFile() {
	// find preexisting config file
	if(configFile.load_file(configFilePath.c_str()).status == pugi::xml_parse_status::status_ok) {
		configLoaded = true;
		return true;
	} else {
		// create new one
		configFile.append_child(rootNode).append_attribute("version");
		configFile.save_file(configFilePath.c_str());
		return false;
	}
}

bool ChairloaderConfigManager::saveConfigFile() {
	return configFile.save_file(configFilePath.c_str());
}
