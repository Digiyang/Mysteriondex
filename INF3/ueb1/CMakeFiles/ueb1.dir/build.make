# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/digiyang/Desktop/inf3/ueb1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/digiyang/Desktop/inf3/ueb1

# Include any dependencies generated for this target.
include CMakeFiles/ueb1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ueb1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ueb1.dir/flags.make

CMakeFiles/ueb1.dir/main.cpp.o: CMakeFiles/ueb1.dir/flags.make
CMakeFiles/ueb1.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/digiyang/Desktop/inf3/ueb1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ueb1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ueb1.dir/main.cpp.o -c /home/digiyang/Desktop/inf3/ueb1/main.cpp

CMakeFiles/ueb1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ueb1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/digiyang/Desktop/inf3/ueb1/main.cpp > CMakeFiles/ueb1.dir/main.cpp.i

CMakeFiles/ueb1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ueb1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/digiyang/Desktop/inf3/ueb1/main.cpp -o CMakeFiles/ueb1.dir/main.cpp.s

CMakeFiles/ueb1.dir/CDate.cpp.o: CMakeFiles/ueb1.dir/flags.make
CMakeFiles/ueb1.dir/CDate.cpp.o: CDate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/digiyang/Desktop/inf3/ueb1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ueb1.dir/CDate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ueb1.dir/CDate.cpp.o -c /home/digiyang/Desktop/inf3/ueb1/CDate.cpp

CMakeFiles/ueb1.dir/CDate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ueb1.dir/CDate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/digiyang/Desktop/inf3/ueb1/CDate.cpp > CMakeFiles/ueb1.dir/CDate.cpp.i

CMakeFiles/ueb1.dir/CDate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ueb1.dir/CDate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/digiyang/Desktop/inf3/ueb1/CDate.cpp -o CMakeFiles/ueb1.dir/CDate.cpp.s

# Object files for target ueb1
ueb1_OBJECTS = \
"CMakeFiles/ueb1.dir/main.cpp.o" \
"CMakeFiles/ueb1.dir/CDate.cpp.o"

# External object files for target ueb1
ueb1_EXTERNAL_OBJECTS =

ueb1: CMakeFiles/ueb1.dir/main.cpp.o
ueb1: CMakeFiles/ueb1.dir/CDate.cpp.o
ueb1: CMakeFiles/ueb1.dir/build.make
ueb1: CMakeFiles/ueb1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/digiyang/Desktop/inf3/ueb1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ueb1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ueb1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ueb1.dir/build: ueb1

.PHONY : CMakeFiles/ueb1.dir/build

CMakeFiles/ueb1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ueb1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ueb1.dir/clean

CMakeFiles/ueb1.dir/depend:
	cd /home/digiyang/Desktop/inf3/ueb1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/digiyang/Desktop/inf3/ueb1 /home/digiyang/Desktop/inf3/ueb1 /home/digiyang/Desktop/inf3/ueb1 /home/digiyang/Desktop/inf3/ueb1 /home/digiyang/Desktop/inf3/ueb1/CMakeFiles/ueb1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ueb1.dir/depend

