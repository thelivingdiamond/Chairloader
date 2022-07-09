#pragma once
#include <type_traits>

//! Base non-templated class for pointers to functions in the game DLL.
class PreyFunctionBase : NoCopy {
public:
	//! Contructs the function pointer.
	//! @param	offset	Offset into the game module.
	PreyFunctionBase(uintptr_t offset);

	//! @returns raw pointer to the function. If not initialized, returns offset.
	inline uintptr_t GetRawPtr() { return m_Ptr; }

protected:
	uintptr_t m_Ptr = 0;

private:
	PreyFunctionBase* m_pNext = nullptr;

	//! Initializes the function pointer.
	//! @param	moduleBase	Base address of the game module.
	void Init(uintptr_t moduleBase);

	friend class PreyFunctionSystem;
};

//! This declaration is required because C++
template <typename UnusedType>
class PreyFunction;

//! Class for pointers to functions in the game DLL.
template <typename ReturnType, typename ... ArgumentTypes>
class PreyFunction<ReturnType(ArgumentTypes ...)> : public PreyFunctionBase {
public:
	using Type = ReturnType(ArgumentTypes ...);

	using PreyFunctionBase::PreyFunctionBase;

	//! Calls the function with specified arguments.
	inline ReturnType operator ()(ArgumentTypes ... args) {
		return Get()(args ...);
	}

	//! @returns the function pointer.
	inline Type* Get() { return reinterpret_cast<Type*>(m_Ptr); }
};

//! Static class for Prey function initialization.
class PreyFunctionSystem {
public:
	//! Initializes all functions.
	static void Init(uintptr_t moduleBase);
};
