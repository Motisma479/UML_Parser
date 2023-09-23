#pragma onces
#include "HeaderRelated/HElement.hpp"

class HClass
{
public:
    HClass() {}
    ~HClass() {}

    std::vector<HElement> variables;
    std::vector<HElement> functions;

    void CreateVariables() {}
    void CreateFunction() {}
};