cmake_minimum_required(VERSION 3.10.2)
project(demo)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)
file(GLOB SOURCE_FILES
        main.cpp
        source/*.cpp)

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
)

if(UNIX AND NOT APPLE)
    find_package(TBB)
    target_link_libraries(${PROJECT_NAME} TBB::tbb)
endif()

add_subdirectory(test)

