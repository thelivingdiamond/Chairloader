#pragma once
#include <Preditor/SceneEditor/Common.h>

namespace LevelEditor
{

class Object;

//! List of level objects.
class ObjectManager : NoCopy
{
public:
    ObjectManager();
    ~ObjectManager();

    //! @returns the list of objects.
    const auto& GetObjects() const { return m_Objects; }

    //! @returns an object by ID or nullptr.
    Object* GetObject(SceneObjectId id);

    //! Creates an object instance.
    //! @tparam T           Object type.
    //! @return the new object.
    template <typename T>
    T* CreateObject()
    {
        size_t idx = m_Objects.size();
        auto& pObj = m_Objects.emplace_back(std::make_unique<T>());
        InitObject(idx, XmlNodeRef());
        return pObj.get();
    }

    //! Creates objects for the level.
    //! @param  objectsNode <Objects> node from mission0.xml
    void CreateLevelObjects(XmlNodeRef objectsNode);

    //! Invokes a method on all objects.
    //! @param  pfnMethod   The method.
    //! @param  args        Method args.
    template <auto func, typename ...TArgs>
    void InvokeOnAll(TArgs&&... args)
    {
        for (std::unique_ptr<Object>& i : m_Objects)
        {
            std::invoke(func, *i, std::forward<TArgs>(args)...);
        }
    }

private:
    std::vector<std::unique_ptr<Object>> m_Objects;

    //! Creates an object instance from level data.
    //! @param  objectNode  Object node from the level.
    //! @return the new object.
    Object* CreateObject(XmlNodeRef objectNode);

    //! Initializes a freshly created object.
    void InitObject(size_t idx, XmlNodeRef objectNode);
};

} // namespace LevelEditor
