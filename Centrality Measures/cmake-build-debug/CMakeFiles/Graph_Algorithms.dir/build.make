# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/daver/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Users/daver/Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Graph_Algorithms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Graph_Algorithms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Graph_Algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Graph_Algorithms.dir/flags.make

CMakeFiles/Graph_Algorithms.dir/main.cpp.o: CMakeFiles/Graph_Algorithms.dir/flags.make
CMakeFiles/Graph_Algorithms.dir/main.cpp.o: /Users/daver/Desktop/Graph-Algorithms/Centrality\ Measures/main.cpp
CMakeFiles/Graph_Algorithms.dir/main.cpp.o: CMakeFiles/Graph_Algorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Graph_Algorithms.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Graph_Algorithms.dir/main.cpp.o -MF CMakeFiles/Graph_Algorithms.dir/main.cpp.o.d -o CMakeFiles/Graph_Algorithms.dir/main.cpp.o -c "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/main.cpp"

CMakeFiles/Graph_Algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Graph_Algorithms.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/main.cpp" > CMakeFiles/Graph_Algorithms.dir/main.cpp.i

CMakeFiles/Graph_Algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Graph_Algorithms.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/main.cpp" -o CMakeFiles/Graph_Algorithms.dir/main.cpp.s

# Object files for target Graph_Algorithms
Graph_Algorithms_OBJECTS = \
"CMakeFiles/Graph_Algorithms.dir/main.cpp.o"

# External object files for target Graph_Algorithms
Graph_Algorithms_EXTERNAL_OBJECTS =

Graph_Algorithms: CMakeFiles/Graph_Algorithms.dir/main.cpp.o
Graph_Algorithms: CMakeFiles/Graph_Algorithms.dir/build.make
Graph_Algorithms: CMakeFiles/Graph_Algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Graph_Algorithms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Graph_Algorithms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Graph_Algorithms.dir/build: Graph_Algorithms
.PHONY : CMakeFiles/Graph_Algorithms.dir/build

CMakeFiles/Graph_Algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Graph_Algorithms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Graph_Algorithms.dir/clean

CMakeFiles/Graph_Algorithms.dir/depend:
	cd "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures" "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures" "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug" "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug" "/Users/daver/Desktop/Graph-Algorithms/Centrality Measures/cmake-build-debug/CMakeFiles/Graph_Algorithms.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Graph_Algorithms.dir/depend

