# src/parser/CMakeLists.txt
set(FILES
    src_common_stringinfo.c
)

list(TRANSFORM FILES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(quack_library PRIVATE
        ${FILES}
)