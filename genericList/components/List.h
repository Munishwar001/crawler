#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template <typename T>
class List
{
    Node<T> *head;
    int count;
public:
    List()
    {
        this->head = NULL;
        count = 0; 
    }
    void prepend(T data);
    void insertAtEnd(T data);
    void insertion(T data , int index);
    void pop();
    void DeletefromBeging();
    void Deletion(int index);
    Node<T>* getNode(int index);
    void print();
   ~List(){
        Node<T>* current = head;
        while (current != NULL) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
        count = 0; 
    }
   
};


#include "functions/List.tpp"
