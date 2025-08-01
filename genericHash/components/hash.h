#pragma once
#include <iostream>
#include "Node.h"
#include "functions/indexFinder.h"
using namespace std; // Munishwar tu kar sakta h
template <typename keyType, typename valueType>
class Hash
{
      Node<keyType, valueType> **head;
      int noOfElements;
      int size;

public:
      Hash(int size)
      {
            this->size = size;
            this->head = new Node<keyType, valueType> *[size];
            this->noOfElements = 0 ; 
            for (int i = 0; i < size; i++)
            {
                  head[i] = NULL;
            }
      }
      void insertion(keyType key, valueType value);
      void search(keyType key);
      void deleteElement(keyType key);
      void display();
      // void reSize();
};
#include "functions/hashFunctions.tpp"