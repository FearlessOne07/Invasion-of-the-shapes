# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build

# Include any dependencies generated for this target.
include src/game/CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/game/CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include src/game/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include src/game/CMakeFiles/game.dir/flags.make

src/game/CMakeFiles/game.dir/game.cpp.o: src/game/CMakeFiles/game.dir/flags.make
src/game/CMakeFiles/game.dir/game.cpp.o: /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/src/game/game.cpp
src/game/CMakeFiles/game.dir/game.cpp.o: src/game/CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/game/CMakeFiles/game.dir/game.cpp.o"
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/game/CMakeFiles/game.dir/game.cpp.o -MF CMakeFiles/game.dir/game.cpp.o.d -o CMakeFiles/game.dir/game.cpp.o -c /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/src/game/game.cpp

src/game/CMakeFiles/game.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/game.cpp.i"
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/src/game/game.cpp > CMakeFiles/game.dir/game.cpp.i

src/game/CMakeFiles/game.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/game.cpp.s"
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/src/game/game.cpp -o CMakeFiles/game.dir/game.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/game.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

src/game/libgame.a: src/game/CMakeFiles/game.dir/game.cpp.o
src/game/libgame.a: src/game/CMakeFiles/game.dir/build.make
src/game/libgame.a: src/game/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgame.a"
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean_target.cmake
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/game/CMakeFiles/game.dir/build: src/game/libgame.a
.PHONY : src/game/CMakeFiles/game.dir/build

src/game/CMakeFiles/game.dir/clean:
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : src/game/CMakeFiles/game.dir/clean

src/game/CMakeFiles/game.dir/depend:
	cd /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/src/game /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game /home/baraka-joel/Dev/Repos/Invasion-of-the-shapes/build/src/game/CMakeFiles/game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/game/CMakeFiles/game.dir/depend
