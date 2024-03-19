#include "gtest/gtest.h"
#include "awm_node.h"
#include <chrono>

using namespace awm;

TEST(performance_test, find_speed_test_1000x1000_nodes) {
	int size = 100000;
	Node* saved_root = new Node("root");
	Node* previous_pointer = saved_root;
	for (int i=0;i<size;i++) {
		auto new_pointer = new Node(std::to_string(i));
		previous_pointer->addChild(new_pointer);
		previous_pointer = new_pointer;
	}
    auto t1 = std::chrono::high_resolution_clock::now();
	auto result = saved_root->findChildByNameRecursively("99999");
    auto t2 = std::chrono::high_resolution_clock::now();

	auto ms_diff = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "Execution time: " << ms_diff.count() << "ms.\n";
	delete saved_root;
}
