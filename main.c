#include <iostream>

#include "file_oper.h"



int main(int argc, char** argv) {
	openFile_w("test");

	writeFile("hello, 我想回家");

	closeFile();
	
	openFile_r("test");
	char* myData = nullptr;
	int countData = readFile(&myData);
	std::cout << "size data = " << countData << std::endl;
	std::cout << "\t\t\t" << myData << std::endl;

	auto showEl = [](const char* data) {
		for (int i = 0; data[i] != '\0'; i++) {
			std::cout << std::hex << (unsigned int)((unsigned char)data[i]) << std::dec << " ";
		}
		std::cout << std::endl;
	};

	showEl(myData);

	delete [] myData;

	closeFile();

	return 0;
}
