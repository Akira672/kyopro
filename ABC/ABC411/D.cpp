#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> Op(Q),P(Q);
    vector<string> S(Q);
    for(int i = 0;i < Q;i++){
        cin >> Op[i] >> P[i];
        if(Op[i] == 2){
            cin >> S[i];
            reverse(S[i].begin(),S[i].end());
        }
    }

    string ans = "";
    int i = 0;
    for(int t = Q - 1; 0 <= t;--t){
        switch(Op[t]){
            case 1:{
                if(i == P[t]){
                    i = 0;
                }
                break;
            }
            case 2:{
                if(i == P[t]){
                    ans += S[t];
                }
                break;
            }
            case 3:{
                if(i == 0){
                    i = P[t];
                }
                break;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
    return 0;
}