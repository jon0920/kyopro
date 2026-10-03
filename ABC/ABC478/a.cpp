#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    rep(i,m){
        ans[i % n]++;
    }

    for(int x : ans) cout << x << endl;
    
    return 0;
}