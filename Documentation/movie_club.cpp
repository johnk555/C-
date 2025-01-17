#include <iostream>
#include <string>
using namespace std;

class movie {
public:
    movie();
    movie(string in_title, double in_score_imdb, int in_weeks);
    virtual double score();
protected:
    string title;
    double score_imdb;
    int weeks;

};

class thriller : virtual public movie {
public:
    thriller(double in_fear_factor);
    thriller(string in_title, double in_score_imdb, int in_weeks,double in_fear_factor);
    double score();
protected:
    double fear_factor;
};

class comedy : virtual public movie {
public:
    comedy(double in_fun_factor);
    comedy(string in_title, double in_score_imdb, int in_weeks,double in_fun_factor);
    double score();
protected:
    double fun_factor;
};

class comedy_thriller: public thriller , public comedy {
    public:
    comedy_thriller(string in_title, double in_score_imdb, int in_weeks,double in_fear_factor, double in_fun_factor);
    double score();
};

int main() {

    thriller m1("IT, Chapter 2", 6.8, 10,8.0);
    thriller m2("Us", 6.9, 30,7.0);
    thriller m3("Silence of the Lambs", 8.6, 1540,9.0);
    comedy m4("e of Lambs",8.6,1540,9.0);
    comedy_thriller m5("IT, Chapter 2", 6.8, 10,8.0,4.0);

    cout<<"To score tis 1is tainias: "<<m1.score()<<endl;
    cout<<"To score tis 2is tainias: "<<m2.score()<<endl;
    cout<<"To score tis 3is tainias: "<<m3.score()<<endl;
    cout<<"To score tis 4is tainias: "<<m4.score()<<endl;
    cout<<"To score tis 5is tainias: "<<m5.score()<<endl;

    return 0;
}
movie::movie() {

}

movie::movie(string in_title, double in_score_imdb, int in_weeks) {
    title=in_title;
    score_imdb=in_score_imdb;
    weeks=in_weeks;
}
double movie::score() {
    return score_imdb/(0.5*weeks);
}
thriller::thriller(double in_fear_factor)
{
    fear_factor=in_fear_factor;
}
thriller::thriller(string in_title, double in_score_imdb, int in_weeks,double in_fear_factor):
movie(in_title,in_score_imdb,in_weeks) {
    fear_factor=in_fear_factor;
}
double thriller::score() {
    return fear_factor*movie::score();
}

comedy::comedy(double in_fun_factor)
{
    fun_factor=in_fun_factor;
}

comedy::comedy(string in_title, double in_score_imdb, int in_weeks,double in_fun_factor):
movie(in_title,in_score_imdb,in_weeks) {
    fun_factor=in_fun_factor;
}

double comedy::score() {
    return fun_factor*movie::score();
}

comedy_thriller::comedy_thriller(string in_title, double in_score_imdb, int in_weeks,double in_fear_factor, double in_fun_factor):
    movie(in_title,in_score_imdb,in_weeks),thriller(in_fun_factor),comedy(in_fun_factor) {
}
double comedy_thriller::score() {
    return ((fun_factor+fear_factor)/2)*movie::score();
}
