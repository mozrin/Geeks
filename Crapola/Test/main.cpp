#include <iostream>

using namespace std;

string str_permutations(string s, int i = 0, int d = -1);

string ltrim(string s, const string r = "\t\n\v\f\r ");
string rtrim(string s, const string r = "\t\n\v\f\r ");
string trim(string s, const string r = "\t\n\v\f\r ");

int main()
{
    int t;
    
    string test, test2 = "JAMES";
    
    cout << test2 << endl;
    
    swap(test2[1], test2[2]);
    cout << test2  << endl << endl;


    
    // Input T = number of test cases
    // Input S = N string(s) to process

    cin >> t;
    
    while (t--)
    {
        string s;
        
        cin >> s;
    
        cout << str_permutations(s);
        
        cout << '\n';
    }
    
    cout << "\n\nTesting the trim, ltrim, and rtrim functions\n\n";
    
    test = "   String with a bunch of crap   ";
    
    cout << "      (test) = |" << test << "|\n";
    cout << " ltrim(test) = |" << ltrim(test) << "|\n";
    cout << " rtrim(test) = |" << rtrim(test) << "|\n";
    cout << "  trim(test) = |" << trim(test) << "|\n";
    
    cout << '\n';
    
    return 0;
}

/**
 * @syntax string = str_permutations( <string>, [<start>], [<length>] )
 * 
 * Finds all permutations of a string that have the same number of characters.
 *
 * n.b. This function operates recursively.
 * 
 * @param string containing the string to be processed.
 * @param int containing the starting location in the string to process.
 * @param int containing the length of the string to be processed.
 * 
 * @return string containing all permutations separated by the ' ' character.
 *
 *     1 1 1 2 0 1     
 *     ABC ACB BAC BCA CAB CBA
 *     ABC ACB BAC BCA CBA CAB
 * 
 **/

string str_permutations(string s, int i, int n)
{
    string c; // Container for accumulation of combinations of s.
    
    n = (n == -1) ? s.length() : n; // Used to allow for default value.
    
    if (i == (n - 1)) { c += trim(s); } // Only 1 character passed this recursion.
    
    else
    {
        for (int j = i; j < n; j++)
        {
            // cout << i << " = |" << s[i] << "| - ";
            // cout << j << " = |" << s[j] << "|" << endl;
            
            if (i != j) swap(s[i], s[j]);
            
            c += trim(str_permutations(s, i + 1, n)) + " ";
    
            if (i != j) swap(s[i], s[j]);
            
            // cout << "A: " << i << " = |" << s[i] << "| - ";
            // cout << j << " = |" << s[j] << "|" << endl;
        }
    }
    
    return c;
}

/**
 * @syntax string = ltrim( <string>, [<chars>] )
 * 
 * Removes specific characters from the left side of a string.
 * 
 * @param string containing the string to be processed.
 * @param string containing all characters to be removed from the string.
 * 
 * @return string containing the processed string.
 * 
 **/

string ltrim(string s, const string r)
{
    s.erase(0, s.find_first_not_of(r));
    
    return s;
}

/**
 * @syntax string = rtrim( <string>, [<chars>] )
 * 
 * Removes specific characters from the right side of a string.
 * 
 * @param string containing the string to be processed.
 * @param string containing all characters to be removed from the string.
 * 
 * @return string containing the processed string.
 * 
 **/
 
string rtrim(string s, const string r)
{
    s.erase(s.find_last_not_of(r) + 1);
    
    return s;
}

/**
 * @syntax string = trim( <string>, [<chars>] )
 * 
 * Removes specific characters from both sides of a string.
 * 
 * @param string containing the string to be processed.
 * @param string containing all characters to be removed from the string.
 * 
 * @return string containing the processed string.
 * 
 **/
 
string trim(string s, const string r)
{
    return ltrim(rtrim(s, r), r);
}


