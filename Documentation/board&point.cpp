#include <iostream>
using namespace std;

class point {
public:
    point(int in_x, int in_y);
    void set_x(int in_x);
    void set_y(int in_y);
    int getX() const;
    int getY() const;
    friend ostream& operator<<(ostream& left, const point& p);
private:
    int x;
    int y;
};

class board {
public:
    board(int in_N);
    ~board();
    char get_element(int i, int j) const;
    board(const board& b);
    board &operator=(const board& b);
    friend ostream& operator<<(ostream& left, const board& b);
    void insert_point(point p);
    void print() const;
    int get_N() const;
    void clear();

private:
    int N;
    char** arr;
};

int main() {
    int choice,x,y;
    board b(10);
    while (1) {
        cout<<endl<<"Menu epilogwn:"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1.Insert Point"<<endl;
        cout<<"2.Print the board"<<endl;
        cout<<"3.Clear the board"<<endl;
        cout<<"4.Exit"<<endl;
        cin>>choice;
        switch (choice) {
            case 1: {
                cout<<"Dwse x:";
                cin>>x;
                cout<<"Dwse y:";
                cin>>y;
                point p(x,y);
                b.insert_point(p);
            }
                break;
            case 2:
                b.print();
                break;
            case 3:
                b.clear();
                break;
            case 4:
                exit(0);

        }
    }


    return 0;
}
point::point(int in_x, int in_y) {
    if (in_x<0 || in_x>59) {
        cout << "Invalid input" << endl;
        x=0;
    }
    else {
        x=in_x;
    }
    if (in_y<0 || in_y>59) {
        cout << "Invalid input" << endl;
        y=0;
    }
    else {
        y=in_y;
    }
}
void point::set_x(int in_x) {
    if (in_x>0 && in_x<59) {
        x=in_x;
    }
    else {
        cout << "Invalid input" << endl;
        x=0;
    }
}
void point::set_y(int in_y) {
    if (in_y>0 && in_y<59) {
        y=in_y;
    }
    else {
        cout << "Invalid input" << endl;
        y=0;
    }
}
int point::getX() const {
    return x;
}
int point::getY() const {
    return y;
}
ostream& operator<<(ostream& left, const point& p) {
    left<<"("<<p.getX()<<","<<p.getY()<<")";
    return left;
}

board::board(int in_N) {
    N=in_N;
    arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j]='.';
        }
    }
}
board::~board() {
    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
char board::get_element(int i, int j) const {
    return arr[i][j];
}
board::board(const board& b) {
    N=b.N;
    arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j]=b.arr[i][j];
        }
    }
}
board &board::operator=(const board& b) {

    N=b.N;
    arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j]=b.arr[i][j];
        }
    }
    return *this;
}
ostream& operator<<(ostream& left, const board& b) {
    left<<"[";
    for (int i=0; i<b.N; i++) {
        for (int j=0; j<b.N; j++) {
            left<<b.arr[i][j];
            left<<", ";
        }
        left<<endl;
    }
    left<<"]";

    return left;
}
void board::insert_point(point p) {
    if (p.getX()<=N && p.getY()<=N) {
        arr[p.getX()][p.getY()]='O';
    } else {
        cout << "Invalid input" << endl;
    }
}
void board::print() const {
    cout<<"[";
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<<arr[i][j];
            cout<<", ";
        }
        cout<<endl;
    }
    cout<<"]";
}
int board::get_N() const {
    return N;
}
void board::clear() {
    arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j]='.';
        }
    }
}
