#include <iostream>
#include <time.h>
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

	writeFile("test1");
	openFile_r("test111");
	readFile(&myData);
	closeFile();



	openFile_w("for_graph");

	srand(time(nullptr));

	for (int i = 0; i < 10; i++) {
		std::cout << random() % 100 << "\t";
		//writePoints(i, random() % 100);
	}

	std::cout << std::endl;

	closeFile();

	
	return 0;
}
