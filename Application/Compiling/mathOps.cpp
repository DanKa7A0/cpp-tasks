#include "mathOps.h"
#include "globals.h"

double squareArea(double x) {
    OperationCount++;
    return std::pow(x, 2);
}

double cubeArea(double x) {
    OperationCount++;
    return std::pow(x, 3);
}

double circleArea(double radius) {
    OperationCount++;
    return getPi() * std::pow(radius, 2);
}

double rectangleArea(double a, double b) {
    OperationCount++;
    return a * b;
}

double rightАngledТriangleArea(double a, double b) {
    OperationCount++;
    return (a * b) / 2;
}