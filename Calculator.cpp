#include <limits>
#include <iostream>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_complex.hpp>
#include <boost/math/special_functions/gamma.hpp>

boost::multiprecision::cpp_bin_float_oct x = 0;
boost::multiprecision::cpp_bin_float_oct y = 0;
// yes I'm using global variables, I'll fix it later, just too lazy rn
char shortstage = '0';

void Checklanguage(char Language, int Initiallanguage) {
//    std::string checklanguage;
//    std::ifstream configuration; configuration.open("cfg");
    char Shortlanguage = '0';
//    if (configuration.is_open()) {
//        while (configuration) { // always check whether the file is open
//            configuration >> checklanguage; // pipe file's content into stream
//            std::cout << checklanguage << std::endl; // pipe stream's content to standard output
//            Shortlanguage = checklanguage[0]; // I like reusing code
//        }
//    }
    bool HasLanguage = 0;
    switch (Shortlanguage) {
    case 'E':
        HasLanguage = 1;
        Language = 0;
        break;
    case 'D':
        HasLanguage = 1;
        Language = 1;
        break;
    case '0':
        HasLanguage = 0;
        break;
    default:
        HasLanguage = 0;
        break;
    }

    if (HasLanguage == 0) {
        std::cout << "Please type the number for your language" << std::endl;
        std::cout << "(0) English" << std::endl;
        std::cout << "(1) Deutsch" << std::endl;
        std::string AfterInitialLanguage;
        std::cin >> AfterInitialLanguage;
        Shortlanguage = AfterInitialLanguage[0];
        switch (Shortlanguage) {
        case '0':
            Language = '0';
            break;
        case '1':
            Language = '1';
            break;

        }
    }
}

/* Shortstage numbers meanings:
0 = Initilized
1 = Starting problem
2 = Asking for Operation
3 = Asking for Second number
4 = Invalid Number
5 = Invalid Operation
*/

void English(char shortstage) {
    char line = '0';
    switch (shortstage) {
    case '0':
        std::cout << "Error missing line, Please fill out a detailed bug report" << std::endl;
        break;
    case '1':
        line = '1';
        break;
    case '2':
        line = '2';
        break;
    case '3':
        line = '3';
        break;
    case '4':
        line = '4';
        break;
    case '5':
        line = '5';
        break;
    default:
        std::cout << "Error Line not assigned, Please fill out a detailed bug report" << std::endl;
        break;
    }
    switch (line) {
    case '0':
        std::cout << "Error Line not assigned, Please fill out a detailed bug report" << std::endl;
        break;
    case '1':
        std::cout << "Please enter the number(s) you want to have calculated" << std::endl;
        break;
    case '2':
        std::cout << "What math operation would you like to use" << std::endl;
        break;
    case '3':
        std::cout << "Please enter the second number(s) you want to have calculated" << std::endl;
        break;
    case '4':
        std::cout << "Sorry, that's an invalid number, please use a rational number" << std::endl;
        break;
    case '5':
        std::cout << "This operation is not recognized, please use standard arithmetic math or square roots/exponents" << std::endl;
        break;
    default:
        std::cout << "Error Line not assigned, Please fill out a detailed bug report" << std::endl;
    }
}

    void Deutsch(char shortstage) {
        char line = '0';
        switch (shortstage) {
        case '0':
            std::cout << "Error missing line" << std::endl;
            break;
        case '1':
            line = '1';
            break;
        case '2':
            line = '2';
            break;
        case '3':
            line = '3';
            break;
        case '4':
            line = '4';
            break;
        case '5':
            line = '5';
            break;
        default:
            std::cout << "Error Line not assigned" << std::endl;
            break;
        }
        switch (line) {
        case '0':
            std::cout << "Error Line not assigned, Please fill out a detailed bug report" << std::endl;
            break;
        case '1':
            std::cout << "Bitte geben Sie die erste Zahl, mit welcher gerechnet werden soll, ein" << std::endl;
            break;
        case '2':
            std::cout << "Welche Rechenoperation möchten Sie verwenden" << std::endl;
            break;
        case '3':
            std::cout << "Bitte gib die zweite Zahl, mit welcher gerechnet werden soll, ein" << std::endl;
            break;
        case '4':
            std::cout << "Enschuldigung, dies ist eine ungültige Zahl, bitte nutze eine rationale Zahl" << std::endl;
            break;
        case '5':
            std::cout << "Diese Rechenoperation ist nicht verfügbar, bitte nutzen Sie Arithmetik, oder die Quadratwurzel beziehungsweiße Exponenten" << std::endl;
            break;
        default:
            std::cout << "Error Line not assigned" << std::endl;
        }
    }

    void Translation(char Language, char shortstage) {
//    std::string linereading;
//    std::ifstream configuration; configuration.open("cfg");
//    if (configuration.is_open()) {
        switch (Language) { // Selects which language the user is currently in
        case '0':
            English(shortstage);
            break;
        case '1':
            Deutsch(shortstage);
            break;
        default:
            std::cout << "Error missing Language" << std::endl;
            break;
        }

    }
//}

void calculation(char& math, double a, double b) {
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
        std::cout << a << "^√(" << b << ")" << " = " << pow(b, 1 / a);
        std::cout << "" << std::endl;
        break;
    default:
        std::cout << "you shouldn't see this error, if you do you should make a detailed bug report, thanks!";
        break;
    }
}

void startcalculation(std::string& longword, char Language, char shortstage) {
    for (;;) { //error handling for first number
        shortstage = '1';
//        std::cout << "Please enter the number(s) you want to have calculated" << std::flush << std::endl;
        Translation(Language, shortstage);
        std::cin >> x;
        if (std::cin.fail()) { //if it fails
            shortstage = '4';
            Translation(Language, shortstage);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (std::cin.good());
        break; //verified to be good and continues
    }
    shortstage = '2';
    Translation(Language, shortstage);
}
void continuecalculation(std::string longword, char Language, char shortstage) {
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
        shortstage = '5';
        Translation(Language, shortstage);
        continuecalculation(longword, Language, shortstage);
    }
    for (;;) { //error handling for second number
        shortstage = '3';
        Translation(Language, shortstage);
        std::cin >> y;
        if (std::cin.fail()) { //if it fails
            shortstage = '4';
            Translation(Language, shortstage);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (std::cin.good());
        double a = (double)x * 1;
        double b = (double)y * 1;
        calculation(math, a, b);
        break; //verified to be good and continues
    }
}

void clearvalues(std::string& longword, char Language, char shortstage) // for looping it and making sure all values are cleared
{
    startcalculation(longword, Language, shortstage);
    clearvalues(longword, Language, shortstage);
}

int main()
{
    int Initiallanguage = 0;
    char Language = '0';
    std::cout << "This is a test of my c++ coding ability" << std::endl;
    Checklanguage(Language, Initiallanguage);
    shortstage = '0';
//    std::cin >> x; for later with selecting language
    using namespace boost::multiprecision;
    std::string longword;
    longword.clear();
    startcalculation(longword, Language, shortstage);
    continuecalculation(longword, Language, shortstage);
    clearvalues(longword, Language, shortstage);
    return 0;
}