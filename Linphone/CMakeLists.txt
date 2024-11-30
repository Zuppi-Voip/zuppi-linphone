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

# Set the correct path for Qt6
set(CMAKE_PREFIX_PATH "C:/msys64/mingw64/lib/cmake/Qt6")

# Debugging: Print CMAKE_PREFIX_PATH to ensure it's being used correctly
message(STATUS "Using CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

get_cmake_property(vars CACHE_VARIABLES)
foreach(var ${vars})
	get_property(currentHelpString CACHE "${var}" PROPERTY HELPSTRING)
	if("${currentHelpString}" MATCHES "No help, variable specified on the command line." OR "${currentHelpString}" STREQUAL "")
		list(APPEND USER_ARGS "-D${var}=${${var}}")
		if( "${var}" STREQUAL "CMAKE_PREFIX_PATH")
			set(PREFIX_PATH ";${${var}}")
		endif()
	elseif("${var}" STREQUAL "CMAKE_GENERATOR_PLATFORM" AND NOT("${${var}}" STREQUAL ""))
		message(STATUS "User-Setting Platform to ${${var}}")
	endif()
endforeach()
if(ENABLE_BUILD_VERBOSE)
	message("User Args : ${USER_ARGS}")
endif()

if(POLICY CMP0149)
    cmake_policy(SET CMP0149 NEW)
endif()

if(POLICY CMP0141)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT Embedded)
    cmake_policy(SET CMP0141 NEW)
endif()

project(linphoneqt)

# Include necessary directories
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

if( APPLE )
	set(LINPHONEAPP_MACOS_ARCHS "arm64" CACHE STRING "MacOS architectures to build: comma-separated list of values in [arm64, x86_64]")
	set(LINPHONESDK_BUILD_TYPE "Default")
	set(ENABLE_FAT_BINARY "ON")

	set(CMAKE_INSTALL_BINDIR "${APPLICATION_NAME}.app/Contents/MacOS")
	set(CMAKE_INSTALL_LIBDIR "${APPLICATION_NAME}.app/Contents/Frameworks")
	set(CMAKE_INSTALL_INCLUDEDIR "${APPLICATION_NAME}.app/Contents/Resources/include")
	set(CMAKE_INSTALL_DATAROOTDIR "${APPLICATION_NAME}.app/Contents/Resources/share")

	if( NOT CMAKE_OSX_DEPLOYMENT_TARGET)
		set(CMAKE_OSX_DEPLOYMENT_TARGET "12.3")
	endif()
	set(LINPHONESDK_MACOS_ARCHS ${LINPHONEAPP_MACOS_ARCHS})
	set(CMAKE_OSX_ARCHITECTURES ${LINPHONESDK_MACOS_ARCHS} CACHE STRING "")
elseif(WIN32)
    set(LINPHONESDK_BUILD_TYPE "Default")
else()
endif()

if(NOT LINPHONE_OUTPUT_DIR)
	set(LINPHONE_OUTPUT_DIR "${CMAKE_INSTALL_PREFIX}")
endif()

if( NOT QTKEYCHAIN_OUTPUT_DIR)
	set(QTKEYCHAIN_OUTPUT_DIR "${CMAKE_INSTALL_PREFIX}")
endif()

if (POLICY CMP0071)
    cmake_policy(SET CMP0071 NEW)
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/OUTPUT" CACHE PATH "Default linphone-app installation prefix" FORCE)
	set(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT FALSE)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to 'RelWithDebInfo' as none was specified")
	set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo" FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo")
endif()

# ------------------------------------------------------------------------------
#				SET OPTIONS
# ------------------------------------------------------------------------------
set(OPTION_LIST "")
function(add_option _OPTION_LIST OPTION DESC VALUE)
	option(${OPTION} ${DESC} ${VALUE})
	list(APPEND _OPTION_LIST ${${_OPTION_LIST}} "-D${OPTION}=${${OPTION}}")
	set(${${_OPTION_LIST}} ${_OPTION_LIST} PARENT_SCOPE)
endfunction()

function(add_cache _OPTION_LIST OPTION DESC VALUE)
	set(${OPTION} ${VALUE} CACHE STRING ${DESC})
	list(APPEND _OPTION_LIST ${${_OPTION_LIST}} "-D${OPTION}=${${OPTION}}")
	set(${${_OPTION_LIST}} ${_OPTION_LIST} PARENT_SCOPE)
endfunction()

set(LINPHONEAPP_APPLICATION_NAME "Zuppi6" CACHE STRING "Application name" )
set(LINPHONEAPP_EXECUTABLE_NAME "linphone6" CACHE STRING "Executable name" )

# Qt6 is required
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

if(NOT Qt6_FOUND)
	message(FATAL_ERROR "Qt6 was not found. Make sure Qt6 is installed and CMAKE_PREFIX_PATH is set correctly.")
endif()

# Debugging: Confirm found components
message(STATUS "Qt6 Components Found: Core, Widgets, Gui")

set(LINPHONEAPP_BUILD_TYPE "Default" CACHE STRING "Type of build")
set_property(CACHE LINPHONEAPP_BUILD_TYPE PROPERTY STRINGS "Default" "Macos" "Normal")

if(LINPHONEAPP_BUILD_TYPE STREQUAL "Default")
    if(APPLE)
        set(LINPHONEAPP_BUILD_TYPE "Macos")
    else()
        set(LINPHONEAPP_BUILD_TYPE "Normal")
    endif()
endif()

add_custom_target(linphone-deps)

function(add_linphone_app)
	set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
	add_subdirectory("Zuppi")
endfunction()
add_linphone_app()

include(cmake/install/install.cmake)
