#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    int children[26];
    ll max_weight;
    Node() : max_weight(0){
        fill(children, children + 26, -1);
    }
};

struct Trie{
    vector<Node> nodes;
    Trie(){ nodes.emplace_back(); };

    void insert(const string &p, ll w){
        int cur = 0;
        for(char c : p){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1){
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
        }
        nodes[cur].max_weight = max(nodes[cur].max_weight, w);
    }
};

int main(){
    
    string s;
    cin >> s;
    Trie trie;
    int m;
    cin >> m;
    vector<pair<string,ll>> cand(m);
    rep(i,m) cin >> cand[i].first;
    rep(i,m) cin >> cand[i].second;
    for(auto [s, w] : cand) trie.insert(s, w);
    
    int n = s.size();
    vector<ll> dp(n + 1, 0);

    rep(i,n){
        dp[i + 1] = max(dp[i + 1], dp[i]);

        int cur = 0;
        for(int j = i; j < n; j++){
            int idx = s[j] - 'a';
            if(trie.nodes[cur].children[idx] == -1) break;
            cur = trie.nodes[cur].children[idx];
            if(trie.nodes[cur].max_weight > 0){
                dp[j + 1] = max(dp[j + 1], dp[i] + trie.nodes[cur].max_weight);
            }
        }
    }

    cout << dp[n] << endl;
    
    return 0;
}