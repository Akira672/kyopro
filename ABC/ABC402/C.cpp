#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;
    vector<vector<int>>A(M);
    for(auto&& a:A){
        int K = 0;
        cin >> K;
        a.resize(K);
        for(auto&& ak:a){
            cin >> ak;
        }
    }
    vector<int>B(N);
    for(auto&& b:B)cin >> b;

    map<int,int> trans;
    for(int i = 0;i < N;++i){
        trans[B[i]] = i;
    }

    vector<int> add(N,0);
    for(auto&& a:A){
        int ma = 0;
        for(auto&& ak:a){
            ma = max(ma,trans[ak]);
        }
        add[ma]++;
    }

    int sum = 0;
    for(auto&& a:add){
        sum += a;
        cout << sum << "\n";
    }

    return 0;
}