#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string file_name;
fstream file;

const char ESC = 27;
const char RETURN = 10;
const char slash = 47;


void choose_file(){
    cout << "Please enter the name of the file: ";
    cin >> file_name;
    file_name+= ".txt";
    file.open(file_name);
    if(file.fail()){
        file.open(file_name, ios::out);
        cout << "This is a new file. I created it for you.\n";
    }
    else{
        cout << "This File Already Exists.\n";
    }
    file.close();
}

void add(){
    char ch;
    cout << "Enter your text and enter '/' when you want to end:\n";
    file.open(file_name, ios::app);
    cin.ignore();
    while((ch = getchar()) != slash){
        file << ch;
    }

    file.close();
}

void display(){
    string temp;
    file.open(file_name, ios::in);
    while(!file.eof()){
        getline(file, temp);
        cout << temp << endl;
    }
}

void clear(){
    file.open(file_name, ios::out);
    file.close();
}

void encrypt(){
    vector<char> ch;
    file.open(file_name, ios::in);
    while(!file.eof()){
        char c;
        file.get(c);
        ch.push_back(c);
    }
    ch.pop_back();
    file.close();
    file.open(file_name, ios::out);
    for(char c: ch){
        if(c != '\n'){
            file << char(c + 1);
        }
        else{
            file << c;
        }
    }
    file.close();
}

void decrypt(){
    vector<char> ch;
    file.open(file_name, ios::in);
    while(!file.eof()){
        char c;
        file.get(c);
        ch.push_back(c);
    }
    ch.pop_back();
    file.close();
    file.open(file_name, ios::out);
    for(char c: ch){
        if(c != '\n'){
            file << char(c - 1);
        }
        else{
            file << c;
        }
    }
    file.close();
}

void merge(){
    string file_name_2;
    string str;
    cout << "Please enter the name of the second file: ";
    cin >> file_name_2;
    file_name_2+= ".txt";
    file.open(file_name_2, ios::in);
    if(file.fail()){
        cout << "This file doesn't exsit" << endl;
        file.close();
    }
    else {
        while(!file.eof()){
            str+= file.get();
        }
        str.resize(str.length()-1);
        file.close();
        file.open(file_name, ios::app);
        file << str;
        file.close();
        }

}

void countWords(){
    int numberWords=0;
    string word;
    file.open(file_name, ios:: in);
    while (!file.eof()){
        file >> word;
        numberWords++;
        }

    cout << "Number of words = " << numberWords-1 << endl;
    file.close();
}

void countChar(){
    int numberChar =0;
    char theChar;
    file.open(file_name, ios:: in);
    while (!file.eof()) {
        file >> theChar;
        numberChar++;
    }
    cout << "Number of Characters = " << numberChar-1 << endl;
    file.close();
}

void countLines(){
    int numberLines =0;
    string line;
    file.open(file_name, ios:: in);
    while(getline(file,line)){
        numberLines++;
    }
    cout << "Number of Lines = " << numberLines << endl;
    file.close();
}

void search(){
    cin.ignore();
    string search;
    cout << "Enter a word to search for : ";
    cin >> search;
    for_each(search.begin(), search.end(), [](char & c){c = tolower(c);});
    file.open(file_name,ios::in);
    string word;
    bool flag=true;
    while(file >> word)
    {
        for_each(word.begin(), word.end(), [](char & c){c = tolower(c);});
        if(word == search)
        {
            cout << "Word was found " << endl;
            flag=true;
            break;
        }
        else
        {
            flag=false;
        }
    }
    if(flag==false)
    {
        cout << "Word was not found" << endl;
    }
    file.close();
}



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
             << "F. Save" << endl
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

        default:
            cout << "Sorry invalid input\n";
            break;
        }
        
    }
    return 0;
}