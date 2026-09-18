#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int mg;
    cin >> mg;
    vector<vector<bool>> Gg(n, vector<bool>(n));
    rep(i,mg){
        int u, v;
        cin >> u >> v;
        u--, v--;
        Gg[u][v] = true;
        Gg[v][u] = true;
    }
    int mh;
    cin >> mh;
    vector<vector<bool>> Gh(n, vector<bool>(n));
    rep(i,mh){
        int u, v;
        cin >> u >> v;
        u--, v--;
        Gh[u][v] = true;
        Gh[v][u] = true;
    }

    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n - 1){
        for(int j = i + 1; j < n; j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    ll ans = 1e18;
    do{
        map<int,int> mp;
        ll sum = 0;
        rep(i,n) mp[i] = p[i];
        rep(i,n){
            for(int j = i + 1; j < n; j++){
                if(Gg[i][j] != Gh[mp[i]][mp[j]]) sum += a[mp[i]][mp[j]];
            }
        }
        ans = min(ans, sum);
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    
    return 0;
}