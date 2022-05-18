#include "Drawing.h"
#include "chairloaderModManager.h"



LPCSTR Drawing::lpWindowName = "Chairloader Mod Manager";
ImVec2 Drawing::vWindowSize = { 800, 500 };
ImGuiWindowFlags Drawing::WindowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize;//| ImGuiWindowFlags_MenuBar;
bool Drawing::bDraw = true;

void Drawing::Active() {
	bDraw = true;
}

bool Drawing::isActive() {
	return bDraw == true;
}

static std::vector<std::string> modNames;
static chairloader::modList modConfigs;
static pugi::xml_document chairloaderConfig;
static std::string preyPath;

bool loadModConfigs(){
	loadModConfigs(preyPath, &modConfigs);
	sortModLoadOrder(&modConfigs);
	return true;
}


void merge() {
	pugi::xml_document fileSystem;
	pugi::xml_parse_result result;
	// merge the mods
	result = fileSystem.load_file("Libraries.xml");
	if (result.status == pugi::status_ok) {
		std::vector<std::string> outputPaths;
		treeWalkAndMerge(fileSystem.root().first_child(), "", modNames, preyPath, &outputPaths, &modConfigs);
		// Pack the output
		chairloader::packFiles("patch_chairloader.pak", outputPaths);
	}
}


static std::string statusMessage;
static time_t statusTimer;
void Drawing::Draw()
{
	if (isActive())
	{
		// ImGui::ShowDemoWindow(&bDraw);
		ImGui::SetNextWindowSize(vWindowSize);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			// if (ImGui::BeginMenuBar()) {
			// 	if (ImGui::BeginMenu("Chairloader")) {
			// 		if (ImGui::MenuItem("Load Mods")) {
			// 			modConfigs.clear();
			// 			modNames.clear();
			// 			loadModConfigs();
			// 		}
			// 		if (ImGui::MenuItem("Merge Mods")) {
			//
			// 		}
			// 		if (ImGui::MenuItem("Save Load Order")) {
			//
			// 		}
			// 		if (ImGui::MenuItem("Exit")) {
			//
			// 		}
			// 		ImGui::EndMenu();
			// 	}
			// 	ImGui::EndMenuBar();
			// }
			if(ImGui::BeginChild("ModList", ImVec2(ImGui::GetContentRegionAvail().x * .6, ImGui::GetContentRegionAvail().y), false)) {
				ImGui::BeginTable("loadOrder", 4, ImGuiTableFlags_ScrollY | ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg, ImVec2(0, ImGui::GetContentRegionAvail().y * 0.9f));
				ImGui::TableSetupColumn("Mod Name");
				ImGui::TableSetupColumn("Load Order", ImGuiTableColumnFlags_WidthFixed, 90.0f);
				ImGui::TableSetupColumn("XML\nLoad", ImGuiTableColumnFlags_WidthFixed, 40.0f);
				ImGui::TableSetupColumn("DLL\nLoad", ImGuiTableColumnFlags_WidthFixed, 40.0f);
				ImGui::TableHeadersRow();
				
				std::string lastModName;
				for (auto itr = modConfigs.begin(); itr != modConfigs.end(); ++itr) {
					ImGui::TableNextRow();
					ImGui::TableSetColumnIndex(0);
					if(itr->displayName.empty())	
						ImGui::Text("%s\n", itr->modName.c_str());
					else
						ImGui::Text("%s\n", itr->displayName.c_str());
					ImGui::TableSetColumnIndex(1);
					// ImGui::PushID(itr->modName.c_str());
					// ImGui::InputInt("", &itr->loadOrder, 1, 5);
					// if(ImGui::IsItemClicked()) {
					// 	sortModLoadOrder(&modConfigs);
					// }
					// ImGui::PopID();
					ImGui::Text("%d\n", itr->loadOrder);
					ImGui::SameLine(35.0f);
					// ImGui::PushID((itr->modName + "+").c_str());
					if(ImGui::ArrowButton((itr->modName + "+").c_str(), ImGuiDir_Up)) {
						int i = itr->loadOrder - 1;
						itr->setLoadOrder(i);
						sortModLoadOrder(&modConfigs);
					}
					// ImGui::PopID();
					ImGui::SameLine();
					// ImGui::PushID((itr->modName + "-").c_str());
					if(ImGui::ArrowButton((itr->modName+"-").c_str(), ImGuiDir_Down)) {
						int i = itr->loadOrder + 1;
						itr->setLoadOrder(i);
						sortModLoadOrder(&modConfigs);
					}
					// ImGui::PopID();
					ImGui::TableSetColumnIndex(2);
					ImGui::PushID((itr->modName+ "XML").c_str());
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth()*0.25f);
					ImGui::Checkbox("", &itr->xmlLoad);
					ImGui::PopID();

					ImGui::TableSetColumnIndex(3);
					ImGui::PushID((itr->modName + "DLL").c_str());
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetColumnWidth() * 0.25f);
					ImGui::Checkbox("", &itr->dllLoad);
					ImGui::PopID();
				}
				ImGui::EndTable();
				// ImGui::SetNextItemWidth(ImGui::CalcTextSize("+").y);
				if(ImGui::Button("Load Mods", ImVec2(ImGui::CalcTextSize("Save Config   ").x, 0))) {
					modConfigs.clear();
					modNames.clear();
					loadModConfigs();
				}
				ImGui::SameLine();
				// ImGui::SetNextItemWidth(ImGui::CalcTextSize("+").y);
				if (ImGui::Button("Sort List", ImVec2(ImGui::CalcTextSize("Save Config   ").x, 0))) {
					sortModLoadOrder(&modConfigs);
				}
				ImGui::SameLine();
				// ImGui::SetNextItemWidth(ImGui::CalcTextSize("+").y);
				if(ImGui::Button("Save Config", ImVec2(ImGui::CalcTextSize("Save Config   ").x, 0))) {
					sortModLoadOrder(&modConfigs);
					saveLoadOrderConfig(&modConfigs);
				}
				
				ImGui::EndChild();
			}
			ImGui::SameLine();
			if(ImGui::BeginChild("ModMerging")) {
				
				if (statusTimer + 5 < time(nullptr)) {
					statusMessage = "";
				}
				ImGui::InputText("Prey Path", &preyPath);
				ImGui::Separator();
				if(ImGui::Button("Deploy Patch")) {
					merge();
					chairloader::deployPatch("patch_chairloader.pak", preyPath);
					if(statusMessage.empty())
						Log("Deployed");
					// statusMessage = "	Deployed";
					// time(&statusTimer);
				}
				ImGui::Separator();
				if(ImGui::Button("Inject Mods")) {
					//TODO deal with injection
				}
				ImGui::TextWrapped("%s", statusMessage.c_str());
				ImGui::EndChild();
			}
		}
		ImGui::End();
	}

	#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
	#endif
}

void Drawing::Setup() {
	if (chairloaderConfig.load_file("chairloaderConfig.xml").status == pugi::status_ok) {
		preyPath = chairloaderConfig.child("ChairloaderConfig").child("FilePaths").child("Prey").attribute("Path").as_string();
	}
	loadModConfigs();
}

void Drawing::Log(std::string msg) {
	statusMessage = msg;
	time(&statusTimer);
}


