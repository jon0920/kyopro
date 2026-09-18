#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());

    rep(i,n){
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        int ans = b.end() - it;
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}