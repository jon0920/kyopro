#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct Node{
    int children[26];
    int cnt;
    Node() : cnt(0){
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
        nodes[cur].cnt++;
        for(char c : s){
            int idx = c - 'a';
            if(nodes[cur].children[idx] == -1){
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
            nodes[cur].cnt++;
        }
    }

    int solve(const string &s){
        int cur = 0;
        int depth = 0;
        bool ok = false;
        for(char c : s){
            int idx = c - 'a';
            cur = nodes[cur].children[idx];
            depth++;
            if(nodes[cur].cnt == 1){
                ok = true;
                break;
            }
        }
        if(ok) return depth;
        return -1;
    }
};

int main(){
    
    int n;
    cin >> n;
    Trie trie;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];    
        trie.insert(s[i]);
    }

    ll ans = 0;
    for(auto t : s){
        if(trie.solve(t) == -1){
            cout << -1 << endl;
            return 0;
        }
        ans += trie.solve(t);
    }

    cout << ans << endl;
    
    return 0;
}