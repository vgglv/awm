#include "awm_node.h"
#include <algorithm>
#include <utility>

using namespace awm;

Node::Node(const std::string& _nodeId) : nodeId(_nodeId) {

}

Node::~Node() {
	for (auto child : children_vector) {
		delete child;
	}
	children_vector.clear();
	for (auto component : components_vector) {
		delete component;
	}
	components_vector.clear();
}

const std::string& Node::getNodeId() {
	return nodeId;
}

void Node::addChild(Node* child) {
	children_vector.emplace_back(std::move(child));
}

const std::vector<Node*>& Node::getContainer() {
	return children_vector;
}

Node* Node::findChildByNameRecursively(const std::string& childId) {
	for (const auto& child : children_vector) {
		if (child->getNodeId() == childId) {
			return child;
		}
		auto result = child->findChildByNameRecursively(childId);
		if (result != nullptr) {
			return result;
		}
	}

	return nullptr;
}

Node* Node::findChildByName(const std::string& childId) {
	const auto& it = std::find_if(children_vector.begin(), children_vector.end(), [&childId](Node* node) {
		return node->getNodeId() == childId;
	});
	if (it != children_vector.end()) {
		return *it;
	}
	return nullptr;
}

void Node::updateComponents(float delta) {
	for (const auto& component : components_vector) {
		component->update(delta);
	}
}

void Node::drawComponents() {
	for (const auto& component : components_vector) {
		component->draw();
	}
}

void Node::initializeComponents() {
	for (const auto& component : components_vector) {
		component->initialize();
	}
}
