cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#解决奇数个数中文在msvc上无法编译utf-8不带bom的代码文件
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

project ("MusicPlayer")

#导入hello_imgui
	add_subdirectory(externalLib/hello_imgui)
	list(APPEND CMAKE_MODULE_PATH ${HELLOIMGUI_CMAKE_PATH})
	include(hello_imgui_add_app)

add_subdirectory(modules)



#将源代码添加到此项目的可执行文件。
	hello_imgui_add_app (${PROJECT_NAME} "MusicPlayer.cpp" "MusicPlayer.hpp")




if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MusicPlayer PROPERTY CXX_STANDARD 20)
endif()


target_include_directories(${PROJECT_NAME} PUBLIC modules/core)
target_link_libraries(${PROJECT_NAME} PUBLIC MP_core)