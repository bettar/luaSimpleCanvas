#-------------------
set(CLI1_NAME cliAllKeys)
message("=== TARGET: ${CLI1_NAME}")
add_executable(${CLI1_NAME}
	allKeys/diag1.cpp allKeys/diag1.h
	allKeys/main.cpp)
	
add_dependencies(${CLI1_NAME} ${LIB_NAME})

target_compile_definitions(${CLI1_NAME} PUBLIC STAND_ALONE)

#target_compile_features(${CLI1_NAME} PRIVATE cxx_std_17)
target_include_directories(${CLI1_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${CLI1_NAME} PRIVATE ${LIB_NAME})

#---------------------
set(CLI2_NAME cliMajor)
message("=== TARGET: ${CLI2_NAME}")
add_executable(${CLI2_NAME}
	major/main.cpp
	major/major.cpp major/major.h
	major/maj_arp.cpp major/maj_arp.h)

add_dependencies(${CLI2_NAME} ${LIB_NAME})

target_compile_definitions(${CLI2_NAME} PUBLIC STAND_ALONE)

target_include_directories(${CLI2_NAME} PRIVATE 
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${CLI2_NAME} PRIVATE ${LIB_NAME})

#---------------------
set(CLI3_NAME cliMinor)
message("=== TARGET: ${CLI3_NAME}")
add_executable(${CLI3_NAME}
	minor/main.cpp
	minor/minor.cpp minor/minor.h
	minor/min_arp.cpp minor/min_arp.h)

add_dependencies(${CLI3_NAME} ${LIB_NAME})

target_include_directories(${CLI3_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${CLI3_NAME} PRIVATE ${LIB_NAME})