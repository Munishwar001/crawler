#include<iostream>
#include "../genericHash/components/hash.h"
using namespace std;
int main(){
   Hash<int,int> myHash;
   myHash.insertion(5,4);
   myHash.search(5);
   myHash.display();
    return 0 ; 
}