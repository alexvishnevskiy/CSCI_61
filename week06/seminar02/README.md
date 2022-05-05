## Binary tree

![bnode](../../static/week06/bnode.jpg)

How to represent the tree using bnode clas?

    bnode * root;
    root = new node('a', nullptr, new bnode('c', new node('d'), new bnode('f', new bnode('g'))))

There are two algorithms to traverse a tree:

1) Breadth first
2) Depth first

Variants of depth first traversals: preorder, inorder, postorder
![btree1](../../static/week06/b_tree1.jpg)

How can we traverse a tree?
![btree2](../../static/week06/b_tree2.jpg)

How to make a tree from an array?
![btree3](../../static/week06/b_tree3.jpg)