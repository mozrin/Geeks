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
        
        sort(A, A + N);
        
        for (int i=0; i<N; i++) { cout << A[i] << " "; }
        cout << endl;
        
        int L=0, R=N-2;
        
        for (int i=(N-1); i>0; i--)
        {
            while (true)
            {
                if ((A[L]+A[R])==A[i])
                {
                    L++;
                    R--;
                    cout << C++ << endl;
                    
                }
                
                else if ((A[L]+A[R])<A[i])
                {
                    L++;
                    cout << "L++" << endl;
                    
                }
                    
                else if ((A[L]+A[R])>A[i])
                {
                    R--;
                    cout << "R--" << endl;
                    
                }
                        
                else { cout << "hereh!!!!\n"; break; }
            }
        }
        
        C = C==0 ? -1 : C;
       
       
        cout << C << endl;
    }
    
    return 0; 
}
