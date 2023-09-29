#include "HeaderRelated/HFile.hpp"

HFile::HFile(std::string _name, std::string _path, std::vector<std::string> _listOfFolder) : name(_name), path(_path), listOfFolder(_listOfFolder)
{

}

void HFile::Parse()
{
    std::FILE* file = std::fopen(path.c_str(),"r");
    if(!file)
    {
        std::cerr << "File opening failed" << std::endl;
        return;
    }
    
}