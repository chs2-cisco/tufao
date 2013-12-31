# Project Tufão
project(tufao)
cmake_minimum_required(VERSION 2.8.9)
find_package(Qt4 4.7 COMPONENTS QtCore QtNetwork QUIET)
if(NOT QT4_FOUND)
    find_package(Qt5 5.0 COMPONENTS Core Network REQUIRED)
endif()

if(NOT QT4_FOUND AND NOT Qt5_FOUND)
    message(FATAL_ERROR "*********   No Qt version found, stopping!!!   *********")
else()
    message("tufao using Qt version ${QTVERSION}")
endif()

set(BUFFER_SIZE 128 CACHE STRING
    "The default buffer size (in bytes) used by Tufão")
add_definitions(-DBUFFER_SIZE=${BUFFER_SIZE})

# Install info
set(TUFAO_VERSION_MAJOR 0)
set(TUFAO_VERSION_MINOR 6)
set(TUFAO_VERSION_PATCH 0)
set(TUFAO_VERSION ${TUFAO_VERSION_MAJOR}.${TUFAO_VERSION_MINOR}.${TUFAO_VERSION_PATCH})
set(TUFAO_BRIEF "An asynchronous web framework for C++ built on top of Qt")
set(includedir include/tufao-${TUFAO_VERSION_MAJOR})
set(libdir lib)

# Targets
add_subdirectory(src)
#add_subdirectory(include)

