#pragma once
#include <iostream>
#include "../List.h"
using namespace std;
template <typename T>
void List<T>::print()
{
    NodeList<T> *current = head; 
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
    NodeList<T> *newNode = new NodeList(data);
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
        NodeList<T> *newNode = new NodeList(data);
        count++;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        NodeList<T> *current = head;
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
     NodeList<T> *newNode = new NodeList(data);
     NodeList<T> *current = head;
    while(current){
         position++;
         if(position==index-1) break;
         current = current->next;
    }
    NodeList<T> *temp =  current->next;
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
    NodeList<T>* current = head;
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
    NodeList<T>* temp = head;
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
    NodeList<T>* current = head;
    int position = 0;

    while (current && position < index - 1) {
        current = current->next;
        position++;
    }
    if (current == NULL || current->next == NULL) {
        cout << "Index out of bounds" << endl;
        return;
    }
    NodeList<T>* temp = current->next;
    current->next = temp->next;
    delete temp;
    count--;
}

template <typename T>
NodeList<T>* List<T>::getHead( ){
    return head;    
}

template <typename T>
NodeList<T>* List<T>::getNode(int index){
    if(index<0 || index>=count){
        cout<<"Invalid index";
        return nullptr;
    }
    NodeList<T>* current = head;
    int position = 0;
    while(current){
        if(position==index) {
            // cout<<current->data<<endl;
            return current;
        }
        position++;
        current = current->next;
    }
}