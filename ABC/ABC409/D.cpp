#include<bits/stdc++.h>
using namespace std;

int main(){
    long long T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        string S;
        cin >> S;

        int l = 0;
        int r = 0;
        for(int i = 0;i < N - 1;i++){
            if(S[i+1] < S[i]){
                l = i;
                r = N-1;
                for(int j = i+2;j < N;j++){
                    if(S[l] < S[j]){
                        r = j-1;
                        break;
                    }
                }
                break;
            }
        }
        cout << S.substr(0,l) + S.substr(l + 1,r - l) + S[l] + S.substr(r + 1,N-r-1) << "\n";
    }

    return 0;
}