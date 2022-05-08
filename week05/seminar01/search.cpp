#include <iostream>
#include <vector>
using namespace std;


bool LinearSearch(vector<int> A, int target, int& location){
    for (int i = 0; i < A.size(); i++){
        if (A[i] == target){
            location = i;
            return true;
        }
    }
    return false;
}

bool BinarySearch(vector<int> A, int target, int& location){
    int start = 0;
    int end = A.size()-1;
    bool found = false;

    while (!found && start <= end){
        int middle = (start + end)/2;
        if (A[middle] == target){
            location = middle;
            found = true;
        }else if (A[middle] < target){
            start = middle + 1;
        }else{
            end = middle - 1;
        }
    }
    return found;
}

bool BS(vector<int> A, int target, int location){
    bool found = false;
    BS(A, target, location, found, 0, A.size()-1);
    return found;
}

void BS(vector<int> A, int target, int& location, bool& found, int start, int end){
    int middle = (start + end)/2;

    if (end < start){
        location = -1;
        return;
    }else if (A[middle] == target){
        location = middle; 
        found = true;
    }else if (A[middle < target]){
        BS(A, target, location, found, middle + 1, end);
    }else{
        BS(A, target, location, found, start, middle - 1);
    }
}