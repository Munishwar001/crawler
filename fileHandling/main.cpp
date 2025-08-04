#include <iostream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <filesystem>
#include "../fileHandling/functions.h"
using namespace std;
int main()
{ 
    // task1
    // cout << "Enter the file path: ";
    // char path[50];
    // fgets(path, 50, stdin);
    // path[strcspn(path, "\n")] = 0;
    // if (!filesystem::exists(path))
    // {
    //     cerr << "File does not exist." << endl;
    //     return 1;
    // }
    // int words = countWords(path);
    // cout << "Total words in the file: " << words << endl;

    // Task2
    ifstream T2in("pic.png", ios::binary);
    ofstream T2o("dest.png", ios::binary);
    T2o << T2in.rdbuf();

    // Task3
    string info = "hewlo hewlo";

    ofstream writer("text.txt", ios::app);

    if (!writer)
    {
        cout << "Error opening file: " << endl;
        return -1;
    }
    writer << info << endl;
    writer.close();

    //Task4
     
    return 0;
}