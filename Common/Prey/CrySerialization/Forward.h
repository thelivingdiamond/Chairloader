// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

namespace yasli
{
class Archive;
class Serializer;
struct Context;
class TypeID;
struct BlackBox;
template<class T> class ClassFactory;
class StringList;
class StringListValue;
class StringListStatic;
class StringListStaticValue;
class EnumDescription;
}

namespace Serialization
{
using yasli::ClassFactory;
class IArchive;
struct SBlackBox;
struct SContext;
struct SContextLink;
struct SStruct;
using yasli::TypeID;
using yasli::StringList;
using yasli::StringListValue;
using yasli::StringListStatic;
using yasli::StringListStaticValue;
using yasli::EnumDescription;
class CContextList;
}
