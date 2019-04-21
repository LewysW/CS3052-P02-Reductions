cmake_minimum_required(VERSION 3.6)   # CMake version check
project(CS3052-P02-Reductions)               # Create project "CS3052-P02-Reductions"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

set(SOURCE_FILES src/main.cpp src/parsers/parserCNF.h src/parsers/parserCNF.cpp src/formats/SAT.h src/formats/SAT.cpp src/formats/clause.cpp src/formats/clause.h src/parsers/parserCOL.cpp src/parsers/parserCOL.h src/formats/COL.cpp src/formats/COL.h)            # Add main.cpp file of project root directory as source file
add_executable(sattothreesat ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable
