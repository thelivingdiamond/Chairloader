#pragma once

namespace LevelEditor
{

//! Generic editor for Lua script tables (IScriptTable). It's designed for entity property tables.
//! Stores the values and provides ImGui UI for viewing and editing.
//! In addition to current values, stores defaults for easy reverting.
class ScriptTableEditor : NoCopy
{
public:
    ScriptTableEditor();
    ~ScriptTableEditor();

    //! Removes all variables.
    void Clear();

    //! Gets all values and stores them into a table.
    void GetTable(SmartScriptTable& pTable);

    //! Creates variables for a table and set the values.
    //! Old values are not cleared.
    void SetTable(const SmartScriptTable& pTable, bool isDefault);

    //! Shows the UI.
    bool ShowUI(const char* name);

private:
    enum class EVarType;
    class ConvertTypeVisitor;
    class GetValueAnyVisitor;
    class Variable;

    //! Variant with non-recursive values.
    using ScalarValue = boost::variant<
        std::nullptr_t,
        int,
        bool,
        float,
        Vec3,
        std::string>;

    std::unique_ptr<Variable> m_pValue;

    //! Tries to parse as a scalar value. Converts Vec3-like tables into Vec3.
    //! @param  inValue         Original value.
    //! @param  outScalar       [out] Output value. Set only if returns true.
    //! @param  outScalarType   [out] Output value type.
    //! @returns Whether parsed successfully.
    static bool TryParseScalar(const ScriptAnyValue& inValue, ScalarValue& outScalar, EVarType& outScalarType);

    //! Tries to convert a value to a different type.
    //! @param  inValue         Original value.
    //! @param  type            Target type.
    //! @param  convertedValue  [out] Output value. May point to the same as inValue.
    //! @returns Whether the conversion was successfull.
    static bool TryConvertType(const ScalarValue& inValue, EVarType type, ScalarValue& convertedValue);
};

} // namespace LevelEditor
