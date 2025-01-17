#include <iostream>
using namespace std;

class circle{
private:
    double aktina;
public:
    circle();
    circle(double in_aktina);
    ~circle();
    void set_aktina(double in_aktina);
    double get_embadon();
    double get_perimetros();
};

int main()
{
    circle c1;
    circle c2(4);
    
    cout<<"Perimetros toy kykloy 1 einai: "<<c1.get_perimetros()<<endl;
    cout<<"Perimetros toy kykloy 2 einai: "<<c2.get_perimetros()<<endl;
    
    return 0;
}

circle::circle(){
    aktina = 1;
}
circle::circle(double in_aktina){
    aktina = in_aktina;
}

circle::~circle(){
    cout<<"O KYKLOS KATASTRAFIKE"<<endl;
}

void circle::set_aktina(double in_aktina){
    aktina=in_aktina;
}
double circle::get_embadon(){
    return 3.1415*aktina*aktina;
}
double circle::get_perimetros(){
    return 2*3.1415*aktina;
}
