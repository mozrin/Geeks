#include <bits/stdc++.h> 

using namespace std; 

int main() 
{
    int T, N; // Assumes Integers .. Change If Needed
    
    cin >> T; // Test Cases
    
    while (T--)
    {
        cin >> N; // First Input For Test Case
        
        int A[N];
        
        for (int i=0; i<N; i++) { cin >> A[i]; }
        
        // -------------------------------------------
        
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (A[i]>A[j])
                {
                    int temp = A[i];
                    
                    A[i] = A[j];
                    A[j] = temp;
                    
                    i = (i - 1);
                }
            }
            
            for (int i=0; i<N; i++) { cout << A[i]; }
            cout << endl;
        }
        
        // -------------------------------------------
        
	    cout << endl; // Newline After Outputing Results
    }
    
    return 0; 
}
