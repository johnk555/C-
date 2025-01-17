#include <iostream>
#include <string>
using namespace std;

class animal {
    private:
    int weight;
    int height;
    public:
    animal(int in_weight, int in_height);
    virtual ~animal();
    int get_weight() const;
    int get_height() const;
    void set_weight(int in_weight);
    void set_height(int in_height);
    virtual void make_sound() = 0;
};

class dog : public animal {
private:
    string home_address;
public:
    dog(int in_weight, int in_height, string in_home_address);
    ~dog();
    void set_home_address(string in_home_address);
    string get_home_address() const;
    void make_sound();
    friend ostream& operator<<(ostream& left, const dog& right);
};

class cat : public animal {
    public:
    cat(int in_weight,int in_height);
    ~cat();
    void make_sound();
    friend ostream& operator<<(ostream& left, const cat& right);
};

void f(animal &ob) {
    ob.make_sound();
}

int main() {

    //First condition with pointers
    //animal *pin[3];

    //pin[0] = new dog(10, 35, "Left Hill 154");
    //pin[1] = new cat(6,20);
    //pin[2] = new animal(40,80);

    //for (int i = 0; i < 3; i++) {
//      pin[i]->make_sound();
  //  }

    //for (int i = 0; i < 3; i++) {
      //delete pin[i];
    //}

    //Second condition with References
    //dog d(10,35,"Left Hill 154");
    //f(d);


    //Virtual Destructor
    //animal *bp = new dog(10,35,"Left Hill 154");
    //delete bp;


    //virtual pure methods
    animal *bp = new dog(10,35,"Left Hill 154");
    delete bp;

    return 0;
}

animal::animal(int in_weight, int in_height) {
  weight = in_weight;
    height = in_height;
}
int animal::get_weight() const {
    return weight;
}
int animal::get_height() const {
    return height;
}
void animal::set_weight(int in_weight) {
    weight = in_weight;
}
void animal::set_height(int in_height) {
    height = in_height;
}
void animal::make_sound() {
    cout<<"Animal sound"<<endl;
}

dog::dog(int in_weight, int in_height, string in_home_address): animal(in_weight, in_height)
{
    home_address = in_home_address;
}
void dog::set_home_address(string in_home_address) {
    home_address = in_home_address;
}
string dog::get_home_address() const {
    return home_address;
}
void dog::make_sound() {
    cout<<"Arf arf"<<endl;
}
ostream& operator<<(ostream& left, const dog& right) {
    left<<"("<<right.get_weight()<<","<<right.get_height()<<","<<right.get_home_address()<<")"<<endl;
}
cat::cat(int in_weight, int in_height):animal(in_weight,in_height) {

};

void cat::make_sound() {
    cout<<"Meoooowwww"<<endl;
}
ostream& operator<<(ostream& left, const cat& right) {
    left<<"("<<right.get_weight()<<","<<right.get_height()<<")"<<endl;
}
animal::~animal() {
    cout<<"Destructing Animal"<<endl;
}
dog::~dog() {
    cout<<"Destructing Dog"<<endl;
}
cat::~cat() {
    cout<<"Destructing Cat"<<endl;
}
