#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    s += '!';
    char last = s[0];
    ll cnt = 1;
    vector<pair<char,ll>> rle;
    for(int i = 1; i < n + 1; i++){
        if(s[i] == last) cnt++;
        else {
            rle.push_back({last, cnt});
            last = s[i];
            cnt = 1;
        }
    }

    int sz = rle.size();
    ll ans = 0;
    rep(i,sz - 2){
        if(rle[i].first == rle[i + 2].first) ans += rle[i].second * rle[i + 2].second;
    }

    cout << ans << endl;
    
    return 0;
}