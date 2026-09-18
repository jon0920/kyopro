#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> ans(3);
    rep(i,n){
        int a;
        cin >> a;
        a %= 1000;
        a = 1000 - a;
        string s = to_string(a);
        reverse(s.begin(), s.end());
        int m = s.size();
        rep(j,m) ans[j] += s[j] - '0';
    }

    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}