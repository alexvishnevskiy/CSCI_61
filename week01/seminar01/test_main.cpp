#include "seminar.h"
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
    return 0;
}