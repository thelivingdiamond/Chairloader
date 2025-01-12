#include <regex>
#include <imgui_internal.h>
#include "EditorControls.h"

#define XML_FLOAT_FMT  "{:.8g}"

static const std::regex g_Vec3Regex = std::regex(R"(([\d\.+e-]+)f?\s*,\s*([\d\.+e-]+)f?\s*,\s*([\d\.+e-]+)f?)");
static const std::regex g_Vec4Regex = std::regex(R"(([\d\.+e-]+)f?\s*,\s*([\d\.+e-]+)f?\s*,\s*([\d\.+e-]+)f?,\s*([\d\.+e-]+)f?)");

static bool TryParseFloat(const std::string& s, float& outValue)
{
    char* pEnd = nullptr;
    float result = strtof(s.c_str(), &pEnd);

    if (pEnd == s.c_str())
        return false;

    if (result == HUGE_VALF)
        return false;

    outValue = result;
    return true;
}

static bool TryParseVec3(std::string text, Vec3& outValue)
{
    std::smatch match;

    if (!std::regex_search(text, match, g_Vec3Regex))
        return false;

    Vec3 result = ZERO;
    bool isOk = true;
    isOk &= TryParseFloat(match[1], result.x);
    isOk &= TryParseFloat(match[2], result.y);
    isOk &= TryParseFloat(match[3], result.z);
    
    if (isOk)
    {
        outValue = result;
        return true;
    }
    else
    {
        return false;
    }
}

static bool TryParseVec4(std::string text, Vec4& outValue)
{
    std::smatch match;

    if (!std::regex_search(text, match, g_Vec4Regex))
        return false;

    Vec4 result = ZERO;
    bool isOk = true;
    isOk &= TryParseFloat(match[1], result.x);
    isOk &= TryParseFloat(match[2], result.y);
    isOk &= TryParseFloat(match[3], result.z);
    isOk &= TryParseFloat(match[4], result.w);

    if (isOk)
    {
        outValue = result;
        return true;
    }
    else
    {
        return false;
    }
}

static const char* GetClipboardTextSafe()
{
    const char* clipboardText = ImGui::GetClipboardText();

    if (!clipboardText)
        clipboardText = "";

    return clipboardText;
}

bool EditorControls::DragVec3(const char* label, Vec3* pValue, float v_speed, const char* format, ImGuiSliderFlags flags)
{
    ImGui::PushID(label);

    Vec3 value = *pValue;
    bool result = ImGui::DragFloat3(label, &value.x, v_speed, 0.0f, 0.0f, format, flags);

    bool hasChanged = ImGui::IsItemActive() && ImGui::TempInputIsActive(ImGui::GetActiveID())
        ? ImGui::IsItemDeactivatedAfterEdit() // When in Text Edit mode, apply only on unfocus. Otherwise the position would jump around.
        : result;   // When in Drag Mode, apply immediately.

    if (ImGui::BeginPopupContextItem("ContextMenu"))
    {
        Vec3 clipboardValue = ZERO;
        bool isInClipboard = TryParseVec3(GetClipboardTextSafe(), clipboardValue);

        if (ImGui::Selectable("Copy as Vec3"))
        {
            std::string text = fmt::format(
                "Vec3(" XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f)",
                pValue->x, pValue->y, pValue->z);
            ImGui::SetClipboardText(text.c_str());
        }

        if (ImGui::Selectable("Copy as XML Vec3"))
        {
            std::string text = fmt::format(
                XML_FLOAT_FMT "," XML_FLOAT_FMT "," XML_FLOAT_FMT,
                pValue->x, pValue->y, pValue->z);
            ImGui::SetClipboardText(text.c_str());
        }

        if (ImGui::Selectable("Paste", false, isInClipboard ? ImGuiSelectableFlags_None : ImGuiSelectableFlags_Disabled))
        {
            value = clipboardValue;
            hasChanged = true;
        }

        ImGui::EndPopup();
    }

    ImGui::PopID();

    if (hasChanged)
    {
        *pValue = value;
        return true;
    }
    else
    {
        return false;
    }
}

bool EditorControls::DragQuat(const char* label, Quat* pValue, float v_speed, const char* format, ImGuiSliderFlags flags)
{
    ImGui::PushID(label);

    Quat valueQuat = *pValue;
    Ang3 valueAngles = RAD2DEG(Ang3(valueQuat));
    bool result = ImGui::DragFloat3(label, &valueAngles.x, v_speed, 0.0f, 0.0f, format, flags);

    if (result)
        valueQuat = Quat(DEG2RAD(valueAngles));

    bool hasChanged = ImGui::IsItemActive() && ImGui::TempInputIsActive(ImGui::GetActiveID())
        ? ImGui::IsItemDeactivatedAfterEdit() // When in Text Edit mode, apply only on unfocus. Otherwise the position would jump around.
        : result;   // When in Drag Mode, apply immediately.

    if (ImGui::BeginPopupContextItem("ContextMenu"))
    {
        Vec3 clipboardValue3 = ZERO;
        Vec4 clipboardValue4 = ZERO;
        bool isInClipboard3 = TryParseVec3(GetClipboardTextSafe(), clipboardValue3);
        bool isInClipboard4 = TryParseVec4(GetClipboardTextSafe(), clipboardValue4);

        if (ImGui::Selectable("Copy as Ang3 (deg)"))
        {
            std::string text = fmt::format(
                "Ang3(" XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f)",
                valueAngles.x, valueAngles.y, valueAngles.z);
            ImGui::SetClipboardText(text.c_str());
        }

        if (ImGui::Selectable("Copy as Quat"))
        {
            std::string text = fmt::format(
                "Quat(" XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f, " XML_FLOAT_FMT "f)",
                valueQuat.w, valueQuat.v.x, valueQuat.v.y, valueQuat.v.z);
            ImGui::SetClipboardText(text.c_str());
        }

        if (ImGui::Selectable("Copy as XML Quat"))
        {
            std::string text = fmt::format(
                XML_FLOAT_FMT "," XML_FLOAT_FMT "," XML_FLOAT_FMT "," XML_FLOAT_FMT,
                valueQuat.w, valueQuat.v.x, valueQuat.v.y, valueQuat.v.z);
            ImGui::SetClipboardText(text.c_str());
        }

        if (ImGui::Selectable("Paste", false, (isInClipboard3 || isInClipboard4) ? ImGuiSelectableFlags_None : ImGuiSelectableFlags_Disabled))
        {
            if (isInClipboard4)
            {
                // Process as quat. XYZW order here is correct because it maps Vec4 to Quat
                valueQuat = Quat(clipboardValue4.x, clipboardValue4.y, clipboardValue4.z, clipboardValue4.w);
            }
            else if (isInClipboard3)
            {
                // Process as angles in degrees
                valueQuat = Quat(DEG2RAD(Ang3(clipboardValue3)));
            }

            hasChanged = true;
        }

        ImGui::EndPopup();
    }

    ImGui::PopID();

    if (hasChanged)
    {
        *pValue = valueQuat;
        return true;
    }
    else
    {
        return false;
    }
}
