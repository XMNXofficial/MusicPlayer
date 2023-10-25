cmake_minimum_required (VERSION 3.8)

project(MP_extern)

include_directories(..)
include_directories(../core)
include_directories(../fileSys)


add_library(${PROJECT_NAME} extern.hpp extern.cpp)


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "link x64 BASS library")#64位机器
	target_include_directories(${PROJECT_NAME} PUBLIC ../../externalLib/bass)
	target_link_directories(${PROJECT_NAME} PUBLIC ../../externalLib/bass/win_64)
	install(FILES ../../externalLib/bass/win_64/bass.dll DESTINATION ${CMAKE_BINARY_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC bass.lib)
else()
    message(STATUS "link x86 BASS library")#32位机器
	target_include_directories(${PROJECT_NAME} PUBLIC ../../externalLib/bass)
	target_link_directories(${PROJECT_NAME} PUBLIC ../../externalLib/bass/win_32)
	install(FILES ../../externalLib/bass/win_64/bass.dll DESTINATION ${CMAKE_BINARY_DIR})
	target_link_libraries(${PROJECT_NAME} PUBLIC bass.lib)
endif()
