// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/XML/IXml.h>

class ArkClass;
class ArkProperty;
class ArkReflectedObject;

// Header: Exact
// Prey/ArkCommon/reflection/XMLObjectReader.h
class XMLObjectReader // Id=800442B Size=8
{
public:
	XmlNodeRef m_root;
	
	bool ReadObject(ArkReflectedObject *const _pObject) const { return FReadObject(this,_pObject); }
	static void ReadObjectInternal(XmlNodeRef _node, ArkClass const *const _pClassDef, ArkReflectedObject *const _pObject, bool _bResetArrays) { FReadObjectInternal(_node,_pClassDef,_pObject,_bResetArrays); }
	static void ReadPropertyElement(XmlNodeRef _node, ArkProperty const *const _pProperty, const char *_name, ArkReflectedObject *const _pObject) { FReadPropertyElement(_node,_pProperty,_name,_pObject); }
	
#if 0
	ArkReflectedObject *CreateObject() const;
	static bool ReadObjects(std::vector<XmlNodeRef> arg0, ArkReflectedObject *const arg1);
	static void ReadProperty(XmlNodeRef arg0, ArkProperty const *const arg1, ArkReflectedObject *const arg2, bool arg3);
#endif
	
	static inline auto FReadObject = PreyFunction<bool(XMLObjectReader const *const _this, ArkReflectedObject *const _pObject)>(0x158BB00);
	static inline auto FReadObjectInternal = PreyFunction<void(XmlNodeRef _node, ArkClass const *const _pClassDef, ArkReflectedObject *const _pObject, bool _bResetArrays)>(0x2A0EF0);
	static inline auto FReadPropertyElement = PreyFunction<void(XmlNodeRef _node, ArkProperty const *const _pProperty, const char *_name, ArkReflectedObject *const _pObject)>(0x2A1360);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/XML/IXml.h>

class ArkClass;
class ArkProperty;
class ArkReflectedObject;

// XMLObjectReader
// Header:  Prey/ArkCommon/reflection/XMLObjectReader.h
class XMLObjectReader
{ // Size=8 (0x8)
public:
	XmlNodeRef m_root;

	bool ReadObject(ArkReflectedObject* const _pObject) const { return FReadObject(this, _pObject); }
	static void ReadObjectInternal(XmlNodeRef _node, const ArkClass* const _pClassDef, ArkReflectedObject* const _pObject, bool _bResetArrays) { FReadObjectInternal(_node, _pClassDef, _pObject, _bResetArrays); }
	static void ReadPropertyElement(XmlNodeRef _node, const ArkProperty* const _pProperty, const char* _name, ArkReflectedObject* const _pObject) { FReadPropertyElement(_node, _pProperty, _name, _pObject); }

#if 0
	XMLObjectReader(XmlNodeRef _arg0_);
	ArkReflectedObject* CreateObject() const;
	static bool ReadObjects(std::vector<XmlNodeRef> _arg0_, ArkReflectedObject* const _arg1_);
	static void ReadProperty(XmlNodeRef _arg0_, const ArkProperty* const _arg1_, ArkReflectedObject* const _arg2_, bool _arg3_);
#endif

	static inline auto FReadObject = PreyFunction<bool(const XMLObjectReader* const _this, ArkReflectedObject* const _pObject)>(0x16B2860);
	static inline auto FReadObjectInternal = PreyFunction<void(XmlNodeRef _node, const ArkClass* const _pClassDef, ArkReflectedObject* const _pObject, bool _bResetArrays)>(0x2B93B0);
	static inline auto FReadPropertyElement = PreyFunction<void(XmlNodeRef _node, const ArkProperty* const _pProperty, const char* _name, ArkReflectedObject* const _pObject)>(0x2B9820);
};
#endif // !MOONCRASH
