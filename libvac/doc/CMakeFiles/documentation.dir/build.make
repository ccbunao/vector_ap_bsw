# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/user/AdaptiveEvalbundle/BSW/libvac

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/AdaptiveEvalbundle/BSW/libvac

# Utility rule file for documentation.

# Include the progress variables for this target.
include doc/CMakeFiles/documentation.dir/progress.make

doc/CMakeFiles/documentation:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/user/AdaptiveEvalbundle/BSW/libvac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating API documentation with Doxygen"
	cd /home/user/AdaptiveEvalbundle/BSW/libvac/doc && /usr/bin/doxygen /home/user/AdaptiveEvalbundle/BSW/libvac/doc/Doxyfile

documentation: doc/CMakeFiles/documentation
documentation: doc/CMakeFiles/documentation.dir/build.make

.PHONY : documentation

# Rule to build all files generated by this target.
doc/CMakeFiles/documentation.dir/build: documentation

.PHONY : doc/CMakeFiles/documentation.dir/build

doc/CMakeFiles/documentation.dir/clean:
	cd /home/user/AdaptiveEvalbundle/BSW/libvac/doc && $(CMAKE_COMMAND) -P CMakeFiles/documentation.dir/cmake_clean.cmake
.PHONY : doc/CMakeFiles/documentation.dir/clean

doc/CMakeFiles/documentation.dir/depend:
	cd /home/user/AdaptiveEvalbundle/BSW/libvac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/AdaptiveEvalbundle/BSW/libvac /home/user/AdaptiveEvalbundle/BSW/libvac/doc /home/user/AdaptiveEvalbundle/BSW/libvac /home/user/AdaptiveEvalbundle/BSW/libvac/doc /home/user/AdaptiveEvalbundle/BSW/libvac/doc/CMakeFiles/documentation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : doc/CMakeFiles/documentation.dir/depend

