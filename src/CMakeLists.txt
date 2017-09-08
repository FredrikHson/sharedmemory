cmake_minimum_required(VERSION 3.4)

project(sharedmemory)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


include_directories(
    "."
    )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

add_executable(${CMAKE_PROJECT_NAME}_client client.cpp)
add_executable(${CMAKE_PROJECT_NAME}_server server.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}_server
    rt
    )
install(TARGETS ${CMAKE_PROJECT_NAME}_server RUNTIME DESTINATION bin)

target_link_libraries(${CMAKE_PROJECT_NAME}_client
    rt
    )
install(TARGETS ${CMAKE_PROJECT_NAME}_client RUNTIME DESTINATION bin)
# uninstall target
#configure_file(
#	"${CMAKE_MODULE_PATH}/cmake_uninstall.cmake"
#	"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
#	IMMEDIATE @ONLY)
#
#add_custom_target(uninstall
#	COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

find_program(iwyu_path NAMES include-what-you-use iwyu)
if(iwyu_path)
    set_property(TARGET ${CMAKE_PROJECT_NAME}_server PROPERTY C_INCLUDE_WHAT_YOU_USE ${iwyu_path})
    set_property(TARGET ${CMAKE_PROJECT_NAME}_server PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})
    set_property(TARGET ${CMAKE_PROJECT_NAME}_client PROPERTY C_INCLUDE_WHAT_YOU_USE ${iwyu_path})
    set_property(TARGET ${CMAKE_PROJECT_NAME}_client PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})
endif()
