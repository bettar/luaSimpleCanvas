cmake_minimum_required(VERSION 3.20)

project (simpleCanvas
    VERSION 1.0.0
    HOMEPAGE_URL "https://github.com/bettar/luaSimpleCanvas"
    DESCRIPTION "Create 2D drawings from Lua scripts"
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")

message("CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

#-------------------------------
find_package(wxWidgets REQUIRED)

message("wxWidgets_CONFIGURATION = ${wxWidgets_CONFIGURATION}")
message("wxWidgets_defines = ${wxWidgets_defines}")
message("wxWidgets_INCLUDE_DIRS = ${wxWidgets_INCLUDE_DIRS}")
message("wxWidgets_LIBRARIES = ${wxWidgets_LIBRARIES}")
message("wxWidgets_DIR = ${wxWidgets_DIR}")
message("wxWidgets_CXX_FLAGS = ${wxWidgets_CXX_FLAGS}")

include(${wxWidgets_USE_FILE})

#-----------------------------------------------------------------------------
find_package(Lua REQUIRED)
message("Lua_VERSION: ${Lua_VERSION}")
message("LUA_INCLUDE_DIR: ${LUA_INCLUDE_DIR}")
message("LUA_LIBRARIES: ${LUA_LIBRARIES}")

#-------------------
set(LIB_NAME scEngine)
message("=== TARGET: ${LIB_NAME}")
add_library(${LIB_NAME} #SHARED
	lib/common.cpp lib/common.h
	lib/engineWx.cpp lib/engineWx.h
	lib/engineHgl.cpp lib/engineHgl.h
  )

target_include_directories(${LIB_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries( ${LIB_NAME} ${wxWidgets_LIBRARIES} )

#-----------------------------------------------------------------------------
# Recurse into subdirectories
FOREACH(SUBDIR cli gui lua)
  ADD_SUBDIRECTORY(${SUBDIR})
ENDFOREACH(SUBDIR)