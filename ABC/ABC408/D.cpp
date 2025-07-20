#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        vector<vector<int>> DP(3,vector<int>(N+1,0));
        for(int i=0;i<N;i++) {
            DP[0][i+1] = DP[0][i] + (S[i] == '1');
            DP[1][i+1] = min(DP[0][i] + (S[i] == '0'),DP[1][i] + (S[i] == '0'));
            DP[2][i+1] = min(DP[1][i] + (S[i] == '1'),DP[2][i] + (S[i] == '1'));
        }

        cout << min(DP[0][N],min(DP[1][N],DP[2][N])) << "\n";
    }

    return 0;
}
