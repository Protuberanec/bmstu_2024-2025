#include <assert.h>
#include <iostream>
#include <string>
#include <time.h>
#include <cstring>

#include "double_ll.h"

int main(int argc, char** argv) {
	LL* my_ll;
	my_ll = new LL();

	Data stupid_data;

	for (int i = 0; i < 10; i++) {
		my_ll->putToBegin(stupid_data);
	}

	for (int i = 0; i < 10; i++) {
		my_ll->putToEnd(stupid_data);
	}

	my_ll->printLL();

	bool ok = false;
	for (int i = 0; i < 3; i++) {
		my_ll->getFromBegin(ok);
		if (ok == false) {
			break;
		}
	}

	my_ll->printLL();

	for (int i = 0; i < 3; i++) {
		my_ll->getFromEnd(ok);
		if (ok == false) {
			break;
		}
	}

	my_ll->printLL();
	my_ll->delete_element(5);
	my_ll->printLL();

	my_ll->delete_element(0);
	my_ll->printLL();

	std::cout << my_ll->totalCountNodes() << std::endl;
	my_ll->delete_element(my_ll->totalCountNodes() - 1);
	my_ll->printLL();

	my_ll->delete_element(1200);

	delete my_ll;


	return 0;
}
