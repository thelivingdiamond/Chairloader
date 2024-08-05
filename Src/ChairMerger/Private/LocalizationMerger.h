#pragma once

class LocalizationMergingException : public std::runtime_error
{
public:
    LocalizationMergingException(const std::string& message, int rowIndex = -1, int cellIndex = -1);

private:
    std::string FormatMsg(const std::string& message, int rowIndex, int cellIndex);
};

//! Stores a localization Excel table.
class LocalizationTable
{
public:
    //! Name of the key column.
    static constexpr char KEY_NAME[] = "key";

    using ColumnNameList = std::vector<std::string>;
    using Row = std::vector<std::string>;
    using RowList = std::vector<Row>;

    //! The names of the columns.
    ColumnNameList columnNames;

    //! Rows of the table.
    RowList rows;

    //! Index of the key column.
    int keyColumnIdx = -1;

    //! Reads a table into this object. May only be called once.
    void ReadTable(const pugi::xml_node& rootNode);

private:
    //! Parses column names from the first row.
    void ParseFirstRow(Row&& row);
};

//! Helper class for Excel spreadsheets merging, which are used by the localization system.
class LocalizationMerger
{
public:
    //! Reads column names and contents from the base node.
    void ReadBaseSheet(const pugi::xml_node& spreadsheet);

    //! Merges a spreadsheet into the current table.
    void MergeSheet(const pugi::xml_node& spreadsheet);

    //! Exports the internal state into an Excel XML spreadsheet.
    pugi::xml_document ExportExcelXml() const;

private:
    //! Maps a column index in mod table to the current table.
    using ColumnMap = std::vector<int>;

    LocalizationTable m_CurrentTable;

    //! Creates new columns if needs to.
    //! @returns The map of column indices in mod table to the current table's.
    ColumnMap MergeColumns(const LocalizationTable& modTable);

    int FindRowByKey(const std::string& key);

    int FindColumnByName(const std::string& name);
};
