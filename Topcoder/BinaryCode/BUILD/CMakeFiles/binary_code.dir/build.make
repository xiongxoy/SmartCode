# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zx/algo/Topcoder/BinaryCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zx/algo/Topcoder/BinaryCode/BUILD

# Include any dependencies generated for this target.
include CMakeFiles/binary_code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary_code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary_code.dir/flags.make

CMakeFiles/binary_code.dir/binary_code.cpp.o: CMakeFiles/binary_code.dir/flags.make
CMakeFiles/binary_code.dir/binary_code.cpp.o: ../binary_code.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/zx/algo/Topcoder/BinaryCode/BUILD/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/binary_code.dir/binary_code.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/binary_code.dir/binary_code.cpp.o -c /Users/zx/algo/Topcoder/BinaryCode/binary_code.cpp

CMakeFiles/binary_code.dir/binary_code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_code.dir/binary_code.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/zx/algo/Topcoder/BinaryCode/binary_code.cpp > CMakeFiles/binary_code.dir/binary_code.cpp.i

CMakeFiles/binary_code.dir/binary_code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_code.dir/binary_code.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/zx/algo/Topcoder/BinaryCode/binary_code.cpp -o CMakeFiles/binary_code.dir/binary_code.cpp.s

CMakeFiles/binary_code.dir/binary_code.cpp.o.requires:
.PHONY : CMakeFiles/binary_code.dir/binary_code.cpp.o.requires

CMakeFiles/binary_code.dir/binary_code.cpp.o.provides: CMakeFiles/binary_code.dir/binary_code.cpp.o.requires
	$(MAKE) -f CMakeFiles/binary_code.dir/build.make CMakeFiles/binary_code.dir/binary_code.cpp.o.provides.build
.PHONY : CMakeFiles/binary_code.dir/binary_code.cpp.o.provides

CMakeFiles/binary_code.dir/binary_code.cpp.o.provides.build: CMakeFiles/binary_code.dir/binary_code.cpp.o

# Object files for target binary_code
binary_code_OBJECTS = \
"CMakeFiles/binary_code.dir/binary_code.cpp.o"

# External object files for target binary_code
binary_code_EXTERNAL_OBJECTS =

binary_code: CMakeFiles/binary_code.dir/binary_code.cpp.o
binary_code: CMakeFiles/binary_code.dir/build.make
binary_code: CMakeFiles/binary_code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable binary_code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary_code.dir/build: binary_code
.PHONY : CMakeFiles/binary_code.dir/build

CMakeFiles/binary_code.dir/requires: CMakeFiles/binary_code.dir/binary_code.cpp.o.requires
.PHONY : CMakeFiles/binary_code.dir/requires

CMakeFiles/binary_code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary_code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary_code.dir/clean

CMakeFiles/binary_code.dir/depend:
	cd /Users/zx/algo/Topcoder/BinaryCode/BUILD && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zx/algo/Topcoder/BinaryCode /Users/zx/algo/Topcoder/BinaryCode /Users/zx/algo/Topcoder/BinaryCode/BUILD /Users/zx/algo/Topcoder/BinaryCode/BUILD /Users/zx/algo/Topcoder/BinaryCode/BUILD/CMakeFiles/binary_code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary_code.dir/depend

