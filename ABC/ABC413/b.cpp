#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<string, bool> mp;
    string ss;
    vector<string> ans;
    rep(i,n){
        rep(j,n){
            if(i != j){
                ss = s[i] + s[j];
                mp[ss] = true;
            }
        }
    }
    cout << mp.size() << endl;
}