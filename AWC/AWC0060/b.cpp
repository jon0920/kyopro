#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    int r = 0, w = 0, q = 0;
    rep(i,n){
        char s;
        cin >> s;
        if(s == 'R') r++;
        else if(s == 'W') w++;
        else q++;
    }

    if(r < w) swap(r, w);
    int d = min(r - w, q);
    w += d; q -= d;

    if(q == 0) cout << abs(r - w) << endl;
    else {
        if(q % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}