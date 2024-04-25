#pragma once

namespace LevelEditor
{

class LevelEditMode;
class ObjectManager;

struct GlobalLevel
{
    LevelEditMode* pEditor;
    ObjectManager* pObjectManager;
};

extern GlobalLevel* gLevel;

} // namespace LevelEditor
