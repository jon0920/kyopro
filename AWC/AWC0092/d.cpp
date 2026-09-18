#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector<pair<int,int>> uv(m);
    rep(i,m){
        cin >> uv[i].first >> uv[i].second;
        uv[i].first--;
        uv[i].second--;
    }

    int ans = 0;
    do{
        map<int,int> mp;
        rep(i,n) mp[p[i]] = i;
        bool ok = true;
        rep(i,m){
            if(mp[uv[i].first] > mp[uv[i].second]) ok = false;
        }
        if(ok){
            int sum = 0;
            rep(i,n){
                sum += a[p[i]] * (i + 1);
            }
            ans = max(ans, sum);
        }
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    
    return 0;
}