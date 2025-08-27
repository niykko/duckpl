add_library(quack_library STATIC
        quack_extension.cpp
)


add_subdirectory(libpg_query)


# Link the static libpg_query.a here
target_link_libraries(quack_library PRIVATE libpg_query)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES}
        $<TARGET_OBJECTS:quack_library>
        PARENT_SCOPE
)