#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class card {
protected:
    string name;
    string color;
    string rarity;
public:
    card(string in_name, string in_color, string in_rarity);
    virtual void print(ostream& left);
    friend ostream& operator<<(ostream& left, card& right);
};

class creature : public card {
private:
    int attack;
    int defense;
    string type;
public:
    creature(string in_name, string in_color, string in_rarity, int in_attack, int in_defense, string in_type);
    void print(ostream& left);
    friend ostream& operator<<(ostream& left, creature& right);
};

class land : public card {
private:
    int mana;
    string description;
    bool tap;
public:
    land(string in_name, string in_color, string in_rarity,int in_mana, string in_description, bool in_tap);
    void print(ostream& left);
    friend ostream& operator<<(ostream& left, land& right);
};

class pool {
private:
    card *cards[300];
    int n_cards;
public:
    pool();
    ~pool();
    card *pick_random_card();
};

class hand {
private:
    card *cards[10];
    int n_cards;
public:
    void pick_card(pool &p, int i);
    void fill_hand(pool &p);
    hand(pool &p);
    friend ostream& operator<<(ostream& left, hand& right);
};

int main() {

    srand(time(NULL));

    pool p;

    hand h(p);

    cout << h << endl;
    return 0;
}

card::card(string in_name, string in_color, string in_rarity) {
    name = in_name;
    color = in_color;
    rarity = in_rarity;
}
void card::print(ostream& left) {
    left<<"("<<name<<","<<color<<","<<rarity<<")";
}


ostream& operator<<(ostream& left, card& right) {
    right.print(left);
    return left;
}

creature::creature(string in_name, string in_color, string in_rarity, int in_attack, int in_defense, string in_type): card(in_name,in_color,in_rarity)
{
    attack = in_attack;
    defense = in_defense;
    type = in_type;
}

void creature::print(ostream& left) {
    left<<"("<<name<<","<<color<<","<<rarity<<",";
    left<<attack<<","<<defense<<","<<type<<")";
}

ostream& operator<<(ostream& left, creature& right) {
    right.print(left);
    return left;
}
land::land(string in_name, string in_color, string in_rarity,int in_mana, string in_description, bool in_tap): card(in_name,in_color,in_rarity) {
    mana = in_mana;
    description = in_description;
    tap = in_tap;
}

void land::print(ostream& left) {
    left<<"("<<name<<","<<color<<","<<rarity<<",";
    left<<mana<<","<<description<<",";
    if (tap) left<<"tapped";
    else left<<"untapped";

    left<<")";
}

ostream& operator<<(ostream& left, land& right) {
    right.print(left);
    return left;
}

pool::pool() {
    cards[0] = new creature("Rune-Scarred Demon","black","rare",6,6,"Demon");
    cards[1] = new creature("Akroan Crusader","red","common",1,1,"Human Soldier");
    cards[2] = new land("Plains","white","uncommon",1,"Basic Land - Plains",false);
    cards[3] = new land("Swamp","black","uncommon",1,"Basic Land - Swamp",false);
    cards[4] = new creature("Aegis Angel","white","rare",5,5,"Angel");
    cards[5] = new creature("Angler Turtle","blue","rare",5,7,"Turtle");
    cards[6] = new creature("Harbinger of Life","black","common",2,3,"Summon Spirit");
    cards[7] = new creature("Ghalta, Primal Hunger","green","rare",12,12,"Elder Dinosaur");
    cards[8] = new creature("Skarrgan Hellkite","red","rare",4,4,"Dragon");
    cards[9] = new creature("Spawn of Mayhem","black","rare",4,4,"Demon");

    n_cards = 10;
}
pool::~pool() {
    int i;
    for (i=9; i<n_cards; i++)
        delete cards[i];
}
card *pool::pick_random_card() {
return cards[rand()%n_cards];
}


void hand::pick_card(pool &p, int i) {
    cards[i] = p.pick_random_card();
}
void hand::fill_hand(pool &p) {
    for (int i=0; i<7; i++) {
        pick_card(p,i);
    }

    n_cards = 7;
}
hand::hand(pool &p) {
    fill_hand(p);
}
ostream& operator<<(ostream& left, hand& right) {

    for (int i=0; i<right.n_cards; i++) {
        left<<*right.cards[i]<<endl;
    }

    return left;
}
