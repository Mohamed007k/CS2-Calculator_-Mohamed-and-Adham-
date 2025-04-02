#include <iostream>
#include "calculator.h"

int main() {
    std::cout << "Addition: " << add(5, 3) << std::endl;
    std::cout << "Subtraction: " << subtract(10, 4) << std::endl;
    std::cout << "Multiplication: " << multiply(6, 7) << std::endl;
    std::cout << "Division: " << divide(20, 5) << std::endl;
    std::cout << "Factorial: " << factorial(5) << std::endl;
    std::cout << "GCD: " << gcd(24, 36) << std::endl;
    std::cout << "LCM: " << lcm(12, 18) << std::endl;
    std::cout << "Random: " << randomInRange(1, 10) << std::endl;
    return 0;
}

