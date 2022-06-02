#include "stack.h"
#include <cassert>


Stack::Stack(){
    data = nullptr;
    size_ = 0;
}

Stack::Stack(const Stack& s){
    copyArr(data, s.data);
    size_ = s.size_;
}

Stack::~Stack(){
    clear();
}

Stack& Stack::operator=(const Stack& s){
    copyArr(data, s.data);
    size_ = s.size_;
    return *this;
}

void Stack::push(int x){
    node * temp = new node(x, data);
    data = temp;
    size_++;
}

void Stack::clear(){
    while (data != nullptr){
        node * temp = data;
        data = data->link();
        delete temp;
    }
}

void copyArr(node * to, node * from){
    if (from != nullptr){
        to = new node(from->data(), nullptr);
        node * temp = to;

        for (node * temp1 = from->link(); temp1 != nullptr; temp1 = temp1->link()){
            to->set_link(temp1);
            to = to->link();
        }
        
        to = temp;
        temp = nullptr;
    }
}

int Stack::top() const{
    assert (size_ > 0 && "should be some value at the top");
    return data->data();
}

bool Stack::isEmpty(){
    return size_ == 0;
}

void Stack::pop(){
    assert (size_ > 0);

    node * temp = data;
    data = data->link();
    delete temp;
    size_--;
}

int Stack::peek(int j) const {
    assert(j >= 0 && j <= size_-1);
    node * temp = data;
    for (int i = j; i>= 0; i--){
        temp = temp->link();
    }
    return temp->data();
}