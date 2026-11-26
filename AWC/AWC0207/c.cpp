#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    map<int,int> cnt;
    rep(i,n) rep(i,m){
        int a;
        cin >> a;
        cnt[a]++;
    }

    int mx = 0;
    for(auto [k, v] : cnt) mx = max(mx, v);

    cout << n * m - mx << endl;
    
    return 0;
}