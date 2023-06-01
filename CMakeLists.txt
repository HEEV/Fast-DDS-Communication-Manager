cmake_minimum_required(VERSION 3.15)

project("CommunicationManager")
add_library(${PROJECT_NAME} STATIC)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(lib)
add_subdirectory(src)
target_include_directories(${PROJECT_NAME}
    PRIVATE
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET fmt PROPERTY CXX_STANDARD 20)
if(MSVC)
    set_property(TARGET fmt PROPERTY COMPILE_OPTIONS /permissive)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC fastrtps fastcdr fmt::fmt-header-only)
