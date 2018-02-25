cmake_minimum_required(VERSION 3.2)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(PROJETC_TEST ${PROJECT_NAME}_test)

add_executable(${PROJETC_TEST} test.cpp)


set_target_properties(${PROJETC_TEST} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(${PROJETC_TEST} PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)
target_include_directories(${PROJETC_TEST} PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_BINARY_DIR}/src
)

target_link_libraries(${PROJETC_TEST} ${PROJECT_NAME}_lib ${Boost_LIBRARIES})



add_test(test_version_valid ${PROJETC_TEST})
