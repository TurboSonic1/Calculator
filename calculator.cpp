#include <limits>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void startcalculation(double &x, double &z){
for (;;) { //error handling for first number
	cout << "Please enter the number(s) you want to have calculated" << flush << endl;
	cin >> x;
	if (cin.fail()) { //if it fails
            cerr << "Sorry, I cannot read that. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    else if (cin.good());
        break; //verified to be good and continues
}
}


void calculation(char &math, double x, double y, double z) {
switch (math) { //Actual Calculations
    case '+':
        cout << x << " + " << y << " = " << (double)x + (double)y << endl;
	    cout << "" << endl;
        z = (double)x + (double)y;
	        break;
    case '-':
        cout << x << " - " << y << " = " << (double)x - (double)y << endl;
	    cout << "" << endl;
        z = x - y;
	        break;
    case '*':
        cout << x << " * " << y << " = " << (double)x * (double)y << endl;
	    cout << "" << endl;
        z = x * y;
	        break;
    case '/':
        cout << x << " / " << y << " = " << (double)x / (double)y << endl;
	    cout << "" << endl;
        z = x / y;
	        break;
	case 's':
	    cout << x << "√(" << y << ")" << " = " << (double)x * sqrt(y);
	    cout << "" << endl;
        z = x * sqrt(y);
	        break;
    case '^':
        cout << x << "^" << y << "=" << pow(x, y);
        cout << "" << endl;
        z = pow(x,y);
            break;
    default:
        cout << "you shouldn't see this error, if you do you should make a detailed bug report, thanks!";
            break;
    }
}

void operation(string &longword,double x, double y, double z){
cout << "what math operation would you like to use" << endl;
    cin >> longword;
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
            default:
                cout << "This operation is not recognized please use standard arithmetic math or squareroots/exponents" << endl;
                operation (longword, x, y, z);
        }
for (;;) { //error handling for second number
	cout << "Please enter the second number(s) you want to have calculated" << flush << endl; //flush is needed to verify that its cleared
	cin >> y;
	if (cin.fail()) { //if it fails
            cerr << "Sorry, I cannot read that. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    else if (cin.good());
        calculation (math, x, y, z);
        break; //verified to be good and continues
}
}

void clearvalues(string &longword, double &x, double &y, double &z)
{
    startcalculation(x, z);
    operation(longword, x, y, z);
    clearvalues(longword, x, y, z);
}

int main()
{
cout << "This is a test of my c++ coding ability" << endl;
	double x; //using 64bit floating point numbers for variables
	    x = 0; // initialized as 0 to ensure its an integer
	double y;
	    y = 0;
    double z; //currently not in use, for future update
        z = 0;
	string longword;
	longword.clear();
    startcalculation(x, z);
    operation(longword, x, y, z);
    clearvalues(longword, x, y, z);
    return 0;
}
