#pragma once

// C headers
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <ctime>

// Containers
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Utilities
#include <algorithm>
#include <functional>
#include <utility>
#include <memory>
#include <limits>
#include <optional>

// Threading
#include <mutex>
#include <condition_variable>
#include <thread>
#include <future>

// File system
#include <filesystem>
namespace fs = std::filesystem;

// Libraries
#include <iostream>
#include <fstream>
#include <boost/variant.hpp>
#include <boost/optional.hpp>
#include <boost/bimap.hpp>
#include <pugixml.hpp>
#include <imgui.h>
#include <imgui_stdlib.h>

template <typename R>
inline bool IsFutureReady(const std::future<R>& f)
{
	return f.valid() && f.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}
