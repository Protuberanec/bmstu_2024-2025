#include "node.h"

int Data::countEl = 0;

Node::Node() {
	next = nullptr;
	data = new Data();
	std::cout << __func__ << std::endl;
}

Node::~Node() {
	delete data;
	if (next != nullptr) {
		std::cout << __func__ << std::endl;
		delete next;
	}
}


void AddNode(struct Node* Head) {
//	if (Head->next != nullptr) {
//		AddNode(Head->next);
//		return;
//	}
//	Head->next = new Node();
//
//
//
//	return;
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

