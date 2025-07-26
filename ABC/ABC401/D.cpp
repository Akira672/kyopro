#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N,K;
    cin >> N >> K;
    string S;
    cin >> S;

    for(int i = 1;i < N - 1;i++){
        if(S[i] == '?' && (S[i-1] == 'o' || S[i+1] == 'o')){
            S[i] == '.';
        }
    }

    
    
    
    cout << ans << "\n";

    return 0;
}