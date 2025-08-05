#include <cstdlib>
#include <cstdio>
#include <string.h>
// #include "../genericList/components/List.h"
#include "../genericList/components/List.h"
#include "../genericHash/components/hash.h"
#include "../fileHandling/components/fileHandling.h"
using namespace std;
class crawler
{
    char url[2083];
    char targetDir[100];
    int max_depth;
    int current_depth;
    filehandling *fp;
    Hash<char *, bool> myHash;
    List<char *> myList;
    // Node<char*, int> *headURL;

public:
    crawler(char *url, char *targetDir, char *max_depth = "1")
    {
        my_strcpy(this->url, url);
        my_strcpy(this->targetDir, targetDir);
        this->max_depth = stringToInt(max_depth);
        this->fp = new filehandling(this->targetDir);
        current_depth = 0;
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
        if (my_strlen(url) > 0 && my_strchr(url, '/') != -1)
        {
            return true;
        }
        cout << "Invalid URL: " << url << endl;
        return false;
    }

    void extractLinksFromFile(char *filepath)
    {
        cout << "Extracting links from file: " << filepath << endl;
        ifstream file(filepath);
        cout << "before opening" << endl;
        if (!file.is_open())
        {
            cerr << "Failed to open file.\n";
            return;
        }
        char ch;
        int i = 0;
        while (file.get(ch))
        {
            // cout << ch;
            char url[2800];
            int urlLength = 0;
            char startURL[] = "href=";
            if (ch == startURL[i])
            {
                i++;
            }
            else
            {
                i = 0;
            }
            if (startURL[i] == '\0')
            {
                while (file.get(ch))
                {
                    if (ch == '"' || ch == '\'')
                    {
                        break;
                    }
                }
                while (file.get(ch))
                {
                    if (ch == '"' || ch == '\'')
                    {
                        break;
                    }
                    //   cout<<"forming the url";
                    url[urlLength] = ch;
                    urlLength++;
                }
                url[urlLength] = '\0';
                if (isHtmlResource(url))
                {
                    //  myList.insertAtEnd(url);
                    if (myHash.search(url) != -1)
                    {   
                        myHash.insertion(url,false);
                        myList.insertAtEnd(url);
                        my_strcpy(this->url, url);
                        this->current_depth++;
                        this->crawl();
                    }
                    // cout << url << endl;
                }
                i = 0;
            }
        }
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
            extractLinksFromFile(filepath);
        }
    }
    void crawl()
    {
        if (current_depth > max_depth)
        {
            return;
        }
        //   myList.insertAtEnd(url);
        cout<<"url in crawler"<<url; 
        if (myHash.search(url) != -1)
        {
            cout << "Already visited: " << url << endl;
            return;
        }
        
        myHash.insertion(url, true);
        myList.insertAtEnd(url); 
        
        current_depth++;
        downloadHTML();
        // Node<char*>* temp = myList.getHead();
        if (current_depth < max_depth)
        {
            crawl();
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
