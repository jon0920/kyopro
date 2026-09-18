#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int L, R, n;
    cin >> L >> R >> n;
    rep(i,n){
        int l, r;
        cin >> l >> r;
        if(L < l) L = l;
        if(R > r) R = r;
        cout << max(R - L + 1, 0) << endl;
    }

    return 0;
}