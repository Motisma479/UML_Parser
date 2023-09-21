#pragma once
#include"Utils.hpp"
#include<vector>
#include<filesystem>

enum class Visibility 
{
    NONE,
    PUBLIC,
    PRIVATE,
    PROTECTED
};

struct Element
{
    Visibility visibility;
    const char* name;
    const char* type;
    std::vector<Element>argument;
};

class Class
{
public:
    Class() {}
    ~Class() {}

    std::vector<Element> variables;
    std::vector<Element> functions;

    void CreateVariables() {}
    void CreateFunction() {}
};

struct HFile
{
    const char* name;
    const char* path;
    std::vector<const char*> listOfFolder;
};

class HParser
{
public:
    HParser() {}
    ~HParser() {}

    void AllHeaderFrom(const char* path, std::vector<int> lastLineAt= {}, int recurrence = 0, bool last = false, bool isFinal = false);
};