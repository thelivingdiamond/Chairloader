// Header file automatically created from a PDB.

#pragma once

namespace NFlowSystemUtils
{

//! This class helps define IFlowGraph by declaring typed virtual functions corresponding to TFlowSystemDataTypes.
template<typename T>
struct Wrapper;

template<>
struct Wrapper<SFlowSystemVoid>
{
	explicit Wrapper(const SFlowSystemVoid& v) : value(v) {}
	const SFlowSystemVoid& value;
};
template<>
struct Wrapper<int>
{
	explicit Wrapper(const int& v) : value(v) {}
	const int& value;
};
template<>
struct Wrapper<float>
{
	explicit Wrapper(const float& v) : value(v) {}
	const float& value;
};
template<>
struct Wrapper<EntityId>
{
	explicit Wrapper(const EntityId& v) : value(v) {}
	const EntityId& value;
};
template<>
struct Wrapper<Vec3>
{
	explicit Wrapper(const Vec3& v) : value(v) {}
	const Vec3& value;
};
template<>
struct Wrapper<string>
{
	explicit Wrapper(const string& v) : value(v) {}
	const string& value;
};
template<>
struct Wrapper<bool>
{
	explicit Wrapper(const bool& v) : value(v) {}
	const bool& value;
};

} // namespace NFlowSystemUtils

