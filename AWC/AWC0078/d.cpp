#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    vector<int> k(q);
    rep(i,q) cin >> k[i];

    vector<int> ord(q);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return k[i] < k[j];
    });

    vector<int> orda(n);
    iota(orda.begin(), orda.end(), 0);
    sort(orda.begin(), orda.end(), [&](int i, int j){
        return a[i] < a[j];
    });

    atcoder::dsu uf(n);
    int idx = 0;
    ll ans = 0;
    vector<ll> res(q);
    for(auto i : ord){
        while(idx < n && a[orda[idx]] < k[i]){
            const int id = orda[idx];
        }
    }
    
    return 0;
}