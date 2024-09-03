#include "ExcelMerger.h"

ExcelMergingException::ExcelMergingException(const std::string& message, int rowIndex, int cellIndex)
    : std::runtime_error(FormatMsg(message, rowIndex, cellIndex))
{
}

std::string ExcelMergingException::FormatMsg(const std::string& message, int rowIndex, int cellIndex)
{
    std::string outMsg = "Localization error: " + message;

    if (rowIndex != -1)
        outMsg += fmt::format("\n    Row: {}", rowIndex + 1);
    if (cellIndex != -1)
        outMsg += fmt::format("\n    Cell: {}", cellIndex + 1);

    return outMsg;
}

void ExcelTable::ReadTable(std::string_view keyName, const pugi::xml_node& rootNode)
{
    const pugi::xml_node tableNode = rootNode.child("Workbook").child("Worksheet").child("Table");
    if (!tableNode)
        throw ExcelMergingException("Workbook.Worksheet.Table node not found");

    bool foundFirstRow = false;
    int rowIdx = 0;

    for (const pugi::xml_node& row : tableNode.children("Row"))
    {
        // Read contents
        Row rowData;
        rowData.reserve(columnNames.size()); // Can't resize because column count is unknown until first row is read

        int cellIdx = 0;

        for (const pugi::xml_node& cell : row.children("Cell"))
        {
            int excelIndex = cellIdx + 1; // 1-based
            excelIndex = cell.attribute("ss:Index").as_int(excelIndex);
            excelIndex--; // Back to 0-based

            if (columnNames.size() != 0 && excelIndex >= columnNames.size())
            {
                // Too many cells in this row. Skip the rest of the cells.
                break;
            }

            if (excelIndex < cellIdx)
                throw ExcelMergingException("Invalid cell index", rowIdx, cellIdx);

            if (excelIndex > cellIdx)
            {
                // Skip columns
                for (; cellIdx < excelIndex; cellIdx++)
                {
                    rowData.emplace_back();
                }
            }

            std::string value = cell.child("Data").text().as_string();
            rowData.emplace_back(std::move(value));
            cellIdx++;
        }

        if (foundFirstRow)
        {
            // Check that the row isn't empty
            bool isEmpty = true;
            for (const std::string& i : rowData)
            {
                if (!i.empty())
                {
                    isEmpty = false;
                    break;
                }
            }

            if (!isEmpty)
            {
                // Add empty columns at the end
                assert(rowData.size() <= columnNames.size());
                rowData.resize(columnNames.size());

                // Add the data row
                rows.emplace_back(std::move(rowData));
            }
        }
        else
        {
            // Parse column names
            ParseFirstRow(keyName, std::move(rowData));

            if (columnNames.empty())
                throw ExcelMergingException("Table has no columns defined");

            foundFirstRow = true;
        }

        rowIdx++;
    }

    if (!foundFirstRow)
        throw ExcelMergingException("Table has no rows");
}

void ExcelTable::ParseFirstRow(std::string_view keyName, Row&& row)
{
    assert(columnNames.empty());
    int colIdx = 0;
    columnNames = std::move(row);

    for (std::string& colName : columnNames)
    {
        // Convert to lower-case (because CryEngine ignores case when comparing)
        for (char& c : colName)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c - 'A' + 'a';
            }
        }

        if (colName == keyName)
        {
            // Found the key
            if (keyColumnIdx != -1)
            {
                // Allow multiple keys if key is empty
                if (!keyName.empty())
                    throw ExcelMergingException("Table has multiple key columns", 0, colIdx);
            }
            else
            {
                keyColumnIdx = colIdx;
            }
        }

        colIdx++;
    }

    if (keyColumnIdx == -1)
        throw ExcelMergingException("Table has no key column", 0);
}

void ExcelMerger::ReadBaseSheet(const pugi::xml_node& spreadsheet)
{
    m_CurrentTable.ReadTable(m_KeyName, spreadsheet);
    assert(m_CurrentTable.keyColumnIdx != -1);
}

void ExcelMerger::MergeSheet(const pugi::xml_node& spreadsheet)
{
    ExcelTable modTable;
    modTable.ReadTable(m_KeyName, spreadsheet);
    assert(modTable.keyColumnIdx != -1);

    // Create new columns and the column map
    ColumnMap colMap = MergeColumns(modTable);

    for (const ExcelTable::Row& modRow : modTable.rows)
    {
        const std::string& key = modRow[modTable.keyColumnIdx];
        int baseRowIdx = FindRowByKey(key);

        if (baseRowIdx == -1)
        {
            // Create new row
            baseRowIdx = (int)m_CurrentTable.rows.size();
            m_CurrentTable.rows.emplace_back();
            m_CurrentTable.rows[baseRowIdx].resize(m_CurrentTable.columnNames.size());
            m_CurrentTable.rows[baseRowIdx][m_CurrentTable.keyColumnIdx] = key;
        }

        // Replace all non-empty columns in the row
        ExcelTable::Row& currentRow = m_CurrentTable.rows[baseRowIdx];

        for (size_t modCellIdx = 0; modCellIdx < modRow.size(); modCellIdx++)
        {
            const std::string& modCellValue = modRow[modCellIdx];
            int currentCellIdx = colMap[modCellIdx];

            if (modCellIdx == modTable.keyColumnIdx)
            {
                // Key must match. If not, programming bug
                assert(currentRow[currentCellIdx] == modCellValue);
            }

            if (modCellValue.empty())
            {
                // Skip this column since it has no value
                continue;
            }

            // Overwrite the value
            currentRow[currentCellIdx] = modCellValue;
        }
    }
}

