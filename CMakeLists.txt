
cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION_BUILD 1)
endif()

project(hello VERSION 1.0.${VERSION_BUILD})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)