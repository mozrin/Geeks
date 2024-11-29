#include <bits/stdc++.h>

using namespace std;

int int_RomanToInteger(string s);

int main()
{
    string romanNumerals;
    
    cout << "Enter the Roman Numerals to convert: ";
    cin >> romanNumerals;
    
    cout << endl << endl << romanNumerals << " = " << int_RomanToInteger(romanNumerals) << endl;
    
    return 0;
}

int int_RomanToInteger(string s)
{
    int rc = 0, tempTotal = 0;
    
    map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    for (int i = 0; i < s.length(); i++)
    {
        if (values[s[i+1]] <= values[s[i]])
        {
            tempTotal += values[s[i]];
        }
        else
        {
            tempTotal -= values[s[i]];
            youOnlyGetOneOfThese++;
        }
    }
    
    rc = tempTotal;
    
    return rc;
}
    
    
    