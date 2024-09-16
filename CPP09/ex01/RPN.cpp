#include "RPN.hpp"


RPN::RPN() {
}


RPN::~RPN() {
}

RPN::RPN(const RPN &rpn) {
    _stack = rpn._stack;
}

RPN &RPN::operator=(const RPN &rpn) {
    if (this != &rpn) {
        _stack = rpn._stack;
    }
    return *this;
}

std::vector<std::string> RPN::tokenize(const std::string &input) {
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void RPN::processToken(const std::string &token) {
    if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
        std::istringstream iss(token);
        double num;
        iss >> num;
        _stack.push(num);
    } else if (token == "+" || token == "-" || token == "*" || token == "/") {
        performOperation(token);
    } else {
        throw std::runtime_error("Invalid token in RPN expression");
    }
}

void RPN::performOperation(const std::string &operation) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Invalid RPN expression");
    }
    double b = _stack.top(); _stack.pop();
    double a = _stack.top(); _stack.pop();
    if (operation == "+") {
        _stack.push(a + b);
    } else if (operation == "-") {
        _stack.push(a - b);
    } else if (operation == "*") {
        _stack.push(a * b);
    } else if (operation == "/") {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        _stack.push(a / b);
    }
}

double RPN::evaluateRPN(const std::string &input) {
    std::vector<std::string> tokens = tokenize(input);

    for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
         processToken(*it);
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid RPN expression");

    return _stack.top();
}