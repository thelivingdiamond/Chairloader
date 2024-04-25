#pragma once
#include <App/AppStage.h>

//! Base class for singleton app stages.
//! Provides static Get() method to get the singleton instance.
//! @tparam	T	Type name of the stage.
template <typename T>
class SingletonAppStage : public AppStage
{
public:
	//! Gets the instance of this singleton app stage.
	//! @returns instance or nullptr.
	static T* Get() { return static_cast<T*>(m_spInstance); }

	SingletonAppStage()
	{
		assert(!m_spInstance && "Duplicate singleton app stage instance");
		m_spInstance = this;
	}

	virtual ~SingletonAppStage()
	{
		assert(m_spInstance == this);
		m_spInstance = nullptr;
	}

private:
	static inline SingletonAppStage* m_spInstance = nullptr;
};
