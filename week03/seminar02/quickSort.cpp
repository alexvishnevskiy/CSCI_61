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

int medianPartition(vector<int>& A, int start, int end) {
    if (start == end) //for one element
        return start;

    int pivot_index = start + ((end - start) / 2);
    if(start != pivot_index) swap(A[start], A[pivot_index]);
    pivot_index = start;
        
    int i = start + 1; // we can pick another pivot, for example median
    int j = end;
    int pivot = A[pivot_index];

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
    if (start >= end){ // when two element there is a case when (pivot - 1) < start
                       // for example [0, 14]
        return;
    }else{
        int pivot_index = medianPartition(A, start, end);
        QuickSort(A, start, pivot_index-1);
        QuickSort(A, pivot_index+1, end);
    }
}


int main(){
    vector<int> a(10);

    srand(time(0));
    for (int i = 0; i < 10; i++){
        a[i] = rand()%20;
    }
    QuickSort(a, 0, a.size()-1);

    for (int x: a){
        cout << x << " ";
    }
    return 0;
}