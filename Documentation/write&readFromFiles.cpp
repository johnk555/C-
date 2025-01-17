#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char data[100];

    fstream file;
    file.open("test.dat", ios::out);

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    file << data << endl;

    cout << "Enter your age: ";
    cin.getline(data, 100);
    file << data << endl;
    file.close();

    fstream file2;
    file2.open("test.dat", ios::in);

    cout << "Reading from the file" << endl;
    file2 >> data;
    cout << data << endl;

    file2 >> data;
    cout << data << endl;

    file2.close();
    return 0;
}
