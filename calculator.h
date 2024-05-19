#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
#include <sstream>
#include<cmath>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <cctype>

bool isBalanced(const std::string& expr);
int getPrecedence(char op);
bool isOperator(char ch);
bool isUnaryMinus(const std::string& expr, size_t pos);
std::string toRPN(const std::string& expr);
double evaluateRPN(const std::string& rpn);
double calculate(const std::string& expr);

#endif