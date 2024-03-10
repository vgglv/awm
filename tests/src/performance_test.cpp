#include "gtest/gtest.h"
#include "awm_node.h"
#include <chrono>

TEST(performance_test, find_speed_test_1000x1000_nodes) {
	int size = 1000;
	awm::Node* saved_root = new awm::Node("root");
	awm::Node* previous_pointer = saved_root;
	awm::Node* last_element = nullptr;
	for (int i=0;i<size;i++) {
		for (int j=0; j<size;j++) {
			auto new_pointer = new awm::Node(std::to_string(i) + "_" + std::to_string(j));
			previous_pointer->addChild(new_pointer);
		}
		auto new_pointer = new awm::Node(std::to_string(i) + "_0");
		previous_pointer->addChild(new_pointer);
		previous_pointer = new_pointer;
	}
    auto t1 = std::chrono::high_resolution_clock::now();
	auto result = saved_root->findChildByNameRecursively("999_999");
    auto t2 = std::chrono::high_resolution_clock::now();

	auto ms_diff = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "Execution time: " << ms_diff.count() << "ms.\n";
	delete saved_root;
}

TEST(performance_test, find_speed_test_10000_recursed_nodes) {
	int size = 10000;
	awm::Node* saved_root = new awm::Node("root");
	awm::Node* previous_pointer = saved_root;
	awm::Node* last_element = nullptr;
	for (int i=0;i<size;i++) {
		auto new_pointer = new awm::Node(std::to_string(i));
		previous_pointer->addChild(new_pointer);
		previous_pointer = new_pointer;
	}
    auto t1 = std::chrono::high_resolution_clock::now();
	auto result = saved_root->findChildByNameRecursively("9999");
    auto t2 = std::chrono::high_resolution_clock::now();

	auto ms_diff = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "Execution time: " << ms_diff.count() << "ms.\n";
	delete saved_root;
}
