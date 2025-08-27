//===----------------------------------------------------------------------===//
//                         DuckDB
//
// postgres_parser.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include <string>
#include <vector>
#include "nodes/pg_list.hpp"
#include "pg_simplified_token.hpp"
#include "duckdb/common/vector.hpp"

namespace duck_pl {
class PostgresParser {
public:
	PostgresParser();
	~PostgresParser();

	bool success;
	duck_pl::PGList *parse_tree;
	std::string error_message;
	int error_location;
public:
	void Parse(const std::string &query);
	static duckdb::vector<duck_pl::PGSimplifiedToken> Tokenize(const std::string &query);

	static duck_pl::PGKeywordCategory IsKeyword(const std::string &text);
	static duckdb::vector<duck_pl::PGKeyword> KeywordList();

	static void SetPreserveIdentifierCase(bool downcase);
};

}