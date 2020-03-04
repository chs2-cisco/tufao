# Fix CMake for standalone build
# Nov 8, 2016, Jukka Lehtniemi (Cisco Systems, Inc.)

# BTUC-8049: Remove support for building against Qt 4
# Mar 31, 2015, Juho Frits (Cisco Systems, Inc.)

# BTUC-1392: Use CMake policy CMP0020 only if it exists
# Jan 15, 2014, Juho Frits (Cisco Systems, Inc.)

# BTUC-1392: Set CMake policy regarding Qt::WinMain
# Jan 14, 2014, Juho Frits (Cisco Systems, Inc.)

# BTUC-1392: Qt 5 build fixes for Windows
# Jan 3, 2014, Juho Frits (Cisco Systems, Inc.)

# BTUC-1392: set automoc on for tufao
# Dec 31, 2013, Kimmo Karvinen (Cisco Systems, Inc.)

# BTUC-1392: Qt 4/5 CMakeLists.txt fixes to tufao
# Dec 31, 2013, Kimmo Karvinen (Cisco Systems, Inc.)

# BTUC-2604: added Tufao framework to extern (now built when running standalone extern build).
# Pre-built dll+lib for win32 added also, still need binaries for osx.
# Jun 5, 2013, Teemu Patja (Cisco Systems, Inc.)

# Project Tufão
project(tufao)
cmake_minimum_required(VERSION 2.8.9)
if(POLICY CMP0020)
	cmake_policy(SET CMP0020 OLD)
endif()

find_package(Qt5 5.0 COMPONENTS Core Network REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(BUFFER_SIZE 128 CACHE STRING
    "The default buffer size (in bytes) used by Tufão")
add_definitions(-DBUFFER_SIZE=${BUFFER_SIZE})

# Install info
set(TUFAO_VERSION_MAJOR 0)
set(TUFAO_VERSION_MINOR 6)
set(TUFAO_VERSION_PATCH 0)
set(TUFAO_VERSION ${TUFAO_VERSION_MAJOR}.${TUFAO_VERSION_MINOR}.${TUFAO_VERSION_PATCH})
set(TUFAO_BRIEF "An asynchronous web framework for C++ built on top of Qt")
set(includedir include)
set(libdir lib)

# Targets
add_subdirectory(src)
add_subdirectory(include)

