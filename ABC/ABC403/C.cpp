#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,Q;
    cin>>N>>M>>Q;

    vector<map<int,bool>> per(N+1);
    vector<bool> per_all(N+1,false);

    while (Q--) {
        int op;
        cin>>op;

        switch (op) {
            case 1: {
                int x,y;
                cin>>x>>y;
                per[x][y]=true;
                break;
            }
            case 2: {
                int x;
                cin>>x;
                per_all[x]=true;
                break;
            }

            case 3: {
                int x,y;
                cin>>x>>y;
                if (per[x][y] || per_all[x]) {
                    cout<<"Yes\n";
                }else {
                    cout<<"No\n";
                }
                break;
            }

        }
    }

    return 0;
}