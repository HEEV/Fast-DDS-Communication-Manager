
include(cmake/GetDDSDeps.cmake)
add_subdirectory(Fast-DDS)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/cpp-httplib
)
add_subdirectory(fmt)
