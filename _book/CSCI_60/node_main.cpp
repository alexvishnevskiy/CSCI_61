#include <iostream>
#include "node.h"
#include <cassert>


void printNode(node * & n);
void insertAtHead(node * & head, node * & tail, int data);
void insertAtTail(node * & head, node * & tail, int data);
void insertAtK(node * & head, node * & tail, int index, int data);
void reverse(node * & head);
void copy(node * &, node * &, node * &, node * &);
void deleteAtK(node * & head, node * & tail, int index);
void insertListAtK(node * & head1, node * & tail1, node * & head2, node * & tail2, int index);


int main(){
    node *head, *tail, *head1, *tail1;
    head = tail = nullptr;

    for (int i = 0; i < 5; i++){
        insertAtHead(head, tail, i);
    }
    // std::cout << "before\n";
    // printNode(head);
    // for (int i = 0; i < 10; i++){
    //     insertAtTail(head, tail, i);
    // }
    // insertAtK(head, tail, 4, 30);

    // reverse(head);
    // std::cout << "after\n";
    // printNode(head);
    copy(head, tail, head1, tail1);
    // printNode(head1);
    insertListAtK(head, tail, head1, tail1, 5);
    printNode(head);
    // std::cout << "Deleting" << std::endl;
    // deleteAtK(head1, tail1, 4);
    // printNode(head1);
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
    if (head == nullptr){
        head = tail = temp;
    }else{
        tail->set_link(temp);
        tail = temp;
    }
    
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

// copy from head1 to head2
void copy(node * & head1, node * & tail1, node * & head2, node * & tail2){
    head2 = tail2 = nullptr;
    for (node * temp = head1; temp != nullptr; temp = temp->link()){
        insertAtTail(head2, tail2, temp->data());
    }
}

void deleteAtK(node * & head, node * & tail, int index){
    assert (head != nullptr);
    //assert size > index
    node * temp = head;
    for (int i = 1; i < index; i++){
        temp = temp->link();
    }
    if (temp->link() == tail)
        tail = temp;
    temp->set_link(temp->link()->link());
}

// insert into head1 head2
void insertListAtK(node * & head1, node * & tail1, node * & head2, node * & tail2, int index){
    if (head2 != nullptr){
        node * temp = head1;
        // iterate over first array to get index
        for (int i = 1; i < index; i++){
            temp = temp->link();
        }
        // get the remaining part of first array
        node * remain = temp ->link();
        // join first part of first array with second
        temp->set_link(head2);

        node * temp1 = head2;
        while (temp1->link() != nullptr){
            temp1 = temp1 -> link();
        }
        // join second part
        temp1->set_link(remain);
        // change tail
        if (remain == nullptr)
            tail1 = tail2;
    }
}

// iterative 1: O(n)-time, O(n)-space
// void reverse(node * & head){
//     if (head != nullptr){
//         // start from tail and then iteratively append to tail
//         node * tail = new node(head -> data(), nullptr);
//         head = head -> link();

//         while (head != nullptr){
//             tail = new node(head -> data(), tail);
//             head = head ->link();
//         }
//         head = tail;
//     }
// }

// iterative 2: O(n)-time, O(1)-space
// void reverse(node * & head){
//     // Initialize current, previous and
//     // next pointers
//     node* current = head;
//     node *prev = NULL, *next = NULL;
 
//     while (current != NULL) {
//         // Store next
//         next = current->link();
//         // Reverse current node's pointer
//         current->set_link(prev);
//         // Move pointers one position ahead.
//         prev = current;
//         current = next;
//     }
//     head = prev;
// }

// recursive
// https://www.geeksforgeeks.org/reverse-a-linked-list/
// void reverse(node * & head){
//     if (head == nullptr || head -> link() == nullptr){
//         return;
//     }else{
//         node * first = head;
//         node * rest = head -> link();
//         reverse(rest);
        
//         first -> link() -> set_link(first);
//         first -> set_link(nullptr);

//         head = rest;
//     }
// }