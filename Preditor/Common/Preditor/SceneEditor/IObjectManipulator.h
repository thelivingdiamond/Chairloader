#pragma once
#include <Preditor/SceneEditor/Common.h>

struct IObjectManipulator
{
    virtual ~IObjectManipulator() {}

    //! @returns an object's world translation matrix.
    virtual Matrix34 GetObjectWorldTM(SceneObjectId id) = 0;

    //! Sets an object's world translation matrix.
    virtual void SetObjectWorldTM(SceneObjectId id, const Matrix34& tm) = 0;
};
