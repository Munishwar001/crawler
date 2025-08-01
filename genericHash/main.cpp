#include <iostream>
#include "../genericHash/components/hash.h"
using namespace std;
int main()
{   
    cout<<"Enter the size that you want \n";
    int size1; cin>>size1;
    Hash<int, int> myHash(size1);
    myHash.insertion(5, 4);
    myHash.display();

    return 0;
}