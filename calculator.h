#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include<iostream>

enum Priority {
    OPEN_BRACKET = 0,
    CLOSED_BRACKET = 0,
    PLUS_OR_MINUS = 1,
    MULT_OR_DIV = 2,
    DEGREE = 3,
    UNARY_MINUS = 4
};

bool isOperator(char symbol);
void getPostfixNotation(const std::string& expression, std::stack<std::string>* postfixNotation);
int getPriorityOperators(char symbol);
void reverseStack(std::stack<std::string> postfixNotation, std::stack<std::string>* reversePostfixNotation);
double calculatePostfixNotation(std::stack<std::string> postfixNotation);
double getExpressionValue(double firstNumber, double secondNumber, std::string operators);
double calculate(const std::string& expr);

#endif