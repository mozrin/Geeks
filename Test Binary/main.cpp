/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

string toBinary(int n);
int power2( int num, int power );

int main()
{
    int test=121;
    
    cout << toBinary(test);
    cout << "\n\n\n" << power2(6,2);
    
    
    return 0;
}

string toBinary(int number)
{
    string rc;
    
    while (number != 0)
    {
        rc = ((number % 2) == 0 ? "0" : "1" ) + rc;
        number /= 2;
    }
    
    rc = "00000000000000" + rc;
    
    rc = rc.substr(rc.length()-14);
    
    return rc;
}