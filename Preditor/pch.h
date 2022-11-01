#pragma once
#include <Prey/CryCore/StdAfx.h>
#include "IconsMaterialDesign.h"
#include <future>

template <typename R>
inline bool IsFutureReady(const std::future<R>& f)
{
    return f.valid() && f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}