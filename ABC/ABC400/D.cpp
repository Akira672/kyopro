#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H,W;
    cin>>H>>W;
    vector<string>S(H);
    for(auto&& s:S)cin >> s;

    int A,B,C,D;
    cin >> A >> B >> C >> D;
    A--;B--;C--;D--;

    vector<vector<int>>cost(H,vector<int>(W,1e9));
    deque<pair<int,int>>q;
    q.push_back({A,B});
    cost[A][B] = 0;
    vector<pair<int,int>> op1 = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    vector<pair<int,int>> op2 = { {-2,0}, {2,0}, {0,-2}, {0,2} };

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop_front();
        for(int i = 0;i < op1.size();i++){
            auto [dx,dy] = op1[i];
            if(0 <= x + dx && x + dx < H && 0 <= y + dy && y + dy < W){
               int w = 0;
                if(S[x+dx][y+dy]=='#')w = 1;
                if(cost[x][y]+w < cost[x+dx][y+dy]){
                    cost[x+dx][y+dy] = cost[x][y]+w;
                    if(w == 0){
                        q.push_front({x+dx,y+dy});
                    }else{
                        q.push_back({x+dx,y+dy});
                    }
                }
            }
        }

        for(int i = 0;i < op2.size();i++){
            auto [dx,dy] = op2[i];
            if(0 <= x + dx && x + dx < H && 0 <= y + dy && y + dy < W && (S[x+dx][y+dy]=='#' || S[x+dx/2][y+dy/2]=='#')){
                if(cost[x][y]+1 < cost[x+dx][y+dy]){
                    cost[x+dx][y+dy] = cost[x][y]+1;
                    q.push_back({x+dx,y+dy});
                    
                }
            }
        }
    }
    
    cout << cost[C][D] << "\n";

    return 0;
}