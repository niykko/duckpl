add_library(quack_library OBJECT
        quack_extension.cpp
)
set(SUBDIRS
        pg
        postgres
)

foreach(subdir IN LISTS SUBDIRS)
    add_subdirectory(${subdir})
endforeach()
set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:quack_library>
        PARENT_SCOPE)