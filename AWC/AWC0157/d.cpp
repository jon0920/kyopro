#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> l(m);
    rep(i,m) cin >> l[i];

    if(m < n - 1){
        cout << "No" << endl;
        return 0;
    }

    sort(a.rbegin(), a.rend());
    sort(l.rbegin(), l.rend());

    rep(i,n - 1){
        if(a[i] + a[n - 1] > l[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}