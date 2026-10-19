#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i = 0; i < (n); i++)


int main(){
    
    int t;
    cin >> t;
    while(t--){
        int tsx, tsy, tgx, tgy;
        int asx, asy, agx, agy;
        cin >> tsx >> tsy >> tgx >> tgy;
        cin >> asx >> asy >> agx >> agy;

        ld sdx = tgx - tsx, sdy = tgy - tsy;
        ld st = hypotl(sdx, sdy);

        ld adx = agx - asx, ady = agy - asy;
        ld at = hypotl(adx, ady);

        ld tvx = sdx / st, tvy = sdy / st;
        ld avx = adx / at, avy = ady / at;

        ld vx = tvx - avx, vy = tvy - avy;

    }
    
    return 0;
}