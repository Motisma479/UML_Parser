#CMakeLists.txt

cmake_minimum_required(VERSION 3.8)
project(UML_Parser)
set (CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG=1)
else()
    add_compile_definitions(DEBUG=0)
endif()

if (WIN32)
    add_compile_definitions(WINDOWS)
elseif (APPLE)
    add_compile_definitions(MACOS)
else()
    add_compile_definitions(LINUX)
endif()

set(SOURCES

"Sources/main.cpp"
"Sources/stdafx.cpp"
"Sources/Color.cpp"
"Sources/HeaderRelated/HParser.cpp"
"Sources/HeaderRelated/HFile.cpp"
"Sources/HeaderRelated/HClass.cpp"

)

include_directories ("Headers")

add_executable (${PROJECT_NAME} ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE "Headers/stdafx.hpp")