#include "double_ll.h"


int node::count_nodes = 0;

node::node() {
	name_node = ++count_nodes;

	next = nullptr;
	prev = nullptr;
	data = nullptr;
}

node::~node() {
	if (data) {
		delete data;
	}

	if (next != nullptr) {
		delete next;
	}
	count_nodes--;
}
//--------------------------------------------------
LL::LL() {
	Head = nullptr;
	Tail = nullptr;
}

LL::~LL() {
	if (Head != nullptr) {
		delete Head;
	}
}

void LL::putToEnd(const Data& data) {
	if (Head == nullptr) {
		Head = new node();
		Tail = Head;
		Head->changeNameNode(0);
		return;
	}
	
	node* temp = new node();
	temp->prev = Tail;
	Tail->next = temp;
	temp->changeNameNode(Tail->name_node + 1);
	Tail = Tail->next; //<-- temp
					   
/*	
 	Tail->next = new node();
	Tail->next->prev = Tail;
	Tail = Tail->next;
*/
}

void LL::putToBegin(const Data& data) {
	if (Head == nullptr) {
		Head = new node();
		Tail = Head;
		Head->changeNameNode(0);
		return;
	}
	
	node* temp = new node();

	temp->next = Head;
	Head->prev = temp;
	temp->changeNameNode(Head->name_node - 1);
	Head = temp;
}

Data LL::getFromEnd(bool& ok) {
	if (Head == nullptr) {
		ok = false;
		return Data();
	}
	ok = true;
	Data temp = *Tail->data;

	Tail = Tail->prev;
	delete Tail->next;
	Tail->next = nullptr;

	return temp;
}

Data LL::getFromBegin(bool& ok) {
	if (Head == nullptr) {
		ok = false;
		return Data();
	}

	ok = true;
	Data temp_data = *Head->data;
	Head = Head->next;	/// move Head to next element
	node* temp = Head->prev;

	Head->prev = nullptr;	///it's firts element
	temp->next = nullptr;
	delete temp;

	return temp_data;
}

int LL::totalCountNodes() const {
	return Head->count_nodes;
}

void LL::delete_element(int start, int count) {
#ifdef DEBUG
	std::cout << __func__ << std::endl;
#endif
	if (Head == nullptr) {
		return;
	}

	int current = 0;
	node* temp_node = Head;
	while(current != start && temp_node != nullptr) {
		temp_node = temp_node->next;
		current++;
	}
#ifdef DEBUG
	std::cout << "node was found" << std::endl;
#endif
	if (current < start) {
		return;
	}
	if (temp_node == nullptr) {
		return;
	}
#ifdef DEBUG
	std::cout << "start change addr" << std::endl;
#endif

	if (temp_node->prev == nullptr) {
			//temp_node is HEAD 
		Head = Head->next;
		Head->prev = nullptr;
	}
	else if (temp_node->next == nullptr) {
		//temp_node is Tail
		Tail = Tail->prev;
		Tail->next = nullptr;
	}
	else if (temp_node->prev != nullptr) {
		temp_node->next->prev = temp_node->prev;
		temp_node->prev->next = temp_node->next;
	}

	temp_node->prev = nullptr;
	temp_node->next = nullptr;
#ifdef DEBUG
	std::cout << "delete node" << std::endl;
#endif
	delete temp_node;
}

void LL::flush() {
	if (Head == nullptr) {
		return;
	}
	delete Head;
	Head = nullptr;
}

int LL::search(const Data& toSearch) {
	node* temp = Head;
	int count = 0;
	while (temp != nullptr) {
		
		if (temp->data == toSearch) {
			return count;
		}
		count++;
	}	
	return -1;
}

void LL::printLL(int start, int count) const {
	node* temp = Head;
	std::cout << "LL : ";
	while(temp != nullptr) {
		std::cout << temp->name_node << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}




