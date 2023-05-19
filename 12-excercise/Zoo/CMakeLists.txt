cmake_minimum_required(VERSION 3.21)
project(Zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Zoo main.cpp Animal.cpp Animal.h Mammal.cpp Mammal.h Bird.cpp Bird.h Zoo.cpp Zoo.h Zoo.cpp Zoo.h ZooSector.h)
