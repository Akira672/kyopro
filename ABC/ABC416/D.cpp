#include<bits/stdc++.h>
using namespace std;

int main(){
    long long T;
    cin >> T;
    while(T--) {
        long long N,M;
        cin >> N >> M;
        vector<long long> A(N);
        for (auto&& a:A)cin >> a;
        vector<long long> B(N);
        for (auto&& b:B)cin >> b;

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        long long b_i = N - 1;
        long long sum = 0;
        for (int i = 0;i < N;i++) {
            sum += A[i] + B[i];
            if (M <= A[i] + B[b_i]) {
                b_i--;
                sum -= M;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
