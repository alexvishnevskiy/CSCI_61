#include <iostream>
using namespace std; // namespace std;


struct node{
    int val;
    node * next;
    node(int a, node * b){
        val = a;
        next = b;
    }
};

void _swap(node * A, node * B){
    int tmp = A->val;
    A->val = B->val;
    B->val = tmp;
}

void swap(node * head, int i, int j){
    node * tmp1, *tmp2;
    tmp1 = tmp2 = head;

    while (i > 0){
        tmp1 = tmp1 -> next;
        i--;
    }
    while (j > 0){
        tmp2 = tmp2 -> next;
        j--;
    }
    _swap(tmp1, tmp2);
}

int indexAt(node * head, int i){
    node * tmp = head;
    while (i > 0){
        tmp = tmp->next;
        i--;
    }
    return tmp->val;
}

int partition(node * head, int start, int end){
    if (start == end) //for one element
        return start;

    int pivot = indexAt(head, start);
    int pivot_index = start;
    int i = start + 1; // we can pick another pivot, for example median
    int j = end;
    
    while (i <= j) {
        while ((i <= end) && (indexAt(head, i) <= pivot)){ // check for condition and also the end of array
            i++;
        }
        while ((j >= start) && (indexAt(head, j) > pivot)){ // check for condition and also the start of array
            j--;
        }
        if (i < j){ // if we skip this condition, we can break the order
            swap(head, i, j);
        }
    }
    swap(head, pivot_index, j);
    return j; // return pivot location
}

void QuickSort(node * head, int start, int end){
    // if (start + 10 <= end) insertionSort(A, start, end); 
    // if there are 10 elements it is likely that list is nearly sorted
    // and it is better to use another algorithm
    if (start >= end){ // when two element there is a case when (pivot - 1) < start
                       // for example [0, 14]
        return;
    }else{
        int pivot_index = partition(head, start, end);
        QuickSort(head, start, pivot_index-1);
        QuickSort(head, pivot_index+1, end);
    }
}

int main(){
    node * A = nullptr;
    srand(time(0));
    for (int i = 0; i < 10; i++){
        A = new node(rand()%30, A);
    }

    QuickSort(A, 0, 9);

    for (node * tmp = A; tmp != nullptr; tmp = tmp -> next){
        cout << tmp->val << ' ';
    }
    return 0;
}