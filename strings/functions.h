#include<iostream>
#include<string.h>
#include <filesystem>

#include <fstream>
// #include "genericHash/components/hash.h"
using namespace std;


int  my_strlen(char* str){
    int length = 0 ;
     while(*str != '\0'){
        length++;
        str++; 
     }
    //   cout<< "Length of the String is: " << length << endl;
      return length ; 
}

int my_strcmp(char* str1, char* str2){
    while(*str1 && *str2){
        if(*str1 != *str2){
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;    
}

void my_strcpy(char* destination, const char* source){
    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

void my_strcat(char* destination, const char* source){
    while(*destination != '\0'){
        destination++;
    }
    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

int my_strchr(char* searchStr , char seacrhChar){
    int i = 0 ; 
    cout<<"enter in chr function";
    while(*searchStr!='\0'){
        i++;
        if(*searchStr==seacrhChar){
            return i+1;
        } 
        searchStr++;
    }
    return -1;
}

int my_strstr(char* str , char* sub){
     int subSize = my_strlen(sub);
     int i = 0 ; int temp;
    while(str[i]!='\0'){ 
         int j = 0 ;
         int size = 0 ;  
        if(str[i]==sub[j]){
                temp = i; 
            while(str[i]==sub[j] && sub[j]!='\0'){
                  size++;
                  j++;
                  i++;
            }
            if(size==subSize){
                return temp;
            }
        }else{
            i++;
        } 
    }
    return -1; 
}

void reverse_inplace(char* str) {
    int start = 0;
    int end = my_strlen(str) - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
} 

void to_lower(char* str) {
    while (*str!='\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 32;
        }
        str++;
    }
}

void to_upper(char* str) {
    while (*str!='\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 32;
        }
        str++;
    }
}

int is_palindrome( char *s){
    to_lower(s);
    int start = 0;
    int end = my_strlen(s) - 1;
    while (start < end) {
        if (s[start] != s[end]) {
            return 0; 
        }
        start++;
        end--;
    }
    return 1;
}

int count_words(const char* str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t') {
            in_word = 0; 
        } else if (in_word == 0) {
            in_word = 1; 
            count++;
        }
        str++;
    }
    return count;
}

// char* most_frequent_word(const char* str) {
//       Hash<int, int> myHash(100);
//     int word_count = 0;
//     char* word = strtok(str, " \n\t");
//     while (word != NULL) {
//         int found = 0;
//         for (int i = 0; i < word_count; i++) {
//             if (strcmp(head[i].key, word) == 0) {
//                 head[i].value++;
//                 found = 1;
//                 break;
//             }
//         }
//         if (!found) {
//             head[word_count].key = new char[my_strlen(word) + 1];
//             my_strcpy(head[word_count].key, word);
//             head[word_count].value = 1;
//             word_count++;
//         }
//         word = strtok(NULL, " \n\t");
//     }
// }
int my_strcasestr(char* str, char* sub) {
    char* lower_str = new char[my_strlen(str) + 1];
    char* lower_sub = new char[my_strlen(sub) + 1];
    
    my_strcpy(lower_str, str);
    my_strcpy(lower_sub, sub);
    
    to_lower(lower_str);
    to_lower(lower_sub);
    
    int index = my_strstr(lower_str, lower_sub);
    
    delete[] lower_str;
    delete[] lower_sub;
    return index;
      
}

void my_strTrim(char* str) {
    char* end = str + my_strlen(str) - 1;

    while (*str == ' ') str++;
    while (end > str && *end == ' ') end--;

    *(end + 1) = '\0';
    
    char* start = str;
    while (*start != '\0') {
        if (*start == ' ' && *(start + 1) == ' ') {
            char* temp = start + 1;
            while (*temp != '\0') {
                *start++ = *temp++;
            }
            *start = '\0';
        } else {
            start++;
        }
    }
}


char* my_strTok(char* str, const char* delimiters) {
    static char* next_token = nullptr;

    if (str != nullptr) {
        next_token = str;
    }

    if (next_token == nullptr || *next_token == '\0') {
        return nullptr;
    }

    char* token_start = next_token;

    while (*next_token != '\0' && strchr(delimiters, *next_token) == nullptr) {
        next_token++;
    }

    if (*next_token != '\0') {
        *next_token = '\0';
        next_token++;
    }

    return token_start;
}

