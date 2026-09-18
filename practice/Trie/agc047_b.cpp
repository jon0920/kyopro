#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    int children[26];
    bool is_end;

    Node() : is_end(false){
        fill(children, children + 26, -1);
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){
        nodes.emplace_back();
    }

    void insert(const string &s){
        int cur = 0;
        for(char c : s){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1){
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
        }
        nodes[cur].is_end = true;
    }

    ll solve(const string &s){
        int m = s.size();
        string r = s;
        reverse(r.begin(), r.end());

        vector<int> char_cnt(26);
        for(char c : s) char_cnt[c - 'a']++;

        ll res = 0;
        int cur = 0;
        rep(d,m - 1){
            rep(c,26){
                if(char_cnt[c] > 0){
                    int nxt = nodes[cur].children[c];
                    if(nxt != -1 && nodes[nxt].is_end) res++;
                }
            }
            char_cnt[s[m - 1 - d] - 'a']--;
            int idx = r[d] - 'a';
            cur = nodes[cur].children[idx];
        }
        return res;
    }
};

int main(){
    
    int n;
    cin >> n;
    Trie trie;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
        string r = s[i];
        reverse(r.begin(), r.end());
        trie.insert(r);
    }

    ll ans = 0;
    rep(i,n){
        ans += trie.solve(s[i]);
    }
    cout << ans << endl;
    
    return 0;
}