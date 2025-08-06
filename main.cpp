#include<iostream>
#include"./crawler/crawler.h"
using namespace std;
int main(int argc ,char* argv[]){
    if(argc<4){
         cerr<<"please make sure your input is in ./crawler [SEED_URL] [TARGET_DIRECTORY] [MAX_CRAWLING_DEPTH]";
         return -1;
    }

     crawler cr(argv[1],argv[2] ,argv[3]);
      cout<< "directory exists"<<cr.directoryExists();
     // cr.createDir();
     // cr.downloadHTML();
     // cr.crawlWithURL(argv[1]);
     // cr.crawl();
     // cr.validateURL(argv[1]);
     cr.start();
     // cr.extractLinksFromFile("public/storage/1754304723.html");
     // cr.print();
}