pugi::xml_document ExcelMerger::ExportExcelXml() const
{
    // Based on https://en.wikipedia.org/wiki/Microsoft_Office_XML_formats
    // and real Office XML files.
    pugi::xml_document doc;

    // XML declaration
    pugi::xml_node xmlDecl = doc.append_child(pugi::node_declaration);
    xmlDecl.set_name("xml");
    xmlDecl.append_attribute("version").set_value("1.0");
    xmlDecl.append_attribute("encoding").set_value("utf-8");

    // Excel processing instruction
    pugi::xml_node excelPi = doc.append_child(pugi::node_pi);
    excelPi.set_name("mso-application");
    // pugixml doesn't add this attribute for some reason.
    // But it works without it.
    // excelPi.append_attribute("progid").set_value("Excel.Sheet");

    // Workbook
    pugi::xml_node workbook = doc.append_child("Workbook");
    workbook.append_attribute("xmlns").set_value("urn:schemas-microsoft-com:office:spreadsheet");
    workbook.append_attribute("xmlns:o").set_value("urn:schemas-microsoft-com:office:office");
    workbook.append_attribute("xmlns:x").set_value("urn:schemas-microsoft-com:office:excel");
    workbook.append_attribute("xmlns:ss").set_value("urn:schemas-microsoft-com:office:spreadsheet");
    workbook.append_attribute("xmlns:html").set_value("http://www.w3.org/TR/REC-html40");

    // Worksheet
    pugi::xml_node worksheet = workbook.append_child("Worksheet");
    worksheet.append_attribute("ss:Name").set_value("Sheet1");

    // Table
    pugi::xml_node table = worksheet.append_child("Table");

    // Columns
    for (size_t i = 0; i < m_CurrentTable.columnNames.size(); i++)
    {
        table.append_child("Column");
    }

    // Column names row
    {
        pugi::xml_node row = table.append_child("Row");

        for (const std::string& colName : m_CurrentTable.columnNames)
        {
            pugi::xml_node cell = row.append_child("Cell");

            if (!colName.empty())
            {
                pugi::xml_node dataNode = cell.append_child("Data");
                dataNode.append_attribute("ss:Type").set_value("String");
                dataNode.text().set(colName.c_str());
            }
        }
    }

    // Chairloader watermark
    // Size check because the watermark can't go into the key column
    // So there needs to be at least two columns
    // (file with only key column doesn't make sense but just in case)
    if (m_CurrentTable.columnNames.size() >= 2)
    {
        // Find first non-key column
        // It must exist due to the condition above
        size_t watermarkCol = 0;
        while (watermarkCol == m_CurrentTable.keyColumnIdx)
        {
            watermarkCol++;
            assert(watermarkCol < m_CurrentTable.columnNames.size());
        }

        // Watermark row
        pugi::xml_node row = table.append_child("Row");
        for (size_t i = 0; i < m_CurrentTable.columnNames.size(); i++)
        {
            pugi::xml_node cell = row.append_child("Cell");

            if (i == watermarkCol)
            {
                // TODO 2024-03-26: Put version and timestamp here
                // But it will break unit-tests since they compare files directly
                pugi::xml_node dataNode = cell.append_child("Data");
                dataNode.append_attribute("ss:Type").set_value("String");
                dataNode.text().set("File generated by Chairloader");
            }
        }
    }

    // Rows
    for (const ExcelTable::Row& rowData : m_CurrentTable.rows)
    {
        pugi::xml_node row = table.append_child("Row");

        // Cells
        assert(rowData.size() == m_CurrentTable.columnNames.size());

        for (const std::string& cellData : rowData)
        {
            pugi::xml_node cell = row.append_child("Cell");

            if (!cellData.empty())
            {
                pugi::xml_node dataNode = cell.append_child("Data");
                dataNode.append_attribute("ss:Type").set_value("String");
                dataNode.text().set(cellData.c_str());
            }
        }
    }

    return doc;
}

ExcelMerger::ColumnMap ExcelMerger::MergeColumns(const ExcelTable& modTable)
{
    ColumnMap colMap;
    colMap.resize(modTable.columnNames.size());

    size_t oldColumnCount = m_CurrentTable.columnNames.size();

    // Create column mapping. Add new columns if have to.
    for (size_t i = 0; i < colMap.size(); i++)
    {
        int modColIdxInCurrentTable = FindColumnByName(modTable.columnNames[i]);

        if (modColIdxInCurrentTable == -1)
        {
            // Make a new column
            modColIdxInCurrentTable = (int)m_CurrentTable.columnNames.size();
            m_CurrentTable.columnNames.emplace_back();
        }

        colMap[i] = modColIdxInCurrentTable;
    }

    size_t newColumnCount = m_CurrentTable.columnNames.size();

    if (newColumnCount != oldColumnCount)
    {
        // Resize all rows to add the new columns
        for (ExcelTable::Row& modRow : m_CurrentTable.rows)
        {
            assert(modRow.size() == oldColumnCount);
            modRow.resize(newColumnCount);
        }
    }

    return colMap;
}

int ExcelMerger::FindRowByKey(const std::string& key)
{
    // Linear search.
    // This makes merging O(n^2) but there's only a few hundred rows in a table
    int keyColumnIdx = m_CurrentTable.keyColumnIdx;

    for (size_t i = 0; i < m_CurrentTable.rows.size(); i++)
    {
        const ExcelTable::Row& modRow = m_CurrentTable.rows[i];

        if (modRow[keyColumnIdx] == key)
            return (int)i;
    }

    return -1;
}

int ExcelMerger::FindColumnByName(const std::string& name)
{
    for (size_t i = 0; i < m_CurrentTable.columnNames.size(); i++)
    {
        if (m_CurrentTable.columnNames[i] == name)
            return (int)i;
    }

    return -1;
}
