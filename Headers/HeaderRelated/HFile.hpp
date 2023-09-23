#pragma once
#include "HeaderRelated/HClass.hpp"

class HFile
{
public:
    HFile() = delete;
    HFile(std::string _name, std::string _path, std::vector<std::string> _listOfFolder);
    ~HFile() {}

    std::string name;
    std::string path;
    std::vector<std::string> listOfFolder;
};