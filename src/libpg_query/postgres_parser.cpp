#include "postgres_parser.hpp"

#include "pg_functions.hpp"
#include "parser/parser.hpp"
#include "parser/scansup.hpp"
#include "common/keywords.hpp"

namespace duck_pl {

PostgresParser::PostgresParser() : success(false), parse_tree(nullptr), error_message(""), error_location(0) {}

void PostgresParser::Parse(const std::string &query) {
	duck_pl::pg_parser_init();
	duck_pl::parse_result res;
	duck_pl::pg_parser_parse(query.c_str(), &res);
	success = res.success;

	if (success) {
		parse_tree = res.parse_tree;
	} else {
		error_message = std::string(res.error_message);
		error_location = res.error_location;
	}
}

duckdb::vector<duck_pl::PGSimplifiedToken> PostgresParser::Tokenize(const std::string &query) {
	duck_pl::pg_parser_init();
	auto tokens = duck_pl::tokenize(query.c_str());
	duck_pl::pg_parser_cleanup();
	return std::move(tokens);
}

PostgresParser::~PostgresParser()  {
    duck_pl::pg_parser_cleanup();
}

duck_pl::PGKeywordCategory PostgresParser::IsKeyword(const std::string &text) {
	return duck_pl::is_keyword(text.c_str());
}

duckdb::vector<duck_pl::PGKeyword> PostgresParser::KeywordList() {
	// FIXME: because of this, we might need to change the libpg_query library to use duckdb::vector
	duckdb::vector<duck_pl::PGKeyword> tmp(duck_pl::keyword_list());
	return tmp;
}

void PostgresParser::SetPreserveIdentifierCase(bool preserve) {
	duck_pl::set_preserve_identifier_case(preserve);
}

}
