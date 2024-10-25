#pragma once

class ExcelMergingException : public std::runtime_error
{
public:
    ExcelMergingException(const std::string& message, int rowIndex = -1, int cellIndex = -1);

private:
    std::string FormatMsg(const std::string& message, int rowIndex, int cellIndex);
};

//! Stores a localization Excel table.
class ExcelTable
{
public:
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
    void ReadTable(std::string_view keyName, const pugi::xml_node& rootNode);

    //! Exports the table into an Excel XML spreadsheet.
    pugi::xml_document ExportExcelXml() const;

private:
    //! Parses column names from the first row.
    void ParseFirstRow(std::string_view keyName, Row&& row);
};

//! Helper class for Excel spreadsheets merging, which are used by the localization system.
class ExcelMerger
{
public:
    ExcelMerger(std::string_view keyName) { m_KeyName = keyName; }

    //! Reads column names and contents from the base node.
    void ReadBaseSheet(const pugi::xml_node& spreadsheet);

    //! Merges a spreadsheet into the current table.
    void MergeSheet(const pugi::xml_node& spreadsheet);

    //! Exports the internal state into an Excel XML spreadsheet.
    pugi::xml_document ExportExcelXml() const;

private:
    //! Maps a column index in mod table to the current table.
    using ColumnMap = std::vector<int>;

    std::string m_KeyName;
    ExcelTable m_CurrentTable;

    //! Creates new columns if needs to.
    //! @returns The map of column indices in mod table to the current table's.
    ColumnMap MergeColumns(const ExcelTable& modTable);

    int FindRowByKey(const std::string& key);

    int FindColumnByName(const std::string& name);
};
