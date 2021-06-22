#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
#include <tuple>
#include "data_define.h"
QueryResult::QueryResult(): occurence_time(0), query_word("DEFAULT_WORD") {
    occurence_time = 0;
    queried_lines.clear();
}

