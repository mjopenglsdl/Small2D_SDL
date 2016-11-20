cmake_minimum_required(VERSION 3.1.2)

project(Small2D_SDL)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


IF (APPLE OR WIN32)
	set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/deps/include)
	set(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/deps/lib)
ENDIF ()

include_directories(${PROJECT_SOURCE_DIR}/include)


find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)


add_executable(Small2D_SDL 
./src/DisplayManager.cpp
./src/FontManager.cpp
./src/FPSManager.cpp
./src/GameManager.cpp
./src/GameState.cpp
./src/IntroState.cpp
./src/MenuState.cpp
./src/Logger.cpp
./src/PlayState.cpp
./src/UIObject.cpp
./src/Player.cpp
./src/Wall.cpp
./src/Button.cpp
./src/Label.cpp
./src/main.cpp
./src/Texture.cpp
)

target_link_libraries(Small2D_SDL 
${SDL2_LIBRARY}
${SDL2_TTF_LIBRARIES}
${SDL2_IMAGE_LIBRARY}
)
