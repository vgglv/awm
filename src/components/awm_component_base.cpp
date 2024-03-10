#include "awm_component_base.h"

using namespace awm::components;

ComponentBase::ComponentBase(const std::string& _component_id) : component_id(_component_id) {

}

const std::string& ComponentBase::getComponentId() {
	return component_id;
}
