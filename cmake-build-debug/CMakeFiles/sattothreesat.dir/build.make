# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cs/home/locw/Downloads/CLion/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /cs/home/locw/Downloads/CLion/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sattothreesat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sattothreesat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sattothreesat.dir/flags.make

CMakeFiles/sattothreesat.dir/src/main.cpp.o: CMakeFiles/sattothreesat.dir/flags.make
CMakeFiles/sattothreesat.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sattothreesat.dir/src/main.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sattothreesat.dir/src/main.cpp.o -c /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/main.cpp

CMakeFiles/sattothreesat.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sattothreesat.dir/src/main.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/main.cpp > CMakeFiles/sattothreesat.dir/src/main.cpp.i

CMakeFiles/sattothreesat.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sattothreesat.dir/src/main.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/main.cpp -o CMakeFiles/sattothreesat.dir/src/main.cpp.s

CMakeFiles/sattothreesat.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/sattothreesat.dir/src/main.cpp.o.requires

CMakeFiles/sattothreesat.dir/src/main.cpp.o.provides: CMakeFiles/sattothreesat.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sattothreesat.dir/build.make CMakeFiles/sattothreesat.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/sattothreesat.dir/src/main.cpp.o.provides

CMakeFiles/sattothreesat.dir/src/main.cpp.o.provides.build: CMakeFiles/sattothreesat.dir/src/main.cpp.o


CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o: CMakeFiles/sattothreesat.dir/flags.make
CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o: ../src/parsers/parserCNF.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o -c /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/parsers/parserCNF.cpp

CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/parsers/parserCNF.cpp > CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.i

CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/parsers/parserCNF.cpp -o CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.s

CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.requires:

.PHONY : CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.requires

CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.provides: CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.requires
	$(MAKE) -f CMakeFiles/sattothreesat.dir/build.make CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.provides.build
.PHONY : CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.provides

CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.provides.build: CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o


CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o: CMakeFiles/sattothreesat.dir/flags.make
CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o: ../src/formats/SAT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o -c /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/SAT.cpp

CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/SAT.cpp > CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.i

CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/SAT.cpp -o CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.s

CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.requires:

.PHONY : CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.requires

CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.provides: CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.requires
	$(MAKE) -f CMakeFiles/sattothreesat.dir/build.make CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.provides.build
.PHONY : CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.provides

CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.provides.build: CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o


CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o: CMakeFiles/sattothreesat.dir/flags.make
CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o: ../src/formats/clause.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o -c /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/clause.cpp

CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/clause.cpp > CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.i

CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/clause.cpp -o CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.s

CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.requires:

.PHONY : CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.requires

CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.provides: CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.requires
	$(MAKE) -f CMakeFiles/sattothreesat.dir/build.make CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.provides.build
.PHONY : CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.provides

CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.provides.build: CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o


CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o: CMakeFiles/sattothreesat.dir/flags.make
CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o: ../src/parsers/parserCOL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o -c /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/parsers/parserCOL.cpp

CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/parsers/parserCOL.cpp > CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.i

CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/parsers/parserCOL.cpp -o CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.s

CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.requires:

.PHONY : CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.requires

CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.provides: CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.requires
	$(MAKE) -f CMakeFiles/sattothreesat.dir/build.make CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.provides.build
.PHONY : CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.provides

CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.provides.build: CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o


CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o: CMakeFiles/sattothreesat.dir/flags.make
CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o: ../src/formats/COL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o -c /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/COL.cpp

CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/COL.cpp > CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.i

CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/src/formats/COL.cpp -o CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.s

CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.requires:

.PHONY : CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.requires

CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.provides: CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.requires
	$(MAKE) -f CMakeFiles/sattothreesat.dir/build.make CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.provides.build
.PHONY : CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.provides

CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.provides.build: CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o


# Object files for target sattothreesat
sattothreesat_OBJECTS = \
"CMakeFiles/sattothreesat.dir/src/main.cpp.o" \
"CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o" \
"CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o" \
"CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o" \
"CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o" \
"CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o"

# External object files for target sattothreesat
sattothreesat_EXTERNAL_OBJECTS =

sattothreesat: CMakeFiles/sattothreesat.dir/src/main.cpp.o
sattothreesat: CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o
sattothreesat: CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o
sattothreesat: CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o
sattothreesat: CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o
sattothreesat: CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o
sattothreesat: CMakeFiles/sattothreesat.dir/build.make
sattothreesat: CMakeFiles/sattothreesat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable sattothreesat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sattothreesat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sattothreesat.dir/build: sattothreesat

.PHONY : CMakeFiles/sattothreesat.dir/build

CMakeFiles/sattothreesat.dir/requires: CMakeFiles/sattothreesat.dir/src/main.cpp.o.requires
CMakeFiles/sattothreesat.dir/requires: CMakeFiles/sattothreesat.dir/src/parsers/parserCNF.cpp.o.requires
CMakeFiles/sattothreesat.dir/requires: CMakeFiles/sattothreesat.dir/src/formats/SAT.cpp.o.requires
CMakeFiles/sattothreesat.dir/requires: CMakeFiles/sattothreesat.dir/src/formats/clause.cpp.o.requires
CMakeFiles/sattothreesat.dir/requires: CMakeFiles/sattothreesat.dir/src/parsers/parserCOL.cpp.o.requires
CMakeFiles/sattothreesat.dir/requires: CMakeFiles/sattothreesat.dir/src/formats/COL.cpp.o.requires

.PHONY : CMakeFiles/sattothreesat.dir/requires

CMakeFiles/sattothreesat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sattothreesat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sattothreesat.dir/clean

CMakeFiles/sattothreesat.dir/depend:
	cd /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug /cs/home/locw/Documents/CS3052/CS3052-P02-Reductions/cmake-build-debug/CMakeFiles/sattothreesat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sattothreesat.dir/depend

