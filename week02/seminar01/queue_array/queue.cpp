#include "queue.h"


void Queue::copy(const Queue& other){
        count = other.count;
        front_ = other.front_;
        back = other.back;
        capacity = other.capacity;
        data = new int[other.capacity];
        for (int i = 0; i < other.capacity; i++){
            data[i] = other.data[i];
        }
}
Queue::Queue(){
    count = front_ = back = 0;
    capacity = 4;
    data = new int[capacity];
}
Queue::~Queue(){
    if (data)
        delete [] data;
}
Queue::Queue(const Queue& other){
    copy(other);
}
Queue& Queue::operator=(const Queue& other){
    if (this == &other) 
        return *this;

    if (data)
        delete [] data;

    copy(other);
    return *this;
}
void Queue::enqueue(int d){
    if (count >= capacity)
        incCapacity();
        
    data[back] = d;
    back = nextIndex(back);
    count++;
}
void Queue::dequeue(){
    front_ = nextIndex(front_);
    count--;
}
int Queue::front(){
    assert(!empty());
    return data[front_];
}
bool Queue::empty(){
    return count == 0;
}
void Queue::incCapacity(){
    int * tmp = new int[2*capacity];
    int tmp_indx = 0;
    for (unsigned int i = 1; i <= count; i++){
        tmp[tmp_indx] = data[front_];
        front_ = nextIndex(front_);
        tmp_indx++;
    }
    delete [] data;
    data = tmp;
    back = count - 1;
    front_ = 0;
    capacity *= 2;
}