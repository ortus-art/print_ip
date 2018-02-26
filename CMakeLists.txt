
cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION_BUILD 1)
endif()

project(hello VERSION 1.0.${VERSION_BUILD})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

add_subdirectory(src)

# Unit test are enabled only for Debug or Coverage builds
if( CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "Coverage")

    #include(CodeCoverage)
    #setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_NAME}_test coverage)

    include(CTest)

    enable_testing()

    add_subdirectory(tests)

endif()


