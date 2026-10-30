#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<bool>> g(26, vector<bool>(26));
    rep(i,m){
        char x, y;
        cin >> x >> y;
        g[x - 'A'][y - 'A'] = true;
    }

    string t = "";
    for(char c : s){
        if(t.empty()) t += c;
        else {
            if(g[t.back() - 'A'][c - 'A']) t.pop_back();
            else t += c;
        }
    }

    if(t.empty()) cout << "EMPTY" << endl;
    else cout << t << endl;
    
    return 0;
}