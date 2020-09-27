
project(hello)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/deps")
message("---->>>> ${CMAKE_PREFIX_PATH}")
set(CMAKE_FIND_ROOT_PATH ${CMAKE_FIND_ROOT_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/deps")

add_executable(hello main.cpp)
find_package(mathOp CONFIG REQUIRED)
target_link_libraries(hello PRIVATE mathOp::mathOp)
