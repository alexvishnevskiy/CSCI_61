#ifndef QUEUE_H
#define QUEUE_H
#include <cassert>
#include <list>


class Queue{
private:
    int * data;
    unsigned int capacity;
    unsigned int count, front_, back;
    unsigned int nextIndex(unsigned int i){ return (i+1)%capacity; };
    void copy(const Queue& other);
    void incCapacity();
public:
    Queue();
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    void enqueue(int d);
    void dequeue()
    int front();
    bool empty();
};

#endif