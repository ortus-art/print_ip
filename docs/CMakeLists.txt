cmake_minimum_required(VERSION 3.2)


list(APPEND PROJECT_DOXYGEN_INPUT 
    ${CMAKE_CURRENT_SOURCE_DIR}/MainPage.md 
)
set(PROJECT_DOXYGEN_README MainPage.md)


string(REPLACE ";" " " PROJECT_DOXYGEN_INPUT "${PROJECT_DOXYGEN_INPUT}")


configure_file(Doxyfile.in Doxyfile)