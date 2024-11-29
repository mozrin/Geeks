// CSIS 223 CHAP 15, PROBLEM 1, PAGE 1064
// CODE FROZEN: 20200722
//
// Use the FORK THIS button to grab a version of this program that you can make changes to!

#include <bits/stdc++.h>

// This code will only run in a perfect world. Only rudimentary error handling is included. In order
// to make this more robust, try/catch{} and advanced error handling should be included.

using namespace std; // Always a bad idea to use this in production code. The better option is to learn about namespaces.

// Assignment Function

void OutputStars(int);
void OutputStarsDescending(int);
void OutputStarsAscending(int);
    
// Main Routine

const int STARS = 4;

int main()
{
    OutputStars(STARS);
    
    return 0;
}

void OutputStars(int starCount)
{
    OutputStarsDescending(starCount);
    OutputStarsAscending(starCount);
    
    return;
}

void OutputStarsAscending(int starCount)
{
    
    
    for (int j = 1; j < starCount + 1; j++)
    {
        for (int i = starCount; i > 0 ; i--) { cout << "*"; }
    }
    
    if (starCount > 0)
    {
        for (int i = starCount; i > 0 ; i--) { cout << "*"; }
        
        cout << endl;
        
        OutputStars(--starCount);
    }
    
    return;
}

void OutputStarsDescending(int starCount)
{
    if (starCount > 0)
    {
        for (int i = 0; i < starCount ; i++) { cout << "*"; }
        
        cout << endl;
        
        OutputStars(--starCount);
    }
    
    return;
}