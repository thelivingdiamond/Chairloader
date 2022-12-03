#pragma once
// This file validates compiler configuration to match Prey's ABI
// If you get an error here in Debug mode, set your compiler to:
// - Use "Multi-threaded DLL" runtime library
// - Not define _DEBUG macro

#ifdef _DEBUG
#error _DEBUG must not be defined
#endif

#if CRY_ITERATOR_DEBUGGING || _HAS_ITERATOR_DEBUGGING
#error Iterator debugging must not be enabled
#endif

// Just a few is enough since check above should catch everything
static_assert(sizeof(std::vector<int>) == 24);
static_assert(sizeof(std::string) == 32);
static_assert(sizeof(std::map<int, int>) == 16);
