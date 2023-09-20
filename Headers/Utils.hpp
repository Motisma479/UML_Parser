#pragma once

#include<iostream>
#include<vector>

#if PLATFORM == WINDOWS

#include<Windows.h>
#define EXECUTION_PATH [] () -> const char* {\
    static char buffer[MAX_PATH];\
    DWORD size = GetCurrentDirectoryA(MAX_PATH, buffer);\
    if(size != 0)\
        return static_cast<const char*>(buffer);\
} ()

#elif PLATFORM == LINUX

#include<unistd.h>
#define EXECUTION_PATH [] () -> const char* {\
    static char buffer[1024];\
    if (getcwd(buffer, sizeof(buffer)) != nullptr)\
        return static_cast<const char*>(buffer);\
} ()

#endif
