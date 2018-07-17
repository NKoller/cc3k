#include "floor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void readingFile() {
    ifstream file {"input.txt"};
    string str;
    while(true) {
        file>>str;
        if(file.fail()) {
            break;
        }
        istringstream ss;
        char ch;
        vector <char> temp;
        while(ss >> ch) {
            temp.emplace_back(ch);
        }
    }
}

void readingInput(vector <char> temp) {
    string s; //this should technically be char but I dont know why its giving me an error
    for(int row=0; row < 50; ++row) {
      vector <Cell> rowVec;
        for(int col=0; col < 50; ++col) {
            s = grid[row][col];
     if(s == "|") {
         cout<<"Cell pointing at nullptr"<<endl;
     }
     else if(s == "-") {
         cout<<"Cell pointing at nullptr"<<endl;
     }
     else if(s == ".") {
         cout<<"Create normal cell here"<<endl;
     }
     else if(s == "+") {
         cout<<"Create door cell here"<<endl;
     }
     else if(s == "#") {
        cout<<"Create passage cell here"<<endl;
     }
     else if(s == " ") {
         cout<<"Create no cell here"<<endl;
     }
     else {
         return;
     }
  }
 }
}

void attach()
