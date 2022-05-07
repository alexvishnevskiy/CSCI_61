#include <vector>
#include <iostream>
using namespace std;


int partition(vector<int>& A, int start, int end){
    if (start == end) //for one element
        return start;

    int pivot = A[start];
    int pivot_index = start;
    int i = start + 1; // we can pick another pivot, for example median
    int j = end;
    
    while (i <= j) {
        while ((i <= end) && (A[i] <= pivot)){ // check for condition and also the end of array
            i++;
        }
        while ((j >= start) && (A[j] > pivot)){ // check for condition and also the start of array
            j--;
        }
        if (i < j){ // if we skip this condition, we can break the order
            swap(A[i], A[j]);
        }
    }
    swap(A[pivot_index], A[j]);
    return j; // return pivot location
}

void QuickSort(vector<int>& A, int start, int end){
    // if (start + 10 <= end) insertionSort(A, start, end); 
    // if there are 10 elements it is likely that list is nearly sorted
    // and it is better to use another algorithm
    if (start <= end){ // when two element there is a case when partion - 1 < start
                       // for example [0, 14]
        return;
    }else{
        int pivot_index = partition(A, start, end);
        QuickSort(A, start, pivot_index-1);
        QuickSort(A, pivot_index+1, end);
    }
}


int main(){
    vector<int> a;

    a.push_back(14);
    a.push_back(0);
    // a.push_back(1);
    // a.push_back(2);
    QuickSort(a, 0, 1);

    // for (int x: a){
    //     cout << x << " ";
    // }
    return 0;
}