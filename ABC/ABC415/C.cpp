#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        string S;
        cin >> S;

        vector<bool>visit(N,false);
        bool yes = false;

        function<void(int,int)> solve = [&](int p,int cnt){
            if(cnt == N){
                yes = true;
            }
            for(int i = 0;i < N;++i){
                int d = p + (1 << i);
                if(!visit[i] && S[p + (1 << i)-1] == '0'){
                    visit[i] = true;
                    S[p + (1 << i)-1] = '1';
                    solve(p + (1 << i),cnt + 1);
                    visit[i] = false;
                }
            }
        };

        solve(0,0);

        if(yes){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}