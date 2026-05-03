#include "Clipboard.h"

FlowgraphEditor::Clipboard& FlowgraphEditor::Clipboard::Get()
{
    static Clipboard s_instance;
    return s_instance;
}
