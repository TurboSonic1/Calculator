#include <limits>
#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_complex.hpp>
#include <boost/math/special_functions/gamma.hpp>
    boost::multiprecision::cpp_bin_float_oct x = 0;
    boost::multiprecision::cpp_bin_float_oct y = 0;
// yes I'm using global variables, I'll fix it later, just too lazy rn

void calculation(char &math, double a, double b) {
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
        std::cout << x << " / " << y << " = " << x / y << std::endl;
	    std::cout << "" << std::endl;
	        break;
	case 's':
	    std::cout << x << "√(" << y << ")" << " = " << x * sqrt(y);
	    std::cout << "" << std::endl;
	        break;
// all of these operations below just don't work without being converted to double long (???)
    case '^': 
        std::cout << a << "^" << b << "=" << std::pow(a, b) << std::endl;
        std::cout << "" << std::endl;
            break;
    case 'c':
        std::cout << a << " 3^√(" << b << ")" << " = " << a * std::cbrt(b);
        std::cout << "" << std::endl;
        break;
    case 'r':
       std::cout << a << "^√(" << b << ")" << " = " << pow(b, 1/a);
       std::cout << "" << std::endl;
        break;
    default: 
        std::cout << "you shouldn't see this error, if you do you should make a detailed bug report, thanks!";
            break;
    }
}

void startcalculation(std::string &longword){
for (;;) { //error handling for first number
	std::cout << "Please enter the number(s) you want to have calculated" << std::flush << std::endl;
	std::cin >> x;
	if (std::cin.fail()) { //if it fails
            std::cerr << "Sorry, that's an invalid number, please use a rational number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    else if (std::cin.good());
        break; //verified to be good and continues
}
std::cout << "What math operation would you like to use" << std::endl;
    restart:
    std::cin >> longword;
    char math = longword[0]; //only takes first letter of what the user types to prevents errors
        switch (math) {
            case '+':
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            case 's': //todo: make this more clear to user that its square root
                break;
            case '^':
                break;
            case 'c': //cube root
                break;
            case 'r': //nth root
                break;
            default:
                std::cout << "This operation is not recognized please use standard arithmetic math or squareroots/exponents" << std::endl;
                goto restart;
                break; (longword);
        }
for (;;) { //error handling for second number
	std::cout << "Please enter the second number(s) you want to have calculated" << std::flush << std::endl; //flush is needed to verify that its cleared
	std::cin >> y;
	if (std::cin.fail()) { //if it fails
            std::cerr << "Sorry, that's an invalid number, please use a rational number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    else if (std::cin.good());
        double a = (double) x * 1;
        double b = (double) y * 1;
        calculation (math, a, b);
        break; //verified to be good and continues
}
}

void clearvalues(std::string &longword) // for looping it and making sure all values are cleared
{
    startcalculation(longword);
    clearvalues(longword);
}

int main()
{
using namespace boost::multiprecision;
std::cout << "This is a test of my c++ coding ability" << std::endl;
	std::string longword;
	longword.clear();
    startcalculation(longword);
    clearvalues(longword);
    return 0;
}