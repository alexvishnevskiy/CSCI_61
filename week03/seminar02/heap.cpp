void insertAtk(){
    while (k > 0){
        int p = parent(k);
        if (A[p] > A[k]){
            swap(A[p], A[k]);
            k = p;
        }else{
            break;
        }
    }
}

//implement heap
