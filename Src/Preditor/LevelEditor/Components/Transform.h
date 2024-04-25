#pragma once
#include <Preditor/IntrusiveList.hpp>
#include "Components/Component.h"

namespace LevelEditor
{

//! Object transform hierarchy.
class Transform : public Component
{
public:
    Transform();
    ~Transform();

    //! @returns local transformation.
    //! @{
    const Vec3& GetPos() const { return m_Pos; }
    const Quat& GetRot() const { return m_Rot; }
    const Vec3& GetScale() const { return m_Scale; }
    const Matrix34& GetLocalTM() const { return m_Mat; }
    //! @}

    //! Sets local transformation.
    //! @{
    void SetPos(const Vec3& pos);
    void SetRot(const Quat& rot);
    void SetScale(const Vec3& scale);
    void SetPosRotScale(const Vec3& pos, const Quat& rot, const Vec3& scale);
    void SetLocalTM(const Matrix34& tm);
    //! @}
    
    //! @returns world-space tranformation matrix.
    const Matrix34& GetWorldTM() const { return m_WMat; }

    //! Sets the world-space tranformation matrix.
    void SetWorldTM(const Matrix34& tm);

    //! @returns the object's parent, if there is one.
    Transform* GetParent() const { return m_pParent; }

    //! Sets the object's parent.
    void SetParent(Transform* pNewParent, bool suppressTransform = false);

    //! @returns the object's children.
    const IntrusiveList<Transform>& GetChildren() const { return m_Children; }

    //! Invalidates the transformation matrix.
    //! @param  nWhyFlags   Mask of EEntityXFormFlags. Informs what has changed.
    void InvalidateTM(unsigned nWhyFlags);

    //! Loads object transform.
    void Init(XmlNodeRef objectNode);

protected:
    // Component
    virtual void ShowInspector();

private:
    // Local transform
    Vec3 m_Pos = Vec3(ZERO);
    Quat m_Rot = Quat(IDENTITY);
    Vec3 m_Scale = Vec3(1, 1, 1);
    Matrix34 m_Mat;

    // World transform cache
    Matrix34 m_WMat;

    // Object parenting
    Transform* m_pParent = nullptr;
    IntrusiveListItem m_ThisItemInParent;
    IntrusiveList<Transform> m_Children; //!< The list is non-owning!!

    void CalcLocalTM();
    void CalcWorldTM();
};

} // namespace LevelEditor
