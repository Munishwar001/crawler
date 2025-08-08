
#include <cstdlib>
#include <cstdio>
#include <string.h>
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
    Hash<char *, char *> myHash;
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

    void extractLinksFromFile(char *filepath, int depth, char *baseURL)
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
                    char *normalized = normalizeURL(baseURL, url);
                    // cout<<"\n normalize url"<<normalized;
                    if (normalized != NULL)
                        crawl(normalized, depth + 1);
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

   
void countFileWordFrequencies(char *filepath)
{
    ifstream file(filepath);
    if (!file.is_open())
    {
        cerr << "Failed to open file.\n";
        return;
    }
    // cout<<"inside the file"<<filepath;
    char line[5000];
    char cleanedLine[5000];

    Hash<char *, int> wordFreq;
    char mostFrequentWord[100] = "";
    int highestCount = 0;

    ofstream debugFile("debug_tokens.txt", ios::app);
    debugFile << "file: " << filepath << endl;
    bool skipContent = false;
    while (file.getline(line, sizeof(line)))
    {
        removeHTMLTags(line, cleanedLine ,skipContent);
        if(cleanedLine == NULL || cleanedLine=="") continue;
        char *token = strtok(cleanedLine, " \t\n\r.,;:!?()[]{}<>\"\'");
        // cout<<"token"<<token<<endl;
        while (token != NULL)
        {
            to_lower(token);
            if (!isHelpingWord(token))
            {
                debugFile << token << endl;
                int index = wordFreq.search(token);
                if (index == -1)
                {
                    // char *wordCopy = new char[strlen(token) + 1];
                    // strcpy(wordCopy, token);
                    wordFreq.insertion(token, 1);
                    if (highestCount < 1)
                    {
                        highestCount = 1;
                        strcpy(mostFrequentWord, token);
                    }
                    // delete[] wordCopy;
                }
                else
                {
                    int currCount = wordFreq.increment(token);
                    if (currCount > highestCount)
                    {
                        highestCount = currCount;
                        strcpy(mostFrequentWord, token);
                    }
                }
            } 
            // cout<<"token"<<token<<endl;
            token = strtok(NULL, " \t\n\r.,;:!?()[]{}<>\"\'");
        }
    }

    debugFile.close();
    file.close();

    if (highestCount > 0)
    {
        cout << "\n Most Frequent Word: " << mostFrequentWord << "\n";
    }
}

    void crawl(char *currentUrl, int depth)
    {
        // cout<< "DEPTH : " << depth;
        if (depth > max_depth || !validateURL(currentUrl))
            return;

        if (myHash.search(currentUrl) != -1)
        {
            // cout << "\nAlready visited: " << currentUrl << endl;
            return;
        }

        char *filepath = downloadHTML(currentUrl);
        myHash.insertion(currentUrl, filepath);
        cout << "\n depth: " << depth << " currentURL :" << currentUrl;
        myList.insertAtEnd(currentUrl);
        if (filepath != NULL)
        {
            countFileWordFrequencies(filepath);
            extractLinksFromFile(filepath, depth, currentUrl);
        }
    }

    void start()
    {
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