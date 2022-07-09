#pragma once
#include "SerializeFwd.h"

template<typename T> class CSerializeWrapper {};

//! Simple struct to declare something serializable - useful for exposition.
struct ISerializable
{
	virtual ~ISerializable() {}
	virtual void SerializeWith(TSerialize) = 0;
};
