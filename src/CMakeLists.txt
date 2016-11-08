if(QT4_FOUND)
    include(${QT_USE_FILE})
endif()

# Source files
set(tufao_SRC
    httpserver.cpp
    httpserverrequest.cpp
    httpserverresponse.cpp
    httpsserver.cpp
    url.cpp
    querystring.cpp
    priv/tcpserverwrapper.cpp
    priv/reasonphrase.cpp
    priv/http_parser.c
    websocket.cpp
    abstractmessagesocket.cpp
    httpfileserver.cpp
    abstracthttpserverrequesthandler.cpp
    httpserverrequestrouter.cpp
    httppluginserver.cpp
    headers.cpp
    priv/rfc1123.cpp
    priv/rfc1036.cpp
    priv/asctime.cpp
    sessionstore.cpp
    simplesessionstore.cpp
    urlrewriterhandler.cpp
    abstracthttpupgradehandler.cpp
    httpupgraderouter.cpp
)

# MOC header files
set(tufao_MOC_HDRS
    httpserver.h
    httpserverrequest.h
    httpserverresponse.h
    httpsserver.h
    priv/tcpserverwrapper.h
    websocket.h
    abstractmessagesocket.h
    httpfileserver.h
    abstracthttpserverrequesthandler.h
    httpserverrequestrouter.h
    httppluginserver.h
    sessionstore.h
    simplesessionstore.h
    urlrewriterhandler.h
    abstracthttpupgradehandler.h
    httpupgraderouter.h
)

# Build info
add_definitions(-DTUFAO_LIBRARY
    -Wall
)

add_library(tufao SHARED ${tufao_SRC})
if(QT4_FOUND)
    target_link_libraries(tufao ${QT_LIBRARIES})
elseif(Qt5_FOUND)
    qt5_use_modules(tufao Core Network)
endif()

set_target_properties(
    tufao
    PROPERTIES
    SOVERSION ${TUFAO_VERSION_MAJOR}
    VERSION ${TUFAO_VERSION}
    VS_KEYWORD Qt4VSv1.0
)

install(TARGETS tufao
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION lib
)
# install(DIRECTORY .
#      DESTINATION "${includedir}/Tufao"
#      COMPONENT development
#      FILES_MATCHING PATTERN *.h
#      PATTERN doc EXCLUDE
#      PATTERN priv EXCLUDE
# )
