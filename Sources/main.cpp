#include"Utils.hpp"

int main(int argc, char** argv)
{
    std::vector<char*> args(argv, argc+argv);
    for(const auto& arg : args)
        std::cout << arg << std::endl;

    std::cout << "Hello World!\n";
    std::cout << "argc : " << argc << std::endl;

    std::cout << "------------------------------------------------------------\n";
    std::cout << EXECUTION_PATH << std::endl;
    std::cout << "------------------------------------------------------------\n";
    system("pause");
    return 0;
}