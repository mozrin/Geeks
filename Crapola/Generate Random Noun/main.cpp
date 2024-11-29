#include <bits/stdc++.h>

using namespace std;

const string NOUN_FILE = "nouns.txt";

int CountLinesInFile(string f);

int main()
{
    int random, nounCount, counter = 0;
    
    nounCount = CountLinesInFile(NOUN_FILE);
    
    string noun, nouns[nounCount];
    
    ifstream nounsFile(NOUN_FILE);
    
    do
    {
        if (nounsFile.eof()) { break; }
    
        nounsFile >> noun;
        
        nouns[counter] = noun;
        
        counter++;
        
    } while (true);
    
    cout << "Press a key for a random noun, Q to quit.\n\n";
    
    do
    {
        random = rand() % nounCount;
        cout << nouns[random];
        
    } while (toupper(cin.get()) != 'Q');
        
    
    return 0;
}

int CountLinesInFile(string f)
{
    int rc, counter = 0;
    
    string line;
    
    ifstream filet(f);
    
    do
    {
        if (filet.eof()) { break; }
    
        filet >> line;
        
        counter++;
        
    } while (true);
    
    filet.close();
    
    rc = counter;
    
    return rc;
}