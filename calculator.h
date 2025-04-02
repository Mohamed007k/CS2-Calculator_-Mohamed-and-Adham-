#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

using namespace std;

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
long long factorial(int n);
int gcd(int a, int b);
int lcm(int a, int b);
int randomInRange(int min, int max);

double evaluateExpression(const string& expression);

#endif // CALCULATOR_H

