#include <iostream>
using namespace std;

void function() 
{
	cout << "This is a test of my c++ coding ability" << endl;
calculate:
	cout << "please input the first number you want to calculate" << endl;
	double x;
	double y;
	cin >> x;
	cout << "Please input the second number you want to calculate" << endl;
	cin >> y;
	cout << x << " + " << y << " = " << (double)x + (double)y << endl;
	cout << x << " - " << y << " = " << (double)x - (double)y << endl;
	cout << x << " * " << y << " = " << (double)x * (double)y << endl;
	cout << x << " / " << y << " = " << (double)x / (double)y << endl;
	cout << "" << endl;
	goto calculate; // Yes I'm using goto in a function to loop my code.
}

int main()
{
    function ();
    return 0;
}
