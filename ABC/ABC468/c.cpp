#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    int ans = 0;
    do{
        bool P = false, Q = false;
        rep(i,n){
            if(p[i] > v[i]) break;
            if(p[i] < v[i]){
                P = true;
                break;
            }
        }
        rep(i,n){
            if(q[i] < v[i]) break;
            if(q[i] > v[i]){
                Q = true;
                break;
            }
        }
        if(P && Q) ans++;
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans << endl;
    
    return 0;
}