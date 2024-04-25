#include <limits>
#include <iostream>
#include <string>
#include <fstream>
#include "bigint.hpp"
#include "Language.cpp"
#include "BasicCalculations.cpp"
#include "math.cpp"

BigInt FirstNumber(char Language, char Stage) {
    for (;;) { //error handling for first number
        Stage = '1';
        BigInt x;
        Translation(Language, Stage); // Please enter the number(s) you want to have calculated
        std::cin >> x;
        if (std::cin.fail()) {
            Stage = '4'; // "Sorry, that's an invalid number, please use a rational number"
            Translation(Language, Stage);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (std::cin.good()) {
            return x;
        }   
        else {
            std::cout << "Unexpected writing condition!" << std::endl;
            FirstNumber(Language, Stage);
        }
    }
}

char Operator(std::string &LongWord, char Language, char Stage) {
    Stage = '2';
    Translation(Language, Stage); // What math operation would you like to use
    std::cout << "(+) Addition\n(-) Subtraction\n(*) Multiplication\n(/) Division\n(s) Squareroot\n(^) Exponent\n(c) Cuberoot\n(r) nth root" << std::endl;
    std::cin >> LongWord;
    char math = LongWord[0]; //only takes first letter of what the user types to prevents errors
    switch (math) {
    case '+':
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
        break;
    case 's': //Square root
        break;
    case '^':
        break;
    case 'c': //cube root
        break;
    case 'r': //nth root
        break;
    default:
        Stage = '5'; // This operation is not recognized, please use standard arithmetic math or square roots/exponents
        Translation(Language, Stage);
        Operator(LongWord, Language, Stage);
    }
    return math;
}

BigInt SecondNumber (char Language, char Stage) {
    for (;;) { //error handling for second number
        Stage = '3';
        Translation(Language, Stage);
        int y;
        std::cin >> y;
        if (std::cin.fail()) { //if it fails
            Stage = '4';
            Translation(Language, Stage);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (std::cin.good()){
            return y;
        }
        else {
            std::cout << "Unexpected writing condition!" << std::endl;
            SecondNumber(Language, Stage);
        }

    }
}

void loop(char &Language) {
    while (true) {
        char Stage, math;
        BigInt x, y;
        std::string LongWord;
        x = FirstNumber(Language, Stage);
        math = Operator(LongWord, Language, Stage);
        y = SecondNumber(Language, Stage);
        calculation (math, x, y);
    }
}

int main() {
    char Mode, Language;
    std::cout << "Enter (0) for Algebra\nEnter (1) for Radical Number Calculations" << std::endl;
    std::cin >> Mode;
    switch (Mode) {
        case '0':
            Language = CheckLanguage(Language);
            loop(Language);
        case '1':
            Radical();
        default:
            std::cout << "Wrong inputted number" << std::endl;
            main();
    }
    return 0;
}