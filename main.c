#include <iostream>


unsigned int sum(char a, char b) {
	return a + b;
}

int main(int argc, char** argv) {

	unsigned char a = 140;
	unsigned char b = 150;
	unsigned char c = a + b;

	std::cout << (int)a << " + " << (int)b << " = " << (int)c << std::endl;
	std::cout << std::hex << sum(a,b) << std::endl;
	return 0;
}
