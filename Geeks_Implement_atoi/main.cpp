#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
    int T, O;
    string S;
    
    cin >> T;
    
    while (T--)
    {
        cin >> S;
        
        if (any_of(S.begin(), S.end(), ::isalpha))
        {
            O = -1;
        }
        
        else
        {
            O = stoi(S. c_str());
        }
                
        cout << O << endl;
    }
    
    return 0; 
}