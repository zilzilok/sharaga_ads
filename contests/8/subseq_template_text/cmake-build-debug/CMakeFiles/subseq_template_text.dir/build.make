# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\USER\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6911.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\USER\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.6911.21\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\sharaga\sharaga_ads\contests\8\subseq_template_text

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\sharaga\sharaga_ads\contests\8\subseq_template_text\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/subseq_template_text.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/subseq_template_text.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subseq_template_text.dir/flags.make

CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.obj: CMakeFiles/subseq_template_text.dir/flags.make
CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.obj: ../subseq_template_text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\sharaga\sharaga_ads\contests\8\subseq_template_text\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\subseq_template_text.dir\subseq_template_text.cpp.obj -c C:\sharaga\sharaga_ads\contests\8\subseq_template_text\subseq_template_text.cpp

CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\sharaga\sharaga_ads\contests\8\subseq_template_text\subseq_template_text.cpp > CMakeFiles\subseq_template_text.dir\subseq_template_text.cpp.i

CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\sharaga\sharaga_ads\contests\8\subseq_template_text\subseq_template_text.cpp -o CMakeFiles\subseq_template_text.dir\subseq_template_text.cpp.s

# Object files for target subseq_template_text
subseq_template_text_OBJECTS = \
"CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.obj"

# External object files for target subseq_template_text
subseq_template_text_EXTERNAL_OBJECTS =

subseq_template_text.exe: CMakeFiles/subseq_template_text.dir/subseq_template_text.cpp.obj
subseq_template_text.exe: CMakeFiles/subseq_template_text.dir/build.make
subseq_template_text.exe: CMakeFiles/subseq_template_text.dir/linklibs.rsp
subseq_template_text.exe: CMakeFiles/subseq_template_text.dir/objects1.rsp
subseq_template_text.exe: CMakeFiles/subseq_template_text.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\sharaga\sharaga_ads\contests\8\subseq_template_text\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable subseq_template_text.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\subseq_template_text.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subseq_template_text.dir/build: subseq_template_text.exe

.PHONY : CMakeFiles/subseq_template_text.dir/build

CMakeFiles/subseq_template_text.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\subseq_template_text.dir\cmake_clean.cmake
.PHONY : CMakeFiles/subseq_template_text.dir/clean

CMakeFiles/subseq_template_text.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\sharaga\sharaga_ads\contests\8\subseq_template_text C:\sharaga\sharaga_ads\contests\8\subseq_template_text C:\sharaga\sharaga_ads\contests\8\subseq_template_text\cmake-build-debug C:\sharaga\sharaga_ads\contests\8\subseq_template_text\cmake-build-debug C:\sharaga\sharaga_ads\contests\8\subseq_template_text\cmake-build-debug\CMakeFiles\subseq_template_text.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subseq_template_text.dir/depend

