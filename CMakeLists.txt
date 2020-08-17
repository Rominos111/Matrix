set(DEBUG)
# set(RELEASE)
# set(ASM_PRE)

########################################################################################################################

cmake_minimum_required(VERSION 3.10)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

if (RELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -O3 -s")
elseif (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
endif()

if (ASM_PRE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
endif()

########################################################################################################################

project(Matrix)

include_directories("${PROJECT_BINARY_DIR}")

include_directories(./include)

add_executable(Matrix src/main.cpp include/main.h src/matrix.cpp include/matrix.h)
