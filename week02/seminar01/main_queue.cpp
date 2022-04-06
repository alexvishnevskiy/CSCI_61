#include "queue_array/queue.h"
#include "queue_linked_list/queue.h"
#include <iostream>


int main(){
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(10);
    q.dequeue();
    std::cout << q.front();
    return 0;
}