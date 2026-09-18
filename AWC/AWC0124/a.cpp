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
    int cnt = 0;
    vector<pair<char,int>> rle;
    rep(i,n + 1){
        if(last == s[i]){
            cnt++;
        } else {
            rle.push_back({last, cnt});
            cnt = 1;
            last = s[i];
        }
    }

    int ans = 0;
    for(auto [c, x] : rle){
        if(c == 'W') ans = max(ans, x);
    }
    cout << ans << endl;
    
    return 0;
}