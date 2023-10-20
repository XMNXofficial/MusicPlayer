cmake_minimum_required (VERSION 3.8)

project(MP_fileSys)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#导入第三方库
	#导入native-file-dialog-extended
		add_subdirectory(../../externalLib/nfd nfd)

add_library(${PROJECT_NAME} SHARED fileSys.hpp fileSys.cpp)

#链接第三方库
	#native-file-dialog-extended
		target_include_directories(${PROJECT_NAME} PUBLIC ../../externalLib/nfd)
		target_link_libraries(${PROJECT_NAME} PUBLIC nfd)