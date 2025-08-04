#include <iostream>
#include <string>
#include "../strings/functions.h"
using namespace std;
int main()
{
    int choice;
    do
    {
        cout << "******** Select String Operations********\n";
        cout << "1. Length\n";
        cout << "2. Compare\n";
        cout << "3. Copy\n";
        cout << "4. Cancatenat\n";
        cout << "5. Search Char First Occurance\n";
        cout << "6. Search substring in String\n";
        cout << "7. Reverse in Place String\n";
        cout << "8. Check String is Palindrome or NOT\n";
        cout << "9. Count the Number of Words in a String\n";
        cout<<"10. check the subString eist or not using lowerCase\n";
        cout<<"11.  \n";
        cout<<"12. Remove extra spaces form the string\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        char str8[] = "Hello World"; 
        char str9[] = "Hello World Hello";
            char str10[] = "This    is   a   test   string   with  extra spaces.";
        switch (choice)
        {
        case 1:
            cout << "Enter String \n";
            char str[50];
            cin >> str;
            cout << "Length of String is" << my_strlen(str);
            break;
        case 2:
            char str1[50];
            char str2[50];
            cout << "Enter first String \n";
            cin >> str1;
            cout << "Enter second String \n";
            cin >> str2;
            if (!my_strcmp(str1, str2))
            {
                cout << "\nBoth are same\n";
            }
            else
            {
                cout << "\nBoth are not same\n\n";
            }
            break;
        case 3:
            char source[50], destination[50];
            cout << "Enter source String \n";
            cin >> source;
            my_strcpy(destination, source);
            cout << "Copied String: " << destination << endl;
            break;
        case 4:
            char str3[50], str4[50];
            cout << "Enter first String \n";
            cin >> str3;
            cout << "Enter second String \n";
            cin >> str4;
            my_strcat(str3, str4);
            cout << "Concatenated String: " << str3 << endl;
            break;
        case 5:
            char searchStr[50];
            char searchChar;
            cout << "Enter String to search in \n";
            cin >> searchStr;
            cout << "Enter character to search for \n";
            cin >> searchChar;
            int result;
            result = my_strchr(searchStr, searchChar);
            if (result != -1)
            {
                cout << "Element found at index \n"
                     << result;
            }
            else
            {
                cout << "Element not found \n";
            }
            break;

        case 6:
            char str5[50];
            char sub[50];
            cout << "Enter the String :";
            cin >> str5;
            cout << "Enter the Substring you want to search :";
            cin >> sub;
            int output;
            output = my_strstr(str5, sub);
            if (output != -1)
            {
                cout << "\nSubString is present at : " << output << endl;
            }
            else
            {
                cout << "\nSubString is not present in the String" << endl;
            }
            break;
        case 7:
            cout << "Enter String to reverse in place \n";
            char str6[50];
            cin >> str6;
            reverse_inplace(str6);
            cout << "Reversed String: " << str6 << endl;
            break;

        case 8:
            cout << "Enter String to check Palindrome \n";
            char str7[50];
            cin >> str7;
            if (is_palindrome(str7))
            {
                cout << "The string is a palindrome." << endl;
            }
            else
            {
                cout << "The string is not a palindrome." << endl;
            }
            break;
        case 9:
            // cout << "Enter String to count words \n";
            //  cin>> str8;
            cout << "Number of words in the string: " << count_words(str8) << endl;
            break;
        case 10:
            // cout << "Most frequent word in the string: " << most_frequent_word(str9) << endl;
            // if(my_strcasestr(str9, "hello") != -1) {
            //     cout << "Substring found using case-insensitive search." << endl;
            // } else {
            //     cout << "Substring not found using case-insensitive search." << endl;
            // }
            break;
         case 11:
        //       cout<<"Enter sting in the format of csv apple,banana,,cherry";  
        //     char csvStr[100];
        //     cin.getline(csvStr, 100);
        //     cout << "CSV String: " << csvStr << endl;
        //     char* token ;
        //     token = my_strTok(csvStr, ",");
        //     cout << "Tokens in the CSV String: ";
        //     while (token != NULL) {
        //        cout << token << " ";
        //        token = my_strTok(NULL, ",");
        //     }
        //      cout<<token ; 
               break;   
        case 12:
            cout << "Enter String to collapse spaces \n";
            // cin.getline(str10, 100);
            cout << "Collapsed String: " << my_strCollapse(str10) << endl;
         break;  

        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice);
    return 0;
}