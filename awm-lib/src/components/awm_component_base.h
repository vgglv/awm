#pragma once
#include <string>
#include "json/value.h"

namespace awm::components {
	class ComponentBase {
	public:
		ComponentBase(const std::string& _component_id);
		virtual ~ComponentBase() = default;

		virtual void initialize() = 0;
		virtual void draw() = 0;
		virtual void update(float delta) = 0;
		virtual void parse(const Json::Value& properties) = 0;

		const std::string& getComponentId();
	protected:

		// this will 
		std::string component_id;
	};

}
