#pragma once
#include <WindowManager/ManagedWindow.h>

namespace Main
{

class HexViewer : public ManagedWindow
{
public:
    HexViewer(const std::string& path);
    ~HexViewer();

protected:
    virtual void ShowContents() override;

private:
    static constexpr uint64_t MAX_FILE_SIZE = 32 * 1024 * 1024;
    
    std::vector<uint8_t> m_Buf;
    std::vector<char> m_TextBuf;
    std::string m_LargeFileWarn;
    int m_BytesPerLine = 32;
};

} // namespace Main
