#include <assert.h>
#include <iostream>
#include <string>
#include <time.h>
#include <cstring>
#include "file_oper.h"
#include "filo.h"
#include "node.h"

#include "test.h"
#include "test_node.h"

int main(int argc, char** argv) {
	RUN_TEST(test_node_add);


	return 0;
	struct Node* Head = new Node();
	for (int i = 0; i < 10; AddNode(Head), i++);

	ShowElements(Head);
	ShowElements(Head->next->next->next);


	delete Head;

	return 0;
}
