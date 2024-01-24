#include "Utils/ScriptTableEditor.h"

enum class LevelEditor::ScriptTableEditor::EVarType
{
    None,
    Int,
    Bool,
    Float,
    Vec3,
    String,
    Table,
};

/*class LevelEditor::ScriptTableEditor::VarValue
{
public:
};*/

class LevelEditor::ScriptTableEditor::Variable
{
public:
    //! Tries to set the value.
    //! @param  inValue     Value.
    //! @param  isDefault   Whether to set the default or current value.
    //! @returns Whether value was set. When setting tables recursively, always returns true.
    bool TrySetValue(const ScriptAnyValue& inValue, bool isDefault)
    {
        // Try parse as scalar
        ScalarValue parsedScalarValue;
        EVarType parsedScalarType = EVarType::None;
        
        bool isScalar = TryParseScalar(inValue, parsedScalarValue, parsedScalarType);

        if (isScalar)
        {
            ScalarValue& outScalarValue = isDefault ? m_DefaultScalarValue : m_CurrentScalarValue;

            if (m_Type == EVarType::None)
            {
                // No type set yet, set the value
                outScalarValue = parsedScalarValue;
                m_Type = parsedScalarType;

                // If setting default before actual, set actual, too
                if (isDefault)
                    m_CurrentScalarValue = outScalarValue;

                return true;
            }
            else if (m_Type == parsedScalarType)
            {
                // Identical types, set the value
                outScalarValue = parsedScalarValue;
                return true;
            }
            else
            {
                // Try to convert
                return TryConvertType(parsedScalarValue, m_Type, outScalarValue);
            }
        }
        else if (inValue.type == ANY_TTABLE)
        {
            if (m_Type == EVarType::None)
            {
                // We're a table now
                m_Type = EVarType::Table;
            }
            else if (m_Type != EVarType::Table)
            {
                // Trying to set a table into a non-table
                return false;
            }

            // Table merge
            IScriptTable* pTable = inValue.table;
            IScriptTable::Iterator iter = pTable->BeginIteration();

            try
            {
                while (pTable->MoveNext(iter))
                {
                    string keyName;

                    if (!iter.key.CopyTo(keyName))
                    {
                        // Non-string key, skip this
                        continue;
                    }

                    auto myIt = m_Table.find(keyName.AsStringView());

                    if (myIt == m_Table.end())
                    {
                        // New key
                        Variable& newKey = m_Table.emplace(std::string(keyName.AsStringView()), Variable()).first->second;
                        newKey.TrySetValue(iter.value, isDefault);
                    }
                    else
                    {
                        // Merge with existing key
                        myIt->second.TrySetValue(iter.value, isDefault);
                    }
                }
            }
            catch (const std::exception& e)
            {
                pTable->EndIteration(iter);
                throw;
            }

            pTable->EndIteration(iter);
            return true;
        }
        else
        {
            // Unknown type
            return false;
        }
    }

    bool ShowUI(const char* name)
    {
        bool changed = false;
        ImGui::PushID(this);

        if (m_Type == EVarType::Table)
        {
            if (ImGui::TreeNode(name))
            {
                ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

                // Sub-tables first
                for (auto& [key, value] : m_Table)
                {
                    if (value.m_Type == EVarType::Table)
                        changed |= value.ShowUI(key.c_str());
                }

                // Non-tables next
                for (auto& [key, value] : m_Table)
                {
                    if (value.m_Type != EVarType::Table)
                        changed |= value.ShowUI(key.c_str());
                }

                ImGui::TreePop();
            }
        }
        else
        {
            if (m_Type != EVarType::Bool)
            {
                ImGui::TextUnformatted(name);
                ImGui::Indent();
            }

            switch (m_Type)
            {
            case EVarType::None:
                ImGui::TextUnformatted("nil");
                break;
            case EVarType::Int:
            {
                int value = boost::get<int>(m_CurrentScalarValue);
                ImGui::InputInt("##", &value);

                if (ImGui::IsItemDeactivatedAfterEdit())
                {
                    m_CurrentScalarValue = value;
                    changed = true;
                }

                break;
            }
            case EVarType::Bool:
            {
                bool value = boost::get<bool>(m_CurrentScalarValue);

                if (ImGui::Checkbox(name, &value))
                {
                    m_CurrentScalarValue = value;
                    changed = true;
                }

                break;
            }
            case EVarType::Float:
            {
                float value = boost::get<float>(m_CurrentScalarValue);
                ImGui::InputFloat("##", &value);

                if (ImGui::IsItemDeactivatedAfterEdit())
                {
                    m_CurrentScalarValue = value;
                    changed = true;
                }

                break;
            }
            case EVarType::Vec3:
            {
                Vec3 value = boost::get<Vec3>(m_CurrentScalarValue);
                ImGui::InputFloat3("##", &value.x);

                if (ImGui::IsItemDeactivatedAfterEdit())
                {
                    m_CurrentScalarValue = value;
                    changed = true;
                }

                break;
            }
            case EVarType::String:
            {
                std::string value = boost::get<std::string>(m_CurrentScalarValue);
                ImGui::InputText("##", &value);

                if (ImGui::IsItemDeactivatedAfterEdit())
                {
                    m_CurrentScalarValue = value;
                    changed = true;
                }

                break;
            }
            }

            if (m_Type != EVarType::Bool)
            {
                ImGui::Unindent();
            }
        }

        ImGui::PopID();
        return changed;
    }

private:
    EVarType m_Type = EVarType::None;

