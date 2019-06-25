get_filename_component(VAC_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
# CONF_INCLUDE_DIRS must match the ${PROJECT_SOURCE_DIR}/lib/include of vac
set(VAC_INCLUDE_DIRS "${VAC_CMAKE_DIR}/../../../include/vac")
# LIBRARY_NAME must match the name from vacTargets.cmake
set(VAC_LIBRARIES "vac")

include("${VAC_CMAKE_DIR}/vacTargets.cmake")
