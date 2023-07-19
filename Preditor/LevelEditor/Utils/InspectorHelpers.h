#pragma once

namespace LevelEditor::Inspector
{

//! Begins the inspector node.
bool Begin(const char* name, ImGuiTreeNodeFlags flags = 0);

//! Ends the inspector node. Only call if BeginInspector returned true.
void End();

} // namespace LevelEditor::Inspector
