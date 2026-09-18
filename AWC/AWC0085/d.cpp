#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> offset(q + 1);
    vector<ll> max_L(q + 1), max_R(q + 1);
    for(int qi = 1; qi <= q; qi++){
        ll p, d;
        char c;
        cin >> p >> c >> d;
        if(c == 'L') d *= -1;
        offset[qi] = offset[p] + d;

        max_L[qi] = max(max_L[p], -offset[qi]);
        max_R[qi] = max(max_R[p], offset[qi]);

        ll lower_A = 1 + max_L[qi];
        ll upper_A = m - max_R[qi];

        ll rem = 0;
        if(lower_A <= upper_A){
            auto lit = lower_bound(a.begin(), a.end(), lower_A);
            auto rit = upper_bound(a.begin(), a.end(), upper_A);
            rem = rit - lit;
        }
        cout << n - rem << endl;
    } 
    
    return 0;
}