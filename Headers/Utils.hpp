#pragma once
#include "stdafx.hpp"

#ifdef WINDOWS

#include<Windows.h>
#include<conio.h>

#define EXECUTION_PATH [] () -> const char* {\
    static char buffer[MAX_PATH];\
    DWORD size = GetCurrentDirectoryA(MAX_PATH, buffer);\
    if(size != 0)\
        return static_cast<const char*>(buffer);\
} ()

#define PAUSE [] () -> void {\
    std::cout << "Press any key to continue...";\
    _getch();\
} ()

#elif LINUX

#include<unistd.h>
#include <termios.h>

#define EXECUTION_PATH [] () -> const char* {\
    static char buffer[1024];\
    if (getcwd(buffer, sizeof(buffer)) != nullptr)\
        return static_cast<const char*>(buffer);\
} ()

#define PAUSE [] () -> void {\
    std::cout << "Press any key to continue...";\
    auto getch = [] () -> s32 {\
        struct termios oldt, newt;\
        s32 ch;\
        tcgetattr(STDIN_FILENO, &oldt);\
        newt = oldt;\
        newt.c_lflag &= ~(ICANON | ECHO);\
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);\
        ch = getchar();\
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);\
        std::cout << "\n";\
        return ch;\
    };\
    getch();\
} ()

#endif
