#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    long long l = 0;
    long long r = sqrt(N) + 1;

    while(l + 1 < r){
        long long m = (l + r) / 2;
        if(2 * m * m <= N){
            l = m;
        }else{
            r = m;
        }
    }

    long long a = l;

    l = 0;
    r = sqrt(N);

    while(l + 1 < r){
        long long m = (l + r) / 2;
        if(4 * m * m <= N){
            l = m;
        }else{
            r = m;
        }
    }

    long long b = l;


    cout << a + b << "\n";
    return 0;
}