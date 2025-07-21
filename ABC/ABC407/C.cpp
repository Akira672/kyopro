#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    long long ans = 0;
    for(int i=0;i<S.size()-1;i++) {
        ans += (10 + S[i] - S[i+1]) % 10 + 1;
    }

    ans += S[S.size()-1] - '0' + 1;

    cout << ans << "\n";

    return 0;
}