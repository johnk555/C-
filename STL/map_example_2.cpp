#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Contact {
    string name, phone;

    public:
    Contact (string n, string p) { name = n; phone = p; }
    string getName() const { return name; }
    string getPhone() const { return phone; }
    bool operator<(const Contact &rhs) const { return phone < rhs.phone; }
};

int main() {

    /*
    vector<int> a{ 88 , 22 , 77 };
    vector<int> b{ 90 , 87 , 91 };
    vector<int> c{ 79 , 81 , 74 };

    // student's name, vector of scores
    map<string, vector<int>> scores{ {"John Doe", a} , {"Patrick Mahlmes", b} , {"Max Crosby" , c} };

    for ( auto student : scores ) {
        cout << student.first << endl;
        for (auto score : student.second)
            cout << score << " ";

        cout << endl;
    }
*/

    /* Insert as value a class
    map<string, Contact> contacts{ { "Joe Montana", Contact("Joe Montana","555-1234")} , {"Jerry Rice",Contact("Jerry Rice" , "555-1235")} };

    for ( auto c : contacts ) {
        cout << c.first << " " << c.second.getPhone() << endl;
    } */

    Contact jm("Joe Montana" , "555-1616");
    Contact jr("Jerry Rice" , "555-8080");
    map<Contact , int> contacts;

    contacts[jm] = 16;
    contacts[jr] = 80;

    cout << contacts[jm] + contacts[jr] << endl;

    map<Contact , int>::iterator it = contacts.lower_bound(jr);
    cout << it->second << endl;
    bool choice = contacts[jm] < contacts[jr];
    cout << choice << endl;

    return 0;
}
