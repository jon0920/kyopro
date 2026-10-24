#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0;
    rep(i,n) if(a[i] == k) ans++;

    rep(i,n - 1){
        if(min(a[i], a[i + 1]) < k && k < max(a[i], a[i + 1])) ans++;
    }
    cout << ans << endl;
    
    return 0;
}