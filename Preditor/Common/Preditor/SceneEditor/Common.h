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
