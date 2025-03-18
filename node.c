#include "node.h"

int Data::countEl = 0;

Node::Node() {
	next = nullptr;
	data = new Data();
	
#ifdef SHOW_CONSTR_DATA
	std::cout << __func__ << std::endl;
#endif
}

Node::~Node() {
	delete data;
	if (next != nullptr) {

#ifdef SHOW_CONSTR_DATA
		std::cout << __func__ << std::endl;
#endif
		delete next;
	}
}


void AddNode(struct Node* Head) {
	while(Head->next != nullptr) {
		Head = Head->next;
	}

	Head->next = new Node();
}

void ShowElements(struct Node *Head) {
	Node* temp = Head;
	while(temp->next != nullptr) {
		std::cout << temp->data->nameData << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

struct Data GetNode(struct Node* Head, int num_node, bool del = false) {
	struct Node* temp = Head;
	while(num_node-- > 0 && temp != nullptr) {
		temp = temp->next;
	}
	//in temp will placed address of num_node
	return Data(*temp->data);
}

