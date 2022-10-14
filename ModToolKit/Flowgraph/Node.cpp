#include "Node.h"
#include "ImNodes/imnodes.h"
#include "ImGui/imgui_stdlib.h"

void Node::draw() {
    ImNodes::BeginNode(ID);
    if(!PosSet){
        ImNodes::SetNodeEditorSpacePos(ID, Pos);
        PosSet = true;
    }
    ImNodes::BeginNodeTitleBar();
    ImGui::Text("%s", Class.c_str());
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
