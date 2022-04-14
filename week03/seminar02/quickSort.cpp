#include <vector>


int partition(vector<int>& A, int start, int end){
    int pivot = A[start];
    int pivot_index = start;
    int i = start + 1; // we can pick another pivot, for example median
    int j = end;

    while (i <= j) {
        while ((i <= end) && (A[i] <= pivot)){
            i++;
        }
        while ((j >= start) && A[j] > pivot)){
            j--;
        }
        if (i < j){
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
    if (start == end) return;
    int pivot_index = partition(A, start, end);
    QuickSort(A, start, pivot_index-1);
    QuickSort(A, pivot_index, end);
}
