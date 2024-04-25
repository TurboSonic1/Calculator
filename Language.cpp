#include <fstream>
#include <iostream>
#include <string>

char CheckLanguage(char &Language) { // referencing a variable is pretty important
    std::ifstream ReadingLanguage;
    ReadingLanguage.open("C:\\Users\\Public\\Documents\\Config");
    if (ReadingLanguage.is_open()) {
        while (ReadingLanguage) {
            Language = ReadingLanguage.get();
            switch (Language) {
                case '0':
                    return Language;
                case '1':
                    return Language;
                default:
                    std::cout << "Invalid Language in config! Resetting." << std::endl;
                    std::ofstream WritingLanguage;
                    WritingLanguage.open ("C:\\Users\\Public\\Documents\\Config");
                    remove ("C:\\Users\\Public\\Documents\\Config");
                    WritingLanguage.close();
            }
        }
    }
    else {
        back:
        std::cout << "Please type the number for your language" << std::endl;
        std::cout << "(0) English" << std::endl;
        std::cout << "(1) Deutsch" << std::endl;
        std::string AfterInitialLanguage;
        std::cin >> AfterInitialLanguage;
        Language = AfterInitialLanguage[0];
        std::ofstream WritingLanguage;
        WritingLanguage.open ("C:\\Users\\Public\\Documents\\Config");
        switch (Language) {
            case '0':
                Language = '0';
                WritingLanguage << "0\n";
                WritingLanguage.close();
                return Language;
            case '1':
                Language = '1';
                WritingLanguage << "1\n";
                WritingLanguage.close();
                return Language;
            default:
                std::cout << "Initial language invalid!" << std::endl;
                goto back;
        }
    }
}

/* Shortstage numbers meanings:
0 = Intialized
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