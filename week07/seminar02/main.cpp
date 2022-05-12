#include <queue>
using namespace std;


class bag{
    struct node{
        int data;
        node * left;
        node * right;
        node (int d, node * l = nullptr, node * r = nullptr): data(d), left(l), right(r){};
    };
    node * _find(int x){
        node * p = nullptr;
        queue<node *> Q; Q.push(root);
        while (!Q.empty()){
            p = Q.front(); Q.pop();
            if (p){
                if (p->data == x) return p;
                Q.push(p->left); Q.push(p->right);
            }
        }
        return nullptr;
    }
    bool isLeaf(node * p){
        return p&&!p->left&&!p->right;
    }
    node * findleaf(node * p){
        while (!isLeaf(p)){
            if (p->left){
                p = p->left;
            }
            else{
                p = p->right;
            }
        }
        return p;
    }
    node * find_parent(node * p){
        queue<node *> Q; Q.push(root);
        while (!Q.empty()){
            node * p = Q.front(); Q.pop();
            if (p){
                if ((p->left == a)
                    || (p->right == a))
                    return p;
                Q.push(p->left); Q.push(p->right);
            }
        }
        return nullptr;
    }
    node * root;
public:
    bag(): root(nullptr) {};
    ~bag(){clear(root);};
    bag(const bag& other): root(nullptr) {*this = other;};
    bag& operator = (const bag & other){
        if (this == &other) return *this;
        clear(root);
        root = copy(other.root);
        return *this;
    };
    void add(int x){
        queue<node *> Q; Q.push(root);
        node * p =  nullptr;
        while (!Q.empty()){
            p = Q.front(); Q.pop();
            if (p){
                if (!(p->left && p->right))
                    break;
                Q.push(p->left); Q.push(p->right);
            }
        }

        if (p == nullptr)
            root = new node(x);
        else{
            if (p->left)
                p->right = new node(x);
            else
                p->left = new node(x);
        }
    }
    bool find(int x){
        return _find(x);
    }
    void remove(int x){
        // find a node for value x
        node * p = _find(x);
        if (isLeaf(p)){
            node * pp = find_parent(p);
            if (!pp)
                delete root;
            else{
                if (pp->left == p)
                    delete pp->left;
                else
                    delete pp->right;
            }
        }
        if (p){
            // find first leaf for p
            node * leaf = findleaf(p);
            // swap the value of p with leaf
            p->data = leaf->data;
            // find the parent of the leaf
            node * pleaf = find_parent(leaf);
            // if leaf is the left child -> delete
            if (pleaf->left == leaf)
                delete pleaf->left;
            // if leaf is the right child -> delete
            else
                delete pleaf->right;
        }
    }
};