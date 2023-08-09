#pragma once

//! Unique ID assigned to each listener.
using ListenerId = unsigned;

//! An invalid listener ID.
constexpr ListenerId INVALID_LISTENER_ID = 0;

template <typename... TArgs>
class ListenerSet
{
public:
    using FuncType = typename std::function<void(TArgs...)>;

    //! Adds a new listener.
    //! @returns unique listener id.
    ListenerId Add(const FuncType& f)
    {
        ListenerId id = NextId();
        m_Listeners.push_back(ListenerRecord{ f, id });
        return id;
    }

    //! Removes the listener with specified ID.
    //! @returns true if was removed, false if not found.
    bool Remove(ListenerId id)
    {
        if (id == INVALID_LISTENER_ID)
            return false;

        auto it = std::find_if(m_Listeners.begin(), m_Listeners.end(), [id](const ListenerRecord& r) { return r.id == id; });

        if (it != m_Listeners.end())
        {
            m_Listeners.erase(it);
            return true;
        }
        else
        {
            return false;
        }
    }

    //! Calls all listeners with specified arguments.
    void Invoke(TArgs... args)
    {
        for (ListenerRecord& i : m_Listeners)
        {
            i.func(args...);
        }
    }

    //! @returns whether there are no listeners.
    bool IsEmpty() { return m_Listeners.empty(); }

    //! @returns whether there are any listeners.
    bool IsNotEmpty() { return !m_Listeners.empty(); }

private:
    static constexpr ListenerId MAX_ID = std::numeric_limits<ListenerId>::max();
    
    struct ListenerRecord
    {
        FuncType func;
        ListenerId id;
    };

    std::vector<ListenerRecord> m_Listeners;
    ListenerId m_NextId = 1;

    ListenerId NextId()
    {
        ListenerId id = m_NextId;

        if (id == MAX_ID)
            CryFatalError("ListenerSet: Too many listeners");

        m_NextId++;
        return id;
    }
};
