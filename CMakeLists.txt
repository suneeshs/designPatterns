# CMakeList.txt : CMake project for designPatternProj, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("designPatternProj")

# Add source to this project's executable.
add_executable (designPatternProj "designPatternProj.cpp" "designPatternProj.h" "Observer.hpp")

# TODO: Add tests and install targets if needed.
