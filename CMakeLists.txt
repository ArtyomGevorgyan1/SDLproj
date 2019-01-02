cmake_minimum_required(VERSION 3.13)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)



add_executable(untitled1 main.cpp Game.cpp Game.h TextureManager.cpp TextureManager.h GameObject.cpp GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

#pkg_search_module(SLD2 REQUIRED sdl2)
#pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})