struct node{
    int data;
    node * left;
    node * right;
    node (int val): data(val) {;};
};



bool find(int x, node * p){
    if (p == nullptr) return false;
    if (p->data) return true;
    else if (p->data < x)
        return find(x, p->right);
    else
        return find(x, p->left);
}

void insert(int x, node *& p){//we use call by reference because we modify pointer
    if (p == nullptr)
        p = new node(x);
    
    if (p->data < x)
        insert(x, p->data);
    else if (x < p->data)
        insert(x, p->left);
    else
        return;
}