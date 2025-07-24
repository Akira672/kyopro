#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N,M;
    cin >> N >> M;

    vector<pair<long long,long long>>A(M);
    for(auto&& a:A){
        cin >> a.first >> a.second;
    }

    long long ans = M * (M - 1) / 2;
    vector<long long> dif(N,0);
    for(int i = 0;i < M;++i){
        dif[(A[i].first + A[i].second) % N]++;
    }

    for(int i = 0;i < N;++i){
        ans -= dif[i]*(dif[i]-1)/2;
    }
    
    cout << ans << "\n";

    return 0;
}