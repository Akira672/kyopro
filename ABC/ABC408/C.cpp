#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,M;
    cin >> N >> M;
    vector<pair<long long,long long>> LR(M);
    for(auto&& [l,r]:LR){cin >> l >> r;l--;r--;}

    vector<long long> C(N,0),D(N+1,0);
    for(auto&& [l,r]:LR){
        D[l]++;
        D[r+1]--;
    }

    long long min = D[0];
    C[0] = D[0];
    for(int i = 1;i < N;i++){
        C[i] = D[i] + C[i-1];
        if(C[i] < min){
            min = C[i];
        }
    }

    cout << min << "\n";

    return 0;
}