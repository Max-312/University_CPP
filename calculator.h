#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include<iostream>

bool isOperator(char ch);
bool isUnary(char c, size_t pos, const std::string& expr);
int precedence(char op);
double applyOperation(double a, double b, char op);
bool isValidExpression(const std::string& expr);
double calculate(const std::string& expr);

#endif