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
    int cnt = 0;
    int last = s[0];
    for(int x : s){
        if(x == last) cnt++;
        else {
            rle.push_back({last, cnt});
            cnt = 1;
            last = x;
        }
    }

    for(auto [x, cnt] : rle){
        if(cnt >= k){
            rep(_,cnt) cout << x << " ";
        }
    }
    cout << endl;
    
    return 0;
}