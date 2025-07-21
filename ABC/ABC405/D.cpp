#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> S(H,vector<char>(W));
    for(auto&& s_h:S)for(auto&& s:s_h)cin >> s;

    queue<pair<int,int>> q;

    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            if(S[i][j] == 'E'){
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        auto [h,w] = q.front();
        q.pop();

        if(0 <= h - 1 && S[h - 1][w] == '.'){
            S[h - 1][w] = 'v';
            q.push({h - 1,w});
        }
        if(h + 1 < H && S[h + 1][w] == '.'){
            S[h + 1][w] = '^';
            q.push({h + 1,w});
        }
        if(0 <= w - 1 && S[h][w - 1] == '.'){
            S[h][w - 1] = '>';
            q.push({h,w - 1});
        }
        if(w + 1 < W && S[h][w + 1] == '.'){
            S[h][w + 1] = '<';
            q.push({h,w + 1});
        }
    }
    for(auto&& s_h:S){
        for(auto&& s:s_h)cout << s;
        cout << "\n";
    }

    return 0;
}