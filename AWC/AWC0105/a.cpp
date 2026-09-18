#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;

    int cur = 0;
    ll ans = 0;
    for(char c : s){
        if(c == 'R') cur++;
        else cur--;
        cur = (cur + n) % n;
        ans += a[cur];
    }

    cout << ans << endl;
    
    return 0;
}