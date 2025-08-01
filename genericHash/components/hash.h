#include <iostream>
#include "Node.h"
#include "functions/indexFinder.h"
using namespace std;  // Munishwar tu kar sakta h 
template<typename keyType, typename valueType>
class Hash {
      Node<keyType, valueType>** head;
      int size;
      public:
      Hash(){
             this->size = 10 ; 
             this->head = new Node<keyType, valueType>*[size];
             for(int i = 0; i < size; i++) {
                  head[i] = NULL;
             }
      }
      void insertion(keyType key, valueType value){
            int index =getIndex(key ,size);
            // cout<<"Index is =>"<<index<<endl ; 
            Node<keyType, valueType>* newNode = new Node<keyType, valueType>(key, value); 
            // cout<<"abcdes key"<<key<<endl ; 
            if(head[index]==NULL){
                  head[index] = newNode;
                  // cout<<"inserted with value"<<value<<endl ; 
                  return ; 
            } 
             Node<keyType, valueType>* current = head[index]; 
            while(current->next!=NULL){
                  current = current->next;
            }
            current->next = newNode;
      }
     void search(keyType key){
        int index =getIndex(key ,size);
         if(head[index]==NULL){
                  cout<<"Element not present";
                  return ; 
            } 
            Node<keyType,valueType>* current = head[index];
          while(current){
             if(current->key ==key){
                  cout<<"value for your key: "<<key<<" is "<<current->value<<endl;
                  return;
            }
            current = current->next;
          }
          cout<<"Element not present"<<endl;
          return ;    
     }

     void deleteElement (keyType key){
        int index =getIndex(key ,size);
         if(head[index]==NULL){
            cout<<"The Element is already not exist";
            return ; 
         }
         if(head[index]->key == key){
            head[index] = head[index]->next;
            cout<<"Element with the key "<<key<<" is deleted"<<endl;
            return;
         }
        Node<keyType,valueType>* current = head[index];
        Node<keyType,valueType>* prev = NULL ; 
        while(current){
             if(current->key==key){
                  cout<<"element with the key: "<<key<<" is Deleted";
                  prev->next = current->next;
                  return;
             }
             prev = current;
             current = current->next;
        }
        return;
     } 
     void display(){
            for(int i=0 ; i<size ; i++){
                  while(head[i]){
                        cout<<"key "<<head[i]->key<<" value "<<head[i]->value;
                        head[i] = head[i]->next;
                  }
            }
            return;
       } 

};