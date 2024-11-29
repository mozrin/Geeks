#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional> 
#include <string>

using namespace std;

string GetStringInput(string q = "No question specified");

inline uint32_t str_hash(const string& str);

string str_tolower(string s);
string str_toupper(string s);
string str_replace(string s, char a, char b);

int main()
{
    uint32_t hashCorrectAnswer, hashinputAnswer;
    
    
 
    string question, correctAnswer, inputAnswer;
    
    question      = GetStringInput("       Enter Question:  ");    
    correctAnswer = GetStringInput(" Enter Correct Answer:  ");    
    inputAnswer   = GetStringInput("    Enter Your Answer:  ");

    cout << str_hash(correctAnswer) << "\n";
    cout << str_hash(inputAnswer) << "\n";

    return 0;
}

string GetStringInput(string q)
{
    string input;
    
    cout << q;
    getline(cin, input);
    
    return input;
}

inline uint32_t str_hash(const string& str) {

    uint32_t hash = 0x821c9dc5;
    uint32_t prime = 0x1000293;

    for(int i = 0; i < str.size(); ++i) {
        uint8_t value = str[i];
        hash = hash ^ value;
        hash *= prime;
    }

    return hash;
}

string str_replace(string s, char a, char b)
{
    replace( s.begin(), s.end(), a, b);
    
    return s;
}

string str_toupper(string s)
{
    transform( s.begin(),
               s.end(),
               s.begin(),
               
               [](unsigned char c){ return toupper(c); }
               
               );
    return s;
}

string str_tolower(string s)
{
    transform( s.begin(),
               s.end(),
               s.begin(),
               
               [](unsigned char c){ return tolower(c); }
               
               );
    return s;
}

