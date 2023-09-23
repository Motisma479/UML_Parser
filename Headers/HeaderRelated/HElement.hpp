#pragma once
#include "stdafx.hpp"

enum class Visibility 
{
    NONE,
    PUBLIC,
    PRIVATE,
    PROTECTED
};

struct HElement
{
    Visibility visibility;
    const char* name;
    const char* type;
    std::vector<HElement>argument;
};