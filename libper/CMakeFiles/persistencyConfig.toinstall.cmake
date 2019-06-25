
get_filename_component(PERSISTENCY_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(PERSISTENCY_INCLUDE_DIRS "${PERSISTENCY_CMAKE_DIR}/../../../include")
set(PERSISTENCY_LIBRARIES "persistency")

find_package(RapidJSON REQUIRED)

include("${PERSISTENCY_CMAKE_DIR}/persistencyTargets.cmake")

find_package(vac REQUIRED)
find_package(RapidJSON REQUIRED)
