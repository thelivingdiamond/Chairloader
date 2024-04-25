#pragma once
#include <Prey/CryCore/StdAfx.h>

// Threading
#include <mutex>
#include <condition_variable>
#include <thread>
#include <future>

// Libraries
#include <pugixml.hpp>

template <typename R>
inline bool IsFutureReady(const std::future<R>& f)
{
	return f.valid() && f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}
