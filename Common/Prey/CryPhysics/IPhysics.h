// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.
#pragma once

#if defined (_LIB)
#define CRYPHYSICS_API
#elif defined (PHYSICS_EXPORTS)
#define CRYPHYSICS_API DLL_EXPORT
#else
#define CRYPHYSICS_API DLL_IMPORT
#endif

struct IPhysicalWorld;

#if !defined (_LIB)
extern "C" 
#endif
CRYPHYSICS_API IPhysicalWorld * CreatePhysicalWorld(struct ISystem* pLog);

//! IDs that can be used for foreign id.
enum EPhysicsForeignIds
{
	PHYS_FOREIGN_ID_TERRAIN = 0x0,
	PHYS_FOREIGN_ID_STATIC = 0x1,
	PHYS_FOREIGN_ID_ENTITY = 0x2,
	PHYS_FOREIGN_ID_FOLIAGE = 0x3,
	PHYS_FOREIGN_ID_ROPE = 0x4,
	PHYS_FOREIGN_ID_WATERVOLUME = 0x8,
	PHYS_FOREIGN_ID_RIGID_PARTICLE = 0xB,
	PHYS_FOREIGN_ID_RESERVED1 = 0xC,
	PHYS_FOREIGN_ID_RAGDOLL = 0xD,
	PHYS_FOREIGN_ID_BREAKABLE_PLANE = 0xE,
	PHYS_FOREIGN_ID_ARK_BREAKABLE_GLASS = 0xF,
	PHYS_FOREIGN_ID_EXPLOSION = 0x10,
	PHYS_FOREIGN_ID_USER                     = 100, //!< All user defined foreign ids should start from this enum.
	PHYS_FOREIGN_ID_ARK_DECAL,
	PHYS_FOREIGN_ID_ARK_SERIALIZED_EVENT,
};

//#include <CryMemory/CrySizer.h>
#include <Prey/CryPhysics/physinterface.h>
