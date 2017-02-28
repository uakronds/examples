
# Requires the `cmake` command to be at least version 2.8.
cmake_minimum_required(VERSION 2.8)


# Declares the project name and its implementation language. "CXX"
# means "C++".
project(avl CXX)

# Update the C++ compiler flags so that we use C++11, not the older
# version of the language, C++03. GCC-4.9, the default compiler in
# our labs works with this setting. So does the default compiler on
# an up-to-date Mac OS X system.
set(CMAKE_CXX_FLAGS -std=c++11)


# Declare that we want to build an executable program named "ordered"
add_executable(avl avl.cpp)


# DO NOT REMOVE OR MODIFY THIS MACRO.
#
# This creates a new target for the make program. After
# including this, you can write:
#
#     make printout
#
# And the build system will assemble a PDF containing the
# formatted text in the files listed above. The PDF will
# be created in the build directory and is named "printout.pdf".
#
# To use this, add the following to this file:
#
#     add_printout(f1.hpp f1.cpp f2.hpp f2.cpp ...)
#
# Where f1 and f2 are the files that you want to include
# in the printout. Note that header files should always
# precede their source files.
macro(add_printout)
  add_custom_target(printout
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND a2ps -Afill -o- ${ARGN} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
endmacro()
