#pragma once

namespace LevelEditor
{

class LevelEditMode;
class ObjectManager;
class AuxGeomManager;

struct GlobalLevel
{
    LevelEditMode* pEditor = nullptr;
    ObjectManager* pObjectManager = nullptr;
    AuxGeomManager* pAuxGeomManager = nullptr;
};

extern GlobalLevel* gLevel;

} // namespace LevelEditor
