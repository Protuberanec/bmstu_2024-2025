#include <iostream>
#include <time.h>
#include "file_oper.h"
#include "filo.h"
#include "node.h"


int main(int argc, char** argv) {
	struct Node* Head = new Node();
	for (int i = 0; i < 10; AddNode(Head), i++);

	ShowElements(Head);
	ShowElements(Head->next->next->next);


	delete Head;

	return 0;
}
