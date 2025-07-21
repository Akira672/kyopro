#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<long long> A(N);
    long long sum=0;
    for (auto& a:A) {
        cin>> a;
        sum+=a;
    }

    long long ans = 0;
    for (int i = 0;i < N - 1;++i) {
        sum -= A[i];
        ans += sum * A[i];
    }

    cout<<ans<< "\n";

    return 0;
}