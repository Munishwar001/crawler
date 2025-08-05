#include <cstdlib>
#include<cstdio>
#include "../fileHandling/components/fileHandling.h"
using namespace std;
class crawler
{
    char url[2083];
    char targetDir[100];
    int max_depth;
    filehandling *fp;

public:
    crawler(char *url, char *targetDir , char *max_depth = "1")
    {
        my_strcpy(this->url, url);
        my_strcpy(this->targetDir, targetDir);
        this->max_depth = stringToInt(max_depth);
        this->fp = new filehandling(this->targetDir);
    }
    bool directoryExists()
    {
        return fp->dir_exists();
    }
    void createDir()
    {
        if (!directoryExists())
        {
            cout << "\n in the createDir" << endl;
            fp->dir_create();
        }
    }
    bool validateURL()
    {
        if (my_strlen(url) > 0 && my_strchr(url, '/') != -1 && (my_strstr(url, "http") != -1 || my_strstr(url, "https") != -1))
        {
            return true;
        }
        cout << "Invalid URL: " << url << endl;
        return false;
    }
   

    void downloadHTML()
    {
        createDir();
        if (!validateURL())
        {
            cout << "Invalid URL. Cannot download HTML." << endl;
            return;
        }
        char command[2500];
        char filepath[2200];
        char filename[200];
        clock_t currentTime = time(0);
        sprintf(filename, "%ld.html", currentTime);
        my_strcpy(filepath, "public/");
        my_strcat(filepath, targetDir);
        my_strcat(filepath, "/");
        my_strcat(filepath, filename);

        sprintf(command, "wget -O \"%s\" \"%s\"", filepath, url);

        cout << "Executing:" << command << endl;
        int result = system(command);
        if (result != 0)
        {
            cout << "Error downloading HTML from " << url << endl;
        }
        else
        {
            cout << "HTML downloaded successfully to " << filepath << endl;
        }
    }
  

    void print()
    {
        cout << "\nurl" << url;
        cout << "\n targetDir" << targetDir << endl;
        cout << "\n max_depth" << max_depth << endl;
    }

    ~crawler()
    {
        delete fp;
    }
};
