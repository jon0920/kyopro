#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    string sub = s.substr(n - m);

    priority_queue<int, vector<int>, greater<int>> pq;
    bool ok = true;
    rep(i,m){
        if(t[i] != sub[i] && t[i] != '?' && sub[i] != '?'){
            pq.push(i);
            ok = false;
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    rep(i,m){
        sub[i] = s[i];
        if(pq.empty() || pq.top() > i){
            if(sub[i] != t[i] && t[i] != '?' && sub[i] != '?') pq.push(i);
        }
        else if(pq.top() == i){
            if(sub[i] == t[i] || sub[i] == '?' || t[i] == '?') pq.pop();
        }
        if(pq.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}