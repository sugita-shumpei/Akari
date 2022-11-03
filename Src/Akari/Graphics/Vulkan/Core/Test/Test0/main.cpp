#include <Akari/Graphics/Vulkan/Core/AkariVKCoreExtension.h>
#include <tinyxml2.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
struct ExtensionConfig
{
	std::string name = "";
	std::string type = "";
	std::string requires_core = "";
	std::string promoted_to   = "";
	bool is_partially_promoted = false;
	std::string features_name = "";
	std::vector<std::string> required_extensions = {};
	std::unordered_set<std::string> depended_extensions = {};
	uint32_t number = 0;
	std::string supported = "";
};
int main()
{
	tinyxml2::XMLDocument doc;
	auto res = doc.LoadFile(__FILE__"/../vk.xml");
	std::vector<std::pair<std::string,ExtensionConfig>> extension_configs = {};
	{
		std::unordered_map<std::string, ExtensionConfig> tmp_extension_configs = {};
		if (res == tinyxml2::XML_SUCCESS) {
			tinyxml2::XMLElement* element = doc.FirstChildElement("registry")->FirstChildElement("extensions")->FirstChildElement();
			while (element) {
				ExtensionConfig config = {};
				auto type_attr = element->FindAttribute("type");
				if (type_attr) {
					config.type = type_attr->Value();
				}
				auto name_attr = element->FindAttribute("name");
				if (name_attr) {
					config.name = name_attr->Value();
				}
				auto number_attr = element->FindAttribute("number");
				if (number_attr) {
					config.number = number_attr->IntValue();
				}
				auto supported_attr = element->FindAttribute("supported");
				if (supported_attr) {
					config.supported = supported_attr->Value();
				}
				auto promoted_attr = element->FindAttribute("promotedto");
				if (promoted_attr) {
					config.promoted_to = promoted_attr->Value();
				}
				auto requires_attr = element->FindAttribute("requiresCore");
				if (requires_attr) {
					config.requires_core = requires_attr->Value();
				}
				bool isValidExtensions = true;
				{
					if (config.name.find(std::string("extension_") + std::to_string(config.number)) != std::string::npos)
					{
						isValidExtensions = false;
					}
				}
				if ((config.type != "") && isValidExtensions) {
					auto requires_attr = element->FindAttribute("requires");
					if (requires_attr) {
						std::string required_extensions = requires_attr->Value();
						std::string required_extension = "";
						std::stringstream ss;
						ss << required_extensions;
						while (std::getline(ss, required_extension, ','))
						{
							config.required_extensions.push_back(required_extension);
						}
					}
					{
						auto require_element = element->FirstChildElement("require");
						if (require_element) {
							auto comment_element = require_element->FirstChildElement("comment");
							if (comment_element) {
								std::string comment = comment_element->GetText();
								if (comment.find("not promoted") != std::string::npos) {
									config.is_partially_promoted = true;
								}
							}
							auto type_element = require_element->FirstChildElement("type");
							while (type_element)
							{
								auto type_name_attr = type_element->FindAttribute("name");
								if (type_name_attr) {
									std::string type_name_str = type_name_attr->Value();
									if ((type_name_str.find("VkPhysicalDevice") != std::string::npos) &&
										(type_name_str.find("Features") != std::string::npos)) {
										config.features_name = type_name_str;
									}
								}
								type_element = type_element->NextSiblingElement();
							}
						}
					}
					tmp_extension_configs.emplace(config.name, config);
				}
				element = element->NextSiblingElement();
			}
		}
		{
			std::queue<std::string> unsolved_extensions = {};
			std::unordered_set<std::string> resolved_extensions = {};
			for (auto& [name, extension_config] : tmp_extension_configs) {
				if (extension_config.required_extensions.empty()) {
					extension_config.depended_extensions = {};
					resolved_extensions.insert(name);
				}
				else {
					unsolved_extensions.push(name);
				}
			}
			while (!unsolved_extensions.empty())
			{
				auto  unsolved_extension = unsolved_extensions.front();
				unsolved_extensions.pop();
				auto& unsolve_config = tmp_extension_configs[unsolved_extension];
				bool is_required_extensions_all_solved = true;
				for (auto& required_extension : unsolve_config.required_extensions) {
					if (resolved_extensions.count(required_extension) == 0) {
						is_required_extensions_all_solved = false;
					}
				}
				if (is_required_extensions_all_solved) {
					unsolve_config.depended_extensions = {};
					for (auto& required_extension : unsolve_config.required_extensions)
					{
						auto& required_config = tmp_extension_configs[required_extension];
						unsolve_config.depended_extensions.insert(required_extension);
						for (auto& depended_extension : required_config.depended_extensions) {
							unsolve_config.depended_extensions.insert(depended_extension);
						}
					}
					resolved_extensions.insert(unsolved_extension);
				}
				else {
					unsolved_extensions.push(unsolved_extension);
				}
			}

		}
		
		extension_configs = std::vector <std::pair<std::string, ExtensionConfig >>(
			std::begin(tmp_extension_configs),std::end(tmp_extension_configs)
		);

		std::sort(std::begin(extension_configs), std::end(extension_configs), [](
			const std::pair<std::string, ExtensionConfig >& a_in, const std::pair<std::string, ExtensionConfig >& b_in) {
				auto& a = a_in.first;
				auto& b = b_in.first;
				std::string a_real_part = a.substr(3, a.size() - 3);
				std::string b_real_part = b.substr(3, a.size() - 3);
				auto comp_func = [](const auto& real_part) {
					if (real_part.substr(0, 3) == "KHR") {
						return 100;
					}
					if (real_part.substr(0, 3) == "EXT") {
						return 99;
					}
					if (real_part.substr(0, 3) == "AMD") {
						return 98;
					}
					if (real_part.substr(0, 3) == "NV_") {
						return 97;
					}

					if (real_part.substr(0, 3) == "NVX") {
						return 96;
					}
					return 0;
				};
				std::uint32_t a_score = comp_func(a_real_part);
				std::uint32_t b_score = comp_func(b_real_part);
				if (a_score > b_score) {
					return true;
				}
				else if (a_score < b_score) {
					return false;
				}
				else {
					return a_real_part < b_real_part;
				}
		});
	}
	std::fstream file("result.txt", std::ios::out | std::ios::binary);
	file << "enum class AkariVKExtensionType :unsigned int{ \n";
	file << "	eInstance,\n";
	file << "	eDevice,\n";
	file << "};" << std::endl;
	file << "enum class AkariVKExtensionFlags :unsigned int{ \n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		file << "	e" << name <<"," << std::endl;
		if (!extension_config.features_name.empty()) {
			
			//file << name << ":" << extension_config.features_name << std::endl;
		}
	}
	file << "	eCount" << std::endl;
	file << "};" << std::endl;
	file << "enum class AkariVKInstanceExtensionFlags :unsigned int{ \n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		if (extension_config.type != "instance") { continue; }
		file << "	e" << name << " = static_cast<unsigned int>(AkariVKExtensionFlags::e"<< name << ")," << std::endl;
		if (!extension_config.features_name.empty()) {

			//file << name << ":" << extension_config.features_name << std::endl;
		}
	}
	file << "};" << std::endl;
	file << "enum class AkariVKDeviceExtensionFlags :unsigned int{ \n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		if (extension_config.type != "device") { continue; }
		file << "	e" << name << " = static_cast<unsigned int>(AkariVKExtensionFlags::e" << name << ")," << std::endl;
		if (!extension_config.features_name.empty()) {

			//file << name << ":" << extension_config.features_name << std::endl;
		}
	}
	file << "};" << std::endl;
	file << "static constexpr std::array<const char*, static_cast<uint32_t>(AkariVKExtensionFlags::eCount)> AkariVKSupportedExtensionNames {" << std::endl;
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		file << "	\"" << name << "\"," << std::endl;
	}
	file << "};" << std::endl;
	file << "inline constexpr auto to_string(AkariVKExtensionFlags flags)->const char* {" << std::endl;
	file << "	return AkariVKSupportedExtensionNames[static_cast<uint32_t>(flags)];\n";
	file << "};" << std::endl;
	file << "struct AkariVKExtensionFeaturesNotAvailable{};\n";
	file << "struct AkariVKExtensionFeaturesNotNecessary{};\n";
	file << "template<AkariVKExtensionFlags flags>\n";
	file << "struct AkariVKExtensionFeaturesTraits;\n";

	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		bool isDevice = extension_config.type == "device";
		auto typeStr = isDevice ? "Device" : "Instance";
		file << "template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::e" << name << ">{\n";
		if (extension_config.features_name == "") {
			file << "using type = AkariVKExtensionFeaturesNotNecessary;" << std::endl;
		}
		else {
			file << "#if defined(" << extension_config.name << ")\n";
			auto replaced_name = std::string(extension_config.features_name).replace(0,std::size("VkPhysicalDevice")-1, "vk::PhysicalDevice");
			file << "using type = " << replaced_name << ";" << std::endl;
			file << "#else\n";
			file << "	using type = AkariVKExtensionFeaturesNotAvailable;\n";
			file << "#endif;\n";
		}
		file << "};" << std::endl;
	}
	file << "template<AkariVKExtensionFlags flags>\n";
	file << "struct AkariVKExtensionTraits;\n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		bool isDevice = extension_config.type == "device";
		auto typeStr = isDevice ? "Device" : "Instance";
		file << "template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::e" << name << ">{\n";
		file << "	static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::e" << typeStr << ";" << std::endl;
		if (extension_config.requires_core.empty()) {
			file << "	static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_0;" << std::endl;
		}
		else if (extension_config.requires_core == "1.1") {
			file << "	static inline constexpr uint32_t required_core_version = VK_API_VERSION_1_1;" << std::endl;
		}
		if (extension_config.promoted_to.empty()) {
			file << "	static inline constexpr uint32_t promoted_core_version = UINT32_MAX;" << std::endl;
		}
		else if (extension_config.promoted_to=="VK_VERSION_1_1") {
			file << "	static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_1;" << std::endl;
		}
		else if (extension_config.promoted_to == "VK_VERSION_1_2") {
			file << "	static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_2;" << std::endl;
		}
		else if (extension_config.promoted_to == "VK_VERSION_1_3") {
			file << "	static inline constexpr uint32_t promoted_core_version = VK_API_VERSION_1_3;" << std::endl;
		}
		else {
			file << "	static inline constexpr uint32_t promoted_core_version = UINT32_MAX;" << std::endl;
		}
		file << "	static inline bool is_partially_promoted = " << (extension_config.is_partially_promoted ? "true;" : "false;") << std::endl;
		file << "	static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::e" << name << ";" << std::endl;
		
		file << "	static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {\n";
		file << "		AkariVKExtensionFlags::e" << name << ",\n";
		for (auto& extension_name : extension_config.required_extensions) {
			file << "		AkariVKExtensionFlags::e" << extension_name << ",\n";
		}
		file << "	};\n";

		file << "	static inline constexpr AkariVKExtensionFlags depended_extension_flags[] = {\n";
		file << "		AkariVKExtensionFlags::e" << name << ",\n";
		for (auto& extension_name : extension_config.depended_extensions) {
			file << "		AkariVKExtensionFlags::e" << extension_name << ",\n";
		}
		file << "	};\n";

		file << "	using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::e" << name << ">::type;" << std::endl;
		if (!extension_config.features_name.empty()) {

			//file << name << ":" << extension_config.features_name << std::endl;
		}
		
		file << "};" << std::endl;
	}
	
	file.close();
	return 0;
}