    // Scalar field - only valid if m_Type != EVarType::Table
    ScalarValue m_CurrentScalarValue;
    ScalarValue m_DefaultScalarValue;
    bool m_bEqualsDefault = false;

    // Table fields - only valid if m_Type == EVarType::Table
    std::map<std::string, Variable, std::less<>> m_Table;
};

class LevelEditor::ScriptTableEditor::ConvertTypeVisitor : public boost::static_visitor<bool>
{
public:
    ConvertTypeVisitor(EVarType type, ScalarValue& convertedValue)
        : m_ConvertedValue(convertedValue)
    {
        m_Type = type;
    }

    bool operator()(std::nullptr_t) const
    {
        // Return default value
        switch (m_Type)
        {
        case EVarType::None:
            m_ConvertedValue = nullptr;
            return true;
        case EVarType::Int:
            m_ConvertedValue = int(0);
            return true;
        case EVarType::Bool:
            m_ConvertedValue = false;
            return true;
        case EVarType::Float:
            m_ConvertedValue = float(0.0f);
            return true;
        case EVarType::Vec3:
            m_ConvertedValue = Vec3(ZERO);
            return true;
        case EVarType::String:
            m_ConvertedValue = std::string();
            return true;
        }

        return false;
    }

    bool operator()(int inValue) const
    {
        return NumericConvert(inValue);
    }

    bool operator()(bool inValue) const
    {
        return NumericConvert(inValue);
    }

    bool operator()(float inValue) const
    {
        return NumericConvert(inValue);
    }

    bool operator()(const Vec3& value) const
    {
        if (m_Type == EVarType::Vec3)
        {
            m_ConvertedValue = value;
            return true;
        }

        return false;
    }

    bool operator()(const std::string& value) const
    {
        if (m_Type == EVarType::String)
        {
            m_ConvertedValue = value;
            return true;
        }

        return false;
    }

private:
    EVarType m_Type;
    ScalarValue& m_ConvertedValue;

    //! Converts between numeric types (int, float, bool).
    template <typename T>
    bool NumericConvert(T inValue) const
    {
        switch (m_Type)
        {
        case EVarType::Int:
            m_ConvertedValue = int(inValue);
            return true;
        case EVarType::Bool:
            m_ConvertedValue = bool(inValue);
            return true;
        case EVarType::Float:
            m_ConvertedValue = float(inValue);
            return true;
        }

        return false;
    }
};

LevelEditor::ScriptTableEditor::ScriptTableEditor()
{
}

LevelEditor::ScriptTableEditor::~ScriptTableEditor()
{
}

void LevelEditor::ScriptTableEditor::Clear()
{
    m_pValue.reset();
}

void LevelEditor::ScriptTableEditor::SetTable(const SmartScriptTable& pTable, bool isDefault)
{
    if (!m_pValue)
        m_pValue = std::make_unique<Variable>();

    m_pValue->TrySetValue(pTable, isDefault);
}

bool LevelEditor::ScriptTableEditor::ShowUI(const char* name)
{
    if (!m_pValue)
        return false;

    // No width for input labels
    ImGui::PushItemWidth(-1);

    // Compact spacing
    ImGuiStyle& style = ImGui::GetStyle();
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(style.FramePadding.x, (float)(int)(style.FramePadding.y * 0.60f)));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(style.ItemSpacing.x, (float)(int)(style.ItemSpacing.y * 0.60f)));

    bool changed = m_pValue->ShowUI(name);

    ImGui::PopStyleVar(2);
    ImGui::PopItemWidth();

    return changed;
}

bool LevelEditor::ScriptTableEditor::TryParseScalar(const ScriptAnyValue& inValue, ScalarValue& outScalar, EVarType& outScalarType)
{
    switch (inValue.type)
    {
    case ANY_TNIL:
        outScalarType = EVarType::None;
        outScalar = nullptr;
        return true;
    case ANY_TBOOLEAN:
        outScalarType = EVarType::Bool;
        outScalar = inValue.b;
        return true;
    case ANY_TNUMBER:
        outScalarType = EVarType::Float;
        outScalar = inValue.number;
        return true;
    case ANY_TSTRING:
        outScalarType = EVarType::String;
        outScalar = std::string(inValue.str);
        return true;
    case ANY_TTABLE:
    {
        IScriptTable* table = inValue.table;

        // Check for Vec3
        Vec3 vec;
        if (table->Count() == 3 && table->GetValue("x", vec.x) && table->GetValue("y", vec.y) && table->GetValue("z", vec.z))
        {
            outScalarType = EVarType::Vec3;
            outScalar = vec;
            return true;
        }

        // Tables are not scalars
        return false;
    }
    case ANY_TVECTOR:
        outScalarType = EVarType::Vec3;
        outScalar = Vec3(inValue.vec3.x, inValue.vec3.y, inValue.vec3.z);
        return true;
    case ANY_TFUNCTION:
    case ANY_TUSERDATA:
    case ANY_THANDLE:
        // Can't be edited
        return false;
    }
}

bool LevelEditor::ScriptTableEditor::TryConvertType(const ScalarValue& inValue, EVarType type, ScalarValue& convertedValue)
{
    // Convert into a temporary because convertedValue may point to inValue.
    ScalarValue outValue;

    if (boost::apply_visitor(ConvertTypeVisitor(type, outValue), inValue))
    {
        convertedValue = std::move(outValue);
        return true;
    }
    else
    {
        return false;
    }
}
