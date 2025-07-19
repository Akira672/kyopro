#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    map<int,vector<pair<int,int>>>arror;
    for(int i = 0;i < M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        arror[a].push_back({b,w});
    }

    vector<vector<bool>> visit(N,vector<bool>(1 << 10,false));
    deque<pair<int,int>> q;
    visit[0][0] = true;
    q.push_back({0,0});

    while(!q.empty()){
        auto [n,x] = q.front();
        q.pop_front();

        for(auto&& [b,w]:arror[n]){
            int y = x ^ w;
            if(!visit[b][y]){
                visit[b][y] = true;
                q.push_back({b,y});
            }
        }
    }

    for(int i = 0;i < 1 << 10;i++){
        if(visit[N-1][i]){
            cout << i << "\n";
            break;
        }
        if(i == (1 << 10) - 1){
            cout << "-1\n";
        }
    }

    return 0;
}