cmake_minimum_required(VERSION 3.10)
project(RayTracing)

set(CMAKE_CXX_STANDARD 17)
set(EXEC_NAME RayTracer)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out/)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

include_directories(lib src)
file(GLOB_RECURSE LIBRARY_FILES "lib/*.[ch]pp")
file(GLOB_RECURSE SOURCE_FILES "src/*.[ch]pp")

add_executable(${EXEC_NAME} ${LIBRARY_FILES} ${SOURCE_FILES})

#Find and link SFML
    find_package(SFML 2 REQUIRED graphics system)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})