#include <boost/json.hpp>
#include <Prey/ArkCommon/reflection/ArkClass.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/GameDll/ark/ArkGameDataManager.h>
#include <Prey/CryGame/Game.h>
#include "UI/ArkLibraryExplorer.h"

namespace
{

constexpr int NODE_FLAGS = ImGuiTreeNodeFlags_SpanAvailWidth;
constexpr int LEAF_NODE_FLAGS = NODE_FLAGS | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_Leaf;

//! Gets a property from an object via reflection.
//! @param  pProp   Property.
//! @param  pObject Object. Must be of the same type as the property.
//! @tparam T       Property type.
//! @returns        Reference to the property value.
template <typename T>
T& GetArkPropertyValue(const ArkProperty* pProp, ArkReflectedObject* pObject)
{
    T* pVal = reinterpret_cast<T*>(pProp->GetMemPtr(pObject));
    return *pVal;
}

//! Visits a property via reflection. Calls the visitor object depending on property type.
//! @param  pProp       Property.
//! @param  pObject     Object. Must be of the same type as the property.
//! @param  visitor     Visitor.
//! @tparam T           Visitor type.
//! @returns visitor's return value.
template <typename T>
auto VisitArkProperty(const ArkProperty* pProp, ArkReflectedObject* pObject, T& visitor)
{
    switch (pProp->m_arkType)
    {
    case ArkProperty::EArkType::intT:
    {
        auto& val = GetArkPropertyValue<int>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::uintT:
    {
        auto& val = GetArkPropertyValue<unsigned>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::boolT:
    {
        auto& val = GetArkPropertyValue<bool>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::floatT:
    {
        auto& val = GetArkPropertyValue<float>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::stringT:
    {
        auto& val = GetArkPropertyValue<string>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::crynameT:
    {
        auto& val = GetArkPropertyValue<CCryName>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::vec2T:
    {
        auto& val = GetArkPropertyValue<Vec2>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::vec3T:
    {
        auto& val = GetArkPropertyValue<Vec3>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::objectT:
    {
        auto& val = GetArkPropertyValue<ArkReflectedObject>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::object_ptrT:
    {
        auto& val = GetArkPropertyValue<ArkReflectedObject*>(pProp, pObject);
        return visitor(val);
    }
    case ArkProperty::EArkType::unknownT:
    {
        void* pVal = reinterpret_cast<void*>(pProp->GetMemPtr(pObject));
        return visitor(pVal);
    }
    }

    return visitor(pProp->m_arkType);
}

std::string_view ArkTypeToString(ArkProperty::EArkType type)
{
    switch (type)
    {
        case ArkProperty::EArkType::intT:
            return "intT";
        case ArkProperty::EArkType::uintT:
            return "uintT";
        case ArkProperty::EArkType::boolT:
            return "boolT";
        case ArkProperty::EArkType::floatT:
            return "floatT";
        case ArkProperty::EArkType::stringT:
            return "stringT";
        case ArkProperty::EArkType::crynameT:
            return "crynameT";
        case ArkProperty::EArkType::vec2T:
            return "vec2T";
        case ArkProperty::EArkType::vec3T:
            return "vec3T";
        case ArkProperty::EArkType::objectT:
            return "objectT";
        case ArkProperty::EArkType::object_ptrT:
            return "object_ptrT";
        case ArkProperty::EArkType::unknownT:
            return "unknownT";
        default:
            return "";
    }
}

boost::json::value ArkTypeToJsonValue(ArkProperty::EArkType type)
{
    std::string_view s = ArkTypeToString(type);

    if (s.empty())
        return nullptr;

    return s;
}

//! Converts ArkProperty value to a string.
class PropertyToStringVisitor
{
public:
    std::string operator()(int val) { return std::to_string(val); }
    std::string operator()(unsigned val) { return std::to_string(val); }
    std::string operator()(bool val) { return val ? "true" : "false"; }
    std::string operator()(float val) { return std::to_string(val); }
    std::string operator()(const string& val) { return std::string(val.data(), val.size()); }
    std::string operator()(const CCryName& val) { return std::string(val.c_str(), val.length()); }
    std::string operator()(const Vec2& val) { return fmt::format("{}, {}", val.x, val.y); }
    std::string operator()(const Vec3& val) { return fmt::format("{}, {}, {}", val.x, val.y, val.z); }
    std::string operator()(const ArkReflectedObject& val) { return fmt::format("object - {}", val.GetClass()->m_name); }

    std::string operator()(const ArkReflectedObject* pVal)
    {
        if (pVal)
            return fmt::format("object - {}*", pVal->GetClass()->m_name);
        else
            return "object - nullptr";
    }

    std::string operator()(void* val) { return fmt::format("unknown - {:p}", val); }
    std::string operator()(ArkProperty::EArkType type) { return fmt::format("unknown type - {}", (int)type); }
};

} // namespace

Main::ArkLibraryExplorer::ArkLibraryExplorer()
{
    SetTitle("Ark Library Explorer");
    SetPersistentID("ArkLibraryExplorer");
    SetDestroyOnClose(true);
    m_pMgr = static_cast<CGame*>(gEnv->pGame)->m_pArkGameDataManager.get();
}

Main::ArkLibraryExplorer::~ArkLibraryExplorer()
{
}

void Main::ArkLibraryExplorer::ShowContents()
{
    if (ImGui::Button("Force Reload"))
        m_pMgr->LoadLibraries(true);

    ImGui::SameLine();
    if (ImGui::Button("Dump JSON"))
        DumpClassesToJson();

    ImGui::PushFont(gPreditor->pFonts->pMonospace);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f });

    for (auto& [pClass, pLibrary] : m_pMgr->m_libraries)
    {
        ShowObjectNode(pClass, pLibrary.get(), nullptr);
    }

    ImGui::PopStyleVar();
    ImGui::PopFont();
}

void Main::ArkLibraryExplorer::ShowObjectNode(const ArkClass* pClass, ArkReflectedObject* pObject, const char* name)
{
    bool nodeOpen = false;

    if (name)
        nodeOpen = ImGui::TreeNodeEx(pObject, NODE_FLAGS, "%s: %s", name, pClass->m_name);
    else
        nodeOpen = ImGui::TreeNodeEx(pObject, NODE_FLAGS, "%s", pClass->m_name);

    if (nodeOpen)
    {
        for (auto& [propName, pProp] : pClass->m_Properties)
        {
            if (pProp->IsArray())
            {
                ImGui::TreeNodeEx(pProp, LEAF_NODE_FLAGS, "%s: %s[] = < array >", propName.c_str(), pProp->m_typeStr);
            }
            else if (pProp->m_arkType == ArkProperty::EArkType::objectT)
            {
                ArkReflectedObject& val = GetArkPropertyValue<ArkReflectedObject>(pProp, pObject);
                ShowObjectNode(pProp->m_typeStr, &val, propName);
            }
            else if (pProp->m_arkType == ArkProperty::EArkType::object_ptrT)
            {
                ArkReflectedObject* val = GetArkPropertyValue<ArkReflectedObject*>(pProp, pObject);

                if (val)
                    ShowObjectNode(pProp->m_typeStr, val, propName + "*");
                else
                    ImGui::TreeNodeEx(pProp, LEAF_NODE_FLAGS, "%s: %s* = null", propName.c_str(), pProp->m_typeStr);
            }
            else
            {
                std::string value = VisitArkProperty(pProp, pObject, PropertyToStringVisitor());
                ImGui::TreeNodeEx(pProp, LEAF_NODE_FLAGS, "%s: %s = %s", propName.c_str(), pProp->m_typeStr, value.c_str());
            }
        }

        ImGui::TreePop();
    }
}

void Main::ArkLibraryExplorer::ShowObjectNode(const char* className, ArkReflectedObject* pObject, const char* name)
{
    const ArkClass* pClass = ArkClass::GetClassByName(className);

    if (pClass)
        ShowObjectNode(pClass, pObject, name);
    else
        ImGui::TreeNodeEx(pObject, LEAF_NODE_FLAGS, "%s: %s = < unknown class >", name, className);
}

void Main::ArkLibraryExplorer::DumpClassesToJson()
{
    namespace json = boost::json;

    json::object jRoot;
    const auto& classMap = ArkClass::GetClasses();

    for (const auto& [className, pClass] : classMap)
    {
        json::object jClass;
        json::object jProps;

        jClass["name"] = pClass->m_name;
        jClass["baseClass"] = pClass->m_baseClass ? pClass->m_baseClass->m_name : json::value(nullptr);

        for (const auto& [propName, pProperty] : pClass->m_Properties)
        {
            json::object jProp;
            jProp["name"] = pProperty->m_name;
            jProp["type"] = pProperty->m_typeStr;
            jProp["arkType"] = ArkTypeToJsonValue(pProperty->m_arkType);
            jProp["isArray"] = pProperty->IsArray();

            jProps[propName.c_str()] = std::move(jProp);
        }

        jClass["properties"] = std::move(jProps);
        jRoot[className.c_str()] = std::move(jClass);
    }

    std::ofstream file(gPreditor->pPaths->GetUserPath() / "ark_classes.json");
    file << json::serialize(jRoot) << "\n";
}
