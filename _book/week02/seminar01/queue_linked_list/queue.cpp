#include "queue.h"


Queue::Queue(){
    count = 0;
}

Queue::Queue(const Queue& other){
    count = other.count;
    data = other.data;
}

Queue& Queue::operator=(const Queue& other){
    count = other.count;
    data = other.data;
    return *this;
}

void Queue::enqueue(int d){
    data.push_back(d);
    count++;
}

void Queue::dequeue(){
    data.pop_front();
    count--;
}

int Queue::front(){
    return data.front();
}

bool Queue::empty(){
    return data.empty();
}