#include <iostream>
#include <string>
using namespace std;

void InsertionSort(string *str, int n); // Correct function declaration
void swap(string &str1, string &str2);  // Use references to swap actual elements

int main() {
    string str1("abc");
    string str2("defg");
    string str3("hello");
    string str4("ghijkl");
    string str5("mnopqrs");
    string str6("tvyxtyz");
    string str100[6] = {str4, str3, str1, str6, str2, str5};

    // Print the array before sorting
    cout << "Before sorting:" << endl;
    for (const auto &s : str100) {
        cout << s << " ";
    }
    cout << endl;

    // Sort the array
    InsertionSort(str100, 6);

    // Print the array after sorting
    cout << "After sorting:" << endl;
    for (const auto &s : str100) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}

void InsertionSort(string *str, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (str[j + 1] < str[j]) {
                swap(str[j + 1], str[j]); // Swap adjacent elements if out of order
            } else {
                break; // Exit inner loop if order is correct
            }
        }
    }
}

void swap(string &str1, string &str2) { // Use references for swapping
    string temp = str1;
    str1 = str2;
    str2 = temp;
}
