#CMakeLists.txt

cmake_minimum_required(VERSION 3.8)
project(UML_Parcer)
set (CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG=1)
else()
    add_compile_definitions(DEBUG=0)
endif()

add_compile_definitions(WINDOWS=0)
add_compile_definitions(MACOS=1)
add_compile_definitions(LINUX=2)

if (WIN32)
    add_compile_definitions(PLATFORM=0)
elseif (APPLE)
    add_compile_definitions(PLATFORM=1)
else()
    add_compile_definitions(PLATFORM=2)
endif()

set(SOURCES

"Sources/main.cpp"
)

include_directories ("Headers")

add_executable (${PROJECT_NAME} ${SOURCES})