#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,bool>>> V(N);

    for(int i = 0;i < M;++i){
        int u,v;
        cin>>u>>v;
        u--;v--;
        V[u].push_back({v,true});
    };

    cout<<ans<<"\n";


    return 0;
}