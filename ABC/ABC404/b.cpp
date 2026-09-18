#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int count(vector<string> s, vector<string> t){
    int n = s.size();
    int cnt = 0;
    rep(i,n){
        rep(j,n){
            if(s[i][j] != t[i][j]) cnt++;
        }
    }
    return cnt;
}

vector<string> rotation(vector<string> s){
    int n = s.size();
    vector<string> ret(n, string(n, '.'));
    rep(i,n){
        rep(j,n){
            ret[i][j] = s[n - j - 1][i];
        }
    }
    return ret;
}

int main(){

    int n;
    cin >> n;
    vector<string> s(n), t(n); 
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];

    int diff = 1e9;
    rep(i,4){
        int d = count(s,t);
        diff = min(diff, d + i);
        s = rotation(s);
    }

    cout << diff << endl;
    return 0;
}