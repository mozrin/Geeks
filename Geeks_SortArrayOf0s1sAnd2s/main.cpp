#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
    /* 2
       5
       0 2 1 2 0
       3
       0 1 0
    */
    
    int T, N;
    
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        
        int A[N];
        
        for (int i=0; i<N; i++) { cin >> A[i]; }
        
        sort(A, A + (sizeof(A)/sizeof(A[0])));
        
        for (int i=0; i<N; i++) { cout << A[i] << " "; }
        
        cout << endl;
    }
    
    return 0; 
}
