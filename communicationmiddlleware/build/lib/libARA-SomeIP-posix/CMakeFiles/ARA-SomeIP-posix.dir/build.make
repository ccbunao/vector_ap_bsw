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
CMAKE_SOURCE_DIR = /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build

# Include any dependencies generated for this target.
include lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/depend.make

# Include the progress variables for this target.
include lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/progress.make

# Include the compile flags for this target's objects.
include lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/flags.make

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/flags.make
lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o: ../lib/libARA-SomeIP-posix/src/aracom_someip_proxy_instance_factory.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o"
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o -c /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/src/aracom_someip_proxy_instance_factory.cc

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.i"
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/src/aracom_someip_proxy_instance_factory.cc > CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.i

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.s"
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/src/aracom_someip_proxy_instance_factory.cc -o CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.s

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.requires:

.PHONY : lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.requires

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.provides: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.requires
	$(MAKE) -f lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/build.make lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.provides.build
.PHONY : lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.provides

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.provides.build: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o


# Object files for target ARA-SomeIP-posix
ARA__SomeIP__posix_OBJECTS = \
"CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o"

# External object files for target ARA-SomeIP-posix
ARA__SomeIP__posix_EXTERNAL_OBJECTS =

lib/libARA-SomeIP-posix/libARA-SomeIP-posix.a: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o
lib/libARA-SomeIP-posix/libARA-SomeIP-posix.a: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/build.make
lib/libARA-SomeIP-posix/libARA-SomeIP-posix.a: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libARA-SomeIP-posix.a"
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix && $(CMAKE_COMMAND) -P CMakeFiles/ARA-SomeIP-posix.dir/cmake_clean_target.cmake
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ARA-SomeIP-posix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/build: lib/libARA-SomeIP-posix/libARA-SomeIP-posix.a

.PHONY : lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/build

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/requires: lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/src/aracom_someip_proxy_instance_factory.cc.o.requires

.PHONY : lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/requires

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/clean:
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix && $(CMAKE_COMMAND) -P CMakeFiles/ARA-SomeIP-posix.dir/cmake_clean.cmake
.PHONY : lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/clean

lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/depend:
	cd /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix /home/wsj/workspace/vector_ap/DATA/BSW/communicationmiddlleware/build/lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/libARA-SomeIP-posix/CMakeFiles/ARA-SomeIP-posix.dir/depend

