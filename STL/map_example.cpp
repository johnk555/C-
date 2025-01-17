#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int main() {

    // key , value
    // name , phone number
    map<string, string> phonebook = { {"John Doe" , "555-1234"} , {"Jana Doe","555-1235"} , {"Jack Doe","555-1236"} };

    // take the size of the map
    cout << "Size : " << phonebook.size() << endl;

    // take the value of the key: John Doe
    cout << phonebook.at("John Doe") << endl;

    // check if the map is empty
    cout << phonebook.empty() << endl;

    for (auto e : phonebook) {
        cout << e.first << " , " << e.second << endl;
    }

    // clear the map
    phonebook.clear();

    cout << "Size : " << phonebook.size() << endl;

    // insert an element
    phonebook["Tom Jones"] = "999-1234";

    cout << "Size : " << phonebook.size() << endl;

    cout << phonebook.at("Tom Jones") << endl;

    // use insert - make_pair()(key, value)
    auto a = make_pair("John Doe", "555-1234");

    phonebook.insert(a);

    cout << phonebook.at("John Doe") << endl;

    phonebook.insert(make_pair("Tim Brown" , "555-8181"));

    cout << phonebook.at("Tim Brown") << endl;

    phonebook.emplace("Joe Montana" , "555-1616");

    cout << phonebook.at("Joe Montana") << endl;

    if (phonebook.count("John Karelas"))
        cout << phonebook.at("John Karelas") << endl;   //throw an exception
    else
        cout << "Not found!" << endl;

    map<string, string>::iterator it = phonebook.begin();

    cout << endl;
    while (it != phonebook.end()) {
        cout << it->first << ", " << it->second << endl;
        it++;
    }

    cout << endl;
    map<string, string> newphonebook(phonebook);
    for ( auto e : newphonebook) {
        cout << e.first <<", " << e.second << endl;
    }




    return 0;
}
