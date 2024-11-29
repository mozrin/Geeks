#include <bits/stdc++.h> 

using namespace std; 

int main() 
{ 
    int T, M, N;
    
    cin >> T;
    
    while (T--)
    {
        cin >> M >> N;
        
        long double X[M], Y[N];
        
        for (int i=0; i<M; i++) { cin >> X[i]; }
        for (int i=0; i<N; i++) { cin >> Y[i]; }
        
        int C=0;
        
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (pow(X[i], Y[j]) > pow(Y[j], X[i])) { C++; }
            }
        }
        
        cout << C << endl;
    }
    
    return 0; 
}
