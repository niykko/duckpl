add_library(quack_library STATIC
        quack_extension.cpp
)


add_subdirectory(libpg_query)

target_link_libraries(quack_library PRIVATE pl_pg_query)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES}
        $<TARGET_OBJECTS:quack_library>
        PARENT_SCOPE
)