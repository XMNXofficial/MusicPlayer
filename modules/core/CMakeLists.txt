cmake_minimum_required (VERSION 3.8)

project(MP_core)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(${PROJECT_NAME} SHARED core.cpp core.hpp)


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "link x64 BASS library")#64位机器
	target_include_directories(${PROJECT_NAME} PRIVATE ../../externalLib/bass)
	target_link_directories(${PROJECT_NAME} PUBLIC ../../externalLib/bass/win_64)
	install(FILES ../../externalLib/bass/win_64/bass.dll DESTINATION ${CMAKE_BINARY_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC bass.lib)
else()
    message(STATUS "link x86 BASS library")#32位机器
	target_include_directories(${PROJECT_NAME} PRIVATE /externalLib/bass)
	target_link_directories(${PROJECT_NAME} PUBLIC /externalLib/bass/win_32)
	install(FILES ../../externalLib/bass/win_64/bass.dll DESTINATION ${CMAKE_BINARY_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC bass.lib)
endif()

