#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string file_name;
fstream file;

const char ESC = 27;
const char RETURN = 10;


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
    cout << "Enter your text and press ESC button when you want to end:\n";
    file.open(file_name, ios::app);
    cin.ignore();
    while(ch != ESC){
        ch = getchar();
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

        default:
            cout << "Sorry invalid input\n";
            break;
        }
        
    }
    return 0;
}