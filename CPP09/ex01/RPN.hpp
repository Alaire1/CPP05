#pragma once

#include <string>
#include <stack>
#include <vector>
#include <sstream> 
#include <cctype>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class RPN {
private:
    std::stack<double> _stack;

    void processToken(const std::string &token);
    void performOperation(const std::string &operation);

public:
    RPN();
    ~RPN();
    RPN(const RPN &rpn);
    RPN &operator=(const RPN &rpn);

    double evaluateRPN(const std::string &input);
    std::vector<std::string> tokenize(const std::string &input); // Corrected declaration
};