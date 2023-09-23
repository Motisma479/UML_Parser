#pragma onces
#include "HeaderRelated/HElement.hpp"

class HClass
{
public:
    HClass() = delete;
    HClass(std::string _name);
    ~HClass() {}

    std::string name;

    std::vector<HElement> variables;
    std::vector<HElement> consDesTructor;
    std::vector<HElement> functions;

    std::vector<std::string> aggregation;
    std::vector<std::string> composition;
    std::vector<std::string> inheritance;

    void CreateVariables();
    void CreateConsDesTructor();
    void CreateFunction();
};