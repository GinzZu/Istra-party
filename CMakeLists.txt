cmake_minimum_required(VERSION 3.5)
project(Game2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Plane.cpp
        Bullet.cpp Bullet.hpp
        Game.cpp Game.hpp
        Entity.cpp Entity.hpp
        Boom.cpp Boom.hpp
        Menu.cpp
        )
add_executable(Game2 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game2 ${SFML_LIBRARIES})
endif()