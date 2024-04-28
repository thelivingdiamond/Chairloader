#pragma once
#include <mutex>
#include <shared_mutex>

template <typename T, typename TMutex = std::mutex>
class SynchronizedData
{
public:
    //! @returns A new scoped lock.
    std::scoped_lock<TMutex> GetScopedLock() const { return std::scoped_lock<TMutex>(m_Mutex); }

    //! @returns A new unique lock.
    std::unique_lock<TMutex> GetUniqueLock() const { return std::unique_lock<TMutex>(m_Mutex); }

    //! @returns A new shared lock. Only valid if using a shared mutex.
    std::shared_lock<TMutex> GetSharedLock() const { return std::shared_lock<TMutex>(m_Mutex); }

    //! @returns The data. Only use when holding a lock.
    //! @{
    T& GetData() { return m_Data; }
    const T& GetData() const { return m_Data; }
    //! @}

private:
    mutable TMutex m_Mutex;
    T m_Data;
};
