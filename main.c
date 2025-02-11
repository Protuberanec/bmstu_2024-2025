#include <iostream>



int main(int argc, char** argv) {
	int temp = 10;
	int *pTemp = &temp;

	(*pTemp)++;

	std::cout << "temp = " << temp << std::endl;

	temp++;
	std::cout << "*pTemp, addr =  " << pTemp << " val = " << *pTemp << std::endl;



	return 0;
}
