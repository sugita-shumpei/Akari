add_library(Akari-Core-Lib STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include/Akari/Core/AkariCoreUtility.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/AkariCoreUtility.cpp
)
target_include_directories(
    Akari-Core-Lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)