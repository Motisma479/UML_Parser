#include "HeaderRelated/HParser.hpp"
#include "Color.hpp"
#include "Utils.hpp"

void HParser::AllHeadersFrom(const char* path, std::vector<s32> lastLineAt, s32 recurrence)
{
    if(recurrence == 0) // Draw the origin of execution
    {
        std::cout << "------------------------------------------------------------\n";
        std::cout << path << std::endl;
        std::cout << "------------------------------------------------------------\n";
        std::cout << "\xe2\x94\x82   \n";// "    │   "
    }

    std::string tab = "";
    for (s32 i = 0; i < recurrence; i++)
    {
        auto checkIfBlank = [i,lastLineAt](){for(const auto& check : lastLineAt){ if(check == i){return true;}}return false;};
        if(checkIfBlank())
            tab += "    ";
        else
            tab += "\xe2\x94\x82   "; // "    │   "
    }

    std::filesystem::path executionPath = path;
    
    if (std::filesystem::exists(executionPath) && std::filesystem::is_directory(executionPath)) {
        std::filesystem::directory_entry lastEntry;
        for (const auto& entry : std::filesystem::directory_iterator(executionPath, std::filesystem::directory_options::skip_permission_denied))
        {
            lastEntry = entry;
        }
        try
        {
            for (const auto& entry : std::filesystem::directory_iterator(executionPath, std::filesystem::directory_options::skip_permission_denied)) {

                std::string caseTab = "";
                if (entry == lastEntry)
                    caseTab = "\xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"; // "    └───"
                else
                    caseTab = "\xe2\x94\x9c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"; // "    ├───"

                if (entry.is_directory())
                {
                    std::cout << tab << caseTab << SetTerminalColor(entry.path().filename().string().c_str(),{8, 69, 143}) << std::endl;

                    if (entry == lastEntry)
                    {
                        lastLineAt.push_back(recurrence);
                        AllHeadersFrom(entry.path().string().c_str(), lastLineAt, recurrence + 1);
                    }
                    else
                        AllHeadersFrom(entry.path().string().c_str(), lastLineAt, recurrence + 1);
                }
                else
                {
                    Color fileColor = {204, 83, 83};
                    std::string ext = entry.path().extension().string();
                    if(ext == ".h" || ext == ".hpp"|| ext == ".H"|| ext == ".hh"|| ext == ".h++"|| ext == ".hxx")
                    {
                        fileColor = {160, 116, 196};
                        std::vector<std::string> temp;
                        std::filesystem::path launchPath = EXECUTION_PATH;
                        for (const auto& component : entry.path().parent_path().lexically_relative(launchPath)) {
                            temp.push_back(component.string());
                        }
                        files.push_back({entry.path().filename().string(), entry.path().string(), temp});
                    }
                    std::cout << tab << caseTab  << SetTerminalColor(entry.path().filename().string().c_str(), fileColor) << std::endl;
                }
            }
        }
        catch (const std::filesystem::filesystem_error& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    else
        std::cerr << "The specified path is not a valid directory." << std::endl;
}

void HParser::ParseRegisteredHeaders()
{
    for(HFile file : files)
        file.Parse();
}

#if DEBUG
void HParser::PrintRegisteredHeaders()
{
    for(const auto& file : files)
    {
        std::cout << "------------------------------------------------------\n";
        std::cout << file.name << "\n" << file.path << std::endl;
        for(const auto& folder : file.listOfFolder)
        {
            std::cout << "\t" << folder << std::endl;
        }
        std::cout << "------------------------------------------------------\n";
    }
}
#endif