#include <iostream>


int sum(char a, char b) {
	return a + b;
}

int main(int argc, char** argv) {

	char a = 140;
	char b = 150;
	char c = a + b;

	std::cout << (int)a << " + " << (int)b << " = " << (int)c << std::endl;
	std::cout << sum(a,b) << std::endl;
	return 0;
}
