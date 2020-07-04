cmake_minimum_required(VERSION 3.17.3)

project("bashDB")
set(CMAKE_CXX_STANDARD 20)
# Binary output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
file(GLOB SOURCES
    src/*.cpp         # Main files
    src/parser/*.cpp  # Parser files
)

# Include folders
set(BASHDB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(BASHDB_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/BashDB)
include_directories(${BASHDB_INCLUDE_DIR})

add_executable("${PROJECT_NAME}" ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR/include}")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
