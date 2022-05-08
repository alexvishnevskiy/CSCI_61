#include <queue>
#include <iostream>
using namespace std;


struct bnode{
    char data;
    bnode * left;
    bnode * right;
    bnode(char d, bnode * left, bnode * right){
        data = d;
        this->left = left;
        this->right = right;
    }
};

bnode * convert_from_array_to_tree(char A[]){
    // we want to create binary tree from an array using queue
    // suppose array has 6 elements
    queue<bnode *> Q;
    bnode * root = new bnode(A[0]);
    Q.push(root);
    int i = 1;
    while (i < 6){
        bnode * p = Q.front(); Q.pop();
        p->left = new bnode(A[i++]);
        //if we have right left
        if (i < 6)
            p->right = new bnode(A[i++]);
        Q.push(p->left);
        Q.push(p->right);
    }
    return root;
}

// How to traverse a tree depth first
void DF(bnode * p){
    if (p == nullptr) return;
    cout << p->data; //preorder
    DF(p->left);
    //cout << p->data; inorder
    DF(p->right);
    //cout << p->data; postorder
}

// How to count the number of nodes
int count(bnode * p){
    if (p == nullptr)
        return 0;
    return 1 + count(p->left) + count(p->right);
}

// How to clean the tree?
void clear(bnode *& p){
    if (p){
        clear(p->left);
        clear(p->right);
        delete p;
    }
}