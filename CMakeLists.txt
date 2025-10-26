cmake_minimum_required(VERSION 3.16)
project(SFMLtriangles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output compiled binary to build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find SFML 3
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

# Gather source and header files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.h)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include header directory
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link SFML 3 libraries
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)