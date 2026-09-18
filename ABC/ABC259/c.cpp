#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;
    s += '!';
    t += '!';
    int n = s.size();
    int m = t.size();
    vector<pair<char,int>> srle, trle;
    char last = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(last == s[i]) cnt++;
        else{
            srle.push_back({last, cnt});
            cnt = 1;
            last = s[i];
        }
    }
    last = t[0];
    cnt = 1;
    for(int i = 1; i < m; i++){
        if(last == t[i]) cnt++;
        else{
            trle.push_back({last, cnt});
            cnt = 1;
            last = t[i];
        }
    }

    if(srle.size() != trle.size()){
        cout << "No" << endl;
        return 0;
    }

    int sz = srle.size();
    bool ok = true;
    rep(i,sz){
        if(srle[i].first != trle[i].first) ok = false;
        else if(srle[i].second != trle[i].second){
            if(srle[i].second > trle[i].second) ok = false;
            else if(srle[i].second == 1) ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}