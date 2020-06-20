cmake_minimum_required(VERSION 3.15)
project(GameV0_1)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(GameV0_1 main.cpp Resources/Window.h Resources/SDL/SdlWindow.cpp Resources/SDL/SdlWindow.h Resources/Factory.h Resources/SDL/SdlFactory.cpp Resources/SDL/SdlFactory.h Resources/Game.cpp Resources/Game.h Resources/Input.h Resources/InputHandler.h Resources/SDL/SdlInputHandler.cpp Resources/SDL/SdlInputHandler.h Resources/GameObject.cpp Resources/GameObject.h Resources/Sprite.h Resources/SDL/SdlSprite.cpp Resources/SDL/SdlSprite.h Resources/GameController.cpp Resources/GameController.h Resources/Input.cpp Resources/Alien.cpp Resources/Alien.h Resources/EnemyHorde.cpp Resources/EnemyHorde.h Resources/SDL/SdlText.cpp Resources/SDL/SdlText.h Resources/Text.h Resources/Config.h)
target_link_libraries(GameV0_1 ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)