#pragma once 

struct Data {};

struct Node {
	Node* next;
	Data* data;
	Node();
	~Node();
};
