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

string QueryResult::tostring() {
    ostringstream os;
    os << query_word << " occurence_time:" << occurence_time << "\n";
    for (auto& pair: queried_lines) {
        os << "line(" << pair.first << ") " << *(pair.second) << "\n";
    }   
    return os.str();
}

void QueryResult::print_result(string sep_line) {
    cout << sep_line << endl;
    cout << tostring();
}
