project(main)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(protobuf CONFIG REQUIRED)
target_link_libraries(main PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(main main.cpp person.pb.cc person.pb.h)
target_link_libraries(main person ${Protobuf_LIBRARIES})

# utilities

# build

# install

# install(TARGETS main DESTINATION ${PROJECT_SOURCE_DIR}/bin)
