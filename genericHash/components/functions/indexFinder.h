#include<iostream>
using namespace std;

int getIndex(int key , int size){
    return key%size;
}

int getIndex(float key  , int size){
    return ((int)key)%size;
}

int getIndex(char key , int size){
    return ((int)key)%size;
}

int getIndex(string key , int size){
     int strSize = key.size();
     int sum = 0 ; 
     for(int i=0 ; i<strSize ; i++){
            sum+= (int)key[i];
     }
     return  sum%size;
}

int getIndex(char* key , int size){
     int i = 0 ;
     int sum = 0 ;  
     while(key[i]!='\0'){
         sum+= (int)key[i];
         i++;
     }
     return  sum%size;
}