#pragma once
#include <iostream>
#include "../List.h"
using namespace std;
template <typename T>
void List<T>::print()
{
    Node<T> *current = head; 
    cout<<"size of list is "<<count<<"\n";
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

template <typename T>
void List<T>::prepend(T data)
{
    Node<T> *newNode = new Node(data);
    count++;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

template <typename T>
void List<T>::insertAtEnd(T data)
    {
        Node<T> *newNode = new Node(data);
        count++;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node<T> *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

template <typename T>
void List<T>::insertion(T data , int index){
     if(index<0 || index>count){
        cout<<"Invalid index";
        return;
     }
     int position = 0 ;
     Node<T> *newNode = new Node(data);
     Node<T> *current = head;
    while(current){
         position++;
         if(position==index-1) break;
         current = current->next;
    }
    Node<T> *temp =  current->next;
    current->next = newNode;
    newNode->next = temp; 
}    

template <typename T>
void List<T>::pop(){
      if(head==NULL){
        cout<<"List is already Empty";
        return ;
    }
        if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node<T>* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
    count--;
}    

template <typename T>
void List<T>::DeletefromBeging(){
    if(head==NULL){
        cout<<"List is already Empty";
        return ;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    count--;
}

template <typename T>
void List<T>::Deletion(int index){
    if(head==NULL){
        cout<<"List is already Empty";
        return ;
    }
    if(index<0 || index>=count){
        cout<<"Invalid index";
        return;
    } 
    if(index==0){
        DeletefromBeging();
        return;
    }
    Node<T>* current = head;
    int position = 0;

    while (current && position < index - 1) {
        current = current->next;
        position++;
    }
    if (current == NULL || current->next == NULL) {
        cout << "Index out of bounds" << endl;
        return;
    }
    Node<T>* temp = current->next;
    current->next = temp->next;
    delete temp;
    count--;
}
