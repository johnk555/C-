#include <iostream>
using namespace std;

#define STACK_SIZE 100

template<typename T>
class stack {
public:
    stack();
    bool empty();
    bool full();
    bool push(T elem);
    bool pop(T *elem);
    template<typename U>friend ostream& operator<<(ostream& left, const stack<U>& right);
private:
    T array[STACK_SIZE];
    int top;
};

int main() {

    stack<int> st;

    int temp;

    st.push(1);
    cout << st <<endl;

    st.push(2);
    cout<<st<<endl;

    st.pop(&temp);
    cout<<st<<endl;

    st.push(3);
    cout<<st<<endl;

    st.push(4);
    cout<<st<<endl;

    return 0;
}

template<typename T>
stack<T>::stack() {
    top = -1;
}

template<typename T>
bool stack<T>::empty() {
    return (top == -1);
}

template<typename T>
bool stack<T>::full() {
    return top == STACK_SIZE - 1;
}
template<typename T>
bool stack<T>::push(T elem) {
    if (!full()) {
        top++;
        array[top] = elem;
        return true;
    }
    cout << "Stack overflow" << endl;
    return false;
}
template<typename T>
bool stack<T>::pop(T *elem) {
    if (!empty()) {
        *elem = array[top];
        top--;
        return true;
    }
    cout << "Stack is empty" << endl;
    return false;
}
template<typename T>
ostream &operator<<(ostream &left,const stack<T> &right){

    for (int i = 0; i <= right.top; i++)
        left<<right.array[i]<<" ";
    return left;
}
