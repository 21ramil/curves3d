cmake_minimum_required(VERSION 3.21)

project(test_curves CXX)

set(TARGET_NAME main)
set(SOURCE_EXE main.cpp)

add_subdirectory(curves)

add_executable(${TARGET_NAME} ${SOURCE_EXE})
target_link_libraries(${TARGET_NAME} curves)
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/curves)
install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION .)