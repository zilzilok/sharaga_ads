# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/103/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/103/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/levenshtein_distance.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/levenshtein_distance.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/levenshtein_distance.dir/flags.make

CMakeFiles/levenshtein_distance.dir/main.cpp.o: CMakeFiles/levenshtein_distance.dir/flags.make
CMakeFiles/levenshtein_distance.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/levenshtein_distance.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/levenshtein_distance.dir/main.cpp.o -c /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/main.cpp

CMakeFiles/levenshtein_distance.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/levenshtein_distance.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/main.cpp > CMakeFiles/levenshtein_distance.dir/main.cpp.i

CMakeFiles/levenshtein_distance.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/levenshtein_distance.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/main.cpp -o CMakeFiles/levenshtein_distance.dir/main.cpp.s

# Object files for target levenshtein_distance
levenshtein_distance_OBJECTS = \
"CMakeFiles/levenshtein_distance.dir/main.cpp.o"

# External object files for target levenshtein_distance
levenshtein_distance_EXTERNAL_OBJECTS =

levenshtein_distance: CMakeFiles/levenshtein_distance.dir/main.cpp.o
levenshtein_distance: CMakeFiles/levenshtein_distance.dir/build.make
levenshtein_distance: CMakeFiles/levenshtein_distance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable levenshtein_distance"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/levenshtein_distance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/levenshtein_distance.dir/build: levenshtein_distance

.PHONY : CMakeFiles/levenshtein_distance.dir/build

CMakeFiles/levenshtein_distance.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/levenshtein_distance.dir/cmake_clean.cmake
.PHONY : CMakeFiles/levenshtein_distance.dir/clean

CMakeFiles/levenshtein_distance.dir/depend:
	cd /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug /home/zilzilok/sharaga/proga/ads/contests/5/LevDistance/cmake-build-debug/CMakeFiles/levenshtein_distance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/levenshtein_distance.dir/depend
