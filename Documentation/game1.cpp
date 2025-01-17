#include <iostream>
#include <random>
using namespace std;
int random_number(int a, int b);

class demigoron {
    public:
        demigoron();
        int attack();
    private:
        int height;
        int weight;
        int health;
};

class demidog {
    public:
        int attack();
        demidog();
    private:
        int health;
};

class hive {
    public:
        hive(bool in_demigoron);
        int attack();
    private:
        demigoron *p1;
        demidog *arr;
        int n_demidogs;
};
int main() {
    hive h1(true);

    cout<<"Prokalese tosi zimia: "<<h1.attack()<<endl;
    return 0;
}

int random_number(int a, int b) {
    std::random_device rd;  // Παράγει έναν αριθμό για αρχικοποίηση
    std::mt19937 gen(rd()); // Μηχανή γεννήτριας τυχαίων αριθμών (Mersenne Twister)
    std::uniform_int_distribution<> distr(a, b); // Διάστημα [300, 500]

    // Δημιουργία τυχαίου αριθμού
    return distr(gen);
}


demigoron::demigoron() {
    height = 5;
    weight = 500;
    health = 10000;
}
int demigoron::attack() {
    return random_number(300,500);
}


demidog::demidog() {
    health=100;
}
int demidog::attack() {
    return random_number(10,30);
}



hive::hive(bool in_demigoron) {
    if (in_demigoron) {
        p1 = new demigoron();
        if (!p1)
            cout << "Error allocating memory for demigoron" << endl;

    }
    n_demidogs = random_number(10,50);
    arr = new demidog[n_demidogs];
    if (!arr)
        cout << "Error allocating memory for demidog" << endl;
}


int hive::attack() {
    int sum = 0;
    int damage1 = 0;
    int damage2 = 0;

    if (p1) {
        damage1 = p1->attack();
        cout<<"Demigoron epithetai!"<<"(damage: "<<damage1<<")"<<endl;
        sum+=damage1;
    }
    else {
        cout<<"To demigoron den yparxei"<<endl;
    }

    for (int i = 0; i < n_demidogs; i++) {
        damage2 = arr[i].attack();
        cout<<"Demidog "<<i<<" epithetai!"<<"(damage: "<<damage2<<")"<<endl;
        sum+=damage2;
    }


    return sum;
}
