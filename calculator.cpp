#include "calculator.h"

#include "Header.h"
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include<iostream>
using namespace std;
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isUnary(char c, size_t pos, const std::string& expr) {
    if (c == '-' && (pos == 0 || isOperator(expr[pos - 1]) || expr[pos - 1] == '('))
        return true;
    if (c == '-' && pos > 0 && std::isspace(expr[pos - 1])) {
        size_t prev = pos - 1;
        while (prev > 0 && std::isspace(expr[prev - 1])) {
            --prev;
        }
        if (prev == 0 || expr[prev - 1] == '(' || isOperator(expr[prev - 1]))
            return true;
    }
    return false;
}

int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return std::pow(a, b);
    default:
        return 0;
    }
}

double calculate(const std::string& expr) {
    std::stack<double> values;
    std::stack<char> operators;

    bool lastWasOperator = true;

    for (size_t i = 0; i < expr.length(); ++i) {
        if (expr[i] == ' ') {
            continue;
        }
        else if (std::isdigit(expr[i]) || (expr[i] == '-' && lastWasOperator)) {
            if (expr[i] == '-') {
                if (expr[i] == '-') {
                    size_t j = i + 1;
                    while (j < expr.length() && (std::isdigit(expr[j]) || expr[j] == '.')) {
                        ++j;
                    }
                    values.push(-1 * std::stod(expr.substr(i + 1, j - i - 1)));
                    i = j - 1;
                    lastWasOperator = false;
                }

            }
            else {
                double num = std::stod(expr.substr(i));
                while (i < expr.length() && (std::isdigit(expr[i]) || expr[i] == '.')) {
                    ++i;
                }
                --i;
                values.push(num);
                lastWasOperator = false;
            }
        }
        else if (expr[i] == '(') {
            operators.push(expr[i]);
            lastWasOperator = true;
        }
        else if (expr[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();
            lastWasOperator = false;
        }
        else if (isOperator(expr[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i])) {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(expr[i]);
            lastWasOperator = true;
        }
    }

    while (!operators.empty()) {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

bool isValidExpression(const std::string& expr) {
    int balance = 0;
    bool lastWasOperator = true;

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];

        if (c == '(') {
            ++balance;
            lastWasOperator = true;
        }
        else if (c == ')') {
            --balance;
            lastWasOperator = false;
        }
        else if (isOperator(c)) {
            if (lastWasOperator && c != '-')
                return false;
            lastWasOperator = true;
        }
        else if (std::isdigit(c) || c == '.' || c == ' ') {
            lastWasOperator = false;
        }
        else {

            if (c == '-' && (i == 0 || expr[i - 1] == '('))
                continue;
            if (c == '-' && i > 0 && std::isspace(expr[i - 1]))
                continue;
            return false;
        }
    }

    return balance == 0 && !lastWasOperator;
}
