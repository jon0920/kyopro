#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> A;
    map<ll,ll> mp;
    rep(i,n){
        int a;
        cin >> a;
        A.push_back(a);
        mp[a]++;
    }
    ll ans = -1, max_value = -1;
    rep(i,n){
        if(mp[A[i]] == 1 && A[i] > max_value){
            max_value = A[i];
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}