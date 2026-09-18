#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

string solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<char> c(n);
    rep(i,n) c[i] = s[i];
    vector<int> change(n, 0);
    rep(i,n - 1){
        if(c[i] > c[i + 1]){
            change[i] = 1;
            break;
        }
    }
    rep(i,n - 1){
        if(c[i] >= c[i + 1] && change[i] == 1){
            swap(c[i], c[i + 1]);
            swap(change[i], change[i + 1]);
        }
    }
    string res = "";
    for(auto t : c) res += t;
    return res;
}

int main() {
    
    int t;
    cin >> t;
    rep(i,t) cout << solve() << endl;
    
    return 0;
}