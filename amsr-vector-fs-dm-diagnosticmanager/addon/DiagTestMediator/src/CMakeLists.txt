###############################################################################
#    Model Element   : CMakeLists
#    Component       : TEMPLATE
#    Copyright       : Copyright (C) 2017, Vector Informatik GmbH.
#    File Name       : CMakeLists.txt
###############################################################################

message(STATUS "-------------------------------------------------------------")
set(TARGET_NAME diag-test-mediator)

# Automatically add the current source- and build directories to the include path.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Collect source files
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/addon/DiagTestMediator/src/*.cc
                       ${PROJECT_SOURCE_DIR}/addon/DiagTestMediator/src-gen/*.cc
                       ${PROJECT_SOURCE_DIR}/addon/DiagTestMediator/src-future-gen/*.cc)

# Use libDM
message(STATUS "Importing DM")
set(SRCS ${SRCS} ${LIB_DM_SRCS})
set(LIBS_INCLUDE_DIRS ${LIBS_INCLUDE_DIRS} ${LIB_DM_INCLUDE_DIRS})
message(STATUS "Following DM dependencies have to be present: ${LIB_DM_DEPENDENCIES}")
message(STATUS " ")

add_executable(${TARGET_NAME} ${SRCS})

# find external packages
message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing Threads")
find_package(Threads REQUIRED)
message(STATUS "Package Threads found = ${Threads_FOUND}")
target_link_libraries(${TARGET_NAME} ${CMAKE_THREAD_LIBS_INIT})

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing Vector Adaptive Common library (vac)")
find_package(vac REQUIRED)
message(STATUS "Package vac found: ${vac_FOUND}")
message(STATUS "VAC_INCLUDE_DIRS: ${VAC_INCLUDE_DIRS}")
message(STATUS "VAC_LIBRARIES: ${VAC_LIBRARIES}")
target_link_libraries(${TARGET_NAME} ${VAC_LIBRARIES})

message(STATUS "Importing osabstraction")
find_package(osabstraction REQUIRED)
if (vac_FOUND)
  message(STATUS "Package osabstraction found: ${osabstraction_FOUND}")
  message(STATUS "OSABSTRACTION_INCLUDE_DIRS: ${OSABSTRACTION_INCLUDE_DIRS}")
  message(STATUS "OSABSTRACTION_LIBRARIES: ${OSABSTRACTION_LIBRARIES}")
  target_link_libraries(${TARGET_NAME} ${OSABSTRACTION_LIBRARIES})
endif ()

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing ara")
find_package(ARA REQUIRED)
message(STATUS "Package ARA found: ${ARA_FOUND}")
message(STATUS "ARA_INCLUDE_DIRS: ${ARA_INCLUDE_DIRS}")
message(STATUS "ARA_LIBRARIES: ${ARA_LIBRARIES}")
target_link_libraries(${TARGET_NAME} ${ARA_LIBRARIES})

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing ARA-SomeIP-posix")
find_package(ARA-SomeIP-posix REQUIRED)
message(STATUS "Package ARA-SomeIP-posix found: ${ARA-SomeIP-posix_FOUND}")
message(STATUS "ARA_SOMEIP_POSIX_INCLUDE_DIRS: ${ARA_SOMEIP_POSIX_INCLUDE_DIRS}")
message(STATUS "ARA_SOMEIP_POSIX_LIBRARIES: ${ARA_SOMEIP_POSIX_LIBRARIES}")
target_link_libraries(${TARGET_NAME} ${ARA_SOMEIP_POSIX_LIBRARIES})

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing SomeIP-posix-common")
find_package(SomeIP-posix-common REQUIRED)
message(STATUS "Package SomeIP-posix-common found: ${SomeIP-posix-common_FOUND}")
message(STATUS "SOMEIP_POSIX_COMMON_INCLUDE_DIRS: ${SOMEIP_POSIX_COMMON_INCLUDE_DIRS}")
message(STATUS "SOMEIP_POSIX_COMMON_LIBRARIES: ${SOMEIP_POSIX_COMMON_LIBRARIES}")
target_link_libraries(${TARGET_NAME} ${SOMEIP_POSIX_COMMON_LIBRARIES})

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing SomeIP-posix")
find_package(SomeIP-posix REQUIRED)
message(STATUS "Package SomeIP-posix found: ${SomeIP-posix_FOUND}")
message(STATUS "SOMEIP_POSIX_INCLUDE_DIRS: ${SOMEIP_POSIX_INCLUDE_DIRS}")
message(STATUS "SOMEIP_POSIX_LIBRARIES: ${SOMEIP_POSIX_LIBRARIES}")
target_link_libraries(${TARGET_NAME} ${SOMEIP_POSIX_LIBRARIES})

message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing Microsar Persistency")
find_package(persistency REQUIRED)
message(STATUS "Package persistency found: ${persistency_FOUND}")
message(STATUS "PERSISTENCY_INCLUDE_DIRS: ${PERSISTENCY_INCLUDE_DIRS}")
message(STATUS "PERSISTENCY_LIBRARIES: ${PERSISTENCY_LIBRARIES}")
target_link_libraries(${TARGET_NAME} ${PERSISTENCY_LIBRARIES})


if (ENABLE_EXEC_MANAGER_VECTOR)
  set(VectorApplicationClient amsr-vector-fs-em-executionmanagement_application-client)
  find_package(${VectorApplicationClient} REQUIRED)
  set(ARA_EXEC_LIBRARIES ${${VectorApplicationClient}_LIBRARIES})
  message(STATUS "    Package ApplicationClient (Vector) found with libraries: ${ARA_EXEC_LIBRARIES}")
  set(ARA_EXEC_INCLUDE_DIRS ${${VectorApplicationClient}_INCLUDE_DIRS})
  set(ARA_EXEC_FLAGS "-DENABLE_EXEC_MANAGER_SUPPORT_VECTOR")
  set(MANIFEST_FILE "${CMAKE_CURRENT_LIST_DIR}/../etc/manifest.json")
  set(EXEC_MANAGER_ENABLED true)
endif()

if (ENABLE_EXEC_MANAGER_AUTOSAR)
  find_package(ARAExec REQUIRED)
  find_package(AdaptivePlatform REQUIRED)
  set(ARA_EXEC_LIBRARIES ${ARAEXEC_LIBRARIES} ${ADAPTIVEPLATFORM_LIBRARIES})
  message(STATUS "    Package ARAExec and AdaptivePlatform (AUTOSAR) found with libraries: ${ARA_EXEC_LIBRARIES}")
  set(ARA_EXEC_INCLUDE_DIRS ${ARAEXEC_INCLUDE_DIRS})
  set(ARA_EXEC_FLAGS "-DENABLE_EXEC_MANAGER_SUPPORT_AUTOSAR")
  set(MANIFEST_FILE "${CMAKE_CURRENT_LIST_DIR}/../etc/MANIFEST.ini")
  set(EXEC_MANAGER_ENABLED true)
endif()

if(EXEC_MANAGER_ENABLED)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ARA_EXEC_FLAGS}")
  target_link_libraries(${TARGET_NAME} ${ARA_EXEC_LIBRARIES})
endif()


message(STATUS "-------------------------------------------------------------")
message(STATUS "Importing Log-module")
find_package(ara-logging REQUIRED)
message(STATUS "Package amsr-vector-fs-log-api found: ${amsr-vector-fs-log-api_FOUND}")
target_link_libraries(${TARGET_NAME} ${ARA_LOGGING_LIBRARIES})

include_directories(
    ${LIB_DM_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/lib/libDM/include
    ${PROJECT_SOURCE_DIR}/addon/DiagTestMediator/src-gen/includes
    ${PROJECT_SOURCE_DIR}/addon/DiagTestMediator/src-future-gen/includes
    ${PROJECT_SOURCE_DIR}/addon/DiagTestMediator/src-gen/someip-posix
    ${VAC_INCLUDE_DIRS}
    ${OSABSTRACTION_INCLUDE_DIRS}
    ${PERSISTENCY_INCLUDE_DIRS}
    ${SOMEIP_POSIX_COMMON_INCLUDE_DIRS}
    ${SOMEIP_POSIX_INCLUDE_DIRS}
    ${ARA_SOMEIP_POSIX_INCLUDE_DIRS}
    ${ARA_INCLUDE_DIRS}
    ${ARA_LOGGING_INCLUDE_DIRS}
    ${EXEC_MANAGER_INCLUDE_DIRS}
    )

set(DIAGTEST_MEDIATOR_INSTALL_BIN_DIR "/opt/${TARGET_NAME}/bin")

install(
  TARGETS ${TARGET_NAME}
  RUNTIME DESTINATION "${DIAGTEST_MEDIATOR_INSTALL_BIN_DIR}"
  )

install(
  FILES ${MANIFEST_FILE}
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  DESTINATION ${CMAKE_INSTALL_SYSCONFDIR}
  )

message(STATUS "-------------------------------------------------------------")
