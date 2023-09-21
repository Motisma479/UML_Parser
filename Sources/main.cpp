#include"Utils.hpp"
#include"HParser.hpp"

int main(int argc, char** argv)
{
#ifdef WINDOWS
    std::system("chcp 65001");
#endif
    HParser parser;

    std::vector<char*> args(argv, argc+argv);
    for(const auto& arg : args)
        std::cout << arg << std::endl;

    std::cout << "Hello World!\n";
    std::cout << "argc : " << argc << std::endl;

    parser.AllHeaderFrom(EXECUTION_PATH);

    //PAUSE;
    return 0;
}