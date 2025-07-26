#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,D;
    cin>>N>>D;
    vector<int> cnt(1e6+1,0);
    for(int i=0;i<N;++i) {
        int ai;
        cin>>ai;
        cnt[ai]++;
    }

    int ans = 0;

    if (D == 0) {
        for (int i = 0;i < 1e6 + 1;++i) {
            ans += max(0,cnt[i]-1);
        }
    }else {
        vector<vector<int>> DP(1e6+1,vector<int>(2,0));
        for (int i = 0;i < D;++i) {
            if (cnt[i] == 0) {
                DP[i][0] = 1e7;
                DP[i][1] = 0;
            }else {
                DP[i][0] = 0;
                DP[i][1] = cnt[i];
            }

            int j;
            for (j = i + D;j < 1e6+1;j += D) {
                if (cnt[j] == 0) {
                    DP[j][0] = 1e7;
                    DP[j][1] = min(DP[j-D][0],DP[j-D][1]);
                }else {
                    DP[j][0] = DP[j-D][1];
                    DP[j][1] = min(DP[j-D][0],DP[j-D][1]) + cnt[j];
                }

            }
            ans += min(DP[j-D][0],DP[j-D][1]);

        }
    }

    cout << ans << "\n";

    return 0;
}