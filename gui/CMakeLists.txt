set(APP_NAME wx2png)
message("=== TARGET: ${APP_NAME}")
#message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

add_executable( ${APP_NAME} WIN32 MACOSX_BUNDLE
  main.cpp main.h
  fbp/MyFrameBase.cpp fbp/MyFrameBase.h
  MyFrame.cpp MyFrame.h
  MyPanel.cpp MyPanel.h

  diag1b.cpp diag1b.h

  ${PROJECT_SOURCE_DIR}/cli/major/major.cpp
  ${PROJECT_SOURCE_DIR}/cli/major/major.h
	${PROJECT_SOURCE_DIR}/cli/major/maj_arp.cpp
  ${PROJECT_SOURCE_DIR}/cli/major/maj_arp.h
  )

add_dependencies(${APP_NAME} ${LIB_NAME})

target_include_directories( ${APP_NAME} PUBLIC
    "fbp"
    ${PROJECT_SOURCE_DIR}/lib
    ${PROJECT_SOURCE_DIR}/cli/major
    ${LUA_INCLUDE_DIR})

target_link_libraries( ${APP_NAME}
    ${wxWidgets_LIBRARIES}
    ${LUA_LIBRARIES}
    ${LIB_NAME})

if (MINGW)
    target_link_libraries(${APP_NAME} opengl32.lib)
endif()