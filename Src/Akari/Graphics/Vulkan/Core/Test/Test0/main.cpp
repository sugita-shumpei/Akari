#include <Akari/Graphics/Vulkan/Core/AkariVKCoreExtension.h>
#include <tinyxml2.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
struct ExtensionConfig
{
	std::string name = "";
	std::string type = "";
	uint32_t number = 0;
	std::string supported = "";
	std::vector<std::string> requiredExtensions = {};
	std::string features_name = "";
};
int main()
{
	tinyxml2::XMLDocument doc;
	auto res = doc.LoadFile(__FILE__"/../vk.xml");
	std::unordered_map<std::string, ExtensionConfig> extension_configs = {};
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
						config.requiredExtensions.push_back(required_extension);
					}
				}
				{
					auto require_element = element->FirstChildElement("require");
					if (require_element) {
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
				extension_configs.emplace(config.name, config);
			}

			element = element->NextSiblingElement();
		}

	}
	std::cout << "enum class AkariVKExtensionType :unsigned int{ \n";
	std::cout << "	eInstance,\n";
	std::cout << "	eDevice,\n";
	std::cout << "};" << std::endl;
	std::cout << "enum class AkariVKExtensionFlags :unsigned int{ \n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		std::cout << "	e" << name <<"," << std::endl;
		if (!extension_config.features_name.empty()) {
			
			//std::cout << name << ":" << extension_config.features_name << std::endl;
		}
	}
	std::cout << "};" << std::endl;
	std::cout << "enum class AkariVKInstanceExtensionFlags :unsigned int{ \n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		if (extension_config.type != "instance") { continue; }
		std::cout << "	e" << name << " = static_cast<unsigned int>(AkariVKExtensionFlags::e"<< name << ")," << std::endl;
		if (!extension_config.features_name.empty()) {

			//std::cout << name << ":" << extension_config.features_name << std::endl;
		}
	}
	std::cout << "};" << std::endl;

	std::cout << "enum class AkariVKDeviceExtensionFlags :unsigned int{ \n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		if (extension_config.type != "device") { continue; }
		std::cout << "	e" << name << " = static_cast<unsigned int>(AkariVKExtensionFlags::e" << name << ")," << std::endl;
		if (!extension_config.features_name.empty()) {

			//std::cout << name << ":" << extension_config.features_name << std::endl;
		}
	}
	std::cout << "};" << std::endl;
	std::cout << "struct AkariVKExtensionFeaturesNotAvailable{};\n";
	std::cout << "template<AkariVKExtensionFlags flags>\n";
	std::cout << "struct AkariVKExtensionFeaturesTraits;\n";

	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		bool isDevice = extension_config.type == "device";
		auto typeStr = isDevice ? "Device" : "Instance";
		std::cout << "template<> struct AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::e" << name << ">{\n";
		if (extension_config.features_name == "") {
			std::cout << "using type = void;" << std::endl;
		}
		else {
			std::cout << "#if defined(" << extension_config.name << ")\n";
			auto replaced_name = std::string(extension_config.features_name).replace(0,std::size("VkPhysicalDevice")-1, "vk::PhysicalDevice");
			std::cout << "using type = " << replaced_name << ";" << std::endl;
			std::cout << "#else\n";
			std::cout << "	using type = AkariVKExtensionFeaturesNotAvailable;\n";
			std::cout << "#endif;\n";
		}
		std::cout << "};" << std::endl;
	}
	std::cout << "template<AkariVKExtensionFlags flags>\n";
	std::cout << "struct AkariVKExtensionTraits;\n";
	for (auto& [name, extension_config] : extension_configs) {
		if (extension_config.supported != "vulkan") { continue; }
		bool isDevice = extension_config.type == "device";
		auto typeStr = isDevice ? "Device" : "Instance";
		std::cout << "template<> struct AkariVKExtensionTraits<AkariVKExtensionFlags::e" << name << ">{\n";
		std::cout << "	static inline constexpr AkariVKExtensionFlags extension_flag = AkariVKExtensionFlags::e" << name << ";" << std::endl;
		std::cout << "	static inline constexpr char extension_name[] = \"" << name << "\";" << std::endl;
		std::cout << "	static inline constexpr AkariVKExtensionType extension_type = AkariVKExtensionType::e" << typeStr << ";" << std::endl;
		std::cout << "	static inline constexpr AkariVKExtensionFlags required_extension_flags[] = {\n";
		std::cout << "AkariVKExtensionFlags::e" << name << ",\n";
		for (auto& extension_name : extension_config.requiredExtensions) {
			std::cout << "AkariVKExtensionFlags::e" << extension_name << ",\n";
		}
		std::cout << "};\n";
		std::cout << "	static inline constexpr const char* required_extension_names[] = {\n";
		std::cout << "\"" << name << "\",\n";
		for (auto& extension_name : extension_config.requiredExtensions) {
			std::cout << "\"" << extension_name << "\",\n";
		}
		std::cout << "};\n";
		std::cout << "  using features_type = AkariVKExtensionFeaturesTraits<AkariVKExtensionFlags::e" << name << ">::type;" << std::endl;
		if (!extension_config.features_name.empty()) {

			//std::cout << name << ":" << extension_config.features_name << std::endl;
		}
		
		std::cout << "};" << std::endl;
	}
	return 0;
}