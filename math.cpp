#include <iostream>
#include <cmath>

// Keeps dividing square root number until it equals 1
int dividingsquarerootnumber (int squarerootnumberfloat) {
    std::cout << "\n";
    while (squarerootnumberfloat != 1) {
        if (squarerootnumberfloat % 2 == 0) {
            squarerootnumberfloat = squarerootnumberfloat/2;
            std::cout << "divided by 2\n";
        }
        else if (squarerootnumberfloat % 3 == 0) {
            squarerootnumberfloat = squarerootnumberfloat/3;
            std::cout << "divided by 3\n";
        }
        else if (squarerootnumberfloat % 5 == 0) {
            squarerootnumberfloat = squarerootnumberfloat/5;
            std::cout << "divided by 5\n";
        }
        else if (squarerootnumberfloat % 7 == 0) {
            squarerootnumberfloat = squarerootnumberfloat/7;
            std::cout << "divided by 7\n";
        }
        else if (squarerootnumberfloat % 11 == 0) {
            squarerootnumberfloat = squarerootnumberfloat/11;
            std::cout << "divided by 11\n";
        }
        else if (squarerootnumberfloat % 13 == 0) {
            squarerootnumberfloat = squarerootnumberfloat/13;
            std::cout << "divided by 11\n";
        }
        else {
            std::cout << "Not enough prime numbers or is invalid!" << std::endl;
            goto end;
        }
    }
    end:
    return squarerootnumberfloat;
}

// Checks if Exponent is even or odd and math for it
void dividingexponent (int exponent) {
    if (exponent % 2 == 0) {
        exponent = exponent/2;
        std::cout << "The exponent is " << exponent << "\n" << std::endl;
    }
    else {
        exponent = exponent - 1;
        exponent = exponent/2;
        std::cout << "\nexponent equals x^" << exponent << "√x\n";
    }
}

void squarerootmath (int numberaftersquareint) {
    // Converts int to float to check if you can square root it without it having a decimal
    float numberafterfloat = numberaftersquareint;
    // Squarerooting both int and float
    float squarerootnumberfloat = sqrt(numberafterfloat);
    int squarerootnumberint = sqrt(numberaftersquareint);
    
    // If else statement to check if it has a decimal
    if (squarerootnumberint == squarerootnumberfloat) {
        std::cout << "\nThe first number is " << squarerootnumberfloat << std::endl;
    }
    else {
        int squarerootnumberfloat = dividingsquarerootnumber(numberaftersquareint); // Executing function since it has a decimal
    }
}

void mathoftwosquareroots(int firstsquarenumber, int firstexponent, int secondsquarenumber, int secondexponent) {
    int squareresult, exponentresult;
    squareresult = firstsquarenumber * secondsquarenumber;
    exponentresult = firstexponent + secondexponent;
    squarerootmath (squareresult);
    dividingexponent(exponentresult);
}

void userinput0 (int &firstsquarenumber, int &firstexponent, int &secondsquarenumber, int &secondexponent) {
    std::cout << "\nInput the first number after the square root symbol" << std::endl;
    std::cin >> firstsquarenumber;
    std::cout << "Input the first exponent number" << std::endl;
    std::cin >> firstexponent;
    std::cout << "\nInput the second number after the square root symbol" << std::endl;
    std::cin >> secondsquarenumber;
    std::cout << "Input the second exponent number" << std::endl;
    std::cin >> secondexponent;
}

void userinput(int &numberaftersquareint, int &exponentnumber) {
    std::cout << "\nInput the number after the square root symbol" << std::endl;
    std::cin >> numberaftersquareint;
    std::cout << "Input the exponent number" << std::endl;
    std::cin >> exponentnumber;
}

int modeselect(int mode) {
    std::cout << "What mode would you like to have?\n(0) Normal Radical\n(1) Multiplying two radicals" << std::endl;
    std::cin >> mode;
    return mode;
}

void Radical() {
    int Radicalmode;
    Radicalmode = modeselect(Radicalmode);
    while (Radicalmode == 0) {
        int numberaftersquareint, exponentnumber;
        userinput(numberaftersquareint, exponentnumber);
        squarerootmath (numberaftersquareint);
        dividingexponent(exponentnumber);
    }
    while (Radicalmode == 1) {
        int firstsquarenumber, firstexponent, secondsquarenumber, secondexponent;
        userinput0(firstsquarenumber, firstexponent, secondsquarenumber, secondexponent);
        mathoftwosquareroots (firstsquarenumber, firstexponent, secondsquarenumber, secondexponent);
    }
}