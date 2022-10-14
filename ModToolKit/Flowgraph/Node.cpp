#include "Node.h"
#include "ImNodes/imnodes.h"
#include "ImGui/imgui_stdlib.h"
#include <IconsMaterialDesign.h>

void Node::draw() {
    SetCategoryColor();
    ImNodes::BeginNode(ID);
    if(!PosSet){
        ImNodes::SetNodeEditorSpacePos(ID, Pos);
        PosSet = true;
    }
    ImNodes::BeginNodeTitleBar();
    ImGui::Text(ICON_MD_TOC " %s", Class.c_str());
    ImNodes::EndNodeTitleBar();
    for(auto &input : Inputs){
        ImNodes::BeginInputAttribute(input.ID);
        if(input.isLinked()) {
            ImGui::Text("%s", input.Name.c_str());
        } else {
            ImGui::Text("%s", input.Name.c_str());
            ImGui::SameLine();
            if(ImNodes::IsNodeSelected(ID) || isHovered){
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImGui::GetStyleColorVec4(ImGuiCol_FrameBgHovered));
            } else {
                ImGui::PushStyleColor(ImGuiCol_FrameBg, ImGui::GetStyleColorVec4(ImGuiCol_FrameBg));
            }
            ImGui::SetNextItemWidth(120);
            ImGui::InputText(("##input" + input.Name + std::to_string(input.ID)).c_str(), &input.value);
            ImGui::PopStyleColor();
        }
        ImNodes::EndInputAttribute();
    }
    for(auto &output : Outputs){
        ImNodes::BeginOutputAttribute(output.ID);
        ImGui::Text("%s", output.Name.c_str());
        ImNodes::EndOutputAttribute();
    }
    ImNodes::EndNode();
    ClearCategoryColor();
}

ImColor Node::GetCategoryColor() const {
    switch(Category){
        case nodeCategory::NONE:
        default:
            return ImNodes::GetStyle().Colors[ImNodesCol_TitleBar];
            break;
        case nodeCategory::AI:
            return ImColor(0.8f, 0.2f, 0.2f, 1.0f);
            break;

    }
    return ImColor();
}

void Node::SetCategoryColor() {
    auto color = GetCategoryColor();
    ImColor selectedColor = ImVec4(color.Value.x + 0.1f, color.Value.y + 0.1f, color.Value.z + 0.1f, color.Value.w);
    switch (Category){
        case nodeCategory::NONE:
        default:
            ImNodes::PushColorStyle(ImNodesCol_TitleBar, color);
            ImNodes::PushColorStyle(ImNodesCol_TitleBarSelected, selectedColor);
            ImNodes::PushColorStyle(ImNodesCol_TitleBarHovered, selectedColor);
            break;
        case nodeCategory::AI:
            ImNodes::PushColorStyle(ImNodesCol_TitleBar, color);
            ImNodes::PushColorStyle(ImNodesCol_TitleBarSelected, selectedColor);
            ImNodes::PushColorStyle(ImNodesCol_TitleBarHovered, selectedColor);
            break;
    }

}

void Node::ClearCategoryColor() {
    ImNodes::PopColorStyle();
    ImNodes::PopColorStyle();
    ImNodes::PopColorStyle();
}

void commentBox::draw() {
    ImNodes::BeginNode(ID);
    if(!PosSet){
        ImNodes::SetNodeEditorSpacePos(ID, Pos);
        PosSet = true;
    }
    ImNodes::BeginNodeTitleBar();
    ImGui::Text("%s", Class.c_str());
    ImNodes::EndNodeTitleBar();
    ImGui::TextWrapped("%s", Name.c_str());
    ImNodes::EndNode();
}

void PrototypeNode::setCategory() {
    {
        auto categoryPrefix = Class.substr(0, Class.find_first_of(':'));
        CryLog("Category prefix: %s", categoryPrefix.c_str());
        std::transform(categoryPrefix.begin(), categoryPrefix.end(), categoryPrefix.begin(), ::tolower);
        if(categoryPrefix == "ai"){
            Category = nodeCategory::AI;
        } else if(categoryPrefix == "actor"){
            Category = nodeCategory::ACTOR;
        } else if(categoryPrefix == "animations"){
            Category = nodeCategory::ANIMATIONS;
        } else if(categoryPrefix == "ark"){
            Category = nodeCategory::ARK;
        } else if(categoryPrefix == "arkplayer"){
            Category = nodeCategory::ARK_PLAYER;
        } else if(categoryPrefix == "audio"){
            Category = nodeCategory::AUDIO;
        } else if(categoryPrefix == "camera"){
            Category = nodeCategory::CAMERA;
        } else if(categoryPrefix == "customaction"){
            Category = nodeCategory::CUSTOM_ACTION;
        } else if(categoryPrefix == "debug"){
            Category = nodeCategory::DEBUG;
        } else if(categoryPrefix == "effects"){
            Category = nodeCategory::EFFECTS;
        } else if(categoryPrefix == "engine"){
            Category = nodeCategory::ENGINE;
        } else if(categoryPrefix == "entity"){
            Category = nodeCategory::ENTITY;
        } else if(categoryPrefix == "environment"){
            Category = nodeCategory::ENVIRONMENT;
        } else if(categoryPrefix == "game"){
            Category = nodeCategory::GAME;
        } else if(categoryPrefix == "image"){
            Category = nodeCategory::IMAGE;
        } else if(categoryPrefix == "input"){
            Category = nodeCategory::INPUT;
        } else if(categoryPrefix == "interpol"){
            Category = nodeCategory::INTERPOL;
        } else if(categoryPrefix == "inventory"){
            Category = nodeCategory::INVENTORY;
        } else if(categoryPrefix == "logic"){
            Category = nodeCategory::LOGIC;
        } else if(categoryPrefix == "material"){
            Category = nodeCategory::MATERIAL;
        } else if(categoryPrefix == "materialfx"){
            Category = nodeCategory::MATERIALFX;
        } else if(categoryPrefix == "math"){
            Category = nodeCategory::MATH;
        } else if(categoryPrefix == "mission"){
            Category = nodeCategory::MISSION;
        } else if(categoryPrefix == "module"){
            Category = nodeCategory::MODULE;
        } else if(categoryPrefix == "movement"){
            Category = nodeCategory::MOVEMENT;
        } else if(categoryPrefix == "multiplayer"){
            Category = nodeCategory::MULTIPLAYER;
        } else if(categoryPrefix == "physics"){
            Category = nodeCategory::PHYSICS;
        } else if(categoryPrefix == "playerprofile"){
            Category = nodeCategory::PLAYER_PROFILE;
        } else if(categoryPrefix == "prefab"){
            Category = nodeCategory::PREFAB;
        } else if(categoryPrefix == "stereo"){
            Category = nodeCategory::STEREO;
        } else if(categoryPrefix == "string"){
            Category = nodeCategory::STRING;
        } else if(categoryPrefix == "time"){
            Category = nodeCategory::TIME;
        } else if(categoryPrefix == "ui"){
            Category = nodeCategory::UI;
        } else if(categoryPrefix == "vec3"){
            Category = nodeCategory::VEC3;
        } else if(categoryPrefix == "video"){
            Category = nodeCategory::VIDEO;
        } else if(categoryPrefix == "xml"){
            Category = nodeCategory::XML;
        } else {
            Category = nodeCategory::NONE;
        }
    }
}
