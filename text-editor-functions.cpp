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
    file_name+= ".txt"; //the file that the user enters turns to text
    file.open(file_name);
    if(file.fail()){
        file.open(file_name, ios::out);
        cout << "This is a new file. I created it for you.\n";
    } //if the file is empty it'll make i new file
    else{
        cout << "This File Already Exists.\n";
    }
    file.close();
}

void add(){
    char ch;
    cout << "Enter your text and enter '/' when you want to end:\n";
    file.open(file_name, ios::app);
    cin.ignore(); //clearing what was entered before
    file << '\n'; //reading lines
    while((ch = getchar()) != slash){
        file << ch;
    } //enterting the characters that the user is entering
    file.close();
}

void display(){
    string temp;
    file.open(file_name, ios::in);
    while(!file.eof()){
        getline(file, temp);
        cout << temp << endl;
    } //until the files reachs end, print what is written in it
}

void clear(){
    file.open(file_name, ios::out);
    file.close();
} //erase what is written in the file

void encrypt(){
    vector<char> ch;
    file.open(file_name, ios::in);
    while(!file.eof()){
        char c;
        file.get(c);
        ch.push_back(c);
    } //declaring an vector array and putting what is in the file in it
    ch.pop_back(); //remove the last character from the array
    file.close();
    file.open(file_name, ios::out);
    for(char c: ch){
        if(c != '\n'){
            file << char(c + 1);
        } //if the character not equal to space , add to the character one which will change it to the next character
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
        } //same thing as encryption , instead we subtract one to get back to the previous ascii
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
        } //put in a new string each character in the file
        str.resize(str.length()-1); //remove the last character from the string
        file.close();
        file.open(file_name, ios::app);
        file << str; //read in the file the new string after merging
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
        } //after reading each word , the iterator increases by one

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
    }//after reading each character , the iterator increases by one
    cout << "Number of Characters = " << numberChar-1 << endl;
    file.close();
}

void countLines(){
    int numberLines =0;
    string line;
    file.open(file_name, ios:: in);
    while(getline(file,line)){
        numberLines++;
    } //reading each line increases the iterator by one
    cout << "Number of Lines = " << numberLines << endl;
    file.close();
}

void search(){
    cin.ignore();
    string search;
    cout << "Enter a word to search for : ";
    cin >> search;
    for_each(search.begin(), search.end(), [](char & c){c = tolower(c);}); //turning each character to lower
    file.open(file_name,ios::in);
    string word;
    bool flag=true;
    while(file >> word) //while reading the file
    {
        for_each(word.begin(), word.end(), [](char & c){c = tolower(c);}); //turn each character to lower to make it easier while searching
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
    }//increasing the iterator by one after finding the same word
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
        } //if the character is alphabet , turn it to uppercase
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
        } //if the character is alpahbet , turn it to lowercase
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
    }//if the first character is alphabet, turn it to uppercase
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i]) && !isalpha(str[i-1])){
            str[i] = toupper(str[i]);
        }
    } //if the character is alphabet after a space turn it to upper
    file.open(file_name, ios::out);
    file << str;
    file.close();
}

void save_as(){
    string target_file, str;
    cout << "Enter target file name";
    cin >> target_file;
    target_file += ".txt";
    file.open(file_name, ios::in);
    while(!file.eof()){
        str+= file.get();
    }
    str.resize(str.length()-1);
    file.close();
    file.open(target_file, ios::out);
    file << str;
    file.close();
}