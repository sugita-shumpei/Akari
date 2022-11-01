add_library(Akari-Graphics-Vulkan-Utility-Lib STATIC

${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Utility/AKariVKUtils.h
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKUtils.cpp

${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Utility/AKariVKUtilsStructureWrapper.h
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKUtilsStructureWrapper.cpp

${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Graphics/Vulkan/Utility/AKariVKUtilsFeaturesWrapper.h
${CMAKE_CURRENT_SOURCE_DIR}/Src/AKariVKUtilsFeaturesWrapper.cpp

)
target_include_directories(Akari-Graphics-Vulkan-Utility-Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(Akari-Graphics-Vulkan-Utility-Lib  PUBLIC Akari-Graphics-Vulkan-Core-Lib)