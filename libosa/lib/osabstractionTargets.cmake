# Generated by CMake 3.5.1

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget osabstraction)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target osabstraction
add_library(osabstraction STATIC IMPORTED)

set_target_properties(osabstraction PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/user/AdaptiveEvalbundle/BSW/libsoa/lib/libosabstraction-interface/include/;/home/user/AdaptiveEvalbundle/BSW/libsoa/lib/libosabstraction-posix/include/;/home/user/AdaptiveEvalbundle/BSW/libsoa/lib/libosabstraction-linux/include/"
  INTERFACE_LINK_LIBRARIES "vac;rt"
)

# Import target "osabstraction" for configuration ""
set_property(TARGET osabstraction APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(osabstraction PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "/home/user/AdaptiveEvalbundle/BSW/libsoa/lib/libosabstraction.a"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
