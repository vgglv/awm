#pragma once
#include <string>

namespace awm {
	struct NodeParam {
		std::string name;
		
		// fonts
		std::string font_name;
		int font_size = 12;
		float font_bold_size = 0.F;

		// localization
		std::string locale_id;

		// texture
		std::string texture_path;

		// z-order
		int position;
	};
}
