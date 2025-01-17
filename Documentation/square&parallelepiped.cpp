#include <iostream>
using namespace std;

class tetragono{
protected:
    double pleura;
public:
    tetragono(double in_pleura=1);
    ~tetragono();
    double get_perimetros();
};

class orthogonioParalilepipedo : public tetragono{
    private:
        double height;
    public:
        orthogonioParalilepipedo(double in_pleura, double in_height=1);
        ~orthogonioParalilepipedo();
        double get_ogko();
};

int main()
{
    orthogonioParalilepipedo o1(5,10);
    
    cout<<"H perimetros tis basis einai: "<<o1.get_perimetros()<<endl;
    
    cout<<"O ogkos toy PARALLHLEPIPEDOU einai: "<<o1.get_ogko()<<endl;
    
    return 0;
}

tetragono::tetragono(double in_pleura){
    pleura = in_pleura;
}

tetragono::~tetragono(){
    cout<<"KATASTROFI TETRAGONOU"<<endl;
}

double tetragono::get_perimetros(){
    return 4*pleura;
}

orthogonioParalilepipedo::orthogonioParalilepipedo(double in_pleura, double in_height) : tetragono(in_pleura)
{
    height = in_height;
}
orthogonioParalilepipedo::~orthogonioParalilepipedo(){
    cout<<"KATASTROFI PARALLHLEPIPEDOU"<<endl;
}

double orthogonioParalilepipedo::get_ogko(){
    return pleura*pleura*height;
}
        
        
        
        
