add_library(Akari-Engine
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Engine/AkariEngine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Engine/AkariWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Engine/AkariUtility.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Engine/AkariFormat.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariEngine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariWindow.cpp
)
target_include_directories(Akari-Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
target_link_libraries(Akari-Engine PRIVATE SDL2::SDL2)