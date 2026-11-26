#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    set<string> st;
    rep(i,n) cin >> s[i];
    sort(s.begin(), s.end());
    rep(i,m){
        string t;
        cin >> t;
        st.insert(t);
    }
    int rem = 16 - (n - 1);
    rep(i,n) rem -= s[i].size();

    auto dfs = [&](auto dfs, int depth, string str, int rem) -> void {
        if(depth == n){
            if(str.size() >= 3 && str.size() <= 16 && !st.count(str)){
                cout << str << endl;
                exit(0);
            }
            return;
        }

        if(depth == 0){
            dfs(dfs, 1, s[0], rem);
        } else {
            for(int i = 0; i <= rem; i++){
                string nstr = str + string(i + 1, '_') + s[depth];
                dfs(dfs, depth + 1, nstr, rem - i);
            }
        }
    };

    do{
        dfs(dfs, 0, "", rem);
    }while(next_permutation(s.begin(), s.end()));

    cout << -1 << endl;
    
    return 0;
}