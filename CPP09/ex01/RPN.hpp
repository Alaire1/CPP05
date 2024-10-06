#pragma once

#include <string>
#include <stack>
#include <vector>
#include <sstream> 
#include <cctype>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define END "\033[0m"

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

    double calculateRPN(const std::string &input);
    std::vector<std::string> tokenize(const std::string &input);
};