char *my_strCollapse(char* str){
    // cout<<"enter in the collapse string function"<<str;
    int i = 0 , j = 0 ; 
    while(str[i]!='\0'){
        if(str[i]==' '||str[i]=='\n' || str[i]=='\t'){
            if(j > 0 && str[j - 1] != ' ') {
                str[j++] = ' ';
            }
            i++;
        } else {
            str[j] = str[i];
            j++;
             i++;
        }
    }
    return str;
}

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    return result;
}

bool isHtmlResource(char* url) {
    char invalid_ext[][15] = { ".jpg", ".jpeg", ".png", ".gif", ".pdf", ".css", ".js", ".svg", ".ico", ".asp", ".woff2", ".woff", ".webmanifest" };
    
    int count = sizeof(invalid_ext) / sizeof(invalid_ext[0]);
    
    for (int i = 0; i < count; i++) {
        if (my_strstr(url, invalid_ext[i]) != -1) {
            return false;
        }
    }
    
    return true;
}

char* normalizeURL(char* baseURL,  char* relativeURL) {
    static  char result[2083];

    if (my_strstr(relativeURL, (char*)"http://") == 0 || my_strstr(relativeURL, (char*)"https://") == 0) {
        my_strcpy(result, (char*)relativeURL);
        return result;
    }

    if (relativeURL[0] == '/') {
        int idx = my_strstr(baseURL, (char*)"://");
        if (idx == -1) return NULL;
        idx += 3;

        int i = idx;
        while (baseURL[i] != '/' && baseURL[i] != '\0') {
            i++;
        }

        for (int j = 0; j < i; j++) {
            result[j] = baseURL[j];
        }
        result[i] = '\0';

        my_strcat(result, (char*)relativeURL);
        return result;
    }

    int len = my_strlen(baseURL);
    int lastSlash = -1;

    for (int i = len - 1; i >= 0; i--) {
        if (baseURL[i] == '/') {
            lastSlash = i;
            break;
        }
    }

    if (lastSlash != -1) {
        for (int i = 0; i <= lastSlash; i++) {
            result[i] = baseURL[i];
        }
        result[lastSlash + 1] = '\0';
    } else {
        my_strcpy(result,baseURL);
        my_strcat(result, (char*)"/");
    }

    my_strcat(result, relativeURL);
    return result;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Assume your to_lower and my_strstr are defined as above

void removeHTMLTags(const char* input, char* output) {
    int i = 0, j = 0;
    bool insideTag = false;
    bool skipContent = false;
    char tagBuffer[64];
    char lowerTag[64];

    while (input[i]) {
        if (input[i] == '<') {
            insideTag = true;

            // Collect full tag into buffer
            int k = 0;
            int temp = i + 1;  // Skip '<'
            while (input[temp] && input[temp] != '>' && k < sizeof(tagBuffer) - 1) {
                tagBuffer[k++] = input[temp++];
            }
            tagBuffer[k] = '\0';

            to_lower(lowerTag);
            to_lower(tagBuffer);
            // Check for start of <script> or <style>
            if (my_strstr(lowerTag, "script") == 0 || my_strstr(lowerTag, "style") == 0) {
                skipContent = true;
            }

            // Check for end of </script> or </style>
            if (my_strstr(lowerTag, "/script") == 0 || my_strstr(lowerTag, "/style") == 0) {
                skipContent = false;
            }

        } else if (input[i] == '>') {
            insideTag = false;
        } else if (!insideTag && !skipContent) {
            output[j++] = input[i];
        }
        i++;
    }
    output[j] = '\0';
}



bool isHelpingWord(const char* word) {
    const char* stopWords[] = {
        "is", "a", "the", "in", "at", "on", "of", "for", "with", "and", "but", "or", "an", "as",
        "to", "by", "was", "were", "are", "be", "this", "that", "these", "those", "it", "its",
        "from", "has", "have", "had", "not", "can", "will", "would", "could", "should", "do",
        "does", "did", NULL
    };

    for (int i = 0; stopWords[i] != NULL; ++i) {
        if (strcmp(word, stopWords[i]) == 0)
            return true;
    }
    return false;
}

