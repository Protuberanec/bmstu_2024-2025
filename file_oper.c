#include "file_oper.h"

static FILE* f = nullptr;

bool openFile_w(const char* file_name) {
	f = fopen(file_name, "w");
	return f == nullptr ? false : true;
}	   

bool openFile_r(const char* file_name) {
	f = fopen(file_name, "r");
	return f == nullptr ? false : true;
}	   

int writeFile(const char* data) {
	if (f == nullptr) {
		std::cerr << "please open file..." << std::endl;
		return -1;
	}

	int count_written = fwrite(data, 1, strlen(data), f);

	return count_written;	// - strlen(data);
}

int readFile(char** data) {
	if (f == nullptr) {
		std::cerr << "please!!!" << std::endl;
		return -1;
	}

	*data = new char [1024];

	int count_read = fread(*data, 1, 1024, f);
	return count_read;
}

void closeFile() {
	if (f == nullptr) {
		std::cerr << "file is not opened" << std::endl;
		return;
	}
	fclose(f);
	f = nullptr;
}
