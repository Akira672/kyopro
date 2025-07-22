#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<long long> C(N);
    for(auto&& c:C)cin>>c;
    vector<vector<long long>> A(M);
    for (auto&& a:A) {
        int K;
        cin>>K;
        a.resize(K);
        for (auto&& ak:a) {
            cin >> ak;
            ak--;
        }
    }

    long long T = pow(3,N);
    long long min_cost = 1LL << 60;
    for (long long i = 1;i < T;++i) {
        vector<int> zoo(N,0);
        vector<int> animal(M,0);
        long long cost = 0;

        long long i_copy = i;

        for (int j = 0;j < N;j++) {
            zoo[j] = i_copy % 3;
            i_copy /= 3;
        }

        for (int j = 0;j < M;++j) {
            for (int k =0;k < A[j].size();++k) {
                animal[j] += zoo[A[j][k]];
            }
        }

        bool ok = true;
        for (int j = 0;j < M;++j) {
            if (animal[j] < 2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (int j = 0;j < N;++j) {
                cost += C[j]*zoo[j];
            }
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }
    cout << min_cost << "\n";
    return 0;
}