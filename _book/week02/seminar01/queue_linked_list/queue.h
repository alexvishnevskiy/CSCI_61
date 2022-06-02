#ifndef QUEUE_H
#define QUEUE_H
#include <cassert>
#include <list>


class Queue{
private:
    std::list<int> data;
    unsigned int count;
public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    void enqueue(int d);
    void dequeue();
    int front();
    bool empty();
};

#endif