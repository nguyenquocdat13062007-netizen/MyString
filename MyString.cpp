#include "MyString.h"

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

//unsigned char* MyString::operator+(const MyString& other) {
//    int newLen = this->len + other.len;
//    unsigned char* res = new unsigned char[newLen + 1];
//
//    for (int i = 0; i < this->len; i++) res[i] = this->data[i];
//    for (int i = 0; i < other.len; i++) res[this->len + i] = other.data[i];
//    res[newLen] = '\0';
//
//    return res;
//}

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
    is >> buffer;

    int newLen = 0;
    while (buffer[newLen] != '\0') newLen++;

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

bool MyString::operator > (MyString sub)
{
    int i = 0, j = 0; 
    while(i < len && j < sub.len)
    {
        if (data[i++] > sub.data[j++]) return true;
        else if (data[i++] < sub.data[j++]) return false;
    }
    if (len > sub.len) return true;
    else return false;
    return false;
}
bool MyString::operator < (MyString sub)
{
    int i = 0, j = 0;
    while (i < len && j < sub.len)
    {
        if (data[i++] > sub.data[j++]) return false;
        else if (data[i++] < sub.data[j++]) return true;
    }
    if (len > sub.len) return false;
    else return true;
    return false;
}
bool MyString::operator == (MyString sub)
{
    if (len != sub.len) return false; 
    int i = 0, j = 0;
    while (i < len && j < len)
    {
        if (data[i++] != sub.data[j++]) return false;
    }
    return true;
}

bool MyString ::operator!= (const MyString& other) {
	if (len != other.len) return true;
	for (int i = 0; i < len; i++) {
		if (data[i] != other.data[i]) return true;
	}
	return false;
}

bool MyString::operator>= (const MyString& other) {
	for (int i = 0; i < len && i < other.len; i++) {
		if (data[i] > other.data[i]) return true;
		if (data[i] < other.data[i]) return false;
	}
	if (len >= other.len) return true;
	else return false;
}

bool MyString::operator<= (const MyString& other) {
	for (int i = 0; i < len && i < other.len; i++) {
		if (data[i] < other.data[i]) return true;
		if (data[i] > other.data[i]) return false;
	}
	if (len <= other.len) return true;
	else return false;
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

//MyString MyString::operator+(MyString& other) {
//    MyString res;
//    int newLen = len + other.len + 1;
//    res.data = new unsigned char[len];
//    for (int i = 0; i < len; i++) {
//
//    }
//}
