#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    if(k == 1){
        vector<int> res(n);
        for(int i = 1; i <= n; i++){
            int p;
            cin >> p;
            res[p - 1] = i;
        }
        for(int x : res) cout << x << endl;
        return 0;
    }

    vector<int> under(n, -1);
    vector<int> cnt(n);
    set<int> st;

    vector<int> ans(n, -1);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        p--;
        if(st.upper_bound(p) == st.end()){
            st.insert(p);
            cnt[p] = 1;
        } else {
            auto it = st.upper_bound(p);
            int x = *it;
            under[p] = x;
            cnt[p] = cnt[x] + 1;
            st.erase(it);
            if(cnt[p] == k){
                int cur = p;
                while(cur != -1){
                    ans[cur] = i;
                    cur = under[cur];
                }
            } else st.insert(p);
        }
    }

    for(int x : ans) cout << x << endl;
    
    return 0;
}