#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

int countWords(char* path){
     ifstream in(path);

    if (!in.is_open())
    {
        cerr << "Failed to open file";
    }
    string word;
    int count = 0 ; 
    while (in >> word)
    {
        count++;
    }
    cout<<"the words are "<<count;
    in.close(); 
    return count ; 
}

void append(){
    
}