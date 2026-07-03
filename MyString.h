#pragma once
#include <iostream>

using namespace std;

class MyString {
private:
    unsigned char* data ;
    int len ;
public:
    MyString() {
        data =  new unsigned char[1];
        len = 0;
        data[0] = '\0';
    }

    MyString(MyString& M) {
        len = M.len;
        data = new unsigned char[len + 1];
        for (int i = 0; i < len; i++) {
            data[i] = M.data[i];
        }
    }

    int length();
    unsigned char* subString(int, int);
    unsigned char* operator+(const MyString&);
    bool insert(int, unsigned char*);
    bool erase(int, int);
    bool replace(int, int, unsigned char*);
    int find(int, unsigned char*);

    friend istream& operator>>(istream& is, MyString& M);
    friend ostream& operator<<(ostream& os, const MyString& str);

    bool operator > (MyString);
    bool operator < (MyString); 
    bool operator == (MyString);
    bool operator != (const MyString);
    bool operator >= (const MyString&);
    bool operator <= (const MyString&);

    MyString operator+(const char* other);
    MyString operator+(MyString&);
    unsigned char& operator [](int);

    bool insert(int pos, const char* str);
    bool replace(int pos, int size, const char* str);
    int find(int pos, const char* str);

    ~MyString() {
        delete []data;
    }
};


