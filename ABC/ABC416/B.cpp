#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    bool flag = true;
    for (int i = 0;i < S.size();i++) {
        if (S[i] == '.') {
            if (flag) {
                S[i] = 'o';
                flag = false;
            }
        }else {
            flag = true;
        }
    }

    cout << S << endl;

    return 0;
}