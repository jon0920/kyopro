#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i], a[i]--;
    rep(i,n) cin >> b[i], b[i]--;

    bool ok = true;
    rep(i,n){
        if(i != b[a[i]]) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}