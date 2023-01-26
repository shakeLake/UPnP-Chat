# Install script for directory: D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/upnp_chat")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private.cmake"
         "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/CMakeFiles/Export/53e9199ca912d8c63274af79c6df728e/miniupnpc-private.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/miniupnpc-private.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/CMakeFiles/Export/53e9199ca912d8c63274af79c6df728e/miniupnpc-private.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/libminiupnpc.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static.cmake"
         "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/CMakeFiles/Export/53e9199ca912d8c63274af79c6df728e/libminiupnpc-static.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc/libminiupnpc-static.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/CMakeFiles/Export/53e9199ca912d8c63274af79c6df728e/libminiupnpc-static.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/CMakeFiles/Export/53e9199ca912d8c63274af79c6df728e/libminiupnpc-static-relwithdebinfo.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniupnpc" TYPE FILE FILES
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/miniupnpc.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/miniwget.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/upnpcommands.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/igd_desc_parse.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/upnpreplyparse.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/upnperrors.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/upnpdev.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/miniupnpctypes.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/portlistingparse.h"
    "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/include/miniupnpc_declspec.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/miniupnpc" TYPE FILE FILES "D:/it's a cake/1/pr/upnp_chat/third-party/miniupnpc-2.2.4/miniupnpc-config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/it's a cake/1/pr/upnp_chat/build-debug/chat-build/upnp-build/miniupnpc-build/miniupnpc.pc")
endif()

