cmake_minimum_required(VERSION 3.10)
project(SFMLtriangles)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# List all source files
set(SOURCES
    main.cpp
    Game.cpp  # Add your new source file here
    Triangle.cpp
    Figure.cpp
    Grid.cpp
)

# List all header files (optional, for clarity)
set(HEADERS
    Game.h    # Add your new header file here
    Triangle.h
    Figure.h
    Grid.h
)

add_executable(SFMLtriangles ${SOURCES})
target_link_libraries(SFMLtriangles sfml-graphics sfml-window sfml-system)

