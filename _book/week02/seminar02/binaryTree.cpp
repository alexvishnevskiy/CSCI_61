
void traverseTree(){
    queue<node *> todo;
    todo.enqueu(root);
    while (!todo.empty()){
        node * p = todo.front();
        todo.dequeue();
        if (p){
            cout << *p << ' ';
            // firstly left then right
            todo.enqueue(p->left_children());
            todo.enqueue(p->right_children());
        }
    }
}