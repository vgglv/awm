#include "gtest/gtest.h"
#include <memory>
#include "awm_node.h"

TEST(nodes_test, add_child) {
	awm::NodeParam param;
	param.name = "MainScene";
	auto root_node = std::make_unique<awm::Node>(param);

	param.name = "questWindow";
	auto child_node = std::make_unique<awm::Node>(param);
	root_node->addChild(std::move(child_node));

	EXPECT_EQ(root_node->getContainer().size(), 1U);
}
