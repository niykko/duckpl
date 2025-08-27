add_subdirectory(libpg_query)

add_library(quack_library STATIC
        quack_extension.cpp
        $<TARGET_OBJECTS:pl_pg_query>
)

target_include_directories(quack_library PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/libpg_query/include
)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES}
        $<TARGET_OBJECTS:pl_pg_query>
        $<TARGET_OBJECTS:quack_library>
        PARENT_SCOPE
)