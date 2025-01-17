#include <iostream>
#include <cstring>
#include <random>
using namespace std;

int random_number(int a, int b){
    std::random_device rd;  // Obtain a random seed from hardware
    std::mt19937 gen(rd()); // Initialize generator with seed

    // Define the range of the random number (0 to 99)
    std::uniform_int_distribution<> distrib(a, b);

    // Generate a random number between 0 and 99
    int randomNumber = distrib(gen);
    return randomNumber;
}

class wizard {
    public:
        wizard(int in_age, char *in_beard, int in_mana);
        int fireball();
        int lightning();
        void wait();
        wizard &operator+= (int add_health);
        wizard &operator-= (int sub_health);
        bool check_dead();
        int get_health();
        int attack();
    private:
        int age;
        char beard[80];
        int mana;
        int health;
};

class humanoid{
    public:
        humanoid();
        humanoid &operator-= (int sub_health);
        int attack();
        bool check_dead();
        int get_health();
    private:
        int health;

};




int main()
{
    char str[80]="grey";
    wizard gandalf(2019, str, 100);
    int damage;
    humanoid a;
    int r=1;

    while(1){
        cout<<endl<<"==========================";
        cout<<endl<<"Round "<<r<<endl;

        //paizei o magos
        int randomNumber = random_number(0,1);
        if (randomNumber == 0){
            damage = gandalf.attack();
            damage += gandalf.lightning();
            a-=damage;
            cout<<endl<<"Wizard's health = "<<gandalf.get_health();
            cout<<endl<<"Humanoid's health = "<<a.get_health();
            if(a.check_dead())
                break;
        }
        else{
            damage = gandalf.attack();
            damage += gandalf.fireball();
            a-=damage;
            cout<<endl<<"Wizard's health = "<<gandalf.get_health();
            cout<<endl<<"Humanoid's health = "<<a.get_health();
            if(a.check_dead())
                break;
        }

        //paizei to antropoeides
        damage=a.attack();
        gandalf-=damage;
        cout<<endl<<"Wizard's health = "<<gandalf.get_health();
        cout<<endl<<"Humanoid's health = "<<a.get_health();
        if(gandalf.check_dead())
            break;

        r++;
    }
}




wizard::wizard(int in_age, char *in_beard, int in_mana)
{
    age = in_age;
    strcpy(beard, in_beard);
    mana = in_mana;
    health = 100;
}

int wizard::fireball()
{
    if (mana >= 90)
    {
        mana-=90;
        cout<<endl<<"Fireball! (mana:"<<mana<<")";
    }
    else{
        cout<<endl<<"Fireball effort (not enough mana)";
    }

    return random_number(10,20);
}

int wizard::lightning()
{
    if (mana >= 30)
    {
        mana-=30;
        cout<<endl<<"Lighting! (mana:"<<mana<<")";
    }
    else
        cout<<endl<<"Lightning effort (not enough mana)";

    return random_number(50,70);
}



void wizard::wait()
{
    if (mana<=90)
        mana+=10;
    cout<<endl<<"wait... (mana:"<<mana<<")";
}
wizard &wizard::operator+= (int add_health){

    health = health +add_health;

    if(health >= 100)
        health = 100;

    return *this;
}
wizard &wizard::operator-= (int sub_health){
    health-=sub_health;

    if(health <= 0)
        cout<<endl<<"Wizard is dead!";

    return *this;

}
bool wizard::check_dead(){
    if(health<=0){
        cout<<endl<<"Humanoid is dead";
        return true;
    }
    return false;
}
int wizard::get_health(){
    return health;
}

int wizard::attack() {
    return random_number(20,30);
}


humanoid::humanoid(){
    health = 100;
}
humanoid &humanoid::operator-= (int sub_health){
    health-=sub_health;

    if(health <= 0)
        cout<<endl<<"Humanoid dead";

    return *this;
}
int humanoid::attack(){
    return random_number(1,5);
}
bool humanoid::check_dead(){
    if(health<=0){
        cout<<endl<<"Humanoid is dead";
        return true;
    }
    return false;
}
int humanoid::get_health(){
    return health;
}
