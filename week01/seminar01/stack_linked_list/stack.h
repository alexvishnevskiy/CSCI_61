#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <string>
#include "node.h"


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
    int peek(int j) const;
    int size() const {return size_;};
private:
    node *data;
    unsigned int size_;
};

void copyArr(node * to, node * from);

#endif // SEMINAR_H