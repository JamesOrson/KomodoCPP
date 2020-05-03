#pragma once

#include <memory>

namespace komodo::core::ecs
{
    namespace entities
    {
        class Entity;
    }
    namespace systems
    {
        class BehaviorSystem;
        class Render2DSystem;
    }
}

namespace komodo::core::ecs::components
{
  class Component
  {
    friend komodo::core::ecs::entities::Entity;
    // friend komodo::core::ecs::systems::BehaviorSystem;
    // friend komodo::core::ecs::systems::Render2DSystem;

public:
#pragma region Constructors
    Component(bool isEnabled = true);
#pragma endregion

    virtual ~Component() = 0;

#pragma region Static Members
    static unsigned int nextId;
#pragma endregion

#pragma region Accessors
    unsigned int getId() const;
    bool getIsEnabled() const;
    bool getIsInitialized() const;
    unsigned int getParentId() const;
    std::weak_ptr<komodo::core::ecs::entities::Entity> getParent() const;
    /*TODO: Waiting on Vector3 implementation
    Vector3 getPosition() const;
    Vector3 getRotation() const;
    Vector3 getScale() const;*/
#pragma endregion

#pragma region Mutators
    void setIsEnabled(bool value);
    /*TODO: Waiting on Vector3 implementation
    void setPosition(Vector3 value);
    void setRotation(Vector3 value);
    void setScale(Vector3 value);*/
#pragma endregion

#pragma region Member Methods
    /*TODO: Waiting on Matrix implementation
    Matrix getRotationMatrix() const;*/
    /*TODO: Waiting on Quaternion implementation
    Matrix getRotationQuaternion() const;*/
#pragma endregion
protected:
#pragma region Members
    unsigned int id;
    bool isEnabled;
    bool isInitialized;
    /*TODO: Waiting on Vector3 implementation
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;*/
#pragma endregion

private:
#pragma region Members
    unsigned int parentId;
#pragma endregion
  };
} // namespace komodo::core::ecs::components