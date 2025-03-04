#include <iostream>
#include <time.h>
#include "file_oper.h"
#include "filo.h"


int main(int argc, char** argv) {
	struct FILO test_filo(100);

	test_filo.addToEnd(-1);
	test_filo.addToEnd(100);
	test_filo.addToEnd(1000);
	test_filo.addToEnd(-1);

	bool ok = false;
	for (int i = 0;; i++) {
		std::cout << test_filo.getFromEnd(ok) << " ";
		if (ok == false) {
			std::cout << std::endl;
			break;
		}
	}

	

	return 0;
}
