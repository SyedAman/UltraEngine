cmake_minimum_required(VERSION 3.15)
project(UltraEngine)

set(CMAKE_CXX_STANDARD 20)

# Add Vulkan SDK
set(VULKAN_SDK_PATH "C:/VulkanSDK/1.3.243.0")
set(VULKAN_LIB_LIST "${VULKAN_SDK_PATH}/Lib/vulkan-1.lib")
include_directories(${VULKAN_SDK_PATH}/Include)

# Add googletest
set(GOOGLETEST_PATH "${PROJECT_SOURCE_DIR}/external/googletest")
add_subdirectory(${GOOGLETEST_PATH})
include_directories(${GOOGLETEST_PATH}/googletest/include)
include_directories(${GOOGLETEST_PATH}/googlemock/include)

# Add source files (Note: GLOB_RECURSE not recommended due to removing files not triggering build system reconfiguration, but this project is big)
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/Engine/*.cpp" "${PROJECT_SOURCE_DIR}/Engine/*.h")
file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/Engine/*_Test.cpp" "${PROJECT_SOURCE_DIR}/Engine/*_Test.h")
list(REMOVE_ITEM SOURCES ${TEST_SOURCES})

# Create executable and link libraries
add_executable(UltraEngine ${SOURCES} ${TEST_SOURCES})
target_link_libraries(UltraEngine gtest gmock gtest_main ${VULKAN_LIB_LIST})

# Create the engine library (for our games to depend on) and link libraries
add_library(EngineLib STATIC ${SOURCES})
target_link_libraries(EngineLib ${VULKAN_LIB_LIST})
