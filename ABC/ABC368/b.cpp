#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    bool ok = true;
    int ans = 0;
    while(ok){
        sort(a.rbegin(), a.rend());
        a[0]--, a[1]--;
        int cnt = 0;
        for(int i : a){
            if(i > 0) cnt++; 
        }
        if(cnt <= 1) ok = false;
        ans++;
    }

    cout << ans << endl;
    return 0;
}