#pragma once
#include <iostream>
#include "Node.h"
#include "functions/indexFinder.h"
using namespace std; 
template <typename keyType, typename valueType>
class Hash
{
      Node<keyType, valueType> **head;
      int noOfElements;
      int size;

public:
      Hash( )
      {
            this->size =2;
            this->head = new Node<keyType, valueType> *[size];
            this->noOfElements = 0 ; 
            for (int i = 0; i < size; i++)
            {
                  head[i] = NULL;
            }
      }
      void insertion(keyType key, valueType value);
      int search(keyType key);
      void deleteElement(keyType key);
      void display();
      void reSize();
      void insertUsingKey(keyType key);
      int increment(keyType key);
      ~Hash();
};
#include "functions/hashFunctions.tpp"