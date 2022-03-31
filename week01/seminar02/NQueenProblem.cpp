#include <iostream>
#include "../seminar01/seminar.h"
#include <cassert>
#include <algorithm>


//checks whether we can place queen or not
bool checkQueen(const Stack& Q, int N){
    int q1 = Q.top(); //check last queen
    int q2;
    for (int i = 1; i < N; i++){
        q2 = Q.peek(i);
        if ((q1 == q2) || (std::abs(q1 - q2)== i)){
            return true; //conflict
        }
    }
    return false; //no conflict
}

void printSolution(const Stack& s, int N){
    for (int i = 0; i < N; i++){
        for (int j = 1; j <= N; j++){
            if (s.peek(i) == j)
                std::cout << 'Q';
            std::cout << 'X';
        }
        std::cout << '\n';
    }
}

std::pair <bool, Stack> NQuuenProblem(int N){
    Stack Q;
    bool finished = false;
    std::pair <bool, Stack> return_pair;
    Q.push(1);

    //whether is is finished or stack is empty = all variants are bad
    while (!finished && !Q.isEmpty()){ 
        //if there is a conflict
        if (checkQueen(Q, Q.size())){ 
            //take last queen if it is not at the right corner
            //then increase by 1 its column
            while (!Q.isEmpty() && Q.top() == N) 
                Q.pop();
            if (!Q.isEmpty()){
                int tmp = Q.top();
                Q.pop();
                Q.push(tmp + 1);
            }
        //if there are no problems and size of stack == N finish
        }else if (!checkQueen(Q, Q.size()) && Q.size() == N){
            finished = true;
        //else put a queen
        }else {
            Q.push(1);
        }
    }

    return_pair.first = finished;
    return_pair.second = Q;
    return return_pair;
}

int main(){
    int N = 5;
    bool hasSolution;
    Stack s;

    hasSolution = NQuuenProblem(N).first;
    if (hasSolution){
        s = NQuuenProblem(N).second;
        printSolution(s, N);
    } 
    return 0;
}