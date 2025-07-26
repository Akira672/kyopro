#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,K,X;
    cin >> N >> K >> X;
    vector<string> S(N);
    for (auto&& s:S)cin >> s;

    vector<string> f(pow(N,K));

    long long cnt = 0;
    function<void(string, long long)> create = [&](string s, long long n) {
        for (int i = 0;i < N;++i) {
            if (0 < n) {
                create(s + S[i],n - 1);
            }else {
                f[cnt] = s + S[i];
                cnt++;
            }
        }
    };

    create("",K-1);

    sort(f.begin(),f.end());

    cout << f[X-1] << "\n";

    return 0;
}