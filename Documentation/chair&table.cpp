#include <iostream>
#include <cstring>
using namespace std;

class table;
class chair {
public:
    chair(char* in_color,double in_height);
    friend ostream& operator<<(ostream& left, const chair& chair);
    friend void shrink(table& in_table,chair& in_chair);
private:
    double height;
    char* color;
};
class table {
public:
    table(char* in_color,double in_width, double in_length);
    friend ostream& operator<<(ostream& left, const table& table);
    friend void shrink(table& in_table,chair& in_chair);
private:
    double width;
    double length;
    char* color;
};



int main() {

    chair chair1("blue",3);

    table table1("red",4,8);

    cout<<table1<<endl;
    cout<<chair1<<endl;

    shrink(table1,chair1);

    cout<<table1<<endl;
    cout<<chair1<<endl;
    return 0;
}
chair::chair(char* in_color,double in_height)
{
    color = new char[std::strlen(in_color)];

    strcpy(color,in_color);
    height = in_height;
}
table::table(char* in_color,double in_width, double in_length) {
    width = in_width;
    length = in_length;
    color = new char[std::strlen(in_color)];
    strcpy(color,in_color);
}
ostream& operator<<(ostream& left, const chair& chair) {
    left<<"Chair has "<<chair.color<<" color and height: "<<chair.height<<endl;

    return left;
}
ostream& operator<<(ostream& left, const table& table) {
    left<<"Table has "<<table.color<<" color and width: "<<table.width<<" and legth: "<<table.length<<endl;

    return left;
}
void shrink(table& in_table,chair& in_chair) {
    in_table.length = in_table.length - in_table.length/10;
    in_table.width = in_table.width - in_table.width/10;

    in_chair.height = in_chair.height - in_chair.height/10;
}
