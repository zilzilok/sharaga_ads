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
CMAKE_SOURCE_DIR = /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wagner_fisher.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wagner_fisher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wagner_fisher.dir/flags.make

CMakeFiles/wagner_fisher.dir/main.cpp.o: CMakeFiles/wagner_fisher.dir/flags.make
CMakeFiles/wagner_fisher.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wagner_fisher.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wagner_fisher.dir/main.cpp.o -c /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/main.cpp

CMakeFiles/wagner_fisher.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wagner_fisher.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/main.cpp > CMakeFiles/wagner_fisher.dir/main.cpp.i

CMakeFiles/wagner_fisher.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wagner_fisher.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/main.cpp -o CMakeFiles/wagner_fisher.dir/main.cpp.s

# Object files for target wagner_fisher
wagner_fisher_OBJECTS = \
"CMakeFiles/wagner_fisher.dir/main.cpp.o"

# External object files for target wagner_fisher
wagner_fisher_EXTERNAL_OBJECTS =

wagner_fisher: CMakeFiles/wagner_fisher.dir/main.cpp.o
wagner_fisher: CMakeFiles/wagner_fisher.dir/build.make
wagner_fisher: CMakeFiles/wagner_fisher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wagner_fisher"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wagner_fisher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wagner_fisher.dir/build: wagner_fisher

.PHONY : CMakeFiles/wagner_fisher.dir/build

CMakeFiles/wagner_fisher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wagner_fisher.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wagner_fisher.dir/clean

CMakeFiles/wagner_fisher.dir/depend:
	cd /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug /home/zilzilok/sharaga/proga/ads/contests/5/WagnerFisher/cmake-build-debug/CMakeFiles/wagner_fisher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wagner_fisher.dir/depend

