set(LUA_PKG_NAME luaPackage)
message("=== TARGET: ${LUA_PKG_NAME}")

add_library(${LUA_PKG_NAME} SHARED
	./main.cpp )

add_dependencies(${APP_NAME} ${LIB_NAME})

set_property(TARGET ${LUA_PKG_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(${LUA_PKG_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/lib
    ${LUA_INCLUDE_DIR})

target_link_libraries( ${LUA_PKG_NAME}
    ${LUA_LIBRARIES}
    ${LIB_NAME})
