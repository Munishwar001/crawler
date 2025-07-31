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
    void print();
};


#include "functions/List.tpp"
