#include "test_node.h"
#include "node.h"
#include "test.h"


void test_node_add() {
	{
		Node* Head = new Node();
		ASSERT(Head->next == nullptr);	
		delete Head;
	}
	{
		Node* Head = new Node();
		for (int i = 0; i < 10; i++) {
			AddNode(Head);
		}
		int count = 0;
		for (Node* temp = Head; temp != nullptr; count++, temp = temp->next);

		ASSERT_EQUAL(count, 11);

		delete Head;
	}
	{
		Node* Head = new Node();
		Node* temp = Head;
		for (int i = 0; i < 10; i++) {
			AddNode(temp);
			temp = temp->next;
			temp->data->nameData = i*2;
		}

		int count = 0;
		for (temp = Head; temp->data->nameData != 8; temp = temp->next, count++);
		ASSERT(count == 6);
		temp = Head;
		delete Head;
		delete temp;
		
	}

	


}
