#include "MyString.h"

using namespace std;

int MyString::length() {
    return len;
}

unsigned char* MyString::subString(int start, int count) {
    if (start < 0 || start >= len) return nullptr;
    if (start + count > len) count = len - start;

    unsigned char* res = new unsigned char[count + 1];
    for (int i = 0; i < count; i++) {
        res[i] = data[start + i];
    }
    res[count] = '\0';
    return res;
}

MyString operator + (const char* sstring, const MyString& my_string) {
    MyString res;

    int newLen = 0;
    int idx = 0;

    if (sstring != nullptr) {
        while (sstring[newLen] != '\0') {
            newLen++;
        }
    }

    delete[]res.data;

    res.len = newLen + my_string.len;
    res.data = new unsigned char[res.len + 1];

    for (int i = 0; i < newLen; i++) res.data[i] = static_cast<unsigned char>(sstring[i]);
    for (int i = 0; i < my_string.len; i++) res.data[newLen + i] = my_string.data[i];

    res.data[res.len] = '\0';

    return res;
}

bool MyString::insert(int pos, unsigned char* strToInsert) {
    if (pos < 0 || pos > len || !strToInsert) return false;

    int strLen = 0;
    while (strToInsert[strLen] != '\0') strLen++;
    if (strLen == 0) return true;

    unsigned char* newData = new unsigned char[len + strLen + 1];

    for (int i = 0; i < pos; i++) newData[i] = data[i];
    for (int i = 0; i < strLen; i++) newData[pos + i] = strToInsert[i];
    for (int i = pos; i < len; i++) newData[strLen + i] = data[i];

    newData[len + strLen] = '\0';
    data = newData;
    len += strLen;
    return true;
}

bool MyString::erase(int start, int size) {
    if (start < 0 || start >= len || size <= 0) return false;
    if (start + size > len) size = len - start;

    unsigned char* newData = new unsigned char[len - size + 1];
    for (int i = 0; i < start; i++) newData[i] = data[i];
    for (int i = start + size; i < len; i++) newData[i - size] = data[i];

    newData[len - size] = '\0';
    data = newData;
    len -= size;
    return true;
}

bool MyString::replace(int pos, int size, unsigned char* strToReplace) {
    if (erase(pos, size)) {
        return insert(pos, strToReplace);
    }
    return false;
}

int MyString::find(int pos, unsigned char* strToSearch) {
    if (pos < 0 || pos >= len || !strToSearch) return -1;

    int strLen = 0;
    while (strToSearch[strLen] != '\0') strLen++;
    if (strLen == 0) return pos;

    for (int i = pos; i <= len - strLen; i++) {
        bool match = true;
        for (int j = 0; j < strLen; j++) {
            if (data[i + j] != strToSearch[j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return -1;
}

istream& operator>>(istream& is, MyString& M) {
    char buffer[1024];
    cin.getline(buffer, 100);

    int newLen = 0;
    while (buffer[newLen] != '\0') newLen++;

    delete[]M.data;

    M.len = newLen;
    M.data = new unsigned char[newLen + 1];
    for (int i = 0; i < newLen; i++) M.data[i] = buffer[i];
    M.data[newLen] = '\0';
    return is;
}

ostream& operator<<(ostream& os, const MyString& str) {
    if (str.data) os << reinterpret_cast<char*>(str.data);
    return os;
}

ostream& operator<<(ostream& os, unsigned char* str) {
    if (str) os << reinterpret_cast<char*>(str);
    return os;
}

MyString MyString::operator+(const char* other) {
    MyString res;
    int otherLen = 0;
    while (other[otherLen] != '\0') otherLen++;

    res.len = len + otherLen;
    res.data = new unsigned char[res.len + 1];
    for (int i = 0; i < len; i++) res.data[i] = data[i];
    for (int i = 0; i < otherLen; i++) res.data[len + i] = other[i];
    res.data[res.len] = '\0';
    return res;
}

bool MyString::insert(int pos, const char* str) {
    return insert(pos, (unsigned char*)str);
}
bool MyString::replace(int pos, int size, const char* str) {
    return replace(pos, size, (unsigned char*)str);
}
int MyString::find(int pos, const char* str) {
    return find(pos, (unsigned char*)str);
}

unsigned char& MyString::operator [](int index) {
    return data[index];
}

MyString MyString::operator+(MyString& other) {
    MyString res;
    delete[] res.data;

    res.len = len + other.len;
    res.data = new unsigned char[res.len + 1];

    for (int i = 0; i < len; i++) {
        res.data[i] = data[i];
    }

    for (int i = 0; i < other.len; i++) {
        res.data[len + i] = other.data[i];
    }

    res.data[res.len] = '\0';
    return res;
}


bool MyString::operator > (const MyString& sub) const {
    int i = 0, j = 0;
    while (i < len && j < sub.len) {
        if (data[i] > sub.data[j]) return true;
        if (data[i] < sub.data[j]) return false;
        i++; j++;
    }
    return len > sub.len;
}

bool MyString::operator < (const MyString& sub) const {
    int i = 0, j = 0;
    while (i < len && j < sub.len) {
        if (data[i] < sub.data[j]) return true;
        if (data[i] > sub.data[j]) return false;
        i++; j++;
    }
    return len < sub.len;
}

bool MyString::operator == (const MyString& sub) const {
    if (len != sub.len) return false;
    for (int i = 0; i < len; i++) {
        if (data[i] != sub.data[i]) return false;
    }
    return true;
}

bool MyString::operator != (const MyString& other) const {
    if (len != other.len) return true;
    for (int i = 0; i < len; i++) {
        if (data[i] != other.data[i]) return true;
    }
    return false;
}

bool MyString::operator >= (const MyString& other) const {
    for (int i = 0; i < len && i < other.len; i++) {
        if (data[i] > other.data[i]) return true;
        if (data[i] < other.data[i]) return false;
    }
    return len >= other.len;
}

bool MyString::operator <= (const MyString& other) const {
    for (int i = 0; i < len && i < other.len; i++) {
        if (data[i] < other.data[i]) return true;
        if (data[i] > other.data[i]) return false;
    }
    return len <= other.len;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {

        delete[] data;

        len = other.len;
        data = new unsigned char[len + 1];
        for (int i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
        data[len] = '\0';
    }
    return *this;
}

void MyString::set(int _size) {
    if (_size < 0 || _size == len) {
        return;
    }

    if (_size == 0) {
        delete[] data;
        len = 0;
        data = new unsigned char[1];
        data[0] = '\0';
        return;
    }

    unsigned char* newData = new unsigned char[_size + 1];

    if (_size < len) {
        for (int i = 0; i < _size; i++) {
            newData[i] = data[i];
        }
    }
    else if (_size > len) {
        for (int i = 0; i < len; i++) {
            newData[i] = data[i];
        }
        for (int i = len; i < _size; i++) {
            newData[i] = '-';
        }
    }

    newData[_size] = '\0';

    delete[] data;
    data = newData;
    len = _size;
}

void MyString::set(const char* s) {
    int len_s = 0;
    bool flag = true;

    while (s[len_s] != '\0') {
        if (s[len_s] != data[len_s]) {
            flag = false;
        }
        len_s++;
    }
    if (flag == true) return;

    if (len_s == 0) {
        delete[]data;
        len = 0;
        data = new unsigned char[1];
        data[0] = '\0';
        return;
    }

    delete[]data;
    len = len_s;
    data = new unsigned char[len + 1];


    for (int i = 0; i < len; i++) {
        data[i] = s[i];
    }

    data[len] = '\0';
}