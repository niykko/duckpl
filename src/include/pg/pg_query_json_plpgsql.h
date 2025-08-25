#pragma once
#include "postgres/include/plpgsql.h"

char * plpgsqlToJSON(PLpgSQL_function* func);

