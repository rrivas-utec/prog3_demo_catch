cmake_minimum_required(VERSION 3.10.2)
set(PROJECT_NAME demo)
project(${PROJECT_NAME}_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_DEBUG})

message(STATUS "Runtime Output Dir: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Deducir el home folder dinámicamente
if (WIN32)
    set(HOME_DIR $ENV{USERPROFILE})
else ()
    set(HOME_DIR $ENV{HOME})
endif ()
message(STATUS "Home Dir: ${HOME_DIR}")

# Definir la opción CATCH2_AMALGAMATED y habilitarla por defecto
option(CATCH2_AMALGAMATED "Enable Catch2 amalgamated" ON)

# Incluir el directorio de encabezados
include_directories(../include)
include_directories(.)
file(GLOB SOURCES_FILES
        ../source/*.cpp
        *.cpp
        test_*/*.cpp
        )

# Crear el ejecutable
if (CATCH2_AMALGAMATED)
    message(STATUS "Using CATCH2 AMALGAMATED")
    add_definitions(-DCATCH2_AMALGAMATED)
    include_directories(../catch2)
    file(GLOB CATCH2_FILES "../catch2/*.cpp")
    add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${CATCH2_FILES})
else ()
    message(STATUS "Using CATCH2 PACKAGE")
    find_package(Catch2 REQUIRED CONFIG)
    add_executable(${PROJECT_NAME} ${SOURCES_FILES})
    target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
endif ()

# Copiando Test files en Runtime Output Directory
file(GLOB test_files
        test_*/*.in
        test_*/*.txt
        )
foreach(full_test_file_name ${test_files})
    configure_file(${full_test_file_name} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
endforeach(full_test_file_name)
