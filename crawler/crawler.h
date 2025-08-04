#include <cstdlib> 
#include"../fileHandling/components/fileHandling.h"
using namespace std;
 class crawler{
    char url[2083];
    char targetDir[100];
    filehandling* fp;  
    public:
     crawler(char* url , char* targetDir){
             my_strcpy(this->url,url);
             my_strcpy(this->targetDir, targetDir);
             this->fp = new filehandling(this->targetDir);
     }
    bool directoryExists(){
         return fp->dir_exists();
    }
    void  createDir(){
        if(!directoryExists()){
             cout<<"\n in the createDir"<<endl;
             fp->dir_create();
        }
    } 
    void downloadHTML(const char* filename = "page.html") {
        createDir(); 
        char command[2500];
        char filepath[2200];
        my_strcpy(filepath, targetDir);
        my_strcat(filepath, "/");
        my_strcat(filepath, filename);

        sprintf(command, "wget -O \"%s\" \"%s\"", filepath, url);

        cout << "Executing:" << command << endl;
        system(command);  
    }

    void print() {
        cout << "\nurl" << url;
        cout << "\n targetDir" << targetDir << endl;
    }

    ~crawler() {
        delete fp;
    }
};
