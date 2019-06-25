# Install script for directory: /home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/libARA-SomeIP-posix.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/include/")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets.cmake"
         "/home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/CMakeFiles/Export/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix" TYPE FILE FILES "/home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/CMakeFiles/Export/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix" TYPE FILE FILES "/home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/lib/libARA-SomeIP-posix/CMakeFiles/Export/lib/cmake/ARA-SomeIP-posix/ARA-SomeIP-posixTargets-noconfig.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ARA-SomeIP-posix" TYPE FILE RENAME "ARA-SomeIP-posixConfig.cmake" FILES "/home/user/AdaptiveEvalbundle/BSW/communicationmiddlleware/CMakeFiles/ARA-SomeIP-posixConfig.toinstall.cmake")
endif()

