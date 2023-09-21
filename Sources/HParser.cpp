#include "HParser.hpp"

void HParser::AllHeaderFrom(const char* path, std::vector<int> lastLineAt, int recurrence, bool last, bool isFinal)
{
    if(recurrence == 0) // Draw the origin of execution
    {
        std::cout << "------------------------------------------------------------\n";
        std::cout << EXECUTION_PATH << std::endl;
        std::cout << "------------------------------------------------------------\n";
        std::cout << "    \xe2\x94\x82   \n";// "    │   "
    }

    std::string tab = "";
    if(!isFinal)
        for (int i = 0; i < recurrence; i++)
        {
            auto checkIfBlank = [i,lastLineAt](){for(const auto& check : lastLineAt){ if(check == i){return true;}}return false;};
            if(checkIfBlank())
                tab += "        ";
            else
                tab += "    \xe2\x94\x82   "; // "    │   "
        }
    else
        for (int i = 0; i < recurrence; i++)
        {
            tab += last == true ? "        " : "    \xe2\x94\x82   "; // "    │   "
        }


    std::filesystem::path executionPath = path;
    
    if (std::filesystem::exists(executionPath) && std::filesystem::is_directory(executionPath)) {
        std::filesystem::directory_entry lastEntry;
        for (const auto& entry : std::filesystem::directory_iterator(executionPath)) {
            lastEntry = entry;
        }

        for (const auto& entry : std::filesystem::directory_iterator(executionPath)) {
            if (entry.is_directory()) {
                std::string caseTab = "";
                if (entry == lastEntry)
                    caseTab = "    \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"; // "    └───"
                else
                    caseTab = "    \xe2\x94\x9c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"; // "    ├───"


                std::cout << tab<< caseTab <<"Folder: " << entry.path().filename().string().c_str() << std::endl;
                
                if(entry == lastEntry)
                {
                    lastLineAt.push_back(recurrence);
                    AllHeaderFrom(entry.path().string().c_str(), lastLineAt, recurrence + 1, true, (recurrence == 0));
                }
                else
                    AllHeaderFrom(entry.path().string().c_str(), lastLineAt, recurrence + 1, false);
            }
            else
            {
                std::string caseTab = "";
                if (entry == lastEntry)
                    caseTab = "    \xe2\x94\x94\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"; // "    └───"
                else
                    caseTab = "    \xe2\x94\x9c\xe2\x94\x80\xe2\x94\x80\xe2\x94\x80"; // "    ├───"
                std::cout << tab << caseTab << "File: " << entry.path().filename() << std::endl;
            }
        }
    } else {
        std::cerr << "The specified path is not a valid directory." << std::endl;
    }
}
