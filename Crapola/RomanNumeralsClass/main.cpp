#include <bits/stdc++.h>

using namespace std;

class Number
{
    public:
    
    Number();
    
    void SetInput(string n);
    void SetConvertFrom(char t);
    void SetConvertTo(char t);
    
    string Binary();
    string Decimal();
    string Hexidecimal();
    string Octal();
    string Roman();
    
    int baseline = 0;
    
    char convertFrom = 'D', convertTo = 'D';
    
    string input = "0", output, roman, binary, octal, hexidecimal;
    
    ConvertEverything
};

void Number::SetInput(string n)
{
    input = n;
    
    switch(convertFrom)
    {
        case 'D':
        
        break;
    }
    
}
void Number::SetConvertFrom(char t) { convertFrom = t; }
void Number::SetConvertTo(char t) { convertTo = t; }

string Number::Decimal() { return to_string(stoi(input)); }
string Number::Roman() { return roman; }
string Number::Binary() { return binary; }
string Number::Octal() { return octal; }
string Number::Hexidecimal() { return hexidecimal; }

Number::Number()
{
    
    
    return;
}

int main()
{
    int rc = 0;
    
    Number n;
    
    n.SetInput("9120");
    
    
    cout << stoi("9120") << endl;
    cout << n.Decimal();
    
    return rc;
}