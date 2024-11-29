#include<bits/stdc++.h>

using namespace std;

// My Helper Functions & Definitions

#define PANDW(p,w) setprecision(p) << setw(w) << fixed

int GetInteger(string q = "Enter an integer:  ");
int GetIntegerRange(string prompt, int lowNumber, int highNumber);
int WaitForUserToPressKey(int errorCode = 0, char waitKey = '\n', string = "Press <Enter> to end...");
    
bool isLeapYear(int year = -1);

void PermutationsOfString(string str, int i, int n);

string int_toBinary(int i, int b=32);

string str_replace(string s, char a, char b);
string str_tolower(string s);
string str_toupper(string s);
string str_reverse(string s);

// Other People's Functions

int main()
{
    int rc = 0; // Pass any error codes to this variable before dropping out.
    
    //----------------------------------------------------

    string str = "ABCDEFGH";

    PermutationsOfString(str, 0, str.length());
    
    //----------------------------------------------------

    return WaitForUserToPressKey(rc); // Default is ENTER ...
}

void PermutationsOfString(string str, int i, int n)
{
    if (i == (n - 1))
    {
        cout << str << endl;
    }
    
    else
    {

        for (int j = i; j < n; j++)
        {
            swap(str[i], str[j]);
            
            PermutationsOfString(str, i + 1, n);
    
            swap(str[i], str[j]);
        }
    }
}

int GetInteger(string q)
{
    int returnCode;
    
    do
    {
        cout << q;
        
        if (cin >> returnCode) break;
        
        cin.clear();
        cin.ignore();
        
    } while (true);
    
    return returnCode;
}

int GetIntegerRange(string prompt, int lowNumber, int highNumber)
{
    int inputNumber;
    
    do
    {
        inputNumber = GetInteger(prompt);
        
        cout << "Broken";
        
        if (inputNumber < lowNumber || inputNumber > highNumber )
        {
            cout << "**** INVALID Number: Must be >= " << lowNumber;
            cout << " and <= " << highNumber << "!\n";
        }
        
        else
        { 
            cout << endl;
            break;
        }
        
    } while (true);
}

string str_reverse(string s)
{
    string rc = "";
    
    for (int i=s.length(); i>=0; i--)
    {
        rc += s[i];
    }
    
    return rc;
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

string int_toBinary(int i, int b)
{
    string r = "";
    
    if (i>0)
    {
        while (i>0)
        {
            r = ((i % 2) == 0 ? "0" : "1" ) + r;
            i /= 2;
        }
    }
    
    r = string(b, '0') + r;
    r = r.substr(r.length() - b);

    return r;
}

bool isLeapYear(int year)
{
    bool returnCode = false;
    
    if (year == -1)
    {
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        
        year = timePtr->tm_year;
    }
    
    returnCode = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    
    return returnCode;
}

int WaitForUserToPressKey(int errorCode, char waitKey, string message)
{
	char c;
	
	cout << message;
	
	while ((getchar()) != '\n'); // Clear Buffer (find something more elegant)
	
	do
	{
	    c = getchar();
	    
	    if (c == waitKey) break;
	    
	} while (true);

	if (errorCode < 0 || errorCode > 0)
	{
	    cout << "\n\n" << "An error was passed to the exit routine. The error code is (" << errorCode << ")\n";
	}
	
	return errorCode;
}





