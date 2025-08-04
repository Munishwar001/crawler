#include <iostream>
#include <fstream>
#include <iostream>
#include "../../strings/functions.h"
#include <filesystem>
using namespace std;
class filehandling{
   char path[150];
   public:
    // filehandling(char* path){
    //    my_strcpy(this->path , path);
    // }
     filehandling(char* targetDir) {
        my_strcpy(this->path, "public/");     
        my_strcat(this->path, targetDir); 
    }

   bool dir_exists(){
      if (filesystem::exists(path)) {
        if (filesystem::is_directory(path)) { 
            return true;
        } else {
            return false;
        }
    } else {
         cout << "Directory does not exist: " << path << std::endl;
          return false;
    }
   }
   bool dir_create(){
       if(!dir_exists()){ 
        cout<<"in create dir"<<endl;
           filesystem::create_directories(path);
           return true;
       }
       return false;
   }
   int countWords( ){
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

};