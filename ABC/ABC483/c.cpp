#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    vector<vector<int>> second(n);
    rep(j,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++;
        second[a].push_back(b);
    }
    
    
    return 0;
}