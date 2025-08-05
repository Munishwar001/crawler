#include<iostream>
using namespace std;
template<typename T>
class NodeList{
   public:
       T data;
       NodeList<T>* next;
         NodeList(T data){
            this->data = data ;
            this->next = NULL;
         }
};