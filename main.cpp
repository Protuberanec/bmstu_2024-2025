#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <string>
#include "test.h"

template<class T, class P>
struct Pair {
	T key;
	P value;
};

struct Pair1 {
	int key;
	std::string value;
};


std::pair<int, int> getErrors() { }
void getErrro1(int& a, int& b) {}



int main(int argc, char** argv) {

	std::map<std::string, int> words;

	std::map<int /*parents*/, std::vector<int> /*childsssssss*/> graph;
	
	auto show_words = [&]() {
		for (const auto &[key, value] : words) {
			std::cout << key << " " << value << std::endl;
		}
	};

	
	std::vector<std::pair<std::string, int>> test_words;

	words["cat"] = 1;
	for (int i = 0; i < 10; i++) {
		words["cat"]++;
	}

	words.insert({"dog", 10});
	words.insert({"dog", 11});
	words.insert({"dog", 12});
	words.insert({"dog", 13});
	std::cout << words["cat"] << std::endl;
	std::cout << words.count("cat") << " " << words.count("dog") << std::endl;
	show_words();

	for (auto iter = words.begin(); iter != words.end(); iter++) {
		std::cout << iter->first << " " << iter->second << std::endl;
	}

	for (const auto &[key, value] : words) {
		std::cout << key << " " << value << std::endl;
	}


	for (;!words.empty();) {
		words.erase(words.begin());
	}

	show_words();

	return 0;
}
