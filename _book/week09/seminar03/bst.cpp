// BST for short

/*

  doesn't have to be complete
  right is larger left is smaller

  this is going to be a bitch to write

  largest(left substree) < value(node) < smallest(right subtree)
*/

class BST{
public:
  void add(int x);
  bool find(int x);
  bool remove(int x);

private:
  struct node{
    int data;
    node* right;
    node* left;

    node(int d, node* rc = nullptr, node* lc = nullptr) :
      data(d), right(rc), left(lc) {};
  };
  node* root;

};

void BST::add(int x, node*& p){
  if (p == nullptr)
    p = new node(x);

  if (value < p->data)
    add(x, p->left;
  else if(p->data < x)
    add(x, p->right);
  else
    return;
}

bool BST::find(int x, node* p){
  if (p == nullptr) return false;

  if (p->data == x)
    return true;
  else if(p->data < x)
    return find(x, p->right);
  else
    return find(x, p->left);

}

node* findMax(node* p){
  if (p == nullptr) return nullptr; // should be impossible to hit

  if (p->right == nullptr) // base case
    return p;
  else
    findMax(p->right);
}

void BST::remove(int target, node*& p){
  // pass p by refrence so you can modify the node directly
  // (so you don't need to re-find the node and/or parent)

  if (p == nullptr) return;

  if (target < p->data)
    remove(target, p->left);
  else if (p->data < target)
    remove(target, p->right);
  else if (p->left == nullptr || p->right == nullptr) {
    // target == p->data (certainty)
    temp = p;
    p = (p->left ? p->left : p->right); // p = the non-null ptr (if exists)
    delete temp;
  } else { // target == p->data (still a certainty) but both children exist
    // max of left case
    node* temp = findMax(p->left);
    p->data = temp->data;
  }
}

void BST::remove(int target, node* p){
  remove(target, root);
}