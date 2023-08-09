#pragma once
#include <Preditor/Input/IKeyboardInputSystem.h>
#include "KeyMap.h"
#include "KeyActionSet.h"
#include "KeyActionBind.h"

namespace Input
{

class KeyboardInputSystem final : public IKeyboardInputSystem
{
public:
    KeyboardInputSystem();

    //! @returns the default action set priority.
    int GetDefaultPriority() const { return m_DefaultPriority; }

    //! @returns the current frame index.
    unsigned GetFrameIndex() const { return m_CurrentFrame; }

    void Update();

    // IKeyboardInputSystem
    virtual IKeyMap* GetKeyMap() override { return &m_KeyMap; }
    virtual IKeyActionSet* FindActionSet(std::string_view name) override;
    virtual IKeyAction* FindAction(std::string_view path, bool silent = false) override;
    virtual void ReloadKeybinds() override;
    virtual void UpdateModMask(ModifierKeyMask modMask) override;
    virtual void OnKeyDown(EKeyId keyId) override;
    virtual void OnKeyUp(EKeyId keyId) override;

private:
    static constexpr char ACTION_SETS_PATH[] = "Preditor/ActionSets.xml";

    struct KeyBindList
    {
        std::vector<KeyActionBind> bindList;
    };

    struct KeyEventArgs
    {
        EKeyId keyId = eKI_Unknown;
        bool isPressed = false;
    };

    KeyMap m_KeyMap;
    int m_DefaultPriority = 0;
    std::vector<std::unique_ptr<KeyActionSet>> m_ActionSets;
    std::map<std::string, KeyActionSet*, std::less<>> m_ActionSetsByName;

    std::vector<KeyBindList> m_KeyBinds;
    unsigned m_NextBindId = 1;
    ModifierKeyMask m_ModMask = MODIFIER_MASK_NONE;

    //! Key press events can come at different times during the frame.
    //! Queue them to always process at the same time.
    std::vector<KeyEventArgs> m_EventQueue;

    //! Frame index. Incremented every update.
    unsigned m_CurrentFrame = 1;

    void LoadActionSets();
    void LoadDefaultKeybinds();
    void LoadUserKeybinds();

    //! Adds a new bind for the action.
    void AddBind(const KeyBind& bind, KeyAction* pAction);

    //! Gets the bind list for a key id.
    KeyBindList* GetBindList(EKeyId keyId);

    void ProcessKeyEvent(const KeyEventArgs& ev);

    //! Counts the number of modifiers set.
    static int CountModifiers(ModifierKeyMask mask);
};

} // namespace Input
