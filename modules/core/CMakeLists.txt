cmake_minimum_required (VERSION 3.8)

project(MP_core)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(${PROJECT_NAME} SHARED core.hpp core.cpp)


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

include(D:/Dev_Libs/vcpkg/scripts/buildsystems/vcpkg.cmake)
include(FindIconv) # Attempted without this line also
find_package(Iconv)
message("找到了吗:"${Iconv_FOUND})
target_include_directories(${PROJECT_NAME} PUBLIC ${Iconv_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${Iconv_LIBRARIES})#D:/Dev_Libs/vcpkg/installed/x64-windows/debug/lib/iconv.lib
string(REPLACE "debug/lib/iconv.lib" "debug/bin/charset-1.dll" DLL_PATH_charset ${Iconv_LIBRARY})#变量:DLL_PATH_charset
string(REPLACE "debug/lib/iconv.lib" "debug/bin/iconv-2.dll" DLL_PATH_iconv ${Iconv_LIBRARY})#变量:DLL_PATH_iconv
install(FILES ${DLL_PATH_charset} DESTINATION ${CMAKE_BINARY_DIR})
install(FILES ${DLL_PATH_iconv} DESTINATION ${CMAKE_BINARY_DIR})
