#pragma once
#include "HeaderRelated/HFile.hpp"

class HParser
{
public:
    HParser() {}
    ~HParser() {}

    std::vector<HFile> files;

    void AllHeadersFrom(const char* path, std::vector<s32> lastLineAt= {}, s32 recurrence = 0);
    void ParseRegisteredHeaders();

#if DEBUG
    void PrintRegisteredHeaders();
#endif
};