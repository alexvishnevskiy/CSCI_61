// #include "stack_array/stack.h"
#include "stack_linked_list/stack.h"
#include <iostream>


int main(){
    Stack s;
    s = Stack();

    for (int i = 0; i < 10; i++){
        s.push(i);
    }
    
    for (int i = 0; i < 10; i++){
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << s.size();
    return 0;
}