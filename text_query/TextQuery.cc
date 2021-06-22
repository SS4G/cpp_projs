#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
#include <algorithm>
#include "data_define.h"
using namespace std;

//注意 构造函数中调用其他的构造函数 需要在初始值列表的地方调用
TextQuery::TextQuery(string file_name): TextQuery() {
    //cout << __LINE__ << ":" << __func__ << endl; 
    reload_data(file_name);
}

TextQuery::TextQuery(istream& is): TextQuery() {
    reload_data(is);
}

TextQuery::TextQuery() {
    //cout << __LINE__ << ":" << __func__ << endl; 
    text_lines = make_shared<vector<shared_ptr<string>>>();
    //cout << __LINE__ << ":" << __func__ << text_lines -> size() << endl; 
    word_line_number_map = make_shared<unordered_map<string, unordered_set<int>>>();
    word_cnt = make_shared<unordered_map<string, int>>();
    //cout << __LINE__ << ":" << __func__ << endl; 
}

void TextQuery::reload_data(string file_name) {
    //cout << __LINE__ << ":" << __func__ << endl; 
    //cout << __LINE__ << ":" << __func__ << text_lines -> size() << endl; 
    text_lines -> clear();
    //cout << __LINE__ << ":" << __func__ << endl; 
    word_line_number_map -> clear();
    //cout << __LINE__ << ":" << __func__ << endl; 
    word_cnt ->clear();
    //cout << __LINE__ << ":" << __func__ << endl; 
    ifstream ifs(file_name);
    reload_data(ifs); //使用基类多态实现
}

void TextQuery::reload_data() {
    text_lines -> clear();
    word_line_number_map -> clear();
    word_cnt ->clear();
    reload_data(cin); //使用基类多态实现
}

void TextQuery::reload_data(istream& isp) {
    string line;
    int line_num = 0;
    while (getline(isp, line)) {
        //所有数据行使用shared_ptr存储
        shared_ptr<string> line_ptr = make_shared<string>(line);
        text_lines -> push_back(line_ptr); 

        istringstream is(line);
        string word;
        while(is >> word) {
            if (word_line_number_map -> find(word) == word_line_number_map -> end()) {
                unordered_set<int> tmp_set; //这里赋值了
                (*word_line_number_map)[word] = tmp_set;
                (*word_cnt)[word] = 0;
            }
            (*word_line_number_map)[word].insert(line_num);
            (*word_cnt)[word]++;
        }
        line_num++;
    }
}

//在当前textQuery数据库中查找word 找到就返回 对应的QueryResult shared_ptr 否则返回null
shared_ptr<QueryResult> TextQuery::query(string word) {
    if (word_line_number_map -> find(word) != word_line_number_map -> end()) {
        shared_ptr<QueryResult> query_result = make_shared<QueryResult>();
        query_result -> occurence_time = (*word_cnt)[word];
        query_result -> query_word = word;

        for (int line_num: word_line_number_map -> at(word)) {
            pair<int, shared_ptr<string>> pair_d = make_pair(line_num, (*text_lines)[line_num]);
            query_result -> queried_lines.push_back(pair_d);
            //按照行号排序
            auto func = [](const pair<int, shared_ptr<string>>& i1, pair<int, shared_ptr<string>>& i2) -> bool {return i1.first < i2.first;};
            sort((query_result -> queried_lines).begin(), query_result -> queried_lines.end(), func);
        }
        return query_result;
    }
    return nullptr;
}