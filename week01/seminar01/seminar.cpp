#include "seminar.h"
#include <cassert>


Stack::Stack(){
    data = new int[10];
    capacity = 10;
    size_ = 0;
}

Stack::Stack(const Stack& s){
    data = s.data;
    capacity = s.capacity;
    size_ = s.size_;
}

Stack::~Stack(){
    delete [] data;
    data = nullptr;
}

Stack& Stack::operator=(const Stack& s){
    int *temp = new int[s.size()];

    for (int i = 0; i < s.size(); i++){
        temp[i] = s.data[i];
    }

    delete [] data;
    data = temp;
    capacity = s.capacity;
    size_ = s.size_;    
    return *this;
}

void Stack::push(int x){
    if (size_ == capacity){
        Stack::incCapacity();
    }
    data[size_] = x;
    size_++;
}

void Stack::clear(){
    delete [] data;
}

void copyArr(int * to, int * from, unsigned int N){
    to = new int [N];
    for (int i = 0; i < N; i++){
        to[i] = from[i];
    }
}

void Stack::incCapacity(){
    int *temp = new int[capacity * 2];
    copyArr(temp, data, capacity);
    delete [] data;
    data = temp;
    temp = nullptr;
    capacity *= 2;
}

int Stack::top() const{
    assert (size_ > 0 && "should be some value at the top");
    return data[size_ - 1];
}

bool Stack::isEmpty(){
    return size_ == 0;
}

void Stack::pop(){
    size_--;
}

int Stack::peek(int j) const {
    assert(j >= 0 && j <= size_-1);
    return data[size_-1-j];
}