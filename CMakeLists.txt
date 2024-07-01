cmake_minimum_required(VERSION 3.28)
project(AssetViewer)
if (APPLE) # Objective-C
    enable_language(OBJCXX)
endif ()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

## wxWidgets Options
set(wxBUILD_TESTS OFF) # CONSOLE_ONLY, ALL or OFF
option(wxUSE_GUI "Build the UI libraries" ON)
set(wxBUILD_COMPATIBILITY 3.1)
option(wxBUILD_PRECOMP "Use precompiled headers" ON)
option(wxBUILD_MONOLITHIC "Build a single library" OFF)
IF (CMAKE_BUILD_TYPE MATCHES Release)
    set(wxBUILD_SAMPLES OFF) #	SOME, ALL or OFF
    option(wxBUILD_DEMOS "Build demo applications" OFF)
    set(wxBUILD_SHARED OFF)
ELSE ()
    IF (WIN32)
        set(wxBUILD_SAMPLES ALL) #	SOME, ALL or OFF
        option(wxBUILD_DEMOS "Build demo applications" ON)
        set(wxBUILD_SHARED OFF)
    ELSE ()
        set(wxBUILD_SAMPLES OFF) #	SOME, ALL or OFF
        option(wxBUILD_DEMOS "Build demo applications" OFF)
        set(wxBUILD_SHARED ON)
    ENDIF ()
ENDIF ()

## Git Fetch Content
include(FetchContent)

# wxWidgets https://docs.wxwidgets.org/latest/
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
        WX_WIDGETS
        #        EnTT
)

## Source files directories
file(GLOB_RECURSE SRC_FILES
        ./src/*.cpp
        ./src/ui/*.cpp
        ./src/data/*.cpp
        ./src/utils/*.cpp
        ./src/ui/samples/*.cpp
        ./src/ui/controls/*.cpp

)
## Header files directory
file(GLOB_RECURSE INCLUDE_DIR
        ./include
        ./include/ui
        ./include/data
        ./include/utils
        ./include/ui/samples
        ./include/ui/controls

)

message(STATUS "Build wsWidgets subdirectory: ${CMAKE_CURRENT_BINARY_DIR}/_deps/wx_widgets-subbuild")
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/_deps/wx_widgets-subbuild)

IF (WIN32)
    IF (CMAKE_BUILD_TYPE MATCHES Release)
        add_executable(${CMAKE_PROJECT_NAME} WIN32 main.cpp ${SRC_FILES})
    ELSE ()
        add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SRC_FILES})
    ENDIF ()
ELSE ()
    if (APPLE)
        add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SRC_FILES})

        set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES MACOSX_BUNDLE_INFO_LIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
    ELSE ()
        add_executable(${CMAKE_PROJECT_NAME} main.cpp ${SRC_FILES})
    ENDIF ()
ENDIF ()

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
#if(UNIX AND NOT APPLE)
#    target_link_libraries(vsgwxviewer vsgwx ${wxWidgets_LIBRARIES} ${GTK3_LIBRARIES})
#else()
#    target_link_libraries(vsgwxviewer vsgwx ${wxWidgets_LIBRARIES})
#endif()
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE

        wx::core
        wx::base
        wx::aui
        wx::xrc
        wx::xml
        wx::webview
        wx::stc
        wx::richtext
        wx::ribbon
        wx::qa
        wx::propgrid
        wx::media
        wx::html
        wx::gl
        wx::net

)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)