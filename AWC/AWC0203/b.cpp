#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<int> ans(w);
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w) if(s[j] == '#') ans[j]++;
    }
    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}