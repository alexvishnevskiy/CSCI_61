#ifndef SEMINAR_H
#define SEMINAR_H

#include <cstdlib>
#include <string>

class Stack{
public:
    Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack();
    void push(int);
    void pop();
    int top() const;
    bool isEmpty();
    void clear();
    void incCapacity();
    int peek(int j) const;
    int size() const {return size_;};
private:
    int *data;
    unsigned int capacity;
    unsigned int size_;
};

void copyArr(int * to, int * from, unsigned int N);

#endif // SEMINAR_H