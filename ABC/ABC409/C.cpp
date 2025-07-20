#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,L;
    cin >> N >> L;
    vector<long long> cnt(L,0);
    long long p = 0;
    cnt[0]++;
    for(int i = 0;i < N-1;++i){
        long long d;
        cin >> d;
        p = (p + d) % L;
        cnt[p]++;
    }

    if(L % 3 != 0){
        cout << "0\n";
        return 0;
    }

    long long ans = 0;
    for(long long i = 0;i < L/3;++i){
        ans += cnt[i]*cnt[i+L/3]*cnt[i+L/3*2];
    }

    cout << ans << "\n";

    return 0;
}