#pragma once
#include <Preditor/Input/Common.h>

struct IKeyAction;

//! A group of actions. Can be toggled in runtime (e.g. based on currently selected tool)
//! Has priority. When a key combination activates multiple actions from different sets,
//! the one with higher priority is activated.
struct IKeyActionSet
{
    virtual ~IKeyActionSet() {}

    //! @returns the name of the action set.
    virtual const std::string& GetName() = 0;

    //! Activates/deactivates the action set.
    //! @{
    virtual void SetActive(bool state) = 0;
    virtual bool IsActive() = 0;
    //! @}
    
    //! @returns the prioroty of the action set.
    virtual int GetPriority() = 0;

    //! Finds an action by its name.
    //! @returns action or nullptr.
    virtual IKeyAction* FindAction(std::string_view name) = 0;
};
