add_library(quack_library OBJECT
        quack_extension.cpp
)

# Include libpg_query headers
target_include_directories(quack_library PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/libpg_query
)


# Wrap libpg_query.a as a proper CMake target
add_library(libpg_query STATIC IMPORTED)
set_target_properties(libpg_query PROPERTIES
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/third_party/libpg_query/libpg_query.a
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/third_party/libpg_query
)

# Now create a proper STATIC extension library for DuckDB
add_library(newlib STATIC
        $<TARGET_OBJECTS:quack_library>
)

# Link the static libpg_query.a here
target_link_libraries(newlib PRIVATE libpg_query)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES}
        $<TARGET_OBJECTS:quack_library>
        PARENT_SCOPE
)