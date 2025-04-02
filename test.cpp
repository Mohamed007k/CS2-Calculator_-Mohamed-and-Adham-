#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    cout << "Addition: " << add(5, 3) << std::endl;
    cout << "Subtraction: " << subtract(10, 4) << std::endl;
    cout << "Multiplication: " << multiply(6, 7) << std::endl;
    cout << "Division: " << divide(20, 5) << std::endl;
    cout << "Factorial: " << factorial(5) << std::endl;
    cout << "GCD: " << gcd(24, 36) << std::endl;
    cout << "LCM: " << lcm(12, 18) << std::endl;
    cout << "Random: " << randomInRange(1, 10) << std::endl;
    return 0;
}

