#include <iostream>
#include "../genericHash/components/hash.h"
using namespace std;
int main()
{   
    cout<<"Enter the size that you want \n";
    // int size1; cin>>size1;
    Hash<char *, int> myHash; 
    int choice;
    do{
    cout<<"********SELECT CHOICES*********\n";
    cout<<"Enter 1 for Insertion\n";
    cout<<"Enter 2 for Search\n";
    cout<<"Enter 3 for Deletion\n";
    cout<<"Enter 4 for Display All\n";
    cout<<"Enter 0 for Exit All\n";
    cin>>choice;
    switch(choice){
        case 1:
            char* key;
            int  value;
            cout<<"Enter the key and value to insert\n";
            cin>>key>>value;
            myHash.insertion(key, value);
            break;
        case 2:
            cout<<"Enter the key to search\n";
            cin>>key;
            myHash.search(key);
            break;
        case 3:
            cout<<"Enter the key to delete\n";
            cin>>key;
            myHash.deleteElement(key);
            break;
        case 4: 
            cout<<"Displaying all elements:\n";
            myHash.display();
            break;
        case 0:
            cout<<"Exiting...\n";
            break;
        default:
            cout<<"Invalid choice, please try again.\n";
    }
}while(choice);
    return 0;
}