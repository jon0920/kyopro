#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, c;
    cin >> n >> c;
    vector<ll> w(n);
    rep(i,n) cin >> w[i];
    sort(w.begin(), w.end());

    ll sum = 0;
    int cnt = 0;
    while(cnt < n && sum + w[cnt] <= c){
        sum += w[cnt];
        cnt++;
    }

    if(cnt < n) cnt++;
    cout << cnt << endl;
    
    return 0;
}