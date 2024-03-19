#include "gtest/gtest.h"
#include "awm_node.h"

TEST(nodes_test, add_child) {
	auto root_node = new awm::Node("main_scene");

	auto child_node = new awm::Node("quest_window");
	root_node->addChild(std::move(child_node));

	EXPECT_EQ(root_node->getContainer().size(), 1U);
	EXPECT_EQ("quest_window", root_node->getContainer().front()->getNodeId());
}

TEST(nodes_test, tree_test) {
	int size = 100000;
	awm::Node* saved_root = new awm::Node("root");
	awm::Node* previous_pointer = saved_root;
	awm::Node* last_element = nullptr;
	for (int i=0;i<size;i++) {
		auto new_pointer = new awm::Node(std::to_string(i));
		previous_pointer->addChild(new_pointer);
		previous_pointer = new_pointer;
	}
	auto result = saved_root->findChildByNameRecursively("99999");
	EXPECT_EQ(previous_pointer,result); 
	delete saved_root;
}
