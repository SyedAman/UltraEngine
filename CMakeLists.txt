cmake_minimum_required(VERSION 3.15)
project(CustomEngine)

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

# Add source files
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/Engine/AStar.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/AStar.h"
    "${PROJECT_SOURCE_DIR}/Engine/AStar_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/DynamicArray.h"
    "${PROJECT_SOURCE_DIR}/Engine/DynamicArray_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/Engine.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/Engine.h"
    "${PROJECT_SOURCE_DIR}/Engine/Engine_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/main.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/Pair.h"
    "${PROJECT_SOURCE_DIR}/Engine/Pair_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/PriorityQueue.h"
    "${PROJECT_SOURCE_DIR}/Engine/PriorityQueue_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/RenderHardwareInterface.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/RenderHardwareInterface.h"
    "${PROJECT_SOURCE_DIR}/Engine/RenderHardwareInterface_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/UtilityFunctions.h"
    "${PROJECT_SOURCE_DIR}/Engine/UtilityFunctions_Test.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/WindowingLibrary.cpp"
    "${PROJECT_SOURCE_DIR}/Engine/WindowingLibrary.h"
    "${PROJECT_SOURCE_DIR}/Engine/WindowingLibrary_Test.cpp"
)

# Create executable
add_executable(CustomEngine ${SOURCES})

# Link libraries
target_link_libraries(CustomEngine gtest gmock gtest_main ${VULKAN_LIB_LIST})


