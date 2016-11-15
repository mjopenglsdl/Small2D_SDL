cmake_minimum_required(VERSION 3.0.2)

project(Small2D_SDL)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
  
IF (APPLE OR WIN32)
	set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/deps/include)
	set(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/deps/lib)
ENDIF ()

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(Small2D_SDL ./Core/DisplayManager.cpp
./Core/GameManager.cpp
./Core/GameState.cpp
./Core/IntroState.cpp
./Core/MenuState.cpp
./Core/PlayState.cpp
./UIObject/UIObject.cpp
./UIObject/Entities/Player.cpp
./UIObject/Entities/Wall.cpp
./UIObject/Widgets/Button.cpp
./UIObject/Widgets/Label.cpp
)

target_link_libraries(Small2D_SDL 
${SDL2_LIBRARIES}
${SDL2_ttf_LIBRARIES}
)