#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
    int T, N;
    
    cin >> T;
    
    while (T--)
    {
        
        cin >> N;
        
        int A[N], C=0;
        
        for (int i=0; i<N; i++) { cin >> A[i]; }
        
        sort(A, A + N-1);
        
        for (int i=(N-1); i>-1; i--)
        {
            int L=0, R=i-1;
            
            while (true)
            {
                if (L-R <= 0) break;
                
                if      ((A[L]+A[R]) == A[i]) { L++; R--; C++; }
                else if ((A[L]+A[R]) <  A[i]) { L++; }
                else if ((A[L]+A[R]) >  A[i]) { R--; }
            }
        }
        
        C = C==0 ? -1 : C;
       
        cout << (C/2) << endl;
    }
    
    return 0; 
}
