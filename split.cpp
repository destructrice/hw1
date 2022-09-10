/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */
void append(Node*& head, int a) {
    Node n = new Node(a, *head);
    *head = n;
}
Node remove(Node*&head){
    if(head == nullptr){
        return nullptr;
    }
    Node*temp=head;
    head= head->next;
    return reinterpret_cast<Node &&>(temp);
}

void split(Node*& in, Node*& odds, Node*& evens) {
    Node* curr = in;
    if(curr->value % 2 == 0){
        append(evens, remove())
    }
    *odds = curr;
    *evens = curr->next;


}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE