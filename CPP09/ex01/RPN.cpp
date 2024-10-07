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

std::list<std::string> RPN::tokenize(const std::string &input) {
    std::list<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
} 
bool isValidNegativeNum(const std::string &token) {
    if (token.size() > 1 && token[0] == '-') {
        for (size_t i = 1; i < token.size(); i++) {
            if (!std::isdigit(token[i])) {
                throw std::runtime_error(RED "Invalid number: " END + token);
            }
        }
        return true;
    }
    return false;
}

void RPN::processToken(const std::string &token) {
    if (std::isdigit(token[0]) || (isValidNegativeNum(token))) {
        std::istringstream iss(token);
        double num;
        iss >> num;
        _stack.push(num);
    } else if (token == "+" || token == "-" || token == "*" || token == "/") {
        performOperation(token);
    } else {
        throw std::runtime_error(RED "Invalid token in RPN expression" END);
    }
}

void RPN::performOperation(const std::string &operation) {
    if (_stack.size() < 2) {
        throw std::runtime_error(RED "Invalid RPN expression" END);
    }
    double b = _stack.top();
    _stack.pop();
    double a = _stack.top();
     _stack.pop();
    if (operation == "+") {
        _stack.push(a + b);
    } else if (operation == "-") {
        _stack.push(a - b);
    } else if (operation == "*") {
        _stack.push(a * b);
    } else if (operation == "/") {
        if (b == 0 || a == 0) {
            throw std::runtime_error( RED "Division by zero" END);
        }
        _stack.push(a / b);
    }
}
double RPN::calculateRPN(const std::string &input) {
    std::list<std::string> tokens = tokenize(input);
    if (tokens.size() == 1) {
        std::string token = tokens.front();
        if (std::isdigit(token[0]) || isValidNegativeNum(token)) {
            throw std::runtime_error(RED "Invalid RPN expression: Only a single number given" END);
        }
    }
    for (std::list<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
        processToken(*it);
    }
    if (_stack.size() != 1) {
        throw std::runtime_error(RED "Invalid RPN expression" END);
    }

    return _stack.top();
}
// double RPN::calculateRPN(const std::string &input) {
//     std::list<std::string> tokens = tokenize(input);
//     for (std::list<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
//         processToken(*it);
//     }
//     if (_stack.size() != 1)
//         throw std::runtime_error(RED "Invalid RPN expression" END);
//     return _stack.top();
// }