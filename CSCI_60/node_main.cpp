#include <iostream>
#include "node.h"
#include <cassert>


void printNode(node * & n);
void insertAtHead(node * & head, node * & tail, int data);
void insertAtTail(node * & head, node * & tail, int data);
void insertAtK(node * & head, node * & tail, int index, int data);


int main(){
    node *head, *tail;
    head = tail = nullptr;

    for (int i = 0; i < 10; i++){
        insertAtHead(head, tail, i);
    }
    printNode(head);
    for (int i = 0; i < 10; i++){
        insertAtTail(head, tail, i);
    }
    insertAtK(head, tail, 4, 30);
    printNode(head);
    return 0;
}


void printNode(node * & n){
    for (node *t = n; t != nullptr; t = t->link()){
        std::cout << t->data() << std::endl;
    }
}

void insertAtHead(node * & head, node * & tail, int data){
    node * temp = new node(data, head);
    if (tail == nullptr)
        tail = temp;
    head = temp;
}

void insertAtTail(node * & head, node * & tail, int data){
    node * temp = new node(data, nullptr);
    tail->set_link(temp);
    if (head == nullptr)
        head = temp;
    tail = temp;
}

void insertAtK(node * & head, node * & tail, int index, int data){
    if (index > 0)
        assert(head != nullptr && tail != nullptr);

    if (index == 0){
        insertAtHead(head, tail, data);
    }else{
        node * temp1 = head;
        for (int i = 0; i < index; i++){
            temp1 = temp1->link();
        }
        node * temp2 =  new node(data, temp1->link());
        temp1->set_link(temp2);
    }
}