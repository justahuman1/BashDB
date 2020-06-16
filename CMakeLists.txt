cmake_minimum_required(VERSION 3.17.3)

project("bashDB")
set(CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" src/main.cpp)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
