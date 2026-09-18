#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<pair<ll,int>> add(n, {0, -1});
    pair<ll,int> offset = {-1, -1};
    cin >> q;
    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            ll x;
            cin >> x;
            offset = {x, qi};
        }
        else if(type == 2){
            ll i, x;
            cin >> i >> x;
            i--;
            if(add[i].second < offset.second){
                add[i] = {x, qi};
            }
            else{
                add[i].first += x;
                add[i].second = qi;
            }
        }
        else{
            int i;
            cin >> i;
            i--;
            if(offset.first == -1){
                cout << a[i] + add[i].first << endl;
            }
            else{
                if(add[i].second < offset.second) cout << offset.first << endl;
                else cout << offset.first + add[i].first << endl;
            }
        }
    }

    return 0;
}