
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
    Hash<char *, char*> myHash;
    List<char *> myList;

public:
    crawler(char *url, char *targetDir, char *max_depth)
    {
        my_strcpy(this->url, url);
        my_strcpy(this->targetDir, targetDir);
        this->max_depth = stringToInt(max_depth);
        this->fp = new filehandling(this->targetDir);
        // current_depth = 0;
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
    bool validateURL(char *urlToCheck)
    {
        char validation[3000];
        my_strcpy(validation, "wget --spider -q ");
        my_strcat(validation, urlToCheck);
        if (system(validation) == 0)
        {
            return true;
        }
        // cout << "Invali url";
        return false;
    }

    void extractLinksFromFile(char *filepath, int depth)
    {
        if (depth >= max_depth)
            return;

        ifstream file(filepath);
        if (!file.is_open())
        {
            cerr << "Failed to open file.\n";
            return;
        }

        char ch;
        int i = 0;
        while (file.get(ch))
        {
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
                        break;
                }

                while (file.get(ch))
                {
                    if (ch == '"' || ch == '\'')
                        break;
                    url[urlLength++] = ch;
                }

                url[urlLength] = '\0';
                if (isHtmlResource(url))
                {    
                    crawl(url, depth + 1);
                }
                else
                {
                    i = 0;
                }
            }
        }
    }

    char *downloadHTML(char *urlToDownload)
    {
        createDir();
        if (!validateURL(urlToDownload))
        {
            cout << "Invalid URL. Cannot download HTML." << endl;
            return NULL;
        }

        static char filepath[2200];
        static char filename[200];
        char command[2500];
        clock_t currentTime = time(0);
        sprintf(filename, "%ld.html", currentTime);

        my_strcpy(filepath, "public/");
        my_strcat(filepath, targetDir);
        my_strcat(filepath, "/");
        my_strcat(filepath, filename);

sprintf(command, "wget -q -O \"%s\" \"%s\"", filepath, urlToDownload);

        // cout << "Executing:" << command << endl;
        int result = system(command);
        if (result != 0)
        {
            cout << "Error downloading HTML from " << urlToDownload << endl;
            return NULL;
        }
        else
        {
            cout << "HTML downloaded successfully to " << filepath << endl;
            return filepath;
        }
    }

    void crawl(char *currentUrl, int depth)
    {
        // cout<< "DEPTH : " << depth;
        if (depth >= max_depth || !validateURL(currentUrl))
            return;
          
        if (myHash.search(currentUrl) != -1)
        {
            // cout << "\nAlready visited: " << currentUrl << endl;
            return;
        }
        
        char *filepath = downloadHTML(currentUrl);
        myHash.insertion(currentUrl, filepath);
        cout<<"\n depth: "<<depth<<" currentURL :"<<currentUrl;
        myList.insertAtEnd(currentUrl);
        if (filepath != NULL)
        {
            extractLinksFromFile(filepath, depth);
        }
    }

    void start()
    {
        if (!validateURL(url))
        {
            cout << "Your url is not valid " << url;
            return;
        }
        crawl(url, 0);
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