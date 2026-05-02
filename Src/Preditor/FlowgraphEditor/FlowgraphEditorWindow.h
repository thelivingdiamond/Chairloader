#pragma once
#include <WindowManager/ManagedWindow.h>

namespace FlowgraphEditor
{

class GraphTab;

class FlowgraphEditorWindow : public ManagedWindow
{
public:
    FlowgraphEditorWindow();
    ~FlowgraphEditorWindow();

protected:
    virtual void Update(bool isVisible) override;
    virtual void ShowContents() override;

private:
    void DrawFileLoader();
    void DrawPrototypeBrowser();
    void LoadGraphsFromFile(const std::string& path);

    std::vector<std::unique_ptr<GraphTab>> m_Tabs;
    std::string m_LoadPath;
    std::string m_LoadStatus;
    std::string m_PrototypeFilter;
};

} // namespace FlowgraphEditor
