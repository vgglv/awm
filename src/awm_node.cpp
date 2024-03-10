#include "awm_node.h"
#include <algorithm>
#include <utility>

using namespace awm;

Node::Node(NodeParam _params) : params(std::move(_params)) {

}

Node::~Node() {
	children_vector.clear();
}

const NodeParam& Node::getParams() {
	return params;
}

void Node::deleteChild(std::unique_ptr<Node> child) {
	const auto& iter = std::find(children_vector.begin(), children_vector.end(), child);
	if (iter == children_vector.end()) {
		return;
	}
	children_vector.erase(iter);
}

void Node::addChild(std::unique_ptr<Node> child) {
	children_vector.emplace_back(std::move(child));
}

const std::vector<std::unique_ptr<Node>>& Node::getContainer() {
	return children_vector;
}
