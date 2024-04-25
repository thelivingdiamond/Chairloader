#include <Prey/CrySystem/File/ICryPak.h>
#include <Prey/CrySystem/File/CryFile.h>
#include <UI/FileViewers/HexViewer.h>

Main::HexViewer::HexViewer(const std::string& path)
{
    std::string_view fileName = path;
    auto slash = path.find_last_of("/\\");
    if (slash != std::string::npos)
        fileName = fileName.substr(slash + 1);

    SetTitle(fmt::format("HEX: {}", fileName));
    SetFlags(ImGuiWindowFlags_NoSavedSettings);
    SetDestroyOnClose(true);
    
    CCryFile file;
    
    if (!file.Open(path.c_str(), "rb"))
        throw std::runtime_error("Failed to open file");

    uint64_t fileSize = file.GetLength();

    if (fileSize > MAX_FILE_SIZE)
    {
        m_LargeFileWarn = fmt::format("Files is too large and was truncated ({:.2f} MiB > {:.2f} MiB)",
            fileSize / 1024.0 / 1024.0,
            MAX_FILE_SIZE / 1024.0 / 1024.0);
        fileSize = MAX_FILE_SIZE;
    }

    m_Buf.resize(fileSize);
    uint64_t readSize = file.ReadRaw(m_Buf.data(), m_Buf.size());

    if (readSize == 0)
    {
        throw std::runtime_error("Failed to read file");
    }
    else if (readSize != fileSize)
    {
        m_LargeFileWarn = fmt::format("File was read partially ({:.2f}/{:.2f} KiB)",
            readSize / 1024.0,
            fileSize / 1024.0);
    }
}

Main::HexViewer::~HexViewer()
{
}

void Main::HexViewer::ShowContents()
{
    ImGui::InputInt("Bytes per line", &m_BytesPerLine);

    if (!m_LargeFileWarn.empty())
        ImGui::TextColored(ImColor(255, 255, 0), "Warning! %s", m_LargeFileWarn.c_str());

    m_TextBuf.resize(m_BytesPerLine + 1);

    ImGui::PushFont(gPreditor->pFonts->pMonospace);

    // Header
    ImGui::Text("Offset(h) ");
    ImGui::SameLine(0, 0);
    for (int i = 0; i < m_BytesPerLine; i++)
    {
        ImGui::Text("%02X ", i);
        ImGui::SameLine(0, 0);
    }

    ImGui::Text("  Decoded Text");

    int lineCount = m_Buf.size() / m_BytesPerLine;
    if ((m_Buf.size() % m_BytesPerLine) != 0)
        lineCount++;

    ImGuiListClipper clipper;
    clipper.Begin(lineCount);
    while (clipper.Step())
    {
        for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++)
        {
            // Offset
            size_t offset = (size_t)m_BytesPerLine * row;
            ImGui::Text("%08llX  ", offset);
            ImGui::SameLine(0, 0);

            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.75f, 0.75f, 0.75f, 1.0f));

            size_t len = m_BytesPerLine;
            if (offset + len > m_Buf.size())
                len = m_Buf.size() - offset;

            for (int i = 0; i < len; i++)
            {
                int val = m_Buf[offset + i];
                ImGui::Text("%02X ", val);
                ImGui::SameLine(0, 0);

                if (val >= 0x20 && val <= 0x7E)
                    m_TextBuf[i] = val;
                else
                    m_TextBuf[i] = '.';
            }

            for (int i = len; i < m_BytesPerLine; i++)
            {
                ImGui::Text("   ");
                ImGui::SameLine(0, 0);
            }

            m_TextBuf[len] = '\0';
            ImGui::Text("  %s", m_TextBuf.data());

            ImGui::PopStyleColor();
        }
    }

    ImGui::PopFont();
}
