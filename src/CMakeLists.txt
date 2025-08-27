# Build own modified version of duckdb's libpg_query
add_subdirectory(libpg_query)

# Build static library (do not build against pl_pg_query, it will not propagate to ${ALL_OBJECT_FILES} because its static)
add_library(quack_library STATIC
        quack_extension.cpp
)

target_include_directories(quack_library PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/libpg_query/include
)

# Instead, send pl_pg_query objects up explicitly
set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES}
        $<TARGET_OBJECTS:pl_pg_query>
        $<TARGET_OBJECTS:quack_library>
        PARENT_SCOPE
)