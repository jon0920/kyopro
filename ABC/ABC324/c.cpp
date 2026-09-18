#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string t;
    cin >> n >> t;
    int m = t.size();
    vector<int> ans;
    rep(i,n){
        string s;
        cin >> s;
        if(t == s){
            ans.push_back(i + 1);
            continue;
        }
        int sz = s.size();
        if(abs(sz - m) >= 2) continue;
        else if(abs(sz - m) == 1){
            int cnt = 0; 
            int si = 0, ti = 0;
            if(sz > m){
                while(si < sz && ti < m){
                    if(s[si] == t[ti]){
                        si++, ti++;
                    }
                    else{
                        si++, cnt++;
                    }
                }
            }
            else{
                while(si < sz && ti < m){
                    if(s[si] == t[ti]){
                        si++, ti++;
                    }
                    else{
                        ti++, cnt++;
                    }
                }
            }
            if(cnt <= 1) ans.push_back(i + 1);
        }
        else if(sz == m){
            int cnt = 0;
            rep(j,m){
                if(s[j] != t[j]) cnt++;
            }
            if(cnt == 1) ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}