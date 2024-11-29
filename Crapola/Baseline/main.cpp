#include<bits/stdc++.h>

#include "curl/curl.h"
/*
int m2ain(int argc, char *argv[])
{
CURL *curl;
   CURLcode res;

   curl_global_init( CURL_GLOBAL_ALL );
}
*/ 
using namespace std;

// My Helper Functions & Definitions

#define PANDW(p,w) setprecision(p) << setw(w) << fixed

int GetInteger(string q = "Enter an integer:  ");
int GetIntegerRange(string prompt, int lowNumber, int highNumber);
int WaitForUserToPressKey(int errorCode = 0, char waitKey = '\n', string = "Press <Enter> to end...");
    
bool isLeapYear(int year = -1);

string int_toBinary(int i, int b=32);

string str_replace(string s, char a, char b);
string str_tolower(string s);
string str_toupper(string s);
string str_reverse(string s);

// Other People's Functions

int main()
{
    CURL *curl;
    
    CURLcode res;
    
    curl_global_init( CURL_GLOBAL_ALL );
    
    int rc = 0; // Pass any error codes to this variable before dropping out.
    
    int sum = 0, input = 0, counter = 0, maximum = 0, minimum = INT_MAX, evens = 0, odds = 0;
    
    double average;
    
    //----------------------------------------------------
    
    do
    {
        input = GetInteger("\n Enter an integer (negative value to Quit):  ");
        
        if (input < 0) break;
        
        counter++;
        
        sum += input;
        
        evens += ((input % 2) == 0) ? 1 : 0;
        
        odds += ((input % 2) == 1) ? 1 : 0;
        
        minimum = (input < minimum) ? input : minimum;
        
        maximum = (input > maximum) ? input : maximum;
        
        average = (1.0 * sum) / counter;
        
    } while (true);
    
    cout << '\n';
    
    if (counter > 0)
    {
        cout << "Values Entered:  " << PANDW(0,10) << counter << "\n";
        cout << "Sum of numbers:  " << PANDW(0,10) << sum << "\n";
        cout << " Average value:  " << PANDW(4,10) << average << "\n";
        cout << " Maximum value:  " << PANDW(0,10) << maximum << "\n";
        cout << " Minimum value:  " << PANDW(0,10) << minimum << "\n";
        cout << "  Even numbers:  " << PANDW(0,10) << evens << "\n";
        cout << "   Odd numbers:  " << PANDW(0,10) << odds << "\n";
    }
    
    else 
    {
        cout << "You must enter at least one value greater than 0.";
    }
    
    cout << '\n';
    
    //----------------------------------------------------

    return WaitForUserToPressKey(rc); // Default is ENTER ...
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

