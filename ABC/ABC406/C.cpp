#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> P(N);
    for(auto&& i : P) cin>>i;

    long long ans = 0;
    long long pre_cnt = 0;
    long long cnt = 0;

    for(int i = 1;i < N;++i){
        if(P[i-1] < P[i]){
            cnt++;
        }else {
            if(0 < cnt){
                ans += cnt * pre_cnt;
                pre_cnt = cnt;
                cnt = 0;
            }
        }
    }
    ans += cnt * pre_cnt;

    cout<<ans<<"\n";

    return 0;
}