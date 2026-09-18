#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int m = a[0];
    for(auto &x : a){
        if(x != m){
            cout << x << endl;
            return 0;
        }
    }
    
    return 0;
}