#include <iostream>

int main()
{
	std::cout << "This is a test" << std::endl;
	std::cout << "please input the first number you want to calculate" << std::endl;
	int x;
	int y;
	std::cin >> x;
	std::cout << "Please input the second number you want to calculate" << std::endl;
	std::cin >> y;

	std::cout << x << " + " << y << " = " << (double)x + (double)y << std::endl;
	std::cout << x << " - " << y << " = " << (double)x - (double)y << std::endl;
	std::cout << x << " * " << y << " = " << (double)x * (double)y << std::endl;
	std::cout << x << " / " << y << " = " << (double)x / (double)y << std::endl;
	return 0;
}
