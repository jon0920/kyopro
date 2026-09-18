#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    vector<pair<int,int>> w(n);
    rep(i,n){
        cin >> w[i].first;
        w[i].second = s[i] - '0';
    }
    sort(w.begin(), w.end());
    
    int cnt = 0;
    rep(i,n){
        if(w[i].second == 1) cnt++;
    }

    int ans = cnt;
    rep(i,n){
        if(w[i].second == 0) cnt++;
        else cnt--;

        if(i < n - 1){
            if(w[i].first != w[i + 1].first) ans = max(ans, cnt);
        } else {
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
    
    return 0;
}