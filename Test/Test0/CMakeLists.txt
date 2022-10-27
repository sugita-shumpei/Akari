add_executable(Akari-Test0 
${CMAKE_CURRENT_SOURCE_DIR}/Include/Test0App.h
${CMAKE_CURRENT_SOURCE_DIR}/Src/Test0App.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Src/main.cpp
)
target_include_directories(Akari-Test0 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(Akari-Test0 PUBLIC Akari-TestLib)