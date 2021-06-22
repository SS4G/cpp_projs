#include <iostream>
#include <memory>
#include <vector>
#include "data_define.h"
void test_func1() {
    TextQuery tq = TextQuery("test_data.txt");
    string word;
    shared_ptr<QueryResult> qe_ptr; 
    while (cin >> word) {
        //cout << word;
        qe_ptr = tq.query(word);
        if (qe_ptr != nullptr) {
            qe_ptr -> print_result("---------------");
        } else {
            cout << word << " not found in text!" << endl;
        }
    }
}

void test_func2() {
    TextQuery tq = TextQuery(cin);
    string word = "the";
    shared_ptr<QueryResult> qe_ptr; 
    qe_ptr = tq.query(word);
    if (qe_ptr != nullptr) {
        qe_ptr -> print_result("---------------");
    } else {
        cout << word << " not found in text!" << endl;
    }
}

int main() {
    test_func2();
    //shared_ptr<vector<shared_ptr<string>>> srd = make_shared<vector<shared_ptr<string>>>();
    //cout << srd -> size() << endl;
    //srd -> clear();
    //cout <<  << endl;
}