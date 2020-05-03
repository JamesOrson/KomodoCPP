#pragma once

#include <komodo/core/ecs/systems/behavior_system.h>
#include <komodo/core/ecs/systems/render_2d_system.h>

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <spdlog/spdlog.h>
#include <string>

namespace komodo::core
{
  class Game
  {
public:
#pragma region Constructors
    Game();
#pragma endregion

    ~Game();

#pragma region Accessors
    komodo::core::ecs::systems::BehaviorSystem&
    getBehaviorSystem();
    // weak_ptr<CameraSystem> getCameraSystem() const;
    // weak_ptr<Shader> getDefaultSpriteShader() const;
    float getFramesPerSecond() const;
    // weak_ptr<GraphicsManager> getGraphicsManager() const;
    bool getIsActive() const;
    // vector<PhysicsSystem> getPhysicsSystem() const;
    // vector<Render2DSystem> getRender2DSystem() const;
    // vector<Render3DSystem> getRender3DSystem() const;
    std::string getScreenDeviceName() const;
    // weak_ptr<SoundSystem> getSoundSystem() const;
    std::string getTitle() const;
    sf::RenderWindow& getWindow() const;
#pragma endregion

#pragma region Mutators
    // void setDefaultSpriteShader(Shader value);
    void setTitle(std::string value);
#pragma endregion

#pragma region Member Methods

    // std::shared_ptr<PhysicsSystem> createPhysicsSystem();
    // std::shared_ptr<Render2DSystem> createRender2DSystem();
    // std::shared_ptr<Render3DSystem> createRender3DSystem();

    std::shared_ptr<komodo::core::ecs::systems::Render2DSystem>
    createRender2DSystem();
    void draw(float dt, sf::Color clearColor = sf::Color(0u, 100u, 100u));
    void exit();
    void initialize();
    void run();
    void update(float dt);

#pragma region Event handlers
    // int addExitingEvent(const std::shared_ptr<function<bool(ExitEventArgs
    // args)>> handler); int addFocusGainedEvent(const
    // std::shared_ptr<function<bool(FoxusGainedArgs args)>> handler); int
    // addFocusLostEvent(const std::shared_ptr<function<bool(FocusLostArgs
    // args)>> handler); int addKeyDownEvent(const
    // std::shared_ptr<function<bool(KeyDownEventArgs args)>> handler); int
    // addScreenDeviceNameChangedEvent(const
    // std::shared_ptr<function<bool(KeyUpArgs args)>> handler); int
    // addTextInputEvent(const std::shared_ptr<function<bool(TextInputEventArgs
    // args)>> handler); int addWindowSizeChangedEvent(const
    // std::shared_ptr<function<bool(WindowSizeChangedEventArgs args)>>
    // handler); bool removeExitingEvent(const int handlerId); bool
    // removeFocusGainedEvent(const int handlerId); bool
    // removeFocusLostEvent(const int handlerId); bool removeKeyDownEvent(const
    // int handlerId); bool removeScreenDeviceNameChangedEvent(const int
    // handlerId); bool removeTextInputEvent(const int handlerId); bool
    // removeWindowSizeChangedEvent(const int handlerId);
#pragma endregion

#pragma endregion

#pragma region Static Member Methods
    static Game &getInstance();
#pragma endregion

private:
#pragma region Members
    std::unique_ptr<komodo::core::ecs::systems::BehaviorSystem> behaviorSystem;
    // CameraSystem cameraSystem;
    std::unique_ptr<sf::Clock> clock;
    // Shader defaultSpriteShader;
    float framesPerSecond = 0.0;
    // GraphicsManager graphicsManager;
    bool isActive = true;
    // vector<PhysicsSystem> physicsSystems;
    std::vector<std::shared_ptr<komodo::core::ecs::systems::Render2DSystem>>
      render2DSystems;
    // vector<Render2DSystem> render2DSystems;
    std::string screenDeviceName;
    bool shouldClose = false;
    // SoundSystem soundSystem;
    std::string title;
    std::unique_ptr<sf::RenderWindow> window;
#pragma endregion

#pragma region Static Members
    static std::once_flag onceFlag;
    static Game* instance;
#pragma endregion
  };
} // namespace komodo::core