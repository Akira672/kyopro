#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H,W,N;
    cin>>H>>W>>N;
    vector<vector<int>> X(H);
    vector<vector<int>> Y(W);
    for(int i = 0;i < N;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        X[x].push_back(i);
        Y[y].push_back(i);
    }
    int Q;
    cin>>Q;

    vector<bool> exist(N,true);
    vector<bool> clean_X(H,false);
    vector<bool> clean_Y(W,false);
    while(Q--){
        int op,a;
        cin>>op>>a;
        a--;
        int cnt = 0;
        switch(op){
            case 1:{
                if(!clean_X[a]){
                    clean_X[a] = true;
                    for(int i = 0;i < X[a].size();i++){
                        if(exist[X[a][i]]){
                            cnt++;
                            exist[X[a][i]] = false;
                        }
                    }
                }
                break;
            }
            case 2:{
                if(!clean_Y[a]){
                    clean_Y[a] = true;
                    for(int i = 0;i < Y[a].size();i++){
                        if(exist[Y[a][i]]){
                            cnt++;
                            exist[Y[a][i]] = false;
                        }
                    }
                }
                break;
            }
        }

        cout<<cnt<<"\n";
    }

    return 0;
}