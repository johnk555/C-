/* cpp6.askisi1.3.cpp */

#include <iostream>
#include <cstring>
using namespace std;

class STRING {
    public:
        STRING();
        STRING(char *in_str);
        STRING(const STRING &ob);
        ~STRING();
        int get_length() const;
        char *get_str() const;
        void set_str(char *in_str);
        void print();
        STRING &operator=(STRING &right);
        char &operator[](int i);
        bool operator<(STRING &right);
        bool operator>(STRING &right);
        bool operator==(STRING &right);
        friend ostream &operator<<(ostream &left, STRING &right);
        friend istream &operator>>(istream &left, STRING &right);
    private:
       int length;
       char *str;
};


int main()
{
    char s[80]="This is a string";
    STRING s1(s);
    STRING s2;

    s2=s1;

    cin>>s1;
    s2[2]='a';
    s2[3]='t';

    cout<<s1<<endl;
    cout<<s2<<endl;

    return 0;
}

STRING::STRING()
{
    length = 0;
    str = new char[1];
    str[0]='\0';
}

STRING::STRING(char *in_str)
{
    length = strlen(in_str);

    str = new char [length+1];
    if (!str) cout<<"Error Allocating Memory";

    strcpy(str, in_str);
}

STRING::STRING(const STRING &ob)
{
    length = ob.get_length();

    str = new char [length+1];
    if (!str) cout<<"Error Allocating Memory";

    strcpy(str, ob.get_str());
}

STRING::~STRING()
{
    delete [] str;
}

int STRING::get_length() const
{
    return length;
}

char *STRING::get_str() const
{
    return str;
}

void STRING::set_str(char *in_str)
{
    if (str!=NULL)
        delete str;

    length = strlen(in_str);

    str = new char [length];
    if (!str) cout<<"Error Allocating Memory";

    strcpy(str, in_str);
}

void STRING::print()
{
    cout<<str;
}

STRING &STRING::operator=(STRING &right)
{
    if (this==&right) return *this;

    length=right.length;

    delete [] str;
    str = new char [length+1];
    if (!str) cout<<"Error Allocating Memory";

    strcpy(str, right.str);

    return *this;
}

char &STRING::operator[](int i)
{
    if (i>=0 && i<=length)
        return str[i];
    else
        cout<<"Index out of bounds!";
}

bool STRING::operator<(STRING &right)
{
    if (strcmp(str, right.str)<0)
        return true;
    return false;
}

bool STRING::operator>(STRING &right)
{
    if (strcmp(str, right.str)>0)
        return true;
    return false;
}

bool STRING::operator==(STRING &right)
{
    if (strcmp(str, right.str)==0)
        return true;
    return false;
}
ostream &operator<<(ostream &left, STRING &right) {
    left<<right.str;
    return left;
}
istream &operator>>(istream &left, STRING &right) {
    char in_str[80];
    left>>in_str;
    if (right.str!=NULL) {
        delete right.str;
        right.str = new char [strlen(in_str)+1];
    }
    if (right.str==NULL) {
        cout<<"Error Allocating Memory";
    }
    right.length=strlen(in_str);
    strcpy(right.str, in_str);
    return left;
}
