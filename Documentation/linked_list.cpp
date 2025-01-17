#include <iostream>
#include <string>
using namespace std;

template <typename T>
class linked_list;

template <typename T>
class node{
public:
    friend class linked_list<T>;
    T data;
    node<T> *next;
};

template <typename T>
class linked_list{
public:
    linked_list();
    bool insert_start(T in_data);
    bool insert(T in_data);
    void print();
    bool empty();
    T get_data(node<T> *p);
    bool insert_after(node<T> *p, T in_data);
    bool delete_start(T *out_data);
    bool delete_after(node<T> *p, T *out_data);
    ~linked_list();
    node<T> *head;
};

int main() {
    linked_list<int> l;

    l.insert_start(5);
    l.insert_start(4);
    l.insert_start(3);
    l.insert(555);

    node<int> *n1 = new node<int>;
    n1 = l.head->next->next;

    int i;
    l.delete_after(n1,&i);

    l.print();

    cout<<"The deleted string is: "<<i<<endl;

    return 0;
}

template <typename T>
linked_list<T>::linked_list() {
    this->head = new node<T>();
    this->head->next = NULL;
}
template <typename T>
bool linked_list<T>::insert_start(T in_data) {
    //if (this->head->next == NULL)
    node<T> *temp = new node<T>();
    temp->data = in_data;
    temp->next = this->head->next;
    this->head->next = temp;
    return true;
}
template <typename T>
bool linked_list<T>::insert(T in_data) {
    if (this->head->next == NULL) {
        cout << "Error in insert()" << endl;
        return false;
    }else {
        node<T> *current = this->head->next;
        while (current->next != NULL) {
            current = current->next;
        }
        node<T> *temp = new node<T>();
        temp->data = in_data;
        temp->next = NULL;
        current->next = temp;
        return true;
    }
}
template<typename T>
void linked_list<T>::print() {
        node<T> *temp = this->head->next;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
}
template <typename T>
bool linked_list<T>::empty() {
    return head == NULL;
}

template <typename T>
T linked_list<T>::get_data(node<T> *p) {
    return  p->data;
}

template <typename T>
bool linked_list<T>::insert_after(node<T> *p, T in_data) {
    node<T> *temp = new node<T>();
    temp->data = in_data;
    temp->next = p->next;
    p->next = temp;
    return true;
}

template <typename T>
bool linked_list<T>::delete_start(T *out_data) {
    if (this->head->next == nullptr) {
        return false;
    }
    node<T> *temp = this->head->next;
    *out_data = temp->data;
    this->head->next = temp->next;
    return true;
}

template <typename T>
bool linked_list<T>::delete_after(node<T> *p, T *out_data) {
    if (p->next == nullptr) {
        return false;
    }
    node<T> *temp = new node<T>();
    temp = p->next;
    *out_data = temp->data;
    p->next = temp->next;
    return true;
}

template <typename T>
linked_list<T>::~linked_list() {
    node<T> *temp = this->head->next;
    while (temp != NULL) {
        node<T> *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}
