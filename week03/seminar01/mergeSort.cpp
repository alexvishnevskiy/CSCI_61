#include <vector>
#include <iostream>
using namespace std;


void merge(vector<int>& A, int start, int middle, int end){
    vector<int> L, R;
    for (int i = start; i <= middle; i++){
        L.push_back(A[i]);
    }
    L.push_back(INT_MAX); //should use additional cell, to avoid problem
    // if L finish first it should use this value to compare with right

    for (int j = middle+1; j <= end; j++){
        R.push_back(A[j]);
    }
    R.push_back(INT_MAX);

    int i = 0, j = 0;
    for (int k = start; k <= end; k++){
        if (L[i] < R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& A, int start, int end){
    if (start == end){
        return;
    }else{
        int middle = (start + end)/2;
        mergeSort(A, start, middle);
        mergeSort(A, middle+1, end);
        merge(A, start, middle, end);
    }
}

void mergeSort(vector<int>& A){
    mergeSort(A, 0, A.size()-1);
}

int main(){
    vector<int> A;
    A.push_back(5);
    A.push_back(3);
    A.push_back(1);
    mergeSort(A);
    for (int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
}