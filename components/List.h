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
    void print();
};

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
    count--;
     Node<T> *current = head;
    while(current->next->next!=NULL && current->next!=NULL){
         current = current->next;
    }
     current->next = NULL;
}    
