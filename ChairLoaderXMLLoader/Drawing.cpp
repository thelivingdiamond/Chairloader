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

class StorageCell {
public:
	uint32_t m_entityId;
	int32_t m_x;
	int32_t m_y;
	int32_t m_width;
	int32_t m_height;
};
//Id to item map
static std::vector<StorageCell> inventoryItems{
	// add 50 storage cells to the vector
	{ 0, 0, 0, 1, 1 },
	{ 1, 2, 1, 2, 2 },
	{ 2, 1, 1, 1, 1 }
	 
};

void Drawing::Draw()
{
	if (isActive())
	{
		ImGui::ShowDemoWindow(&bDraw);
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
		/*
		// ImGui::SetNextWindowSize(vWindowSize);
		ImGui::Begin("Inventory Test", &bDraw); {
			ImGui::Text("Player Inventory");
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
			ImVec2 p = ImGui::GetCursorScreenPos();
			// 12 grids across at max size
			// 8 grids down
			float size;
			if(ImGui::GetContentRegionAvail().x / 12 <= ImGui::GetContentRegionAvail().y / 8) {
				size = ImGui::GetContentRegionAvail().x / 12;
			} else {
				size = ImGui::GetContentRegionAvail().y / 8;
			}
			float padding = 4.0f;
			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			//iterate through inventoryItems
			// draw_list->AddCircleFilled(ImVec2(p.x, p.y), 20.0f, 0xFFFFFFFF);
			ImU32 gridColor = ImColor(188,188,188);
			ImColor itemColor = ImColor(255, 180, 255, 255);
			int columns = 12, rows = 8;
			// iterate 12 times
			for (int i = 0; i < rows + 1; i++) {
				draw_list->AddLine(ImVec2(p.x, p.y + i * size), ImVec2(p.x + columns * size, p.y + i * size), gridColor);
			}
			for (int i = 0; i < columns + 1; i++) {
				draw_list->AddLine(ImVec2(p.x + i*size, p.y), ImVec2(p.x + i*size, p.y + rows*size), gridColor);
			}
			ImVec2 pos = ImGui::GetCursorPos();
			for (auto &itr :inventoryItems) {
				//draw item
				ImGui::SetCursorPos(ImVec2(pos.x + itr.m_x * size + padding, pos.y + itr.m_y*size + padding));
				if (ImGui::Button(((std::string)("button") + std::to_string(itr.m_entityId)).c_str(), ImVec2(itr.m_width * size - 2 * padding, itr.m_height * size - 2 * padding))) {
					if (ImGui::BeginPopupModal("Information")) {
						// if (ImGui::BeginPopupContextItem(((std::string)"context" + std::to_string(itr.m_entityId)).c_str())) {
						ImGui::Text("Information");

						ImGui::EndPopup();
					}
				}
				// draw_list->AddRectFilled(
				// 	ImVec2(p.x + itr.m_x*size + padding, p.y + itr.m_y*size + padding), 
				// 	ImVec2(p.x + itr.m_x*size + itr.m_width*size - padding, p.y+ itr.m_y*size + itr.m_height*size - padding),
				// 	itemColor);
			}
			ImGui::End();
			
		}
		*/
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


