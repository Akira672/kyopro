#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;
    map<int,vector<int>>arror;
    for(int i=0;i<N;i++) {
        int a,b;
        cin>>a>>b;
        arror[a].push_back(b);
        arror[b].push_back(a);
    }

    vector<bool> visited(N+1,false);
    int pre_p = -1;
    int p = 1;
    int cnt = 0;
    bool cycle = false;
    while (true) {
        if (arror[p].size() == 2){
            int next_p = arror[p][0];
            if (next_p == pre_p) next_p = arror[p][1];
            if (!visited[next_p]) {
                pre_p = p;
                p = next_p;
                visited[p] = true;
                cnt++;
                if (cnt == N) {
                    cycle = true;
                }else {
                    continue;
                }

            }
        }
        break;
    }

    if (cycle) {
        cout<<"Yes\n";
    }else {
        cout<<"No\n";
    }

    return 0;
}