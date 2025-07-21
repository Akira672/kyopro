#include<bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    int HW = H * W;
    vector<vector<long long>> A(H,vector<long long>(W,0));
    vector<vector<long long>> I(H,vector<long long>(W,0));
    long long temp_i = 1;
    long long xor_all = 0;
    for (int i = 0;i < H;i++) {
        for (int j = 0;j < W;j++) {
            cin >> A[i][j];
            I[i][j] = temp_i;
            temp_i *= 2;
            xor_all ^= A[i][j];
        }
    }

    vector<bool> visit(1 << HW ,false);
    vector<bool> domino(1 << HW ,false);


    long long ans = xor_all;
    function<void(long long,long long)> solve = [&](long long p,long long old_xor) {
        visit[p] = true;

        for (int i = 0;i < H;i++) {
            for (int j = 0;j < W - 1;j++) {
                if (!domino[I[i][j]] && !domino[I[i][j+1]] && !visit[p^I[i][j]^I[i][j+1]]) {
                    domino[I[i][j]] = true;
                    domino[I[i][j+1]] = true;
                    long long new_xor = old_xor ^ A[i][j] ^ A[i][j+1];
                    ans = max(ans,new_xor);
                    solve(p^I[i][j]^I[i][j+1],new_xor);
                    domino[I[i][j]] = false;
                    domino[I[i][j+1]] = false;
                }
            }
        }

        for (int i = 0;i < W;i++) {
            for (int j = 0;j < H - 1;j++) {
                if (!domino[I[j][i]] && !domino[I[j+1][i]] && !visit[p^I[j][i]^I[j+1][i]]) {
                    domino[I[j][i]] = true;
                    domino[I[j+1][i]] = true;
                    long long new_xor = old_xor ^ A[j][i] ^ A[j+1][i];
                    ans = max(ans,new_xor);
                    solve(p^I[j][i]^I[j+1][i],new_xor);
                    domino[I[j][i]] = false;
                    domino[I[j+1][i]] = false;
                }
            }
        }

        return;
    };

    solve(0,xor_all);

    cout << ans << "\n";

    return 0;
}