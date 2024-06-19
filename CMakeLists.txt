cmake_minimum_required(VERSION 3.28)
project(AssetViewer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
set(TGUI_BACKEND SFML_GRAPHICS)

file(GLOB_RECURSE USER_SOURCES ./src/*.cpp)

include(FetchContent)
# SFML https://www.sfml-dev.org/tutorials/2.6/
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
# TGUI https://tgui.eu/tutorials/latest-stable/
FetchContent_Declare(TGUI
        GIT_REPOSITORY https://github.com/texus/TGUI.git
        GIT_TAG 1.x
)
# EnTT https://github.com/skypjack/entt/wiki
FetchContent_Declare(EnTT
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG master
)
FetchContent_MakeAvailable(SFML TGUI EnTT)


add_executable(AssetViewer main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-graphics
        sfml-window
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)