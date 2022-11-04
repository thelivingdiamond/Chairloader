//
// Created by theli on 10/30/2022.
//

#ifndef CHAIRLOADER_LOOKINGGLASS_H
#define CHAIRLOADER_LOOKINGGLASS_H


#include "pch.h"
#include "App/AppModule.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_stdlib.h"
#include "LookingGlass/XMLReference.h"

class LookingGlass : public AppModule {
public:
    LookingGlass();

    ~LookingGlass() override;

    void Init() override;

    void Update() override;
 
    void ShowUI() override;

    static LookingGlass* Get();

    void addXMLReference(XMLReference& reference);
private:
    std::vector< std::shared_ptr<XMLReference>> m_References;
    std::map<std::string, std::shared_ptr<XMLReference>> m_ReferencesByName;
    std::map<int32_t, std::shared_ptr<XMLReference>> m_ReferencesByID32;
    std::map<int64_t, std::shared_ptr<XMLReference>> m_ReferencesByID64;
    std::map<__int128, std::shared_ptr<XMLReference>> m_ReferencesByID128;
    std::map<fs::path, std::vector<std::shared_ptr<XMLReference>>> m_ReferencesByPath;
};


#endif //CHAIRLOADER_LOOKINGGLASS_H


namespace ImGui {
    static bool LookingGlassInputText(const char* label, std::string* str, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL){
        // todo: add looking glass features like automatic replacement of id with name
        ImGui::InputText(label, str, flags, callback, user_data);
    }
}