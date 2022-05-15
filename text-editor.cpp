#include <iostream>

#include "text-editor-functions.cpp"

using namespace std;

int main(){
    char input, in;
    while(input != 'G'){
        choose_file();
        cout << "Choose one of the following actions" << endl
             << "1. Add new text to the end of the file" << endl
             << "2. Display the content of the file" << endl
             << "3. Empty the file" << endl
             << "4. Encrypt the file content" << endl
             << "5. Decrypt the file content" << endl
             << "6. Merge another file" << endl
             << "7. Count the number of words in the file." << endl
             << "8. Count the number of characters in the file" << endl
             << "9. Count the number of lines in the file" << endl
             << "A. Search for a word in the file" << endl
             << "B. Count the number of times a word exists in the file" << endl
             << "C. Turn the file content to upper case." << endl
             << "D. Turn the file content to lower case." << endl
             << "E. Turn file content to 1st caps (1st char of each word is capital)" << endl
             << "F. Turn file content to 1st caps (1st char of each word is capital)" << endl
             << "G. Exit" << endl;
        cin >> input;
        in = toupper(input);
        switch (in)
        {
        case '1':
            add();
            break;

        case '2':
            display();
            break;

        case '3':
            clear();
            break;

        case '4':
            encrypt();
            break;

        case '5':
            decrypt();
            break;

        case '6':
            merge();
            break;

        case '7':
            countWords();
            break;

        case '8':
            countChar();
            break;

        case '9':
            countLines();
            break;

        case 'A':
            search();
            break;

        case 'B':
            countTimesWord();
            break;

        case 'C':
            turnUpper();
            break;

        case 'D':
            turnLower();
            break;

        case 'E':
            firstCaps();
            break;

        case 'F':
            save_as();
            break;

        case 'G':
            return 0;
            break;

        default:
            cout << "Sorry invalid input\n";
            break;
        }
        char ans;
        cout << "Do you you want to continue using our program [Y/n]: ";
        cin >> ans;
        ans = toupper(ans);
        if(ans == 'N'){
            cout << "Thank you for using our program";
            return 0;
        }
    }
    return 0;
}