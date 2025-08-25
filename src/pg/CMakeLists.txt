# src/parser/CMakeLists.txt
set(FILES
    pg_query_parse_plpgsql.c
    pg_query_json_plpgsql.c
    pg_query_json_helper.c
)

list(TRANSFORM FILES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

target_sources(quack_library PRIVATE
        ${FILES}
)
