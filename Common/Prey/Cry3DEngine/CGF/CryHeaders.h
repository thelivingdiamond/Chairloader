#pragma once

#define MAX_STATOBJ_LODS_NUM 6
#define MAX_SUB_MATERIALS    128

enum EPhysicsGeomType
{
	PHYS_GEOM_TYPE_NONE = -1,
	PHYS_GEOM_TYPE_DEFAULT = 0x1000 + 0,
	PHYS_GEOM_TYPE_NO_COLLIDE = 0x1000 + 1,
	PHYS_GEOM_TYPE_OBSTRUCT = 0x1000 + 2,

	PHYS_GEOM_TYPE_DEFAULT_PROXY = 0x1000 + 0x100, //!< Default physicalization, but only proxy (NoDraw geometry).
};
