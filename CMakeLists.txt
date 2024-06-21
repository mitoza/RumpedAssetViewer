cmake_minimum_required(VERSION 3.28)
project(AssetViewer)
if (APPLE) # UNIX
    enable_language(OBJCXX)
endif ()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# SFML Options
IF (WIN32 AND (CMAKE_BUILD_TYPE MATCHES Release))
    option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
ELSE ()
    option(BUILD_SHARED_LIBS "Build shared libraries" ON)
ENDIF ()

# wxWidgets Options
IF (WIN32 AND (CMAKE_BUILD_TYPE MATCHES Release))
    option(wxBUILD_SHARED "Build shared or static libraries" OFF)
    set(wxBUILD_TESTS OFF) # CONSOLE_ONLY, ALL or OFF
    set(wxBUILD_SAMPLES OFF) #	SOME, ALL or OFF
    option(wxBUILD_DEMOS "Build demo applications" OFF)
    option(wxUSE_GUI "Build the UI libraries" ON)
    #option(wxBUILD_COMPATIBILITY "Enable API compatibility with 3.0, 3.2 or neither (\"NONE\")" 3.2)
    set(wxBUILD_COMPATIBILITY 3.1)
    set(wxBUILD_SHARED ON)
    option(wxBUILD_PRECOMP "Use precompiled headers" ON)
    option(wxBUILD_MONOLITHIC "Build a single library" OFF)
ELSE ()
    option(wxBUILD_SHARED "Build shared or static libraries" ON)
    set(wxBUILD_TESTS OFF) # CONSOLE_ONLY, ALL or OFF
    set(wxBUILD_SAMPLES OFF) #	SOME, ALL or OFF
    option(wxBUILD_DEMOS "Build demo applications" OFF)
    option(wxUSE_GUI "Build the UI libraries" ON)
    #option(wxBUILD_COMPATIBILITY "Enable API compatibility with 3.0, 3.2 or neither (\"NONE\")" 3.2)
    set(wxBUILD_COMPATIBILITY 3.1)
    set(wxBUILD_SHARED OFF)
    option(wxBUILD_PRECOMP "Use precompiled headers" ON)
    option(wxBUILD_MONOLITHIC "Build a single library" ON)
ENDIF ()

include(FetchContent)
# SFML https://www.sfml-dev.org/tutorials/2.6/
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
# TGUI https://tgui.eu/tutorials/latest-stable/
FetchContent_Declare(WX_WIDGETS
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_TAG 3.2
)
# EnTT https://github.com/skypjack/entt/wiki
#FetchContent_Declare(EnTT
#        GIT_REPOSITORY https://github.com/skypjack/entt.git
#        GIT_TAG master
#)
FetchContent_MakeAvailable(
        SFML
        WX_WIDGETS
        #        EnTT
)

file(GLOB_RECURSE SRC_FILES
        ./src/*.cpp
        ./src/ui/*.cpp
        ./src/data/*.cpp
        ./src/utils/*.cpp
)

file(GLOB_RECURSE INCLUDE_DIR
        ./include
        ./include/ui
        ./include/data
        ./include/utils
)
message("Build dir: ${CMAKE_CURRENT_BINARY_DIR}/_deps/wx_widgets-build/libs")
#add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/_deps/wx_widgets-build/libs)

IF (WIN32 AND (CMAKE_BUILD_TYPE MATCHES Release))
    add_executable(${CMAKE_PROJECT_NAME} WIN32
            main.cpp
            ${SRC_FILES}
    )
ELSE ()
    add_executable(${CMAKE_PROJECT_NAME}
            main.cpp
            ${SRC_FILES}
    )
ENDIF ()

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        sfml-system
        sfml-graphics
        sfml-window

        wx::net
        wx::core
        wx::base

)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)