#include <vector>
using namespace std;


//b-beginning, e-ending
int smallest(vector<int>& A, int b, int e){ //look for smallest element in A[b]->A[e]
    int smallest_index = b;
    for (int i = b+1; i <= e; i++){
        if (A[i] < A[smallest_index]){
            smallest_index = i;
        }
    }
    return smallest_index;
}

void selectionSort(vector<int>& A, int b, int e){
    for (int j = b; j < e; j++){
        int si = smallest(A, j, e);
        swap(A[j], A[si]);
    }
}

void insertionSort(vector<int>& A, int b, int e){
    for (int i = b+1; i<=e; i++){
        int key = A[i];
        int j = i-1;
        while ((key < A[j]) && (j >= b)){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}