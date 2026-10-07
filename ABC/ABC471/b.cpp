#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    map<string,int> mp;
    rep(i,n){
        string s;
        cin >> s;
        for(char &c : s){
            c = tolower(c);
        }
        mp[s]++;
    }

    int ans = 0;
    for(auto [k, v] : mp) ans = max(ans, v);
    cout << ans << endl;
    
    return 0;
}