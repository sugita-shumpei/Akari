add_library(Akari-TestLib 
${CMAKE_CURRENT_SOURCE_DIR}/Include/TestLib/TestApp.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/TestLib/TestWindow.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/TestLib/TestWindowManager.h
${CMAKE_CURRENT_SOURCE_DIR}/Include/TestLib/TestGraphicsVulkan.h
${CMAKE_CURRENT_SOURCE_DIR}/Src/TestApp.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/TestWindow.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/TestWindowManager.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/TestGraphicsVulkan.cpp
)
target_include_directories(Akari-TestLib PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/Include
)
target_link_libraries(Akari-TestLib PUBLIC Vulkan::Vulkan SDL2::SDL2)