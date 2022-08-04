// Header file automatically created from a PDB.

#pragma once

struct IRenderNode;
struct SDynTexture_Shadow;

// Header: MadeUp
// _unknown/CShadowTextureGroupManager.h
class CShadowTextureGroupManager // Id=8010E31 Size=24
{
public:
	struct SShadowTextureGroup // Id=8010E32 Size=16
	{
		IRenderNode const *m_pLightOwner;
		SDynTexture_Shadow *m_pTextureGroupItem;
	};

	std::vector<CShadowTextureGroupManager::SShadowTextureGroup> m_GSMGroups;
	
#if 0
	SDynTexture_Shadow **FindOrCreateShadowTextureGroup(IRenderNode const *arg0);
	void RemoveTextureGroupEntry(IRenderNode const *arg0);
#endif
};

