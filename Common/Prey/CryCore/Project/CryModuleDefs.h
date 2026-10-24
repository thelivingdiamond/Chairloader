// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef CRYMODULEDEFS_H__
#define CRYMODULEDEFS_H__

enum ECryModule
{
	eCryM_Local = 0x0,
	eCryM_3DEngine = 0x1,
	eCryM_Action = 0x2,
	eCryM_AISystem = 0x3,
	eCryM_Animation = 0x4,
	eCryM_EntitySystem = 0x5,
	eCryM_Font = 0x6,
	eCryM_Input = 0x7,
	eCryM_Movie = 0x8,
	eCryM_Network = 0x9,
	eCryM_Lobby = 0xA,
	eCryM_Physics = 0xB,
	eCryM_ScriptSystem = 0xC,
	eCryM_SoundSystem = 0xD,
	eCryM_System = 0xE,
	eCryM_Game = 0xF,
	eCryM_Render = 0x10,
	eCryM_Launcher = 0x11,
	eCryM_Editor = 0x12,
	eCryM_Num = 0x13,
};

#endif //CRYMODULEDEFS_H__
