#include "MyString.h"
#include <iostream>
using namespace std;

int main() {
    MyString str1, str2, str3;
    cout << "---------------------------------PLEASE ENTER 2 STRINGS---------------------------------" << "\n\n";
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;
    cout << "\n\n";
    cout << "---------------------------------ASSIGN STR1'S VALUE TO STR3---------------------------------" << "\n\n";
    str3 = str1;
    cout << "String 3 after assignment: " << str3 << "\n\n";
    cout << "---------------------------------COMPARE STR1 AND STR2---------------------------------" << "\n\n";
    if (str1 > str2)  cout << "String 1 is greater than string 2" << "\n";
    else if (str1 < str2) cout << "String 1 is less than string 2" << "\n";
    else cout << "String 1 is equal to string 2" << "\n";

    if (str1 == str2) cout << "String 1 is equal to string 2" << "\n";
    else cout << "String 1 is different from string 2" << "\n";

    if (str1 != str2) cout << "String 1 is different from string 2" << "\n";
    else cout << "String 1 is equal to string 2" << "\n";

    if (str1 >= str2) cout << "String 1 is greater than or equal to string 2" << "\n";
    else cout << "String 1 is less than string 2" << "\n";

    if (str1 <= str2) cout << "String 1 is less than or equal to string 2" << "\n\n";
    else cout << "String 1 is greater than string 2" << "\n\n";

    cout << "---------------------------------PLEASE ENTER THE DESIRED STRING SIZE---------------------------------" << "\n\n";
    cout << "Enter desired size: ";
    int n;
    cin >> n;
    str3.set(n);
    cout << "String 3 after resizing: " << str3 << "\n\n";

    cout << "---------------------------------PLEASE ENTER THE DESIRED STRING---------------------------------" << "\n\n";
    char str4[1024];
    cout << "Enter desired string: ";
    cin >> str4;
    str3.set(str4);
    cout << "String 3 after setting string: " << str3 << "\n\n";
    cout << "---------------------------------RESULT AFTER CONCATENATION---------------------------------" << "\n\n";
    MyString kq;
    kq = "T" + str1 + str2 + " " + str3;
    cout << "T" << " + str1 + str2 + 'space' + str3: " << kq;

    return 0;
}
