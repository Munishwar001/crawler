#include<iostream>
#include "components/List.h"
using namespace std;

int main() {
    List<int> myList;
    myList.prepend(2);
    myList.prepend(5);
    myList.prepend(10);
    myList.insertAtEnd(20);
    myList.insertion(50,2);
    myList.pop();
    myList.DeletefromBeging();
    myList.Deletion(1);
    myList.print(); 
    // List<string> obj;
    // obj.prepend("Hello");
    // obj.prepend("World");
    // obj.print();
    return 0;
}