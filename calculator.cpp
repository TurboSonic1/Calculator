#include <limits>
#include <iostream>
using namespace std;

void function() 
{
	cout << "This is a test of my c++ coding ability" << endl;
initialize:
	double x; //using 64bit floating point numbers for variables
	    x = 0; // initialized as 0 to ensure its an integer
	double y;
	    y = 0;
	char math = 'h';
for (;;) { //error handling for first number
	cout << "please input the first number you want to calculate" << flush << endl; //flush is needed to verify that its cleared
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
initialize0:
    cout << "what math operation would you like to use" << endl;
    cin >> math;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (math) {
            case '+':
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            default:
                cout << "This operation is not recognized please use standard arithmetic math" << endl;
                goto initialize;
        }
for (;;) { //error handling for second number
	cout << "Please input the second number you want to calculate" << flush << endl;
	cin >> y;
	if (cin.fail()) { //if it fails
            cerr << "Sorry, I cannot read that. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    else if (cin.good());
        break; //continues to actual calculation
}
calculate: //function for calculation
    switch (math) {
        case '+':
            goto addition;
        case '-':
            goto subtraction;
        case '*':
            goto multiplication;
        case '/':
            goto division;
        default:
            cout << "you shouldn't see this error, if you do you should make a detailed bug report, thanks!";
            goto initialize;
    }
addition:
	cout << x << " + " << y << " = " << (double)x + (double)y << endl;
	cout << "" << endl;
	    goto initialize;
subtraction:
	cout << x << " - " << y << " = " << (double)x - (double)y << endl;
	cout << "" << endl;
	    goto initialize;
multiplication:
	cout << x << " * " << y << " = " << (double)x * (double)y << endl;
	cout << "" << endl;
	    goto initialize;
division:
	cout << x << " / " << y << " = " << (double)x / (double)y << endl;
	cout << "" << endl;
	    goto initialize; // Yes I'm using goto in a function to loop my code.
}

int main()
{
    function ();
    return 0;
}
