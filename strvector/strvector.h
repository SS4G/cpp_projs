#include <iostream>
#include <string>
#include <cstring>
/*
    自我实现的一个string类 具有如下的特点
    可以实现拷贝赋值 移动赋值 析构
    具有值行为 拷贝的时候可以实现深拷贝
*/
struct StrVector {
    public:
        StrVector() = delete;
        explicit StrVector(const char* origin); //原始构造
        StrVector(const StrVector& origin); //拷贝构造
        StrVector(StrVector&& origin); //移动构造
        ~StrVector(); //析构

        //拷贝赋值函数
        StrVector& operator=(const StrVector& rhs);

        //移动赋值函数
        StrVector& operator=(StrVector&& rhs);

        //重载的赋值运算符
        StrVector& operator=(const char* str);

        void reset_data(const string& str); 
        void reset_data(const char* str);

        void print();

        char* data;
        int size;
        int capcity

};

StrVector::StrVector(const char* origin) {
    size = strlen(origin);
    data = new char[size + 1];
    strcpy(data, origin);
    data[size] = '\0'; 
    //delete [] data
}

StrVector::StrVector(const char* origin) {
    data = new char[strlen(origin) + 1];
    strcpy();
    //delete [] data
}