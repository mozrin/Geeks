// CSIS 223 FINAL 2
// CODE FROZEN: 20200722
//
// Use the FORK THIS button to grab a version of this program that you can make changes to!

#include <bits/stdc++.h>

// This code will only run in a perfect world. Only rudimentary error handling is included. In order
// to make this more robust, try/catch{} and advanced error handling should be included.

using namespace std; // Always a bad idea to use this in production code. The better option is to learn about namespaces.

// Assignment Function

double GetSmallestDouble(double double1, double double2, double double3)
{
    double rc = 0;
    
    if (double1 == double2 || double1 == double3 || double2 == double3)
    {
        // This will set the return value to -1 if any of the numbers
        // are equal to each other. If none of the checks below are
        // valid, the return code will be -1 indicating you entered
        // two numbers in that are smallest and equal.
        //
        // I did this because the instructions did not tell me what to
        // do if NONE of the invidual numbers were smallest.
        
        rc = -1;
    }

    // Find out which of the passed doubles are smallest.
    
    if (double1 < double2 && double1 < double3)
    {
        rc = double1; // double1 is smallest
    }
    
    else
    {
        if (double2 < double1 && double2 < double3)
        {
            rc = double2; // double2 is smallest
        }
        
        // If you were not worried about matching smallest numbers, you could
        // remove the first if() block at the top and change the next
        // if() to an else. You would also need to change several < to <= above.
        
        if (double3 < double1 && double3 < double2)
        {
            rc = double3; // double3 is smallest
        }
    }
    
    return rc;
}

// Main routine

int main()
{
    int rc = 0;
    
    double double1 = 0, double2 = 0, double3 = 0, doubleSmallest;

    // Print Header and Get Input
    
    cout << "Enter three numbers (doubles):\n\n";
    cout << "  1: ";
    cin >> double1;
    cout << "  2: ";
    cin >> double2;
    cout << "  3: ";
    cin >> double3;
    cout << "\n";
    
    doubleSmallest = GetSmallestDouble(double1, double2, double3);
    
    if (doubleSmallest == -1)
    {
        cout << "At least two of the numbers you entered were equal and smallest.\n";
        cout << "Therefore, \"none\" are technically smallest.\n\n";
        cout << "1: " << double1 << ", 2: " << double2 << ", 3: " << double3 << endl;
        
        rc = -1;
    }
    
    else
    {
        cout << "You entered three numbers: " << double1 << ", " << double2 << ", and " << double3 << "\n";
        cout << "Of those three numbers, " << doubleSmallest << " was the smallest!";
    }
    
    return rc;
}