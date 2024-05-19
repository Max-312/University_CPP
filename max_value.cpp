#include <limits>
#include "max_value.h"

// Применение операции к двум числам
double applyOperation(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : std::numeric_limits<double>::lowest(); // Избегаем деления на ноль
    default: return 0;
    }
}

// Рекурсивная функция для перебора всех возможных комбинаций операций
void calculateMaxValueRecursive(double* nums, int n, char* ops, int idx, double currentResult, double& maxResult) {
    if (idx == n - 1) {
        if (currentResult > maxResult) {
            maxResult = currentResult;
        }
        return;
    }

    char operations[] = { '+', '-', '*', '/' };
    for (char op : operations) {
        double newResult = applyOperation(currentResult, nums[idx + 1], op);
        calculateMaxValueRecursive(nums, n, ops, idx + 1, newResult, maxResult);
    }
}

// Основная функция для вычисления максимального значения
double calculateMaxValue(double* nums, int n) {
    if (n == 1) return nums[0];

    char* ops = new char[n - 1];
    double maxResult = std::numeric_limits<double>::lowest();
    calculateMaxValueRecursive(nums, n, ops, 0, nums[0], maxResult);
    delete[] ops;

    return maxResult;
}