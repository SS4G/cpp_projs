#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
using namespace std;
struct QueryResult;
struct TextQuery {
    public:
        TextQuery();//创建一个空QueryResult
        TextQuery(string file_name); //从给定的文本文件中读取
        TextQuery(istream& is);

        void reload_data(istream& isp);
        void reload_data(string fileName);//从给定的文本文件中重新载入数据
        void reload_data();//从stdin中重新载入数据
        
        shared_ptr<QueryResult> query(string word); //在数据中查询给定词


        shared_ptr<vector<shared_ptr<string>>> text_lines; //文本行
        shared_ptr<unordered_map<string, unordered_set<int>>> word_line_number_map;
        shared_ptr<unordered_map<string, int>> word_cnt;

};

struct QueryResult {
    friend struct TextQuery; 
    public:
        /* data */
        QueryResult(); //创建一个空的查询结果
        string tostring(); //创建一个空的查询结果
        void print_result(string sep_line = "======================"); //创建一个空的查询结果

    private:
        string query_word;
        int occurence_time;
        vector<pair<int, shared_ptr<string>>> queried_lines;
};