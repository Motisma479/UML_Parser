#include"Utils.hpp"
#include"HeaderRelated/HParser.hpp"

s32 main(s32 argc, char** argv)
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

    parser.AllHeadersFrom(EXECUTION_PATH);
    parser.ParseRegisteredHeaders();

#if DEBUG
    parser.PrintRegisteredHeaders();
#endif

    //PAUSE;
    return 0;
}