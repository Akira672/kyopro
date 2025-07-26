#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N,K;
    cin >> N >> K;
    vector<long long> A(N+1,1);
    vector<long long> S(N+1,1);

    for(int i = 0;i < N + 1;++i){

        if(K < i){
            A[i] = ((long long)1e9 + S[i-1] - S[i-K-1]) % (long long)1e9; 
        }else if(K == i){
            A[i] = S[i-1];
        }

        if(0 < i){
            S[i] = (S[i-1] + A[i]) % (long long)1e9;
        }
    }

    cout << A[N] << "\n";

    return 0;
}