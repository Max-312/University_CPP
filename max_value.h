#ifndef MAX_VALUE_H
#define MAX_VALUE_H

double applyOperation(double a, double b, char op);
void calculateMaxValueRecursive(double* nums, int n, char* ops, int idx, double currentResult, double& maxResult);
double calculateMaxValue(double* nums, int n);

#endif