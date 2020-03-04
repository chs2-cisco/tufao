# Fix CMake for standalone build
# Nov 8, 2016, Jukka Lehtniemi (Cisco Systems, Inc.)

# Extra include files

install(DIRECTORY .
    DESTINATION "${includedir}"
    COMPONENT development
    PATTERN CMakeLists.txt EXCLUDE
)
