#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(26);
        int mx = 0;
        for(char c : s){
            int x = c - 'a';
            cnt[x]++;
            mx = max(mx, cnt[x]);
        }

        if(n % 2 == 1) n++;
        if(mx > n / 2){
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
        priority_queue<pair<int,int>> pq;
        rep(i,26){
            if(cnt[i] > 0) pq.push({cnt[i], i});
        }

        string res = "!";
        while(!pq.empty()){
            auto [rem, id] = pq.top(); pq.pop();
            char c = 'a' + id;
            if(res.back() != c){
                res += c;
                rem--;
                if(rem != 0){
                    pq.push({rem, id});
                }
            } else {
                auto [rem2, id2] = pq.top(); pq.pop();
                char c2 = 'a' + id2;
                res += c2;
                rem2--;
                if(rem != 0) pq.push({rem, id});
                if(rem2 != 0) pq.push({rem2, id2});
            }
        }

        int m = res.size();
        for(int i = 1; i < m; i++) cout << res[i];
        cout << endl;
    }
    
    return 0;
}