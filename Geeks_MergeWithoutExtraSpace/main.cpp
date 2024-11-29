#include <bits/stdc++.h> 

using namespace std; 

int main() 
{
    int T, M, N;
    
    cin >> T;
    
    while (T--)
    {
        cin >> M >> N;
        
        int A[M], B[N];
        
        for (int i=0; i<M; i++) { cin >> A[i]; }
        for (int i=0; i<N; i++) { cin >> B[i]; }
        
	    int C[M + N];
	
	    for (int i=0; i<(M+N); i++)
	    {
		    if (i < M) { C[i] = A[i]; }
		    else { C[i] = B[i - M]; }
	    }
	    
	    sort(C, C+M+N);
	    
	    for (int i=0; i<(M+N); i++) { cout << C[i] << ' '; }
	    
	    cout << endl;
    }
    
    return 0; 
}
