#include "test.h"


void run_test1(void (*f)(), const std::string& func_name) {
	std::cout << func_name << " start test" << std::endl;

	f();
	
}
