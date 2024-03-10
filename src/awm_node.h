#pragma once
#include <vector>
#include <string>
#include "components/awm_component_base.h"

namespace awm {
	class Node {
	public:
		explicit Node(const std::string& _nodeId);
		~Node();
		const std::string& getNodeId();

		/*
		 * Adds a child to a container.
		 * Don't make manual calls to this function. Make this calls from external gui editor.
		 */
		void addChild(Node* child);

		const std::vector<Node*>& getContainer();

		/*
		 * Searches for child among all children recursively.
		 * Returns nullptr when not found.
		 */
		Node* findChildByNameRecursively(const std::string& childId);
		Node* findChildByName(const std::string& childId);

		void updateComponents(float delta);
		void drawComponents();
		void initializeComponents();
	private:
		std::string nodeId;
		std::vector<Node*> children_vector;
		std::vector<components::ComponentBase*> components_vector;
	};
}
