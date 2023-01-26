
include(cmake/GetDDSDeps.cmake)
add_subdirectory(Fast-DDS)

if(NOT fmt)
    add_subdirectory(fmt)
endif()
