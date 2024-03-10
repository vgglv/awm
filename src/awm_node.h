#pragma once
#include "awm_node_param.h"
#include <vector>
#include <memory>

namespace awm {
	class Node {
	public:
		explicit Node(NodeParam _params);
		~Node();
		const NodeParam& getParams();

		void addChild(std::unique_ptr<Node> child);
		void deleteChild(std::unique_ptr<Node> child);

		const std::vector<std::unique_ptr<Node>>& getContainer();
	private: 
		NodeParam params;
		std::vector<std::unique_ptr<Node>> children_vector;
	};
}
