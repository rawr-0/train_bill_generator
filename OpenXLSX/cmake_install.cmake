# Install script for directory: /cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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
  set(CMAKE_OBJDUMP "/usr/bin/objdump.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/OpenXLSX-Exports.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/IZipArchive.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLCell.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLCellIterator.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLCellRange.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLCellReference.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLCellValue.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLColor.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLColumn.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLCommandQuery.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLConstants.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLContentTypes.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLDateTime.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLDocument.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLException.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLFormula.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLIterator.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLProperties.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLRelationships.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLRow.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLRowData.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLSharedStrings.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLSheet.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLWorkbook.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLXmlData.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLXmlFile.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLXmlParser.hpp"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/headers/XLZipArchive.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX" TYPE FILE FILES "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/OpenXLSX.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/cygdrive/c/Users/User/CLionProjects/xlsx/output/libOpenXLSXd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/OpenXLSXConfig.cmake"
    "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/OpenXLSX/OpenXLSXConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake"
         "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/CMakeFiles/Export/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/CMakeFiles/Export/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "/cygdrive/c/Users/User/CLionProjects/xlsx/OpenXLSX/CMakeFiles/Export/lib/cmake/OpenXLSX/OpenXLSXTargets-debug.cmake")
  endif()
endif()

