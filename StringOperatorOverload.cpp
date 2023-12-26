/*
Write a C++ program to perform String operations
i. = Equality   Compare string
ii. == String Copy
iii. + Concatenation
iv. << To display a string
v. >> To reverse a string
vi. Function to determine whether a string is a palindrome
To find occurrence of a sub-string. Use Operator Overloading.
*/

#include<iostream>
#include<string.h>

using namespace std;

class StringOperations {
public:
    char str[100];


    // Default constructor
    StringOperations()
    {
        strcpy(str, "");
    }

    // Parameterized constructor
    StringOperations(const char* s)
    {
        strcpy(str, s);
    }

    // Equality operator
    bool operator=(const StringOperations& other) {
        return (strcmp(str, other.str) == 0);
    }

    // String copy operator
    void operator==(const StringOperations& other) {
        strcpy(str, other.str);
    }

    // Concatenation operator
    void operator+(const StringOperations& other) {
        strcat(str, other.str);
    }

    // Display a string
    friend ostream& operator<<(ostream& os, const StringOperations& s) {
        os << s.str;
        return os;
    }

    // Reverse a string
    void operator>>(StringOperations& reversed) {
        int length = strlen(str);
        for (int i = 0; i < length; i++) {
            reversed.str[i] = str[length - 1 - i];
        }
        reversed.str[length] = '\0';
    }

    // Check if a string is a palindrome
    bool isPalindrome() {
        int length = strlen(str);
        for (int i = 0; i < length / 2; i++) {
            if (str[i] != str[length - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    // Find occurrence of a sub-string using operator overloading
    int operator()(const char* subStr) {
        int count = 0;
        char* found = strstr(str, subStr);
        while (found != nullptr) {
            count++;
            found = strstr(found + 1, subStr);
        }
        return count;
    }
};

int main() {
    // Test the StringOperations class
    StringOperations str1("Hello");
    StringOperations str2("World");

    // Equality
    if (str1 = str2) {
        cout << "Strings are equal.\n";
    } else {
        cout << "Strings are not equal.\n";
    }

    // String copy
    str1 == str2;
    cout << "String after copy: " << str1 << endl;

    // Concatenation
    str1 + str2;
    cout << "String after concatenation: " << str1 << endl;

    // Display a string
    cout << "String to display: " << str1 << endl;

    // Reverse a string
    StringOperations reversed;
    str1 >> reversed;
    cout << "Reversed string: " << reversed << endl;

    // Check if a string is a palindrome
    if (str1.isPalindrome()) {
        cout << "String is a palindrome.\n";
    } else {
        cout << "String is not a palindrome.\n";
    }

    // Find occurrence of a sub-string
    const char* subStr = "l";
    int occurrence = str1(subStr);
    cout << "Occurrence of '" << subStr << "': " << occurrence << endl;

    return 0;
}
