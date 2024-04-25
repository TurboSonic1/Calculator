#include <iostream>
#include <cmath>
#include "BigInt.hpp"

void calculation(char &math, BigInt x, BigInt y) {
    double long a, b;
    a = x.to_long_long();
    b = y.to_long_long();
    switch (math) { //Actual Calculations
        case '+':
            std::cout << x << " + " << y << " = " << x + y << std::endl;
            std::cout << "" << std::endl;
            break;
        case '-':
            std::cout << x << " - " << y << " = " << x - y << std::endl;
            std::cout << "" << std::endl;
            break;
        case '*':
            std::cout << x << " * " << y << " = " << x * y << std::endl;
            std::cout << "" << std::endl;
            break;
        case '/':
            if (y == 0) {
                std::cout << "Can't divide by 0!" << std::endl;
                break;
            }
            else {
                std::cout << x << " / " << y << " = " << x / y << std::endl;
                std::cout << "" << std::endl;
                break;
            }
        case 's':
            std::cout << x << "√(" << y << ")" << " = " << x * sqrt(y);
            std::cout << "" << std::endl;
            break;
            // all of these operations below just don't work without being converted to double long (???) bigint should support it...
        case '^':
            std::cout << a << "^" << b << "=" << std::pow(a, b) << std::endl;
            std::cout << "" << std::endl;
            break;
        case 'c':
            std::cout << a << " 3^√(" << b << ")" << " = " << a * std::cbrt(b);
            std::cout << "" << std::endl;
            break;
        case 'r':
            std::cout << a << "^√(" << b << ")" << " = " << std::pow(b, 1 / a);
            std::cout << "" << std::endl;
            break;
        default:
            std::cout << "you shouldn't see this error, if you do you should make a detailed bug report, thanks!";
            break;
    }
}