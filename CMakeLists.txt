################################################################################
#
#  Copyright (c) 2010-2024 Belledonne Communications SARL.
# 
#  This file is part of linphone-desktop
#  (see https://www.zuppi.site).
# 
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program. If not, see <http://www.gnu.org/licenses/>.
#
################################################################################

cmake_minimum_required(VERSION 3.22)

# Set the path for Qt6 and explicitly add the CMake module path
set(CMAKE_PREFIX_PATH "/mingw64/lib/cmake/Qt6")
set(CMAKE_MODULE_PATH "/mingw64/lib/cmake/Qt6")
set(Qt6_DIR "/mingw64/lib/cmake/Qt6") # Explicitly set Qt6_DIR

# Debugging: Print paths
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
message(STATUS "Qt6_DIR: ${Qt6_DIR}")

project(linphoneqt)

# Include necessary CMake modules
include(GNUInstallDirs)
include(CheckCXXCompilerFlag)
include(Linphone/application_info.cmake)

set(CMAKE_CXX_STANDARD 17)

if(LINPHONEAPP_INSTALL_PREFIX)
  set(APPLICATION_OUTPUT_DIR "${LINPHONEAPP_INSTALL_PREFIX}")
else()
  set(APPLICATION_OUTPUT_DIR "${CMAKE_BINARY_DIR}/OUTPUT")
endif()

set(CMAKE_INSTALL_PREFIX "${APPLICATION_OUTPUT_DIR}")

# Force find_package to search explicitly in the Qt6 directory
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui HINTS "/mingw64/lib/cmake/Qt6")

if(NOT Qt6_FOUND)
  message(FATAL_ERROR "Qt6 was not found. Ensure Qt6 is installed and Qt6_DIR is set correctly.")
endif()

# Debugging: Confirm found components
message(STATUS "Qt6 Components Found: Core, Widgets, Gui")

# Set application details
set(LINPHONEAPP_APPLICATION_NAME "Zuppi6" CACHE STRING "Application name")
set(LINPHONEAPP_EXECUTABLE_NAME "linphone6" CACHE STRING "Executable name")

# Add custom targets and dependencies
add_custom_target(linphone-deps)

function(add_linphone_app)
  set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
  add_subdirectory("Zuppi")
endfunction()

add_linphone_app()

include(cmake/install/install.cmake)

