#include "MyString.h"
#include <iostream>

using namespace std;

void main() {
	MyString str1, str2, str3;
	cout << "Nhap chuoi 1" << endl;
	cin >> str1;

	cout << "nhap chuoi 2" << endl;
	cin >> str2;

	cout << "Nhap chuoi 3" << endl;
	cin >> str3;

	cout << "Chuoi 1: " << str1 << endl;
	cout << "chuoi 2: " << str2 << endl;
	cout << "Chuoi 3: " << str3 << endl;

	cout << "Chuoi 3 = chuoi 1" << endl;
	str3 = str1;

	cout << "So sanh: chuoi 3 = chuoi 2: " << (str3 == str2 ? "Dung" : "Sai") << endl;
	cout << "So sanh: chuoi 3 != chuoi 2: " << (str3 != str2 ? "Dung" : "Sai") << endl;
	cout << "So sanh: chuoi 3 > chuoi 2: " << (str3 > str2 ? "Dung" : "Sai") << endl;
	cout << "So sanh: chuoi 3 <= chuoi 2: " << (str3 <= str2 ? "Dung" : "Sai") << endl;
	cout << "So sanh: chuoi 3 < chuoi 2: " << (str3 < str2 ? "Dung" : "Sai") << endl;
	cout << "So sanh: chuoi 3 >= chuoi 2: " << (str3 >= str2 ? "Dung" : "Sai") << endl;


	cout << "Nhap so - set" << endl;
	int n; cin >> n;
	str3.set(n);
	cout << "Chuoi 3 - set so: " << str3 << endl;

	cin.ignore();
	cout << "Nhap chuoi - set" << endl;
	char temp[100];
	cin.getline(temp, 100);
	str3.set((const char*)temp);
	cout << "Chuoi 3 - set chuoi: " << str3 << endl;

	MyString kq = "T" + str1 + str2 + " " + str3;
	cout << "kq: " << kq << endl;
	return;
}