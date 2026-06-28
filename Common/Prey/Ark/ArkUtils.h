// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

struct IEntityClass;
class XmlNodeRef;

namespace ArkUtils
{

// Header: Exact
// Prey/Ark/arkutils.h
class ClassList // Id=80031C7 Size=24
{
public:
	std::vector<IEntityClass *> m_classes;
	
	void Init(XmlNodeRef const &_root) { FInit(this,_root); }
	
#if 0
	bool Contains(IEntityClass const *const arg0) const;
#endif
	
	static inline auto FInit = PreyFunction<void(ArkUtils::ClassList *const _this, XmlNodeRef const &_root)>(0x5AC380);
};

} // namespace ArkUtils

namespace ArkUtils
{

// Header: Override
// Prey/Ark/ArkUtils.h
class CollisionCache // Id=80031C8 Size=24
{
public:
	struct Collision // Id=80031CE Size=12
	{
		unsigned m_src;
		unsigned m_trg;
		float m_time;
		
#if 0
		bool operator<(const float arg0);
#endif
	};

	std::vector<ArkUtils::CollisionCache::Collision> m_collisions;
	
#if 0
	boost::optional<float> Process(const unsigned arg0, const unsigned arg1, const float arg2, const float arg3);
#endif
};

} // namespace ArkUtils
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IEntityClass;
class XmlNodeRef;

namespace ArkUtils
{

// ArkUtils::ClassList
// Header:  Prey/Ark/ArkUtils.h
class ClassList
{ // Size=24 (0x18)
public:
	std::vector<IEntityClass*> m_classes;

	void Init(const XmlNodeRef& _root) { FInit(this, _root); }

#if 0
	bool Contains(const IEntityClass* const _arg0_) const;
#endif

	static inline auto FInit = PreyFunction<void(ArkUtils::ClassList* const _this, const XmlNodeRef& _root)>(0x5C5A60);
};

// ArkUtils::CollisionCache
// Header:  Prey/Ark/ArkUtils.h
class CollisionCache
{ // Size=24 (0x18)
public:
	// ArkUtils::CollisionCache::Collision
	// Header:  Prey/Ark/ArkUtils.h
	struct Collision
	{ // Size=12 (0xC)
		unsigned m_src;
		unsigned m_trg;
		float m_time;

	#if 0
		bool operator<(const float _arg0_);
	#endif
	};

	std::vector<ArkUtils::CollisionCache::Collision> m_collisions;

#if 0
	boost::optional<float> Process(const unsigned _arg0_, const unsigned _arg1_, const float _arg2_, const float _arg3_);
#endif
};


} // namespace ArkUtils
#endif // !MOONCRASH
