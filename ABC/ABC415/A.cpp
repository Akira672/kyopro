#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto&& a:A)cin >> a;
    int X;
    cin >> X;

    for(int i = 0;i < N;i++){
        if(A[i] == X){
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}