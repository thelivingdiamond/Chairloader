// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntity.h>
#include <Prey/CrySystem/XML/IXml.h>

namespace CryGame
{

// CryGame::tEntityParams
// Header:  _unknown/CryGame__tEntityParams.h
struct tEntityParams
{ // Size=200 (0xC8)
	SEntitySpawnParams pSpawnParams;
	XmlNodeRef pEntityNode;
	Matrix34 mat;
};


} // namespace CryGame

