#include <iostream>
#include <cassert>
using namespace std;

// This file contains my realization of MinHeap

class MinHeap{
private:
    int * data;
    int capacity, count;
    void increaseCapacity();
    void insertAtk(int k);
public:
    // int capacity, count;
    MinHeap();
    ~MinHeap();
    int children_l(int i);
    int children_r(int i);
    int parent(int i);
    void push(int d);
    int pop();
};


int main(){
    MinHeap q;
    q.push(10);
    q.push(1);
    q.push(-1);
    q.push(20);

    for (int i = 0; i < 3; i++){
        cout << q.pop() << endl;
    }
    return 0;
}


MinHeap::MinHeap(){
    capacity = 10;
    count = 0;
    data = new int[capacity];
}

MinHeap::~MinHeap(){
    delete [] data;
    data = nullptr;
}

void MinHeap::increaseCapacity(){
    int * tmp = new int[capacity*2];

    for (int i = 0; i < capacity; i++){
        tmp[i] = data[i];
    }

    capacity *= 2;
    data = tmp;
    delete [] data;
    tmp = nullptr;
}

int MinHeap::children_l(int i){
    assert(2*i+1<=count);
    return 2*i+1;
}

int MinHeap::children_r(int i){
    assert(2*i+2<=count);
    return 2*i+2;
}

int MinHeap::parent(int i){
    assert((i-1)/2 >= 0);
    return (i-1)/2;
}

void MinHeap::insertAtk(int k){
    while (k > 0){
        int p = parent(k);
        if (data[p] > data[k]){
            swap(data[p], data[k]);
            k = p;
        }else{
            break;
        }
    }
}

void MinHeap::push(int d){
    if (count == capacity){
        increaseCapacity();
    }

    data[count] = d;
    insertAtk(count);
    count++;
}

int MinHeap::pop(){
    int to_pop = data[0], i = 0;
    swap(data[count-1], data[0]);

    while (children_r(i) <= count-1){
        int l_child = children_l(i);
        int r_child = children_r(i);

        if (r_child >= count-1)
            r_child = l_child;

        if (min(data[l_child], data[r_child]) < data[i]){
            if (data[l_child] < data[i]){
                swap(data[l_child], data[i]);
            }else{
                swap(data[r_child], data[i]);
            }
        }else{
            break;
        }
        i++;
    }
    count--;
    return to_pop;
}

//implement heap
