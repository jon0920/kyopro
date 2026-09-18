#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int h, w, q;
    cin >> h >> w >> q;

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int c;
            cin >> c;
            cout << c * w << endl;
            h -= c;
        }
        else{
            int r;
            cin >> r;
            cout << r * h << endl;
            w -= r;
        }
    }

    return 0;
}