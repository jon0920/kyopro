#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int MAX = 200010;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> cnt(MAX);
    rep(i,n){
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll ans = 0;
    for(int i = 1; i < MAX; i++){
        if(cnt[i] == 0) continue;
        for(int j = 1; i * j < MAX; j++){
            ans += cnt[i] * cnt[j] * cnt[i * j];
        }
    }

    cout << ans << endl;

    return 0;
}