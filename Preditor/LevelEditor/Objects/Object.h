#pragma once
#include <Preditor/SceneEditor/Common.h>
#include "Components/ComponentList.h"
#include "Components/Transform.h"
#include "Components/BBoxComponent.h"
#include "Utils/InspectorHelpers.h"

struct ViewportRaycastInfo;

namespace LevelEditor
{

class ObjectManager;
struct RayIntersectInfo;

enum class EObjectType
{
    None,
    Object,
    Entity,
};

//! Information of an object's runtime time.
struct ObjectTypeInfo
{
    //! EObjectType value for the type.
    EObjectType type = EObjectType::None;

    //! Class name.
    const char* name = nullptr;

    //! Display name.
    const char* displayName = nullptr;

    void Validate() const
    {
        assert(type != EObjectType::None);
        assert(name);
        assert(displayName);
    }
};

//! A single object in the level file (mission_mission0.xml/Objects).
//! Uses hybrid composition/inheritance approach.
//! Inheritance is used for different object types (entity/not entity).
//! Composition (in the form of Components) is used for object sub-properties
//! (like transform, flowgraphs or volumes).
class Object : NoCopy
{
public:
    Object();
    virtual ~Object();

    //! @returns the object ID.
    SceneObjectId GetObjectId() const { return m_ObjectId; }

    //! @returns the type info.
    const ObjectTypeInfo& GetTypeInfo() const { return *m_pTypeInfo; }

    //! @returns Whether the object is of this type.
    bool IsType(EObjectType type) const { return m_pTypeInfo->type == type; }

    //! @returns Whether this object is an entity.
    bool IsEntity() const { return IsType(EObjectType::Entity); }

    //! @returns the object name.
    const std::string& GetName() const { return m_ObjectName; }
    void SetName(const std::string& name);

    //! @returns whether the object itself is visible (ignoring the parents).
    bool IsSelfVisible() const { return m_IsSelfVisible; }
    void SetSelfVisible(bool state);

    //! @returns the list of all components.
    const ComponentList& GetComponents() { return m_Components; }

    //! @returns the transform component.
    Transform* GetTransform() { return m_pTransform.get(); }

    //! @returns The bounding box component.
    BBoxComponent* GetBBox() { return m_pBBox.get(); }

    //! @returns the parent object.
    Object* GetParent() { return m_pTransform->GetParent() ? m_pTransform->GetParent()->GetObject() : nullptr; }

    //! Creates an instance of component and adds it to the object.
    //! The component MUST be saved into a field as it is not owned by Object.
    //! TODO 2023-07-16: Component removal
    //! @param  args    Constructor arguments.
    //! @tparam T       Component type.
    //! @returns unique_ptr to the component.
    template <typename T, typename ...TArgs>
    std::unique_ptr<T> AddComponent(TArgs&&... args)
    {
        auto pComp = std::make_unique<T>(std::forward<TArgs>(args)...);
        m_Components.Add(pComp.get());
        pComp->AttachToObject(this);
        return pComp;
    }

    //! Initializes the object.
    //! @param  objectNode  Object XML node (may be null).
    virtual void Init(XmlNodeRef objectNode);

    //! Shows the inspector nodes.
    virtual void ShowInspector();

    //! Shows the inspector contents for the object node.
    virtual void ShowInspectorSelf();

    //! Shows the inspector nodes for components.
    virtual void ShowInspectorComponents();

    //! Called when object transform is changed.
    //! @param  nWhyFlags   Mask of EEntityXFormFlags. Informs what has changed.
    virtual void OnTransformChanged(unsigned nWhyFlags);

    //! Called when entering Play Mode.
    virtual void OnEnterPlayMode();

    //! Called when exiting Play Mode.
    virtual void OnExitPlayMode();

    //! Intersects a ray with this object.
    //! @returns Whether the object was hit.
    virtual bool IntersectRay(const ViewportRaycastInfo& ray, RayIntersectInfo& intersect);

    //! Draws the selection outline for this object.
    virtual void DrawSelection(bool isActive);

protected:
    //! Sets the object type.
    //! Call this in the constructor.
    //! @param  typeInfo    Type info instance. Must be a static/global.
    void SetType(const ObjectTypeInfo& typeInfo);

private:
    const ObjectTypeInfo* m_pTypeInfo = nullptr;
    SceneObjectId m_ObjectId = INVALID_SCENE_OBJECT;
    std::string m_ObjectName;
    bool m_IsSelfVisible = true;

    ComponentList m_Components;
    std::unique_ptr<Transform> m_pTransform;
    std::unique_ptr<BBoxComponent> m_pBBox;

    //! Called when the object is instantiated by ObjectManager.
    void InternalInit(SceneObjectId id);

    friend class ObjectManager;
};

//! Smart pointer to an object.
using ObjectPtr = std::unique_ptr<Object>;

} // namespace LevelEditor
