#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "text-editor-functions.cpp"


using namespace std;

string file_name;
fstream file;


void choose_file(){
    cout << "Please enter the name of the file or type: ";
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
    file << '\n';
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

void countTimesWord(){
    cin.ignore();
    string search;
    int times = 0;
    cout << "Enter the word you want to count for: ";
    cin >> search;
    for_each(search.begin(), search.end(), [](char & c){c = tolower(c);});
    file.open(file_name,ios::in);
    string word;
    bool flag=false;
    while(file >> word)
    {
        for_each(word.begin(), word.end(), [](char & c){c = tolower(c);});
        if(word == search)
        {
            times++;
            flag=true;
        }
    }
    if(!flag)
    {
        cout << "Word was not found" << endl;
    }
    else{
        cout << "This word has appeared " << times << " time/s in the file." << endl; 
    }
    file.close();
}

void turnUpper(){
    string str;
    char ch;
    file.open(file_name, ios::in);
    while(!file.eof()){
        ch = file.get();
        if(isalpha(ch)){
            str+= toupper(ch);
        }
        else{
            str+= ch;
        }
    }
    str.resize(str.length()-1);
    file.close();
    file.open(file_name, ios::out);
    file << str;
    file.close();
}

void turnLower(){
    string str;
    char ch;
    file.open(file_name, ios::in);
    while(!file.eof()){
        ch = file.get();
        if(isalpha(ch)){
            str+= tolower(ch);
        }
        else{
            str+= ch;
        }
    }
    str.resize(str.length()-1);
    file.close();
    file.open(file_name, ios::out);
    file << str;
    file.close();
}

void firstCaps(){
    string str;
    file.open(file_name, ios::in);
    while(!file.eof()){
        str+= file.get();
    }
    str.resize(str.length()-1);
    file.close();
    if(isalpha(str[0])){
        str[0] = toupper(str[0]);
    }
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i]) && !isalpha(str[i-1])){
            str[i] = toupper(str[i]);
        }
    }
    file.open(file_name, ios::out);
    file << str;
    file.close();
}

void save_as(){
    string target_file, text;
    cout << "Enter target file name";
    cin >> target_file;
    target_file += ".txt";
    file.open(file_name, ios::in);
    text = file.rdbfr();
    file.close();
    file.open(target_file, ios::out);
    file << text;
    file.close();
}