#include<iostream>
using namespace std;
template<typename keyType, typename valueType>
class Node {
   public:
       keyType key;
       valueType value;
       Node<keyType, valueType>* next;

       Node(keyType key, valueType value) {
           this->key = key;
           this->value = value;
           this->next = NULL;
       }
};