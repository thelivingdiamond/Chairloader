// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/weaponoffset.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// Prey/GameDll/ark/weapons/SStaticWeaponPoseParams.h
struct SStaticWeaponPoseParams // Id=801D52C Size=32
{
	enum EPoseType
	{
		EPT_RightHand = 0,
		EPT_LeftHand = 2,
		EPT_Zoom = 1,
	};

	float pose_type;
	float zoom_transition_angle;
	SWeaponOffset m_offset;
	
#if 0
	void Serialize(Serialization::IArchive &arg0);
	SStaticWeaponPoseParams::EPoseType GetPoseType() const;
#endif
};

