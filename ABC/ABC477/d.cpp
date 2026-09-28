#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<tuple<int,int,char>> query(q + 1);
    query[0] = {2, -1, 'a'};
    vector<int> tile(n);
    for(int i = 1; i <= q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            x--;
            tile[x] ^= 1;
            query[i] = {type, x, '!'};
        } else {
            char c;
            cin >> c;
            query[i] = {type, -1, c};
        }
    }
    reverse(query.begin(), query.end());

    set<int> st;
    rep(i,n) if(!tile[i]) st.insert(i);
    
    vector<char> ans(n, '!');
    for(auto [type, x, c] : query){
        if(type == 1){
            if(!tile[x] && ans[x] == '!') st.erase(x);
            if(tile[x] && ans[x] == '!') st.insert(x);
            tile[x] ^= 1;
        } else {
            for(int i : st){
                ans[i] = c;
            }
            st.clear();
        }
    }

    for(char c : ans) cout << c;
    cout << endl;

    return 0;
}