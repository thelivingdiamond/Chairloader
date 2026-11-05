// ArkPairHash<std::hash>: a stateless hasher for std::pair keys (ArkFactionManager disposition maps).
#pragma once
#include <cstddef>
#include <utility>

template<template<typename> class THash>
struct ArkPairHash
{
	template<typename A, typename B>
	size_t operator()(const std::pair<A, B>& p) const
	{
		const size_t h1 = THash<A>()(p.first);
		const size_t h2 = THash<B>()(p.second);
		return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
	}
};
