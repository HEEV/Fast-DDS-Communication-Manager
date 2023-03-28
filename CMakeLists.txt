cmake_minimum_required(VERSION 3.15)

project("CommunicationManager")
add_library(${PROJECT_NAME} STATIC)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(lib)
add_subdirectory(src)

set_property(TARGET fmt PROPERTY CXX_STANDARD 20)
if(MSVC)
    set_property(TARGET fmt PROPERTY COMPILE_OPTIONS /permissive)
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC fastrtps fastcdr fmt::fmt-header-only)
