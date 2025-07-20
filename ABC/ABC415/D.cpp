#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,M;
    cin >> N >> M;
    vector<pair<long long,long long>> AB(M);
    for(auto&& [a,b]:AB)cin >> a >> b;
    sort(AB.begin(), AB.end(), [](const auto& a, const auto& b) {
        return (a.first - a.second) < (b.first - b.second);
    });


    long long ans = 0;

    while(true){
        int index = -1;
        for(int i = 0;i < M;++i){
            if(AB[i].first <= N){
                index = i;
                break;
            }
        }
        if(index != -1){
            long long x = (N - AB[index].first) / (AB[index].first - AB[index].second) + 1;
            ans += x;
            N -= x*(AB[index].first - AB[index].second);
        }else{
            break;
        }
    }

    cout << ans << "\n";


    return 0;
}