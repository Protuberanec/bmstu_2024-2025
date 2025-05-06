#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>
#include "test.h"

#include <tuple>


class Graph {
	private :
		std::map<int, std::vector<int>> nodes;
		void show_rec(int parent, const std::map<int,std::vector<int>>& children) const;
	public :
		Graph();
		Graph(const std::string& file_graph);

		~Graph();

		void addNode(int parent, int child);
		void ShowNodes() const;
		void SaveToFile(const std::string& fileName);
};

Graph::Graph() {}
Graph::Graph(const std::string& fileName) {}
Graph::~Graph() {}

void Graph::addNode(int parent, int child) {
	nodes[parent].push_back(child);
	if (nodes.count(child) == 1) {
		return;	
	}
	nodes[child] = {};
}

void Graph::show_rec(int parent, const std::map<int,std::vector<int>>& children) const {
	std::cout << parent << "{";
	if (children.at(parent).empty()) {
		std::cout << "}";
		return;
	}

	if (!children.at(parent).empty()) {
		show_rec(*children.at(parent).begin(), children);
	}
	else {
		std::cout << *children.at(parent).begin();
	}

	for (auto iter = children.at(parent).begin() + 1; iter != children.at(parent).end(); iter++) {
		if (!children.at(*iter).empty()) {
			show_rec(*iter, children);
			continue;
		}
		else {
			std::cout << ", " << *iter;
		}
	}
	std::cout << "}";

}

void Graph::ShowNodes() const {
	show_rec(0, nodes);
	std::cout << std::endl;
	return ;
	for (auto iter = nodes.begin(); iter != nodes.end(); iter++) {
		if (iter->second.empty()) {
			continue;
		}
		std::cout << iter->first << "{" << *iter->second.begin();
		for (auto iter1 = iter->second.begin() + 1; iter1 != iter->second.end(); iter1++) {
			std::cout << ", " << *iter1;
		}
		std::cout << "}";
	}
	std::cout << std::endl;
}


int main(int argc, char** argv) {

	Graph myGraph;
	myGraph.addNode(0, 1);
	myGraph.addNode(0, 2);
	myGraph.addNode(0, 3);
	myGraph.addNode(0, 4);
	myGraph.addNode(0, 5);
	myGraph.addNode(0, 6);
	myGraph.addNode(0, 7);
	myGraph.addNode(1, 8);
	myGraph.addNode(1, 9);
	myGraph.addNode(1, 10);
	myGraph.addNode(1, 11);
	myGraph.addNode(1, 12);
	myGraph.addNode(2, 13);
	myGraph.addNode(0, 14);
	myGraph.addNode(0, 15);
	myGraph.addNode(0, 16);
	myGraph.addNode(0, 17);
	myGraph.addNode(0, 18);

	myGraph.ShowNodes();


	return 0;
}
