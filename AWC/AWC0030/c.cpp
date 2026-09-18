#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    s.push_back(-1);
    vector<pair<int,int>> rle;
    int last = s[0], cnt = 1;
    for(int i = 1; i <= n; i++){
        if(s[i] == last) cnt++;
        else{
            rle.push_back({last, cnt});
            cnt = 1;
            last = s[i];
        }
    }
    
    int ans = 0;
    for(auto [a, b] : rle){
        if(a == 1 && b >= k) ans++;
    }

    cout << ans << endl;
    
    return 0;
}