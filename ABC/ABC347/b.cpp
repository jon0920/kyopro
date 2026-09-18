#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();

    unordered_set<string> ans;
    rep(i,n){
        for(int j = 0; j + i < n; j++){
            string sub = s.substr(j, i + 1);
            ans.insert(sub);
        }
    }
    cout << ans.size() << endl;
    return 0;
}