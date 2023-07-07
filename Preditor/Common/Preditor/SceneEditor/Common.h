#pragma once

//! Scene edit mode.
enum class EEditMode
{
    //! Not editing a scene (e.g. level not loaded).
    None,

    //! Editing the level file.
    Level,

    //! The game is playing, editing entities.
    Game,
};

//! Level editor play mode.
enum class EPlayMode
{
    //! Game not running, user is editing the level.
    Edit,

    //! Game is playing the level.
    Play,

    //! Not playing but simulating physics/AI.
    PhysicsAI,
};

//! An ID used by SceneEditor interfaces to reference an object (either an entity or level object).
using SceneObjectId = uint64_t;

//! An ID of an invalid scene object.
constexpr SceneObjectId INVALID_SCENE_OBJECT = -1;

//! Selection colors. Stolen from Blender.
//! @{
inline const ColorB SELECTION_COLOR = ColorB(220, 84, 20, 255);
inline const ColorB SELECTION_ACTIVE_COLOR = ColorB(243, 153, 51, 255);
//! @}
