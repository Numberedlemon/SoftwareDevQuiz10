#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int FILE_LENGTH = 500;

bool containsDigit(string l);

int main() {

    string input[FILE_LENGTH] = {};

    ifstream infile;
    infile.open("input.txt");

    string l;
    int i = 0;
    if (infile.is_open()) {
        while (getline(infile, l)) {
            input[i] = l;
            i++;
        }
    }
    infile.close();

    vector<string> validPass = {};

    for (int i = 0; i <= FILE_LENGTH; i++) {
        if (input[i].length() < 8 && containsDigit(input[i]) == true) {
            validPass.push_back(input[i]);
        }
        else {
            continue;
        }
    }


    cout << "HOW MANY PASSWORDS ARE CORRECT?" << endl;
    cout << "This many of " << FILE_LENGTH << " passwords are correct: " << validPass.size() << endl;

    
}

bool containsDigit(string l) {
    return any_of(l.begin(), l.end(), ::isdigit);
}
